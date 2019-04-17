#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <tgmath.h>
#include <DHT11/bbb_dht_read.h>
#include "cJSON.h"
#include "ST_interface.h"
//#define SIMPLE
#define FILENAME "onething.json"

/*
 * TODO Feature of Interest?
 * TODO Add fuller ST json verification
 * TODO Add proper Error handling
 * TODO Generalise to Read in Unknown Number of things etc
 * TODO swap out loop for MQTT stream
 */

int main() {

#ifdef SIMPLE

    while (1) {
        printf("\nMolweni\n");
        sleep(1);
    }
#else

char *file_str = NULL;
char *filename = FILENAME;
char *ST_ID = "000\0";

cJSON *athing = NULL;
cJSON *obsproperty0 = NULL;
cJSON *obsproperty1 = NULL;
cJSON *datastream0 = NULL;
cJSON *datastream1 = NULL;
cJSON *asensor = NULL;
cJSON *obs0 = cJSON_CreateObject();
cJSON *obs1 = cJSON_CreateObject();

//Read in json file
read_json(&file_str, filename);

// Parse json into thing, datastream0, datastream1, sensor
parse_json(&file_str, &athing, &datastream0, &datastream1, &asensor, &obsproperty0, &obsproperty1);

//Post a thing
cJSON *thing_id = post_ST(athing, "http://129.74.246.19:8080/v1.0/Things");
printf("\nPosted thing");

//Post a sensor
cJSON *sensor_id = post_ST(asensor, "http://129.74.246.19:8080/v1.0/Sensors");
printf("\nPosted sensor");

//Post 2 observed properties
cJSON *obsprop_id0 = post_ST(obsproperty0, "http://129.74.246.19:8080/v1.0/ObservedProperties");
printf("\nPosted obs prop0");
cJSON *obsprop_id1 = post_ST(obsproperty1, "http://129.74.246.19:8080/v1.0/ObservedProperties");
printf("\nPosted obs prop1");

//Post datastream0 by inserting thing, obsprop, and sensor ids into json
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "Thing"), "@iot.id", thing_id);
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "Sensor"), "@iot.id", sensor_id);
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "ObservedProperty"), "@iot.id", obsprop_id0);
cJSON *datastream_id0 = post_ST(datastream0, "http://129.74.246.19:8080/v1.0/Datastreams");
printf("\nPosted datastream0");

//Post datastream1 by inserting thing, obsprop, and sensor ids into json
    cJSON *thing_id2 = cJSON_Duplicate(thing_id,cJSON_True);
    cJSON *sensor_id2 = cJSON_Duplicate(sensor_id,cJSON_True);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "Thing"), "@iot.id", thing_id2);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "Sensor"), "@iot.id", sensor_id2);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "ObservedProperty"), "@iot.id", obsprop_id1);
    cJSON *datastream_id1 = post_ST(datastream1, "http://129.74.246.19:8080/v1.0/Datastreams");
    printf("\nPosted datastream1");

//Create an observation cJSON object > insert a datastream ids
create_aobservation(obs0);
create_aobservation(obs1);
printf("\nPosted observation0");
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(obs0, "Datastream"), "@iot.id", datastream_id0);
printf("\nPosted observation1");
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(obs1, "Datastream"), "@iot.id", datastream_id1);

//Loop posting observations
int read_s = 0;
int misread_count=0;

while (1) {
//    read_s = read_sensor_dummy(obs0,obs1);
    read_s = read_sensor_DHT(obs0,obs1);

    post_ST(obs0, "http://129.74.246.19:8080/v1.0/Observations");
    post_ST(obs1, "http://129.74.246.19:8080/v1.0/Observations");

    if (read_s !=0){
        misread_count++;
    }

    if (misread_count >= 100) {
        printf("Too many misreads, suspending operation and closing application");
        break;
    }
    sleep(1);
//    sleep(5*60);
}

printf("\n\nGoing to free mem now");
free(file_str);
cJSON_Delete(athing);
cJSON_Delete(datastream0);
//cJSON_Delete(datastream1);
cJSON_Delete(asensor);
cJSON_Delete(obs0);
//cJSON_Delete(obs1);
//cJSON_Delete(obsproperty0);
//cJSON_Delete(obsproperty1);
//cJSON_Delete(obsprop_id0);
//cJSON_Delete(obsprop_id1);
#endif

printf("\n\nDone\n\n");
return 0;

}
