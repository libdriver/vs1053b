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
 * @file      driver_vs1053b_basic.c
 * @brief     driver vs1053b basic source file
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
 
#include "driver_vs1053b_basic.h"
#include <stdlib.h>

static vs1053b_handle_t gs_handle;        /**< vs1053b handle */

/**
 * @brief     basic example init
 * @param[in] mode is the chip working mode
 * @param[in] format is the set record format
 * @param[in] *callback points to a callback function
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t vs1053b_basic_init(vs1053b_mode_t mode, vs1053b_record_format_t format, void (*callback)(uint8_t type, uint32_t cur_pos))
{
    uint8_t res;
    uint8_t reg;
    uint8_t buf[2];
    uint16_t clk;
    uint16_t config;
    
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
    DRIVER_VS1053B_LINK_RECEIVE_CALLBACK(&gs_handle, callback);
    
    /* vs1053b init */
    res = vs1053b_init(&gs_handle);
    if (res != 0)
    {
        vs1053b_interface_debug_print("vs1053b: init failed.\n");
        
        return 1;
    }
    
    /* play mode */
    if (mode == VS1053B_MODE_PLAY)
    {
        /* set default play clock multiplier */
        res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_CLOCK_MULTIPLIER);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default play allowed multiplier addition */
        res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_ALLOWED_MULTIPLIER_ADDITION);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default play clock frequency */
        res = vs1053b_clock_frequency_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_CLOCK_FREQUENCY, &clk);
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
        
        /* set default play diff */
        res = vs1053b_set_diff(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_DIFF);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play mpeg layer i and ii */
        res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_MPEG_LAYER_I_AND_II);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play cancel decoding current file */
        res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_CANCEL_DECODING_CURRENT_FILE);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play ear speaker low setting */
        res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_EAR_SPEAKER_LOW_SETTING);
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
        
        /* set default play ear speaker high setting */
        res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_EAR_SPEAKER_HIGH_SETTING);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play dclk edge */
        res = vs1053b_set_dclk_edge(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_DCLK_EDGE);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set dclk edge failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play sdi bit order */
        res = vs1053b_set_sdi_bit_order(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_BIT_ORDER);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set sdi bit order failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play share spi chip select */
        res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_SHARE_SPI_CHIP_SELECT);
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
        
        /* set default play selector */
        res = vs1053b_set_selector(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_SELECTOR);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play clock range */
        res = vs1053b_set_clock_range(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_CLOCK_RANGE);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set clock range failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play do not jump */
        res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_DO_NOT_JUMP);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play swing */
        res = vs1053b_swing_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_SWING, &reg);
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
        
        /* set default play overload detection */
        res = vs1053b_set_overload_detection(&gs_handle,VS1053B_BASIC_DEFAULT_PLAY_OVERLOAD_DETECTION);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play analog driver power down */
        res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_ANALOG_DRIVER_POWER_DOWN);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play analog internal power down */
        res = vs1053b_set_analog_internal_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_ANALOG_INTERNAL_POWER_DOWN);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set analog internal power down failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play ad clock */
        res = vs1053b_set_ad_clock(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_AD_CLOCK);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set ad clock failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play reference voltage */
        res = vs1053b_set_reference_voltage(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_REFERENCE_VOLTAGE);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set reference voltage failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set default play treble control */
        res = vs1053b_treble_control_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_TREBLE_CONTROL, &reg);
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
        
        /* set default play lower limit frequency in 1000 hz */
        res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_LOWER_LIMIT_FREQUENCY_IN_1000_HZ, &reg);
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
        
        /* set default play bass enhancement */
        res = vs1053b_set_bass_enhancement(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_BASS_ENHANCEMENT);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set bass enhancement failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default play lower limit frequency in 10 hz */
        res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_LOWER_LIMIT_FREQUENCY_IN_10_HZ, &reg);
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
        
        /* set default play vol */
        res = vs1053b_vol_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_VOL, &reg);
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
        
        /* set default play speed */
        res = vs1053b_set_play_speed(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_SPEED);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set play speed failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
    #if (VS1053B_BASIC_DEFAULT_PLAY_IIS_OUTPUT == VS1053B_BOOL_TRUE)
        /* set default gpio direction */
        res = vs1053b_set_gpio_direction(&gs_handle, 0x00F0);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set gpio direction failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default iis mclk */
        res = vs1053b_set_iis_mclk(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_IIS_MCLK_OUTPUT);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set iis mclk failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default iis rate */
        res = vs1053b_set_iis_rate(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_IIS_RATE);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set iis rate failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
        
        /* set default iis */
        res = vs1053b_set_iis(&gs_handle, VS1053B_BASIC_DEFAULT_PLAY_IIS_OUTPUT);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set iis failed.\n");
            (void)vs1053b_deinit(&gs_handle);
             
            return 1;
        }
    #endif
    }
    else
    {
        if (format == VS1053B_RECORD_FORMAT_WAV)
        {
            /* set default record clock multiplier */
            res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_MULTIPLIER);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record allowed multiplier addition */
            res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_ALLOWED_MULTIPLIER_ADDITION);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record clock frequency */
            res = vs1053b_clock_frequency_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_FREQUENCY, &clk);
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

            /* set default record do not jump */
            res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_DO_NOT_JUMP);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record swing */
            res = vs1053b_swing_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_SWING, &reg);
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
            
            /* set default record overload detection */
            res = vs1053b_set_overload_detection(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_OVERLOAD_DETECTION);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record analog driver power down */
            res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_ANALOG_DRIVER_POWER_DOWN);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record analog internal power down */
            res = vs1053b_set_analog_internal_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_ANALOG_INTERNAL_POWER_DOWN);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set analog internal power down failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record ad clock */
            res = vs1053b_set_ad_clock(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_AD_CLOCK);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set ad clock failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record reference voltage */
            res = vs1053b_set_reference_voltage(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_REFERENCE_VOLTAGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set reference voltage failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record treble control */
            res = vs1053b_treble_control_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_TREBLE_CONTROL, &reg);
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
            
            /* set default record lower limit frequency in 1000 hz convert to register */
            res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_LOWER_LIMIT_FREQUENCY_IN_1000_HZ, &reg);
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
            
            /* set default record bass enhancement */
            res = vs1053b_set_bass_enhancement(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_BASS_ENHANCEMENT);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set bass enhancement failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record lower limit frequency in 10 hz convert to register */
            res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_LOWER_LIMIT_FREQUENCY_IN_10_HZ, &reg);
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
            
            /* set default record vol */
            res = vs1053b_vol_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_VOL, &reg);
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

            /* set default record sample rate */
            config = VS1053B_BASIC_DEFAULT_RECORD_WAV_SAMPLE;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_0, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record times */
            config = VS1053B_BASIC_DEFAULT_RECORD_WAV_TIMES;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_1, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record gain */
            config = VS1053B_BASIC_DEFAULT_RECORD_WAV_GAIN;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_2, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record channel */
            config = VS1053B_BASIC_DEFAULT_RECORD_WAV_CHANNEL;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_3, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record diff */
            res = vs1053b_set_diff(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_DIFF);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record mpeg layer i and ii */
            res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_MPEG_LAYER_I_AND_II);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record cancel decoding current file */
            res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_CANCEL_DECODING_CURRENT_FILE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record ear speaker low setting */
            res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_EAR_SPEAKER_LOW_SETTING);
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
            
            /* set default record ear speaker high setting */
            res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_EAR_SPEAKER_HIGH_SETTING);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record dclk edge */
            res = vs1053b_set_dclk_edge(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_DCLK_EDGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set dclk edge failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record sdi bit order */
            res = vs1053b_set_sdi_bit_order(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_BIT_ORDER);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set sdi bit order failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record share spi chip select */
            res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_SHARE_SPI_CHIP_SELECT);
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
            
            /* set default record selector */
            res = vs1053b_set_selector(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_SELECTOR);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record clock range */
            res = vs1053b_set_clock_range(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_RANGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set clock range failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
        }
        else
        {
            /* set default record clock multiplier */
            res = vs1053b_set_clock_multiplier(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_MULTIPLIER);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set clock multiplier failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record allowed multiplier addition */
            res = vs1053b_set_allowed_multiplier_addition(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_ALLOWED_MULTIPLIER_ADDITION);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set allowed multiplier addition failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record clock frequency */
            res = vs1053b_clock_frequency_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_FREQUENCY, &clk);
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

            /* set default record do not jump */
            res = vs1053b_set_do_not_jump(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_DO_NOT_JUMP);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set do not jump failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record swing */
            res = vs1053b_swing_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_SWING, &reg);
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
            
            /* set default record overload detection */
            res = vs1053b_set_overload_detection(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_OVERLOAD_DETECTION);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set overload detection failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record analog driver power down */
            res = vs1053b_set_analog_driver_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_ANALOG_DRIVER_POWER_DOWN);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set analog driver power down failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record analog internal power down */
            res = vs1053b_set_analog_internal_power_down(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_ANALOG_INTERNAL_POWER_DOWN);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set analog internal power down failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record ad clock */
            res = vs1053b_set_ad_clock(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_AD_CLOCK);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set ad clock failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record reference voltage */
            res = vs1053b_set_reference_voltage(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_REFERENCE_VOLTAGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set reference voltage failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record treble control */
            res = vs1053b_treble_control_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_TREBLE_CONTROL, &reg);
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
            
            /* set default record lower limit frequency in 1000 hz convert to register */
            res = vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_LOWER_LIMIT_FREQUENCY_IN_1000_HZ, &reg);
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
            
            /* set default record bass enhancement */
            res = vs1053b_set_bass_enhancement(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_BASS_ENHANCEMENT);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set bass enhancement failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record lower limit frequency in 10 hz convert to register */
            res = vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_LOWER_LIMIT_FREQUENCY_IN_10_HZ, &reg);
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
            
            /* set default record vol */
            res = vs1053b_vol_convert_to_register(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_VOL, &reg);
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

            /* set default record sample rate */
            config = VS1053B_BASIC_DEFAULT_RECORD_OGG_SAMPLE;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_0, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record times */
            config = VS1053B_BASIC_DEFAULT_RECORD_OGG_TIMES;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_1, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record gain */
            config = VS1053B_BASIC_DEFAULT_RECORD_OGG_GAIN;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_2, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* stop */
            config = VS1053B_BASIC_DEFAULT_RECORD_OGG_CONTROL;
            buf[0] = (config >> 8) & 0xFF;
            buf[1] = (config >> 0) & 0xFF;
            res = vs1053b_write_application(&gs_handle, VS1053B_APPLICATION_3, buf, 2);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: write application failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                 
                return 1;
            }
            
            /* set default record diff */
            res = vs1053b_set_diff(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_DIFF);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set diff failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record mpeg layer i and ii */
            res = vs1053b_set_mpeg_layer_i_and_ii(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_MPEG_LAYER_I_AND_II);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set mpeg layer i and ii failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record cancel decoding current file */
            res = vs1053b_set_cancel_decoding_current_file(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_CANCEL_DECODING_CURRENT_FILE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set cancel decoding current file failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record ear speaker low setting */
            res = vs1053b_set_ear_speaker_low_setting(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_EAR_SPEAKER_LOW_SETTING);
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
            
            /* set default record ear speaker high setting */
            res = vs1053b_set_ear_speaker_high_setting(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_EAR_SPEAKER_HIGH_SETTING);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set ear speaker high setting failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record dclk edge */
            res = vs1053b_set_dclk_edge(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_DCLK_EDGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set dclk edge failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record sdi bit order */
            res = vs1053b_set_sdi_bit_order(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_BIT_ORDER);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set sdi bit order failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record share spi chip select */
            res = vs1053b_set_share_spi_chip_select(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_SHARE_SPI_CHIP_SELECT);
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
            
            /* set default record selector */
            res = vs1053b_set_selector(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_SELECTOR);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set selector failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
            
            /* set default record clock range */
            res = vs1053b_set_clock_range(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_RANGE);
            if (res != 0)
            {
                vs1053b_interface_debug_print("vs1053b: set clock range failed.\n");
                (void)vs1053b_deinit(&gs_handle);
                
                return 1;
            }
        }
    }
    
    return 0;
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_basic_deinit(void)
{
    /* deinit */
    if (vs1053b_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief  basic example pause
 * @return status code
 *         - 0 success
 *         - 1 pause failed
 * @note   none
 */
uint8_t vs1053b_basic_pause(void)
{
    /* pause */
    if (vs1053b_pause(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief  basic example stop
 * @return status code
 *         - 0 success
 *         - 1 stop failed
 * @note   none
 */
uint8_t vs1053b_basic_stop(void)
{
    /* stop */
    if (vs1053b_stop(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example play
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 play failed
 * @note      none
 */
uint8_t vs1053b_basic_play(char *path)
{
    uint8_t res;
    
    /* if flac format, load the flac patch */
    if (strstr(path, ".flac") != NULL)
    {
        const uint16_t *patch_addr;
        uint16_t l;
        
        /* get flac patch */
        res = vs1053b_get_patch(&gs_handle, VS1053B_PATCH_FLAC, &patch_addr, &l);
        if (res != 0)
        {
            return 1;
        }
        
        /* load flac patch */
        res = vs1053b_load_patch(&gs_handle, patch_addr, l);
        if (res != 0)
        {
            return 1;
        }
    }
    
    /* play music */
    res = vs1053b_play(&gs_handle, path);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example record
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 record failed
 * @note      none
 */
uint8_t vs1053b_basic_record(char *path)
{
    uint8_t res;
    
    /* if wav format, load the wav patch */
    if (strstr(path, ".wav") != NULL)
    {
        const uint16_t *patch_addr;
        uint16_t l;
        
        /* enable pcm adpcm recording active */
        res = vs1053b_set_pcm_adpcm_recording_active(&gs_handle, VS1053B_BOOL_TRUE);
        if (res != 0)
        {
            return 1;
        }
        
        /* both soft reset and pcm adpcm recording active to start ima adpcm mode */
        res = vs1053b_set_soft_reset(&gs_handle, VS1053B_BOOL_TRUE);
        if (res != 0)
        {
            return 1;
        }
        
        /* delay 5ms */
        vs1053b_interface_delay_ms(5);
        
        /* set record format wav */
        res = vs1053b_set_record_format(&gs_handle, VS1053B_RECORD_FORMAT_WAV);
        if (res != 0)
        {
            return 1;
        }
        
        /* get wav patch */
        res = vs1053b_get_patch(&gs_handle, VS1053B_PATCH_WAV, &patch_addr, &l);
        if (res != 0)
        {
            return 1;
        }
        
        /* load wav patch */
        res = vs1053b_load_patch(&gs_handle, patch_addr, l);
        if (res != 0)
        {
            return 1;
        }
        
        /* record audio */
        res = vs1053b_record(&gs_handle, path, VS1053B_BASIC_DEFAULT_RECORD_WAV_SAMPLE);
        if (res != 0)
        {
            return 1;
        }
    }
    else if (strstr(path, ".ogg") != NULL)
    {
        uint8_t buf[2];
        const uint16_t *patch_addr;
        uint16_t l;
        uint16_t addr;
        uint16_t value;
        
        /* enable pcm adpcm recording active */
        res = vs1053b_set_pcm_adpcm_recording_active(&gs_handle, VS1053B_BOOL_TRUE);
        if (res != 0)
        {
            return 1;
        }
        
        /* both soft reset and pcm adpcm recording active to start ima adpcm mode */
        res = vs1053b_set_soft_reset(&gs_handle, VS1053B_BOOL_TRUE);
        if (res != 0)
        {
            return 1;
        }
        
        /* delay 5ms */
        vs1053b_interface_delay_ms(5);
        
        /* set interrupt enable ram address */
        addr = 0xC01A;
        res = vs1053b_set_ram_address(&gs_handle, addr);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: set ram address failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* disable all interrupts except sci */
        value = 0x0002;
        buf[0] = (value >> 8) & 0xFF;
        buf[1] = (value >> 0) & 0xFF;
        res = vs1053b_write_ram(&gs_handle, buf, 2);
        if (res != 0)
        {
            vs1053b_interface_debug_print("vs1053b: write ram failed.\n");
            (void)vs1053b_deinit(&gs_handle);
            
            return 1;
        }
        
        /* set record format ogg */
        res = vs1053b_set_record_format(&gs_handle, VS1053B_RECORD_FORMAT_OGG);
        if (res != 0)
        {
            return 1;
        }
        
        /* get ogg patch */
        res = vs1053b_get_patch(&gs_handle, VS1053B_BASIC_DEFAULT_RECORD_OGG_VENC, &patch_addr, &l);
        if (res != 0)
        {
            return 1;
        }
        
        /* load ogg patch */
        res = vs1053b_load_patch(&gs_handle, patch_addr, l);
        if (res != 0)
        {
            return 1;
        }
        
        /* record audio */
        res = vs1053b_record(&gs_handle, path, VS1053B_BASIC_DEFAULT_RECORD_OGG_SAMPLE);
        if (res != 0)
        {
            return 1;
        }
    }
    else
    {
        vs1053b_interface_debug_print("vs1053b: record only supports wav and ogg format.\n");
        
        return 1;
    }

    
    return 0;
}

/**
 * @brief  basic example service
 * @return status code
 *         - 0 success
 *         - 1 service failed
 * @note   none
 */
uint8_t vs1053b_basic_service(void)
{
    /* process */
    if (vs1053b_process(&gs_handle) != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example set callback period
 * @param[in] second is the set time
 * @return    status code
 *            - 0 success
 *            - 1 callback period failed
 * @note      none
 */
uint8_t vs1053b_basic_set_callback_period(uint32_t second)
{
    uint8_t res;
    
    /* set callback period */
    res = vs1053b_set_period_callback(&gs_handle, second, 0, VS1053B_BOOL_TRUE);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief     basic example set vol
 * @param[in] vol is the set vol
 * @return    status code
 *            - 0 success
 *            - 1 set vol failed
 * @note      none
 */
uint8_t vs1053b_basic_set_vol(float vol)
{
    uint8_t res;
    uint8_t reg;
    
    /* convert vol */
    res = vs1053b_vol_convert_to_register(&gs_handle, vol, &reg);
    if (res != 0)
    {
        return 1;
    }
    
    /* set vol */
    res = vs1053b_set_vol(&gs_handle, reg, reg);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example get decode time
 * @param[out] *decode_time points to a decode time buffer
 * @return     status code
 *             - 0 success
 *             - 1 get decode time failed
 * @note       none
 */
uint8_t vs1053b_basic_get_decode_time(uint16_t *decode_time)
{
    uint8_t res;
    
    /* get decode time */
    res = vs1053b_get_decode_time(&gs_handle, decode_time);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example get bytes rate
 * @param[out] *rate points to a rate buffer
 * @return     status code
 *             - 0 success
 *             - 1 get bytes rate failed
 * @note       none
 */
uint8_t vs1053b_basic_get_bytes_rate(uint16_t *rate)
{
    uint8_t res;
    
    /* get byte rate */
    res = vs1053b_get_byte_rate(&gs_handle, rate);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example get sample rate
 * @param[out] *rate points to a rate buffer
 * @param[out] *channel points to a channel buffer
 * @return     status code
 *             - 0 success
 *             - 1 get sample rate failed
 * @note       none
 */
uint8_t vs1053b_basic_get_sample_rate(uint16_t *rate, vs1053b_channel_t *channel)
{
    uint8_t res;
    
    /* get sample rate */
    res = vs1053b_get_sample_rate(&gs_handle, rate, channel);
    if (res != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief      basic example get info
 * @param[out] *info points to an info buffer
 * @return     status code
 *             - 0 success
 *             - 1 get info failed
 * @note       none
 */
uint8_t vs1053b_basic_get_info(vs1053b_audio_info_t *info)
{
    uint8_t res;
    uint16_t dat0;
    uint16_t dat1;
    
    /* get hdata */
    res = vs1053b_get_hdata(&gs_handle, &dat0, &dat1);
    if (res == 0)
    {
        /* parse info */
        if (vs1053b_parse_info(&gs_handle, dat0, dat1, info) != 0)
        {
            return 1;
        }
        
        return 0;
    }
    
    return 1;
}
