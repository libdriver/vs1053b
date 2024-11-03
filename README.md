[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver VS1053B

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/vs1053b/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

VS1053b is an Ogg Vorbis/MP3/AAC/WMA/FLAC/WAVMIDI audio decoder as well as an PCM/IMA ADPCM/Ogg Vorbis encoder on a single chip. It contains a high-performance, proprietary low-power DSP processor core VS_DSP4, data memory, 16 KiB instruction RAM and 0.5+ KiB data RAM for user applications running simultaneously with any builtin decoder, serial control and input data interfaces, up to 8 general purpose I/O pins, an UART, as well as a high-quality variablesample-rate stereo ADC (mic, line, line + mic or 2line) and stereo DAC, followed by an earphone amplifier and a common voltage buffer.VS1053b receives its input bitstream through a serial input bus, which it listens to as a system slave. The input stream is decoded and passed through a digital volume control to an 18-bit oversampling, multi-bit, sigmadelta DAC. The decoding is controlled via a serial control bus. In addition to the basic decoding, it is possible to add application specific features, like DSP effects, to the user RAM memory.

LibDriver VS1053B is the full function driver of VS1053B launched by LibDriver. It provides functions of audio playing, audio recording, etc. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic play](#example-basic-play)
    - [example basic record](#example-basic-record)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver VS1053B source files.

/interface includes LibDriver VS1053B SPI platform independent template.

/test includes LibDriver VS1053B driver test code and this code can test the chip necessary function simply.

/example includes LibDriver VS1053B sample code.

/doc includes LibDriver VS1053B offline document.

/datasheet includes VS1053B datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface SPI platform independent template and finish your platform SPI driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

#### example basic play

```C
#include "driver_vs1053b_basic.h"

uint8_t res;
volatile uint8_t gs_flag = 0;
volatile uint8_t gs_mode = 0;

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
res = vs1053b_basic_play("0:test.mp3");
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
```
#### example basic record

```C
#include "driver_vs1053b_basic.h"

uint8_t res;
volatile uint8_t gs_flag = 0;
volatile uint8_t gs_mode = 0;

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

/* record init */
res = vs1053b_basic_init(VS1053B_MODE_RECORD, VS1053B_RECORD_FORMAT_WAV, a_callback);
if (res != 0)
{
    return 1;
}

/* set timeout */
res = vs1053b_basic_set_callback_period(60);
if (res != 0)
{
    (void)vs1053b_basic_deinit();

    return 1;
}

/* record audio */
res = vs1053b_basic_record("record.wav");
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
```

### Document

Online documents: [https://www.libdriver.com/docs/vs1053b/index.html](https://www.libdriver.com/docs/vs1053b/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.