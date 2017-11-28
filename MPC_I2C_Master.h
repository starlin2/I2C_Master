///////////////////////////////////////////////////
//
//	FILE:       MPC_I2C_LIB.lib
//	AUTHOR:     Neo (Hsin-Chih Lin)
//	COPYRIGHT:  (c) Megawin Technology Co., Ltd.
//	CREATED:    2007.8.8
//	PURPOSE:    I2C Master library
//  DESCRIBTION:
//
///////////////////////////////////////////////////

extern void I2C_Initial(unsigned char);
extern void I2C_Write_byte(unsigned char, unsigned int, unsigned char , unsigned char);
extern unsigned char I2C_Read_byte(unsigned char, unsigned int , unsigned char);
extern void I2C_Write_nByte(unsigned char ,unsigned int , unsigned char *, unsigned char, unsigned char);
extern void I2C_Read_nByte(unsigned char, unsigned int, unsigned char *, unsigned char, unsigned char);

///////////////////////////////////////////////////
//
//	Function:   I2C_Initial
//	Input:      Delay
//	Return value:
//              non
//
///////////////////////////////////////////////////
// Delay : Speed
// ==============
//   0   : 155KHz
//   1   :  90KHz
//   2   :  70KHz
//   3   :  64KHz
//   4   :  55KHz
//   5   :  49KHz
//   6   :  45KHz
///////////////////////////////////////////////////
//
//	Function:   I2C_Write_byte
//	Input:      Device address
//              Word address
//              Write data
//	Return value:
//              non
//
///////////////////////////////////////////////////
//
//	Function:   I2C_Read_byte
//	Input:      Device address
//              Word address
//	Return value:
//              Read Data
//
///////////////////////////////////////////////////
//
//	Function:   I2C_Write_nByte
//	Input:      Device address
//              Word address
//              Write data point
//              Write data length
//	Return value:
//              non
//
///////////////////////////////////////////////////
//
//	Function:   I2C_Read_nByte
//	Input:      Device address
//              Word address
//              Write data point
//              Write data length
//	Return value:
//              non
//
///////////////////////////////////////////////////

