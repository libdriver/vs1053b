### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

SCI SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

SDI SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO7.

GPIO Pin: RESET/DREQ GPIO27/GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(vs1053b REQUIRED)
```

### 3. VS1053B

#### 3.1 Command Instruction

1. Show vs1053b chip and driver information.

   ```shell
   vs1053b (-i | --information)
   ```

2. Show vs1053b help.

   ```shell
   vs1053b (-h | --help)
   ```

3. Show vs1053b pin connections of the current board.

   ```shell
   vs1053b (-p | --port)
   ```

4. Run vs1053b register test.

   ```shell
   vs1053b (-t reg | --test=reg)
   ```

5. Run vs1053b play test, path is the audio file path.

   ```shell
   vs1053b (-t play | --test=play) [--file=<path>]
   ```

6. Run vs1053b record test, path is the audio file path, second is the record time.

   ```shell
   vs1053b (-t record | --test=record) [--file=<path>] [--time=<second>]
   ```

7. Run vs1053b play function, path is the audio file path.

   ```shell
   vs1053b (-e play | --example=play) [--file=<path>]
   ```

8. Run vs1053b record function, path is the audio file path, second is the record time.

   ```shell
   vs1053b (-e record | --example=record) [--file=<path>] [--time=<second>]
   ```

#### 3.2 Command Example

```shell
./vs1053b -i

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
```

```shell
./vs1053b -p

vs1053b: SCI SCK connected to GPIO11(BCM).
vs1053b: SCI MISO connected to GPIO9(BCM).
vs1053b: SCI MOSI connected to GPIO10(BCM).
vs1053b: SCI CS connected to GPIO8(BCM).
vs1053b: SDI SCK connected to GPIO11(BCM).
vs1053b: SDI MISO connected to GPIO9(BCM).
vs1053b: SDI MOSI connected to GPIO10(BCM).
vs1053b: SDI CS connected to GPIO7(BCM).
vs1053b: RESET connected to GPIO27(BCM).
vs1053b: DREQ connected to GPIO17(BCM).
```

```shell
./vs1053b -t reg

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start register test.
vs1053b: vs1053b_set_diff/vs1053b_get_diff test.
vs1053b: left channel inverted.
vs1053b: check diff ok.
vs1053b: normal in phase audio.
vs1053b: check diff ok.
vs1053b: vs1053b_set_mpeg_layer_i_and_ii/vs1053b_get_mpeg_layer_i_and_ii test.
vs1053b: disable mpeg layer i and ii.
vs1053b: check mpeg layer i and ii ok.
vs1053b: enable mpeg layer i and ii.
vs1053b: check mpeg layer i and ii ok.
vs1053b: vs1053b_set_cancel_decoding_current_file/vs1053b_get_cancel_decoding_current_file test.
vs1053b: enable cancel decoding current file.
vs1053b: check cancel decoding current file ok.
vs1053b: disable cancel decoding current file.
vs1053b: check cancel decoding current file ok.
vs1053b: vs1053b_set_ear_speaker_low_setting/vs1053b_get_ear_speaker_low_setting test.
vs1053b: enable ear speaker low setting.
vs1053b: check ear speaker low setting ok.
vs1053b: disable ear speaker low setting.
vs1053b: check ear speaker low setting ok.
vs1053b: vs1053b_set_allow_sdi_test/vs1053b_get_allow_sdi_test test.
vs1053b: enable allow sdi test.
vs1053b: check allow sdi test ok.
vs1053b: disable allow sdi test.
vs1053b: check allow sdi test ok.
vs1053b: vs1053b_set_stream_mode/vs1053b_get_stream_mode test.
vs1053b: enable stream mode.
vs1053b: check stream mode ok.
vs1053b: disable stream mode.
vs1053b: check stream mode ok.
vs1053b: vs1053b_set_ear_speaker_high_setting/vs1053b_get_ear_speaker_high_setting test.
vs1053b: enable ear speaker high setting.
vs1053b: check ear speaker high setting ok.
vs1053b: disable ear speaker high setting.
vs1053b: check ear speaker high setting ok.
vs1053b: vs1053b_set_dclk_edge/vs1053b_get_dclk_edge test.
vs1053b: set dclk edge falling.
vs1053b: check dclk edge ok.
vs1053b: vs1053b_set_sdi_bit_order/vs1053b_get_sdi_bit_order test.
vs1053b: set sdi bit order msb first.
vs1053b: check sdi bit order ok.
vs1053b: vs1053b_set_share_spi_chip_select/vs1053b_get_share_spi_chip_select test.
vs1053b: enable share spi chip select.
vs1053b: check share spi chip select ok.
vs1053b: disable share spi chip select.
vs1053b: check share spi chip select ok.
vs1053b: vs1053b_set_native_spi_modes/vs1053b_get_native_spi_modes test.
vs1053b: enable native spi modes.
vs1053b: check native spi modes ok.
vs1053b: vs1053b_set_pcm_adpcm_recording_active/vs1053b_get_pcm_adpcm_recording_active test.
vs1053b: enable pcm adpcm recording active.
vs1053b: check pcm adpcm recording active ok.
vs1053b: disable pcm adpcm recording active.
vs1053b: check pcm adpcm recording active ok.
vs1053b: vs1053b_set_selector/vs1053b_get_selector test.
vs1053b: set selector microphone.
vs1053b: check selector ok.
vs1053b: set selector line1.
vs1053b: check selector ok.
vs1053b: vs1053b_set_clock_range/vs1053b_get_clock_range test.
vs1053b: set clock range 12MHz - 13MHz.
vs1053b: check clock range ok.
vs1053b: vs1053b_set_do_not_jump/vs1053b_get_do_not_jump test.
vs1053b: enable do not jump.
vs1053b: check do not jump ok.
vs1053b: disable do not jump.
vs1053b: check do not jump ok.
vs1053b: vs1053b_set_swing/vs1053b_get_swing test.
vs1053b: set swing 0x07.
vs1053b: check swing ok.
vs1053b: vs1053b_set_overload_indicator/vs1053b_get_overload_indicator test.
vs1053b: disable overload indicator.
vs1053b: check overload indicator ok.
vs1053b: vs1053b_set_overload_detection/vs1053b_get_overload_detection test.
vs1053b: enable overload detection.
vs1053b: check overload indicator ok.
vs1053b: disable overload detection.
vs1053b: check overload indicator ok.
vs1053b: vs1053b_get_version test.
vs1053b: version is 0x04.
vs1053b: vs1053b_set_analog_driver_power_down/vs1053b_get_analog_driver_power_down test.
vs1053b: enable analog driver power down.
vs1053b: check analog driver power down ok.
vs1053b: disable analog driver power down.
vs1053b: check analog driver power down ok.
vs1053b: vs1053b_set_analog_internal_power_down/vs1053b_get_analog_internal_power_down test.
vs1053b: disable analog internal power down.
vs1053b: check analog internal power down ok.
vs1053b: vs1053b_set_ad_clock/vs1053b_get_ad_clock test.
vs1053b: set ad clock 6mhz.
vs1053b: check ad clock ok.
vs1053b: vs1053b_set_reference_voltage/vs1053b_get_reference_voltage test.
vs1053b: set reference voltage 1.23V.
vs1053b: check reference voltage ok.
vs1053b: vs1053b_set_treble_control/vs1053b_get_treble_control test.
vs1053b: set treble control 0x06.
vs1053b: check treble control ok.
vs1053b: vs1053b_set_lower_limit_frequency_in_1000_hz/vs1053b_get_lower_limit_frequency_in_1000_hz test.
vs1053b: set lower limit frequency in 1000 hz 0x09.
vs1053b: check lower limit frequency in 1000 hz ok.
vs1053b: vs1053b_set_bass_enhancement/vs1053b_get_bass_enhancement test.
vs1053b: set bass enhancement 0x03.
vs1053b: check bass enhancement ok.
vs1053b: vs1053b_set_lower_limit_frequency_in_10_hz/vs1053b_get_lower_limit_frequency_in_10_hz test.
vs1053b: set lower limit frequency in 10 hz 0x01.
vs1053b: check lower limit frequency in 10 hz ok.
vs1053b: vs1053b_set_clock_multiplier/vs1053b_get_clock_multiplier test.
vs1053b: set clock multiplier 1.0 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 2.0 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 2.5 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 3.0 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 3.5 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 4.0 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 4.5 xtali.
vs1053b: check clock multiplier ok.
vs1053b: set clock multiplier 5.0 xtali.
vs1053b: check clock multiplier ok.
vs1053b: vs1053b_set_allowed_multiplier_addition/vs1053b_get_allowed_multiplier_addition test.
vs1053b: set allowed multiplier addition no modification.
vs1053b: check allowed multiplier addition ok.
vs1053b: set allowed multiplier addition 1.0 xtali.
vs1053b: check allowed multiplier addition ok.
vs1053b: set allowed multiplier addition 1.5 xtali.
vs1053b: check allowed multiplier addition ok.
vs1053b: set allowed multiplier addition 2.0 xtali.
vs1053b: check allowed multiplier addition ok.
vs1053b: vs1053b_set_clock_frequency/vs1053b_get_clock_frequency test.
vs1053b: set clock frequency 0x0FF.
vs1053b: check clock frequency ok.
vs1053b: vs1053b_set_decode_time/vs1053b_get_decode_time test.
vs1053b: set decode time 86.
vs1053b: check decode time ok.
vs1053b: vs1053b_set_sample_rate/vs1053b_get_sample_rate test.
vs1053b: set mono sample rate 3748.
vs1053b: check sample rate ok.
vs1053b: set stereo sample rate 2094.
vs1053b: check sample rate ok.
vs1053b: vs1053b_set_ram_address test.
vs1053b: check ram address ok.
vs1053b: vs1053b_write_ram/vs1053b_read_ram test.
vs1053b: write ram 0x01 0x23.
vs1053b: check ram ok.
vs1053b: vs1053b_set_start_address/vs1053b_get_start_address test.
vs1053b: set start address 0x01.
vs1053b: check start address ok.
vs1053b: vs1053b_set_vol/vs1053b_get_vol test.
vs1053b: set vol left 0xBA.
vs1053b: set vol left 0xAB.
vs1053b: check vol left ok.
vs1053b: check vol left ok.
vs1053b: vs1053b_get_hdata test.
vs1053b: dat0 is 0x00, dat1 is 0x00.
vs1053b: vs1053b_write_application/vs1053b_read_application test.
vs1053b: write application 0 0xF2 0xFB.
vs1053b: check application ok.
vs1053b: write application 1 0xE3 0x46.
vs1053b: check application ok.
vs1053b: write application 2 0x7C 0xC2.
vs1053b: check application ok.
vs1053b: write application 3 0x54 0xF8.
vs1053b: check application ok.
vs1053b: vs1053b_set_play_speed/vs1053b_get_play_speed test.
vs1053b: set play speed 1x.
vs1053b: check play speed ok.
vs1053b: set play speed 1.0x.
vs1053b: check play speed ok.
vs1053b: set play speed 2.0x.
vs1053b: check play speed ok.
vs1053b: set play speed 3.0x.
vs1053b: check play speed ok.
vs1053b: vs1053b_get_byte_rate test.
vs1053b: byte rate is 0.
vs1053b: vs1053b_get_end_fill_byte test.
vs1053b: end fill byte is 0.
vs1053b: vs1053b_swing_convert_to_register/vs1053b_swing_convert_to_data test.
vs1053b: swing convert check 2.00 and 2.00.
vs1053b: vs1053b_treble_control_convert_to_register/vs1053b_treble_control_convert_to_data test.
vs1053b: treble control convert check 4.50 and 4.50.
vs1053b: vs1053b_lower_limit_frequency_in_1000_hz_convert_to_register/vs1053b_lower_limit_frequency_in_1000_hz_convert_to_data test.
vs1053b: lower limit frequency in 1000 hz convert check 2000 and 2000.
vs1053b: vs1053b_lower_limit_frequency_in_10_hz_convert_to_register/vs1053b_lower_limit_frequency_in_10_hz_convert_to_data test.
vs1053b: lower limit frequency in 10 hz convert check 50 and 50.
vs1053b: vs1053b_clock_frequency_convert_to_register/vs1053b_clock_frequency_convert_to_data test.
vs1053b: clock frequency convert check 12000000.00 and 12000000.00.
vs1053b: vs1053b_vol_convert_to_register/vs1053b_vol_convert_to_data test.
vs1053b: vol convert check 3.50 and 3.50.
vs1053b: vs1053b_set_iis_mclk/vs1053b_get_iis_mclk test.
vs1053b: enable iis mclk.
vs1053b: check iis mclk ok.
vs1053b: disable iis mclk.
vs1053b: check iis mclk ok.
vs1053b: vs1053b_set_iis/vs1053b_get_iis test.
vs1053b: enable iis.
vs1053b: check iis ok.
vs1053b: disable iis.
vs1053b: check iis ok.
vs1053b: vs1053b_set_iis_rate/vs1053b_get_iis_rate test.
vs1053b: set iis rate 48khz.
vs1053b: check iis rate ok.
vs1053b: set iis rate 96hz.
vs1053b: check iis rate ok.
vs1053b: set iis rate 192hz.
vs1053b: check iis rate ok.
vs1053b: vs1053b_set_gpio_direction/vs1053b_get_gpio_direction test.
vs1053b: set gpio direction 0x00F0.
vs1053b: check gpio direction ok.
vs1053b: vs1053b_set_gpio_output/vs1053b_get_gpio_output test.
vs1053b: set gpio output 0x0010.
vs1053b: check gpio output ok.
vs1053b: vs1053b_get_gpio_input test.
vs1053b: gpio input is 0x091C.
vs1053b: finish register test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.mp3

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:05.
vs1053b: byte rate is 40089 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.

vs1053b: play time is 00:00:10.
vs1053b: byte rate is 39985 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.

...

vs1053b: play time is 00:06:21.
vs1053b: byte rate is 39967 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.
vs1053b: irq play end with 15387712.
vs1053b: finish play test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.aac

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:05.
vs1053b: byte rate is 36503 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is aac_adts, rate is 292kbps.

vs1053b: play time is 00:00:10.
vs1053b: byte rate is 36975 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is aac_adts, rate is 296kbps.

...

vs1053b: play time is 00:06:20.
vs1053b: byte rate is 40287 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is aac_adts, rate is 322kbps.
vs1053b: irq play end with 15484800.
vs1053b: finish play test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.flac

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:04.
vs1053b: byte rate is 16588 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is flac, rate is 133kbps.

vs1053b: play time is 00:00:09.
vs1053b: byte rate is 19656 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is flac, rate is 157kbps.

...

vs1053b: play time is 00:06:21.
vs1053b: byte rate is 24184 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is flac, rate is 193kbps.
vs1053b: irq play end with 37039328.
vs1053b: finish play test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.ogg

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:04.
vs1053b: byte rate is 51698 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is ogg, rate is 414kbps.

vs1053b: play time is 00:00:09.
vs1053b: byte rate is 44536 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is ogg, rate is 364kbps.

...

vs1053b: play time is 00:06:20.
vs1053b: byte rate is 42838 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is ogg, rate is 343kbps.
vs1053b: irq play end with 16521344.
vs1053b: finish play test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.wav

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:04.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wav, rate is 524kbps.

vs1053b: play time is 00:00:09.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wav, rate is 524kbps.

...

vs1053b: play time is 00:06:22.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wav, rate is 524kbps.
vs1053b: irq play end with 67880512.
vs1053b: finish play test.
```

```shell
./vs1053b -t play --file=music/we-are-the-world.wma

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start play test.

vs1053b: play time is 00:00:05.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wma, rate is 524kbps.

vs1053b: play time is 00:00:10.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wma, rate is 524kbps.

...

vs1053b: play time is 00:06:21.
vs1053b: byte rate is 65535 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is wma, rate is 524kbps.
vs1053b: irq play end with 26518944.
vs1053b: finish play test.
```

```shell
./vs1053b -t record --file=record.wav --time=60

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start record test.
vs1053b: irq record end with 960556.
vs1053b: up to record time.
vs1053b: finish record test.
```

```shell
./vs1053b -t record --file=record.ogg --time=60

vs1053b: chip is VLSI VS1053B.
vs1053b: manufacturer is VLSI.
vs1053b: interface is SPI.
vs1053b: driver version is 1.0.
vs1053b: min supply voltage is 2.6V.
vs1053b: max supply voltage is 3.6V.
vs1053b: max current is 60.00mA.
vs1053b: max temperature is 85.0C.
vs1053b: min temperature is -40.0C.
vs1053b: start record test.
vs1053b: irq record end with 1202220.
vs1053b: up to record time.
vs1053b: finish record test.
```

```shell
./vs1053b -e play --file=music/we-are-the-world.mp3

vs1053b: play time is 00:00:05.
vs1053b: byte rate is 40089 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.

vs1053b: play time is 00:00:10.
vs1053b: byte rate is 39985 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.

...

vs1053b: play time is 00:06:21.
vs1053b: byte rate is 39967 bytes/sec.
vs1053b: sample rate is 44100Hz, channel is 2.
vs1053b: format is mp3, rate is 320kbps.
vs1053b: play end.
```

```shell
./vs1053b -e record --file=test.wav --time=60

start record
vs1053b: irq record end with 960556.
vs1053b: up to record time.
```

```shell
./vs1053b -e record --file=test.ogg --time=60

start record
vs1053b: irq record end with 1202732.
vs1053b: up to record time.
```

```shell
./vs1053b -h

Usage:
  vs1053b (-i | --information)
  vs1053b (-h | --help)
  vs1053b (-p | --port)
  vs1053b (-t reg | --test=reg)
  vs1053b (-t play | --test=play) [--file=<path>]
  vs1053b (-t record | --test=record) [--file=<path>] [--time=<second>]
  vs1053b (-e play | --example=play) [--file=<path>]
  vs1053b (-e record | --example=record) [--file=<path>] [--time=<second>]

Options:
  -e <play | record>, --example=<play | record>
                          Run the driver example.
      --file=<path>       Set the audio file path.([default: test.mp3])
  -h, --help              Show the help.
  -i, --information       Show the chip information.
  -p, --port              Display the pin connections of the current board.
  -t <reg | play | record>, --test=<reg | play | record>
                          Run the driver test.
      --time=<second>     Set the record time in second.([default: 60])
```
