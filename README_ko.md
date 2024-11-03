[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver VS1053B

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/vs1053b/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

VS1053b는 Ogg Vorbis/MP3/AAC/WMA/FLAC/WAVMIDI 오디오 디코더이자 단일 칩의 PCM/IMA ADPCM/Ogg Vorbis 인코더입니다. 내장형 디코더, 직렬 제어 및 입력 데이터 인터페이스, 최대 8개의 일반 용도 I/O 핀, UART, 고품질 가변 샘플링 속도 스테레오 ADC(마이크, 라인, 라인 + 마이크 또는 2라인) 및 스테레오 DAC, 이어 이어폰 증폭기 및 공통 전압 버퍼.VS1053b는 시스템 슬레이브로 수신하는 직렬 입력 버스를 통한 입력 비트스트림. 입력 스트림은 디코딩되어 디지털 볼륨 컨트롤을 통해 18비트 오버샘플링, 멀티비트, 시그마델타 DAC로 전달됩니다. 디코딩은 직렬 제어 버스를 통해 제어됩니다. 기본 디코딩 외에도 DSP 효과와 같은 애플리케이션별 기능을 사용자 RAM 메모리에 추가할 수 있습니다.

LibDriver VS1053B는 LibDriver에서 시작한 VS1053B의 전체 기능 드라이버입니다. 오디오 재생, 오디오 녹음 등의 기능을 제공합니다. LibDriver는 MISRA를 준수합니다.

### 콘텐츠

  - [설명](#설명)
  - [설치](#설치)
  - [사용](#사용)
    - [example basic play](#example-basic-play)
    - [example basic record](#example-basic-record)
  - [문서](#문서)
  - [기고](#기고)
  - [저작권](#저작권)
  - [문의하기](#문의하기)

### 설명

/src 디렉토리에는 LibDriver VS1053B의 소스 파일이 포함되어 있습니다.

/interface 디렉토리에는 LibDriver VS1053B용 플랫폼 독립적인 SPI버스 템플릿이 포함되어 있습니다.

/test 디렉토리에는 LibDriver VS1053B드라이버 테스트 프로그램이 포함되어 있어 칩의 필요한 기능을 간단히 테스트할 수 있습니다.

/example 디렉토리에는 LibDriver VS1053B프로그래밍 예제가 포함되어 있습니다.

/doc 디렉토리에는 LibDriver VS1053B오프라인 문서가 포함되어 있습니다.

/datasheet 디렉토리에는 VS1053B데이터시트가 있습니다.

/project 디렉토리에는 일반적으로 사용되는 Linux 및 마이크로컨트롤러 개발 보드의 프로젝트 샘플이 포함되어 있습니다. 모든 프로젝트는 디버깅 방법으로 셸 스크립트를 사용하며, 자세한 내용은 각 프로젝트의 README.md를 참조하십시오.

/misra 에는 LibDriver misra 코드 검색 결과가 포함됩니다.

### 설치

/interface 디렉토리에서 플랫폼 독립적인SPI 버스 템플릿을 참조하여 지정된 플랫폼에 대한 SPI버스 드라이버를 완성하십시오.

/src 디렉터리, 플랫폼용 인터페이스 드라이버 및 자체 드라이버를 프로젝트에 추가합니다. 기본 예제 드라이버를 사용하려면 /example 디렉터리를 프로젝트에 추가합니다.

### 사용

/example 디렉터리의 예제를 참조하여 자신만의 드라이버를 완성할 수 있습니다. 기본 프로그래밍 예제를 사용하려는 경우 사용 방법은 다음과 같습니다.

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

```c
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

### 문서

온라인 문서: [https://www.libdriver.com/docs/vs1053b/index.html](https://www.libdriver.com/docs/vs1053b/index.html).

오프라인 문서: /doc/html/index.html.

### 기고

CONTRIBUTING.md 를 참조하십시오.

### 저작권

저작권 (c) 2015 - 지금 LibDriver 판권 소유

MIT 라이선스(MIT)

이 소프트웨어 및 관련 문서 파일("소프트웨어")의 사본을 얻은 모든 사람은 이에 따라 무제한 사용, 복제, 수정, 통합, 출판, 배포, 2차 라이선스를 포함하여 소프트웨어를 처분할 수 있는 권리가 부여됩니다. 소프트웨어의 사본에 대한 라이선스 및/또는 판매, 그리고 소프트웨어가 위와 같이 배포된 사람의 권리에 대한 2차 라이선스는 다음 조건에 따릅니다.

위의 저작권 표시 및 이 허가 표시는 이 소프트웨어의 모든 사본 또는 내용에 포함됩니다.

이 소프트웨어는 상품성, 특정 목적에의 적합성 및 비침해에 대한 보증을 포함하되 이에 국한되지 않는 어떠한 종류의 명시적 또는 묵시적 보증 없이 "있는 그대로" 제공됩니다. 어떤 경우에도 저자 또는 저작권 소유자는 계약, 불법 행위 또는 기타 방식에 관계없이 소프트웨어 및 기타 소프트웨어 사용으로 인해 발생하거나 이와 관련하여 발생하는 청구, 손해 또는 기타 책임에 대해 책임을 지지 않습니다.

### 문의하기

연락주세요lishifenging@outlook.com.