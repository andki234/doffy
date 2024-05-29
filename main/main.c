#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "sdkconfig.h"
#include "esp_log.h"
#include "esp_console.h"
#include "i2c_wrapper.h"
#include "esp_system.h"
#include "cmd_system.h"
#include "cmd_wifi.h"
#include "cmd_nvs.h"


void app_main(void)
{
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    /* Prompt to be printed before each line.
     * This can be customized, made dynamic, etc.
     */
    repl_config.prompt = "dof9>";
    repl_config.max_cmdline_length = 160;

    esp_console_register_help_command();
    register_system_common();
    register_system_sleep();
    register_wifi();

    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_uart(&hw_config, &repl_config, &repl));

    
    ESP_ERROR_CHECK(esp_console_start_repl(repl));

    i2c_master_init(I2C_NUM_0);
    
    
    while (true) {
        //printf("Hello from app_main!\n");
        //i2c_master_read_slave_reg(I2C_PORT_NUM, 0x68, 0x75, 0x00, 1);
        i2c_master_test_send();
        sleep(1);
    }
}
