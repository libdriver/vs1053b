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
 * @file      driver_vs1053b_basic.h
 * @brief     driver vs1053b basic header file
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

#ifndef DRIVER_VS1053B_BASIC_H
#define DRIVER_VS1053B_BASIC_H

#include "driver_vs1053b_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup vs1053b_example_driver vs1053b example driver function
 * @brief    vs1053b example driver modules
 * @ingroup  vs1053b_driver
 * @{
 */

/**
 * @brief vs1053b basic example default definition
 */
#define VS1053B_BASIC_DEFAULT_PLAY_CLOCK_MULTIPLIER                            VS1053B_CLOCK_MULTIPLIER_3P5_XTALI                   /**< 3.5 xtali */
#define VS1053B_BASIC_DEFAULT_PLAY_ALLOWED_MULTIPLIER_ADDITION                 VS1053B_ALLOWED_MULTIPLIER_ADDITION_2P0_XTALI        /**< 2.0 xtali */
#define VS1053B_BASIC_DEFAULT_PLAY_CLOCK_FREQUENCY                             8000000.0f                                           /**< 8000000Hz */
#define VS1053B_BASIC_DEFAULT_PLAY_DIFF                                        VS1053B_DIFF_NORMAL                                  /**< diff normal mode */
#define VS1053B_BASIC_DEFAULT_PLAY_MPEG_LAYER_I_AND_II                         VS1053B_BOOL_TRUE                                    /**< enable mpeg i and ii */
#define VS1053B_BASIC_DEFAULT_PLAY_CANCEL_DECODING_CURRENT_FILE                VS1053B_BOOL_FALSE                                   /**< disable cancel decoding */
#define VS1053B_BASIC_DEFAULT_PLAY_EAR_SPEAKER_LOW_SETTING                     VS1053B_BOOL_FALSE                                   /**< disable ear low setting */
#define VS1053B_BASIC_DEFAULT_PLAY_EAR_SPEAKER_HIGH_SETTING                    VS1053B_BOOL_FALSE                                   /**< disable ear high setting */
#define VS1053B_BASIC_DEFAULT_PLAY_DCLK_EDGE                                   VS1053B_DCLK_EDGE_RISING                             /**< dclk edge rising */
#define VS1053B_BASIC_DEFAULT_PLAY_BIT_ORDER                                   VS1053B_BIT_ORDER_MSB_FIRST                          /**< bit order msb first */
#define VS1053B_BASIC_DEFAULT_PLAY_SHARE_SPI_CHIP_SELECT                       VS1053B_BOOL_FALSE                                   /**< disable share spi */
#define VS1053B_BASIC_DEFAULT_PLAY_SELECTOR                                    VS1053B_SELECTOR_MICP                                /**< micp */
#define VS1053B_BASIC_DEFAULT_PLAY_CLOCK_RANGE                                 VS1053B_CLOCK_RANGE_12MHZ_13MHZ                      /**< 12 - 13MHz */
#define VS1053B_BASIC_DEFAULT_PLAY_DO_NOT_JUMP                                 VS1053B_BOOL_FALSE                                   /**< disable do not jump */
#define VS1053B_BASIC_DEFAULT_PLAY_SWING                                       0.0f                                                 /**< 0.0f */
#define VS1053B_BASIC_DEFAULT_PLAY_OVERLOAD_DETECTION                          VS1053B_BOOL_TRUE                                    /**< enable overload detection */
#define VS1053B_BASIC_DEFAULT_PLAY_ANALOG_DRIVER_POWER_DOWN                    VS1053B_BOOL_FALSE                                   /**< disable analog driver power down */
#define VS1053B_BASIC_DEFAULT_PLAY_ANALOG_INTERNAL_POWER_DOWN                  VS1053B_BOOL_FALSE                                   /**< disable analog internal power down */
#define VS1053B_BASIC_DEFAULT_PLAY_AD_CLOCK                                    VS1053B_AD_CLOCK_6MHZ                                /**< ad clock 6MHz */
#define VS1053B_BASIC_DEFAULT_PLAY_REFERENCE_VOLTAGE                           VS1053B_REFERENCE_VOLTAGE_1P23V                      /**< 1.23V */
#define VS1053B_BASIC_DEFAULT_PLAY_TREBLE_CONTROL                              22.5f                                                /**< 22.5 */
#define VS1053B_BASIC_DEFAULT_PLAY_LOWER_LIMIT_FREQUENCY_IN_1000_HZ            10000                                                /**< 10000Hz */
#define VS1053B_BASIC_DEFAULT_PLAY_BASS_ENHANCEMENT                            15                                                   /**< 15db */
#define VS1053B_BASIC_DEFAULT_PLAY_LOWER_LIMIT_FREQUENCY_IN_10_HZ              60                                                   /**< 60Hz */
#define VS1053B_BASIC_DEFAULT_PLAY_VOL                                         -10.0f                                               /**< -20.0 db */
#define VS1053B_BASIC_DEFAULT_PLAY_SPEED                                       VS1053B_PLAY_SPEED_1P0_X                             /**< 1.0X */
#define VS1053B_BASIC_DEFAULT_PLAY_IIS_OUTPUT                                  VS1053B_BOOL_FALSE                                   /**< disable iis */
#define VS1053B_BASIC_DEFAULT_PLAY_IIS_MCLK_OUTPUT                             VS1053B_BOOL_TRUE                                    /**< enable mclk */
#define VS1053B_BASIC_DEFAULT_PLAY_IIS_RATE                                    VS1053B_IIS_RATE_48KHZ                               /**< 48khz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_MULTIPLIER                      VS1053B_CLOCK_MULTIPLIER_2P0_XTALI                   /**< 2.0 xtali */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_ALLOWED_MULTIPLIER_ADDITION           VS1053B_ALLOWED_MULTIPLIER_ADDITION_NONE             /**< none */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_FREQUENCY                       8000000.0f                                           /**< 8000000Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_DO_NOT_JUMP                           VS1053B_BOOL_FALSE                                   /**< disable do not jump */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_SWING                                 0.0f                                                 /**< 0.0f */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_OVERLOAD_DETECTION                    VS1053B_BOOL_TRUE                                    /**< enable overload detection */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_ANALOG_DRIVER_POWER_DOWN              VS1053B_BOOL_FALSE                                   /**< disable analog driver power down */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_ANALOG_INTERNAL_POWER_DOWN            VS1053B_BOOL_FALSE                                   /**< disable analog internal power down */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_AD_CLOCK                              VS1053B_AD_CLOCK_6MHZ                                /**< ad clock 6MHz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_REFERENCE_VOLTAGE                     VS1053B_REFERENCE_VOLTAGE_1P23V                      /**< 1.23V */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_TREBLE_CONTROL                        0.0f                                                 /**< 0.0 */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_LOWER_LIMIT_FREQUENCY_IN_1000_HZ      0                                                    /**< 0Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_BASS_ENHANCEMENT                      0                                                    /**< 0 db */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_LOWER_LIMIT_FREQUENCY_IN_10_HZ        0                                                    /**< 0Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_VOL                                   -100.0f                                              /**< -100.0 db */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_SAMPLE                                8000                                                 /**< 8000Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_TIMES                                 1024 * 5                                             /**< 5 times */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_GAIN                                  0                                                    /**< agc */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_CHANNEL                               6                                                    /**< left micro */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_DIFF                                  VS1053B_DIFF_NORMAL                                  /**< diff normal mode */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_MPEG_LAYER_I_AND_II                   VS1053B_BOOL_FALSE                                   /**< disable mpeg i and ii */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_CANCEL_DECODING_CURRENT_FILE          VS1053B_BOOL_FALSE                                   /**< disable cancel decoding */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_EAR_SPEAKER_LOW_SETTING               VS1053B_BOOL_FALSE                                   /**< disable ear low setting */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_EAR_SPEAKER_HIGH_SETTING              VS1053B_BOOL_FALSE                                   /**< disable ear high setting */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_DCLK_EDGE                             VS1053B_DCLK_EDGE_RISING                             /**< dclk edge rising */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_BIT_ORDER                             VS1053B_BIT_ORDER_MSB_FIRST                          /**< bit order msb first */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_SHARE_SPI_CHIP_SELECT                 VS1053B_BOOL_FALSE                                   /**< disable share spi */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_SELECTOR                              VS1053B_SELECTOR_MICP                                /**< micp */
#define VS1053B_BASIC_DEFAULT_RECORD_WAV_CLOCK_RANGE                           VS1053B_CLOCK_RANGE_12MHZ_13MHZ                      /**< 12 - 13MHz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_MULTIPLIER                      VS1053B_CLOCK_MULTIPLIER_4P5_XTALI                   /**< 4.5 xtali */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_ALLOWED_MULTIPLIER_ADDITION           VS1053B_ALLOWED_MULTIPLIER_ADDITION_NONE             /**< none */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_FREQUENCY                       8000000.0f                                           /**< 8000000Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_DO_NOT_JUMP                           VS1053B_BOOL_FALSE                                   /**< disable do not jump */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_SWING                                 0.0f                                                 /**< 0.0f */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_OVERLOAD_DETECTION                    VS1053B_BOOL_TRUE                                    /**< enable overload detection */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_ANALOG_DRIVER_POWER_DOWN              VS1053B_BOOL_FALSE                                   /**< disable analog driver power down */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_ANALOG_INTERNAL_POWER_DOWN            VS1053B_BOOL_FALSE                                   /**< disable analog internal power down */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_AD_CLOCK                              VS1053B_AD_CLOCK_6MHZ                                /**< ad clock 6MHz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_REFERENCE_VOLTAGE                     VS1053B_REFERENCE_VOLTAGE_1P23V                      /**< 1.23V */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_TREBLE_CONTROL                        0.0f                                                 /**< 0.0 */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_LOWER_LIMIT_FREQUENCY_IN_1000_HZ      0                                                    /**< 0Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_BASS_ENHANCEMENT                      0                                                    /**< 0 db */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_LOWER_LIMIT_FREQUENCY_IN_10_HZ        0                                                    /**< 0Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_VOL                                   -100.0f                                              /**< -100.0 db */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_SAMPLE                                44100                                                /**< 44100Hz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_TIMES                                 1024                                                 /**< 5 times */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_GAIN                                  0                                                    /**< agc */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_CONTROL                               0                                                    /**< stop */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_DIFF                                  VS1053B_DIFF_NORMAL                                  /**< diff normal mode */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_MPEG_LAYER_I_AND_II                   VS1053B_BOOL_FALSE                                   /**< disable mpeg i and ii */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_CANCEL_DECODING_CURRENT_FILE          VS1053B_BOOL_FALSE                                   /**< disable cancel decoding */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_EAR_SPEAKER_LOW_SETTING               VS1053B_BOOL_FALSE                                   /**< disable ear low setting */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_EAR_SPEAKER_HIGH_SETTING              VS1053B_BOOL_FALSE                                   /**< disable ear high setting */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_DCLK_EDGE                             VS1053B_DCLK_EDGE_RISING                             /**< dclk edge rising */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_BIT_ORDER                             VS1053B_BIT_ORDER_MSB_FIRST                          /**< bit order msb first */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_SHARE_SPI_CHIP_SELECT                 VS1053B_BOOL_FALSE                                   /**< disable share spi */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_SELECTOR                              VS1053B_SELECTOR_MICP                                /**< micp */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_CLOCK_RANGE                           VS1053B_CLOCK_RANGE_12MHZ_13MHZ                      /**< 12 - 13MHz */
#define VS1053B_BASIC_DEFAULT_RECORD_OGG_VENC                                  VS1053B_PATCH_OGG_VENC44K2Q05                        /**< ogg venc44k2q05 */

/**
 * @brief vs1053b mode enumeration definition
 */
typedef enum
{
    VS1053B_MODE_PLAY   = 0x00,        /**< play mode */
    VS1053B_MODE_RECORD = 0x01,        /**< record mode */
} vs1053b_mode_t;

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
uint8_t vs1053b_basic_init(vs1053b_mode_t mode, vs1053b_record_format_t format, void (*callback)(uint8_t type, uint32_t cur_pos));

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t vs1053b_basic_deinit(void);

/**
 * @brief     basic example set callback period
 * @param[in] second is the set time
 * @return    status code
 *            - 0 success
 *            - 1 callback period failed
 * @note      none
 */
uint8_t vs1053b_basic_set_callback_period(uint32_t second);

/**
 * @brief  basic example service
 * @return status code
 *         - 0 success
 *         - 1 service failed
 * @note   none
 */
uint8_t vs1053b_basic_service(void);

/**
 * @brief     basic example play
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 play failed
 * @note      none
 */
uint8_t vs1053b_basic_play(char *path);

/**
 * @brief     basic example record
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 record failed
 * @note      none
 */
uint8_t vs1053b_basic_record(char *path);

/**
 * @brief  basic example pause
 * @return status code
 *         - 0 success
 *         - 1 pause failed
 * @note   none
 */
uint8_t vs1053b_basic_pause(void);

/**
 * @brief  basic example stop
 * @return status code
 *         - 0 success
 *         - 1 stop failed
 * @note   none
 */
uint8_t vs1053b_basic_stop(void);

/**
 * @brief     basic example set vol
 * @param[in] vol is the set vol
 * @return    status code
 *            - 0 success
 *            - 1 set vol failed
 * @note      none
 */
uint8_t vs1053b_basic_set_vol(float vol);

/**
 * @brief      basic example get decode time
 * @param[out] *decode_time points to a decode time buffer
 * @return     status code
 *             - 0 success
 *             - 1 get decode time failed
 * @note       none
 */
uint8_t vs1053b_basic_get_decode_time(uint16_t *decode_time);

/**
 * @brief      basic example get bytes rate
 * @param[out] *rate points to a rate buffer
 * @return     status code
 *             - 0 success
 *             - 1 get bytes rate failed
 * @note       none
 */
uint8_t vs1053b_basic_get_bytes_rate(uint16_t *rate);

/**
 * @brief      basic example get sample rate
 * @param[out] *rate points to a rate buffer
 * @param[out] *channel points to a channel buffer
 * @return     status code
 *             - 0 success
 *             - 1 get sample rate failed
 * @note       none
 */
uint8_t vs1053b_basic_get_sample_rate(uint16_t *rate, vs1053b_channel_t *channel);

/**
 * @brief      basic example get info
 * @param[out] *info points to an info buffer
 * @return     status code
 *             - 0 success
 *             - 1 get info failed
 * @note       none
 */
uint8_t vs1053b_basic_get_info(vs1053b_audio_info_t *info);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
