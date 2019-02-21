#include <stdio.h>
#include "bbb_dht_read.h"
#include "common_dht_read.h"
#include "bbb_mmio.h"
#include <unistd.h>

int main() {
   int sensor, gpio_base,gpio_number,result;
    float humidity = 0, temperature = 0;

    while(1)
    {
    printf("Hello, World!\n");
    gpio_base=1;
    gpio_number=13;
    result = bbb_dht_read(DHT11, gpio_base, gpio_number, &humidity, &temperature);
    
    printf("Result: %d\n",result);
    printf("Pin: GPIO_%d_%d\n",gpio_base, gpio_number);
    printf("Humidity %f\n",humidity);
    printf("Temperature %f\n",temperature);
    sleep(10);
    }
    return 0;
}
