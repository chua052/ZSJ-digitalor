#ifndef __MAIN_H__
#define __MAIN_H__



#define  MODBUS_RTU_NETMODE    1
#define  OFFSET				    0X2D000

#define Original_key    //����ʹ��ԭʼ��Կ


//��Ϊ�汾��ȡ��ע�ͣ�U����53u���㣬����汾����ע�ͣ�U����ʵ��Ϊ׼��
// #define HUAWEI_53U   //��Ϊ��˾�汾��53Uһ�ף�����53Uʱ����ģ���𻵣�

#define Red_OFF    //�ޱ�ǩʱ�����Ҳ��������ޱ�ǩ�����κεƣ�

#define _V3_3     //����V3.4��Ӳ�������ܶ���_V3_4 LED�������궨�����֣�  3.3��Ӳ������3.1���3.2�治���ݣ�ע�͵���ƥ��3.1��3.2��Ӳ��


#ifndef _V3_3       
	#define _53U
#endif


#ifdef _V3_3      //��3.3������������LED
	#define NEW_LED    //3.3��Ӳ�����������ε���ɫLED����λ��һ��
#endif


// #define _V3_4_LED   //����V3.4��LED

#ifdef _V3_4_LED      //
	#define NEW_LED    //3.4��Ӳ������LED��
#endif

#ifdef _V3_3      //��3.3����������RTC��·
	#define History_Event   //ʹ����ʷ��Ϣ����
#endif

#define OCCUPY_ALARM			//�Ƿ���ռλ������ʾ

#ifdef HUAWEI_53U
	#define Err_Report				//�Ƿ���ģ�����ϱ�
#endif

#define ONLINE_BLINK			//�Ƿ�����ǩ���߳���������˸

#define ONE_BEEPER				//һ���豸����һ����������ռλ����ҲӦ��������������



#define ERROR_TIME_LIMIT		10 		//(�ӻ�����Ӧ����)

#define TAG_MSG  0
#define ERR_MSG  1
#define LOAD_MSG  2
#define WEIGHT_MSG  3

#include <ctype.h>
//#include <absacc.h>
#include <string.h>
#include "stdlib.h"
//#include <intrins.h>
// #include "net.h"
#include "sys.h"
#include "spi.h"
#include "usart.h"
#include "stm32f10x_dbgmcu.h"





typedef char   			BOOL;		 //int8_t
typedef unsigned char	UCHAR;	  	 //uint8_t
typedef char    		CHAR;		 //int8_t
typedef unsigned short 	USHORT;		 //uint16_t
typedef short   		SHORT;		 //int16_t
typedef unsigned long 	ULONG;		 //uint32_t
typedef long    		LONG;		 //int32_t



// typedef unsigned char  				UCHAR;
typedef unsigned short int 			UINT;
// typedef unsigned int				ULONG;
// typedef unsigned int				LONG;


// #define Heartbt     400    //10S������

#define Heartbt     800    //20S������

#define Ack_Time    400   


#define HBTime      5
				
// #define    LED_Start_Reg   660   // 8�ֽ�ID�汾
#define    LED_Start_Reg   2000      // 16�ֽ�ID�汾


#define up 0
#define down 1

//#define    UploadMsg       0XA1    //�ϴ�U-WEI��Ϣ
//#define    UploadRackMsg   0XA3    //�ϴ�������Ϣ
//#define    ModiRkMsg       0XA5    //�޸Ļ�����Ϣ
//#define    ModiNetp        0XA7    //�޸��������
//#define    GetNetp         0XA9    //��ȡ�������
//#define    PcCtlLED        0XAB    //����LED��Ϣ
//#define    GetLedSta       0XAC    //��λ����ȡLED״̬
//#define    UploadTick      0XAD    //����������

//#define    GetTime         0XAF    //��ȡʱ��

//#define    GetHisMsg       0XB2    //��ȡ��ʷ�¼�

//#define    WriteTag        0XB5    //д��ǩ

//#define    UploadModuleErrMsg  0XB7    //�ϴ�ģ�������Ϣ

//#define    Upload_Pro_Msg  0xC1    //�ϴ���ά��U-WEI��Ϣ
//#define    UploadDownMsg   0XC3    //�ϴ��¼���Ϣ

////��������ָ��ȡ��
//#define    UploadWeightMsg     0xC5        //�ϴ����ذٷֱ�
//#define    UploadLoadMsg       0xC7    //�ϴ����ʸ��ɰٷֱ�


//#define    SetWK_PAR         0xC5    //����Ԥ��������

//#define    UploadWKMsg     0xC7    //�ϴ��¶ȵ�ʵʱ��Ϣ


//#define    Auth              0xC9    //��Ȩ
//#define    UnAuth            0xCB    //�����Ȩ

//#define    UnAuth_Operation   0xCD    //δ��Ȩ��ǩ���Ƴ�
//#define    Tag_Broken        0xCF    //��ǩ���ƻ�

//#define    To_Update         0XF0    //�·�����ָ��
//#define    Ready_To_Update   0XF2    //�ϴ��豸׼��������ָ��
//#define    Update_Pack       0XF4    //�·��������ݰ�

//#define    UNAUTH_TICK       (40*10) //10����


//#define    CtrBeep           0xD2     //���Ʒ�����





#define    UploadMsg       0XE1    //�ϴ�U-WEI��Ϣ
#define    UploadTick      0XE2    //����������
#define    UploadRackMsg   0XE3    //�ϴ�������Ϣ
#define    GetLedSta       0XE4    //��λ����ȡLED״̬
#define    GetTime         0XE5    //��ȡʱ��
#define    ModiRkMsg       0XE6    //�޸Ļ�����Ϣ
#define    CtrBeep         0xE7     //���Ʒ�����
#define    GetHisMsg       0XE8    //��ȡ��ʷ�¼�
#define    PcCtlLED        0XE9    //����LED��Ϣ


#define    ModbusRTU        0XEA    

//============����=======================================================================================
#define    ModiNetp        0XA7    //�޸��������
#define    GetNetp         0XA9    //��ȡ�������
#define    To_Update         0XF0    //�·�����ָ��
#define    Ready_To_Update   0XF2    //�ϴ��豸׼��������ָ��
#define    Update_Pack       0XF4    //�·��������ݰ�

//===========�޹�===============================================================================
#define    WriteTag        0XB5    //д��ǩ
#define    UploadModuleErrMsg  0XB7    //�ϴ�ģ�������Ϣ
#define    Upload_Pro_Msg  0xC1    //�ϴ���ά��U-WEI��Ϣ
#define    UploadDownMsg   0XC3    //�ϴ��¼���Ϣ
//��������ָ��ȡ��
#define    UploadWeightMsg     0xC5        //�ϴ����ذٷֱ�
#define    UploadLoadMsg       0xC7    //�ϴ����ʸ��ɰٷֱ�
#define    SetWK_PAR         0xC5    //����Ԥ��������
#define    UploadWKMsg     0xC7    //�ϴ��¶ȵ�ʵʱ��Ϣ
#define    Auth              0xC9    //��Ȩ
#define    UnAuth            0xCB    //�����Ȩ
#define    UnAuth_Operation   0xCD    //δ��Ȩ��ǩ���Ƴ�
#define    Tag_Broken        0xCF    //��ǩ���ƻ�


#define    UNAUTH_TICK       (40*10) //10����







#define PC_CTRL_BEEP_MODE   1
#define PC_CTRL_BEEP_CLOSE   255


extern uint16_t Send_UnAuth_Delay;
extern uint8_t To_Write_Auth;
extern uint8_t AuthenBuf[];
extern uint8_t UnAuthenBuf[];

extern uint16_t WK_Info_int;
extern uint16_t Set_Int;
extern uint16_t Total_Weight;
extern uint16_t Total_Power_Comsuption;
extern uint8_t UW_Hight[];
extern uint8_t Last_Up_Pos ;
extern uint8_t Last_Down_Pos;
extern uint8_t Curr_Slave_Data; //��¼������ǰ�洢�����ĸ��ӻ��ı�ǩ����
extern uint8_t Wait_Slave_Data;
extern uint8_t To_Send_Next[];
extern uint8_t Send_Times;
extern uint8_t Cur_Module;
// extern uint8_t IC_Data[14][48];

typedef __packed struct
{
	uint16_t Engage;               //���ε�ַд�����ݱ�ʶ
	uint16_t Year;		             // ��;
	uint8_t month;	               // ��
	uint8_t date;	                 // ��
	uint8_t hour;		               // ʱ
	uint8_t min;	                 // ��
	uint8_t second;	               // ��
	uint8_t UP_DOWN;               // ���߻�������
	uint8_t Msg[34];               // ��ǩ��Ϣ
}_Single_His;

typedef __packed struct          //��������
{	
	uint16_t Cur_Wt;               //��ǰ�ڼ��ʲ�������
	uint16_t Cur_Pr;               //��ǰ�ڼ��ʲ��ܹ���
	uint16_t Cur_Tp[9];           //��ǰ�����¶�	
}_Cur_Val;         

typedef __packed struct          //��������
{
	uint16_t Time_Int;             //��Ϣ�ϴ����ʱ��
	
	uint16_t Al_Wt;                //����������
	uint16_t War_Wt;		           //Ԥ��������
	
	uint16_t Al_Pr;	               //�����ܹ���
	uint16_t War_Pr;	             //Ԥ���ܹ���
	
	uint16_t Al_Tp;                //��������¶�
	uint16_t War_Tp;		           //Ԥ���¶�
	
	_Cur_Val Current_Val;          //��ǰֵ
	
}_WK_Par;                        



// extern _Single_His Single_His[24];

// typedef __packed struct
// {
// 	uint32_t Store;
// 	_Single_His Single_His[24];
// }_His_Page;



typedef __packed struct
{
	uint8_t Header[2];		        // ��ʼ�� ���ֽ�0xfe;
	uint8_t Datlen[2];	          // �������ݳ���
	uint8_t COM[1];	              // ������
	uint8_t VerNo[2];             // �豸�汾��
	uint8_t ID[4];                // �豸ID
	uint8_t DatTR[800];          // �շ����� 
}TCPDat;



typedef  __packed struct
{
	uint8_t SN[32];
	uint8_t UW_High[1];		
	uint8_t Location[32];
	uint8_t Building[32];
	uint8_t Storey[8];
	uint8_t Room[8];
	uint8_t Row[8];
	uint8_t Rack_No[16];
	uint8_t Description[32];
	uint8_t Manufacturer[16];
	uint8_t Serial_No[16];
	uint8_t Vendor[16];
	uint8_t MAC1[6];
	uint8_t MAC2[6];
	uint8_t Life_circle[8];
	uint16_t Weight;
	uint8_t Maintenance_cycle[8];
	uint8_t Person_in_charge[16];
	uint8_t Service_Contact[48];
	uint8_t Device[32];
	uint8_t Device_Class[16];
	uint8_t Inventory_Code[32];
	uint16_t Power_Consumption;
	uint16_t Current_Rating;
	uint16_t Rated_voltage;
	uint8_t Last_Service[48];
	uint8_t Next_Service[48];
	uint8_t Last_Update[16];
	uint8_t Next_Update[16];	
	uint8_t First_commissioned[16];
	uint8_t Additional[131];
	uint8_t Supervisory;//��� ���Ϊ1��ǩ���߻ᱨ��
	//����˫������߼��
	
	
	
}TagDaT;


typedef __packed struct
{
	uint8_t UW_High[6];		        // 20151120  �ɼ���Ϣ�У��ύ�ʲ�ռ��Uλ�߶�
	uint64_t CardID[6][2];	    //����  20151102 HW��Ҫ21��������ĸ��ϣ��ʸ�Ϊ32�ֽ��Զ��忨��
	uint64_t CardID_EXT[6][2];	//����	20151102 HW��Ҫ21��������ĸ��ϣ��ʸ�Ϊ32�ֽ��Զ��忨��
}ReaderDaT;

typedef __packed struct
{
	uint8_t  UW_Num;		   //40020 L
	uint8_t  UW_High;		   //40020 H
	uint64_t RFID_ID[2];		   //40021 - 40014
	uint64_t RFID_ID_EXT[2];  //20150727����ID��չΪ16�ֽڣ�ASCII���ʾ
														//20151102����ID��չΪ32�ֽڣ�ASCII���ʾ
}UW_DaT;

typedef __packed struct
{
	uint16_t Vision;		//40001 		�汾��
	uint32_t ControlID;		//40002 - 40003 ������ID
	uint16_t RS485_Addr;	//40004 		��ַ
	uint8_t  UW_Count;		//40005 L 		Uλ����
	uint8_t  MK_Count;		//40005 H 		ģ������
	uint16_t UW_Updata;		//40006 		Uλ���ݱ仯����
	uint8_t  UW_Num;		//40007 L		Uλ��
	uint8_t  UW_High;		//40007 H		Uλ�߶�
	uint64_t RFID_ID[2];		//40008 - 40011 ���һ�α仯RFID��ǩID
	uint64_t RFID_ID_EXT[2];  //20151102����ID��չΪ32�ֽڣ�ASCII���ʾ
	uint16_t UW_Up[8];		//40012 - 40019 1-128Uλ�ϼ���Ϣ
	uint8_t  UW_DaStart;	//40020			Uλ��Ϣ��ʼλ
}RTU_DaT;


// typedef __packed struct
// {
// 	uint16_t u16_HL[1024];
// }SWAP_DaT;


// typedef union 
// {
// 	__IO uint8_t u8Dat;
// 	struct 
// 	{
// 		__IO uint8_t Bit0:1;	//
// 		__IO uint8_t Bit1:1;	//
// 		__IO uint8_t Bit2:1;	//
// 		__IO uint8_t Bit3:1;	//
// 		__IO uint8_t Bit4:1;	//
// 		__IO uint8_t Bit5:1;	//
// 		__IO uint8_t Bit6:1;	//
// 		__IO uint8_t Bit7:1;	//
// 	} Dat_Bit;
// } Dat_UN;


#define LED_On				0x01		//LED�Ʒ���
#define LED_Off				0x00		//LED�ƹر�

#define LED_Quit			0x00		//LED�˳�����
#define LED_Close			0x01		//LED�ر�
#define LED_At_Blue			0x02		//LEDһֱ����
#define LED_At_Red			0x03		//LEDһֱ���
#define LED_At_R_B			0x04		//LEDһֱ������
#define LED_Fl_Blue			0x05		//LED������˸
#define LED_Fl_Red			0x06		//LED�����˸
#define LED_Fl_R_B			0x07		//LED��������˸

#define LED_At_Green		0x08		//LEDһֱ�̵�
#define LED_At_R_G		  0x09		//LEDһֱ���̵�
#define LED_At_B_G      0x0A		//LEDһֱ���̵�
#define LED_At_ALL			0x0B		//LEDһֱȫ��
#define LED_Fl_Green		0x0C		//LED�̵���˸
#define LED_Fl_R_G			0x0D		//LED���̵���˸
#define LED_Fl_B_G			0x0E		//LED���̵���˸
#define LED_Fl_ALL			0x0F		//LEDһֱȫ��


//20150304
//#define Sys_GetSlCnt_Dly	200			//25ms*200=5s
#define Sys_GetSlCnt_Dly	10			//25ms*10=250MS
#define Sys_UW_Count		6			//Ĭ����6Uλ
// #define Sys_MK_Count		8			//���֧������ģ������
#define Sys_MK_Count		9			//���֧������ģ������  20151123




// #ifdef HUAWEI_53U	
// 	#define Sys_Vision			0x3508		//�汾8 20160902  //���ֽ�53��ʾ53U�汾��HW����
// // 	#define Sys_Vision			0x3614		//���԰汾
// #else
// 	#define Sys_Vision			0x2A08		//�汾8 ��ɳ��������V2A08�汾��
// #endif

#define Sys_Vision			0x2A64   //Pro�棬�汾��64

/***************** IO�ڶ��� **********************/
/*485����ʹ�ܹܽŶ���*/
#ifdef  _V3_3
	#define IO_EN485_1		GPIO_Pin_6		//PB.6
	#define IO_EN485_2		GPIO_Pin_1		//PA.1
	#define IO_EN485_3		GPIO_Pin_1		//PB.1	
#else   //3.1��3.2��Ӳ��
	#define IO_EN485_1		GPIO_Pin_8		//PB.8
	#define IO_EN485_2		GPIO_Pin_1		//PA.1
	#define IO_EN485_3		GPIO_Pin_1		//PB.1
#endif	


//===ͨ��595�л�
// /*HRF-SW1030 RF�л��ܽŶ���*/
// #define IO_SW1030_C0	GPIO_Pin_7		//PB.7
// #define IO_SW1030_C1	GPIO_Pin_8		//PB.8
// #define IO_SW1030_C2	GPIO_Pin_9		//PB.9

#ifdef NEW_LED
	/*LED�� �ܽŶ���*/
	#ifdef _V3_4_LED
		#define LED1_Blue	  5	  // ���--����1
		#define LED1_Red	  4	  // ���--����1
		#define LED1_Green	6	  // ���--����1
		
		#define LED2_Blue	  8	  // ���--����2
		#define LED2_Red	  7	  // ���--����2
		#define LED2_Green	9	  // ���--����2
		
		#define LED3_Blue	  11	// ���--����3
		#define LED3_Red	  10	// ���--����3
		#define LED3_Green	12	// ���--����3
		
		#define LED4_Blue	  14	// ���--����4
		#define LED4_Red	  13	// ���--����4
		#define LED4_Green	15	// ���--����4
		
		#define LED5_Blue	  17	// ���--����5
		#define LED5_Red	  16  // ���--����5
		#define LED5_Green	18	// ���--����5
		
		#define LED6_Blue	  20	// ���--����6
		#define LED6_Red	  19	// ���--����6
		#define LED6_Green	21	// ���--����6
	#else
		#define LED1_Blue	  6	  // ���--����1
		#define LED1_Red	  4	  // ���--����1
		#define LED1_Green	5	  // ���--����1
		
		#define LED2_Blue	  9	  // ���--����2
		#define LED2_Red	  7	  // ���--����2
		#define LED2_Green	8	  // ���--����2
		
		#define LED3_Blue	  12	// ���--����3
		#define LED3_Red	  10	// ���--����3
		#define LED3_Green	11	// ���--����3
		
		#define LED4_Blue	  15	// ���--����4
		#define LED4_Red	  13	// ���--����4
		#define LED4_Green	14	// ���--����4
		
		#define LED5_Blue	  18	// ���--����5
		#define LED5_Red	  16  // ���--����5
		#define LED5_Green	17	// ���--����5
		
		#define LED6_Blue	  21	// ���--����6
		#define LED6_Red	  19	// ���--����6
		#define LED6_Green	20	// ���--����6	
	#endif
#else
	/*LED�� �ܽŶ���*/
	#define LED1_Blue	  4	  // ���--����1
	#define LED1_Red	  5	  // ���--����1
	#define LED1_Green	6	  // ���--����1
	#define LED2_Blue	  7	  // ���--����2
	#define LED2_Red	  8	  // ���--����2
	#define LED2_Green	9	  // ���--����2
	#define LED3_Blue	  10	// ���--����3
	#define LED3_Red	  11	// ���--����3
	#define LED3_Green	12	// ���--����3
	#define LED4_Blue	  13	// ���--����4
	#define LED4_Red	  14	// ���--����4
	#define LED4_Green	15	// ���--����4
	#define LED5_Blue	  16	// ���--����5
	#define LED5_Red	  17  // ���--����5
	#define LED5_Green	18	// ���--����5
	#define LED6_Blue	  19	// ���--����6
	#define LED6_Red	  20	// ���--����6
	#define LED6_Green	21	// ���--����6
#endif



#define	IO_HC595_SCK	GPIO_Pin_5
#define	IO_HC595_OE   GPIO_Pin_3
#define	IO_HC595_SDI	GPIO_Pin_15
#define	IO_HC595_RCK	GPIO_Pin_4



/***************** IO����������� **********************/
/*485����ʹ�ܹܽŶ���*/
//�Ѹ�
#ifdef  _V3_3
	#define EN485_1		PBout(6)	// ���--RS485������
	#define EN485_2		PAout(1)	// ���--RS485������
	#define EN485_3		PBout(1)	// ���--RS485������
#else   //3.1��3.2��Ӳ��
	#define EN485_1		PBout(8)	// ���--RS485������
	#define EN485_2		PAout(1)	// ���--RS485������
	#define EN485_3		PBout(1)	// ���--RS485������
#endif


#ifdef  _V3_3
	/*�Ÿ�Ӧ������� �ܽŶ���*/
//	#define IO_Tout1		GPIO_Pin_13		//PC.13
	#define IO_Tout1		GPIO_Pin_9		//PC.13
	#define IO_Tout2		GPIO_Pin_9		//PB.9
	#define IO_Tout3		GPIO_Pin_8		//PB.8
	#define IO_Tout4		GPIO_Pin_7		//PB.7
	#define IO_Tout5		GPIO_Pin_12	  //PA.12
	#define IO_Tout6		GPIO_Pin_11		//PA.11
	/*�Ÿ�Ӧ������� �ܽŶ���*/
//	#define Tout1		PCin(13)		// ����--�Ÿ�Ӧ��1
	#define Tout1		PCin(9)		// ����--�Ÿ�Ӧ��1
	#define Tout2		PBin(9)		  // ����--�Ÿ�Ӧ��2
	#define Tout3		PBin(8)		  // ����--�Ÿ�Ӧ��3
	#define Tout4		PBin(7)		  // ����--�Ÿ�Ӧ��4
	#define Tout5		PAin(12)	  // ����--�Ÿ�Ӧ��5
	#define Tout6		PAin(11)	  // ����--�Ÿ�Ӧ��6
#else   //3.1��3.2��Ӳ��
	//�Ѹ�
	/*�Ÿ�Ӧ������� �ܽŶ���*/
	#define IO_Tout1		GPIO_Pin_13		//PC.13
	#define IO_Tout2		GPIO_Pin_14		//PC.14
	#define IO_Tout3		GPIO_Pin_15		//PC.15
	#define IO_Tout4		GPIO_Pin_9		//PB.9
	#define IO_Tout5		GPIO_Pin_12	  //PA.12
	#define IO_Tout6		GPIO_Pin_11		//PA.11

	//�Ѹ�
	/*�Ÿ�Ӧ������� �ܽŶ���*/
	#define Tout1		PCin(13)		// ����--�Ÿ�Ӧ��1
	#define Tout2		PCin(14)		// ����--�Ÿ�Ӧ��2
	#define Tout3		PCin(15)		// ����--�Ÿ�Ӧ��3
	#define Tout4		PBin(9)		  // ����--�Ÿ�Ӧ��4
	#define Tout5		PAin(12)	  // ����--�Ÿ�Ӧ��5
	#define Tout6		PAin(11)	  // ����--�Ÿ�Ӧ��6
#endif




#define	Bell_ON             Dat_Lth&=(~(1<<0))
#define Bell_OFF          	Dat_Lth|=(1<<0)  


// #define E_self_addr			0		//������ַ
// #define E_rs485_mode		1		//485ͨ��ģʽ��0������1������������
// #define E_logo_mode			2		//Logo��ʾģʽ��0--Ĭ�ϣ�1--�Զ���
// #define E_wgbits			3		//Τ��λ����26/34/66
// #define E_english_week		4		//Ӣ��������ʾ
// #define E_cal_mode			5		//�㷨ģʽ��0--���ܣ�1--3DES
// #define E_Lenth				0x06	//��������



/* ----------------------- Holding register Defines ------------------------------------------*/

// #define REG_HOLDING_START_1 0001
// #define REG_HOLDING_NREGS_1 847           //(48U 16�ֽڰ汾)

// #define REG_HOLDING_START_2 2001
// #define REG_HOLDING_NREGS_2 48            //(48U 16�ֽڰ汾)

// #define REG_HOLDING_START_3 3001
// #define REG_HOLDING_NREGS_3 7            //(IP��ַ���������롢Ĭ�����ء��˿ں�)

//====20151123  53U�汾
#define REG_HOLDING_START_1 0001

// #define REG_HOLDING_NREGS_1 949           //(53U 32�ֽڰ汾 ʵ�ʸ���54U�Ĵ�����Χ )

#define REG_HOLDING_NREGS_1 30

#define REG_HOLDING_START_2 2001
#define REG_HOLDING_NREGS_2 54            //(53U 32�ֽڰ汾  ʵ�ʸ�54��U��LED)

#define REG_HOLDING_START_3 3001
#define REG_HOLDING_NREGS_3 10            //(IP��ַ���������롢Ĭ�����ء��˿ںŵ�)

#define REG_HOLDING_START_4 3201
#define REG_HOLDING_NREGS_4 100            //(���籣����������)


/* ----------------------- input register Defines ------------------------------------------*/
#define REG_INPUT_START 0000
#define REG_INPUT_NREGS 16

/* ----------------------- coils register Defines ------------------------------------------*/
#define REG_COILS_START     0000
#define REG_COILS_SIZE      16

/* ----------------------- discrete register Defines ------------------------------------------*/
#define REG_DISC_START     0000
#define REG_DISC_SIZE      16


#ifdef Err_Report
extern uint8_t Err_Time[];
#endif

extern uint8_t moni_alm;
extern uint8_t Monitor_ALM[];
extern uint16_t UW_Weight[];
extern uint16_t UW_Power[];
extern uint8_t Store[];
extern uint8_t Up_Send_Flag[];
extern TagDaT TagData[];
extern uint8_t ReREAD_Slave_TAG;
extern uint8_t Reboot_Slave_Flag;
extern uint32_t Colour_Light_Ticks;
//extern uint16_t Interval ;
extern uint32_t Interval  ;

extern uint8_t SyncLed;
// extern _His_Page His_Page[3];
extern uint8_t LINK_ESTABLISHED;
extern uint8_t link;
extern uint16_t  His_ONLine[];
extern uint8_t Link_First;
extern uint16_t PowerUpTime;
extern uint8_t Stop_Colour_Light;
extern uint8_t HeartbeatTime;
extern uint8_t Wait_ACK[];
extern uint16_t Ack_Tick[] ;
extern uint8_t NO_SLAVE;
extern uint16_t Heartbeat_packet; 

// extern uint8_t TcpSendBuf[];

extern _WK_Par WK_Cur_Val;  //����ֵ����ǰֵ
extern TCPDat *pTCPDa;
extern uint8_t First_Send;
extern uint16_t fifo_pop_delay;
// extern uint16_t Up_BAK[8];  //20151203  �����ϼ���Ϣ���б仯�������ϱ� 
// extern uint16_t Up_BAK_OLD[8];  //20151203  �����ϼ���Ϣ���б仯�������ϱ�
extern uint32_t No_Connection_Tick;
// extern uint8_t LedCtl_InProcess;
extern uint8_t Host_Addr;			//������ַ
extern uint8_t Slave_Addr;			//�ӻ���ַ
// extern uint8_t SlaveCnt;			//�ӻ�����
extern uint8_t UW_Cnt;				//Uλ����
extern uint8_t UW_Sta;				//Uλ״̬
// extern uint8_t Sys_Para[];
extern uint8_t GetDat_Pos;			//�л���ȡ����
extern uint8_t GetLed_Sta;      //�л���ȡLED״̬
extern uint8_t TrsLed_Sta;      //�л��·�LED״̬

// extern uint8_t Response_Delay;

extern volatile ReaderDaT ReaderDa[];
// extern uint16_t Tim_GetSlCnt_Dly;	//��ȡ�ӻ�������ʱ

extern RTU_DaT *pRTU_Da;
extern UW_DaT *pUW_Da;
extern uint8_t Sys_UW_Cnt[];		//ϵͳ�ӻ�Uλ����
extern uint8_t Sys_UW_Num[];		//ϵͳUλ�߶�
extern uint8_t Sys_MK_Cnt_New;		//ϵͳģ����������
extern uint8_t Sys_MK_Cnt_Old;		//ϵͳģ���ϴ�����
extern uint8_t Sys_UW_Sta_New[];	//ϵͳUλ����״̬
extern uint8_t Sys_UW_Sta_Old[];	//ϵͳUλ�ϴ�״̬
extern uint32_t Sys_SerialNum;		//ϵͳ���к�
extern uint16_t Sys_RS485Addr;		//ϵͳRS485��ַ
extern uint8_t Ud_UW_Num;			//����һ��Uλ��
extern uint8_t Ud_UW_High;			//����һ��Uλ�߶�
extern uint64_t Ud_RFID_ID[2];			//����һ��RFID��ǩID
extern uint64_t Ud_RFID_ID_EXT[2];			//����һ��RFID��ǩID��չ8�ֽ�
extern uint16_t Ud_UW_Updata;		//Uλ���ݱ仯����

// extern uint8_t ReadDaCnt[6];			//��ȡ���ݴ���
extern uint8_t SenFlag[6];				//�Ÿ�Ӧ��־1~6
extern uint8_t RdFlag[6];				  //�Ѷ�����־1~6
extern uint8_t WtFlag[6];         //��дȨ�ޱ�־1~6
extern uint8_t UpFlashFg[6];			//�������Ʊ�־1~6
extern uint8_t DnFlashFg[6];			//�������Ʊ�־1~6
extern uint8_t DyFlashFg[6];			//��̬���Ʊ�־1~6
extern uint8_t FlashVal[6];				//����ֵ1~6
extern uint8_t UpFlashDly[6];			//�������������ʱ

extern uint8_t DnFlashDly[6];			//�������������ʱ		//20140808

extern uint8_t DyFlashDly[6];			//��̬���������ʱ
extern uint8_t DyFlashPos[6];			//��̬����ƺ�
extern uint8_t DyFlashClr[6];			//��̬�������ɫ

extern uint8_t Tim_IWDG_Cnt;			//���Ź�ι����ѯ������
extern uint8_t Tim_Read_Cnt;			//����ѭ��������
extern uint8_t Tim_Check_Cnt;		//���Ÿ�Ӧ������
extern uint8_t Tim_Flash_Cnt;		//�������������
extern uint8_t Tim_GetCd_Cnt;		//��ȡ��λ�����ݼ�����
extern uint8_t Tim_SetAd_Cnt;		//������λ����ַ������




// extern uint16_t power_up;
extern uint8_t LED_STATUS[];

extern uint8_t LED_STATUS_DOWNLOAD[];

extern uint32_t Dat_Lth;
extern uint8_t UnitResponse;

// // ����Ĵ�������
// extern uint16_t usRegInputBuf[REG_INPUT_NREGS];
// // �Ĵ�����ʼ��ַ
// uint16_t usRegInputStart = REG_INPUT_START;
// ���ּĴ�������
extern uint16_t usRegHoldingBuf1[REG_HOLDING_NREGS_1] ;
// extern uint16_t usRegHoldingBuf2[REG_HOLDING_NREGS_2] ;
extern uint16_t usRegHoldingBuf3[REG_HOLDING_NREGS_3] ;

extern uint16_t usRegHoldingBufBkp3[REG_HOLDING_NREGS_3] ;

// // // ���ּĴ�����ʼ��ַ
// // uint16_t usRegHoldingStart = REG_HOLDING_START;
// // ��Ȧ״̬
// extern uint8_t ucRegCoilsBuf[REG_COILS_SIZE / 8] ;
// // ����״̬
// extern uint8_t ucRegDiscBuf[REG_DISC_SIZE / 8] ;

void read_Para(void);
void Save_Para(void);
void read_card(uint8_t reader_pos);
void FlashLight(uint8_t LightPos, uint8_t LightColor);
void Write_Autn(uint8_t reader_pos,uint8_t auth);
void Send_HeartBeat(void);
uint8_t Cal_bit1(uint8_t t);
uint8_t Cal_Pos(uint8_t U_Num);







#define RST_NET_IO		GPIO_Pin_0		
#define ID_Bus_IO		GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | \
						GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15						
#define ID_GPIO			GPIOB
#define RST_NET			PAin(0)	// PA0���� 

#define Big2Little16(A)  ((((u16)(A) & 0xff00) >> 8) | \
                                 (((u16)(A) & 0x00ff) << 8))

#define Big2Little32(A)  ((((u32)(A) & 0xff000000) >> 24) | \
                                  (((u32)(A) & 0x00ff0000) >> 8) | \
                                  (((u32)(A) & 0x0000ff00) << 8) | \
                                  (((u32)(A) & 0x000000ff) << 24))

#define Little2Big16(A)  ((((u16)(A) & 0xff00) >> 8) | \
                                 (((u16)(A) & 0x00ff) << 8))

#define Little2Big32(A)  ((((u32)(A) & 0xff000000) >> 24) | \
                                  (((u32)(A) & 0x00ff0000) >> 8) | \
                                  (((u32)(A) & 0x0000ff00) << 8) | \
                                  (((u32)(A) & 0x000000ff) << 24))

#define CACHESIZE			2	// 10 ARP cache
#define CACHETIME			20	// expiration time = 20 minutes. 60 second intervals
#define ARP_TIMEOUT	 		4	// Allow 2 seconds to receive an ARP reply, 0.5 second intervals
#define MAC_LEN				6
#define IP_LEN				4

//==========falsh��ص�ַ����==================
#define STM32_FLASH_SIZE 	256 	 		//��ѡSTM32��FLASH������С(��λΪK)
#define STM_SECTOR_SIZE		2048 			//ÿҳ�����ֽ�

#define		STM32_FLASH_BASE		0x08000000 		//STM32 FLASH����ʼ��ַ    0x08000000  - 0x0803 FFFF
													//  0x08000000  - 0x0803 C000   Ԥ��240k�Ŵ���    �����ռ�  0x803C000  - 0x0803 FFFF   ʣ��8ҳ��ÿҳ2k

//==W5500���==   Ԥ��һҳ�ռ䣬2048�ֽ�    0x0803C000   -  0x0803C7FF
//#define		W5500_MAC			0x0803C000      //BB-BB-CC-CC-DD-DD
//#define		W5500_LOCAL_IP		0x0803C01A		//192.168.0.178     0xC0 A8 00 B2
//#define		W5500_GW_IP			0x0803C02A		//192.168.0.1		
//#define		W5500_SUB			0x0803C03A		//255.255.0.0
//#define		W5500_DNS			0x0803C04A		//8.8.8.8

#define		W5500_MAC			0x0803C010      //BB-BB-CC-CC-DD-DD
#define		W5500_LOCAL_IP		0x0803C016		//192.168.0.178     0xC0 A8 00 B2
#define		W5500_GW_IP			0x0803C01A		//192.168.0.1		
#define		W5500_SUB			0x0803C01E		//255.255.0.0
#define		W5500_DNS			0x0803C023		//8.8.8.8

//==��־��Ϣ==    200����ͨ���棬200����������  

//��־��Ϣ������ʼ��ַ��170����־����ͨ���棬ÿ���б仯������һ����־��Ϣ�����ڴ˲��ֿռ�
#define LOG_cache_ADDR          0x0803C800	//0x0803C800   - 0x0803CFFF һҳ�ռ�

//��־��Ϣ������ʼ��ַ��170����־������ʱ����־���浽������ÿ��������������ɹ���Ҫ�ȶ�ȡ�˲��ֿռ�
#define LOG_backup_ADDR         0x0803D000   //0x0803D000   - 0x0803D7FFF




//u8 FlashWriteData(u32 WriteAddr,const u8 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
u8 FlashReadData(u32 ReadAddr,u8 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

/*************************************************************************************/

/*********************************************************************
�����������	�������Ͷ���
*********************************************************************/
typedef struct			 					
{
	UCHAR StartFlag;				//Ԥ��λ	1  Ĭ��:
	UCHAR SetupHead_buf[32];		//������	16 Ĭ��:0x55 0xAA
//	UCHAR SetupFalg_buf[16];		//��־��	16 Ĭ��:0xff
	UCHAR Name_len;					//��������	1  Ĭ��:5
	UCHAR Name_buf[15];				//��������	15 Ĭ��:host1 
	UCHAR IP_mode;					//ip ģʽ  	1  Ĭ��:0
	UCHAR MAC_Local_buf[6]; 		//����MAC	6  Ĭ��:00-AB-CC-65-DE-AA
	UCHAR IP_Local_buf[4];			//���� IP	4  Ĭ��:192.168.1.111 
	UCHAR Sub_Mask_buf[4];			//��������	4  Ĭ��:255.255.255.0
	UCHAR Gate_Way_buf[4];			//Ĭ������	4  Ĭ��:192.168.1.1 
	UCHAR IP_Remote_buf[4];			//Զ�� IP	4  Ĭ��:192.168.1.100 
	UINT  Port_Local;				//���ض˿�	2  Ĭ��:50000
	UINT  Port_Remote;				//Զ�̶˿�	2  Ĭ��:50000
	UCHAR Reserve_buf[64];			//Ԥ���ֽ�  64
	UCHAR Baud_Select;				//������	1
	UCHAR VerCode_buf[7];			//�����汾	7
	UINT  Check_Sum;				//У���ֵ	2 =150(��)
}Setup_Parameter;

extern Setup_Parameter NetParameter;

#define FLASH_FLAG_NUM      	10      // ��־��ռ�ֽ���Ϊ10���ֽ� 
#define NET_PARA_LEN        	150     // ��������
#define END_PARA              141		// 300 ��������
#define CONFIG_PORT     		  65534   // �㲥���ö˿�

//ԭDM9000AEP����оƬ�²���
// /****************** (IP����)���ñ�����Ϣλ��*************************/
// #define UDP_DATA_START  		28      /* 28 = 20(IPͷ) + 8(UDPͷ) */
// #define COMMAND_START_ADDR      60      /* ���ñ�������λ�� */
// #define SAVE_OK                 61      /* ����ɹ� */
// #define EQUNAME_LEN             61      /* 1���ֽ�,���ֳ��� */
// #define EUQ_NAME                62      /* 15���ֽ���Ϊ���ֿռ� */
// #define IP_MODE                 77      /* 1���ֽ�,IPģʽ */
// #define MAC_ADDR                78      /* 6���ֽ�,MAC��ַ */
// #define IP_ADDR                 84      /* 4���ֽ�,����IP��ַ */
// #define NET_MASK                88      /* 4���ֽ�,�������� */
// #define GATE_WAY                92      /* 4���ֽ�,���� */
// #define REMOTE_IPADDR1          96      /* 4���ֽ�,Զ��IP1 */
// #define LOCAL_PORT1             100     /* 2���ֽ�,���ض˿ں� */
// #define REMOTE_PORT1            102     /* 2���ֽ�,Զ�̶˿ں�1 */


//��W5500оƬ�²���
/****************** (IP����)���ñ�����Ϣλ��*************************/
#define UDP_DATA_START  		28      /* 28 = 20(IPͷ) + 8(UDPͷ) */
#define COMMAND_START_ADDR      32      /* ���ñ�������λ�� */
// #define SAVE_OK                 61      /* ����ɹ� */

#define EQUNAME_LEN             33      /* 1���ֽ�,���ֳ��� */


// #define EUQ_NAME                62      /* 15���ֽ���Ϊ���ֿռ� */
// #define IP_MODE                 77      /* 1���ֽ�,IPģʽ */
#define MAC_ADDR                50      /* 6���ֽ�,MAC��ַ */
// #define IP_ADDR                 84      /* 4���ֽ�,����IP��ַ */
// #define NET_MASK                88      /* 4���ֽ�,�������� */
// #define GATE_WAY                92      /* 4���ֽ�,���� */
// #define REMOTE_IPADDR1          96      /* 4���ֽ�,Զ��IP1 */
// #define LOCAL_PORT1             100     /* 2���ֽ�,���ض˿ں� */
// #define REMOTE_PORT1            102     /* 2���ֽ�,Զ�̶˿ں�1 */



// /* ����64���ֽ� */
// #define BAUND_RATE              168     /* 1���ֽ�,������ */

/* ����64���ֽ� */
//20160831   ���沨���ʲ���ʹ��
#define BAUND_RATE              107     /* 1���ֽ�,������ */

/* ����32���ֽ� */
#define RUN_DAYS                201     /* 2���ֽ�,�������� */
#define RUN_HOURS               203     /* 1���ֽ�,Сʱ�� */
#define RUN_MINUTES             204     /* 1���ֽ�,������ */
#define RUN_SECONDS             205     /* 1���ֽ�,���� */
#define UDP_RCV_BYTES           206     /* 4���ֽ�,UDP�����ֽ��� */
#define UDP_SEND_BYTES          210     /* 4���ֽ�,UDP�����ֽ��� */
#define UART_RCV_BYTES          214     /* 4���ֽ�,���ڽ����ֽ��� */
#define UART_SEND_BYTES         218     /* 4���ֽ�,���ڷ����ֽ��� */
#define UART_RCV_SOFT_OVERFLOW  222     /* 4���ֽ�,���ڽ���������� */
#define UART_SEND_SOFT_OVERFLOW 226     /* 4���ֽ�,���ڷ���������� */
#define HARD_SOFT_EIDTION       230     /* 7���ֽڰ汾��,ASCII�� */
/* ����100���ֽ� */

/******************* PC �������� ************************************/
#define BROADCAST_SEARCH        0x00                /* �㲥���� */
#define CONFIG_REQUEST          0x02                /* �������� */
#define SAVE_NET_CONFIG         0x04                /* ������������ */
#define REFLESH_STATISTIC       0x06                /* ˢ��ͳ����Ϣ */
#define CLEAR_STATISTIC         0x08                /* ����ͳ����Ϣ���� */
#define RESET_SYSTEM            0x0A                /* ��λϵͳ */
#define CHANGE_MAC_ADDR			0xA4				/* ���� MAC ��ַ */
/******************* �ظ� PC ���� **********************************/
#define REPLY_BROADCAST         0x01                /* �㲥������Ӧ */
#define REPLY_CONFIG            0x03                /* ���������Ӧ */
#define REPLY_SAVE_NETCONFIG    0x05                /* �����������û�Ӧ */
#define REPLY_FLESH             0x07                /* ˢ��Ӧ�� */
#define REPLY_CLEAR_STATISTIC   0x09                /* ����ͳ����ϢӦ�� */
#define REPLY_CHANGE_MAC_ADDR	0xA5				/* ���� MAC ��ַ */
//********************************************************************


extern UCHAR debug;						//=1����������������
extern UCHAR Sending;
extern UCHAR RxBegin;
extern UCHAR RxDelay;
extern UINT  RxDataCnt;
extern UINT  TxDataCnt;
// extern UINT  Com_Send_Len;
// extern UINT  Com_Recv_Len;
// extern UCHAR Com_Recv_Buf[];
// extern UCHAR Com_Send_Buf[];

extern UCHAR bc_mac[]; 
extern UCHAR my_mac[];
extern ULONG my_ipaddr;
extern ULONG my_subnet;
extern ULONG gw_ipaddr;
extern ULONG remote_ip;
extern UINT  remote_port;
extern UINT  self_port;

extern UCHAR rx_Packet_data[];
extern UCHAR tx_Packet_data[];

extern UINT times_3s;
extern UINT  RandCnt;			//�����������������


extern UCHAR arpbuf[];
extern ULONG initial_sequence_nr;
extern UCHAR volatile event_word;
// extern WAIT  wait;
// extern CONNECTION conxn[];
// //extern char  html_header[];
// //extern char  web_page[];
// //extern char  jpeg_header[];
// //extern UCHAR photo1_jpeg[];
// //extern UCHAR BaudRate_buf[8];
// extern ARP_CACHE arp_cache[CACHESIZE];

// extern u16 Com_Recv_Len;
// extern u16 Com_Send_Len;
// extern u8  Com_Recv_Buf[RECV_MAX];
// extern u8  Com_Send_Buf[SEND_MAX];



// void InitSerial(void);
void InitPara(void);

//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);				//�����жϽ���
void serial_send(UCHAR *base);				//
void udp_to_rs232(UCHAR *base, UINT size);	//
void rs232_to_udp(void);
void send_data(u8 *outdata, u16 size);

void IOWR(UCHAR Channel, UCHAR OutData);
UCHAR IORD(void);


int FlashCheck(void);
void FlashInit(void);
void ResetSystem(void);
void init_arp(void);			//��ʼ��ARP
// UINT cal_crc(UCHAR *ptr, UINT len);
// UINT cksum(UCHAR *check, UINT length); //����У���


UCHAR rcve_frame(void);
void send_frame(UCHAR *, UINT);
void eth_rcve(UCHAR *);
void eth_send(UCHAR *, UCHAR *, UINT, UINT);
void ip_send(UCHAR *, ULONG, UCHAR, UINT);
void config_ip_send(UCHAR *, ULONG, UCHAR, UINT);
void ip_rcve(UCHAR *);
void init_arp(void);
UCHAR *arp_resolve(ULONG);
void arp_send(UCHAR *, ULONG , UCHAR );
void arp_rcve(UCHAR *);
void age_arp_cache(void);
void arp_retransmit(void);
void ping_send(UCHAR *, ULONG, UINT);
void dest_unreach_send(UCHAR *, ULONG);
void icmp_rcve(UCHAR *, UINT);
void udp_send(UCHAR *, UINT, UINT);
void udp_rcve(UCHAR *, UINT);
void init_tcp(void);
void init_http(void);
void init_type(void);
void tcp_send(UINT, UINT, UCHAR);
void tcp_rcve(UCHAR *,UINT);
void tcp_retransmit(void);
void tcp_inactivity(void);
UINT http_server(UCHAR *, UINT, UCHAR, UCHAR);
void ConfigParameter(UCHAR *inbuf, UINT len);


void Create_UP_His_Msg(void);
void Create_DOWN_His_Msg(void);
#endif

