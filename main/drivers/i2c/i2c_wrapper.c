/*
 * i2c_driver.c
 *
 *  Created on: 24 maj 2024
 *      Author: andki
 */

#include "driver/i2c.h"
#include "hal/i2c_types.h"
#include "hw_pin_defs.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include <stdint.h>

#define I2C_FREQ_HZ				10000            /*!< I2C master clock frequency */
#define I2C_PORT_NUM			I2C_NUM_0        /*!< I2C port number for master dev */
#define I2C_TX_BUF_DISABLE  	0                /*!< I2C master do not need buffer */
#define I2C_RX_BUF_DISABLE  	0                /*!< I2C master do not need buffer */


#define ACK_CHECK_EN            0x1              /*!< I2C master will check ack from slave*/
#define READ_BIT                0x1              /*!< I2C master read bit*/
#define WRITE_BIT               0x0              /*!< I2C master write bit*/    
#define ACK_VAL                 0x0              /*!< I2C ack value */
#define NACK_VAL                0x1              /*!< I2C nack value */     

static i2c_master_bus_handle_t bus_handle;
static i2c_master_dev_handle_t dev_handle;

void i2c_master_init(i2c_port_t i2c_num)
{
    i2c_master_bus_config_t i2c_bus_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = i2c_num,
        .scl_io_num = I2C_SCL_IO,
        .sda_io_num = I2C_SDA_IO,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_device_config_t i2c_device_config = {
       .dev_addr_length = I2C_ADDR_BIT_LEN_7,
       .device_address = 0x1C,  // LIS3MDL
       .scl_speed_hz = I2C_FREQ_HZ,
    };

     ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_bus_config, &bus_handle));
     ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &i2c_device_config, &dev_handle));
}

void i2c_master_test_send(void)
{
    //uint8_t data = 0x00;

    //i2c_master_transmit(dev_handle, &data, 1, 1000 / 1);
}

void i2c_master_read_test(void)
{
    /* The I²C embedded inside the LIS3MDL behaves like a slave device and the following protocol must be adhered
        to. After the START condition (ST) a slave address is sent, once a slave acknowledge (SAK) has been returned,
        an 8-bit subaddress (SUB) is transmitted: the 7 LSb represent the actual register address while the MSb enables
        address autoincrement. If the MSb of the SUB field is 1, the SUB (register address) is automatically increased to
        allow multiple data read/write.
    */
     // esp_err_t i2c_master_transmit_receive(i2c_master_dev_handle_t i2c_dev, const uint8_t *write_buffer, size_t write_size, uint8_t *read_buffer, size_t read_size, int xfer_timeout_ms);

    uint8_t data[2] = {0x01, 0x00};
    uint8_t regaddr = 0x05;

    //i2c_master_receive(dev_handle, &reg, 1, 1000 / 1);

    // Works set the register address in data[0] and the data to be sent in data[1]
    //i2c_master_transmit(dev_handle, &reg, 2, 1000 / 1);

    // Receive data from the device
    //i2c_master_receive(dev_handle, &reg, 2, 1000 / 1);

    // Tx rx
    //i2c_master_transmit_receive(dev_handle, &reg, 1, data, 1, 1000 / 1);

    i2c_master_sub_address_read(dev_handle, &regaddr, data, 1, 1000 / 1);

    printf("Data read: %d %d\n", data[0], data[1]);
}