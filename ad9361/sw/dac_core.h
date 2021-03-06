/***************************************************************************//**
 *   @file   dac_core.h
 *   @brief  Header file of DAC Core Driver.
 *   @author DBogdan (dragos.bogdan@analog.com)
********************************************************************************
 * Copyright 2013(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/
#ifndef DAC_CORE_API_H_
#define DAC_CORE_API_H_

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/
#define ADI_REG_RSTN			0x0040
#define ADI_RSTN				(1 << 0)

#define ADI_REG_RATECNTRL		0x004C
#define ADI_RATE(x)				(((x) & 0xFF) << 0)
#define ADI_TO_RATE(x)			(((x) >> 0) & 0xFF)

#define ADI_REG_CNTRL_1			0x0044
#define ADI_ENABLE				(1 << 0)

#define ADI_REG_CNTRL_2			0x0048
#define ADI_PAR_TYPE			(1 << 7)
#define ADI_PAR_ENB				(1 << 6)
#define ADI_R1_MODE				(1 << 5)
#define ADI_DATA_FORMAT			(1 << 4)
#define ADI_DATA_SEL(x)			(((x) & 0xF) << 0)
#define ADI_TO_DATA_SEL(x)		(((x) >> 0) & 0xF)

#define ADI_REG_VDMA_FRMCNT		0x0084
#define ADI_VDMA_FRMCNT(x)		(((x) & 0xFFFFFFFF) << 0)
#define ADI_TO_VDMA_FRMCNT(x)	(((x) >> 0) & 0xFFFFFFFF)

#define ADI_REG_VDMA_STATUS		0x0088
#define ADI_VDMA_OVF			(1 << 1)
#define ADI_VDMA_UNF			(1 << 0)

enum {
	DATA_SEL_DDS,
	DATA_SEL_SED,
	DATA_SEL_DMA,
};

#define ADI_REG_CHAN_CNTRL_1_IIOCHAN(x)	(0x0400 + ((x) >> 1) * 0x40 + ((x) & 1) * 0x8)
#define ADI_DDS_SCALE(x)				(((x) & 0xF) << 0)
#define ADI_TO_DDS_SCALE(x)				(((x) >> 0) & 0xF)

#define ADI_REG_CHAN_CNTRL_2_IIOCHAN(x)	(0x0404 + ((x) >> 1) * 0x40 + ((x) & 1) * 0x8)
#define ADI_DDS_INIT(x)					(((x) & 0xFFFF) << 16)
#define ADI_TO_DDS_INIT(x)				(((x) >> 16) & 0xFFFF)
#define ADI_DDS_INCR(x)					(((x) & 0xFFFF) << 0)
#define ADI_TO_DDS_INCR(x)				(((x) >> 0) & 0xFFFF)

#define DDS_CHAN_TX1_I_F1	0
#define DDS_CHAN_TX1_I_F2	1
#define DDS_CHAN_TX1_Q_F1	2
#define DDS_CHAN_TX1_Q_F2	3
#define DDS_CHAN_TX2_I_F1	4
#define DDS_CHAN_TX2_I_F2	5
#define DDS_CHAN_TX2_Q_F1	6
#define DDS_CHAN_TX2_Q_F2	7

struct dds_state
{
	uint32_t	cached_freq[8];
	uint32_t	cached_phase[8];
	uint32_t	cached_scale[8];
	uint32_t	*dac_clk;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
void dac_init(uint8_t data_sel);
void dds_set_frequency(uint32_t chan, uint32_t freq);
void dds_set_phase(uint32_t chan, uint32_t phase);
void dds_set_scale(uint32_t chan, uint32_t scale);
void dds_update(void);

#endif
