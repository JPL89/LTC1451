// @File		LTC1451.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		13/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef LTC1451_H
#define LTC1451_H

#define LTC1451_CLK PORTCbits.RC0
#define LTC1451_DIN PORTCbits.RC1
#define LTC1451_DOUT PORTCbits.RC2
#define LTC1451_CS PORTCbits.RC3

#define LTC1451_CLK_TRIS TRISCbits.RC0
#define LTC1451_DIN_TRIS TRISCbits.RC1
#define LTC1451_DOUT_TRIS TRISCbits.RC2
#define LTC1451_CS_TRIS TRISCbits.RC3

static const void SPI_transfer(unsigned int data)
{     
    for(unsigned int mask = 0x800; mask; mask >>= 1)
    {
        if(data & mask) LTC1451_DIN = 1; else LTC1451_DIN = 0;
            
         __asm__ __volatile__("nop");
         LTC1451_CLK = 1;
         __asm__ __volatile__("nop");
         LTC1451_CLK = 0;
         __asm__ __volatile__("nop");    
    }
}

void LTC1451_Write(unsigned int value)
{
    LTC1451_CS = 0;
    SPI_transfer(value);
    LTC1451_CS = 1;   
}

void LTC1451_Init(void)
{
    LTC1451_CLK_TRIS = 0;
    LTC1451_DIN_TRIS = 0;
    LTC1451_DOUT_TRIS = 1;
    LTC1451_CS_TRIS = 0;
    
    LTC1451_CS = 1;
}

#endif 
