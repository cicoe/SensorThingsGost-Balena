#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "ST_interface.h"
#include <curl/curl.h>
#include <string.h>
#include <DHT11/common_dht_read.h>
#include <DHT11/bbb_dht_read.h>
#include <DHT11/bbb_mmio.h>


void read_json(char **json_str, char *fname) {
    //Read in json file and return in string
    //Don't forget to free json_str

    printf("Reading in file %s", fname);
    long length;
    FILE *f = fopen(fname, "r");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        *json_str = (char *) malloc(length + 1);

        if (*json_str) {
            fread(*json_str, 1, length, f);
        }
        fclose(f);
    }
}

int valid_thing(cJSON *one_thing) {

    if (cJSON_IsObject(one_thing) && (one_thing->child != NULL)) {
        const cJSON *name = cJSON_GetObjectItem(one_thing, "name");
        const cJSON *description = cJSON_GetObjectItem(one_thing, "description");
        const cJSON *properties = cJSON_GetObjectItem(one_thing, "properties");
        if (cJSON_IsString(name) && (name != NULL) && cJSON_IsString(description) && (description != NULL) &&
            cJSON_IsObject(properties) && (properties->child != NULL)) {
            return 0;
        } else {
            char *string = cJSON_Print(one_thing);
            printf("\nThing is missing mandatory fields");
            printf("%s", string);
            return 1;
        }
    }
    return 0;
}

int valid_datastream(cJSON *one_datastream) {

    if (cJSON_IsObject(one_datastream) && (one_datastream->child != NULL)) {
        const cJSON *name = cJSON_GetObjectItem(one_datastream, "name");
        const cJSON *description = cJSON_GetObjectItem(one_datastream, "description");
        const cJSON *unitOfMeasurement = cJSON_GetObjectItem(one_datastream, "unitOfMeasurement");
        const cJSON *observationType = cJSON_GetObjectItem(one_datastream, "observationType");
        if (cJSON_IsString(name) && (name != NULL) && cJSON_IsString(description) && (description != NULL) &&
            cJSON_IsObject(unitOfMeasurement) && (unitOfMeasurement->child != NULL) &&
            cJSON_IsString(observationType) && (observationType != NULL)
                ) {
            return 0;
        } else {
            char *string = cJSON_Print(one_datastream);
            printf("\nDatastream is missing mandatory fields");
            printf("%s", string);
            return 1;
        }
    }
    return 0;
}

int valid_sensor(cJSON *one_sensor) {
    if (cJSON_IsObject(one_sensor) && (one_sensor->child != NULL)) {
        const cJSON *name = cJSON_GetObjectItem(one_sensor, "name");
        const cJSON *description = cJSON_GetObjectItem(one_sensor, "description");
        const cJSON *encodingType = cJSON_GetObjectItem(one_sensor, "encodingType");
        const cJSON *metadata = cJSON_GetObjectItem(one_sensor, "metadata");
        if (cJSON_IsString(name) && (name != NULL) && cJSON_IsString(description) && (description != NULL) &&
            cJSON_IsString(encodingType) && (encodingType != NULL) && cJSON_IsString(metadata) && (metadata != NULL)
                ) {
            return 0;
        } else {
            char *string = cJSON_Print(one_sensor);
            printf("\nSensor is missing mandatory fields");
            printf("%s", string);
            return 1;
        }
    }
    return 0;
}

void parse_json(char **json_str, cJSON **thing, cJSON **datastream0, cJSON **datastream1, cJSON **sensor, cJSON **obsproperty0,cJSON **obsproperty1) {
    //Separate json into strings of things, datastreams, and sensors

    if (*json_str) {
        cJSON *json = cJSON_Parse(*json_str);

        // Check for valid json
        if (json == NULL) {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL) {
                fprintf(stderr, "Error before: %s\n", error_ptr);
            }
            goto end;
        }
        // Pull out a thing, check it's valid, return it
        cJSON *th = cJSON_GetObjectItem(json, "thing");
        if (valid_thing(th) != 0) { goto end; }
        *thing = cJSON_Duplicate(th, 1);
        
        // Pull out datastreams checking each are valid, currently looks for 2
        cJSON *ds0 = cJSON_GetObjectItem(json, "datastream");
        if (valid_datastream(ds0) != 0) { goto end; }
        *datastream0 = cJSON_Duplicate(ds0, 1);
        // Pull out an obsproperty, check it's valid, return it
        cJSON *op0 = cJSON_GetObjectItem(json, "observed_property");
        // TODO check valid observed property
        *obsproperty0 = cJSON_Duplicate(op0, 1);

        //Remove 1st instance so next one can be found
        cJSON_DeleteItemFromObjectCaseSensitive(json,"datastream");
        cJSON_DeleteItemFromObjectCaseSensitive(json,"observed_property");

        //get second instance
        cJSON *ds1 = cJSON_GetObjectItem(json, "datastream");
        if (valid_datastream(ds1) != 0) { goto end; }
        *datastream1 = cJSON_Duplicate(ds1, 1);
        // Pull out an obsproperty, check it's valid, return it
        cJSON *op1 = cJSON_GetObjectItem(json, "observed_property");
        // TODO check valid observed property
        *obsproperty1 = cJSON_Duplicate(op1, 1);

        // Pull out a sensor, check it's valid, return it
        cJSON *ss = cJSON_GetObjectItem(json, "sensor");
        if (valid_sensor(ss) != 0) { goto end; }
        *sensor = cJSON_Duplicate(ss, 1);



        end:
        cJSON_Delete(json);
    }
}

void init_result_string(struct result_string *rs) {
    rs->len = 0;
    rs->ptr = malloc(rs->len + 1);
    if (rs->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    rs->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct result_string *rs) {
    size_t new_len = rs->len + size * nmemb;
    rs->ptr = realloc(rs->ptr, new_len + 1);
    if (rs->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(rs->ptr + rs->len, ptr, size * nmemb);
    rs->ptr[new_len] = '\0';
    rs->len = new_len;

    return size * nmemb;
}

int create_aobservation(cJSON *aobs) {
    //Create result object
/* TODO removed because using add-delete to add value to result in main but surely is another way
  if (cJSON_AddStringToObject``(aobs, "result", "") == NULL)
  {
    printf("Error creating observation");
    return 1;
  }
  */
    if (cJSON_AddObjectToObject(aobs, "Datastream") == NULL) {
        printf("Error creating observation");
        return 1;
    }
    if (cJSON_AddStringToObject(cJSON_GetObjectItem(aobs, "Datastream"), "@iot.id", "") == NULL) {
        printf("Error creating observation");
        return 1;
    }
}

cJSON *post_ST(cJSON *payload, const char *destination) {
    CURLcode ret;
    CURL *handle = curl_easy_init();

    if (handle) {
        struct result_string rs;
        init_result_string(&rs);

        curl_easy_setopt(handle, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(handle, CURLOPT_URL, destination);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "cache-control: no-cache");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(handle, CURLOPT_POSTFIELDS, cJSON_Print(payload));
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &rs);

// TODO raise error on not OK response
        ret = curl_easy_perform(handle);
//        printf("\n\nCurl return %s [%d]\n\n",curl_easy_strerror(ret),ret);
        cJSON *json = cJSON_Parse(rs.ptr);

//        printf("\n%s",rs.ptr);
//        printf("\n################################\n");

        free(rs.ptr);
        curl_easy_cleanup(handle);

        //Extract returned @iot.id int value from return json
        cJSON *id = cJSON_GetObjectItem(json, "@iot.id");
        int iotid = id->valueint;

    return id;
    }
}

int read_sensor_dummy(cJSON *observation0,cJSON *observation1) {
    //Return fake value for testing
    char str0[16];
    char str1[16];
    float f0 = 102.7;
    float f1 = 54;
    snprintf(str0, sizeof(str0), "%.2f", f0);
    snprintf(str1, sizeof(str1), "%.2f", f1);
    if (cJSON_AddStringToObject(observation0, "result", str0) == NULL) {
        printf("Error creating observation0 from sensor reading");
        return 1;
    }
    if (cJSON_AddStringToObject(observation1, "result", str1) == NULL) {
        printf("Error creating observation1 from sensor reading");
        return 1;
    }
    return 0;
}

int read_sensor_DHT(cJSON *observation0,cJSON *observation1) {
    //TODO make a more general way of accessing sensor read - callback perhaps
    char str0[16];
    char str1[16];
    int error_cnt = 0, gpio_base, gpio_number, result;
    float humidity = 999, temperature = 999;
    gpio_base = 1; //Header P8
    gpio_number = 13; //Pin 11


    result = bbb_dht_read(DHT11, gpio_base, gpio_number, &humidity, &temperature);

    while (result != 0) {
        error_cnt++;
        printf("\nError Reading Sensor.  Error count: %d\n",error_cnt);
        result = bbb_dht_read(DHT11, gpio_base, gpio_number, &humidity, &temperature);
        if (error_cnt >=50){
            printf("\nToo many missreads, returning to try again");
            break;
        }
    }

    printf("Humidity %f\n", humidity);
    printf("Temperature %f\n", temperature);
    snprintf(str0, sizeof(str0), "%.2f", temperature);
    snprintf(str1, sizeof(str1), "%.2f", humidity);
    if (cJSON_AddStringToObject(observation0, "result", str0) == NULL) {
        printf("Error creating observation0 from sensor temp reading");
        return -1;
    }
    if (cJSON_AddStringToObject(observation1, "result", str1) == NULL) {
        printf("Error creating observation1 from sensor humidity reading");
        return -1;
    }
    return 0;
}
