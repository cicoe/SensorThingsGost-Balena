#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <tgmath.h>
#include "cJSON.h"
#include "ST_interface.h"

#define FILENAME "onething.json"

/*
 * TODO Feature of Interest?
 * TODO Add fuller ST json verification
 * TODO Add proper Error handling
 * TODO swap out loop for MQTT stream
 */

int main() {
    char *file_str = NULL;
    char *filename = FILENAME;
    char *ST_ID = "000\0";

    cJSON *athing = NULL;
    cJSON *aobsproperty = NULL;
    cJSON *adatastream = NULL;
    cJSON *asensor = NULL;
    cJSON *aobs = cJSON_CreateObject();

    //Read in json file
    read_json(&file_str, filename);

    // Parse json into thing, datastream, sensor
    parse_json(&file_str, &athing, &adatastream, &asensor, &aobsproperty);

    //Post a thing
    cJSON *thing_id = post_ST(athing, "http://129.74.246.19:8080/v1.0/Things");
    printf("\nPosted thing");

    //Post a sensor
    cJSON *sensor_id = post_ST(asensor, "http://129.74.246.19:8080/v1.0/Sensors");

    //Post an observed property
    cJSON *obsprop_id = post_ST(aobsproperty, "http://129.74.246.19:8080/v1.0/ObservedProperties");


    //Post a datastream by inserting thing, obsprop, and sensor ids into json
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(adatastream, "Thing"), "@iot.id", thing_id);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(adatastream, "Sensor"), "@iot.id", sensor_id);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(adatastream, "ObservedProperty"), "@iot.id", obsprop_id);
    cJSON *datastream_id = post_ST(adatastream, "http://129.74.246.19:8080/v1.0/Datastreams");

    //Create an observation cJSON object > insert a datastream id
    create_aobservation(aobs);

    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(aobs, "Datastream"), "@iot.id", datastream_id);

    //Loop posting observations
//    for (int i =0;i<10;i++){
    int read_s = 0;
    while (1) {
        read_s = read_sensor(aobs);
//    read_s = read_sensor_DHT(aobs);
        if (read_s != 0) {
            printf("Error reading sensor");
            break;
        }
//        printf("\n%s", cJSON_Print(aobs));

        post_ST(aobs, "http://129.74.246.19:8080/v1.0/Observations");

        cJSON_DeleteItemFromObject(aobs, "result");
    }

    printf("\n\nGoing to free mem now");
    free(file_str);
    cJSON_Delete(athing);
    cJSON_Delete(adatastream);
    cJSON_Delete(asensor);
    cJSON_Delete(aobs);
    printf("\n\nDone\n\n");
    return 0;
}
