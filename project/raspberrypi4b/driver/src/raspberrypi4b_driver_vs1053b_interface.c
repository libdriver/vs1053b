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
 * @file      raspberrypi4b_driver_vs1053b_interface.c
 * @brief     raspberrypi4b driver vs1053b interface source file
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

#include "driver_vs1053b_interface.h"
#include "spi.h"
#include "wire.h"
#include <sys/time.h>
#include <stdarg.h>

/**
 * @brief spi device name definition
 */
#define SPI_DEVICE_NAME "/dev/spidev0.0"    /**< spi device name */

/**
 * @brief spi device name definition
 */
#define SPI2_DEVICE_NAME "/dev/spidev0.1"   /**< spi2 device name */

/**
 * @brief spi device handle definition
 */
static int gs_spi_fd;                       /**< spi handle */

/**
 * @brief spi device handle definition
 */
static int gs_spi2_fd;                      /**< spi2 handle */

/**
 * @brief fs handle definition
 */
static FILE *gs_fp = NULL;                  /**< fp handle */

/**
 * @brief  interface spi cmd bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_cmd_init(void)
{
    return spi_init(SPI_DEVICE_NAME, &gs_spi_fd, SPI_MODE_TYPE_3, 1000 * 1000);
}

/**
 * @brief  interface spi cmd bus deinit
 * @return status code
 *         - 0 success
 *         - 1 spi deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_cmd_deinit(void)
{
    return spi_deinit(gs_spi_fd);
}

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
uint8_t vs1053b_interface_spi_cmd_read_address16(uint16_t reg, uint8_t *buf, uint16_t len)
{
    return spi_read_address16(gs_spi_fd, reg, buf, len);
}

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
uint8_t vs1053b_interface_spi_cmd_write_address16(uint16_t reg, uint8_t *buf, uint16_t len)
{
    return spi_write_address16(gs_spi_fd, reg, buf, len);
}

/**
 * @brief  interface spi dat bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_dat_init(void)
{
    return spi_init(SPI2_DEVICE_NAME, &gs_spi2_fd, SPI_MODE_TYPE_3, 1000 * 1000 * 2);
}

/**
 * @brief  interface spi dat bus deinit
 * @return status code
 *         - 0 success
 *         - 1 spi deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_dat_deinit(void)
{
    return spi_deinit(gs_spi2_fd);
}

/**
 * @brief     interface spi dat bus write command
 * @param[in] *buf points to a data buffer
 * @param[in] len is the length of data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t vs1053b_interface_spi_dat_write_cmd(uint8_t *buf, uint16_t len)
{
    return spi_write_cmd(gs_spi2_fd, buf, len);
}

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
uint8_t vs1053b_interface_audio_init(uint8_t type, char *name, uint32_t *size)
{
    if (type == 0)
    {
        gs_fp = fopen(name, "r");
        if (gs_fp == NULL)
        {
            return 1;
        }
    }
    else
    {
        gs_fp = fopen(name, "w");
        if (gs_fp == NULL)
        {
            return 1;
        }
    }
    if (fseek(gs_fp, 0, SEEK_END) != 0)
    {
        return 1;
    }
    *size = ftell(gs_fp);
    
    return 0;
}

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
uint8_t vs1053b_interface_audio_read(uint32_t addr, uint16_t size, uint8_t *buffer)
{
    if (fseek(gs_fp, addr, SEEK_SET) != 0)
    {
        return 1;
    }
    if (fread((void *)buffer, 1, size, gs_fp) < 0)
    {
        return 1;
    }

    return 0;
}

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
uint8_t vs1053b_interface_audio_write(uint32_t addr, uint16_t size, uint8_t *buffer)
{
    if (fseek(gs_fp, addr, SEEK_SET) != 0)
    {
        return 1;
    }
    if (fwrite((void *)buffer, 1, size, gs_fp) < 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief  interface audio deinit
 * @return status code
 *         - 0 success
 *         - 1 audio deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_audio_deinit(void)
{
    if (fclose(gs_fp) != 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief      interface timestamp read
 * @param[out] *sec points to a second buffer
 * @param[out] *us points to a microsecond buffer
 * @return     status code
 *             - 0 success
 *             - 1 timestamp read failed
 * @note       none
 */
void vs1053b_interface_timestamp_read(uint32_t *sec, uint32_t *us)
{
    struct timeval time_s;
    
    if (gettimeofday(&time_s, NULL) < 0)
    {
        return;
    }

    *sec = time_s.tv_sec;
    *us = time_s.tv_usec;
}

/**
 * @brief  interface reset gpio init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t vs1053b_interface_reset_gpio_init(void)
{
    return wire_clock_init();
}

/**
 * @brief  interface reset gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_reset_gpio_deinit(void)
{
    return wire_clock_deinit();
}

/**
 * @brief     interface reset gpio write
 * @param[in] data is the written data
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t vs1053b_interface_reset_gpio_write(uint8_t data)
{
    return wire_clock_write(data);
}

/**
 * @brief  interface dreq gpio init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t vs1053b_interface_dreq_gpio_init(void)
{
    return wire_init();
}

/**
 * @brief  interface dreq gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_interface_dreq_gpio_deinit(void)
{
    return wire_deinit();
}

/**
 * @brief      interface dreq gpio read
 * @param[out] *data points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t vs1053b_interface_dreq_gpio_read(uint8_t *data)
{
    return wire_read(data);
}

/**
 * @brief     interface delay ms
 * @param[in] ms
 * @note      none
 */
void vs1053b_interface_delay_ms(uint32_t ms)
{
    usleep(1000 * ms);
}

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @note      none
 */
void vs1053b_interface_debug_print(const char *const fmt, ...)
{
    char str[256];
    uint16_t len;
    va_list args;
    
    memset((char *)str, 0, sizeof(char) * 256); 
    va_start(args, fmt);
    vsnprintf((char *)str, 255, (char const *)fmt, args);
    va_end(args);
    
    len = strlen((char *)str);
    (void)printf((uint8_t *)str, len);
}

/**
 * @brief     interface receive callback
 * @param[in] type is the receive callback type
 * @param[in] cur_pos is the current position
 * @note      none
 */
void vs1053b_interface_receive_callback(uint8_t type, uint32_t cur_pos)
{
    switch (type)
    {
        case VS1053B_TYPE_PLAY_READ :
        {
            vs1053b_interface_debug_print("vs1053b: irq read data during playing with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_PLAY_WRITE :
        {
            vs1053b_interface_debug_print("vs1053b: irq write data during playing with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_PLAY_END :
        {
            vs1053b_interface_debug_print("vs1053b: irq play end with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_RECORD_READ :
        {
            vs1053b_interface_debug_print("vs1053b: irq read data during recording with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_RECORD_WRITE :
        {
            vs1053b_interface_debug_print("vs1053b: irq write data during recording with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_RECORD_END :
        {
            vs1053b_interface_debug_print("vs1053b: irq record end with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_RECORD_OVER :
        {
            vs1053b_interface_debug_print("vs1053b: irq record over buffer with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_PERIOD :
        {
            vs1053b_interface_debug_print("vs1053b: irq period.\n");
            
            break;
        }
        default :
        {
            vs1053b_interface_debug_print("vs1053b: unknown type.\n");
            
            break;
        }
    }
}
