/*
 * I2S with type casting/punning (made C example into C++)
 * ESP32 official Espressif libraries are written in C
 * 
 * https://docs.espressif.com/projects/esp-idf/en/v4.1/api-reference/peripherals/i2s.html
 * 
 * xtensa-esp32-elf-gcc toolchain
 * 
 */
 
#include "driver/i2s.h"
#include "freertos/queue.h"

static const i2s_port_t i2s_num = I2S_NUM_0; // i2s port number

static const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX) ,
    .sample_rate = 44100,
    .bits_per_sample = (i2s_bits_per_sample_t) 16,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = (i2s_comm_format_t) (I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
};


static const i2s_pin_config_t pin_config = {
    .bck_io_num = 26,
    .ws_io_num = 25,
    .data_out_num = 22,
    .data_in_num = I2S_PIN_NO_CHANGE
};



void setup()
{
    i2s_driver_install(i2s_num, &i2s_config, 0, NULL);   //install and start i2s driver

    i2s_set_pin(i2s_num, &pin_config);  // leave

    i2s_set_sample_rates(i2s_num, 22050); //set sample rates

//    i2s_driver_uninstall(i2s_num); //stop & destroy i2s driver
}

void loop(){}
