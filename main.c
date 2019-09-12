//************************************************************
//  Data        :   2019/04/09
//  Programmer  :   Garfield.Lin
//  Function    :
//  MCU         :   MSP430G2553IPW28
//  Oscillator  :   Internal DOC 12MHZ
//  Version     :   V0.1
//
/*
 *
 *     V1.1  20190521    AID   ÐÞ¸Ä;
 *
 *
 *     V1.4   20190530 fenglong
 *      1. ¿Í»§ÒªÇóÍ¨ÐÅÄÜ¹Ø»ú
 *      2. ¿Í»§ÒªÇó¼ÓÈëSOC£¬ Î´¾­¹ýÑéÖ¤
 *      3. ³äµçÅÐ±¥½ØÖÁµçÁ÷ÐÞ¸ÄÎª150mA
 *      4. Ôö¼ÓÁËµÍÎÂÆð³äºÍ¸ßÎÂÆð³ä¹¦ÄÜ£¬
 *      5. Ôö¼ÓÁË¸ßÎÂÆð·Å¹¦ÄÜ
 *      6. PF_OCCµ÷ÕûÎª12A
 *      7. Ôö¼ÓÍ¨ÐÅ¿ª»úÖ¸Ê¾µÆ²»ÁÁ£¬°´¼ü¿ª»úÔÙÁÁ¡£
 *
 *
 *      V1.5    20190611 fenglong
 *
 *       1. Ôö¼Ó·ÅµçÆðÊ¼ÎÂ¶È±£»¤£¬Éè¶¨61¶È
 *       2. ÐÞ¸ÄÁË¸ßÎÂMOSFET±£»¤BUG
 *       3. 2.8V±£»¤ºó£¬ÉÏµç¼¤»î½ûÖ¹Êä³ö£¬Ö±µ½³äµçµ½3.4V
 *       4. Ôö¼ÓÁËµçÐ¾¸ßÎÂµÍÎÂ±¨¾¯£¬MOSFET¸ßÎÂ±¨¾¯¹¦ÄÜ
 *
 *       5. ËùÓÐ¹¦ÄÜ²âÊÔOK, ×¼±¸·â´æ
 *
 *
 *      V1.6    20190615  fenglong
 *
 *       1.Ôö¼Ó³äµç¾ùºâ£¬ Ôö¼Ólifetimes ,CELLS max/min voltage record
 *       2. Ôö¼ÓÉú²úÈÕÆÚÐ´Èë¶ÁÈ¡¡£
 *       3. Ôö¼ÓÖÆÔìÉÌ¶ÁÈ¡¡£
 *       2.ÐÞ¸Ä·¢ËÍÊµÊ±²ÎÊý½á¹¹Ìå¼°·¢ËÍ·½Ê½£¬ÒÔ½ÚÊ¡RAM
 *       3. °´¼ü100msÑÓÊ±ÐÞ¸ÄÎ»20ms
 *       4. ¹Ø±Õ4.17V ¹ýÑ¹¾¯¸æ¹¦ÄÜ¡£29.
 *       5. Ôö¼ÓÁËµçÁ¿ÏÔÊ¾¹¦ÄÜ¡£
 *       6. ÐÞ¸Ä³äµçºó²»ÄÜ²éÑ¯µçÁ¿BUG
 *       7. ÐÞ¸Ä²éÑ¯µçÁ¿²»ÄÜºôÎüBUG
 *
 *      V1.7    20190701 fenglong
 *       1. ¼ÓÈëSLEEP,Êµ²â¹¦ºÄÐ¡ÓÚ150uA
 *
 *      V1.8    20190702 fenglong
 *       1. ¼ÓÈë±¨¾¯µÆÐ§
 *       2. ÐÞÕý°´¼ü¹Ø»úºó½øÈëÐÝÃß°´¼üÊ§Ð§BUG
 *       3. ÐÞ¸Ä¿ª»úµÈÐ§
 *       4.
 *
 *
 *´ý¸Ä£º  1  ¸ßÎÂÆð³ä
 *´ý¸Ä£º 2. µÆÐ§¸ü¸Ä
 *´ý¸Ä£º 3 .Í¨ÐÅÇåPF
 *
 *      V1.81    20190708 fenglong
 *       1. ÐÞÕý³äµçÎÞ·¨¼¤»îBUG
 *       2. ¸ßÎÂÆð³ä°´¿Í»§ÒªÇóÐÞ¸ÄÎª²»ºìµÆ¾¯±¨
 *       3. Ôö¼ÓÍ¨ÐÅÇå³ýPF
 *       4. ÐÞ¸ÄÁËÐ´ÈëÉú²úÈÕÆÚÖ¸ÁîÂë
 *
 *      V1.82    20190708 fenglong
 *       1. ÐÞÕý³äµçÒ»¼¶¹ýÑ¹ÎÞ·¨ÏÔÊ¾ÂúµçBUG
 *		 2. ÐÞÕý¹ýÎÂÆð·ÅÎÞ·¨±¨¾¯			20190709
 *
 *      V1.83    20190709 fenglong
 *       1. È¡ÏûÐéÄâµçÁ¿²¹³¥¹¦ÄÜ
 *		 2. É¾³ý²¿·ÖÃ»ÓÐÓÃµÄ²éÑ¯µçÁ¿´úÂë
 *
 *
 *       V1.84    20190709 fenglong 20190710
 *       1. ¸ü¸Ä¿ª»úÁ÷Ë®µÆÐ§
 *		 2. ´ý¸Ä Ð´ÈÕÆÚÎÞ·¨¸Ä DD
 *
 *       V1.86    20190713 fenglong 20190713
 *       1. ÐÞÕý¿ª»úÁ÷Ë®µÆÐ§BUG
 *		 2. ´ý¸Ä Ð´ÈÕÆÚÎÞ·¨¸Ä DD
 *		 3. ¸ÄµçÑ¹²é±í,Ôö¼Ó10ÃëÑÓÊ±²é±í
 *
 *        V1.87    20190714 fenglong 20190714
 *       1. Ó¦¿Í»§ÒªÇóÏÖ³¡¸ü¸Ä¿ª»úÁ÷Ë®µÆÐ§ *
 *		 2. ´ý¸Ä Ð´ÈÕÆÚÎÞ·¨¸Ä DD
 *
 *         V1.88    20190714 fenglong 20190714
 *       1. Ó¦¿Í»§ÒªÇóÏÖ³¡¸ü¸ÄSOC²é±íÊ±¼ä
 *       2. ¼ÓÈëÈí¼þÒ»¼¶µÍÑ¹½øSHIPPING
 *		 2. ´ý¸Ä Ð´ÈÕÆÚÎÞ·¨¸Ä DD
 *
 *
 *
 */
//****************************************************************


//#include <msp430.h>
#include "System.h"
//#include "source/System.h"
#include"RS_485.h"
#include"uart.h"
#include"soft_soc.h"
//#include"string.h"

extern _BatteryData BatteryData;
extern UINT8 T0_INT_count;
uchar BQ_GetData_Delay =0;
uchar Powrer_On_Delay =0;
extern UINT16 CellMiniVoltage;
extern UINT16 CellMAXiVoltage;
extern UINT8 SystemMode;
extern  UINT16 Sleep_delay;
extern union FW_PF FW_PF_Status;        //  Èý¼¶±£»¤£¿
extern union FW_PT FW_PT_Status;               //CPU           Ò»¼¶±£»¤
extern unsigned char  power_first_flag;
UINT16 his_data[FLASH_DATA_NUM];
extern UINT16 BatteryCapacityRefreshCount;
#define FLASH_CHECK    0x55AA


void main(void)
{
	uchar i;
	unsigned short crc16;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	_nop ();
    SystemInitial ();

#ifndef UART_PRINTF

    Uart_State_Init();

#endif

    BatteryRealData_Refresh();


    CellMiniVoltage = 3200;
    CellMAXiVoltage = 3200;



    __bic_SR_register(  GIE);       // Enter LPM3 w/ interrupt
    for(i =0;i<FLASH_DATA_NUM;i++)
    {
    	his_data[i] = Flash_Read_int((unsigned int *)Segment_C,i);
    }
    crc16 =0;
    for(i=0;i<FLASH_DATA_NUM-1;i++)
    {
        crc16 += his_data[i];
    }
    if((crc16 == his_data[HIS_CRC16])&&(his_data[0] == FLASH_CHECK))
    {
        FW_PF_Status.Word = his_data[PF_STATE_ADDR];
        if(his_data[HIS_DSG_UVP_ADD])
        {
            FW_PT_Status.Bits.PT_UV = 1;
        }
        sys_cap.val.bat_cycle_cnt = his_data[FLASH_CYCLES_ADDR];              //fenglong 20190615
        sys_cap.val.chg_cap_cnt = (uchar)(his_data[CHG_CAP_CNT]) ;
    }
	else
	{
		for(i =0;i<FLASH_DATA_NUM;i++)
		{
			his_data[i] = Flash_Read_int((unsigned int *)Segment_D,i);
		}
		crc16 =0;
        for(i=0;i<FLASH_DATA_NUM-1;i++)
        {
            crc16 += his_data[i];
        }
		if((his_data[0] == FLASH_CHECK)&&(crc16 == his_data[HIS_CRC16]))
		{
			FW_PF_Status.Word = his_data[PF_STATE_ADDR];
			if(his_data[HIS_DSG_UVP_ADD])
            {
                FW_PT_Status.Bits.PT_UV = 1;
            }
			sys_cap.val.bat_cycle_cnt=his_data[FLASH_CYCLES_ADDR];                      //fenglong 20190615
			sys_cap.val.chg_cap_cnt = (uchar)(his_data[CHG_CAP_CNT]) ;
			Falsh_Write_Arr((unsigned int *)Segment_C,his_data,FLASH_DATA_NUM);         //fenglong 20190615
			//
		}
		else
		{
		    crc16 =0;
			his_data[0] = FLASH_CHECK;
			crc16 += his_data[0];
			for(i=1;i<FLASH_DATA_NUM-1;i++)
			{
				his_data[i] =0;
			}
			his_data[HIS_CRC16] = crc16;
			Falsh_Write_Arr((unsigned int *)Segment_C,his_data,FLASH_DATA_NUM);         //fenglong 20190615
			Falsh_Write_Arr((unsigned int *)Segment_D,his_data,FLASH_DATA_NUM);         //fenglong 20190615
			FW_PF_Status.Word =0;
			FW_PT_Status.Bits.PT_UV =0;
			sys_cap.val.bat_cycle_cnt=0;                                                //fenglong 20190615
			sys_cap.val.chg_cap_cnt = 0;

			his_data[HIS_Cell1MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell2MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell3MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell4MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell5MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell6MiniVoltage]=4200;                                        //fenglong 20190617
			his_data[HIS_Cell7MiniVoltage]=4200;                                        //fenglong 20190617

			his_data[HIS_Cell1MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell2MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell3MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell4MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell5MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell6MAXiVoltage]=0;                                        //fenglong 20190730
			his_data[HIS_Cell7MAXiVoltage]=0;                                        //fenglong 20190730

			his_data[HIS_MOSFET_MAXTEMP]=4000;
		}
	}

	__bis_SR_register(  GIE);       // Enter LPM3 w/ interrupt
	SystemMode = SystemSleepMode;
	if(sys_cap.val.bat_cycle_cnt < 1000)
	{
	    sys_cap.val.full_cap = 2500-sys_cap.val.bat_cycle_cnt;
	}

	BatteryData.TS2.TS2Word = 4000;
	BatteryData.TS1.TS1Word = 4000;

//	sys_cap.val.re_cap_rate =100;						//fenglong 20190713
//	sys_cap.val.bat_cap = sys_cap.val.full_cap;			//fenglong 20190713

	power_first_flag=0;			//fenglong 20190713
	BatteryCapacityRefreshCount = TA0_10s-TA0_2s ;		//fenglong 20190713

	while(1)
	{
	    WDTCTL = WDT_ARST_1000;             //fenglong 20190608

	    ReadKey();          //detect key

	    _nop ();

	    if(Powrer_On_Delay >30)
	    {
	        if(T0_INT_count>0)
	        {
                //PT_ProtectRenew();

                SystemStatusDetect();

                ProtectRenew();//状态保护

                AlarmDetect();
                ImbalanceCheck();
                MosfetDetect();

                MosStatusDetect ();//MOSFET工作切换
                balance();
                NormalCapacityProc();		//fenglong 20190729
                T0_INT_count =0;
                if (SystemMode != SystemBootUp)
                {
                    if(BQ_GetData_Delay %5 == 0)
                    {
                        Update_BQ_Data();
                        His_DataRenew();
                    }
                    BQ_GetData_Delay++;
                    if(BQ_GetData_Delay > 200)
                    {
                        BQ_GetData_Delay =0;
                        LoadFlashData (); //init BQ Data
                    }
                }
	        }

	    }
	    else
	    {
	    	Powrer_On_Delay++;
	    }
	    if(Powrer_On_Delay == 1)
	    {
	        LoadFlashData ();   //init BQ Data
	    }

        BatteryRealData_Refresh();

        RS485_REC_Task();

        SleepCheck();

        SleepMode();

	}
}




