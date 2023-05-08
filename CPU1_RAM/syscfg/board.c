/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	I2C_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// I2CA -> MPU6050 Pinmux
	//
	GPIO_setPinConfig(MPU6050_I2CSDA_PIN_CONFIG);
	GPIO_setPadConfig(MPU6050_I2CSDA_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(MPU6050_I2CSDA_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(MPU6050_I2CSCL_PIN_CONFIG);
	GPIO_setPadConfig(MPU6050_I2CSCL_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(MPU6050_I2CSCL_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// I2C Configurations
//
//*****************************************************************************
void I2C_init(){
	MPU6050_init();
}

void MPU6050_init(){
	I2C_disableModule(MPU6050_BASE);
	I2C_initController(MPU6050_BASE, DEVICE_SYSCLK_FREQ, 1000, I2C_DUTYCYCLE_33);
	I2C_setConfig(MPU6050_BASE, I2C_CONTROLLER_SEND_MODE);
	I2C_setTargetAddress(MPU6050_BASE, 104);
	I2C_disableLoopback(MPU6050_BASE);
	I2C_setBitCount(MPU6050_BASE, I2C_BITCOUNT_8);
	I2C_setDataCount(MPU6050_BASE, 1);
	I2C_setAddressMode(MPU6050_BASE, I2C_ADDR_MODE_7BITS);
	I2C_disableFIFO(MPU6050_BASE);
	I2C_clearInterruptStatus(MPU6050_BASE, I2C_INT_REG_ACCESS_RDY | I2C_INT_RX_DATA_RDY | I2C_INT_STOP_CONDITION | I2C_INT_TX_DATA_RDY);
	I2C_enableInterrupt(MPU6050_BASE, I2C_INT_REG_ACCESS_RDY | I2C_INT_RX_DATA_RDY | I2C_INT_STOP_CONDITION | I2C_INT_TX_DATA_RDY);
	I2C_setEmulationMode(MPU6050_BASE, I2C_EMULATION_FREE_RUN);
	I2C_enableModule(MPU6050_BASE);
}

