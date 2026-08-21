/**
 * @file soldered_slider_potentiometer_qwiic.c
 * @brief Implementation for the Soldered Slider Potentiometer Qwiic component
 * @author Soldered Electronics
 */

#include "soldered_slider_potentiometer_qwiic.h"

/** Register value that selects the slider ADC reading */
#define SOLDERED_SLIDER_POT_REG_VALUE 0x00

esp_err_t soldered_slider_pot_init(i2c_master_bus_handle_t bus_handle, uint8_t i2c_addr,
                                   soldered_slider_pot_handle_t *handle)
{
    if (handle == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = i2c_addr,
        .scl_speed_hz = 100000,
    };

    return i2c_master_bus_add_device(bus_handle, &dev_config, &handle->i2c_dev);
}

esp_err_t soldered_slider_pot_read_raw(const soldered_slider_pot_handle_t *handle, uint16_t *raw)
{
    if (handle == NULL || raw == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t reg = SOLDERED_SLIDER_POT_REG_VALUE;
    uint8_t data[2] = {0};

    esp_err_t err = i2c_master_transmit_receive(handle->i2c_dev, &reg, 1, data, sizeof(data), -1);
    if (err != ESP_OK) {
        return err;
    }

    *raw = ((uint16_t)data[1] << 8) | data[0];
    return ESP_OK;
}

esp_err_t soldered_slider_pot_read_percent(const soldered_slider_pot_handle_t *handle, uint8_t *percent)
{
    if (percent == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    uint16_t raw;
    esp_err_t err = soldered_slider_pot_read_raw(handle, &raw);
    if (err != ESP_OK) {
        return err;
    }

    if (raw > SOLDERED_SLIDER_POT_RAW_MAX) {
        raw = SOLDERED_SLIDER_POT_RAW_MAX;
    }
    *percent = (uint8_t)((uint32_t)raw * 100 / SOLDERED_SLIDER_POT_RAW_MAX);
    return ESP_OK;
}

esp_err_t soldered_slider_pot_deinit(soldered_slider_pot_handle_t *handle)
{
    if (handle == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    return i2c_master_bus_rm_device(handle->i2c_dev);
}
