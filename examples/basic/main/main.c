/**
 * @file main.c
 * @brief Basic usage example for the Soldered Slider Potentiometer Qwiic component
 * @author Soldered Electronics
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soldered-slider-potentiometer-qwiic.h"

/* Qwiic uses the ESP32's default I2C pins on Soldered boards; adjust if needed. */
#define I2C_SDA_GPIO 8
#define I2C_SCL_GPIO 9

void app_main(void)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = I2C_SDA_GPIO,
        .scl_io_num = I2C_SCL_GPIO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, &bus_handle));

    soldered_slider_pot_handle_t slider;
    ESP_ERROR_CHECK(soldered_slider_pot_init(bus_handle, SOLDERED_SLIDER_POT_I2C_ADDR_DEFAULT, &slider));

    while (1) {
        uint16_t raw;
        uint8_t percent;
        ESP_ERROR_CHECK(soldered_slider_pot_read_raw(&slider, &raw));
        ESP_ERROR_CHECK(soldered_slider_pot_read_percent(&slider, &percent));

        printf("Slider: raw=%u percent=%u%%\n", raw, percent);
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}
