/*
 * i2c_driver.c
 *
 *  Created on: 24 maj 2024
 *      Author: andki
 */

#include "hw_pin_defs.h"
#include "driver/i2c.h"

#define I2C_FREQ_HZ				100000           /*!< I2C master clock frequency */
#define I2C_PORT_NUM			I2C_NUM_0        /*!< I2C port number for master dev */
#define I2C_TX_BUF_DISABLE  	0                /*!< I2C master do not need buffer */
#define I2C_RX_BUF_DISABLE  	0                /*!< I2C master do not need buffer */


#define ACK_CHECK_EN            0x1              /*!< I2C master will check ack from slave*/
#define READ_BIT                0x1              /*!< I2C master read bit*/
#define WRITE_BIT               0x0              /*!< I2C master write bit*/    
#define ACK_VAL                 0x0              /*!< I2C ack value */
#define NACK_VAL                0x1              /*!< I2C nack value */     

void i2c_master_init()
{
    int i2c_master_port = I2C_PORT_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ_HZ;
    i2c_param_config(i2c_master_port, &conf);

    i2c_driver_install(i2c_master_port, conf.mode,
    		I2C_RX_BUF_DISABLE, I2C_TX_BUF_DISABLE, 0);
}