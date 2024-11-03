[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver VS1053B

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/vs1053b/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

VS1053b是Ogg-Vorbis/MP3/AAC/WMA/FLAC/WAVMIDI音频解码器以及PCM/IMA ADPCM/Ogg-Vorbis编码器。它包含一个高性能、专有的低功耗DSP处理器核心VS_DSP4、数据存储器、16KiB指令RAM和0.5+KiB数据RAM，用于与任何内置解码器同时运行的用户应用程序、串行控制和输入数据接口、多达8个通用I/O引脚、一个UART，以及一个高质量的可变采样率立体声ADC（麦克风、线路、线路+麦克风或2线路）和立体声DAC，然后是耳机放大器和公共电压缓冲器。VS1053b通过串行输入总线接收其输入比特流，并将其作为系统从机监听。输入流被解码并通过数字音量控制传递到18位过采样、多位、sigmadelta DAC。解码通过串行控制总线进行控制。除了基本解码之外，还可以向用户RAM存储器添加特定于应用程序的功能，如DSP效果。

LibDriver VS1053B是LibDriver推出的VS1053B全功能驱动，提供音频播放、音量录制等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic play](#example-basic-play)
    - [example basic record](#example-basic-record)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver VS1053B的源文件。

/interface目录包含了LibDriver VS1053B与平台无关的SPI总线模板。

/test目录包含了LibDriver VS1053B驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver VS1053B编程范例。

/doc目录包含了LibDriver VS1053B离线文档。

/datasheet目录包含了VS1053B数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的SPI总线模板，完成指定平台的SPI总线驱动。

将/src目录，您使用平台的接口驱动和您开发的驱动加入工程，如果您想要使用默认的范例驱动，可以将/example目录加入您的工程。

### 使用

您可以参考/example目录下的编程范例完成适合您的驱动，如果您想要使用默认的编程范例，以下是它们的使用方法。

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

### 文档

在线文档: [https://www.libdriver.com/docs/vs1053b/index.html](https://www.libdriver.com/docs/vs1053b/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。