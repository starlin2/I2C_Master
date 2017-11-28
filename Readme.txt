////////////////////////////////////////////////////////////
//
//	FILE:           MPC89_I2C_Readme.Txt
//	AUTHOR:         Neo (Hsin-Chih Lin)
//	E-Mail:	        NeoLin@megawin.com.tw
//	COPYRIGHT:      (c) Megawin Technology Co., Ltd.
//	CREATED:        2008.3.3
//	PURPOSE:        Demo I2C programm Document
//  Input :         11.0592MHz clock to 8051.
//	Description:	
//
////////////////////////////////////////////////////////////

   Library file    |  SDA  |  SCL  |
===================+=======+=======+
MPC_I2C_Master_001 |  P00  |  P01  |
MPC_I2C_Master_023 |  P02  |  P03  |
MPC_I2C_Master_045 |  P04  |  P05  |
MPC_I2C_Master_067 |  P06  |  P07  |
MPC_I2C_Master_101 |  P10  |  P11  |
MPC_I2C_Master_123 |  P12  |  P13  |
MPC_I2C_Master_145 |  P14  |  P15  |
MPC_I2C_Master_167 |  P16  |  P17  |
MPC_I2C_Master_201 |  P20  |  P21  |
MPC_I2C_Master_223 |  P22  |  P23  |
MPC_I2C_Master_245 |  P24  |  P25  |
MPC_I2C_Master_267 |  P26  |  P27  |
MPC_I2C_Master_301 |  P30  |  P31  |
MPC_I2C_Master_323 |  P32  |  P33  |
MPC_I2C_Master_345 |  P34  |  P35  |
MPC_I2C_Master_367 |  P36  |  P37  |

///////////////////////////////////////////////////
//
//	Function:   I2C_Initial
//	Input:      Delay
//	Return value:
//              non
//
///////////////////////////////////////////////////
// Delay : MPC82 Speed | MPC89 Speed
// ====================+=============
//   0   :   155KHz    |    30KHz
//   1   :    90KHz    |    15KHz 
//   2   :    70KHz    |    13KHz
//   3   :    64KHz    |    11KHz
//   4   :    55KHz    |     9KHz
//   5   :    49KHz    |   8.5KHz
//   6   :    45KHz    |   7.5KHz

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

PS:If you use Keil C51 to complier assembly code you need to do this

Menu bar -> Flash -> Configure Flash Tools
Change to A51 option and you can see "Special Function Registers"
then disable "Define 8051 SFR Names"

If you have any problem ( can't understand or can't run this code )
or I have any mistake in this Document please send E-Mail let me know.Thx.
