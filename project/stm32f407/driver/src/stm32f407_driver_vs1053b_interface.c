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
 * @file      stm32f407_driver_vs1053b_interface.c
 * @brief     stm32f407 driver vs1053b interface source file
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
#include "ff.h"
#include "delay.h"
#include "spi.h"
#include "uart.h"
#include "wire.h"
#include "tim.h"
#include <stdarg.h>

/**
 * @brief fs var definition
 */
FATFS g_fs;        /**< fatfs handle */
FIL g_file;        /**< fs handle */

/**
 * @brief timer var definition
 */
static uint32_t gs_s = 0;        /**< s */
static uint32_t gs_flag = 0;     /**< init 0 */

/**
 * @brief     timer callback
 * @param[in] us is the timer cnt
 * @note      none
 */
static void gs_tim_irq(uint32_t us)
{
    gs_s += us / 1000000;
}

/**
 * @brief  interface spi cmd bus init
 * @return status code
 *         - 0 success
 *         - 1 spi init failed
 * @note   none
 */
uint8_t vs1053b_interface_spi_cmd_init(void)
{
    return spi_init(SPI_MODE_3);
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
    return spi_deinit();
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
    return spi_read_address16(reg, buf, len);
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
    return spi_write_address16(reg, buf, len);
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
    return spi2_init();
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
    return spi2_deinit();
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
    return spi2_write_cmd(buf, len);
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
    FRESULT res;
    
    res = f_mount(&g_fs, "0:", 1);
    if (res != FR_OK)
    {
        return 1;
    }
    if (type == 0)
    {
        res = f_open(&g_file, name, FA_READ);
        if (res != FR_OK)
        {
            return 1;
        }
    }
    else
    {
        res = f_open(&g_file, name, FA_WRITE | FA_CREATE_ALWAYS);
        if (res != FR_OK)
        {
            return 1;
        }
    }
    *size = f_size(&g_file);
    
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
    FRESULT res;
    UINT bw;
    
    res = f_lseek(&g_file, addr);
    if (res != FR_OK)
    {
        return 1;
    }
    res = f_read(&g_file, buffer, size, &bw);
    if (res != FR_OK)
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
    FRESULT res;
    UINT bw;
    
    res = f_lseek(&g_file, addr);
    if (res != FR_OK)
    {
        return 1;
    }
    res = f_write(&g_file, buffer, size, &bw);
    if (res != FR_OK)
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
    FRESULT res;
    
    res = f_close(&g_file);
    if (res != FR_OK)
    {
        return 1;
    }
    res = f_unmount("0:");
    if (res != FR_OK)
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
    if (gs_flag == 0)
    {
        /* init 0 */
        gs_s = 0;
        
        /* timer init */
        if (tim_init(1000000, gs_tim_irq) != 0)
        {
            return;
        }
        
        /* timer start */
        if (tim_start() != 0)
        {
            return;
        }
        gs_flag = 1;
    }
    *sec = gs_s;
    *us = tim_get_handle()->Instance->CNT;
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
    delay_ms(ms);
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
    (void)uart_write((uint8_t *)str, len);
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
