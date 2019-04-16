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

#ifdef SIMPLE*

    while (1) {
        printf("\nMolweni\n");
        sleep(1);
    }
#else

char *file_str = NULL;
char *filename = FILENAME;
char *ST_ID = "000\0";

cJSON *athing = NULL;
cJSON *aobsproperty = NULL;
cJSON *datastream0 = NULL;
cJSON *datastream1 = NULL;
cJSON *asensor = NULL;
cJSON *aobs = cJSON_CreateObject();

//Read in json file
read_json(&file_str, filename);

// Parse json into thing, datastream0, datastream1, sensor
parse_json(&file_str, &athing, &datastream0, &datastream1, &asensor, &aobsproperty);

//Post a thing
cJSON *thing_id = post_ST(athing, "http://129.74.246.19:8080/v1.0/Things");
printf("\nPosted thing");

//Post a sensor
cJSON *sensor_id = post_ST(asensor, "http://129.74.246.19:8080/v1.0/Sensors");
printf("\nPosted sensor");

//Post an observed property
cJSON *obsprop_id = post_ST(aobsproperty, "http://129.74.246.19:8080/v1.0/ObservedProperties");
printf("\nPosted a obs prop");

//Post datastream0 by inserting thing, obsprop, and sensor ids into json
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "Thing"), "@iot.id", thing_id);
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "Sensor"), "@iot.id", sensor_id);
cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream0, "ObservedProperty"), "@iot.id", obsprop_id);
cJSON *datastream_id = post_ST(datastream0, "http://129.74.246.19:8080/v1.0/Datastreams");
printf("\nPosted datastream0");

//Post datastream1 by inserting thing, obsprop, and sensor ids into json
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "Thing"), "@iot.id", thing_id);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "Sensor"), "@iot.id", sensor_id);
    cJSON_ReplaceItemInObject(cJSON_GetObjectItem(datastream1, "ObservedProperty"), "@iot.id", obsprop_id);
    cJSON *datastream_id = post_ST(datastream1, "http://129.74.246.19:8080/v1.0/Datastreams");
    printf("\nPosted datastream1");

//Create an observation cJSON object > insert a datastream id
create_aobservation(aobs);
printf("\nPosted a observation");

cJSON_ReplaceItemInObject(cJSON_GetObjectItem(aobs, "Datastream"), "@iot.id", datastream_id);

//Loop posting observations
int read_s = 0;
int misread_count=0;
while (1) {

      read_s = read_sensor_dummy(aobs);
//    read_s = read_sensor_DHT(aobs);
    post_ST(aobs, "http://129.74.246.19:8080/v1.0/Observations");

    if (read_s !=0){
        misread_count++;
    }

    if (misread_count >= 100) {
        printf("Too many misreads, suspending operation and closing application");
        break;
    }
    sleep(5*60);
}
*/
printf("\n\nGoing to free mem now");
free(file_str);
//cJSON_Delete(athing);
cJSON_Delete(datastream0);
cJSON_Delete(datastream1);
//cJSON_Delete(asensor);
//cJSON_Delete(aobs);
printf("\n\nDone\n\n");
return 0;

}
