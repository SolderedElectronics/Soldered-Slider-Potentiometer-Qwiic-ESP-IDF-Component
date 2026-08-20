/**
 * @file soldered-slider-potentiometer-qwiic.h
 * @brief Public API for the Soldered Slider Potentiometer Qwiic component
 * @author Soldered Electronics
 */

#pragma once

#include "driver/i2c_master.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Default I2C address (all DIP switches off). The 3 onboard switches OR
 * into the low 3 bits, so the effective address is 0x30..0x37.
 */
#define SOLDERED_SLIDER_POT_I2C_ADDR_DEFAULT 0x30

/** ADC resolution of the onboard reading (10-bit). */
#define SOLDERED_SLIDER_POT_RAW_MAX 1023

/** Opaque handle to an initialized slider potentiometer device. */
typedef struct {
    i2c_master_dev_handle_t i2c_dev;
} soldered_slider_pot_handle_t;

/**
 * @brief Attach the slider potentiometer device to an existing I2C bus
 *
 * @param[in]  bus_handle Already-initialized I2C master bus handle
 * @param[in]  i2c_addr   7-bit I2C address (set via onboard DIP switches)
 * @param[out] handle     Device handle to populate
 *
 * @return ESP_OK on success, error from i2c_master_bus_add_device otherwise
 */
esp_err_t soldered_slider_pot_init(i2c_master_bus_handle_t bus_handle, uint8_t i2c_addr,
                                   soldered_slider_pot_handle_t *handle);

/**
 * @brief Read the raw slider ADC value
 *
 * @param[in]  handle Device handle from soldered_slider_pot_init()
 * @param[out] raw    Raw value, 0..SOLDERED_SLIDER_POT_RAW_MAX
 *
 * @return ESP_OK on success, error from the underlying I2C transaction otherwise
 */
esp_err_t soldered_slider_pot_read_raw(const soldered_slider_pot_handle_t *handle, uint16_t *raw);

/**
 * @brief Read the slider position scaled to a percentage
 *
 * @param[in]  handle  Device handle from soldered_slider_pot_init()
 * @param[out] percent Slider position, 0..100
 *
 * @return ESP_OK on success, error from the underlying I2C transaction otherwise
 */
esp_err_t soldered_slider_pot_read_percent(const soldered_slider_pot_handle_t *handle, uint8_t *percent);

/**
 * @brief Detach the slider potentiometer device from its I2C bus
 *
 * @param[in] handle Device handle from soldered_slider_pot_init()
 *
 * @return ESP_OK on success, error from i2c_master_bus_rm_device otherwise
 */
esp_err_t soldered_slider_pot_deinit(soldered_slider_pot_handle_t *handle);

#ifdef __cplusplus
}
#endif
