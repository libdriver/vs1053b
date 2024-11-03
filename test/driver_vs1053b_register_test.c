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
 * @file      driver_vs1053b_register_test.c
 * @brief     driver vs1053b register test source file
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
 
#include "driver_vs1053b_register_test.h"
#include <stdlib.h>

static vs1053b_handle_t gs_handle;        /**< vs1053b handle */

/**
 * @brief  register test
 * @return status code
 *         - 0 success
 *         - 1 test failed
 * @note   none
 */
uint8_t vs1053b_register_test(void)
{
    uint8_t res;
    uint8_t reg;
    uint8_t reg_check;
    uint8_t version;
    uint8_t left;
    uint8_t right;
    uint8_t left_check;
    uint8_t right_check;
    uint8_t buf[2];
    uint8_t buf_check[2];
    uint16_t clk;
    uint16_t clk_check;
    uint16_t addr;
    uint16_t addr_check;
    uint16_t byte;
    uint16_t decode_time;
    uint16_t decode_time_check;
    uint16_t rate;
    uint16_t rate_check;
    uint16_t dat0;
    uint16_t dat1;
    uint32_t hz;
    uint32_t hz_check;
    float db;
    float db_check;
    vs1053b_info_t info;
    vs1053b_bool_t enable;
    vs1053b_diff_t diff;
    vs1053b_dclk_edge_t edge;
    vs1053b_bit_order_t order;
    vs1053b_selector_t selector;
    vs1053b_clock_range_t range;
    vs1053b_ad_clock_t ad_clock;
    vs1053b_reference_voltage_t voltage;
    vs1053b_clock_multiplier_t multiplier;
    vs1053b_allowed_multiplier_addition_t addition;
    vs1053b_channel_t channel;
    vs1053b_play_speed_t speed;
    vs1053b_iis_rate_t iis_rate;

    /* link interface function */
    DRIVER_VS1053B_LINK_INIT(&gs_handle, vs1053b_handle_t); 
    DRIVER_VS1053B_LINK_SPI_CMD_INIT(&gs_handle, vs1053b_interface_spi_cmd_init);
    DRIVER_VS1053B_LINK_SPI_CMD_DEINIT(&gs_handle, vs1053b_interface_spi_cmd_deinit);
    DRIVER_VS1053B_LINK_SPI_READ_ADDRESS16(&gs_handle, vs1053b_interface_spi_cmd_read_address16);
    DRIVER_VS1053B_LINK_SPI_WRITE_ADDRESS16(&gs_handle, vs1053b_interface_spi_cmd_write_address16);
    DRIVER_VS1053B_LINK_SPI_DAT_INIT(&gs_handle, vs1053b_interface_spi_dat_init);
    DRIVER_VS1053B_LINK_SPI_DAT_DEINIT(&gs_handle, vs1053b_interface_spi_dat_deinit);
    DRIVER_VS1053B_LINK_SPI_DAT_WRITE_CMD(&gs_handle, vs1053b_interface_spi_dat_write_cmd);
    DRIVER_VS1053B_LINK_RESET_GPIO_INIT(&gs_handle, vs1053b_interface_reset_gpio_init);
    DRIVER_VS1053B_LINK_RESET_GPIO_DEINIT(&gs_handle, vs1053b_interface_reset_gpio_deinit);
    DRIVER_VS1053B_LINK_RESET_GPIO_WRITE(&gs_handle, vs1053b_interface_reset_gpio_write);
    DRIVER_VS1053B_LINK_DREQ_GPIO_INIT(&gs_handle, vs1053b_interface_dreq_gpio_init);
    DRIVER_VS1053B_LINK_DREQ_GPIO_DEINIT(&gs_handle, vs1053b_interface_dreq_gpio_deinit);
    DRIVER_VS1053B_LINK_DREQ_GPIO_READ(&gs_handle, vs1053b_interface_dreq_gpio_read);
    DRIVER_VS1053B_LINK_AUDIO_INIT(&gs_handle, vs1053b_interface_audio_init);
    DRIVER_VS1053B_LINK_AUDIO_DEINIT(&gs_handle, vs1053b_interface_audio_deinit);
    DRIVER_VS1053B_LINK_AUDIO_READ(&gs_handle, vs1053b_interface_audio_read);
    DRIVER_VS1053B_LINK_AUDIO_WRITE(&gs_handle, vs1053b_interface_audio_write);
    DRIVER_VS1053B_LINK_TIMESTAMP_READ(&gs_handle, vs1053b_interface_timestamp_read);
    DRIVER_VS1053B_LINK_DELAY_MS(&gs_handle, vs1053b_interface_delay_ms);
    DRIVER_VS1053B_LINK_DEBUG_PRINT(&gs_handle, vs1053b_interface_debug_print);
    DRIVER_VS1053B_LINK_RECEIVE_CALLBACK(&gs_handle, vs1053b_interface_receive_callback);
    
    /* get information */
    res = vs1053b_info(&info);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get info failed.\n");
        
        return 1;
    }
    else
    {
        /* print chip info */
        vs1053b_interface_debug_print("vs1053b: chip is %s.\n", info.chip_name);
        vs1053b_interface_debug_print("vs1053b: manufacturer is %s.\n", info.manufacturer_name);
        vs1053b_interface_debug_print("vs1053b: interface is %s.\n", info.interface);
        vs1053b_interface_debug_print("vs1053b: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        vs1053b_interface_debug_print("vs1053b: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        vs1053b_interface_debug_print("vs1053b: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        vs1053b_interface_debug_print("vs1053b: max current is %0.2fmA.\n", info.max_current_ma);
        vs1053b_interface_debug_print("vs1053b: max temperature is %0.1fC.\n", info.temperature_max);
        vs1053b_interface_debug_print("vs1053b: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start register test */
    vs1053b_interface_debug_print("vs1053b: start register test.\n");
    
    /* vs1053b init */
    res = vs1053b_init(&gs_handle);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: init failed.\n");
        
        return 1;
    }
    
    /* vs1053b_set_diff/vs1053b_get_diff test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_diff/vs1053b_get_diff test.\n");
    
    /* left channel inverted */
    res = vs1053b_set_diff(&gs_handle, VS1053B_DIFF_LEFT_INVERTED);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: left channel inverted.\n");
    
    /* get diff */
    res = vs1053b_get_diff(&gs_handle, &diff);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get diff failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check diff %s.\n", diff == VS1053B_DIFF_LEFT_INVERTED ? "ok" : "error");
    
    /* normal in phase audio */
    res = vs1053b_set_diff(&gs_handle, VS1053B_DIFF_NORMAL);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: normal in phase audio.\n");
    
    /* get diff */
    res = vs1053b_get_diff(&gs_handle, &diff);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get diff failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check diff %s.\n", diff == VS1053B_DIFF_NORMAL ? "ok" : "error");
    
    /* vs1053b_set_mpeg_layer_i_and_ii/vs1053b_get_mpeg_layer_i_and_ii test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_mpeg_layer_i_and_ii/vs1053b_get_mpeg_layer_i_and_ii test.\n");
    
    /* disable mpeg layer i and ii */
    res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable mpeg layer i and ii.\n");
    
    /* get mpeg layer i and ii */
    res = vs1053b_get_mpeg_layer_i_and_ii(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get mpeg layer i and ii failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check mpeg layer i and ii %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* enable mpeg layer i and ii */
    res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable mpeg layer i and ii.\n");
    
    /* get mpeg layer i and ii */
    res = vs1053b_get_mpeg_layer_i_and_ii(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get mpeg layer i and ii failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check mpeg layer i and ii %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* vs1053b_set_cancel_decoding_current_file/vs1053b_get_cancel_decoding_current_file test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_cancel_decoding_current_file/vs1053b_get_cancel_decoding_current_file test.\n");
    
    /* enable cancel decoding current file */
    res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable cancel decoding current file.\n");
    
    /* get cancel decoding current file */
    res = vs1053b_get_cancel_decoding_current_file(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get cancel decoding current file failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check cancel decoding current file %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable cancel decoding current file */
    res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable cancel decoding current file.\n");
    
    /* get cancel decoding current file */
    res = vs1053b_get_cancel_decoding_current_file(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get cancel decoding current file failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check cancel decoding current file %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_ear_speaker_low_setting/vs1053b_get_ear_speaker_low_setting test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_ear_speaker_low_setting/vs1053b_get_ear_speaker_low_setting test.\n");
    
    /* enable ear speaker low setting */
    res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker low setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable ear speaker low setting.\n");
    
    res = vs1053b_get_ear_speaker_low_setting(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get ear speaker low setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ear speaker low setting %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable ear speaker low setting */
    res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker low setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable ear speaker low setting.\n");
    
    res = vs1053b_get_ear_speaker_low_setting(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get ear speaker low setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ear speaker low setting %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_allow_sdi_test/vs1053b_get_allow_sdi_test test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_allow_sdi_test/vs1053b_get_allow_sdi_test test.\n");
    
    /* enable allow sdi test */
    res = vs1053b_set_allow_sdi_test(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allow sdi test failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable allow sdi test.\n");
    
    /* get allow sdi test */
    res = vs1053b_get_allow_sdi_test(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allow sdi test failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allow sdi test %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable allow sdi test */
    res = vs1053b_set_allow_sdi_test(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allow sdi test failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable allow sdi test.\n");
    
    /* get allow sdi test */
    res = vs1053b_get_allow_sdi_test(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allow sdi test failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allow sdi test %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_stream_mode/vs1053b_get_stream_mode test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_stream_mode/vs1053b_get_stream_mode test.\n");
    
    /* enable stream mode */
    res = vs1053b_set_stream_mode(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set stream mode failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable stream mode.\n");
    
    /* get stream mode */
    res = vs1053b_get_stream_mode(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get stream mode failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check stream mode %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable stream mode */
    res = vs1053b_set_stream_mode(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set stream mode failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable stream mode.\n");
    
    /* get stream mode */
    res = vs1053b_get_stream_mode(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get stream mode failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check stream mode %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_ear_speaker_high_setting/vs1053b_get_ear_speaker_high_setting test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_ear_speaker_high_setting/vs1053b_get_ear_speaker_high_setting test.\n");
    
    /* enable ear speaker high setting */
    res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable ear speaker high setting.\n");
    
    /* get ear speaker high setting */
    res = vs1053b_get_ear_speaker_high_setting(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get ear speaker high setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ear speaker high setting %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable ear speaker high setting */
    res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable ear speaker high setting.\n");
    
    /* get ear speaker high setting */
    res = vs1053b_get_ear_speaker_high_setting(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get ear speaker high setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ear speaker high setting %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_dclk_edge/vs1053b_get_dclk_edge test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_dclk_edge/vs1053b_get_dclk_edge test.\n");
    
    /* set dclk edge falling */
    res = vs1053b_set_dclk_edge(&gs_handle, VS1053B_DCLK_EDGE_FALLING);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set dclk edge failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set dclk edge falling.\n");
    
    /* get dclk edge */
    res = vs1053b_get_dclk_edge(&gs_handle, &edge);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get dclk edge failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check dclk edge %s.\n", edge == VS1053B_DCLK_EDGE_FALLING ? "ok" : "error");
    
    /* vs1053b_set_sdi_bit_order/vs1053b_get_sdi_bit_order test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_sdi_bit_order/vs1053b_get_sdi_bit_order test.\n");
    
    /* set sdi bit order msb first */
    res = vs1053b_set_sdi_bit_order(&gs_handle, VS1053B_BIT_ORDER_MSB_FIRST);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set sdi bit order failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set sdi bit order msb first.\n");
    
    /* get sdi bit order */
    res = vs1053b_get_sdi_bit_order(&gs_handle, &order);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get sdi bit order failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check sdi bit order %s.\n", order == VS1053B_BIT_ORDER_MSB_FIRST ? "ok" : "error");
    
    /* vs1053b_set_share_spi_chip_select/vs1053b_get_share_spi_chip_select test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_share_spi_chip_select/vs1053b_get_share_spi_chip_select test.\n");
    
    /* enable share spi chip select */
    res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set share spi chip select failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable share spi chip select.\n");
    
    /* get share spi chip select */
    res = vs1053b_get_share_spi_chip_select(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get share spi chip select failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check share spi chip select %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable share spi chip select */
    res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set share spi chip select failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable share spi chip select.\n");
    
    /* get share spi chip select */
    res = vs1053b_get_share_spi_chip_select(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get share spi chip select failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check share spi chip select %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_native_spi_modes/vs1053b_get_native_spi_modes test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_native_spi_modes/vs1053b_get_native_spi_modes test.\n");
    
    /* enable native spi modes */
    res = vs1053b_set_native_spi_modes(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set native spi modes failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable native spi modes.\n");
    
    /* get native spi modes */
    res = vs1053b_get_native_spi_modes(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get native spi modes failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check native spi modes %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* vs1053b_set_pcm_adpcm_recording_active/vs1053b_get_pcm_adpcm_recording_active test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_pcm_adpcm_recording_active/vs1053b_get_pcm_adpcm_recording_active test.\n");
    
    /* enable pcm adpcm recording active */
    res = vs1053b_set_pcm_adpcm_recording_active(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set pcm adpcm recording active failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable pcm adpcm recording active.\n");
    
    /* get pcm adpcm recording active */
    res = vs1053b_get_pcm_adpcm_recording_active(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get pcm adpcm recording active failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check pcm adpcm recording active %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable pcm adpcm recording active */
    res = vs1053b_set_pcm_adpcm_recording_active(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set pcm adpcm recording active failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable pcm adpcm recording active.\n");
    
    /* get pcm adpcm recording active */
    res = vs1053b_get_pcm_adpcm_recording_active(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get pcm adpcm recording active failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check pcm adpcm recording active %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_selector/vs1053b_get_selector test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_selector/vs1053b_get_selector test.\n");
    
    /* microphone */
    res = vs1053b_set_selector(&gs_handle, VS1053B_SELECTOR_MICP);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set selector microphone.\n");
    
    /* get selector */
    res = vs1053b_get_selector(&gs_handle, &selector);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get selector failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check selector %s.\n", selector == VS1053B_SELECTOR_MICP ? "ok" : "error");
    
    /* line1 */
    res = vs1053b_set_selector(&gs_handle, VS1053B_SELECTOR_LINE1);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set selector line1.\n");
    
    /* get selector */
    res = vs1053b_get_selector(&gs_handle, &selector);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get selector failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check selector %s.\n", selector == VS1053B_SELECTOR_LINE1 ? "ok" : "error");
    
    /* vs1053b_set_clock_range/vs1053b_get_clock_range test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_clock_range/vs1053b_get_clock_range test.\n");

    /* 12MHz - 13MHz */
    res = vs1053b_set_clock_range(&gs_handle, VS1053B_CLOCK_RANGE_12MHZ_13MHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock range failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock range 12MHz - 13MHz.\n");
    
    /* get clock range */
    res = vs1053b_get_clock_range(&gs_handle, &range);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock range failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock range %s.\n", range == VS1053B_CLOCK_RANGE_12MHZ_13MHZ ? "ok" : "error");
    
    /* vs1053b_set_do_not_jump/vs1053b_get_do_not_jump test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_do_not_jump/vs1053b_get_do_not_jump test.\n");
    
    /* enable do not jump */
    res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable do not jump.\n");
    
    /* get do not jump */
    res = vs1053b_get_do_not_jump(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get do not jump failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check do not jump %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable do not jump */
    res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable do not jump.\n");
    
    /* get do not jump */
    res = vs1053b_get_do_not_jump(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get do not jump failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check do not jump %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_swing/vs1053b_get_swing test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_swing/vs1053b_get_swing test.\n");
    
    /* set swing random */
    reg = rand() % 8;
    res = vs1053b_set_swing(&gs_handle,  reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set swing failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set swing 0x%02X.\n", reg);
    
    /* get swing */
    res = vs1053b_get_swing(&gs_handle, &reg_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get swing failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check swing %s.\n", reg == reg_check ? "ok" : "error");
    
    /* vs1053b_set_overload_indicator/vs1053b_get_overload_indicator test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_overload_indicator/vs1053b_get_overload_indicator test.\n");
    
    /* disable overload indicator */
    res = vs1053b_set_overload_indicator(&gs_handle,  VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set overload indicator failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable overload indicator.\n");
    
    /* get overload indicator */
    res = vs1053b_get_overload_indicator(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get overload indicator failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check overload indicator %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_overload_detection/vs1053b_get_overload_detection test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_overload_detection/vs1053b_get_overload_detection test.\n");
    
    /* enable overload detection */
    res = vs1053b_set_overload_detection(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable overload detection.\n");
    
    /* get overload detection */
    res = vs1053b_get_overload_detection(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get overload detection failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check overload indicator %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable overload detection */
    res = vs1053b_set_overload_detection(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable overload detection.\n");
    
    /* get overload detection */
    res = vs1053b_get_overload_detection(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get overload detection failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check overload indicator %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_get_version test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_get_version test.\n");
    
    /* get version */
    res = vs1053b_get_version(&gs_handle, &version);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get version failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: version is 0x%02X.\n", version);
    
    /* vs1053b_set_analog_driver_power_down/vs1053b_get_analog_driver_power_down test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_analog_driver_power_down/vs1053b_get_analog_driver_power_down test.\n");
    
    /* enable analog driver power down */
    res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: enable analog driver power down.\n");
    
    /* get analog driver power down */
    res = vs1053b_get_analog_driver_power_down(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get analog driver power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check analog driver power down %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable analog driver power down */
    res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable analog driver power down.\n");
    
    /* get analog driver power down */
    res = vs1053b_get_analog_driver_power_down(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get analog driver power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check analog driver power down %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_analog_internal_power_down/vs1053b_get_analog_internal_power_down test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_analog_internal_power_down/vs1053b_get_analog_internal_power_down test.\n");
    
    /* disable analog internal power down */
    res = vs1053b_set_analog_internal_power_down(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set analog internal power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: disable analog internal power down.\n");
    
    /* get analog internal power down */
    res = vs1053b_get_analog_internal_power_down(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get analog internal power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check analog internal power down %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_ad_clock/vs1053b_get_ad_clock test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_ad_clock/vs1053b_get_ad_clock test.\n");
    
    /* ad clock 6mhz */
    res = vs1053b_set_ad_clock(&gs_handle, VS1053B_AD_CLOCK_6MHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ad clock failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set ad clock 6mhz.\n");
    
    /* get ad clock */
    res = vs1053b_get_ad_clock(&gs_handle, &ad_clock);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get ad clock failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ad clock %s.\n", ad_clock == VS1053B_AD_CLOCK_6MHZ ? "ok" : "error");
    
    /* vs1053b_set_reference_voltage/vs1053b_get_reference_voltage test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_reference_voltage/vs1053b_get_reference_voltage test.\n");
    
    /* set reference voltage 1.23V */
    res = vs1053b_set_reference_voltage(&gs_handle, VS1053B_REFERENCE_VOLTAGE_1P23V);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set reference voltage failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set reference voltage 1.23V.\n");
    
    /* get reference voltage */
    res = vs1053b_get_reference_voltage(&gs_handle, &voltage);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get reference voltage failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check reference voltage %s.\n", voltage == VS1053B_REFERENCE_VOLTAGE_1P23V ? "ok" : "error");
    
    /* vs1053b_set_treble_control/vs1053b_get_treble_control test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_treble_control/vs1053b_get_treble_control test.\n");
    
    /* set treble control random */
    reg = rand() % 16;
    res = vs1053b_set_treble_control(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set treble control failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set treble control 0x%02X.\n", reg);
    
    /* get treble control */
    res = vs1053b_get_treble_control(&gs_handle, &reg_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get treble control failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check treble control %s.\n", reg_check == reg ? "ok" : "error");
    
    /* vs1053b_set_lower_limit_frequency_in_1000_hz/vs1053b_get_lower_limit_frequency_in_1000_hz test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_lower_limit_frequency_in_1000_hz/vs1053b_get_lower_limit_frequency_in_1000_hz test.\n");
    
    /* set lower limit frequency in 1000 hz random */
    reg = rand() % 16;
    res = vs1053b_set_lower_limit_frequency_in_1000_hz(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 1000 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 1000 hz 0x%02X.\n", reg);
    
    /* get lower limit frequency in 1000 hz */
    res = vs1053b_get_lower_limit_frequency_in_1000_hz(&gs_handle, &reg_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get lower limit frequency in 1000 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check lower limit frequency in 1000 hz %s.\n", reg_check == reg ? "ok" : "error");
    
    /* vs1053b_set_bass_enhancement/vs1053b_get_bass_enhancement test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_bass_enhancement/vs1053b_get_bass_enhancement test.\n");
    
    /* set bass enhancement random */
    reg = rand() % 16;
    res = vs1053b_set_bass_enhancement(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set bass enhancement failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set bass enhancement 0x%02X.\n", reg);
    
    /* get bass enhancement */
    res = vs1053b_get_bass_enhancement(&gs_handle, &reg_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get bass enhancement failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check bass enhancement %s.\n", reg_check == reg ? "ok" : "error");
    
    /* vs1053b_set_lower_limit_frequency_in_10_hz/vs1053b_get_lower_limit_frequency_in_10_hz test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_lower_limit_frequency_in_10_hz/vs1053b_get_lower_limit_frequency_in_10_hz test.\n");
    
    /* set lower limit frequency in 10 hz random */
    reg = rand() % 16;
    res = vs1053b_set_lower_limit_frequency_in_10_hz(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 10 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 10 hz 0x%02X.\n", reg);
    
    /* get lower limit frequency in 10 hz */
    res = vs1053b_get_lower_limit_frequency_in_10_hz(&gs_handle, &reg_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get lower limit frequency in 10 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check lower limit frequency in 10 hz %s.\n", reg_check == reg ? "ok" : "error");
    
    /* vs1053b_set_clock_multiplier/vs1053b_get_clock_multiplier test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_clock_multiplier/vs1053b_get_clock_multiplier test.\n");
    
    /* set clock multiplier 1.0 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_1P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 1.0 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_1P0_XTALI ? "ok" : "error");
    
    /* set clock multiplier 2.0 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_2P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 2.0 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_2P0_XTALI ? "ok" : "error");
    
    /* set clock multiplier 2.5 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_2P5_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 2.5 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_2P5_XTALI ? "ok" : "error");
    
    /* set clock multiplier 3.0 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_3P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 3.0 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_3P0_XTALI ? "ok" : "error");
    
    /* set clock multiplier 3.5 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_3P5_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 3.5 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_3P5_XTALI ? "ok" : "error");
    
    /* set clock multiplier 4.0 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_4P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 4.0 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_4P0_XTALI ? "ok" : "error");
    
    /* set clock multiplier 4.5 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_4P5_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 4.5 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_4P5_XTALI ? "ok" : "error");
    
    /* set clock multiplier 5.0 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_5P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock multiplier 5.0 xtali.\n");
    
    /* get clock multiplier */
    res = vs1053b_get_clock_multiplier(&gs_handle, &multiplier);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock multiplier %s.\n", multiplier == VS1053B_CLOCK_MULTIPLIER_5P0_XTALI ? "ok" : "error");
    
    /* vs1053b_set_allowed_multiplier_addition/vs1053b_get_allowed_multiplier_addition test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_allowed_multiplier_addition/vs1053b_get_allowed_multiplier_addition test.\n");
    
    /* set allowed multiplier addition no modification */
    res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_ALLOWED_MULTIPLIER_ADDITION_NONE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition no modification.\n");
    
    /* get allowed multiplier addition */
    res = vs1053b_get_allowed_multiplier_addition(&gs_handle, &addition);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allowed multiplier addition %s.\n", addition == VS1053B_ALLOWED_MULTIPLIER_ADDITION_NONE ? "ok" : "error");
    
    /* set allowed multiplier addition 1.0 xtali */
    res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition 1.0 xtali.\n");
    
    /* get allowed multiplier addition */
    res = vs1053b_get_allowed_multiplier_addition(&gs_handle, &addition);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allowed multiplier addition %s.\n", addition == VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P0_XTALI ? "ok" : "error");
    
    /* set allowed multiplier addition 1.5 xtali */
    res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P5_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition 1.5 xtali.\n");
    
    /* get allowed multiplier addition */
    res = vs1053b_get_allowed_multiplier_addition(&gs_handle, &addition);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allowed multiplier addition %s.\n", addition == VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P5_XTALI ? "ok" : "error");
    
    /* set allowed multiplier addition 2.0 xtali */
    res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_ALLOWED_MULTIPLIER_ADDITION_2P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition 2.0 xtali.\n");
    
    /* get allowed multiplier addition */
    res = vs1053b_get_allowed_multiplier_addition(&gs_handle, &addition);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check allowed multiplier addition %s.\n", addition == VS1053B_ALLOWED_MULTIPLIER_ADDITION_2P0_XTALI ? "ok" : "error");
    
    /* vs1053b_set_clock_frequency/vs1053b_get_clock_frequency test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_clock_frequency/vs1053b_get_clock_frequency test.\n");
    
    /* set clock frequency random */
    clk = rand() % 0x400;
    res = vs1053b_set_clock_frequency(&gs_handle, clk);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock frequency failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set clock frequency 0x%03X.\n", clk);
    
    /* get clock frequency */
    res = vs1053b_get_clock_frequency(&gs_handle, &clk_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get clock frequency failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check clock frequency %s.\n", clk == clk_check ? "ok" : "error");
    
    /* vs1053b_set_decode_time/vs1053b_get_decode_time test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_decode_time/vs1053b_get_decode_time test.\n");
    
    /* set decode time random */
    decode_time = rand() % 100;
    res = vs1053b_set_decode_time(&gs_handle, decode_time);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set decode time failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set decode time %d.\n", decode_time);
    
    /* get decode time */
    res = vs1053b_get_decode_time(&gs_handle, &decode_time_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get decode time failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check decode time %s.\n", decode_time == decode_time_check ? "ok" : "error");
    
    /* vs1053b_set_sample_rate/vs1053b_get_sample_rate test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_sample_rate/vs1053b_get_sample_rate test.\n");
    
    /* set sample rate random */
    rate = rand() % 0xFFF;
    if ((rate % 2) != 0)
    {
        rate++;
    }
    res = vs1053b_set_sample_rate(&gs_handle, rate, VS1053B_CHANNEL_MONO);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set sample rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set mono sample rate %d.\n", rate);
    
    /* get sample rate */
    res = vs1053b_get_sample_rate(&gs_handle, &rate_check, &channel);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get sample rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check sample rate %s.\n", (rate == rate_check) ? "ok" : "error");
    
    /* set sample rate random */
    rate = rand() % 0xFFF;
    if ((rate % 2) != 0)
    {
        rate++;
    }
    res = vs1053b_set_sample_rate(&gs_handle, rate, VS1053B_CHANNEL_STEREO);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set sample rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set stereo sample rate %d.\n", rate);
    
    /* get sample rate */
    res = vs1053b_get_sample_rate(&gs_handle, &rate_check, &channel);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get sample rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check sample rate %s.\n", (rate == rate_check) ? "ok" : "error");
    
    /* vs1053b_set_ram_address test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_ram_address test.\n");
    
    /* set ram address */
    res = vs1053b_set_ram_address(&gs_handle, 0x1800);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ram address failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ram address %s.\n", (res == 0) ? "ok" : "error");
    
    /* vs1053b_write_ram/vs1053b_read_ram test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_write_ram/vs1053b_read_ram test.\n");
    
    /* write ram */
    buf[0] = 0x01;
    buf[1] = 0x23;
    res = vs1053b_write_ram(&gs_handle, buf, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: write ram failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: write ram 0x%02X 0x%02X.\n", buf[0], buf[1]);
    
    /* read ram */
    res = vs1053b_read_ram(&gs_handle, buf_check, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: read ram failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check ram %s.\n", ((buf[0] == buf_check[0]) && (buf[1] == buf_check[1])) ? "ok" : "error");
    
    /* vs1053b_set_start_address/vs1053b_get_start_address test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_start_address/vs1053b_get_start_address test.\n");
    
    /* set start address random */
    addr = rand() % 10;
    res = vs1053b_set_start_address(&gs_handle, addr);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set start address failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set start address 0x%02X.\n", addr);
    
    /* get start address */
    res = vs1053b_get_start_address(&gs_handle, &addr_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get start address failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check start address %s.\n", (addr == addr_check) ? "ok" : "error");
    
    /* vs1053b_set_vol/vs1053b_get_vol test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_vol/vs1053b_get_vol test.\n");
    
    /* set vol random */
    left = rand() % 256;
    right = rand() % 256;
    res = vs1053b_set_vol(&gs_handle, left, right);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set vol failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set vol left 0x%02X.\n", left);
    vs1053b_interface_debug_print("vs1053b: set vol left 0x%02X.\n", right);
    
    /* get vol */
    res = vs1053b_get_vol(&gs_handle, &left_check, &right_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get vol failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check vol left %s.\n", (left == left_check) ? "ok" : "error");
    vs1053b_interface_debug_print("vs1053b: check vol left %s.\n", (right == right_check) ? "ok" : "error");
    
    /* vs1053b_get_hdata test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_get_hdata test.\n");
    
    /* get hdata */
    res = vs1053b_get_hdata(&gs_handle, &dat0, &dat1);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get hdata failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: dat0 is 0x%02X, dat1 is 0x%02X.\n", dat0, dat1);
    
    /* vs1053b_write_application/vs1053b_read_application test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_write_application/vs1053b_read_application test.\n");
    
    /* write application */
    buf[0] = rand() % 256;
    buf[1] = rand() % 256;
    res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_0, buf, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: write application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: write application 0 0x%02X 0x%02X.\n", buf[0], buf[1]);
    
    /* read application */
    res = vs1053b_read_application(&gs_handle, VS1053B_APPLICATION_0, buf_check, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: read application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check application %s.\n", ((buf[0] == buf_check[0]) && (buf[1] == buf_check[1])) ? "ok" : "error");
    
    /* write application */
    buf[0] = rand() % 256;
    buf[1] = rand() % 256;
    res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_1, buf, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: write application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: write application 1 0x%02X 0x%02X.\n", buf[0], buf[1]);
    
    /* read application */
    res = vs1053b_read_application(&gs_handle, VS1053B_APPLICATION_1, buf_check, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: read application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check application %s.\n", ((buf[0] == buf_check[0]) && (buf[1] == buf_check[1])) ? "ok" : "error");
    
    /* write application */
    buf[0] = rand() % 256;
    buf[1] = rand() % 256;
    res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_2, buf, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: write application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: write application 2 0x%02X 0x%02X.\n", buf[0], buf[1]);
    
    /* read application */
    res = vs1053b_read_application(&gs_handle, VS1053B_APPLICATION_2, buf_check, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: read application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check application %s.\n", ((buf[0] == buf_check[0]) && (buf[1] == buf_check[1])) ? "ok" : "error");
    
    /* write application */
    buf[0] = rand() % 256;
    buf[1] = rand() % 256;
    res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_3, buf, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: write application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: write application 3 0x%02X 0x%02X.\n", buf[0], buf[1]);
    
    /* read application */
    res = vs1053b_read_application(&gs_handle, VS1053B_APPLICATION_3, buf_check, 2);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: read application failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check application %s.\n", ((buf[0] == buf_check[0]) && (buf[1] == buf_check[1])) ? "ok" : "error");
    
    /* vs1053b_set_play_speed/vs1053b_get_play_speed test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_play_speed/vs1053b_get_play_speed test.\n");
    
    /* set play speed 1x */
    res = vs1053b_set_play_speed(&gs_handle, VS1053B_PLAY_SPEED_1_X);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set play speed 1x.\n");
    
    /* get play speed */
    res = vs1053b_get_play_speed(&gs_handle, &speed);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check play speed %s.\n", (speed == VS1053B_PLAY_SPEED_1_X) ? "ok" : "error");
    
    /* set play speed 1.0x */
    res = vs1053b_set_play_speed(&gs_handle, VS1053B_PLAY_SPEED_1P0_X);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set play speed 1.0x.\n");
    
    /* get play speed */
    res = vs1053b_get_play_speed(&gs_handle, &speed);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check play speed %s.\n", (speed == VS1053B_PLAY_SPEED_1P0_X) ? "ok" : "error");
    
    /* set play speed 2.0x */
    res = vs1053b_set_play_speed(&gs_handle, VS1053B_PLAY_SPEED_2P0_X);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set play speed 2.0x.\n");
    
    /* get play speed */
    res = vs1053b_get_play_speed(&gs_handle, &speed);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check play speed %s.\n", (speed == VS1053B_PLAY_SPEED_2P0_X) ? "ok" : "error");
    
    /* set play speed 3.0x */
    res = vs1053b_set_play_speed(&gs_handle, VS1053B_PLAY_SPEED_3P0_X);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* output */
    vs1053b_interface_debug_print("vs1053b: set play speed 3.0x.\n");
    
    /* get play speed */
    res = vs1053b_get_play_speed(&gs_handle, &speed);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check play speed %s.\n", (speed == VS1053B_PLAY_SPEED_3P0_X) ? "ok" : "error");
    
    /* vs1053b_get_byte_rate test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_get_byte_rate test.\n");
    
    /* get byte rate */
    res = vs1053b_get_byte_rate(&gs_handle, &clk);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get byte rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: byte rate is %d.\n", clk);
    
    /* vs1053b_get_end_fill_byte test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_get_end_fill_byte test.\n");
    
    /* get end fill byte */
    res = vs1053b_get_end_fill_byte(&gs_handle, &byte);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get end fill byte failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: end fill byte is %d.\n", byte);
    
    /* vs1053b_swing_convert_to_register/vs1053b_swing_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_swing_convert_to_register/vs1053b_swing_convert_to_data test.\n");
    
    db = 2.0f;
    res = vs1053b_swing_convert_to_register(&gs_handle, db, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: swing convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_swing_convert_to_data(&gs_handle, reg, &db_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: swing convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: swing convert check %0.2f and %0.2f.\n", db, db_check);
    
    /* vs1053b_treble_control_convert_to_register/vs1053b_treble_control_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_treble_control_convert_to_register/vs1053b_treble_control_convert_to_data test.\n");
    
    db = 4.5f;
    res = vs1053b_treble_control_convert_to_register(&gs_handle, db, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: treble control convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_treble_control_convert_to_data(&gs_handle, reg, &db_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: treble control convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: treble control convert check %0.2f and %0.2f.\n", db, db_check);
    
    /* vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register/vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register/vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data test.\n");
    
    hz = 2000;
    res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(&gs_handle, hz, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 1000 hz convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data(&gs_handle, reg, &hz_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 1000 hz convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: lower limit frequency in 1000 hz convert check %d and %d.\n", hz, hz_check);
    
    /* vs1053b_lower_limit_frequency_in_10_hz_convert_to_register/vs1053b_lower_limit_frequency_in_10_hz_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_lower_limit_frequency_in_10_hz_convert_to_register/vs1053b_lower_limit_frequency_in_10_hz_convert_to_data test.\n");
    
    hz = 50;
    res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(&gs_handle, hz, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 10 hz convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_data(&gs_handle, reg, &hz_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 10 hz convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: lower limit frequency in 10 hz convert check %d and %d.\n", hz, hz_check);
    
    /* vs1053b_clock_frequency_convert_to_register/vs1053b_clock_frequency_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_clock_frequency_convert_to_register/vs1053b_clock_frequency_convert_to_data test.\n");
    
    db = 12000000.0f;
    res = vs1053b_clock_frequency_convert_to_register(&gs_handle, db, &clk);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: clock frequency convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_clock_frequency_convert_to_data(&gs_handle, clk, &db_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: clock frequency convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: clock frequency convert check %0.2f and %0.2f.\n", db, db_check);
    
    /* vs1053b_vol_convert_to_register/vs1053b_vol_convert_to_data test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_vol_convert_to_register/vs1053b_vol_convert_to_data test.\n");
    
    db = 3.5f;
    res = vs1053b_vol_convert_to_register(&gs_handle, db, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: vol convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    res = vs1053b_vol_convert_to_data(&gs_handle, reg, &db_check);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: vol convert to data failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: vol convert check %0.2f and %0.2f.\n", db, db_check);
    
    /* vs1053b_set_iis_mclk/vs1053b_get_iis_mclk test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_iis_mclk/vs1053b_get_iis_mclk test.\n");
    
    /* enable iis mclk */
    res = vs1053b_set_iis_mclk(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis mclk failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: enable iis mclk.\n");
    res = vs1053b_get_iis_mclk(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis mclk failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis mclk %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable iis mclk */
    res = vs1053b_set_iis_mclk(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis mclk failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: disable iis mclk.\n");
    res = vs1053b_get_iis_mclk(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis mclk failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis mclk %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_iis/vs1053b_get_iis test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_iis/vs1053b_get_iis test.\n");
    
    /* enable iis */
    res = vs1053b_set_iis(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: enable iis.\n");
    res = vs1053b_get_iis(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis %s.\n", enable == VS1053B_BOOL_TRUE ? "ok" : "error");
    
    /* disable iis */
    res = vs1053b_set_iis(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: disable iis.\n");
    res = vs1053b_get_iis(&gs_handle, &enable);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis %s.\n", enable == VS1053B_BOOL_FALSE ? "ok" : "error");
    
    /* vs1053b_set_iis_rate/vs1053b_get_iis_rate test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_iis_rate/vs1053b_get_iis_rate test.\n");
    
    /* set iis rate 48khz */
    res = vs1053b_set_iis_rate(&gs_handle, VS1053B_IIS_RATE_48KHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: set iis rate 48khz.\n");
    res = vs1053b_get_iis_rate(&gs_handle, &iis_rate);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis rate %s.\n", iis_rate == VS1053B_IIS_RATE_48KHZ ? "ok" : "error");
    
    /* set iis rate 96khz */
    res = vs1053b_set_iis_rate(&gs_handle, VS1053B_IIS_RATE_96KHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: set iis rate 96hz.\n");
    res = vs1053b_get_iis_rate(&gs_handle, &iis_rate);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis rate %s.\n", iis_rate == VS1053B_IIS_RATE_96KHZ ? "ok" : "error");
    
    /* set iis rate 192khz */
    res = vs1053b_set_iis_rate(&gs_handle, VS1053B_IIS_RATE_192KHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: set iis rate 192hz.\n");
    res = vs1053b_get_iis_rate(&gs_handle, &iis_rate);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check iis rate %s.\n", iis_rate == VS1053B_IIS_RATE_192KHZ ? "ok" : "error");
    
    /* vs1053b_set_gpio_direction/vs1053b_get_gpio_direction test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_gpio_direction/vs1053b_get_gpio_direction test.\n");
    
    /* set gpio direction 0x00F0 */
    res = vs1053b_set_gpio_direction(&gs_handle, 0x00F0);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set gpio direction failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: set gpio direction 0x00F0.\n");
    res = vs1053b_get_gpio_direction(&gs_handle, &dat0);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get gpio direction failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check gpio direction %s.\n", dat0 == 0x00F0 ? "ok" : "error");
    
    /* vs1053b_set_gpio_output/vs1053b_get_gpio_output test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_set_gpio_output/vs1053b_get_gpio_output test.\n");
    
    /* set gpio output 0x0010 */
    res = vs1053b_set_gpio_output(&gs_handle, 0x0010);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set gpio output failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: set gpio output 0x0010.\n");
    res = vs1053b_get_gpio_output(&gs_handle, &dat0);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get gpio output failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: check gpio output %s.\n", dat0 == 0x0010 ? "ok" : "error");
    
    /* vs1053b_get_gpio_input test */
    vs1053b_interface_debug_print("vs1053b: vs1053b_get_gpio_input test.\n");
    
    /* get gpio input */
    res = vs1053b_get_gpio_input(&gs_handle, &dat0);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: get gpio input failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    vs1053b_interface_debug_print("vs1053b: gpio input is 0x%04X.\n", dat0);
    
    /* soft reset */
    res = vs1053b_set_soft_reset(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set soft reset failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* hard reset */
    res = vs1053b_hard_reset(&gs_handle);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: hard reset failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* finish register */
    vs1053b_interface_debug_print("vs1053b: finish register test.\n");
    (void)vs1053b_deinit(&gs_handle);
    
    return 0;
}
