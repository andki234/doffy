#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "i2c_wrapper.h"

void app_main(void)
{
    i2c_master_init();
    
    while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
    }
}
