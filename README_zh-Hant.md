[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver VS1053B

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/vs1053b/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

VS1053b是Ogg-Vorbis/MP3/AAC/WMA/FLAC/WAVMIDI音訊解碼器以及PCM/IMA ADPCM/Ogg-Vorbis編碼器。 它包含一個高性能、專有的低功耗DSP處理器覈心VS_ DSP4、數據記憶體、16KiB指令RAM和0.5+KiB數據RAM，用於與任何內寘解碼器同時運行的用戶應用程序、串列控制和輸入資料介面、多達8個通用I/O引脚、一個UART，以及一個高品質的可變取樣速率身歷聲ADC（麥克風、線路、線路+麥克風或2線路）和身歷聲DAC，然後是耳機放大器和公共電壓緩衝器。 VS1053b通過串列輸入匯流排接收其輸入位元流，並將其作為系統從機監聽。 輸入流被解碼並通過數位音量控制傳遞到18比特過採樣、多位、sigmadelta DAC。 解碼通過串列控制匯流排進行控制。 除了基本解碼之外，還可以向用戶RAM記憶體添加特定於應用程序的功能，如DSP效果。

LibDriver VS1053B是LibDriver推出的VS1053B全功能驅動，提供音訊播放、音量錄製等功能並且它符合MISRA標準。

### 目錄

  - [說明](#說明)
  - [安裝](#安裝)
  - [使用](#使用)
    - [example basic play](#example-basic-play)
    - [example basic record](#example-basic-record)
  - [文檔](#文檔)
  - [貢獻](#貢獻)
  - [版權](#版權)
  - [聯繫我們](#聯繫我們)

### 說明

/src目錄包含了LibDriver VS1053B的源文件。

/interface目錄包含了LibDriver VS1053B與平台無關的SPI總線模板。

/test目錄包含了LibDriver VS1053B驅動測試程序，該程序可以簡單的測試芯片必要功能。

/example目錄包含了LibDriver VS1053B編程範例。

/doc目錄包含了LibDriver VS1053B離線文檔。

/datasheet目錄包含了VS1053B數據手冊。

/project目錄包含了常用Linux與單片機開發板的工程樣例。所有工程均採用shell腳本作為調試方法，詳細內容可參考每個工程裡面的README.md。

/misra目錄包含了LibDriver MISRA程式碼掃描結果。

### 安裝

參考/interface目錄下與平台無關的SPI總線模板，完成指定平台的SPI總線驅動。

將/src目錄，您使用平臺的介面驅動和您開發的驅動加入工程，如果您想要使用默認的範例驅動，可以將/example目錄加入您的工程。

### 使用

您可以參考/example目錄下的程式設計範例完成適合您的驅動，如果您想要使用默認的程式設計範例，以下是它們的使用方法。

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

### 文檔

在線文檔: [https://www.libdriver.com/docs/vs1053b/index.html](https://www.libdriver.com/docs/vs1053b/index.html)。

離線文檔: /doc/html/index.html。

### 貢獻

請參攷CONTRIBUTING.md。

### 版權

版權 (c) 2015 - 現在 LibDriver 版權所有

MIT 許可證（MIT）

特此免費授予任何獲得本軟件副本和相關文檔文件（下稱“軟件”）的人不受限制地處置該軟件的權利，包括不受限制地使用、複製、修改、合併、發布、分發、轉授許可和/或出售該軟件副本，以及再授權被配發了本軟件的人如上的權利，須在下列條件下：

上述版權聲明和本許可聲明應包含在該軟件的所有副本或實質成分中。

本軟件是“如此”提供的，沒有任何形式的明示或暗示的保證，包括但不限於對適銷性、特定用途的適用性和不侵權的保證。在任何情況下，作者或版權持有人都不對任何索賠、損害或其他責任負責，無論這些追責來自合同、侵權或其它行為中，還是產生於、源於或有關於本軟件以及本軟件的使用或其它處置。

### 聯繫我們

請聯繫lishifenging@outlook.com。