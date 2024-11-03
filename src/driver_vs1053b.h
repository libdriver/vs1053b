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
 * @file      driver_vs1053b.h
 * @brief     driver vs1053b header file
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

#ifndef DRIVER_VS1053B_H
#define DRIVER_VS1053B_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup vs1053b_driver vs1053b driver function
 * @brief    vs1053b driver modules
 * @{
 */

/**
 * @addtogroup vs1053b_basic_driver
 * @{
 */

/**
 * @brief vs1053b buffer size definition
 */
#ifndef VS1053B_BUFFER_SIZE
    #define VS1053B_BUFFER_SIZE     512        /* 512 bytes */
#endif

/**
 * @brief check buffer size valid
 */
#if VS1053B_BUFFER_SIZE < 512
    #error "VS1053B_BUFFER_SIZE < 512"
#endif

/**
 * @brief vs1053b venc08k1q00 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q00
    #define VS1053B_OGG_VENC08K1Q00        0        /**< ogg venc08k1q00 */
#endif

/**
 * @brief vs1053b venc08k1q01 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q01
    #define VS1053B_OGG_VENC08K1Q01        0        /**< ogg venc08k1q01 */
#endif

/**
 * @brief vs1053b venc08k1q02 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q02
    #define VS1053B_OGG_VENC08K1Q02        0        /**< ogg venc08k1q02 */
#endif

/**
 * @brief vs1053b venc08k1q03 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q03
    #define VS1053B_OGG_VENC08K1Q03        0        /**< ogg venc08k1q03 */
#endif

/**
 * @brief vs1053b venc08k1q04 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q04
    #define VS1053B_OGG_VENC08K1Q04        0        /**< ogg venc08k1q04 */
#endif

/**
 * @brief vs1053b venc08k1q05 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q05
    #define VS1053B_OGG_VENC08K1Q05        0        /**< ogg venc08k1q05 */
#endif

/**
 * @brief vs1053b venc08k1q06 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q06
    #define VS1053B_OGG_VENC08K1Q06        0        /**< ogg venc08k1q06 */
#endif

/**
 * @brief vs1053b venc08k1q07 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q07
    #define VS1053B_OGG_VENC08K1Q07        0        /**< ogg venc08k1q07 */
#endif

/**
 * @brief vs1053b venc08k1q08 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q08
    #define VS1053B_OGG_VENC08K1Q08        0        /**< ogg venc08k1q08 */
#endif

/**
 * @brief vs1053b venc08k1q09 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q09
    #define VS1053B_OGG_VENC08K1Q09        0        /**< ogg venc08k1q09 */
#endif

/**
 * @brief vs1053b venc08k1q10 definition
 */
#ifndef VS1053B_OGG_VENC08K1Q10
    #define VS1053B_OGG_VENC08K1Q10        0        /**< ogg venc08k1q10 */
#endif

/**
 * @brief vs1053b venc16k1q00 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q00
    #define VS1053B_OGG_VENC16K1Q00        0        /**< ogg venc16k1q00 */
#endif

/**
 * @brief vs1053b venc16k1q01 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q01
    #define VS1053B_OGG_VENC16K1Q01        0        /**< ogg venc16k1q01 */
#endif

/**
 * @brief vs1053b venc16k1q02 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q02
    #define VS1053B_OGG_VENC16K1Q02        0        /**< ogg venc16k1q02 */
#endif

/**
 * @brief vs1053b venc16k1q03 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q03
    #define VS1053B_OGG_VENC16K1Q03        0        /**< ogg venc16k1q03 */
#endif

/**
 * @brief vs1053b venc16k1q04 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q04
    #define VS1053B_OGG_VENC16K1Q04        0        /**< ogg venc16k1q04 */
#endif

/**
 * @brief vs1053b venc16k1q05 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q05
    #define VS1053B_OGG_VENC16K1Q05        0        /**< ogg venc16k1q05 */
#endif

/**
 * @brief vs1053b venc16k1q06 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q06
    #define VS1053B_OGG_VENC16K1Q06        0        /**< ogg venc16k1q06 */
#endif

/**
 * @brief vs1053b venc16k1q07 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q07
    #define VS1053B_OGG_VENC16K1Q07        0        /**< ogg venc16k1q07 */
#endif

/**
 * @brief vs1053b venc16k1q08 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q08
    #define VS1053B_OGG_VENC16K1Q08        0        /**< ogg venc16k1q08 */
#endif

/**
 * @brief vs1053b venc16k1q09 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q09
    #define VS1053B_OGG_VENC16K1Q09        0        /**< ogg venc16k1q09 */
#endif

/**
 * @brief vs1053b venc16k1q10 definition
 */
#ifndef VS1053B_OGG_VENC16K1Q10
    #define VS1053B_OGG_VENC16K1Q10        0        /**< ogg venc16k1q10 */
#endif

/**
 * @brief vs1053b venc16k2q00 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q00
    #define VS1053B_OGG_VENC16K2Q00        0        /**< ogg venc16k2q00 */
#endif

/**
 * @brief vs1053b venc16k2q01 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q01
    #define VS1053B_OGG_VENC16K2Q01        0        /**< ogg venc16k2q01 */
#endif

/**
 * @brief vs1053b venc16k2q02 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q02
    #define VS1053B_OGG_VENC16K2Q02        0        /**< ogg venc16k2q02 */
#endif

/**
 * @brief vs1053b venc16k2q03 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q03
    #define VS1053B_OGG_VENC16K2Q03        0        /**< ogg venc16k2q03 */
#endif

/**
 * @brief vs1053b venc16k2q04 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q04
    #define VS1053B_OGG_VENC16K2Q04        0        /**< ogg venc16k2q04 */
#endif

/**
 * @brief vs1053b venc16k2q05 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q05
    #define VS1053B_OGG_VENC16K2Q05        0        /**< ogg venc16k2q05 */
#endif

/**
 * @brief vs1053b venc16k2q06 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q06
    #define VS1053B_OGG_VENC16K2Q06        0        /**< ogg venc16k2q06 */
#endif

/**
 * @brief vs1053b venc16k2q07 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q07
    #define VS1053B_OGG_VENC16K2Q07        0        /**< ogg venc16k2q07 */
#endif

/**
 * @brief vs1053b venc16k2q08 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q08
    #define VS1053B_OGG_VENC16K2Q08        0        /**< ogg venc16k2q08 */
#endif

/**
 * @brief vs1053b venc16k2q09 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q09
    #define VS1053B_OGG_VENC16K2Q09        0        /**< ogg venc16k2q09 */
#endif

/**
 * @brief vs1053b venc16k2q10 definition
 */
#ifndef VS1053B_OGG_VENC16K2Q10
    #define VS1053B_OGG_VENC16K2Q10        0        /**< ogg venc16k2q10 */
#endif

/**
 * @brief vs1053b venc44k1q00 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q00
    #define VS1053B_OGG_VENC44K1Q00        0        /**< ogg venc44k1q00 */
#endif

/**
 * @brief vs1053b venc44k1q01 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q01
    #define VS1053B_OGG_VENC44K1Q01        0        /**< ogg venc44k1q01 */
#endif

/**
 * @brief vs1053b venc44k1q02 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q02
    #define VS1053B_OGG_VENC44K1Q02        0        /**< ogg venc44k1q02 */
#endif

/**
 * @brief vs1053b venc44k1q03 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q03
    #define VS1053B_OGG_VENC44K1Q03        0        /**< ogg venc44k1q03 */
#endif

/**
 * @brief vs1053b venc44k1q04 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q04
    #define VS1053B_OGG_VENC44K1Q04        0        /**< ogg venc44k1q04 */
#endif

/**
 * @brief vs1053b venc44k1q05 definition
 */
#ifndef VS1053B_OGG_VENC44K1Q05
    #define VS1053B_OGG_VENC44K1Q05        0        /**< ogg venc44k1q05 */
#endif

/**
 * @brief vs1053b venc44k2q00 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q00
    #define VS1053B_OGG_VENC44K2Q00        0        /**< ogg venc44k2q00 */
#endif

/**
 * @brief vs1053b venc44k2q01 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q01
    #define VS1053B_OGG_VENC44K2Q01        0        /**< ogg venc44k2q01 */
#endif

/**
 * @brief vs1053b venc44k2q02 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q02
    #define VS1053B_OGG_VENC44K2Q02        0        /**< ogg venc44k2q02 */
#endif

/**
 * @brief vs1053b venc44k2q03 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q03
    #define VS1053B_OGG_VENC44K2Q03        0        /**< ogg venc44k2q03 */
#endif

/**
 * @brief vs1053b venc44k2q04 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q04
    #define VS1053B_OGG_VENC44K2Q04        0        /**< ogg venc44k2q04 */
#endif

/**
 * @brief vs1053b venc44k2q05 definition
 */
#ifndef VS1053B_OGG_VENC44K2Q05
    #define VS1053B_OGG_VENC44K2Q05        1        /**< ogg venc44k2q05 */
#endif

/**
 * @brief vs1053b bool enumeration definition
 */
typedef enum
{
    VS1053B_BOOL_FALSE = 0x00,        /**< disable */
    VS1053B_BOOL_TRUE  = 0x01,        /**< enable */
} vs1053b_bool_t;

/**
 * @brief vs1053b clock range enumeration definition
 */
typedef enum
{
    VS1053B_CLOCK_RANGE_12MHZ_13MHZ = 0x00,        /**< 12MHz - 13MHz */
    VS1053B_CLOCK_RANGE_24MHZ_26MHZ = 0x01,        /**< 24MHz - 26MHz */
} vs1053b_clock_range_t;

/**
 * @brief vs1053b selector enumeration definition
 */
typedef enum
{
    VS1053B_SELECTOR_MICP  = 0x00,        /**< microphone */
    VS1053B_SELECTOR_LINE1 = 0x01,        /**< line1 */
} vs1053b_selector_t;

/**
 * @brief vs1053b bit order enumeration definition
 */
typedef enum
{
    VS1053B_BIT_ORDER_MSB_FIRST = 0x00,        /**< msb first */
    VS1053B_BIT_ORDER_MSB_LAST  = 0x01,        /**< msb last */
} vs1053b_bit_order_t;

/**
 * @brief vs1053b dclk edge enumeration definition
 */
typedef enum
{
    VS1053B_DCLK_EDGE_RISING  = 0x00,        /**< rising edge */
    VS1053B_DCLK_EDGE_FALLING = 0x01,        /**< falling edge */
} vs1053b_dclk_edge_t;

/**
 * @brief vs1053b diff enumeration definition
 */
typedef enum
{
    VS1053B_DIFF_NORMAL        = 0x00,        /**< normal in phase audio */
    VS1053B_DIFF_LEFT_INVERTED = 0x01,        /**< left channel inverted */
} vs1053b_diff_t;

/**
 * @brief vs1053b ad clock enumeration definition
 */
typedef enum
{
    VS1053B_AD_CLOCK_6MHZ = 0x00,        /**< 6MHz */
    VS1053B_AD_CLCOK_3MHZ = 0x01,        /**< 3MHz */
} vs1053b_ad_clock_t;

/**
 * @brief vs1053b reference voltage enumeration definition
 */
typedef enum
{
    VS1053B_REFERENCE_VOLTAGE_1P23V = 0x00,        /**< 1.23V */
    VS1053B_REFERENCE_VOLTAGE_1P65V = 0x01,        /**< 1.65V */
} vs1053b_reference_voltage_t;

/**
 * @brief vs1053b clock multiplier enumeration definition
 */
typedef enum
{
    VS1053B_CLOCK_MULTIPLIER_1P0_XTALI = 0x00,        /**< 1.0 xtali */
    VS1053B_CLOCK_MULTIPLIER_2P0_XTALI = 0x01,        /**< 2.0 xtali */
    VS1053B_CLOCK_MULTIPLIER_2P5_XTALI = 0x02,        /**< 2.5 xtali */
    VS1053B_CLOCK_MULTIPLIER_3P0_XTALI = 0x03,        /**< 3.0 xtali */
    VS1053B_CLOCK_MULTIPLIER_3P5_XTALI = 0x04,        /**< 3.5 xtali */
    VS1053B_CLOCK_MULTIPLIER_4P0_XTALI = 0x05,        /**< 4.0 xtali */
    VS1053B_CLOCK_MULTIPLIER_4P5_XTALI = 0x06,        /**< 4.5 xtali */
    VS1053B_CLOCK_MULTIPLIER_5P0_XTALI = 0x07,        /**< 5.0 xtali */
} vs1053b_clock_multiplier_t;

/**
 * @brief vs1053b allowed multiplier addition enumeration definition
 */
typedef enum
{
    VS1053B_ALLOWED_MULTIPLIER_ADDITION_NONE      = 0x00,        /**< no modification is allowed */
    VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P0_XTALI = 0x01,        /**< 1.0 xtali */
    VS1053B_ALLOWED_MULTIPLIER_ADDITION_1P5_XTALI = 0x02,        /**< 1.5 xtali */
    VS1053B_ALLOWED_MULTIPLIER_ADDITION_2P0_XTALI = 0x03,        /**< 2.0 xtali */
} vs1053b_allowed_multiplier_addition_t;

/**
 * @brief vs1053b channel enumeration definition
 */
typedef enum
{
    VS1053B_CHANNEL_MONO   = 0x00,        /**< mono */
    VS1053B_CHANNEL_STEREO = 0x01,        /**< stereo */
} vs1053b_channel_t;

/**
 * @brief vs1053b application enumeration definition
 */
typedef enum
{
    VS1053B_APPLICATION_0 = 0x00,        /**< application 0 */
    VS1053B_APPLICATION_1 = 0x01,        /**< application 1 */
    VS1053B_APPLICATION_2 = 0x02,        /**< application 2 */
    VS1053B_APPLICATION_3 = 0x03,        /**< application 3 */
} vs1053b_application_t;

/**
 * @brief vs1053b play speed enumeration definition
 */
typedef enum
{
    VS1053B_PLAY_SPEED_1_X   = 0x00,        /**< 1.0x */
    VS1053B_PLAY_SPEED_1P0_X = 0x01,        /**< 1.0x */
    VS1053B_PLAY_SPEED_2P0_X = 0x02,        /**< 2.0x */
    VS1053B_PLAY_SPEED_3P0_X = 0x03,        /**< 3.0x */
} vs1053b_play_speed_t;

/**
 * @brief vs1053b type enumeration definition
 */
typedef enum
{
    VS1053B_TYPE_PLAY_READ    = 0x00,        /**< read data during playing */
    VS1053B_TYPE_PLAY_WRITE   = 0x01,        /**< write data during playing */
    VS1053B_TYPE_PLAY_END     = 0x02,        /**< play end */
    VS1053B_TYPE_RECORD_READ  = 0x03,        /**< read data during recording */
    VS1053B_TYPE_RECORD_WRITE = 0x04,        /**< write data during recording */
    VS1053B_TYPE_RECORD_END   = 0x05,        /**< record end */
    VS1053B_TYPE_RECORD_OVER  = 0x06,        /**< record over buffer */
    VS1053B_TYPE_PERIOD       = 0x07,        /**< period */
} vs1053b_type_t;

/**
 * @brief vs1053b format enumeration definition
 */
typedef enum
{
    VS1053B_FORMAT_WAV      = 0x7665,        /**< wav */
    VS1053B_FORMAT_MIDI     = 0X4D54,        /**< midi */
    VS1053B_FORMAT_AAC_ADTS = 0X4154,        /**< acc adts */
    VS1053B_FORMAT_AAC_ADIF = 0X4144,        /**< acc adif */
    VS1053B_FORMAT_AAC_MP4  = 0X4D34,        /**< acc mp4 */
    VS1053B_FORMAT_OGG      = 0X4F67,        /**< ogg */
    VS1053B_FORMAT_WMA      = 0X574D,        /**< wma */
    VS1053B_FORMAT_FLAC     = 0X664C,        /**< flac */
    VS1053B_FORMAT_MP3      = 0xFFE0,        /**< mp3 */
} vs1053b_format_t;

/**
 * @brief vs1053b patch enumeration definition
 */
typedef enum
{
    VS1053B_PATCH_FLAC            = 0x00,        /**< flac */
    VS1053B_PATCH_WAV             = 0x01,        /**< wav */
    VS1053B_PATCH_OGG_VENC08K1Q00 = 0x02,        /**< ogg venc08k1q00 */
    VS1053B_PATCH_OGG_VENC08K1Q01 = 0x03,        /**< ogg venc08k1q01 */
    VS1053B_PATCH_OGG_VENC08K1Q02 = 0x04,        /**< ogg venc08k1q02 */
    VS1053B_PATCH_OGG_VENC08K1Q03 = 0x05,        /**< ogg venc08k1q03 */
    VS1053B_PATCH_OGG_VENC08K1Q04 = 0x06,        /**< ogg venc08k1q04 */
    VS1053B_PATCH_OGG_VENC08K1Q05 = 0x07,        /**< ogg venc08k1q05 */
    VS1053B_PATCH_OGG_VENC08K1Q06 = 0x08,        /**< ogg venc08k1q06 */
    VS1053B_PATCH_OGG_VENC08K1Q07 = 0x09,        /**< ogg venc08k1q07 */
    VS1053B_PATCH_OGG_VENC08K1Q08 = 0x0A,        /**< ogg venc08k1q08 */
    VS1053B_PATCH_OGG_VENC08K1Q09 = 0x0B,        /**< ogg venc08k1q09 */
    VS1053B_PATCH_OGG_VENC08K1Q10 = 0x0C,        /**< ogg venc08k1q10 */
    VS1053B_PATCH_OGG_VENC16K1Q00 = 0x0D,        /**< ogg venc16k1q00 */
    VS1053B_PATCH_OGG_VENC16K1Q01 = 0x0E,        /**< ogg venc16k1q01 */
    VS1053B_PATCH_OGG_VENC16K1Q02 = 0x0F,        /**< ogg venc16k1q02 */
    VS1053B_PATCH_OGG_VENC16K1Q03 = 0x10,        /**< ogg venc16k1q03 */
    VS1053B_PATCH_OGG_VENC16K1Q04 = 0x11,        /**< ogg venc16k1q04 */
    VS1053B_PATCH_OGG_VENC16K1Q05 = 0x12,        /**< ogg venc16k1q05 */
    VS1053B_PATCH_OGG_VENC16K1Q06 = 0x13,        /**< ogg venc16k1q06 */
    VS1053B_PATCH_OGG_VENC16K1Q07 = 0x14,        /**< ogg venc16k1q07 */
    VS1053B_PATCH_OGG_VENC16K1Q08 = 0x15,        /**< ogg venc16k1q08 */
    VS1053B_PATCH_OGG_VENC16K1Q09 = 0x16,        /**< ogg venc16k1q09 */
    VS1053B_PATCH_OGG_VENC16K1Q10 = 0x17,        /**< ogg venc16k1q10 */
    VS1053B_PATCH_OGG_VENC16K2Q00 = 0x18,        /**< ogg venc16k2q00 */
    VS1053B_PATCH_OGG_VENC16K2Q01 = 0x19,        /**< ogg venc16k2q01 */
    VS1053B_PATCH_OGG_VENC16K2Q02 = 0x1A,        /**< ogg venc16k2q02 */
    VS1053B_PATCH_OGG_VENC16K2Q03 = 0x1B,        /**< ogg venc16k2q03 */
    VS1053B_PATCH_OGG_VENC16K2Q04 = 0x1C,        /**< ogg venc16k2q04 */
    VS1053B_PATCH_OGG_VENC16K2Q05 = 0x1D,        /**< ogg venc16k2q05 */
    VS1053B_PATCH_OGG_VENC16K2Q06 = 0x1E,        /**< ogg venc16k2q06 */
    VS1053B_PATCH_OGG_VENC16K2Q07 = 0x1F,        /**< ogg venc16k2q07 */
    VS1053B_PATCH_OGG_VENC16K2Q08 = 0x20,        /**< ogg venc16k2q08 */
    VS1053B_PATCH_OGG_VENC16K2Q09 = 0x21,        /**< ogg venc16k2q09 */
    VS1053B_PATCH_OGG_VENC16K2Q10 = 0x22,        /**< ogg venc16k2q10 */
    VS1053B_PATCH_OGG_VENC44K1Q00 = 0x23,        /**< ogg venc44k1q00 */
    VS1053B_PATCH_OGG_VENC44K1Q01 = 0x24,        /**< ogg venc44k1q01 */
    VS1053B_PATCH_OGG_VENC44K1Q02 = 0x25,        /**< ogg venc44k1q02 */
    VS1053B_PATCH_OGG_VENC44K1Q03 = 0x26,        /**< ogg venc44k1q03 */
    VS1053B_PATCH_OGG_VENC44K1Q04 = 0x27,        /**< ogg venc44k1q04 */
    VS1053B_PATCH_OGG_VENC44K1Q05 = 0x28,        /**< ogg venc44k1q05 */
    VS1053B_PATCH_OGG_VENC44K2Q00 = 0x29,        /**< ogg venc44k2q00 */
    VS1053B_PATCH_OGG_VENC44K2Q01 = 0x2A,        /**< ogg venc44k2q01 */
    VS1053B_PATCH_OGG_VENC44K2Q02 = 0x2B,        /**< ogg venc44k2q02 */
    VS1053B_PATCH_OGG_VENC44K2Q03 = 0x2C,        /**< ogg venc44k2q03 */
    VS1053B_PATCH_OGG_VENC44K2Q04 = 0x2D,        /**< ogg venc44k2q04 */
    VS1053B_PATCH_OGG_VENC44K2Q05 = 0x2E,        /**< ogg venc44k2q05 */
} vs1053b_patch_t;

/**
 * @brief vs1053b iis rate enumeration definition
 */
typedef enum
{
    VS1053B_IIS_RATE_48KHZ  = 0x00,        /**< 48khz */
    VS1053B_IIS_RATE_96KHZ  = 0x01,        /**< 96khz */
    VS1053B_IIS_RATE_192KHZ = 0x02,        /**< 192khz */
} vs1053b_iis_rate_t;

/**
 * @brief vs1053b record format enumeration definition
 */
typedef enum
{
    VS1053B_RECORD_FORMAT_WAV = 0x00,        /**< wav format */
    VS1053B_RECORD_FORMAT_OGG = 0x01,        /**< ogg format */
} vs1053b_record_format_t;

/**
 * @brief vs1053b audio info structure definition
 */
typedef struct vs1053b_audio_info_s
{
    vs1053b_format_t format;        /**< format */
    char format_name[32];           /**< format name */
    float kbps;                     /**< kbps */
} vs1053b_audio_info_t;

/**
 * @brief vs1053b wav structure definition
 */
typedef struct vs1053b_wav_s
{
    char chunk_id[4];                /**< chunk id */
    uint32_t chunk_size;             /**< chunk size */
    char format[4];                  /**< format */
    char sub_chunk1_id[4];           /**< sub chunk1 id */
    uint32_t sub_chunk1_size;        /**< sub chunk1 size */
    uint16_t audio_format;           /**< audio format */
    uint16_t num_channel;            /**< num channel */
    uint32_t sample_rate;            /**< sample rate */
    uint32_t byte_rate;              /**< byte rate */
    uint16_t block_align;            /**< block align */
    uint16_t bit_per_sample;         /**< bit per sample */
    char sub_chunk2_id[4];           /**< sub chunk2 id */
    uint32_t sub_chunk2_size;        /**< sub chunk2 size */
} vs1053b_wav_t;

/**
 * @brief vs1053b handle structure definition
 */
typedef struct vs1053b_handle_s
{
    uint8_t (*reset_gpio_init)(void);                                                /**< point to a reset_gpio_init function address */
    uint8_t (*reset_gpio_deinit)(void);                                              /**< point to a reset_gpio_deinit function address */
    uint8_t (*reset_gpio_write)(uint8_t data);                                       /**< point to a reset_gpio_write function address */
    uint8_t (*dreq_gpio_init)(void);                                                 /**< point to a dreq_gpio_init function address */
    uint8_t (*dreq_gpio_deinit)(void);                                               /**< point to a dreq_gpio_deinit function address */
    uint8_t (*dreq_gpio_read)(uint8_t *data);                                        /**< point to a dreq_gpio_read function address */
    uint8_t (*spi_cmd_init)(void);                                                   /**< point to a spi_cmd_init function address */
    uint8_t (*spi_cmd_deinit)(void);                                                 /**< point to a spi_cmd_deinit function address */
    uint8_t (*spi_cmd_read_address16)(uint16_t addr, uint8_t *buf, uint16_t len);    /**< point to a spi_cmd_read_address16 function address */
    uint8_t (*spi_cmd_write_address16)(uint16_t addr, uint8_t *buf, uint16_t len);   /**< point to a spi_cmd_write_address16 function address */
    uint8_t (*spi_dat_init)(void);                                                   /**< point to a spi_dat_init function address */
    uint8_t (*spi_dat_deinit)(void);                                                 /**< point to a spi_dat_deinit function address */
    uint8_t (*spi_dat_write_cmd)(uint8_t *buf, uint16_t len);                        /**< point to a spi_dat_write_cmd function address */
    void (*delay_ms)(uint32_t ms);                                                   /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                 /**< point to a debug_print function address */
    void (*receive_callback)(uint8_t type, uint32_t cur_pos);                        /**< point to a receive_callback function address */
    uint8_t (*audio_init)(uint8_t type, char *name, uint32_t *size);                 /**< point to a audio_init function address */
    uint8_t (*audio_deinit)(void);                                                   /**< point to a audio_deinit function address */
    uint8_t (*audio_read)(uint32_t addr, uint16_t size, uint8_t *buffer);            /**< point to a audio_read function address */
    uint8_t (*audio_write)(uint32_t addr, uint16_t size, uint8_t *buffer);           /**< point to a audio_write function address */
    void (*timestamp_read)(uint32_t *sec, uint32_t *us);                             /**< point to a timestamp_read function address */
    uint8_t buf[VS1053B_BUFFER_SIZE];                                                /**< buffer */
    uint8_t inited;                                                                  /**< inited flag */
    uint8_t record_type;                                                             /**< record type */
    uint8_t plugin_patch_type;                                                       /**< plugin patch type */
    uint8_t status;                                                                  /**< status */
    uint8_t pause;                                                                   /**< pause */
    uint32_t cur_pos;                                                                /**< current position */
    uint32_t buf_pos;                                                                /**< buffer position */
    uint32_t size;                                                                   /**< size */
    uint64_t timestamp;                                                              /**< timestamp */
    uint64_t period;                                                                 /**< period */
    uint8_t period_enable;                                                           /**< period enable */
    vs1053b_wav_t wav;                                                               /**< wav header */
} vs1053b_handle_t;

/**
 * @brief vs1053b information structure definition
 */
typedef struct vs1053b_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} vs1053b_info_t;

/**
 * @}
 */

/**
 * @defgroup vs1053b_link_driver vs1053b link driver function
 * @brief    vs1053b link driver modules
 * @ingroup  vs1053b_driver
 * @{
 */

/**
 * @brief     initialize vs1053b_handle_t structure
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] STRUCTURE is vs1053b_handle_t
 * @note      none
 */
#define DRIVER_VS1053B_LINK_INIT(HANDLE, STRUCTURE)                 memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link spi_cmd_init function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_cmd_init function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_CMD_INIT(HANDLE, FUC)              (HANDLE)->spi_cmd_init = FUC

/**
 * @brief     link spi_cmd_deinit function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_cmd_deinit function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_CMD_DEINIT(HANDLE, FUC)            (HANDLE)->spi_cmd_deinit = FUC

/**
 * @brief     link spi_cmd_read_address16 function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_cmd_read_address16 function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_READ_ADDRESS16(HANDLE, FUC)        (HANDLE)->spi_cmd_read_address16 = FUC

/**
 * @brief     link spi_cmd_write_address16 function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_cmd_write_address16 function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_WRITE_ADDRESS16(HANDLE, FUC)       (HANDLE)->spi_cmd_write_address16 = FUC

/**
 * @brief     link spi_dat_init function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_dat_init function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_DAT_INIT(HANDLE, FUC)              (HANDLE)->spi_dat_init = FUC

/**
 * @brief     link spi_dat_deinit function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_dat_deinit function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_DAT_DEINIT(HANDLE, FUC)            (HANDLE)->spi_dat_deinit = FUC

/**
 * @brief     link spi_dat_write_cmd function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a spi_dat_write_cmd function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_SPI_DAT_WRITE_CMD(HANDLE, FUC)         (HANDLE)->spi_dat_write_cmd = FUC

/**
 * @brief     link reset_gpio_init function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a reset_gpio_init function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_RESET_GPIO_INIT(HANDLE, FUC)           (HANDLE)->reset_gpio_init = FUC

/**
 * @brief     link reset_gpio_deinit function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a reset_gpio_deinit function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_RESET_GPIO_DEINIT(HANDLE, FUC)         (HANDLE)->reset_gpio_deinit = FUC

/**
 * @brief     link reset_gpio_write function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a reset_gpio_write function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_RESET_GPIO_WRITE(HANDLE, FUC)          (HANDLE)->reset_gpio_write = FUC

/**
 * @brief     link dreq_gpio_init function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a dreq_gpio_init function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_DREQ_GPIO_INIT(HANDLE, FUC)            (HANDLE)->dreq_gpio_init = FUC

/**
 * @brief     link dreq_gpio_deinit function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a dreq_gpio_deinit function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_DREQ_GPIO_DEINIT(HANDLE, FUC)          (HANDLE)->dreq_gpio_deinit = FUC

/**
 * @brief     link dreq_gpio_read function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a dreq_gpio_read function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_DREQ_GPIO_READ(HANDLE, FUC)            (HANDLE)->dreq_gpio_read = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_DELAY_MS(HANDLE, FUC)                  (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_DEBUG_PRINT(HANDLE, FUC)               (HANDLE)->debug_print = FUC

/**
 * @brief     link receive_callback function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a receive_callback function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_RECEIVE_CALLBACK(HANDLE, FUC)          (HANDLE)->receive_callback = FUC

/**
 * @brief     link audio_init function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a audio_init function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_AUDIO_INIT(HANDLE, FUC)                (HANDLE)->audio_init = FUC

/**
 * @brief     link audio_deinit function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a audio_deinit function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_AUDIO_DEINIT(HANDLE, FUC)              (HANDLE)->audio_deinit = FUC

/**
 * @brief     link audio_read function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a audio_read function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_AUDIO_READ(HANDLE, FUC)                (HANDLE)->audio_read = FUC

/**
 * @brief     link audio_write function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a audio_write function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_AUDIO_WRITE(HANDLE, FUC)               (HANDLE)->audio_write = FUC

/**
 * @brief     link timestamp_read function
 * @param[in] HANDLE points to a vs1053b handle structure
 * @param[in] FUC points to a timestamp_read function address
 * @note      none
 */
#define DRIVER_VS1053B_LINK_TIMESTAMP_READ(HANDLE, FUC)            (HANDLE)->timestamp_read = FUC

/**
 * @}
 */

/**
 * @defgroup vs1053b_basic_driver vs1053b basic driver function
 * @brief    vs1053b basic driver modules
 * @ingroup  vs1053b_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to a vs1053b info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t vs1053b_info(vs1053b_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 reset or dreq gpio initialization failed
 *            - 5 reset failed
 * @note      none
 */
uint8_t vs1053b_init(vs1053b_handle_t *handle);

/**
 * @brief     deinit the chip
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 reset failed
 * @note      none
 */
uint8_t vs1053b_deinit(vs1053b_handle_t *handle);

/**
 * @brief     play audio
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *path points to a path buffer
 * @return    status code
 *            - 0 success
 *            - 1 play failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 audio working
 * @note      none
 */
uint8_t vs1053b_play(vs1053b_handle_t *handle, char *path);

/**
 * @brief     record audio
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *path points to a path buffer
 * @param[in] sample_rate is the set sample rate
 * @return    status code
 *            - 0 success
 *            - 1 record failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 audio working
 *            - 5 sample rate doesn't match patch
 * @note      none
 */
uint8_t vs1053b_record(vs1053b_handle_t *handle, char *path, uint32_t sample_rate);

/**
 * @brief     set record format
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] format is the set record format
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_record_format(vs1053b_handle_t *handle, vs1053b_record_format_t format);

/**
 * @brief      get record format
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *format points to a record format buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_record_format(vs1053b_handle_t *handle, vs1053b_record_format_t *format);

/**
 * @brief     pause audio
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 audio working
 * @note      none
 */
uint8_t vs1053b_pause(vs1053b_handle_t *handle);

/**
 * @brief     stop audio
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 audio not working
 *            - 5 status is invalid
 * @note      none
 */
uint8_t vs1053b_stop(vs1053b_handle_t *handle);

/**
 * @brief     audio process
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 process failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 no working
 *            - 5 status is invalid
 * @note      none
 */
uint8_t vs1053b_process(vs1053b_handle_t *handle);

/**
 * @brief     set period callback
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] second is the set second
 * @param[in] microsecond is the set microsecond
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_period_callback(vs1053b_handle_t *handle, uint32_t second, uint32_t microsecond, vs1053b_bool_t enable);

/**
 * @brief      get period callback
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *second points to a second buffer
 * @param[out] *microsecond points to a microsecond buffer
 * @param[out] *enable points to a bool value buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_period_callback(vs1053b_handle_t *handle, uint32_t *second, uint32_t *microsecond, vs1053b_bool_t *enable);

/**
 * @brief      parse info
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  dat0 is the hdata0
 * @param[in]  dat1 is the hdata1
 * @param[out] *info points to a vs1053b audio info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_parse_info(vs1053b_handle_t *handle, uint16_t dat0, uint16_t dat1, vs1053b_audio_info_t *info);

/**
 * @brief     hard reset
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 hard reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_hard_reset(vs1053b_handle_t *handle);

/**
 * @brief     set the audio differential
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] diff is the audio differential
 * @return    status code
 *            - 0 success
 *            - 1 set diff failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_diff(vs1053b_handle_t *handle, vs1053b_diff_t diff);

/**
 * @brief      get the audio differential
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *diff points to an audio differential buffer
 * @return     status code
 *             - 0 success
 *             - 1 get diff failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_diff(vs1053b_handle_t *handle, vs1053b_diff_t *diff);

/**
 * @brief     enable or disable mpeg layer i and ii
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set mpeg layer i and ii failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_mpeg_layer_i_and_ii(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get mpeg layer i and ii status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get mpeg layer i and ii failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_mpeg_layer_i_and_ii(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable soft reset
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set soft reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_soft_reset(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get soft reset status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get soft reset failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_soft_reset(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable cancel decoding current file
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set cancel decoding current file failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_cancel_decoding_current_file(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get cancel decoding current file status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get cancel decoding current file failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_cancel_decoding_current_file(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable ear speaker low setting
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set ear speaker low setting failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_ear_speaker_low_setting(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get ear speaker low setting status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get ear speaker low setting failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_ear_speaker_low_setting(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable allow sdi test
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set allow sdi test failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_allow_sdi_test(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get allow sdi test status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get allow sdi test failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_allow_sdi_test(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable stream mode
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set stream mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_stream_mode(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get stream mode status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get stream mode failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_stream_mode(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable ear speaker high setting
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set ear speaker high setting failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_ear_speaker_high_setting(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get ear speaker high setting status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get ear speaker high setting failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_ear_speaker_high_setting(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     set dclk edge
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] edge is the dclk edge
 * @return    status code
 *            - 0 success
 *            - 1 set dclk edge failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_dclk_edge(vs1053b_handle_t *handle, vs1053b_dclk_edge_t edge);

/**
 * @brief      get dclk edge
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *edge points to a dclk edge buffer
 * @return     status code
 *             - 0 success
 *             - 1 get dclk edge failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_dclk_edge(vs1053b_handle_t *handle, vs1053b_dclk_edge_t *edge);

/**
 * @brief     set sdi bit order
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] order is the bit order
 * @return    status code
 *            - 0 success
 *            - 1 set sdi bit order failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_sdi_bit_order(vs1053b_handle_t *handle, vs1053b_bit_order_t order);

/**
 * @brief      get sdi bit order
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *order points to a bit order buffer
 * @return     status code
 *             - 0 success
 *             - 1 get sdi bit order failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_sdi_bit_order(vs1053b_handle_t *handle, vs1053b_bit_order_t *order);

/**
 * @brief     enable or disable share spi chip select
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set share spi chip select failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_share_spi_chip_select(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get share spi chip select status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get share spi chip select failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_share_spi_chip_select(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable native spi modes
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set native spi modes failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_native_spi_modes(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get native spi modes status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get native spi modes failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_native_spi_modes(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable pcm adpcm recording active
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set pcm adpcm recording active failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_pcm_adpcm_recording_active(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get pcm adpcm recording active status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get pcm adpcm recording active failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_pcm_adpcm_recording_active(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     set selector
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] selector is the set param
 * @return    status code
 *            - 0 success
 *            - 1 set selector failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_selector(vs1053b_handle_t *handle, vs1053b_selector_t selector);

/**
 * @brief      get selector
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *selector points to a param buffer
 * @return     status code
 *             - 0 success
 *             - 1 get selector failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_selector(vs1053b_handle_t *handle, vs1053b_selector_t *selector);

/**
 * @brief     set clock range
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] range is the clock range
 * @return    status code
 *            - 0 success
 *            - 1 set clock range failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_clock_range(vs1053b_handle_t *handle, vs1053b_clock_range_t range);

/**
 * @brief      get clock range
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *range points to a range buffer
 * @return     status code
 *             - 0 success
 *             - 1 get clock range failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_clock_range(vs1053b_handle_t *handle, vs1053b_clock_range_t *range);

/**
 * @brief     enable or disable do not jump
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set do not jump failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_do_not_jump(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get do not jump status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get do not jump failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_do_not_jump(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     set swing
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] swing is the set param
 * @return    status code
 *            - 0 success
 *            - 1 set swing failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 swing > 7
 * @note      none
 */
uint8_t vs1053b_set_swing(vs1053b_handle_t *handle, uint8_t swing);

/**
 * @brief      get swing
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *swing points to a param buffer
 * @return     status code
 *             - 0 success
 *             - 1 get swing failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_swing(vs1053b_handle_t *handle, uint8_t *swing);

/**
 * @brief      convert the swing to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  db is the set db
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_swing_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg);

/**
 * @brief      convert the register raw data to the swing
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *db points to a db buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_swing_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db);

/**
 * @brief     enable or disable overload indicator
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set overload indicator failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_overload_indicator(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get overload indicator status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get overload indicator failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_overload_indicator(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable overload detection
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set overload detection failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_overload_detection(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get overload detection status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get overload detection failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_overload_detection(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief      get version
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *version points to a version buffer
 * @return     status code
 *             - 0 success
 *             - 1 get version failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_version(vs1053b_handle_t *handle, uint8_t *version);

/**
 * @brief     enable or disable analog driver power down
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set analog driver power down failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_analog_driver_power_down(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get analog driver power down status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get analog driver power down failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_analog_driver_power_down(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable analog internal power down
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set analog internal power down failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_analog_internal_power_down(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get analog internal power down status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool buffer
 * @return     status code
 *             - 0 success
 *             - 1 get analog internal power down failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_analog_internal_power_down(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     set ad clock
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] ad_clock is the ad clock
 * @return    status code
 *            - 0 success
 *            - 1 set ad clock failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_ad_clock(vs1053b_handle_t *handle, vs1053b_ad_clock_t ad_clock);

/**
 * @brief      get ad clock
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *ad_clock points to a ad clock buffer
 * @return     status code
 *             - 0 success
 *             - 1 get ad clock failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_ad_clock(vs1053b_handle_t *handle, vs1053b_ad_clock_t *ad_clock);

/**
 * @brief     set reference voltage
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] voltage is the reference voltage
 * @return    status code
 *            - 0 success
 *            - 1 set reference voltage failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_reference_voltage(vs1053b_handle_t *handle, vs1053b_reference_voltage_t voltage);

/**
 * @brief      get reference voltage
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *voltage points to a reference voltage buffer
 * @return     status code
 *             - 0 success
 *             - 1 get reference voltage failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_reference_voltage(vs1053b_handle_t *handle, vs1053b_reference_voltage_t *voltage);

/**
 * @brief     set treble control
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] db is the set db
 * @return    status code
 *            - 0 success
 *            - 1 set treble control failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 db > 15
 * @note      none
 */
uint8_t vs1053b_set_treble_control(vs1053b_handle_t *handle, uint8_t db);

/**
 * @brief      get treble control
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *db points to a db buffer
 * @return     status code
 *             - 0 success
 *             - 1 get treble control failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_treble_control(vs1053b_handle_t *handle, uint8_t *db);

/**
 * @brief      convert the treble control to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  db is the set db
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_treble_control_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg);

/**
 * @brief      convert the register raw data to the treble control
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *db points to a db buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_treble_control_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db);

/**
 * @brief     set lower limit frequency in 1000 hz
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] step is the set step
 * @return    status code
 *            - 0 success
 *            - 1 set lower limit frequency in 1000 hz failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 step > 15
 * @note      none
 */
uint8_t vs1053b_set_lower_limit_frequency_in_1000_hz(vs1053b_handle_t *handle, uint8_t step);

/**
 * @brief      get lower limit frequency in 1000 hz
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *step points to a step buffer
 * @return     status code
 *             - 0 success
 *             - 1 get lower limit frequency in 1000 hz failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_lower_limit_frequency_in_1000_hz(vs1053b_handle_t *handle, uint8_t *step);

/**
 * @brief      convert the lower limit frequency in 1000 hz to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  hz is the set hz
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(vs1053b_handle_t *handle, uint32_t hz, uint8_t *reg);

/**
 * @brief      convert the register raw data to the lower limit frequency in 1000 hz
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *hz points to an hz buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, uint32_t *hz);

/**
 * @brief     set bass enhancement
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] db is the set db
 * @return    status code
 *            - 0 success
 *            - 1 set bass enhancement failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 db > 15
 * @note      none
 */
uint8_t vs1053b_set_bass_enhancement(vs1053b_handle_t *handle, uint8_t db);

/**
 * @brief      get bass enhancement
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *db points to a db buffer
 * @return     status code
 *             - 0 success
 *             - 1 get bass enhancement failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_bass_enhancement(vs1053b_handle_t *handle, uint8_t *db);

/**
 * @brief     set lower limit frequency in 10 hz
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] step is the set step
 * @return    status code
 *            - 0 success
 *            - 1 set lower limit frequency in 10 hz failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 step > 15
 * @note      none
 */
uint8_t vs1053b_set_lower_limit_frequency_in_10_hz(vs1053b_handle_t *handle, uint8_t step);

/**
 * @brief      get lower limit frequency in 10 hz
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *step points to a step buffer
 * @return     status code
 *             - 0 success
 *             - 1 get lower limit frequency in 10 hz failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_lower_limit_frequency_in_10_hz(vs1053b_handle_t *handle, uint8_t *step);

/**
 * @brief      convert the lower limit frequency in 10 hz to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  hz is the set hz
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(vs1053b_handle_t *handle, uint32_t hz, uint8_t *reg);

/**
 * @brief      convert the register raw data to the lower limit frequency in 10 hz
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *hz points to an hz buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_lower_limit_frequency_in_10_hz_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, uint32_t *hz);

/**
 * @brief     set clock multiplier
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] multiplier is the clock multiplier
 * @return    status code
 *            - 0 success
 *            - 1 set clock multiplier failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_clock_multiplier(vs1053b_handle_t *handle, vs1053b_clock_multiplier_t multiplier);

/**
 * @brief      get clock multiplier
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *multiplier points to a clock multiplier buffer
 * @return     status code
 *             - 0 success
 *             - 1 get clock multiplier failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_clock_multiplier(vs1053b_handle_t *handle, vs1053b_clock_multiplier_t *multiplier);

/**
 * @brief     set allowed multiplier addition
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] addition is the allowed multiplier addition
 * @return    status code
 *            - 0 success
 *            - 1 set allowed multiplier addition failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_allowed_multiplier_addition(vs1053b_handle_t *handle, vs1053b_allowed_multiplier_addition_t addition);

/**
 * @brief      get allowed multiplier addition
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *addition points to an allowed multiplier addition buffer
 * @return     status code
 *             - 0 success
 *             - 1 get allowed multiplier addition failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_allowed_multiplier_addition(vs1053b_handle_t *handle, vs1053b_allowed_multiplier_addition_t *addition);

/**
 * @brief     set clock frequency
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] clk is the clock frequency
 * @return    status code
 *            - 0 success
 *            - 1 set clock frequency failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 clk > 0x3FF
 * @note      none
 */
uint8_t vs1053b_set_clock_frequency(vs1053b_handle_t *handle, uint16_t clk);

/**
 * @brief      get clock frequency
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *clk points to a clock buffer
 * @return     status code
 *             - 0 success
 *             - 1 get clock frequency failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_clock_frequency(vs1053b_handle_t *handle, uint16_t *clk);

/**
 * @brief      convert the clock frequency to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  hz is the set hz
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_clock_frequency_convert_to_register(vs1053b_handle_t *handle, float hz, uint16_t *reg);

/**
 * @brief      convert the register raw data to the clock frequency
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *hz points to an hz buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_clock_frequency_convert_to_data(vs1053b_handle_t *handle, uint16_t reg, float *hz);

/**
 * @brief     set decode time
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] decode_time is the decode time
 * @return    status code
 *            - 0 success
 *            - 1 set decode time failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_decode_time(vs1053b_handle_t *handle, uint16_t decode_time);

/**
 * @brief      get decode time
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *decode_time points to a decode time buffer
 * @return     status code
 *             - 0 success
 *             - 1 get decode time failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_decode_time(vs1053b_handle_t *handle, uint16_t *decode_time);

/**
 * @brief     set sample rate
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] rate is the sample rate
 * @param[in] channel is the set channel
 * @return    status code
 *            - 0 success
 *            - 1 set sample rate failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_sample_rate(vs1053b_handle_t *handle, uint16_t rate, vs1053b_channel_t channel);

/**
 * @brief      get sample rate
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *rate points to a sample rate buffer
 * @param[out] *channel points to a channel buffer
 * @return     status code
 *             - 0 success
 *             - 1 get sample rate failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_sample_rate(vs1053b_handle_t *handle, uint16_t *rate, vs1053b_channel_t *channel);

/**
 * @brief     write ram
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *buf points to an input buffer
 * @param[in] len is the buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write ram failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_write_ram(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @brief      read ram
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *buf points to an output buffer
 * @param[in]  len is the buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read ram failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_read_ram(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @brief     set ram address
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] addr is the ram address
 * @return    status code
 *            - 0 success
 *            - 1 set ram address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_ram_address(vs1053b_handle_t *handle, uint16_t addr);

/**
 * @brief      get hdata
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *dat0 points to a data buffer
 * @param[out] *dat1 points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get hdata failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_hdata(vs1053b_handle_t *handle, uint16_t *dat0, uint16_t *dat1);

/**
 * @brief      get hdata0
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *dat0 points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get hdata0 failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_hdata0(vs1053b_handle_t *handle, uint16_t *dat0);

/**
 * @brief      get hdata1
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *dat1 points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get hdata1 failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_hdata1(vs1053b_handle_t *handle, uint16_t *dat1);

/**
 * @brief     set start address
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] addr is the start address
 * @return    status code
 *            - 0 success
 *            - 1 set start address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_start_address(vs1053b_handle_t *handle, uint16_t addr);

/**
 * @brief      get start address
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *addr points to an address buffer
 * @return     status code
 *             - 0 success
 *             - 1 get start address failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_start_address(vs1053b_handle_t *handle, uint16_t *addr);

/**
 * @brief     set vol
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] left is the left vol
 * @param[in] right is the right vol
 * @return    status code
 *            - 0 success
 *            - 1 set vol failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_vol(vs1053b_handle_t *handle, uint8_t left, uint8_t right);

/**
 * @brief      get vol
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *left points to a left vol buffer
 * @param[out] *right points to a right vol buffer
 * @return     status code
 *             - 0 success
 *             - 1 get vol failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_vol(vs1053b_handle_t *handle, uint8_t *left, uint8_t *right);

/**
 * @brief      convert vol to the register raw data
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  db is the set db
 * @param[out] *reg points to a register raw buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_vol_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg);

/**
 * @brief      convert the register raw data to vol
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register raw data
 * @param[out] *db points to a db buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_vol_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db);

/**
 * @brief     write application
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] num is the application num
 * @param[in] *buf points to an input buffer
 * @param[in] len is the buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write application failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_write_application(vs1053b_handle_t *handle, vs1053b_application_t num, uint8_t *buf, uint16_t len);

/**
 * @brief      read application
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  num is the application num
 * @param[out] *buf points to an output buffer
 * @param[in]  len is the buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read application failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_read_application(vs1053b_handle_t *handle, vs1053b_application_t num, uint8_t *buf, uint16_t len);

/**
 * @brief     set play speed
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] speed is the play speed
 * @return    status code
 *            - 0 success
 *            - 1 set play speed failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_play_speed(vs1053b_handle_t *handle, vs1053b_play_speed_t speed);

/**
 * @brief      get play speed
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *speed points to a play speed buffer
 * @return     status code
 *             - 0 success
 *             - 1 get play speed failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_play_speed(vs1053b_handle_t *handle, vs1053b_play_speed_t *speed);

/**
 * @brief      get byte rate
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *rate points to a rate buffer
 * @return     status code
 *             - 0 success
 *             - 1 get byte rate failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_byte_rate(vs1053b_handle_t *handle, uint16_t *rate);

/**
 * @brief      get end fill byte
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *byte points to a byte buffer
 * @return     status code
 *             - 0 success
 *             - 1 get end fill byte failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_end_fill_byte(vs1053b_handle_t *handle, uint16_t *byte);

/**
 * @brief      get patch info
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  type is the patch info
 * @param[out] **patch_addr points to a patch address
 * @param[out] *len points to a length address
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_patch(vs1053b_handle_t *handle, vs1053b_patch_t type, const uint16_t **patch_addr, uint16_t *len);

/**
 * @brief     load patch
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *patch points to a patch buffer
 * @param[in] len is the length of length
 * @return    status code
 *            - 0 success
 *            - 1 load patch failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 invalid path address
 * @note      none
 */
uint8_t vs1053b_load_patch(vs1053b_handle_t *handle, const uint16_t *patch, uint16_t len);

/**
 * @brief     enable or disable iis mclk
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set iis mclk failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_iis_mclk(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get iis mclk status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool value buffer
 * @return     status code
 *             - 0 success
 *             - 1 get iis mclk failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_iis_mclk(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     enable or disable iis
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] enable is a bool value
 * @return    status code
 *            - 0 success
 *            - 1 set iis failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_iis(vs1053b_handle_t *handle, vs1053b_bool_t enable);

/**
 * @brief      get iis status
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *enable points to a bool value buffer
 * @return     status code
 *             - 0 success
 *             - 1 get iis failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_iis(vs1053b_handle_t *handle, vs1053b_bool_t *enable);

/**
 * @brief     set iis rate
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] iis_rate is the set iis rate
 * @return    status code
 *            - 0 success
 *            - 1 set iis rate failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_iis_rate(vs1053b_handle_t *handle, vs1053b_iis_rate_t iis_rate);

/**
 * @brief      get iis rate
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *iis_rate points to an iis rate buffer
 * @return     status code
 *             - 0 success
 *             - 1 get iis rate failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_iis_rate(vs1053b_handle_t *handle, vs1053b_iis_rate_t *iis_rate);

/**
 * @brief     set gpio direction
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] mask is the set gpio direction mask
 * @return    status code
 *            - 0 success
 *            - 1 set gpio direction failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_gpio_direction(vs1053b_handle_t *handle, uint16_t mask);

/**
 * @brief      get gpio direction
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *mask points to a gpio direction mask buffer
 * @return     status code
 *             - 0 success
 *             - 1 get gpio direction failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_gpio_direction(vs1053b_handle_t *handle, uint16_t *mask);

/**
 * @brief      get gpio input
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *data points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get gpio input failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_gpio_input(vs1053b_handle_t *handle, uint16_t *data);

/**
 * @brief     set gpio output
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] data is the set data
 * @return    status code
 *            - 0 success
 *            - 1 set gpio output failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_gpio_output(vs1053b_handle_t *handle, uint16_t data);

/**
 * @brief      get gpio output
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[out] *data points to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 get gpio output failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_gpio_output(vs1053b_handle_t *handle, uint16_t *data);

/**
 * @}
 */

/**
 * @defgroup vs1053b_extend_driver vs1053b extend driver function
 * @brief    vs1053b extend driver modules
 * @ingroup  vs1053b_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] reg is the register address
 * @param[in] *buf points to a data buffer
 * @param[in] len is the data buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_reg(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief      get the chip register
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register address
 * @param[out] *buf points to a data buffer
 * @param[in]  len is the data buffer length
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t vs1053b_get_reg(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len);

/**
 * @brief     set chip data
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *buf points to a data buffer
 * @param[in] len is the data buffer length
 * @return    status code
 *            - 0 success
 *            - 1 write data failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t vs1053b_set_data(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
