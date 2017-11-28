///////////////////////////////////////////////////
//
//	FILE:       MPC89_I2C_Master.c
//	AUTHOR:     Neo (Hsin-Chih Lin)
//	COPYRIGHT:  (c) Megawin Technology Co., Ltd.
//	CREATED:    2008.6.4
//	PURPOSE:    Demo I2C Master
//
///////////////////////////////////////////////////
//#define DEBUG
//#include "REG_MPC82L54.H"
#include "MPC_I2C_Master.h"
#ifdef DEBUG
#include "debug.h"
#endif
#define E24C02 //EEPROM 24C02(1 byte address)
                 //or not (2 bytes address)

///////////////////////////////////////////////////
//
//	MainLoop()
//
///////////////////////////////////////////////////
unsigned char SLAdd = 0xa0;
void delay5ms()//for 82 series and 11.0592Mhz
{
    unsigned int i;
    for(i=0;i<4978;i++) ;
}
void main(void)
{
    unsigned char j;
	unsigned char numbyte=16;
    unsigned char idata wbuf[16];
    unsigned char idata rbuf[16];

	I2C_Initial(0);	  //set frequency
	
#ifdef DEBUG
    Debug_clear_LCD();
#endif

//1 byte read/write test
#ifdef E24C02
    I2C_Write_byte(SLAdd,0x22,0x55,0);
    delay5ms();
    rbuf[0]=I2C_Read_byte(SLAdd,0x22,0);
#else
    I2C_Write_byte(SLAdd,0x0133,0x55,1);
    delay5ms();
    rbuf[0]=I2C_Read_byte(SLAdd,0x0133,1);
#endif
#ifdef DEBUG
    if(rbuf[0]==0x55)
        Debug_show_msg_to_LCD(0x11);//Pass message
#endif
//2 byte read/write test
#ifdef E24C02
    I2C_Write_byte(SLAdd,0x0022,0x88,0);
    delay5ms();
    I2C_Write_byte(SLAdd,0x0023,0x99,0);
    delay5ms();
    rbuf[0]=I2C_Read_byte(SLAdd,0x0022,0);
    rbuf[1]=I2C_Read_byte(SLAdd,0x0023,0);
#else
    I2C_Write_byte(SLAdd,0x0122,0x88,1);
    delay5ms();
    I2C_Write_byte(SLAdd,0x0123,0x99,1);
    delay5ms();
    rbuf[0]=I2C_Read_byte(SLAdd,0x0122,1);
    rbuf[1]=I2C_Read_byte(SLAdd,0x0123,1);
#endif
#ifdef DEBUG
    if((rbuf[0]==0x88)&(rbuf[1]==0x99))
        Debug_show_msg_to_LCD(0x22);//Pass message
#endif

//16 bytes read/write test
#ifdef E24C02
    for(j=0;j<numbyte;j++)
        wbuf[j] = j;
    for(j=0;j<numbyte;j++)
    {
        I2C_Write_byte(SLAdd,0x0000+j,wbuf[j],0);
        delay5ms();
    }
    for(j=0;j<numbyte;j++)
        rbuf[j]=I2C_Read_byte(SLAdd,0x0000+j,0);
#else
    for(j=0;j<numbyte;j++)
        wbuf[j] = j;
    for(j=0;j<numbyte;j++)
    {
        I2C_Write_byte(SLAdd,0x0100+j,wbuf[j],1);
        delay5ms();
    }
    for(j=0;j<numbyte;j++)
        rbuf[j]=I2C_Read_byte(SLAdd,0x0100+j,1);
#endif
#ifdef DEBUG
    for(j=0;j<numbyte;j++)
        if(wbuf[j]!=rbuf[j])
            Debug_show_msg_to_LCD(0x88);//fail message
#endif

//16 bytes page read/write test
#ifdef E24C02
    for(j=0;j<numbyte;j++)
        wbuf[j] = j+0x11;
    I2C_Write_nByte(SLAdd,0x0000,&wbuf,numbyte,0);
    for(j=0;j<10;j++)
        delay5ms();
    I2C_Read_nByte(SLAdd,0x0000,&rbuf,numbyte,0);
    delay5ms();
#else
    for(j=0;j<numbyte;j++)
        wbuf[j] = j+0x11;
    I2C_Write_nByte(SLAdd,0x0200,&wbuf,numbyte,1);
    for(j=0;j<10;j++)
        delay5ms();
    I2C_Read_nByte(SLAdd,0x0200,&rbuf,numbyte,1);
    delay5ms();
#endif
#ifdef DEBUG
    for(j=0;j<numbyte;j++)
        if(wbuf[j]!=rbuf[j])
            Debug_show_msg_to_LCD(0x99);//fail message
#endif
    while(1);

}
