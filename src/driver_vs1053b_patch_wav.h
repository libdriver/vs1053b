/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted,  free of charge,  to any person obtaining a copy
 * of this software and associated documentation files (the "Software"),  to deal
 * in the Software without restriction,  including without limitation the rights
 * to use,  copy,  modify,  merge,  publish,  distribute,  sublicense,  and/or sell
 * copies of the Software,  and to permit persons to whom the Software is
 * furnished to do so,  subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS OR
 * IMPLIED,  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,  DAMAGES OR OTHER
 * LIABILITY,  WHETHER IN AN ACTION OF CONTRACT,  TORT OR OTHERWISE,  ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_vs1053b_patch_wav.h
 * @brief     driver vs1053b patch wav header file
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

#ifndef DRIVER_VS1053B_PATCH_WAV_H
#define DRIVER_VS1053B_PATCH_WAV_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief vs1053b patch wav plugin size definition
 */
#define VS1053B_PATCH_WAV_PLUGIN_SIZE    40

/**
 * @brief vs1053b patch wav plugin definition
 */
static const uint16_t gsc_vs1053b_patch_wav_plugin[VS1053B_PATCH_WAV_PLUGIN_SIZE] =
{
    /* compressed plugin */ 
    0x0007, 0x0001, 0x8010, 0x0006, 0x001c, 0x3e12, 0xb817, 0x3e14, /* 0 */
    0xf812, 0x3e01, 0xb811, 0x0007, 0x9717, 0x0020, 0xffd2, 0x0030, /* 8 */
    0x11d1, 0x3111, 0x8024, 0x3704, 0xc024, 0x3b81, 0x8024, 0x3101, /* 10 */
    0x8024, 0x3b81, 0x8024, 0x3f04, 0xc024, 0x2808, 0x4800, 0x36f1, /* 18 */
    0x9811, 0x0007, 0x0001, 0x8028, 0x0006, 0x0002, 0x2a00, 0x040e,  
}; 

#ifdef __cplusplus
}
#endif

#endif
