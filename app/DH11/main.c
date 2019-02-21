#include <stdio.h>
#include "bbb_dht_read.h"
#include "common_dht_read.h"
#include "bbb_mmio.h"
#include <unistd.h>

int main() {
/*    printf("Hello, World!\n");
    int sensor, gpio_base,gpio_number;
   gpio_base=1;
   gpio_number=13;
    float humidity = 0, temperature = 0;
    int result = bbb_dht_read(DHT11, gpio_base, gpio_number, &humidity, &temperature);
    
    printf("Result %d\n",result);
    printf("Sensor %d\n",sensor);
    printf("Pin: GPIO_%d_%d\n",gpio_base, gpio_number);
    printf("Humidity %f\n",humidity);
    printf("Temperature %f\n",temperature);
    return 0;
*/

    FILE *io,*iodir,*ioval;

    io = fopen("/sys/class/gpio/export", "w");
    fseek(io,0,SEEK_SET);
    fprintf(io,"%d",67);
    fflush(io);

    iodir = fopen("/sys/class/gpio/gpio67/direction", "w");
    fseek(iodir,0,SEEK_SET);
    fprintf(iodir,"out");
    fflush(iodir);

    ioval = fopen("/sys/class/gpio/gpio67/value", "w");
    fseek(ioval,0,SEEK_SET);

    while(1)
    {
        fprintf(ioval,"%d",1);
        fflush(ioval);
        sleep(1);
        fprintf(ioval,"%d",0);
        fflush(ioval);
        sleep(1);
    }

    fclose(io);
    fclose(iodir);
    fclose(ioval);
    return 0;
}
