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
 * @file      driver_vs1053b_play_test.c
 * @brief     driver vs1053b play test source file
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
 
#include "driver_vs1053b_play_test.h"
#include <stdlib.h>

static vs1053b_handle_t gs_handle;        /**< vs1053b handle */
static volatile uint8_t gs_flag = 0;      /**< end of test */

/**
 * @brief     interface receive callback
 * @param[in] type is the receive callback type
 * @param[in] cur_pos is the current position
 * @note      none
 */
static void a_callback(uint8_t type, uint32_t cur_pos)
{
    uint8_t res;
    
    switch (type)
    {
        case VS1053B_TYPE_PLAY_READ :
        {
            break;
        }
        case VS1053B_TYPE_PLAY_WRITE :
        {
            break;
        }
        case VS1053B_TYPE_PLAY_END :
        {
            gs_flag = 1;
            vs1053b_interface_debug_print("vs1053b: irq play end with %d.\n", cur_pos);
            
            break;
        }
        case VS1053B_TYPE_RECORD_READ :
        {
            break;
        }
        case VS1053B_TYPE_RECORD_WRITE :
        {
            break;
        }
        case VS1053B_TYPE_RECORD_END :
        {
            break;
        }
        case VS1053B_TYPE_RECORD_OVER :
        {
            break;
        }
        case VS1053B_TYPE_PERIOD :
        {
            uint16_t decode_time;
            uint16_t dat0;
            uint16_t dat1;
            uint16_t rate;
            vs1053b_channel_t channel;
            vs1053b_audio_info_t info;
            
            /* get decode time */
            res = vs1053b_get_decode_time(&gs_handle, &decode_time);
            if (res == 0)
            {
                vs1053b_interface_debug_print("\nvs1053b: play time is %02d:%02d:%02d.\n", 
                                             (decode_time % 86400) / 3600, (decode_time % 3600) / 60, decode_time % 60);
            }
            
            /* get byte rate */
            res = vs1053b_get_byte_rate(&gs_handle, &rate);
            if (res == 0)
            {
                vs1053b_interface_debug_print("vs1053b: byte rate is %d bytes/sec.\n", rate);
            }
            
            /* get sample rate */
            res = vs1053b_get_sample_rate(&gs_handle, &rate, &channel);
            if (res == 0)
            {
                vs1053b_interface_debug_print("vs1053b: sample rate is %dHz, channel is %d.\n", rate, (uint8_t)(channel + 1));
            }
            
            /* get hdata */
            res = vs1053b_get_hdata(&gs_handle, &dat0, &dat1);
            if (res == 0)
            {
                /* parse info */
                (void)vs1053b_parse_info(&gs_handle, dat0, dat1, &info);
                vs1053b_interface_debug_print("vs1053b: format is %s, rate is %0.0fkbps.\n", info.format_name, info.kbps);
            }
            
            break;
        }
        default :
        {
            vs1053b_interface_debug_print("vs1053b: unknown type.\n");
            
            break;
        }
    }
}

/**
 * @brief     play test
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t vs1053b_play_test(char *path)
{
    uint8_t res;
    uint8_t reg;
    uint16_t clk;
    vs1053b_info_t info;
    
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
    DRIVER_VS1053B_LINK_RECEIVE_CALLBACK(&gs_handle, a_callback);
    
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
    
    /* start play test */
    vs1053b_interface_debug_print("vs1053b: start play test.\n");
    
    /* vs1053b init */
    res = vs1053b_init(&gs_handle);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: init failed.\n");
        
        return 1;
    }
    
    /* 3.5 xtali */
    res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_CLOCK_MULTIPLIER_3P5_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 2.0 xtali */
    res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_ALLOWED_MULTIPLIER_ADDITION_2P0_XTALI);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 8000000hz */
    res = vs1053b_clock_frequency_convert_to_register(&gs_handle, 8000000.0f, &clk);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: clock frequency convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set clock frequency */
    res = vs1053b_set_clock_frequency(&gs_handle, clk);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock frequency failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* diff normal mode */
    res = vs1053b_set_diff(&gs_handle, VS1053B_DIFF_NORMAL);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* enable mpeg layer i and ii */
    res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable cancel decoding current file */
    res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable ear speaker low setting */
    res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker low setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable allow sdi test */
    res = vs1053b_set_allow_sdi_test(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set allow sdi test failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable stream mode */
    res = vs1053b_set_stream_mode(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set stream mode failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable ear speaker high setting */
    res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* rising dclk edge */
    res = vs1053b_set_dclk_edge(&gs_handle, VS1053B_DCLK_EDGE_RISING);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set dclk edge failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* sdi bit order msb */
    res = vs1053b_set_sdi_bit_order(&gs_handle, VS1053B_BIT_ORDER_MSB_FIRST);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set sdi bit order failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable share spi chip select */
    res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set share spi chip select failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* enable native spi modes */
    res = vs1053b_set_native_spi_modes(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set native spi modes failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable pcm adpcm recording active */
    res = vs1053b_set_pcm_adpcm_recording_active(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set pcm adpcm recording active failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* microphone */
    res = vs1053b_set_selector(&gs_handle, VS1053B_SELECTOR_MICP);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* 12MHz - 13MHz */
    res = vs1053b_set_clock_range(&gs_handle, VS1053B_CLOCK_RANGE_12MHZ_13MHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set clock range failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable do not jump */
    res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* 0.0f */
    res = vs1053b_swing_convert_to_register(&gs_handle, 0.0f, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: swing convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* set swing */
    res = vs1053b_set_swing(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set swing failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* enable overload detection */
    res = vs1053b_set_overload_detection(&gs_handle,VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable analog driver power down */
    res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* disable analog internal power down */
    res = vs1053b_set_analog_internal_power_down(&gs_handle, VS1053B_BOOL_FALSE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set analog internal power down failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* ad clock 6mhz */
    res = vs1053b_set_ad_clock(&gs_handle, VS1053B_AD_CLOCK_6MHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set ad clock failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* 1.23v */
    res = vs1053b_set_reference_voltage(&gs_handle, VS1053B_REFERENCE_VOLTAGE_1P23V);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set reference voltage failed.\n");
        (void)vs1053b_deinit(&gs_handle);
        
        return 1;
    }
    
    /* 22.5db */
    res = vs1053b_treble_control_convert_to_register(&gs_handle, 22.5f, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: treble control convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set treble control */
    res = vs1053b_set_treble_control(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set treble control failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 10khz */
    res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(&gs_handle, 10000, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 1000 hz convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set lower limit frequency in 1000 hz */
    res = vs1053b_set_lower_limit_frequency_in_1000_hz(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 1000 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 15db */
    res = vs1053b_set_bass_enhancement(&gs_handle, 15);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set bass enhancement failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 60hz */
    res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(&gs_handle, 60, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: lower limit frequency in 10 hz convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set lower limit frequency in 10 hz */
    res = vs1053b_set_lower_limit_frequency_in_10_hz(&gs_handle, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set lower limit frequency in 10 hz failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* init 0x0000 */
    res = vs1053b_set_decode_time(&gs_handle, 0x0000);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set decode time failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* -10.0db */
    res = vs1053b_vol_convert_to_register(&gs_handle, -10.0f, &reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: vol convert to register failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set vol */
    res = vs1053b_set_vol(&gs_handle, reg, reg);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set vol failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 1.0x */
    res = vs1053b_set_play_speed(&gs_handle, VS1053B_PLAY_SPEED_1P0_X);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set iis gpio direction */
    res = vs1053b_set_gpio_direction(&gs_handle, 0x00F0);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set gpio direction failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* enable iis mclk */
    res = vs1053b_set_iis_mclk(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis mclk failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* set iis rate 48khz */
    res = vs1053b_set_iis_rate(&gs_handle, VS1053B_IIS_RATE_48KHZ);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis rate failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* enable iis */
    res = vs1053b_set_iis(&gs_handle, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set iis failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* 5s */
    res = vs1053b_set_period_callback(&gs_handle, 5, 0, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: set period callback failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* if flac format, load the flac patch */
    if (strstr(path, ".flac") != NULL)
    {
        const uint16_t *patch_addr;
        uint16_t l;
        
        /* get flac patch */
        res = vs1053b_get_patch(&gs_handle, VS1053B_PATCH_FLAC, &patch_addr, &l);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: get patch failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* load flac patch */
        res = vs1053b_load_patch(&gs_handle, patch_addr, l);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: load patch failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
    }
    
    /* play music */
    res = vs1053b_play(&gs_handle, path);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: play failed.\n");
        (void)vs1053b_deinit(&gs_handle);
         
        return 1;
    }
    
    /* clear flag */
    gs_flag = 0;
    
    /* run the server and wait for the end */
    while (gs_flag == 0)
    {
        (void)vs1053b_process(&gs_handle);
    }

    /* finish play */
    vs1053b_interface_debug_print("vs1053b: finish play test.\n");
    (void)vs1053b_deinit(&gs_handle);
    
    return 0;
}
