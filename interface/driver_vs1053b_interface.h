/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_vs1053b_interface.h
 * @brief     driver vs1053b interface header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-06-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/06/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_VS1053B_INTERFACE_H
#define DRIVER_VS1053B_INTERFACE_H

#include "driver_vs1053b.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup vs1053b_interface_driver vs1053b interface driver function
 * @brief    vs1053b interface driver modules
 * @ingroup  vs1053b_driver
 * @{
 */

/**
 * @brief  interface spi cmd bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_cmd_init(void);

/**
 * @brief  interface spi cmd bus deinit
 * @return status code
 *         - 0 success
 *         - 1 spi deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_cmd_deinit(void);

/**
 * @brief      interface spi cmd bus read
 * @param[in]  reg is the register address
 * @param[out] *buf points to a data buffer
 * @param[in]  len is the length of data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t vs1053b_interface_spi_cmd_read_address16(uint16_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief     interface spi cmd bus write
 * @param[in] reg is the register address
 * @param[in] *buf points to a data buffer
 * @param[in] len is the length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t vs1053b_interface_spi_cmd_write_address16(uint16_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief  interface spi dat bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_dat_init(void);

/**
 * @brief  interface spi dat bus deinit
 * @return status code
 *         - 0 success
 *         - 1 spi deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_dat_deinit(void);

/**
 * @brief     interface spi dat bus write command
 * @param[in] *buf points to a data buffer
 * @param[in] len is the length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t vs1053b_interface_spi_dat_write_cmd(uint8_t *buf, uint16_t len);

/**
 * @brief     interface audio init
 * @param[in] type is the open type, 0 is read and 1 is write.
 * @param[in] *name points to a name buffer
 * @param[in] *size points to a file size buffer
 * @return    status code
 *            - 0 success
 *            - 1 audio init failed
 * @note      none
 */
uint8_t vs1053b_interface_audio_init(uint8_t type, char *name, uint32_t *size);

/**
 * @brief  interface audio deinit
 * @return status code
 *         - 0 success
 *         - 1 audio deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_audio_deinit(void);

/**
 * @brief      interface audio read
 * @param[in]  addr is the mp3 file address
 * @param[in]  size is the read size
 * @param[out] *buffer points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 audio read failed
 * @note       none
 */
uint8_t vs1053b_interface_audio_read(uint32_t addr, uint16_t size, uint8_t *buffer);

/**
 * @brief     interface audio write
 * @param[in] addr is the mp3 file address
 * @param[in] size is the write size
 * @param[in] *buffer points to a data buffer
 * @return    status code
 *            - 0 success
 *            - 1 audio write failed
 * @note      none
 */
uint8_t vs1053b_interface_audio_write(uint32_t addr, uint16_t size, uint8_t *buffer);

/**
 * @brief      interface timestamp read
 * @param[out] *sec points to a second buffer
 * @param[out] *us points to a microsecond buffer
 * @return     status code
 *             - 0 success
 *             - 1 timestamp read failed
 * @note       none
 */
void vs1053b_interface_timestamp_read(uint32_t *sec, uint32_t *us);

/**
 * @brief  interface reset gpio init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t vs1053b_interface_reset_gpio_init(void);

/**
 * @brief  interface reset gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_reset_gpio_deinit(void);

/**
 * @brief     interface reset gpio write
 * @param[in] data is the written data
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t vs1053b_interface_reset_gpio_write(uint8_t data);

/**
 * @brief  interface dreq gpio init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t vs1053b_interface_dreq_gpio_init(void);

/**
 * @brief  interface dreq gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_dreq_gpio_deinit(void);

/**
 * @brief      interface dreq gpio read
 * @param[out] *data points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t vs1053b_interface_dreq_gpio_read(uint8_t *data);

/**
 * @brief     interface delay ms
 * @param[in] ms
 * @note      none
 */
void vs1053b_interface_delay_ms(uint32_t ms);

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @note      none
 */
void vs1053b_interface_debug_print(const char *const fmt, ...);

/**
 * @brief     interface receive callback
 * @param[in] type is the receive callback type
 * @param[in] cur_pos is the current position
 * @note      none
 */
void vs1053b_interface_receive_callback(uint8_t type, uint32_t cur_pos);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
