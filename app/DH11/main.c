#include <stdio.h>
#include "bbb_dht_read.h"
#include "common_dht_read.h"
#include "bbb_mmio.h"

int main() {
    printf("Hello, World!\n");
    int sensor, gpio_base,gpio_number;
   gpio_base=1;
   gpio_number=13;
    float humidity = 0, temperature = 0;
    int result = bbb_dht_read(DHT11, gpio_base, gpio_number, &humidity, &temperature);
    
    gpio_t pin;
    if (bbb_mmio_get_gpio(gpio_base, gpio_number, &pin) < 0) {
        return DHT_ERROR_GPIO;
    }



    printf("Result %d\n",result);
    printf("Sensor %d\n",sensor);
    printf("Pin: GPIO_%d_%d\n",gpio_base, gpio_number);
    printf("Humidity %f\n",humidity);
    printf("Temperature %f\n",temperature);
    return 0;
}
