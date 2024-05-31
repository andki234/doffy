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

void i2c_master_init(i2c_port_t i2c_num);
void i2c_master_test_send(void);
void i2c_master_read_test(void);
esp_err_t i2c_master_read_slave_reg(i2c_port_t i2c_num, uint8_t i2c_addr, uint8_t i2c_reg, uint8_t* data_rd, size_t size);