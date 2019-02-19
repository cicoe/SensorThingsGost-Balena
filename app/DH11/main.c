#include <stdio.h>
#include "bbb_dht_read.h"

int main() {
    printf("Hello, World!");
    int sensor, gpio_base,gpio_number;
   gpio_base=1;
   gpio_number=13;
    float humidity = 0, temperature = 0;
    int result = bbb_dht_read(sensor, gpio_base, gpio_number, &humidity, &temperature);
    printf("Result %d",result);
    printf("Sensor %d",sensor);
    printf("Pin: GPIO_%d_%d",gpio_base, gpio_number);
    printf("Humidity %f",humidity);
    printf("Temperature %f",temperature);
    return 0;
}