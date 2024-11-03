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
 * @file      driver_vs1053b.c
 * @brief     driver vs1053b source file
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

#include "driver_vs1053b.h"
#if VS1053B_OGG_VENC08K1Q00 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q00.h"
#endif
#if VS1053B_OGG_VENC08K1Q01 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q01.h"
#endif
#if VS1053B_OGG_VENC08K1Q02 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q02.h"
#endif
#if VS1053B_OGG_VENC08K1Q03 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q03.h"
#endif
#if VS1053B_OGG_VENC08K1Q04 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q04.h"
#endif
#if VS1053B_OGG_VENC08K1Q05 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q05.h"
#endif
#if VS1053B_OGG_VENC08K1Q06 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q06.h"
#endif
#if VS1053B_OGG_VENC08K1Q07 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q07.h"
#endif
#if VS1053B_OGG_VENC08K1Q08 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q08.h"
#endif
#if VS1053B_OGG_VENC08K1Q09 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q09.h"
#endif
#if VS1053B_OGG_VENC08K1Q10 != 0
    #include "driver_vs1053b_patch_ogg_venc08k1q10.h"
#endif
#if VS1053B_OGG_VENC16K1Q00 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q00.h"
#endif
#if VS1053B_OGG_VENC16K1Q01 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q01.h"
#endif
#if VS1053B_OGG_VENC16K1Q02 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q02.h"
#endif
#if VS1053B_OGG_VENC16K1Q03 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q03.h"
#endif
#if VS1053B_OGG_VENC16K1Q04 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q04.h"
#endif
#if VS1053B_OGG_VENC16K1Q05 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q05.h"
#endif
#if VS1053B_OGG_VENC16K1Q06 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q06.h"
#endif
#if VS1053B_OGG_VENC16K1Q07 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q07.h"
#endif
#if VS1053B_OGG_VENC16K1Q08 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q08.h"
#endif
#if VS1053B_OGG_VENC16K1Q09 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q09.h"
#endif
#if VS1053B_OGG_VENC16K1Q10 != 0
    #include "driver_vs1053b_patch_ogg_venc16k1q10.h"
#endif
#if VS1053B_OGG_VENC16K2Q00 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q00.h"
#endif
#if VS1053B_OGG_VENC16K2Q01 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q01.h"
#endif
#if VS1053B_OGG_VENC16K2Q02 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q02.h"
#endif
#if VS1053B_OGG_VENC16K2Q03 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q03.h"
#endif
#if VS1053B_OGG_VENC16K2Q04 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q04.h"
#endif
#if VS1053B_OGG_VENC16K2Q05 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q05.h"
#endif
#if VS1053B_OGG_VENC16K2Q06 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q06.h"
#endif
#if VS1053B_OGG_VENC16K2Q07 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q07.h"
#endif
#if VS1053B_OGG_VENC16K2Q08 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q08.h"
#endif
#if VS1053B_OGG_VENC16K2Q09 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q09.h"
#endif
#if VS1053B_OGG_VENC16K2Q10 != 0
    #include "driver_vs1053b_patch_ogg_venc16k2q10.h"
#endif
#if VS1053B_OGG_VENC44K1Q00 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q00.h"
#endif
#if VS1053B_OGG_VENC44K1Q01 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q01.h"
#endif
#if VS1053B_OGG_VENC44K1Q02 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q02.h"
#endif
#if VS1053B_OGG_VENC44K1Q03 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q03.h"
#endif
#if VS1053B_OGG_VENC44K1Q04 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q04.h"
#endif
#if VS1053B_OGG_VENC44K1Q05 != 0
    #include "driver_vs1053b_patch_ogg_venc44k1q05.h"
#endif
#if VS1053B_OGG_VENC44K2Q00 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q00.h"
#endif
#if VS1053B_OGG_VENC44K2Q01 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q01.h"
#endif
#if VS1053B_OGG_VENC44K2Q02 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q02.h"
#endif
#if VS1053B_OGG_VENC44K2Q03 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q03.h"
#endif
#if VS1053B_OGG_VENC44K2Q04 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q04.h"
#endif
#if VS1053B_OGG_VENC44K2Q05 != 0
    #include "driver_vs1053b_patch_ogg_venc44k2q05.h"
#endif
#include "driver_vs1053b_patch_flac.h"
#include "driver_vs1053b_patch_wav.h"
#include <math.h>

/**
 * @brief chip information definition
 */
#define CHIP_NAME                 "VLSI VS1053B"       /**< chip name */
#define MANUFACTURER_NAME         "VLSI"               /**< manufacturer name */
#define SUPPLY_VOLTAGE_MIN        2.6f                 /**< chip min supply voltage */
#define SUPPLY_VOLTAGE_MAX        3.6f                 /**< chip max supply voltage */
#define MAX_CURRENT               60.0f                /**< chip max current */
#define TEMPERATURE_MIN           -40.0f               /**< chip min operating temperature */
#define TEMPERATURE_MAX           85.0f                /**< chip max operating temperature */
#define DRIVER_VERSION            1000                 /**< driver version */

/**
 * @brief chip command definition
 */
#define VS1053B_COMMAND_READ         0x03        /**< read command */
#define VS1053B_COMMAND_WRITE        0x02        /**< write command */

/**
 * @brief chip register definition
 */
#define VS1053B_REG_MODE               0x00        /**< mode control register */
#define VS1053B_REG_STATUS             0x01        /**< status register */
#define VS1053B_REG_BASS               0x02        /**< built-in bass register */
#define VS1053B_REG_CLOCKF             0x03        /**< clock freq register */
#define VS1053B_REG_DECODE_TIME        0x04        /**< decode time register */
#define VS1053B_REG_AUDATA             0x05        /**< misc audio data register */
#define VS1053B_REG_WRAM               0x06        /**< ram register */
#define VS1053B_REG_WRAMADDR           0x07        /**< base address for ram register */
#define VS1053B_REG_HDAT0              0x08        /**< stream header data 0 register */
#define VS1053B_REG_HDAT1              0x09        /**< stream header data 1 register */
#define VS1053B_REG_AIADDR             0x0A        /**< start address of application register */
#define VS1053B_REG_VOL                0x0B        /**< volume control register */
#define VS1053B_REG_AICTRL0            0x0C        /**< application control register 0 register */
#define VS1053B_REG_AICTRL1            0x0D        /**< application control register 1 register */
#define VS1053B_REG_AICTRL2            0x0E        /**< application control register 2 register */
#define VS1053B_REG_AICTRL3            0x0F        /**< application control register 3 register */

/**
 * @brief chip status definition
 */
#define VS1053B_STATUS_STOP            0x00        /**< stop status */
#define VS1053B_STATUS_PLAY            0x01        /**< play status */
#define VS1053B_STATUS_RECORD          0x02        /**< record status */

/**
 * @brief inner function definition
 */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))        /**< min function */

/**
 * @brief      read bytes
 * @param[in]  *handle points to a vs1053b handle structure
 * @param[in]  reg is the register address
 * @param[out] *buf points to a data buffer
 * @param[in]  len is the data length
 * @return     status code
 *             - 0 success
 *             - 1 spi read failed
 * @note       none
 */
static uint8_t a_vs1053b_spi_read(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len)
{
    if (handle->spi_cmd_read_address16(((uint16_t)(VS1053B_COMMAND_READ) << 8) | reg, buf, len) != 0)       /* spi read */
    {
        return 1;                                                                                           /* return error */
    }
    else
    {
        return 0;                                                                                           /* success return 0 */
    }
}

/**
 * @brief     write bytes
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] reg is the register address
 * @param[in] *buf points to a data buffer
 * @param[in] len is the data length
 * @return    status code
 *            - 0 success
 *            - 1 spi write failed
 * @note      none
 */
static uint8_t a_vs1053b_spi_write(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len)
{
    if (handle->spi_cmd_write_address16(((uint16_t)(VS1053B_COMMAND_WRITE) << 8) | reg, buf, len) != 0)       /* spi write */
    {
        return 1;                                                                                             /* return error */
    }
    else
    {
        return 0;                                                                                             /* success return 0 */
    }
}

/**
 * @brief     write data bytes
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *buf points to a data buffer
 * @param[in] len is the data length
 * @return    status code
 *            - 0 success
 *            - 1 spi write data failed
 * @note      none
 */
static uint8_t a_vs1053b_spi_write_data(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len)
{
    if (handle->spi_dat_write_cmd(buf, len) != 0)       /* spi write */
    {
        return 1;                                       /* return error */
    }
    else
    {
        return 0;                                       /* success return 0 */
    }
}

/**
 * @brief     check busy pin
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 busy
 *            - 2 read failed
 * @note      none
 */
static uint8_t a_check_busy_pin(vs1053b_handle_t *handle)
{
    uint16_t i;
    uint8_t dat;

    for (i = 0; i < 1000; i++)                        /* up to 1000ms */
    {
        if (handle->dreq_gpio_read(&dat) != 0)        /* read failed */
        {
            return 2;                                 /* return error */
        }
        if (dat != 0)                                 /* if high */
        {
            break;                                    /* break */
        }

        handle->delay_ms(1);                          /* delay 1ms */
    }

    if (i < 1000)                                     /* check up to 1000ms */
    {
        return 0;                                     /* success return 0 */
    }
    else
    {
        return 1;                                     /* return error */
    }
}

/**
 * @brief     stop playing
 * @param[in] *handle points to a vs1053b handle structure
 * @return    status code
 *            - 0 success
 *            - 1 stop failed
 * @note      none
 */
static uint8_t a_vs1053b_stop(vs1053b_handle_t *handle)
{
    uint8_t res;
    uint8_t dat0;
    uint8_t dat1;
    uint8_t buf[2];
    uint8_t buf_init[32];
    uint16_t i;
    uint16_t prev;

    if (a_check_busy_pin(handle) != 0)                                 /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");               /* chip is busy */

        return 1;                                                      /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);        /* read the mode */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");           /* read mode failed */

        return 1;                                                      /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */
    prev &= ~(1 << 3);                                                 /* clear the settings */
    prev |= 1 << 3;                                                    /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                       /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                       /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);       /* write the mode */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");          /* write mode failed */

        return 1;                                                      /* return error */
    }

    memset(buf_init, 0, sizeof(uint8_t) * 32);                         /* init */
    for (i = 0; i < 64; i++)                                           /* 64 times */
    {
        if (handle->spi_dat_write_cmd(buf_init, 32) != 0)              /* push data */
        {
            handle->debug_print("vs1053b: fill buffer failed.\n");     /* fill buffer failed */

            return 1;                                                  /* return error */
        }
        if (a_check_busy_pin(handle) != 0)                             /* check busy */
        {
            handle->debug_print("vs1053b: chip is busy.\n");           /* chip is busy */

            return 1;                                                  /* return error */
        }
        res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);    /* read the mode */
        if (res != 0)                                                  /* check result */
        {
            handle->debug_print("vs1053b: read mode failed.\n");       /* read mode failed */

            return 1;                                                  /* return error */
        }
        prev = ((uint16_t)(buf[0]) << 8) | buf[1];                     /* combine the config */
        if ((prev & (1 << 3)) == 0)                                    /* check cancel bit */
        {
            break;                                                     /* break */
        }
    }
    if (i >= 64)                                                       /* check times */
    {
        handle->debug_print("vs1053b: cancel bit is invalid.\n");      /* cancel bit is invalid */

        return 1;                                                      /* return error */
    }

    for (i = 0; i < 65; i++)                                           /* 65 times */
    {
        if (a_check_busy_pin(handle) != 0)                             /* check busy */
        {
            handle->debug_print("vs1053b: chip is busy.\n");           /* chip is busy */

            return 1;                                                  /* return error */
        }
        prev = 0x1E06;                                                 /* set addr */
        buf[0] = (prev >> 8) & 0xFF;                                   /* get msb */
        buf[1] = (prev >> 0) & 0xFF;                                   /* get lsb */
        res = a_vs1053b_spi_write(handle,
                                  VS1053B_REG_WRAMADDR, buf, 2);       /* write the ram addr */
        if (res != 0)                                                  /* check result */
        {
            handle->debug_print("vs1053b: write ram addr failed.\n");  /* write ram addr failed */

            return 1;                                                  /* return error */
        }
        if (a_check_busy_pin(handle) != 0)                             /* check busy */
        {
            handle->debug_print("vs1053b: chip is busy.\n");           /* chip is busy */

            return 1;                                                  /* return error */
        }
        res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);    /* read the ram */
        if (res != 0)                                                  /* check result */
        {
            handle->debug_print("vs1053b: read ram failed.\n");        /* read ram failed */

            return 1;                                                  /* return error */
        }
        prev = ((uint16_t)(buf[0]) << 8) | buf[1];                     /* combine data */
        memset(buf_init, prev & 0xFF, sizeof(uint8_t) * 32);           /* init */
        if (handle->spi_dat_write_cmd(buf_init, 32) != 0)              /* push data */
        {
            handle->debug_print("vs1053b: fill buffer failed.\n");     /* fill buffer failed */

            return 1;                                                  /* return error */
        }
    }

    if (a_check_busy_pin(handle) != 0)                                 /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");               /* chip is busy */

        return 1;                                                      /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);       /* read the hdat0 */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: read hdat0 failed.\n");          /* read hdat0 failed */

        return 1;                                                      /* return error */
    }
    dat0 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */
    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);       /* read the hdat1 */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: read hdat1 failed.\n");          /* read hdat1 failed */

        return 1;                                                      /* return error */
    }
    dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */
    if ((dat0 != 0) || (dat1 != 0))                                    /* check dat0 */
    {
        handle->debug_print("vs1053b: dat0 and dat1 ara invalid.\n");  /* dat0 and dat1 ara invalid */

        return 1;                                                      /* return error */
    }

    return 0;                                                          /* success return 0 */
}

/**
 * @brief     period callback
 * @param[in] *handle points to a vs1053b handle structure
 * @note      none
 */
static void a_period(vs1053b_handle_t *handle)
{
    if (handle->period_enable != 0)                                                    /* if enable */
    {
        uint32_t sec;
        uint32_t us;
        uint64_t current_time;

        handle->timestamp_read(&sec, &us);                                             /* read timestamp */
        current_time = (((uint64_t)sec) * 1000000 + ((uint64_t)us));                   /* create timestamp */
        if (current_time - handle->timestamp >= handle->period)                        /* check period */
        {
            if (handle->receive_callback != NULL)                                      /* if not null */
            {
                handle->receive_callback(VS1053B_TYPE_PERIOD, handle->cur_pos);        /* run the callback */
            }
            handle->timestamp = current_time;                                          /* save the current timestamp */
        }
    }
}

/**
 * @brief     write wav header
 * @param[in] *handle points to a vs1053b handle structure
 * @param[in] *wav points to a vs1053b wav structure
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
static uint8_t a_vs1053b_write_wav_header(vs1053b_handle_t *handle, vs1053b_wav_t *wav)
{
    uint8_t res;
    uint8_t buf[44];

    buf[0] = handle->wav.chunk_id[0];                                     /* R */
    buf[1] = handle->wav.chunk_id[1];                                     /* I */
    buf[2] = handle->wav.chunk_id[2];                                     /* F */
    buf[3] = handle->wav.chunk_id[3];                                     /* F */
    buf[4] = (handle->wav.chunk_size >> 0) & 0xFF;                        /* set chunk size */
    buf[5] = (handle->wav.chunk_size >> 8) & 0xFF;                        /* set chunk size */
    buf[6] = (handle->wav.chunk_size >> 16) & 0xFF;                       /* set chunk size */
    buf[7] = (handle->wav.chunk_size >> 24) & 0xFF;                       /* set chunk size */
    buf[8] = handle->wav.format[0];                                       /* W */
    buf[9] = handle->wav.format[1];                                       /* A */
    buf[10] = handle->wav.format[2];                                      /* V */
    buf[11] = handle->wav.format[3];                                      /* E */
    buf[12] = handle->wav.sub_chunk1_id[0];                               /* f */
    buf[13] = handle->wav.sub_chunk1_id[1];                               /* m */
    buf[14] = handle->wav.sub_chunk1_id[2];                               /* t */
    buf[15] = handle->wav.sub_chunk1_id[3];                               /* 0x00 */
    buf[16] = (handle->wav.sub_chunk1_size >> 0) & 0xFF;                  /* 16 bytes */
    buf[17] = (handle->wav.sub_chunk1_size >> 8) & 0xFF;                  /* 16 bytes */
    buf[18] = (handle->wav.sub_chunk1_size >> 16) & 0xFF;                 /* 16 bytes */
    buf[19] = (handle->wav.sub_chunk1_size >> 24) & 0xFF;                 /* 16 bytes */
    buf[20] = (handle->wav.audio_format >> 0) & 0xFF;                     /* pcm */
    buf[21] = (handle->wav.audio_format >> 8) & 0xFF;                     /* pcm */
    buf[22] = (handle->wav.num_channel >> 0) & 0xFF;                      /* 1 channel */
    buf[23] = (handle->wav.num_channel >> 8) & 0xFF;                      /* 1 channel */
    buf[24] = (handle->wav.sample_rate >> 0) & 0xFF;                      /* set sample rate */
    buf[25] = (handle->wav.sample_rate >> 8) & 0xFF;                      /* set sample rate */
    buf[26] = (handle->wav.sample_rate >> 16) & 0xFF;                     /* set sample rate */
    buf[27] = (handle->wav.sample_rate >> 24) & 0xFF;                     /* set sample rate */
    buf[28] = (handle->wav.byte_rate >> 0) & 0xFF;                        /* double */
    buf[29] = (handle->wav.byte_rate >> 8) & 0xFF;                        /* double */
    buf[30] = (handle->wav.byte_rate >> 16) & 0xFF;                       /* double */
    buf[31] = (handle->wav.byte_rate >> 24) & 0xFF;                       /* double */
    buf[32] = (handle->wav.block_align >> 0) & 0xFF;                      /* 2 bytes */
    buf[33] = (handle->wav.block_align >> 8) & 0xFF;                      /* 2 bytes */
    buf[34] = (handle->wav.bit_per_sample >> 0) & 0xFF;                   /* 16 bits */
    buf[35] = (handle->wav.bit_per_sample >> 8) & 0xFF;                   /* 16 bits */
    buf[36] = handle->wav.sub_chunk2_id[0];                               /* d */
    buf[37] = handle->wav.sub_chunk2_id[1];                               /* a */
    buf[38] = handle->wav.sub_chunk2_id[2];                               /* t */
    buf[39] = handle->wav.sub_chunk2_id[3];                               /* a */
    buf[40] = (handle->wav.sub_chunk2_size >> 0) & 0xFF;                  /* init 0 */
    buf[41] = (handle->wav.sub_chunk2_size >> 8) & 0xFF;                  /* init 0 */
    buf[42] = (handle->wav.sub_chunk2_size >> 16) & 0xFF;                 /* init 0 */
    buf[43] = (handle->wav.sub_chunk2_size >> 24) & 0xFF;                 /* init 0 */
    res = handle->audio_write(0, 44, buf);                                /* write buffer */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: audio write failed.\n");            /* audio write failed */

        return 1;                                                         /* return error */
    }

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_diff(vs1053b_handle_t *handle, vs1053b_diff_t diff)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 0);                                                /* clear the settings */
    prev |= diff << 0;                                                /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_diff(vs1053b_handle_t *handle, vs1053b_diff_t *diff)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *diff = (vs1053b_diff_t)((prev >> 0) & 0x01);                     /* get the diff */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_mpeg_layer_i_and_ii(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 1);                                                /* clear the settings */
    prev |= enable << 1;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_mpeg_layer_i_and_ii(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 1) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_soft_reset(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 2);                                                /* clear the settings */
    prev |= enable << 2;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }
    handle->delay_ms(2);                                              /* delay 2ms */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_soft_reset(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 2) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_cancel_decoding_current_file(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 3);                                                /* clear the settings */
    prev |= enable << 3;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_cancel_decoding_current_file(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 3) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_ear_speaker_low_setting(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 4);                                                /* clear the settings */
    prev |= enable << 4;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_ear_speaker_low_setting(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 4) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_allow_sdi_test(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 5);                                                /* clear the settings */
    prev |= enable << 5;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_allow_sdi_test(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 5) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_stream_mode(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 6);                                                /* clear the settings */
    prev |= enable << 6;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_stream_mode(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 6) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_ear_speaker_high_setting(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 7);                                                /* clear the settings */
    prev |= enable << 7;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_ear_speaker_high_setting(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 7) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_dclk_edge(vs1053b_handle_t *handle, vs1053b_dclk_edge_t edge)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 8);                                                /* clear the settings */
    prev |= edge << 8;                                                /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_dclk_edge(vs1053b_handle_t *handle, vs1053b_dclk_edge_t *edge)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *edge = (vs1053b_dclk_edge_t)((prev >> 8) & 0x01);                /* get the edge */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_sdi_bit_order(vs1053b_handle_t *handle, vs1053b_bit_order_t order)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 9);                                                /* clear the settings */
    prev |= order << 9;                                               /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_sdi_bit_order(vs1053b_handle_t *handle, vs1053b_bit_order_t *order)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *order = (vs1053b_bit_order_t)((prev >> 9) & 0x01);               /* get the order */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_share_spi_chip_select(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 10);                                               /* clear the settings */
    prev |= enable << 10;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_share_spi_chip_select(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 10) & 0x01);                  /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_native_spi_modes(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 11);                                               /* clear the settings */
    prev |= enable << 11;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_native_spi_modes(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 11) & 0x01);                  /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_pcm_adpcm_recording_active(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 12);                                               /* clear the settings */
    prev |= enable << 12;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_pcm_adpcm_recording_active(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 12) & 0x01);                  /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_selector(vs1053b_handle_t *handle, vs1053b_selector_t selector)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 14);                                               /* clear the settings */
    prev |= selector << 14;                                           /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_selector(vs1053b_handle_t *handle, vs1053b_selector_t *selector)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *selector = (vs1053b_selector_t)((prev >> 14) & 0x01);            /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_clock_range(vs1053b_handle_t *handle, vs1053b_clock_range_t range)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 15);                                               /* clear the settings */
    prev |= range << 15;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);      /* write the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");         /* write mode failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_clock_range(vs1053b_handle_t *handle, vs1053b_clock_range_t *range)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);       /* read the mode */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");          /* read mode failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *range = (vs1053b_clock_range_t)((prev >> 15) & 0x01);            /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_do_not_jump(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 15);                                               /* clear the settings */
    prev |= enable << 15;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_do_not_jump(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 15) & 0x01);                  /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_swing(vs1053b_handle_t *handle, uint8_t swing)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (swing > 7)                                                    /* check swing */
    {
        handle->debug_print("vs1053b: swing > 7.\n");                 /* swing > 7 */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0x07 << 12);                                            /* clear the settings */
    prev |= swing << 12;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_swing(vs1053b_handle_t *handle, uint8_t *swing)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *swing = (vs1053b_bool_t)((prev >> 12) & 0x07);                   /* get the swing */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_swing_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg)
{
    if (handle == NULL)                 /* check handle */
    {
        return 2;                       /* return error */
    }
    if (handle->inited != 1)            /* check handle initialization */
    {
        return 3;                       /* return error */
    }

    *reg = (uint8_t)(db / 2.0f);        /* convert real data to register data */

    return 0;                           /* success return 0 */
}

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
uint8_t vs1053b_swing_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db)
{
    if (handle == NULL)               /* check handle */
    {
        return 2;                     /* return error */
    }
    if (handle->inited != 1)          /* check handle initialization */
    {
        return 3;                     /* return error */
    }

    *db = (float)(reg) / 0.5f;        /* convert raw data to real data */

    return 0;                         /* success return 0 */
}

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
uint8_t vs1053b_set_overload_indicator(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 11);                                               /* clear the settings */
    prev |= enable << 11;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_overload_indicator(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 11) & 0x01);                  /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_overload_detection(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 10);                                               /* clear the settings */
    prev |= (!enable) << 10;                                          /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_overload_detection(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)(!((prev >> 10) & 0x01));               /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_version(vs1053b_handle_t *handle, uint8_t *version)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *version = (vs1053b_bool_t)((prev >> 4) & 0x0F);                  /* get the swing */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_analog_driver_power_down(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 3);                                                /* clear the settings */
    prev |= enable << 3;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_analog_driver_power_down(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 3) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_analog_internal_power_down(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 2);                                                /* clear the settings */
    prev |= enable << 2;                                              /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_analog_internal_power_down(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *enable = (vs1053b_bool_t)((prev >> 2) & 0x01);                   /* get the bool */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_ad_clock(vs1053b_handle_t *handle, vs1053b_ad_clock_t ad_clock)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 1);                                                /* clear the settings */
    prev |= ad_clock << 1;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_ad_clock(vs1053b_handle_t *handle, vs1053b_ad_clock_t *ad_clock)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *ad_clock = (vs1053b_ad_clock_t)((prev >> 1) & 0x01);             /* get the clock */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_reference_voltage(vs1053b_handle_t *handle, vs1053b_reference_voltage_t voltage)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(1 << 0);                                                /* clear the settings */
    prev |= voltage << 0;                                             /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_STATUS, buf, 2);    /* write the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write status failed.\n");       /* write status failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_reference_voltage(vs1053b_handle_t *handle, vs1053b_reference_voltage_t *voltage)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_STATUS, buf, 2);     /* read the status */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read status failed.\n");        /* read status failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *voltage = (vs1053b_reference_voltage_t)((prev >> 0) & 0x01);     /* get the voltage */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_treble_control(vs1053b_handle_t *handle, uint8_t db)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (db > 15)                                                      /* check db */
    {
        handle->debug_print("vs1053b: db > 15.\n");                   /* db > 15 */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0xF << 12);                                             /* clear the settings */
    prev |= db << 12;                                                 /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_BASS, buf, 2);      /* write the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write bass failed.\n");         /* write bass failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_treble_control(vs1053b_handle_t *handle, uint8_t *db)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *db = ((prev >> 12) & 0x0F);                                      /* get the control */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_treble_control_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg)
{
    if (handle == NULL)                 /* check handle */
    {
        return 2;                       /* return error */
    }
    if (handle->inited != 1)            /* check handle initialization */
    {
        return 3;                       /* return error */
    }

    *reg = (uint8_t)(db / 1.5f);        /* convert real data to register data */

    return 0;                           /* success return 0 */
}

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
uint8_t vs1053b_treble_control_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db)
{
    if (handle == NULL)               /* check handle */
    {
        return 2;                     /* return error */
    }
    if (handle->inited != 1)          /* check handle initialization */
    {
        return 3;                     /* return error */
    }

    *db = (float)(reg) * 1.5f;        /* convert raw data to real data */

    return 0;                         /* success return 0 */
}

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
uint8_t vs1053b_set_lower_limit_frequency_in_1000_hz(vs1053b_handle_t *handle, uint8_t step)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (step > 15)                                                    /* check step */
    {
        handle->debug_print("vs1053b: step > 15.\n");                 /* step > 15 */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0xF << 8);                                              /* clear the settings */
    prev |= step << 8;                                                /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_BASS, buf, 2);      /* write the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write bass failed.\n");         /* write bass failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_lower_limit_frequency_in_1000_hz(vs1053b_handle_t *handle, uint8_t *step)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *step = ((prev >> 8) & 0x0F);                                     /* get the freq */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register(vs1053b_handle_t *handle, uint32_t hz, uint8_t *reg)
{
    if (handle == NULL)                 /* check handle */
    {
        return 2;                       /* return error */
    }
    if (handle->inited != 1)            /* check handle initialization */
    {
        return 3;                       /* return error */
    }

    *reg = (uint8_t)(hz / 1000);        /* convert real data to register data */

    return 0;                           /* success return 0 */
}

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
uint8_t vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, uint32_t *hz)
{
    if (handle == NULL)               /* check handle */
    {
        return 2;                     /* return error */
    }
    if (handle->inited != 1)          /* check handle initialization */
    {
        return 3;                     /* return error */
    }

    *hz = (uint32_t)(reg) * 1000;     /* convert raw data to real data */

    return 0;                         /* success return 0 */
}

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
uint8_t vs1053b_set_bass_enhancement(vs1053b_handle_t *handle, uint8_t db)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (db > 15)                                                      /* check db */
    {
        handle->debug_print("vs1053b: db > 15.\n");                   /* db > 15 */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0xF << 4);                                              /* clear the settings */
    prev |= db << 4;                                                  /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_BASS, buf, 2);      /* write the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write bass failed.\n");         /* write bass failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_bass_enhancement(vs1053b_handle_t *handle, uint8_t *db)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *db = ((prev >> 4) & 0x0F);                                       /* get the enhancement */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_set_lower_limit_frequency_in_10_hz(vs1053b_handle_t *handle, uint8_t step)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (step > 15)                                                    /* check step */
    {
        handle->debug_print("vs1053b: step > 15.\n");                 /* step > 15 */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0xF << 0);                                              /* clear the settings */
    prev |= step << 0;                                                /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_BASS, buf, 2);      /* write the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write bass failed.\n");         /* write bass failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_lower_limit_frequency_in_10_hz(vs1053b_handle_t *handle, uint8_t *step)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_BASS, buf, 2);       /* read the bass */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read bass failed.\n");          /* read bass failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    *step = ((prev >> 0) & 0x0F);                                     /* get the freq */

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_lower_limit_frequency_in_10_hz_convert_to_register(vs1053b_handle_t *handle, uint32_t hz, uint8_t *reg)
{
    if (handle == NULL)                 /* check handle */
    {
        return 2;                       /* return error */
    }
    if (handle->inited != 1)            /* check handle initialization */
    {
        return 3;                       /* return error */
    }

    *reg = (uint8_t)(hz / 10);          /* convert real data to register data */

    return 0;                           /* success return 0 */
}

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
uint8_t vs1053b_lower_limit_frequency_in_10_hz_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, uint32_t *hz)
{
    if (handle == NULL)               /* check handle */
    {
        return 2;                     /* return error */
    }
    if (handle->inited != 1)          /* check handle initialization */
    {
        return 3;                     /* return error */
    }

    *hz = (uint32_t)(reg) * 10;       /* convert raw data to real data */

    return 0;                         /* success return 0 */
}

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
uint8_t vs1053b_set_clock_multiplier(vs1053b_handle_t *handle, vs1053b_clock_multiplier_t multiplier)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);     /* read the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");         /* read clock failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0x7 << 13);                                             /* clear the settings */
    prev |= multiplier << 13;                                         /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_CLOCKF, buf, 2);    /* write the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write clock failed.\n");        /* write clock failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_clock_multiplier(vs1053b_handle_t *handle, vs1053b_clock_multiplier_t *multiplier)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);       /* read the clock */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");           /* read clock failed */

        return 1;                                                       /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                          /* combine the config */
    *multiplier = (vs1053b_clock_multiplier_t)((prev >> 13) & 0x07);    /* get the multiplier */

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_set_allowed_multiplier_addition(vs1053b_handle_t *handle, vs1053b_allowed_multiplier_addition_t addition)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);     /* read the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");         /* read clock failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0x3 << 11);                                             /* clear the settings */
    prev |= addition << 11;                                           /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_CLOCKF, buf, 2);    /* write the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write clock failed.\n");        /* write clock failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_allowed_multiplier_addition(vs1053b_handle_t *handle, vs1053b_allowed_multiplier_addition_t *addition)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                          /* check handle */
    {
        return 2;                                                                /* return error */
    }
    if (handle->inited != 1)                                                     /* check handle initialization */
    {
        return 3;                                                                /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                           /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                         /* chip is busy */

        return 1;                                                                /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);                /* read the clock */
    if (res != 0)                                                                /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");                    /* read clock failed */

        return 1;                                                                /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                                   /* combine the config */
    *addition = (vs1053b_allowed_multiplier_addition_t)((prev >> 11) & 0x03);    /* get the addition */

    return 0;                                                                    /* success return 0 */
}

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
uint8_t vs1053b_set_clock_frequency(vs1053b_handle_t *handle, uint16_t clk)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                               /* check handle */
    {
        return 2;                                                     /* return error */
    }
    if (handle->inited != 1)                                          /* check handle initialization */
    {
        return 3;                                                     /* return error */
    }
    if (clk > 0x3FF)                                                  /* check clock */
    {
        handle->debug_print("vs1053b: clk > 0x3FF.\n");               /* clk > 0x3FF */

        return 4;                                                     /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");              /* chip is busy */

        return 1;                                                     /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);     /* read the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");         /* read clock failed */

        return 1;                                                     /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */
    prev &= ~(0x3FF << 0);                                            /* clear the settings */
    prev |= clk << 0;                                                 /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                      /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                      /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_CLOCKF, buf, 2);    /* write the clock */
    if (res != 0)                                                     /* check result */
    {
        handle->debug_print("vs1053b: write clock failed.\n");        /* write clock failed */

        return 1;                                                     /* return error */
    }

    return 0;                                                         /* success return 0 */
}

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
uint8_t vs1053b_get_clock_frequency(vs1053b_handle_t *handle, uint16_t *clk)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                  /* check handle */
    {
        return 2;                                                        /* return error */
    }
    if (handle->inited != 1)                                             /* check handle initialization */
    {
        return 3;                                                        /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                   /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                 /* chip is busy */

        return 1;                                                        /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_CLOCKF, buf, 2);        /* read the clock */
    if (res != 0)                                                        /* check result */
    {
        handle->debug_print("vs1053b: read clock failed.\n");            /* read clock failed */

        return 1;                                                        /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine the config */
    *clk = ((prev >> 0) & 0x3FF);                                        /* get the freq */

    return 0;                                                            /* success return 0 */
}

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
uint8_t vs1053b_clock_frequency_convert_to_register(vs1053b_handle_t *handle, float hz, uint16_t *reg)
{
    if (handle == NULL)                                  /* check handle */
    {
        return 2;                                        /* return error */
    }
    if (handle->inited != 1)                             /* check handle initialization */
    {
        return 3;                                        /* return error */
    }

    *reg = (uint16_t)((hz - 8000000.0f) / 4000.0f);      /* convert real data to register data */

    return 0;                                            /* success return 0 */
}

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
uint8_t vs1053b_clock_frequency_convert_to_data(vs1053b_handle_t *handle, uint16_t reg, float *hz)
{
    if (handle == NULL)                                    /* check handle */
    {
        return 2;                                          /* return error */
    }
    if (handle->inited != 1)                               /* check handle initialization */
    {
        return 3;                                          /* return error */
    }

    *hz = (float)((float)reg * 4000.0f + 8000000.0f);      /* convert raw data to real data */

    return 0;                                              /* success return 0 */
}

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
uint8_t vs1053b_set_decode_time(vs1053b_handle_t *handle, uint16_t decode_time)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                    /* check handle */
    {
        return 2;                                                          /* return error */
    }
    if (handle->inited != 1)                                               /* check handle initialization */
    {
        return 3;                                                          /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                     /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

        return 1;                                                          /* return error */
    }

    buf[0] = (decode_time >> 8) & 0xFF;                                    /* get msb */
    buf[1] = (decode_time >> 0) & 0xFF;                                    /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_DECODE_TIME, buf, 2);    /* write the decode time */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: write decode time failed.\n");       /* write decode time failed */

        return 1;                                                          /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                     /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

        return 1;                                                          /* return error */
    }
    res = a_vs1053b_spi_write(handle, VS1053B_REG_DECODE_TIME, buf, 2);    /* write the decode time */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: write decode time failed.\n");       /* write decode time failed */

        return 1;                                                          /* return error */
    }

    return 0;                                                              /* success return 0 */
}

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
uint8_t vs1053b_get_decode_time(vs1053b_handle_t *handle, uint16_t *decode_time)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                       /* check handle */
    {
        return 2;                                                             /* return error */
    }
    if (handle->inited != 1)                                                  /* check handle initialization */
    {
        return 3;                                                             /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                        /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                      /* chip is busy */

        return 1;                                                             /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_DECODE_TIME, buf, 2);        /* read the decode time */
    if (res != 0)                                                             /* check result */
    {
        handle->debug_print("vs1053b: read decode time failed.\n");           /* read decode time failed */

        return 1;                                                             /* return error */
    }
    *decode_time = ((uint16_t)(buf[0]) << 8) | buf[1];                        /* combine the config */

    return 0;                                                                 /* success return 0 */
}

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
uint8_t vs1053b_set_sample_rate(vs1053b_handle_t *handle, uint16_t rate, vs1053b_channel_t channel)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }

    prev = rate | channel;                                                /* set channel */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_AUDATA, buf, 2);        /* write the audata */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write audata failed.\n");           /* write audata failed */

        return 1;                                                         /* return error */
    }

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_sample_rate(vs1053b_handle_t *handle, uint16_t *rate, vs1053b_channel_t *channel)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                  /* check handle */
    {
        return 2;                                                        /* return error */
    }
    if (handle->inited != 1)                                             /* check handle initialization */
    {
        return 3;                                                        /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                   /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                 /* chip is busy */

        return 1;                                                        /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_AUDATA, buf, 2);        /* read the audata */
    if (res != 0)                                                        /* check result */
    {
        handle->debug_print("vs1053b: read audata failed.\n");           /* read audata failed */

        return 1;                                                        /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine the config */
    *rate = prev & (~(1 << 0));                                          /* get the rate */
    *channel = (vs1053b_channel_t)(prev & 0x01);                         /* get the channel */

    return 0;                                                            /* success return 0 */
}

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
uint8_t vs1053b_write_ram(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len)
{
    uint8_t res;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }

    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, len);        /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_read_ram(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len)
{
    uint8_t res;

    if (handle == NULL)                                                  /* check handle */
    {
        return 2;                                                        /* return error */
    }
    if (handle->inited != 1)                                             /* check handle initialization */
    {
        return 3;                                                        /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                   /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                 /* chip is busy */

        return 1;                                                        /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, len);        /* read the ram */
    if (res != 0)                                                        /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");              /* read ram failed */

        return 1;                                                        /* return error */
    }

    return 0;                                                            /* success return 0 */
}

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
uint8_t vs1053b_set_ram_address(vs1053b_handle_t *handle, uint16_t addr)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }

    buf[0] = (addr >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (addr >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_hdata(vs1053b_handle_t *handle, uint16_t *dat0, uint16_t *dat1)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);        /* read the hdat0 */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read hdat0 failed.\n");           /* read hdat0 failed */

        return 1;                                                       /* return error */
    }
    *dat0 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */
    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);        /* read the hdat1 */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read hdat1 failed.\n");           /* read hdat1 failed */

        return 1;                                                       /* return error */
    }
    *dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_get_hdata0(vs1053b_handle_t *handle, uint16_t *dat0)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);        /* read the hdat0 */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read hdat0 failed.\n");           /* read hdat0 failed */

        return 1;                                                       /* return error */
    }
    *dat0 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_get_hdata1(vs1053b_handle_t *handle, uint16_t *dat1)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);        /* read the hdat1 */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read hdat1 failed.\n");           /* read hdat1 failed */

        return 1;                                                       /* return error */
    }
    *dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_set_start_address(vs1053b_handle_t *handle, uint16_t addr)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    buf[0] = (addr >> 8) & 0xFF;                                        /* get msb */
    buf[1] = (addr >> 0) & 0xFF;                                        /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_AIADDR, buf, 2);      /* write aiaddr */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: write aiaddr failed.\n");         /* write aiaddr failed */

        return 1;                                                       /* return error */
    }

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_get_start_address(vs1053b_handle_t *handle, uint16_t *addr)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                 /* check handle */
    {
        return 2;                                                       /* return error */
    }
    if (handle->inited != 1)                                            /* check handle initialization */
    {
        return 3;                                                       /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                  /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                /* chip is busy */

        return 1;                                                       /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_AIADDR, buf, 2);       /* read the aiaddr */
    if (res != 0)                                                       /* check result */
    {
        handle->debug_print("vs1053b: read aiaddr failed.\n");          /* read aiaddr failed */

        return 1;                                                       /* return error */
    }
    *addr = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */

    return 0;                                                           /* success return 0 */
}

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
uint8_t vs1053b_set_vol(vs1053b_handle_t *handle, uint8_t left, uint8_t right)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                              /* check handle */
    {
        return 2;                                                    /* return error */
    }
    if (handle->inited != 1)                                         /* check handle initialization */
    {
        return 3;                                                    /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                               /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");             /* chip is busy */

        return 1;                                                    /* return error */
    }

    prev = (uint16_t)left << 8 | right;                              /* set vol */
    buf[0] = (prev >> 8) & 0xFF;                                     /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                     /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_VOL, buf, 2);      /* write vol */
    if (res != 0)                                                    /* check result */
    {
        handle->debug_print("vs1053b: write vol failed.\n");         /* write vol failed */

        return 1;                                                    /* return error */
    }

    return 0;                                                        /* success return 0 */
}

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
uint8_t vs1053b_get_vol(vs1053b_handle_t *handle, uint8_t *left, uint8_t *right)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                              /* check handle */
    {
        return 2;                                                    /* return error */
    }
    if (handle->inited != 1)                                         /* check handle initialization */
    {
        return 3;                                                    /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                               /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");             /* chip is busy */

        return 1;                                                    /* return error */
    }

    res = a_vs1053b_spi_read(handle, VS1053B_REG_VOL, buf, 2);       /* read the vol */
    if (res != 0)                                                    /* check result */
    {
        handle->debug_print("vs1053b: read vol failed.\n");          /* read vol failed */

        return 1;                                                    /* return error */
    }
    *left = buf[0];                                                  /* get the left */
    *right = buf[1];                                                 /* get the right */

    return 0;                                                        /* success return 0 */
}

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
uint8_t vs1053b_vol_convert_to_register(vs1053b_handle_t *handle, float db, uint8_t *reg)
{
    if (handle == NULL)                        /* check handle */
    {
        return 2;                              /* return error */
    }
    if (handle->inited != 1)                   /* check handle initialization */
    {
        return 3;                              /* return error */
    }

    *reg = (uint8_t)(fabsf(db) / 0.5f);        /* convert real data to register data */

    return 0;                                  /* success return 0 */
}

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
uint8_t vs1053b_vol_convert_to_data(vs1053b_handle_t *handle, uint8_t reg, float *db)
{
    if (handle == NULL)             /* check handle */
    {
        return 2;                   /* return error */
    }
    if (handle->inited != 1)        /* check handle initialization */
    {
        return 3;                   /* return error */
    }

    *db = (float)(reg * 0.5f);      /* convert raw data to real data */

    return 0;                       /* success return 0 */
}

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
uint8_t vs1053b_write_application(vs1053b_handle_t *handle, vs1053b_application_t num, uint8_t *buf, uint16_t len)
{
    uint8_t res;

    if (handle == NULL)                                                          /* check handle */
    {
        return 2;                                                                /* return error */
    }
    if (handle->inited != 1)                                                     /* check handle initialization */
    {
        return 3;                                                                /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                           /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                         /* chip is busy */

        return 1;                                                                /* return error */
    }

    if (num == VS1053B_APPLICATION_0)                                            /* app0 */
    {
        res = a_vs1053b_spi_write(handle, VS1053B_REG_AICTRL0, buf, len);        /* write the aictrl0 */
        if (res != 0)                                                            /* check result */
        {
            handle->debug_print("vs1053b: write aictrl0 failed.\n");             /* write aictrl0 failed */

            return 1;                                                            /* return error */
        }
    }
    else if (num == VS1053B_APPLICATION_1)                                       /* app1 */
    {
        res = a_vs1053b_spi_write(handle, VS1053B_REG_AICTRL1, buf, len);        /* write the aictrl1 */
        if (res != 0)                                                            /* check result */
        {
            handle->debug_print("vs1053b: write aictrl1 failed.\n");             /* write aictrl1 failed */

            return 1;                                                            /* return error */
        }
    }
    else if (num == VS1053B_APPLICATION_2)                                       /* app2 */
    {
        res = a_vs1053b_spi_write(handle, VS1053B_REG_AICTRL2, buf, len);        /* write the aictrl2 */
        if (res != 0)                                                            /* check result */
        {
            handle->debug_print("vs1053b: write aictrl2 failed.\n");             /* write aictrl2 failed */

            return 1;                                                            /* return error */
        }
    }
    else                                                                         /* app3 */
    {
        res = a_vs1053b_spi_write(handle, VS1053B_REG_AICTRL3, buf, len);        /* write the aictrl3 */
        if (res != 0)                                                            /* check result */
        {
            handle->debug_print("vs1053b: write aictrl3 failed.\n");             /* write aictrl3 failed */

            return 1;                                                            /* return error */
        }
    }

    return 0;                                                                    /* success return 0 */
}

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
uint8_t vs1053b_read_application(vs1053b_handle_t *handle, vs1053b_application_t num, uint8_t *buf, uint16_t len)
{
    uint8_t res;

    if (handle == NULL)                                                         /* check handle */
    {
        return 2;                                                               /* return error */
    }
    if (handle->inited != 1)                                                    /* check handle initialization */
    {
        return 3;                                                               /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                          /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                        /* chip is busy */

        return 1;                                                               /* return error */
    }

    if (num == VS1053B_APPLICATION_0)                                           /* app0 */
    {
        res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL0, buf, len);        /* read the aictrl0 */
        if (res != 0)                                                           /* check result */
        {
            handle->debug_print("vs1053b: read aictrl0 failed.\n");             /* read aictrl0 failed */

            return 1;                                                           /* return error */
        }
    }
    else if (num == VS1053B_APPLICATION_1)                                      /* app1 */
    {
        res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL1, buf, len);        /* read the aictrl1 */
        if (res != 0)                                                           /* check result */
        {
            handle->debug_print("vs1053b: read aictrl1 failed.\n");             /* read aictrl1 failed */

            return 1;                                                           /* return error */
        }
    }
    else if (num == VS1053B_APPLICATION_2)                                      /* app2 */
    {
        res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL2, buf, len);        /* read the aictrl2 */
        if (res != 0)                                                           /* check result */
        {
            handle->debug_print("vs1053b: write aictrl2 failed.\n");            /* read aictrl2 failed */

            return 1;                                                           /* return error */
        }
    }
    else                                                                        /* app3 */
    {
        res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, len);        /* read the aictrl3 */
        if (res != 0)                                                           /* check result */
        {
            handle->debug_print("vs1053b: write aictrl3 failed.\n");            /* read aictrl3 failed */

            return 1;                                                           /* return error */
        }
    }

    return 0;                                                                   /* success return 0 */
}

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
uint8_t vs1053b_set_play_speed(vs1053b_handle_t *handle, vs1053b_play_speed_t speed)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0x1E04;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = speed;                                                         /* set play speed */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_play_speed(vs1053b_handle_t *handle, vs1053b_play_speed_t *speed)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0x1E04;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                            /* combine the config */
    *speed = (vs1053b_play_speed_t)(prev & 0x03);                         /* get speed */

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_byte_rate(vs1053b_handle_t *handle, uint16_t *rate)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0x1E05;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    *rate = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_end_fill_byte(vs1053b_handle_t *handle, uint16_t *byte)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0x1E06;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    *byte = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */

    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_iis_mclk(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t prev2;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev2 = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev2 &= ~(1 << 3);                                                   /* clear settings */
    prev2 |= enable << 3;                                                 /* set bool */
    buf[0] = (prev2 >> 8) & 0xFF;                                         /* get msb */
    buf[1] = (prev2 >> 0) & 0xFF;                                         /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_iis_mclk(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                            /* combine data */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    *enable = (vs1053b_bool_t)((prev >> 3) & 0x01);                       /* get bool */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_iis(vs1053b_handle_t *handle, vs1053b_bool_t enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t prev2;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev2 = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev2 &= ~(1 << 2);                                                   /* clear settings */
    prev2 |= enable << 2;                                                 /* set bool */
    buf[0] = (prev2 >> 8) & 0xFF;                                         /* get msb */
    buf[1] = (prev2 >> 0) & 0xFF;                                         /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_iis(vs1053b_handle_t *handle, vs1053b_bool_t *enable)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                            /* combine data */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    *enable = (vs1053b_bool_t)((prev >> 2) & 0x01);                       /* get bool */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_iis_rate(vs1053b_handle_t *handle, vs1053b_iis_rate_t iis_rate)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t prev2;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev2 = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev2 &= ~(3 << 0);                                                   /* clear settings */
    prev2 |= iis_rate << 0;                                               /* set iis rate */
    buf[0] = (prev2 >> 8) & 0xFF;                                         /* get msb */
    buf[1] = (prev2 >> 0) & 0xFF;                                         /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_iis_rate(vs1053b_handle_t *handle, vs1053b_iis_rate_t *iis_rate)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC040;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                            /* combine data */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    *iis_rate= (vs1053b_iis_rate_t)((prev >> 0) & 0x03);                  /* get iis rate */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_gpio_direction(vs1053b_handle_t *handle, uint16_t mask)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t prev2;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC017;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev2 = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC017;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev2 &= ~(0x3FF);                                                    /* clear settings */
    prev2 |= mask;                                                        /* set mask */
    buf[0] = (prev2 >> 8) & 0xFF;                                         /* get msb */
    buf[1] = (prev2 >> 0) & 0xFF;                                         /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_gpio_direction(vs1053b_handle_t *handle, uint16_t *mask)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC017;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    *mask = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_gpio_input(vs1053b_handle_t *handle, uint16_t *data)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC018;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    *data = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_gpio_output(vs1053b_handle_t *handle, uint16_t data)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t prev2;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC019;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    prev2 = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC019;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }
    
    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev2 &= ~(0x1FF);                                                    /* clear settings */
    prev2 |= data;                                                        /* set data */
    buf[0] = (prev2 >> 8) & 0xFF;                                         /* get msb */
    buf[1] = (prev2 >> 0) & 0xFF;                                         /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAM, buf, 2);          /* write the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram failed.\n");              /* write ram failed */

        return 1;                                                         /* return error */
    }
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_get_gpio_output(vs1053b_handle_t *handle, uint16_t *data)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                   /* check handle */
    {
        return 2;                                                         /* return error */
    }
    if (handle->inited != 1)                                              /* check handle initialization */
    {
        return 3;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    prev = 0xC019;                                                        /* set addr */
    buf[0] = (prev >> 8) & 0xFF;                                          /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                          /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_WRAMADDR, buf, 2);      /* write the ram addr */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: write ram addr failed.\n");         /* write ram addr failed */

        return 1;                                                         /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                    /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                  /* chip is busy */

        return 1;                                                         /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_WRAM, buf, 2);           /* read the ram */
    if (res != 0)                                                         /* check result */
    {
        handle->debug_print("vs1053b: read ram failed.\n");               /* read ram failed */

        return 1;                                                         /* return error */
    }
    *data = ((uint16_t)(buf[0]) << 8) | buf[1];                           /* combine data */
    
    return 0;                                                             /* success return 0 */
}

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
uint8_t vs1053b_set_record_format(vs1053b_handle_t *handle, vs1053b_record_format_t format)
{
    if (handle == NULL)                             /* check handle */
    {
        return 2;                                   /* return error */
    }
    if (handle->inited != 1)                        /* check handle initialization */
    {
        return 3;                                   /* return error */
    }

    handle->record_type = (uint8_t)(format);        /* set record format */

    return 0;                                       /* success return 0 */
}

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
uint8_t vs1053b_get_record_format(vs1053b_handle_t *handle, vs1053b_record_format_t *format)
{
    if (handle == NULL)                                              /* check handle */
    {
        return 2;                                                    /* return error */
    }
    if (handle->inited != 1)                                         /* check handle initialization */
    {
        return 3;                                                    /* return error */
    }

    *format = (vs1053b_record_format_t)(handle->record_type);        /* get record format */

    return 0;                                                        /* success return 0 */
}

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
uint8_t vs1053b_init(vs1053b_handle_t *handle)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;
    uint16_t timeout;

    if (handle == NULL)                                                             /* check handle */
    {
        return 2;                                                                   /* return error */
    }
    if (handle->debug_print == NULL)                                                /* check debug_print */
    {
        return 3;                                                                   /* return error */
    }
    if (handle->spi_cmd_init == NULL)                                               /* check spi_cmd_init */
    {
        handle->debug_print("vs1053b: spi_cmd_init is null.\n");                    /* spi_cmd_init is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_cmd_deinit == NULL)                                             /* check spi_cmd_deinit */
    {
        handle->debug_print("vs1053b: spi_cmd_deinit is null.\n");                  /* spi_cmd_deinit is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_cmd_write_address16 == NULL)                                    /* check spi_cmd_write_address16 */
    {
        handle->debug_print("vs1053b: spi_cmd_write_address16 is null.\n");         /* spi_cmd_write_address16 is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_cmd_read_address16 == NULL)                                     /* check spi_cmd_read_address16 */
    {
        handle->debug_print("vs1053b: spi_cmd_read_address16 is null.\n");          /* spi_cmd_read_address16 is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_dat_init == NULL)                                               /* check spi_dat_init */
    {
        handle->debug_print("vs1053b: spi_dat_init is null.\n");                    /* spi_dat_init is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_dat_deinit == NULL)                                             /* check spi_dat_deinit */
    {
        handle->debug_print("vs1053b: spi_dat_deinit is null.\n");                  /* spi_dat_deinit is null */

        return 3;                                                                   /* return error */
    }
    if (handle->spi_dat_write_cmd == NULL)                                          /* check spi_dat_write_cmd */
    {
        handle->debug_print("vs1053b: spi_dat_write_cmd is null.\n");               /* spi_dat_write_cmd is null */

        return 3;                                                                   /* return error */
    }
    if (handle->reset_gpio_init == NULL)                                            /* check reset_gpio_init */
    {
        handle->debug_print("vs1053b: reset_gpio_init is null.\n");                 /* reset_gpio_init is null */

        return 3;                                                                   /* return error */
    }
    if (handle->reset_gpio_deinit == NULL)                                          /* check reset_gpio_deinit */
    {
        handle->debug_print("vs1053b: reset_gpio_deinit is null.\n");               /* reset_gpio_deinit is null */

        return 3;                                                                   /* return error */
    }
    if (handle->reset_gpio_write == NULL)                                           /* check reset_gpio_write */
    {
        handle->debug_print("vs1053b: reset_gpio_write is null.\n");                /* reset_gpio_write is null */

        return 3;                                                                   /* return error */
    }
    if (handle->dreq_gpio_init == NULL)                                             /* check dreq_gpio_init */
    {
        handle->debug_print("vs1053b: dreq_gpio_init is null.\n");                  /* dreq_gpio_init is null */

        return 3;                                                                   /* return error */
    }
    if (handle->dreq_gpio_deinit == NULL)                                           /* check dreq_gpio_deinit */
    {
        handle->debug_print("vs1053b: dreq_gpio_deinit is null.\n");                /* dreq_gpio_deinit is null */

        return 3;                                                                   /* return error */
    }
    if (handle->dreq_gpio_read == NULL)                                             /* check dreq_gpio_read */
    {
        handle->debug_print("vs1053b: dreq_gpio_read is null.\n");                  /* dreq_gpio_read is null */

        return 3;                                                                   /* return error */
    }
    if (handle->audio_init == NULL)                                                 /* check audio_init */
    {
        handle->debug_print("vs1053b: audio_init is null.\n");                      /* audio_init is null */

        return 3;                                                                   /* return error */
    }
    if (handle->audio_deinit == NULL)                                               /* check audio_deinit */
    {
        handle->debug_print("vs1053b: audio_deinit is null.\n");                    /* audio_deinit is null */

        return 3;                                                                   /* return error */
    }
    if (handle->audio_read == NULL)                                                 /* check audio_read */
    {
        handle->debug_print("vs1053b: audio_read is null.\n");                      /* audio_read is null */

        return 3;                                                                   /* return error */
    }
    if (handle->audio_write == NULL)                                                /* check audio_write */
    {
        handle->debug_print("vs1053b: audio_write is null.\n");                     /* audio_write is null */

        return 3;                                                                   /* return error */
    }
    if (handle->timestamp_read == NULL)                                             /* check timestamp_read */
    {
        handle->debug_print("vs1053b: timestamp_read is null.\n");                  /* timestamp_read is null */

        return 3;                                                                   /* return error */
    }
    if (handle->delay_ms == NULL)                                                   /* check delay_ms */
    {
        handle->debug_print("vs1053b: delay_ms is null.\n");                        /* delay_ms is null */

        return 3;                                                                   /* return error */
    }
    if (handle->receive_callback == NULL)                                           /* check receive_callback */
    {
        handle->debug_print("vs1053b: receive_callback is null.\n");                /* receive_callback is null */

        return 3;                                                                   /* return error */
    }

    if (handle->reset_gpio_init() != 0)                                             /* reset gpio init */
    {
        handle->debug_print("vs1053b: reset gpio init failed.\n");                  /* reset gpio init failed */

        return 4;                                                                   /* return error */
    }
    if (handle->dreq_gpio_init() != 0)                                              /* dreq gpio init */
    {
        handle->debug_print("vs1053b: dreq gpio init failed.\n");                   /* dreq gpio init failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */

        return 4;                                                                   /* return error */
    }
    if (handle->spi_cmd_init() != 0)                                                /* spi cmd init */
    {
        handle->debug_print("vs1053b: spi cmd init failed.\n");                     /* spi cmd init failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */

        return 1;                                                                   /* return error */
    }
    if (handle->spi_dat_init() != 0)                                                /* spi dat init failed */
    {
        handle->debug_print("vs1053b: spi dat init failed.\n");                     /* spi dat init failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */

        return 1;                                                                   /* return error */
    }

    res = handle->reset_gpio_write(0);                                              /* set low */
    if (res != 0)                                                                   /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");                 /* reset gpio write failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }
    handle->delay_ms(20);                                                           /* delay 20ms */
    res = handle->reset_gpio_write(1);                                              /* set high */
    if (res != 0)                                                                   /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");                 /* reset gpio write failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                              /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                            /* chip is busy */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }
    res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);                     /* read the mode */
    if (res != 0)                                                                   /* check result */
    {
        handle->debug_print("vs1053b: read mode failed.\n");                        /* read mode failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }
    prev = ((uint16_t)(buf[0]) << 8) | buf[1];                                      /* combine the config */
    prev &= ~(1 << 2);                                                              /* clear the settings */
    prev |= 1 << 2;                                                                 /* set the config */
    buf[0] = (prev >> 8) & 0xFF;                                                    /* get msb */
    buf[1] = (prev >> 0) & 0xFF;                                                    /* get lsb */
    res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);                    /* write the mode */
    if (res != 0)                                                                   /* check result */
    {
        handle->debug_print("vs1053b: write mode failed.\n");                       /* write mode failed */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }

    if (a_check_busy_pin(handle) != 0)                                              /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                            /* chip is busy */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }
    timeout = 1000;                                                                 /* timeout 1000ms */
    while (timeout != 0)                                                            /* check timeout */
    {
        res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);                 /* read the mode */
        if (res != 0)                                                               /* check result */
        {
            handle->debug_print("vs1053b: read mode failed.\n");                    /* read mode failed */
            (void)handle->reset_gpio_deinit();                                      /* reset gpio deinit */
            (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
            (void)handle->spi_cmd_deinit();                                         /* spi cmd deinit */
            (void)handle->spi_dat_deinit();                                         /* spi dat deinit */

            return 5;                                                               /* return error */
        }
        prev = ((uint16_t)(buf[0]) << 8) | buf[1];                                  /* combine the config */
        if (((prev >> 2) & 0x01) == 0)                                              /* check flag */
        {
            break;                                                                  /* break */
        }
        timeout--;                                                                  /* timeout */
        handle->delay_ms(1);                                                        /* delay 1ms */
    }
    if (timeout == 0)                                                               /* check timeout */
    {
        handle->debug_print("vs1053b: reset failed.\n");                            /* chip is busy */
        (void)handle->reset_gpio_deinit();                                          /* reset gpio deinit */
        (void)handle->dreq_gpio_deinit();                                           /* dreq gpio deinit */
        (void)handle->spi_cmd_deinit();                                             /* spi cmd deinit */
        (void)handle->spi_dat_deinit();                                             /* spi dat deinit */

        return 5;                                                                   /* return error */
    }
    handle->period = 0;                                                             /* init 0 */
    handle->period_enable = 0;                                                      /* init 0 */
    handle->timestamp = 0;                                                          /* init 0 */
    handle->status = VS1053B_STATUS_STOP;                                           /* no working */
    handle->pause = 0;                                                              /* no pause */
    handle->cur_pos = 0;                                                            /* current position */
    handle->buf_pos = 0;                                                            /* buffer position */
    handle->size = 0;                                                               /* total size */
    handle->record_type = 0;                                                        /* init record type */
    handle->plugin_patch_type = 0;                                                  /* plugin patch type */
    handle->inited = 1;                                                             /* flag finish initialization */

    return 0;                                                                       /* success return 0 */
}

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
uint8_t vs1053b_deinit(vs1053b_handle_t *handle)
{
    uint8_t res;

    if (handle == NULL)                                                    /* check handle */
    {
        return 2;                                                          /* return error */
    }
    if (handle->inited != 1)                                               /* check handle initialization */
    {
        return 3;                                                          /* return error */
    }

    res = handle->reset_gpio_write(0);                                     /* set low */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");        /* reset gpio write failed */

        return 4;                                                          /* return error */
    }
    handle->delay_ms(20);                                                  /* delay 20ms */
    res = handle->reset_gpio_write(1);                                     /* set high */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");        /* reset gpio write failed */

        return 4;                                                          /* return error */
    }

    res = handle->spi_cmd_deinit();                                        /* spi cmd deinit */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: spi cmd deinit failed.\n");          /* spi cmd deinit failed */

        return 1;                                                          /* return error */
    }
    res = handle->spi_dat_deinit();                                        /* spi dat deinit */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: spi dat deinit failed.\n");          /* spi dat deinit failed */

        return 1;                                                          /* return error */
    }
    res = handle->dreq_gpio_deinit();                                      /* dreq gpio deinit */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: dreq gpio deinit failed.\n");        /* dreq gpio deinit failed */

        return 1;                                                          /* return error */
    }
    res = handle->reset_gpio_deinit();                                     /* reset gpio deinit */
    if (res != 0)                                                          /* check result */
    {
        handle->debug_print("vs1053b: reset gpio deinit failed.\n");       /* reset gpio deinit failed */

        return 1;                                                          /* return error */
    }
    handle->inited = 0;                                                    /* flag close */

    return 0;                                                              /* success return 0 */
}

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
uint8_t vs1053b_process(vs1053b_handle_t *handle)
{
    uint8_t res;
    uint8_t buf[2];

    if (handle == NULL)                                                            /* check handle */
    {
        return 2;                                                                  /* return error */
    }
    if (handle->inited != 1)                                                       /* check handle initialization */
    {
        return 3;                                                                  /* return error */
    }

    if (handle->status == VS1053B_STATUS_STOP)                                     /* check status */
    {
        return 4;                                                                  /* not working */
    }
    else if (handle->status == VS1053B_STATUS_PLAY)                                /* play */
    {
        a_period(handle);                                                          /* run period callback */
        if ((handle->pause != 0) || (handle->status == VS1053B_STATUS_STOP))       /* if pause and return */
        {
            return 0;                                                              /* success return 0 */
        }
        if (a_check_busy_pin(handle) == 0)                                         /* if not busy */
        {
            if (handle->cur_pos >= handle->buf_pos)                                /* check buffer */
            {
                res = handle->audio_read(handle->cur_pos,
                                         VS1053B_BUFFER_SIZE, handle->buf);        /* read buffer */
                if (res != 0)                                                      /* check result */
                {
                    handle->debug_print("vs1053b: audio read failed.\n");          /* audio read failed */

                    return 1;                                                      /* return error */
                }
                handle->buf_pos += VS1053B_BUFFER_SIZE;                            /* add pos */
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_PLAY_READ,
                                             handle->cur_pos);                     /* run callback */
                }
            }
            if (handle->spi_dat_write_cmd(handle->buf +
                                         (handle->cur_pos %
                                          VS1053B_BUFFER_SIZE), 32) != 0)          /* push data */
            {
                handle->debug_print("vs1053b: fill buffer failed.\n");             /* fill buffer failed */

                return 1;                                                          /* return error */
            }
            handle->cur_pos += 32;                                                 /* current position +32 */
            if (handle->receive_callback != NULL)                                  /* check not null */
            {
                handle->receive_callback(VS1053B_TYPE_PLAY_WRITE,
                                         handle->cur_pos);                         /* run callback */
            }
            if (handle->cur_pos >= handle->size)                                   /* check end */
            {
                if (a_vs1053b_stop(handle) != 0)                                   /* stop audio */
                {
                    return 1;                                                      /* return error */
                }
                if (handle->audio_deinit() != 0)                                   /* audio deinit */
                {
                    handle->debug_print("vs1053b: audio deinit failed.\n");        /* audio deinit failed */

                    return 1;                                                      /* return error */
                }
                handle->status = VS1053B_STATUS_STOP;                              /* set not working */
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_PLAY_END,
                                             handle->cur_pos);                     /* run callback */
                }
            }
        }

        return 0;                                                                  /* success return 0 */
    }
    else if (handle->status == VS1053B_STATUS_RECORD)                              /* record */
    {
        if (handle->record_type != 0)                                              /* ogg */
        {
            uint8_t b[2];
            uint16_t i;
            uint16_t j;
            uint16_t l;
            uint16_t dat1;
            
            a_period(handle);                                                      /* run period callback */
            if ((handle->pause != 0) || (handle->status == VS1053B_STATUS_STOP))   /* if pause and return */
            {
                return 0;                                                          /* success return 0 */
            }

            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }
            res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);           /* read the hdat1 */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read hdat1 failed.\n");              /* read hdat1 failed */

                return 1;                                                          /* return error */
            }
            dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                             /* combine the config */
            while (dat1 >= 256)                                                    /* check length */
            {
                l = MIN(dat1, 256);                                                /* get min */
                dat1 -= l;                                                         /* dat1 - length */
                i = 0;                                                             /* init 0 */
                for (j = 0; j < l; j++)                                            /* loop all */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);   /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    handle->buf[i++] = buf[0];                                     /* save low part */
                    handle->buf[i++] = buf[1];                                     /* save high part */
                }
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_READ,
                                             handle->cur_pos);                     /* run callback */
                }
                res = handle->audio_write(handle->cur_pos, l * 2, handle->buf);    /* write buffer */
                if (res != 0)                                                      /* check result */
                {
                    handle->debug_print("vs1053b: audio write failed.\n");         /* audio write failed */

                    return 1;                                                      /* return error */
                }
                handle->cur_pos += l * 2;                                          /* add bytes */
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_WRITE,
                                             handle->cur_pos);                     /* run callback */
                }
                if (l < 256)                                                       /* check 256 */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, b, 2);     /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, 2); /* read the aictrl3 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat1 failed.\n");      /* read hdat1 failed */

                        return 1;                                                  /* return error */
                    }
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, 2); /* read the aictrl3 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat1 failed.\n");      /* read hdat1 failed */

                        return 1;                                                  /* return error */
                    }
                    dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                     /* combine the config */
                    if (!(dat1 & (1 << 2)))
                    {
                        res = handle->audio_write(handle->cur_pos, 2, b);          /* write buffer */
                        if (res != 0)                                              /* check result */
                        {
                            handle->debug_print("vs1053b: audio write failed.\n"); /* audio write failed */

                            return 1;                                              /* return error */
                        }
                        handle->cur_pos += 2;                                      /* add bytes */
                    }
                    else
                    {
                        res = handle->audio_write(handle->cur_pos, 1, b);          /* write buffer */
                        if (res != 0)                                              /* check result */
                        {
                            handle->debug_print("vs1053b: audio write failed.\n"); /* audio write failed */

                            return 1;                                              /* return error */
                        }
                        handle->cur_pos += 1;                                      /* add bytes */
                    }
                }
            }
            
            return 0;                                                              /* success return 0 */
        }
        else                                                                       /* wav */
        {
            uint16_t i;
            uint16_t dat1;

            a_period(handle);                                                      /* run period callback */
            if ((handle->pause != 0) || (handle->status == VS1053B_STATUS_STOP))   /* if pause and return */
            {
                return 0;                                                          /* success return 0 */
            }

            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }
            res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);           /* read the hdat1 */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read hdat1 failed.\n");              /* read hdat1 failed */

                return 1;                                                          /* return error */
            }
            dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                             /* combine the config */
            if ((dat1 >= 256) && (dat1 < 896))                                     /* check range */
            {
                i = 0;                                                             /* init 0 */
                while (i < 512)                                                    /* 512 bytes */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);   /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    handle->buf[i++] = buf[1];                                     /* save low part */
                    handle->buf[i++] = buf[0];                                     /* save high part */
                }
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_READ,
                                             handle->cur_pos);                     /* run callback */
                }
                res = handle->audio_write(handle->cur_pos, 512, handle->buf);      /* write buffer */
                if (res != 0)                                                      /* check result */
                {
                    handle->debug_print("vs1053b: audio write failed.\n");         /* audio write failed */

                    return 1;                                                      /* return error */
                }
                handle->cur_pos += 512;                                            /* add 512 bytes */
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_WRITE,
                                             handle->cur_pos);                     /* run callback */
                }
            }
            else if (dat1 >= 896)
            {
                i = 0;                                                             /* init 0 */
                while (i < 512)                                                    /* 512 bytes */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);   /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    handle->buf[i++] = buf[1];                                     /* save low part */
                    handle->buf[i++] = buf[0];                                     /* save high part */
                }
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_READ,
                                             handle->cur_pos);                     /* run callback */
                }
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_OVER,
                                             handle->cur_pos);                     /* run callback */
                }
                handle->debug_print("vs1053b: buffer is over.\n");                 /* buffer is over */
            }
            else
            {
                                                                                   /* do nothing */
            }

            return 0;                                                              /* success return 0 */
        }
    }
    else
    {
        handle->debug_print("vs1053b: status is invalid.\n");                      /* status is invalid */

        return 5;                                                                  /* return error */
    }
}

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
uint8_t vs1053b_pause(vs1053b_handle_t *handle)
{
    if (handle == NULL)                                          /* check handle */
    {
        return 2;                                                /* return error */
    }
    if (handle->inited != 1)                                     /* check handle initialization */
    {
        return 3;                                                /* return error */
    }
    if (handle->status != 0)                                     /* check played */
    {
        handle->debug_print("vs1053b: audio working.\n");        /* audio working */

        return 4;                                                /* return error */
    }

    handle->pause = 1;                                           /* flag paused */

    return 0;                                                    /* success return 0 */
}

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
uint8_t vs1053b_play(vs1053b_handle_t *handle, char *path)
{
    uint8_t res;
    uint32_t sec;
    uint32_t us;

    if (handle == NULL)                                                /* check handle */
    {
        return 2;                                                      /* return error */
    }
    if (handle->inited != 1)                                           /* check handle initialization */
    {
        return 3;                                                      /* return error */
    }
    if (handle->status != 0)                                           /* check played */
    {
        handle->debug_print("vs1053b: audio working.\n");              /* audio working */

        return 4;                                                      /* return error */
    }

    if (handle->pause != 0)                                            /* if pause and return */
    {
        handle->pause = 0;                                             /* recover */

        return 0;                                                      /* success return 0 */
    }

    res = a_vs1053b_stop(handle);                                      /* stop playing */
    if (res != 0)                                                      /* check result */
    {
        return 1;                                                      /* return error */
    }
    res = handle->audio_init(0, path, &handle->size);                  /* audio init */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: audio init failed.\n");          /* audio init failed */

        return 1;                                                      /* return error */
    }
    handle->timestamp_read(&sec, &us);                                 /* read timestamp */
    handle->timestamp = (((uint64_t)sec) * 1000000 + ((uint64_t)us));  /* set timestamp */
    handle->cur_pos = 0;                                               /* current position */
    handle->buf_pos = 0;                                               /* buffer position */
    handle->status = VS1053B_STATUS_PLAY;                              /* active play */

    return 0;                                                          /* success return 0 */
}

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
uint8_t vs1053b_record(vs1053b_handle_t *handle, char *path, uint32_t sample_rate)
{
    uint8_t res;
    uint8_t buf[2];
    uint32_t sec;
    uint32_t us;

    if (handle == NULL)                                                /* check handle */
    {
        return 2;                                                      /* return error */
    }
    if (handle->inited != 1)                                           /* check handle initialization */
    {
        return 3;                                                      /* return error */
    }
    if (handle->status != 0)                                           /* check played */
    {
        handle->debug_print("vs1053b: audio working.\n");              /* audio working */

        return 4;                                                      /* return error */
    }

    if (handle->pause != 0)                                            /* if pause and return */
    {
        handle->pause = 0;                                             /* recover */

        return 0;                                                      /* success return 0 */
    }

    res = handle->audio_init(1, path, &handle->size);                  /* audio init */
    if (res != 0)                                                      /* check result */
    {
        handle->debug_print("vs1053b: audio init failed.\n");          /* audio init failed */

        return 1;                                                      /* return error */
    }
    if (handle->record_type != 0)                                      /* ogg */
    {
        if ((handle->plugin_patch_type >= 0x02) && 
            (handle->plugin_patch_type <= 0x0C))                       /* 8000hz */
        {
            if (sample_rate != 8000)                                   /* check sample rate */
            {
                handle->debug_print("vs1053b: sample rate "
                                    "doesn't match path.\n");          /* sample rate doesn't match patch */

                return 5;                                              /* return error */
            }
        }
        else if ((handle->plugin_patch_type >= 0x0D) && 
                 (handle->plugin_patch_type <= 0x22))                  /* 16000hz */
        {
            if (sample_rate != 16000)                                  /* check sample rate */
            {
                handle->debug_print("vs1053b: sample rate "
                                    "doesn't match path.\n");          /* sample rate doesn't match patch */

                return 5;                                              /* return error */
            }
        }
        else if ((handle->plugin_patch_type >= 0x23) && 
                 (handle->plugin_patch_type <= 0x2E))                  /* 44100hz */
        {
            if (sample_rate != 44100)                                  /* check sample rate */
            {
                handle->debug_print("vs1053b: sample rate "
                                    "doesn't match path.\n");          /* sample rate doesn't match patch */

                return 5;                                              /* return error */
            }
        }
        else
        {
            handle->debug_print("vs1053b: sample rate "
                                "doesn't match path.\n");              /* sample rate doesn't match patch */

            return 5;                                                  /* return error */
        }

        if (a_check_busy_pin(handle) != 0)                             /* check busy */
        {
            handle->debug_print("vs1053b: chip is busy.\n");           /* chip is busy */

            return 1;                                                  /* return error */
        }
        buf[0] = 0x00;                                                 /* set msb */
        buf[1] = 0x34;                                                 /* set lsb */
        res = a_vs1053b_spi_write(handle, VS1053B_REG_AIADDR, buf, 2); /* write aiaddr */
        if (res != 0)                                                  /* check result */
        {
            handle->debug_print("vs1053b: write aiaddr failed.\n");    /* write aiaddr failed */

            return 1;                                                  /* return error */
        }
    }
    else                                                               /* wav */
    {
        handle->wav.chunk_id[0] = 'R';                                 /* R */
        handle->wav.chunk_id[1] = 'I';                                 /* I */
        handle->wav.chunk_id[2] = 'F';                                 /* F */
        handle->wav.chunk_id[3] = 'F';                                 /* F */
        handle->wav.chunk_size = 0x00000000;                           /* init 0 */
        handle->wav.format[0] = 'W';                                   /* W */
        handle->wav.format[1] = 'A';                                   /* A */
        handle->wav.format[2] = 'V';                                   /* V */
        handle->wav.format[3] = 'E';                                   /* E */
        handle->wav.sub_chunk1_id[0] = 'f';                            /* f */
        handle->wav.sub_chunk1_id[1] = 'm';                            /* m */
        handle->wav.sub_chunk1_id[2] = 't';                            /* t */
        handle->wav.sub_chunk1_id[3] = 0x20;                           /* 0x20 */
        handle->wav.sub_chunk1_size = 16;                              /* 16 bytes */
        handle->wav.audio_format = 0x01;                               /* pcm */
        handle->wav.num_channel = 1;                                   /* 1 channel */
        handle->wav.sample_rate = sample_rate;                         /* set sample rate */
        handle->wav.byte_rate = handle->wav.sample_rate * 2;           /* double */
        handle->wav.block_align = 2;                                   /* 2 bytes */
        handle->wav.bit_per_sample = 16;                               /* 16 bits */
        handle->wav.sub_chunk2_id[0] = 'd';                            /* d */
        handle->wav.sub_chunk2_id[1] = 'a';                            /* a */
        handle->wav.sub_chunk2_id[2] = 't';                            /* t */
        handle->wav.sub_chunk2_id[3] = 'a';                            /* a */
        handle->wav.sub_chunk2_size = 0x00000000;                      /* init 0 */
        if (a_vs1053b_write_wav_header(handle, &handle->wav) != 0)     /* write wav header */
        {
            return 1;                                                  /* return error */
        }
    }
    handle->timestamp_read(&sec, &us);                                 /* read timestamp */
    handle->timestamp = (((uint64_t)sec) * 1000000 + ((uint64_t)us));  /* set timestamp */
    handle->cur_pos = 44;                                              /* current position */
    handle->buf_pos = 0;                                               /* buffer position */
    handle->status = VS1053B_STATUS_RECORD;                            /* active record */

    return 0;                                                          /* success return 0 */
}

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
uint8_t vs1053b_stop(vs1053b_handle_t *handle)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t prev;

    if (handle == NULL)                                                            /* check handle */
    {
        return 2;                                                                  /* return error */
    }
    if (handle->inited != 1)                                                       /* check handle initialization */
    {
        return 3;                                                                  /* return error */
    }
    if (handle->status == 0)                                                       /* check played */
    {
        handle->debug_print("vs1053b: audio not working.\n");                      /* audio not working */

        return 4;                                                                  /* return error */
    }

    if (handle->status == 1)                                                       /* play */
    {
        if (a_vs1053b_stop(handle) != 0)                                           /* stop audio */
        {
            return 1;                                                              /* return error */
        }
        if (handle->audio_deinit() != 0)                                           /* audio deinit */
        {
            handle->debug_print("vs1053b: audio deinit failed.\n");                /* audio deinit failed */

            return 1;                                                              /* return error */
        }
        handle->status = VS1053B_STATUS_STOP;                                      /* set not working */
        if (handle->receive_callback != NULL)                                      /* check not null */
        {
            handle->receive_callback(VS1053B_TYPE_PLAY_END,
                                     handle->cur_pos);                             /* run callback */
        }

        return 0;                                                                  /* success return 0 */
    }
    else if (handle->status == 2)                                                  /* record */
    {
        if ((handle->pause != 0) || (handle->status == VS1053B_STATUS_STOP))       /* if pause and return */
        {
            return 0;                                                              /* success return 0 */
        }
        
        if (handle->record_type != 0)                                              /* ogg */
        {
            uint8_t b[2];
            uint16_t i;
            uint16_t j;
            uint16_t l;
            uint16_t ll;
            uint16_t dat1;
            
            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }
            buf[0] = 0x00;                                                         /* 0x00 */
            buf[1] = 0x01;                                                         /* 0x01 */
            res = a_vs1053b_spi_write(handle, VS1053B_REG_AICTRL3, buf, 2);        /* read the aictrl3 */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read hdat1 failed.\n");              /* read hdat1 failed */

                return 1;                                                          /* return error */
            }
            
            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }
            res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);           /* read the hdat1 */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read hdat1 failed.\n");              /* read hdat1 failed */

                return 1;                                                          /* return error */
            }
            dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                             /* combine the config */
            
            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }
            res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, 2);         /* read the aictrl3 */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read hdat1 failed.\n");              /* read hdat1 failed */

                return 1;                                                          /* return error */
            }
            ll = ((uint16_t)(buf[0]) << 8) | buf[1];                               /* combine the config */
            if ((ll & (1 << 1)) != 0)                                              /* check next state*/
            {
                if (a_check_busy_pin(handle) != 0)                                 /* check busy */
                {
                    handle->debug_print("vs1053b: chip is busy.\n");               /* chip is busy */

                    return 1;                                                      /* return error */
                }
                res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT1, buf, 2);       /* read the hdat1 */
                if (res != 0)                                                      /* check result */
                {
                    handle->debug_print("vs1053b: read hdat1 failed.\n");          /* read hdat1 failed */

                    return 1;                                                      /* return error */
                }
                dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                         /* combine the config */
            }
            
            while (dat1 >= 256)                                                    /* check length */
            {
                l = MIN(dat1, 256);                                                /* get min */
                dat1 -= l;                                                         /* dat1 - length */
                if (((ll & (1 << 1)) != 0) && (!dat1))                             /* check data */
                {
                    l--;                                                           /* length-- */
                }
                i = 0;                                                             /* init 0 */
                for (j = 0; j < l; j++)                                            /* loop all */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, buf, 2);   /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    handle->buf[i++] = buf[0];                                     /* save low part */
                    handle->buf[i++] = buf[1];                                     /* save high part */
                }
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_READ,
                                             handle->cur_pos);                     /* run callback */
                }
                res = handle->audio_write(handle->cur_pos, l * 2, handle->buf);    /* write buffer */
                if (res != 0)                                                      /* check result */
                {
                    handle->debug_print("vs1053b: audio write failed.\n");         /* audio write failed */

                    return 1;                                                      /* return error */
                }
                handle->cur_pos += l * 2;                                          /* add bytes */
                if (handle->receive_callback != NULL)                              /* check not null */
                {
                    handle->receive_callback(VS1053B_TYPE_RECORD_WRITE,
                                             handle->cur_pos);                     /* run callback */
                }
                if (l < 256)                                                       /* check 256 */
                {
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_HDAT0, b, 2);     /* read the hdat0 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat0 failed.\n");      /* read hdat0 failed */

                        return 1;                                                  /* return error */
                    }
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, 2); /* read the aictrl3 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat1 failed.\n");      /* read hdat1 failed */

                        return 1;                                                  /* return error */
                    }
                    res = a_vs1053b_spi_read(handle, VS1053B_REG_AICTRL3, buf, 2); /* read the aictrl3 */
                    if (res != 0)                                                  /* check result */
                    {
                        handle->debug_print("vs1053b: read hdat1 failed.\n");      /* read hdat1 failed */

                        return 1;                                                  /* return error */
                    }
                    dat1 = ((uint16_t)(buf[0]) << 8) | buf[1];                     /* combine the config */
                    if (!(dat1 & (1 << 2)))
                    {
                        res = handle->audio_write(handle->cur_pos, 2, b);          /* write buffer */
                        if (res != 0)                                              /* check result */
                        {
                            handle->debug_print("vs1053b: audio write failed.\n"); /* audio write failed */

                            return 1;                                              /* return error */
                        }
                        handle->cur_pos += 2;                                      /* add bytes */
                    }
                    else
                    {
                        res = handle->audio_write(handle->cur_pos, 1, b);          /* write buffer */
                        if (res != 0)                                              /* check result */
                        {
                            handle->debug_print("vs1053b: audio write failed.\n"); /* audio write failed */

                            return 1;                                              /* return error */
                        }
                        handle->cur_pos += 1;                                      /* add bytes */
                    }
                }
            }
        }
        else                                                                       /* wav */
        {
            if (a_check_busy_pin(handle) != 0)                                     /* check busy */
            {
                handle->debug_print("vs1053b: chip is busy.\n");                   /* chip is busy */

                return 1;                                                          /* return error */
            }

            res = a_vs1053b_spi_read(handle, VS1053B_REG_MODE, buf, 2);            /* read the mode */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: read mode failed.\n");               /* read mode failed */

                return 1;                                                          /* return error */
            }
            prev = ((uint16_t)(buf[0]) << 8) | buf[1];                             /* combine the config */
            prev &= ~(1 << 12);                                                    /* clear the settings */
            prev |= 0 << 12;                                                       /* set the config */
            buf[0] = (prev >> 8) & 0xFF;                                           /* get msb */
            buf[1] = (prev >> 0) & 0xFF;                                           /* get lsb */
            res = a_vs1053b_spi_write(handle, VS1053B_REG_MODE, buf, 2);           /* write the mode */
            if (res != 0)                                                          /* check result */
            {
                handle->debug_print("vs1053b: write mode failed.\n");              /* write mode failed */

                return 1;                                                          /* return error */
            }
            handle->wav.chunk_size = handle->cur_pos - 44 + 36;                    /* set chunk size */
            handle->wav.sub_chunk2_size = handle->cur_pos - 44;                    /* set sub chunk2 size */
            if (a_vs1053b_write_wav_header(handle, &handle->wav) != 0)             /* write wav header */
            {
                return 1;                                                          /* return error */
            }
        }
        if (handle->audio_deinit() != 0)                                           /* audio deinit */
        {
            handle->debug_print("vs1053b: audio deinit failed.\n");                /* audio deinit failed */

            return 1;                                                              /* return error */
        }
        handle->status = VS1053B_STATUS_STOP;                                      /* set not working */
        if (handle->receive_callback != NULL)                                      /* check not null */
        {
            handle->receive_callback(VS1053B_TYPE_RECORD_END, handle->cur_pos);    /* run callback */
        }

        return 0;                                                                  /* success return 0 */
    }
    else
    {
        handle->debug_print("vs1053b: status is invalid.\n");                      /* status is invalid */

        return 5;                                                                  /* return error */
    }
}

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
uint8_t vs1053b_hard_reset(vs1053b_handle_t *handle)
{
    uint8_t res;

    if (handle == NULL)                                                     /* check handle */
    {
        return 2;                                                           /* return error */
    }
    if (handle->inited != 1)                                                /* check handle initialization */
    {
        return 3;                                                           /* return error */
    }

    res = handle->reset_gpio_write(0);                                      /* set low */
    if (res != 0)                                                           /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");         /* reset gpio write failed */

        return 5;                                                           /* return error */
    }
    handle->delay_ms(20);                                                   /* delay 20ms */
    res = handle->reset_gpio_write(1);                                      /* set high */
    if (res != 0)                                                           /* check result */
    {
        handle->debug_print("vs1053b: reset gpio write failed.\n");         /* reset gpio write failed */

        return 5;                                                           /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                                      /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");                    /* chip is busy */

        return 5;                                                           /* return error */
    }

    return 0;                                                               /* success return 0 */
}

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
uint8_t vs1053b_set_period_callback(vs1053b_handle_t *handle, uint32_t second, uint32_t microsecond, vs1053b_bool_t enable)
{
    if (handle == NULL)                                                           /* check handle */
    {
        return 2;                                                                 /* return error */
    }
    if (handle->inited != 1)                                                      /* check handle initialization */
    {
        return 3;                                                                 /* return error */
    }

    handle->period = (((uint64_t)second) * 1000000 + ((uint64_t)microsecond));    /* set period */
    handle->period_enable = enable;                                               /* set period enable */

    return 0;                                                                     /* success return 0 */
}

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
uint8_t vs1053b_get_period_callback(vs1053b_handle_t *handle, uint32_t *second, uint32_t *microsecond, vs1053b_bool_t *enable)
{
    if (handle == NULL)                                       /* check handle */
    {
        return 2;                                             /* return error */
    }
    if (handle->inited != 1)                                  /* check handle initialization */
    {
        return 3;                                             /* return error */
    }

    *second = (handle->period / 1000000) & 0xFFFFFFFF;        /* get second */
    *microsecond = (handle->period % 1000000) & 0xFFFFFFFF;   /* get microsecond */
    *enable = (vs1053b_bool_t)(handle->period_enable);        /* get period enable */

    return 0;                                                 /* success return 0 */
}

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
uint8_t vs1053b_parse_info(vs1053b_handle_t *handle, uint16_t dat0, uint16_t dat1, vs1053b_audio_info_t *info)
{
    const float bitrate[2][16]= {{0.0f, 8.0f, 16.0f, 24.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f,
                                  80.0f, 96.0f, 112.0f, 128.0f, 144.0f, 160.0f, 0.0f},
                                 {0.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 80.0f, 96.0f, 112.0f,
                                  128.0f, 160.0f, 192.0f, 224.0f, 256.0f, 320.0f, 0.0f}};

    if (handle == NULL)                                             /* check handle */
    {
        return 2;                                                   /* return error */
    }
    if (handle->inited != 1)                                        /* check handle initialization */
    {
        return 3;                                                   /* return error */
    }

    switch (dat1)
    {
        case VS1053B_FORMAT_WAV :                                   /* wav */
        {
            info->format = VS1053B_FORMAT_WAV;                      /* set wav format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "wav", 32);                  /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get wav kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_MIDI :                                  /* midi */
        {
            info->format = VS1053B_FORMAT_MIDI;                     /* set midi format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "midi", 32);                 /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get midi kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_AAC_ADTS :                              /* acc adts */
        {
            info->format = VS1053B_FORMAT_AAC_ADTS;                 /* set acc adts format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "aac_adts", 32);             /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get acc adts kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_AAC_ADIF :                              /* acc adif */
        {
            info->format = VS1053B_FORMAT_AAC_ADIF;                 /* set acc adif format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "aac_adif", 32);             /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get acc adif kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_AAC_MP4 :                               /* acc mp4 */
        {
            info->format = VS1053B_FORMAT_AAC_MP4;                  /* set acc mp4 format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "aac_mp4", 32);              /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get acc mp4 kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_OGG :                                   /* ogg */
        {
            info->format = VS1053B_FORMAT_OGG;                      /* set ogg format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "ogg", 32);                  /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get ogg kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_WMA :                                   /* wma */
        {
            info->format = VS1053B_FORMAT_WMA;                      /* set wma format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "wma", 32);                  /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get wma kbps */

            break;                                                  /* break */
        }
        case VS1053B_FORMAT_FLAC :                                  /* flac */
        {
            info->format = VS1053B_FORMAT_FLAC;                     /* set flac format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "flac", 32);                 /* copy name */
            info->kbps = (float)(dat0) * 8.0f / 1000.0f;            /* get flac kbps */

            break;                                                  /* break */
        }
        default :                                                   /* mp3 */
        {
            uint16_t tmp;

            info->format = VS1053B_FORMAT_MP3;                      /* set mp3 format */
            memset(info->format_name, 0, sizeof(char) * 32);        /* init buffer */
            strncpy(info->format_name, "mp3", 32);                  /* copy name */
            tmp = (dat1 >> 3) & 0x03;                               /* get index */
            if (tmp == 3)                                           /* index 1 */
            {
                info->kbps = bitrate[1][(dat0 >> 12) & 0xF];        /* get mp3 kbps */
            }
            else                                                    /* index 0 */
            {
                info->kbps = bitrate[0][(dat0 >> 12) & 0xF];        /* get mp3 kbps */
            }
        }

        break;                                                      /* break */
    }

    return 0;                                                       /* success return 0 */
}

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
uint8_t vs1053b_get_patch(vs1053b_handle_t *handle, vs1053b_patch_t type, const uint16_t **patch_addr, uint16_t *len)
{
    if (handle == NULL)                                            /* check handle */
    {
        return 2;                                                  /* return error */
    }
    if (handle->inited != 1)                                       /* check handle initialization */
    {
        return 3;                                                  /* return error */
    }

    if (type == VS1053B_PATCH_FLAC)                                /* flac */
    {
        *patch_addr = gsc_vs1053b_patch_flac_plugin;               /* set flac plugin address */
        *len = VS1053B_PATCH_FLAC_PLUGIN_SIZE;                     /* set flac plugin size */
    }
#if VS1053B_OGG_VENC08K1Q00 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q00)                /* ogg venc08k1q00 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q00_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q00_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q01 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q01)                /* ogg venc08k1q01 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q01_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q01_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q02 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q02)                /* ogg venc08k1q02 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q02_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q02_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q03 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q03)                /* ogg venc08k1q03 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q03_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q03_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q04 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q04)                /* ogg venc08k1q04 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q04_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q04_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q05 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q05)                /* ogg venc08k1q05 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q05_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q05_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q06 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q06)                /* ogg venc08k1q06 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q06_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q06_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q07 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q07)                /* ogg venc08k1q07 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q07_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q07_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q08 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q08)                /* ogg venc08k1q08 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q08_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q08_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q09 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q09)                /* ogg venc08k1q09 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q09_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q09_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC08K1Q10 != 0
    else if (type == VS1053B_PATCH_OGG_VENC08K1Q10)                /* ogg venc08k1q10 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc08k1q10_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC08K1Q10_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q00 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q00)                /* ogg venc16k1q00 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q00_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q00_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q01 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q01)                /* ogg venc16k1q01 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q01_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q01_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q02 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q02)                /* ogg venc16k1q02 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q02_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q02_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q03 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q03)                /* ogg venc16k1q03 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q03_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q03_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q04 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q04)                /* ogg venc16k1q04 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q04_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q04_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q05 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q05)                /* ogg venc16k1q05 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q05_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q05_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q06 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q06)                /* ogg venc16k1q06 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q06_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q06_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q07 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q07)                /* ogg venc16k1q07 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q07_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q07_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q08 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q08)                /* ogg venc16k1q08 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q08_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q08_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q09 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q09)                /* ogg venc16k1q09 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q09_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q09_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K1Q10 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K1Q10)                /* ogg venc16k1q10 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k1q10_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K1Q10_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q00 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q00)                /* ogg venc16k2q00 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q00_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q00_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q01 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q01)                /* ogg venc16k2q01 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q01_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q01_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q02 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q02)                /* ogg venc16k2q02 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q02_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q02_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q03 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q03)                /* ogg venc16k2q03 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q03_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q03_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q04 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q04)                /* ogg venc16k2q04 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q04_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q04_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q05 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q05)                /* ogg venc16k2q05 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q05_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q05_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q06 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q06)                /* ogg venc16k2q06 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q06_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q06_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q07 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q07)                /* ogg venc16k2q07 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q07_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q07_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q08 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q08)                /* ogg venc16k2q08 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q08_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q08_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q09 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q09)                /* ogg venc16k2q09 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q09_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q09_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC16K2Q10 != 0
    else if (type == VS1053B_PATCH_OGG_VENC16K2Q10)                /* ogg venc16k2q10 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc16k2q10_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC16K2Q10_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q00 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q00)                /* ogg venc44k1q00 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q00_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q00_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q01 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q01)                /* ogg venc44k1q01 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q01_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q01_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q02 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q02)                /* ogg venc44k1q02 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q02_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q02_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q03 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q03)                /* ogg venc44k1q03 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q03_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q03_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q04 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q04)                /* ogg venc44k1q04 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q04_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q04_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K1Q05 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K1Q05)                /* ogg venc44k1q05 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k1q05_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K1Q05_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q00 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q00)                /* ogg venc44k2q00 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q00_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q00_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q01 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q01)                /* ogg venc44k2q01 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q01_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q01_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q02 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q02)                /* ogg venc44k2q02 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q02_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q02_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q03 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q03)                /* ogg venc44k2q03 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q03_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q03_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q04 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q04)                /* ogg venc44k2q04 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q04_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q04_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
#if VS1053B_OGG_VENC44K2Q05 != 0
    else if (type == VS1053B_PATCH_OGG_VENC44K2Q05)                /* ogg venc44k2q05 */
    {
        *patch_addr = gsc_vs1053b_patch_ogg_venc44k2q05_plugin;    /* set plugin address */
        *len = VS1053B_PATCH_OGG_VENC44K2Q05_PLUGIN_SIZE;          /* set plugin size */
    }
#endif
    else                                                           /* wav */
    {
        *patch_addr = gsc_vs1053b_patch_wav_plugin;                /* set wav plugin address */
        *len = VS1053B_PATCH_WAV_PLUGIN_SIZE;                      /* set wav plugin size */
    }

    return 0;                                                      /* success return 0 */
}

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
uint8_t vs1053b_load_patch(vs1053b_handle_t *handle, const uint16_t *patch, uint16_t len)
{
    uint8_t res;
    uint8_t buf[2];
    uint16_t i;
    uint16_t addr;
    uint16_t n;
    uint16_t val;

    if (handle == NULL)                                                          /* check handle */
    {
        return 2;                                                                /* return error */
    }
    if (handle->inited != 1)                                                     /* check handle initialization */
    {
        return 3;                                                                /* return error */
    }

    if (patch == gsc_vs1053b_patch_flac_plugin)                                  /* flac */
    {
        handle->plugin_patch_type = VS1053B_PATCH_FLAC;                          /* save type */
    }
#if VS1053B_OGG_VENC08K1Q00 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q00_plugin)                  /* venc08k1q00 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q00;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q01 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q01_plugin)                  /* venc08k1q01 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q01;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q02 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q02_plugin)                  /* venc08k1q02 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q02;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q03 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q03_plugin)                  /* venc08k1q03 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q03;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q04 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q04_plugin)                  /* venc08k1q04 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q04;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q05 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q05_plugin)                  /* venc08k1q05 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q05;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q06 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q06_plugin)                  /* venc08k1q06 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q06;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q07 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q07_plugin)                  /* venc08k1q07 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q07;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q08 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q08_plugin)                  /* venc08k1q08 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q08;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q09 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q09_plugin)                  /* venc08k1q09 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q09;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC08K1Q10 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc08k1q10_plugin)                  /* venc08k1q10 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC08K1Q10;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q00 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q00_plugin)                  /* venc16k1q00 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q00;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q01 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q01_plugin)                  /* venc16k1q01 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q01;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q02 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q02_plugin)                  /* venc16k1q02 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q02;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q03 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q03_plugin)                  /* venc16k1q03 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q03;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q04 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q04_plugin)                  /* venc16k1q04 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q04;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q05 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q05_plugin)                  /* venc16k1q05 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q05;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q06 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q06_plugin)                  /* venc16k1q06 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q06;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q07 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q07_plugin)                  /* venc16k1q07 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q07;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q08 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q08_plugin)                  /* venc16k1q08 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q08;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q09 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q09_plugin)                  /* venc16k1q09 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q09;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K1Q10 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k1q10_plugin)                  /* venc16k1q10 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K1Q10;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q00 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q00_plugin)                  /* venc16k2q00 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q00;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q01 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q01_plugin)                  /* venc16k2q01 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q01;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q02 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q02_plugin)                  /* venc16k2q02 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q02;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q03 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q03_plugin)                  /* venc16k2q03 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q03;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q04 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q04_plugin)                  /* venc16k2q04 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q04;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q05 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q05_plugin)                  /* venc16k2q05 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q05;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q06 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q06_plugin)                  /* venc16k2q06 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q06;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q07 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q07_plugin)                  /* venc16k2q07 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q07;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q08 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q08_plugin)                  /* venc16k2q08 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q08;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q09 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q09_plugin)                  /* venc16k2q09 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q09;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC16K2Q10 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc16k2q10_plugin)                  /* venc16k2q10 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC16K2Q10;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q00 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q00_plugin)                  /* venc44k1q00 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q00;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q01 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q01_plugin)                  /* venc44k1q01 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q01;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q02 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q02_plugin)                  /* venc44k1q02 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q02;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q03 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q03_plugin)                  /* venc44k1q03 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q03;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q04 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q04_plugin)                  /* venc44k1q04 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q04;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K1Q05 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k1q05_plugin)                  /* venc44k1q05 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K1Q05;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q00 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q00_plugin)                  /* venc44k2q00 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q00;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q01 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q01_plugin)                  /* venc44k2q01 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q01;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q02 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q02_plugin)                  /* venc44k2q02 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q02;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q03 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q03_plugin)                  /* venc44k2q03 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q03;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q04 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q04_plugin)                  /* venc44k2q04 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q04;               /* save type */
    }
#endif
#if VS1053B_OGG_VENC44K2Q05 != 0
    else if (patch == gsc_vs1053b_patch_ogg_venc44k2q05_plugin)                  /* venc44k2q05 */
    {
        handle->plugin_patch_type = VS1053B_PATCH_OGG_VENC44K2Q05;               /* save type */
    }
#endif
    else if (patch == gsc_vs1053b_patch_wav_plugin)                              /* wav */
    {
        handle->plugin_patch_type = VS1053B_PATCH_WAV;                           /* save type */
    }
    else
    {
        handle->debug_print("vs1053b: invalid path address.\n");                 /* invalid path address */

        return 4;                                                                /* return error */
    }
    
    i = 0;                                                                       /* init 0 */
    while (i < len)                                                              /* loop */
    {
        addr = patch[i++];                                                       /* get addr */
        n = patch[i++];                                                          /* get n */
        if ((n & 0x8000U) != 0)                                                  /* rle run, replicate n samples */
        {
            n &= 0x7FFFU;                                                        /* & */
            val = patch[i++];                                                    /* get a val */
            while (n--)                                                          /* loop */
            {
                buf[0] = (val >> 8) & 0xFF;                                      /* high part */
                buf[1] = (val >> 0) & 0xFF;                                      /* low part */
                res = a_vs1053b_spi_write(handle, (uint8_t)addr, buf, 2);        /* write patch */
                if (res != 0)                                                    /* check result */
                {
                    handle->debug_print("vs1053b: load patch failed.\n");        /* load patch failed */

                    return 1;                                                    /* return error */
                }
            }
        }
        else                                                                     /* copy run, copy n sample */
        {
            while (n--)                                                          /* loop */
            {
                val = patch[i++];                                                /* get a val */
                buf[0] = (val >> 8) & 0xFF;                                      /* high part */
                buf[1] = (val >> 0) & 0xFF;                                      /* low part */
                res = a_vs1053b_spi_write(handle, (uint8_t)addr, buf, 2);        /* write patch */
                if (res != 0)                                                    /* check result */
                {
                    handle->debug_print("vs1053b: load patch failed.\n");        /* load patch failed */

                    return 1;                                                    /* return error */
                }
            }
        }
    }

    return 0;                                                                    /* success return 0 */
}

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
uint8_t vs1053b_set_data(vs1053b_handle_t *handle, uint8_t *buf, uint16_t len)
{
    if (handle == NULL)                                      /* check handle */
    {
        return 2;                                            /* return error */
    }
    if (handle->inited != 1)                                 /* check handle initialization */
    {
        return 3;                                            /* return error */
    }

    return a_vs1053b_spi_write_data(handle, buf, len);       /* write data */
}

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
uint8_t vs1053b_set_reg(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len)
{
    if (handle == NULL)                                      /* check handle */
    {
        return 2;                                            /* return error */
    }
    if (handle->inited != 1)                                 /* check handle initialization */
    {
        return 3;                                            /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                       /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");     /* chip is busy */

        return 1;                                            /* return error */
    }

    return a_vs1053b_spi_write(handle, reg, buf, len);       /* write data */
}

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
uint8_t vs1053b_get_reg(vs1053b_handle_t *handle, uint8_t reg, uint8_t *buf, uint16_t len)
{
    if (handle == NULL)                                     /* check handle */
    {
        return 2;                                           /* return error */
    }
    if (handle->inited != 1)                                /* check handle initialization */
    {
        return 3;                                           /* return error */
    }
    if (a_check_busy_pin(handle) != 0)                      /* check busy */
    {
        handle->debug_print("vs1053b: chip is busy.\n");    /* chip is busy */

        return 1;                                           /* return error */
    }

    return a_vs1053b_spi_read(handle, reg, buf, len);       /* read data */
}

/**
 * @brief      get chip's information
 * @param[out] *info points to a vs1053b info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t vs1053b_info(vs1053b_info_t *info)
{
    if (info == NULL)                                               /* check handle */
    {
        return 2;                                                   /* return error */
    }

    memset(info, 0, sizeof(vs1053b_info_t));                        /* initialize vs1053b info structure */
    strncpy(info->chip_name, CHIP_NAME, 32);                        /* copy chip name */
    strncpy(info->manufacturer_name, MANUFACTURER_NAME, 32);        /* copy manufacturer name */
    strncpy(info->interface, "SPI", 8);                             /* copy interface name */
    info->supply_voltage_min_v = SUPPLY_VOLTAGE_MIN;                /* set minimal supply voltage */
    info->supply_voltage_max_v = SUPPLY_VOLTAGE_MAX;                /* set maximum supply voltage */
    info->max_current_ma = MAX_CURRENT;                             /* set maximum current */
    info->temperature_max = TEMPERATURE_MAX;                        /* set minimal temperature */
    info->temperature_min = TEMPERATURE_MIN;                        /* set maximum temperature */
    info->driver_version = DRIVER_VERSION;                          /* set driver version */

    return 0;                                                       /* success return 0 */
}
