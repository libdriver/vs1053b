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
 * @file      main.c
 * @brief     main source file
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
#include "driver_vs1053b_play_test.h"
#include "driver_vs1053b_record_test.h"
#include "driver_vs1053b_basic.h"
#include <getopt.h>
#include <stdlib.h>

/**
 * @brief global var definition
 */
volatile uint8_t gs_flag = 0;      /**< end of test */
volatile uint8_t gs_mode = 0;      /**< audio mode */

/**
 * @brief     interface receive callback
 * @param[in] type is the receive callback type
 * @param[in] cur_pos is the current position
 * @note      none
 */
static void a_callback(uint8_t type, uint32_t cur_pos)
{
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
            vs1053b_interface_debug_print("vs1053b: play end.\n");
            
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
            if (gs_mode == 1)
            {
                uint8_t res;
                uint16_t decode_time;
                uint16_t rate;
                vs1053b_channel_t channel;
                vs1053b_audio_info_t info;
                
                /* get decode time */
                res = vs1053b_basic_get_decode_time(&decode_time);
                if (res == 0)
                {
                    vs1053b_interface_debug_print("\nvs1053b: play time is %02d:%02d:%02d.\n", 
                                                 (decode_time % 86400) / 3600, (decode_time % 3600) / 60, decode_time % 60);
                }
                
                /* get byte rate */
                res = vs1053b_basic_get_bytes_rate(&rate);
                if (res == 0)
                {
                    vs1053b_interface_debug_print("vs1053b: byte rate is %d bytes/sec.\n", rate);
                }
                
                /* get sample rate */
                res = vs1053b_basic_get_sample_rate(&rate, &channel);
                if (res == 0)
                {
                    vs1053b_interface_debug_print("vs1053b: sample rate is %dHz, channel is %d.\n", rate, (uint8_t)(channel + 1));
                }
                
                /* get info */
                res = vs1053b_basic_get_info(&info);
                if (res == 0)
                {
                    vs1053b_interface_debug_print("vs1053b: format is %s, rate is %0.0fkbps.\n", info.format_name, info.kbps);
                }
            }
            if (gs_mode == 2)
            {
                (void)vs1053b_basic_stop();
                gs_flag = 1;
                vs1053b_interface_debug_print("vs1053b: up to record time.\n");
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
 * @brief     vs1053b full function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t vs1053b(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"file", required_argument, NULL, 1},
        {"time", required_argument, NULL, 2},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    char file[49] = "test.mp3";
    uint32_t audio_time = 60;
    
    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }
    
    /* init 0 */
    optind = 0;
    
    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);
        
        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");
                
                break;
            }
            
            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");
                
                break;
            }
            
            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");
                
                break;
            }
            
            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);
                
                break;
            }
            
            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);
                
                break;
            }
            
            /* file */
            case 1 :
            {
                uint16_t i;
                uint16_t len;
                
                /* set the file */
                memset(file, 0, sizeof(char) * 49);
                strncpy(file, optarg, 48);
                
                /* replace the - */
                len = (uint16_t)strlen(file);
                for (i = 0; i < len; i++)
                {
                    if (file[i] == '-')
                    {
                        file[i] = ' ';
                    }
                }
                
                break;
            }
            
            /* time */
            case 2 :
            {
                /* convert the audio time */
                audio_time = atol(optarg);
                
                break;
            }
            
            /* the end */
            case -1 :
            {
                break;
            }
            
            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run the function */
    if (strcmp("t_reg", type) == 0)
    {
        uint8_t res;
        
        /* run reg test */
        res = vs1053b_register_test();
        if (res != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("t_play", type) == 0)
    {
        uint8_t res;
        
        /* run play test */
        res = vs1053b_play_test(file);
        if (res != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("t_record", type) == 0)
    {
        uint8_t res;
        
        /* run record test */
        res = vs1053b_record_test(file, audio_time);
        if (res != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("e_play", type) == 0)
    {
        uint8_t res;
        
        /* play init */
        res = vs1053b_basic_init(VS1053B_MODE_PLAY, VS1053B_RECORD_FORMAT_WAV, a_callback);
        if (res != 0)
        {
            return 1;
        }
        
        /* set timeout */
        res = vs1053b_basic_set_callback_period(5);
        if (res != 0)
        {
            (void)vs1053b_basic_deinit();
            
            return 1;
        }
        
        /* play audio */
        res = vs1053b_basic_play(file);
        if (res != 0)
        {
            (void)vs1053b_basic_deinit();
            
            return 1;
        }
        
        /* clear flag */
        gs_flag = 0;
        
        /* play */
        gs_mode = 1;
        
        /* run the server and wait for the end */
        while (gs_flag == 0)
        {
            (void)vs1053b_basic_service();
        }
        
        /* deinit */
        (void)vs1053b_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_record", type) == 0)
    {
        uint8_t res;
        
        /* output */
        vs1053b_interface_debug_print("start record\n");
        
        if (strstr(file, ".ogg") != NULL)
        {
            /* record init */
            res = vs1053b_basic_init(VS1053B_MODE_RECORD, VS1053B_RECORD_FORMAT_OGG, a_callback);
            if (res != 0)
            {
                return 1;
            }
        }
        else
        {
            /* record init */
            res = vs1053b_basic_init(VS1053B_MODE_RECORD, VS1053B_RECORD_FORMAT_WAV, a_callback);
            if (res != 0)
            {
                return 1;
            }
        }
        
        /* set timeout */
        res = vs1053b_basic_set_callback_period(audio_time);
        if (res != 0)
        {
            (void)vs1053b_basic_deinit();
            
            return 1;
        }
        
        /* record audio */
        res = vs1053b_basic_record(file);
        if (res != 0)
        {
            (void)vs1053b_basic_deinit();
            
            return 1;
        }
        
        /* clear flag */
        gs_flag = 0;
        
        /* record */
        gs_mode = 2;
        
        /* run the server and wait for the end */
        while (gs_flag == 0)
        {
            (void)vs1053b_basic_service();
        }
        
        /* deinit */
        (void)vs1053b_basic_deinit();
        
        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        vs1053b_interface_debug_print("Usage:\n");
        vs1053b_interface_debug_print("  vs1053b (-i | --information)\n");
        vs1053b_interface_debug_print("  vs1053b (-h | --help)\n");
        vs1053b_interface_debug_print("  vs1053b (-p | --port)\n");
        vs1053b_interface_debug_print("  vs1053b (-t reg | --test=reg)\n");
        vs1053b_interface_debug_print("  vs1053b (-t play | --test=play) [--file=<path>]\n");
        vs1053b_interface_debug_print("  vs1053b (-t record | --test=record) [--file=<path>] [--time=<second>]\n");
        vs1053b_interface_debug_print("  vs1053b (-e play | --example=play) [--file=<path>]\n");
        vs1053b_interface_debug_print("  vs1053b (-e record | --example=record) [--file=<path>] [--time=<second>]\n");
        vs1053b_interface_debug_print("\n");
        vs1053b_interface_debug_print("Options:\n");
        vs1053b_interface_debug_print("  -e <play | record>, --example=<play | record>\n");
        vs1053b_interface_debug_print("                          Run the driver example.\n");
        vs1053b_interface_debug_print("      --file=<path>       Set the audio file path.([default: test.mp3])\n");
        vs1053b_interface_debug_print("  -h, --help              Show the help.\n");
        vs1053b_interface_debug_print("  -i, --information       Show the chip information.\n");
        vs1053b_interface_debug_print("  -p, --port              Display the pin connections of the current board.\n");
        vs1053b_interface_debug_print("  -t <reg | play | record>, --test=<reg | play | record>\n");
        vs1053b_interface_debug_print("                          Run the driver test.\n");
        vs1053b_interface_debug_print("      --time=<second>     Set the record time in second.([default: 60])\n");

        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        vs1053b_info_t info;
        
        /* print vs1053b info */
        vs1053b_info(&info);
        vs1053b_interface_debug_print("vs1053b: chip is %s.\n", info.chip_name);
        vs1053b_interface_debug_print("vs1053b: manufacturer is %s.\n", info.manufacturer_name);
        vs1053b_interface_debug_print("vs1053b: interface is %s.\n", info.interface);
        vs1053b_interface_debug_print("vs1053b: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        vs1053b_interface_debug_print("vs1053b: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        vs1053b_interface_debug_print("vs1053b: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        vs1053b_interface_debug_print("vs1053b: max current is %0.2fmA.\n", info.max_current_ma);
        vs1053b_interface_debug_print("vs1053b: max temperature is %0.1fC.\n", info.temperature_max);
        vs1053b_interface_debug_print("vs1053b: min temperature is %0.1fC.\n", info.temperature_min);
        
        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        vs1053b_interface_debug_print("vs1053b: SCI SCK connected to GPIO11(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SCI MISO connected to GPIO9(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SCI MOSI connected to GPIO10(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SCI CS connected to GPIO8(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SDI SCK connected to GPIO11(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SDI MISO connected to GPIO9(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SDI MOSI connected to GPIO10(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: SDI CS connected to GPIO7(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: RESET connected to GPIO27(BCM).\n");
        vs1053b_interface_debug_print("vs1053b: DREQ connected to GPIO17(BCM).\n");
        
        return 0;
        
        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc is arg numbers
 * @param[in] **argv is the arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = vs1053b(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        vs1053b_interface_debug_print("vs1053b: run failed.\n");
    }
    else if (res == 5)
    {
        vs1053b_interface_debug_print("vs1053b: param is invalid.\n");
    }
    else
    {
        vs1053b_interface_debug_print("vs1053b: unknown status code.\n");
    }

    return 0;
}
