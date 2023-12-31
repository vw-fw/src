/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2010 Adrian Chadd
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* $FreeBSD$ */

#ifndef	__AR91XX_REG_H__
#define	__AR91XX_REG_H__

#define	AR91XX_BASE_FREQ		5000000

/* reset block */
#define	AR91XX_RESET_REG_RESET_MODULE	AR71XX_RST_BLOCK_BASE + 0x1c

#define	AR91XX_RST_RESET_MODULE_USBSUS_OVERRIDE	(1 << 10)
#define	AR91XX_RST_RESET_MODULE_AMBA2WMAC	(1 << 22)

/* PLL block */
#define	AR91XX_PLL_REG_CPU_CONFIG       AR71XX_PLL_CPU_BASE + 0x00
#define	AR91XX_PLL_REG_ETH_CONFIG       AR71XX_PLL_CPU_BASE + 0x04
#define	AR91XX_PLL_REG_ETH0_INT_CLOCK   AR71XX_PLL_CPU_BASE + 0x14
#define	AR91XX_PLL_REG_ETH1_INT_CLOCK   AR71XX_PLL_CPU_BASE + 0x18

#define	AR91XX_PLL_DIV_SHIFT		0
#define	AR91XX_PLL_DIV_MASK		0x3ff
#define	AR91XX_DDR_DIV_SHIFT		22
#define	AR91XX_DDR_DIV_MASK		0x3
#define	AR91XX_AHB_DIV_SHIFT		19
#define	AR91XX_AHB_DIV_MASK		0x1

#define	AR91XX_ETH0_PLL_SHIFT		20
#define	AR91XX_ETH1_PLL_SHIFT		22

#define	AR91XX_PLL_VAL_1000		0x1a000000
#define	AR91XX_PLL_VAL_100		0x13000a44
#define	AR91XX_PLL_VAL_10		0x00441099

/* DDR block */
#define	AR91XX_DDR_CTRLBASE		(AR71XX_APB_BASE + 0)
#define	AR91XX_DDR_CTRL_SIZE		0x10000
#define	AR91XX_DDR_REG_FLUSH_GE0	AR91XX_DDR_CTRLBASE + 0x7c
#define	AR91XX_DDR_REG_FLUSH_GE1	AR91XX_DDR_CTRLBASE + 0x80
#define	AR91XX_DDR_REG_FLUSH_USB	AR91XX_DDR_CTRLBASE + 0x84
#define	AR91XX_DDR_REG_FLUSH_WMAC	AR91XX_DDR_CTRLBASE + 0x88

/* WMAC stuff */
#define	AR91XX_WMAC_BASE		(AR71XX_APB_BASE + 0x000C0000)
#define	AR91XX_WMAC_SIZE		0x30000

/* GPIO stuff */
#define	AR91XX_GPIO_FUNC_WMAC_LED_EN	(1 << 22)
#define	AR91XX_GPIO_FUNC_EXP_PORT_CS_EN	(1 << 21)
#define	AR91XX_GPIO_FUNC_I2S_REFCLKEN	(1 << 20)
#define	AR91XX_GPIO_FUNC_I2S_MCKEN	(1 << 19)
#define	AR91XX_GPIO_FUNC_I2S1_EN	(1 << 18)
#define	AR91XX_GPIO_FUNC_I2S0_EN	(1 << 17)
#define	AR91XX_GPIO_FUNC_SLIC_EN	(1 << 16)
#define	AR91XX_GPIO_FUNC_UART_RTSCTS_EN	(1 << 9)
#define	AR91XX_GPIO_FUNC_UART_EN	(1 << 8)
#define	AR91XX_GPIO_FUNC_USB_CLK_EN	(1 << 4)

#endif
