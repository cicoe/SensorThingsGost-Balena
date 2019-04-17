#include "cJSON.h"
#include <curl/curl.h>
#ifndef ST_INTERFACE__H
#define ST_INTERFACE__H

struct result_string {
    char *ptr;
    size_t len;
};

void read_json (char ** jsonstr, char *fname);
void parse_json (char ** json_str, cJSON ** thing, cJSON ** datastream0, cJSON ** datastream1, cJSON ** sensor, cJSON ** observedproperty0, cJSON ** observedproperty1);
int valid_thing(cJSON * one_thing);
int valid_datastream(cJSON * one_datastream);
int valid_sensor(cJSON * one_sensor);
void init_result_string(struct result_string *rs);
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct result_string *rs);
cJSON * post_ST (cJSON * payload, const char * destination);
int create_aobservation (cJSON * aobs);
int read_sensor_dummy(cJSON * observation0, cJSON * observation1);
int read_sensor_DHT(cJSON * observation0, cJSON * observation1);



#endif
