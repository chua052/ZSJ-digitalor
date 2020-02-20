/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 * 2013-07-12     aozima       update for auto initial.
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <board.h>
#include <rtthread.h>



#ifdef RT_USING_DFS
/* dfs filesystem:ELM filesystem init */
#include <dfs_elm.h>
/* dfs Filesystem APIs */
#include <dfs_fs.h>
#endif

#ifdef RT_USING_RTGUI
#include <rtgui/rtgui.h>
#include <rtgui/rtgui_server.h>
#include <rtgui/rtgui_system.h>
#include <rtgui/driver.h>
#include <rtgui/calibration.h>
#endif

#include <rtdbg.h>

#include "led.h"
#include "w5500.h"
#include "global.h"
#include "delay.h"
#include "stmflash.h"
#include "rtc.h"
#include "iwdg.h"
//ALIGN(RT_ALIGN_SIZE)
/******** thread extern ***********/
extern void mqtt_start(void* parameter);

extern void pub_sub_entry(void* parameter);
extern void mqtt_pub_entry(void* parameter);
extern void thread_entry(void* parameter);


#ifdef RT_USING_RTGUI
rt_bool_t cali_setup(void)
{
    rt_kprintf("cali setup entered\n");
    return RT_FALSE;
}

void cali_store(struct calibration_data *data)
{
    rt_kprintf("cali finished (%d, %d), (%d, %d)\n",
               data->min_x,
               data->max_x,
               data->min_y,
               data->max_y);
}
#endif /* RT_USING_RTGUI */


/****************************************************************************************************
函数名：
功能：
入口参数：
返回值：
说明：
版本：
作者：
日期：
*******************************************************************************************************/
//void MainInitBsp(void)
//{

////SCB->VTOR = FLASH_BASE | 0x3000; /* Vector Table Relocation in Internal FLASH. */
////__enable_irq();
//	delay_init();			       //延时函数初始化
//	delay_ms(1000);			     //等待硬件上电稳定
//	//NVIC_Configuration();	   //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 
//	JATG_Close();

//  RESET_GPIO_Init();
//  Sys_SerialNum = Get_Device_Id();	 
//	delay_ms(Sys_SerialNum/256);	
//	times_3s=0;
//  
//	
//	Need_Update = STMFLASH_ReadHalfWord(NEED_UPDATE_ADD);//64K   开始读取
//	if(Need_Update!=0x0000)
//	{
//		Need_Update = 0x0000;
//		Ver_No = Sys_Vision;

//		FLASH_Unlock();						//解锁
//		FLASH_ErasePage(NEED_UPDATE_ADD);//擦除这个扇区
//		FlashWriteOnly_16(NEED_UPDATE_ADD,&Need_Update,1);
//		FlashWriteOnly_16(VERSION_ADD,&Ver_No,1);	
//  }
//	if(Sys_Vision != STMFLASH_ReadHalfWord(VERSION_ADD))//64K+2
//	{
//		Ver_No = Sys_Vision;
//		Need_Update = 0x0000;
//    FLASH_Unlock();						//解锁
//		FLASH_ErasePage(NEED_UPDATE_ADD);//擦除这个扇区
//		FlashWriteOnly_16(NEED_UPDATE_ADD,&Need_Update,1);
//		FlashWriteOnly_16(VERSION_ADD,&Ver_No,1);	
//			
//	}	

//	FlashCheck(); // 
//  InitPara();	
//	

//	system_initial();//已改
//  MinBeepBsp();
//if(MODBUS_RTU_NETMODE == 1)
//{	
//  RTC_Init();
//  Maindoorbsp();
//}
//  delay_ms(200);


//	usRegHoldingBuf3[0] = my_ips[0];
//	usRegHoldingBuf3[0] <<= 8;
//	usRegHoldingBuf3[0] |= my_ips[1];
//	usRegHoldingBuf3[1] = my_ips[2];
//	usRegHoldingBuf3[1] <<= 8;
//	usRegHoldingBuf3[1] |= my_ips[3];
//	
//	usRegHoldingBuf3[2] = sb_net[0];
//	usRegHoldingBuf3[2] <<= 8;
//	usRegHoldingBuf3[2] |= sb_net[1];
//	usRegHoldingBuf3[3] = sb_net[2];
//	usRegHoldingBuf3[3] <<= 8;
//	usRegHoldingBuf3[3] |= sb_net[3];
//	
//	usRegHoldingBuf3[4] = gw_ips[0];
//	usRegHoldingBuf3[4] <<= 8;
//	usRegHoldingBuf3[4] |= gw_ips[1];
//	usRegHoldingBuf3[5] = gw_ips[2];
//	usRegHoldingBuf3[5] <<= 8;
//	usRegHoldingBuf3[5] |= gw_ips[3];
//	
//	usRegHoldingBuf3[6] = self_port; 
//	
//	usRegHoldingBuf3[7] = rm_ips[0];
//	usRegHoldingBuf3[7] <<= 8;
//	usRegHoldingBuf3[7] |= rm_ips[1];
//	usRegHoldingBuf3[8] = rm_ips[2];
//	usRegHoldingBuf3[8] <<= 8;
//	usRegHoldingBuf3[8] |= rm_ips[3];
//	
//	usRegHoldingBuf3[9] = remote_port; 

//	memcpy(usRegHoldingBufBkp3,usRegHoldingBuf3,2*REG_HOLDING_NREGS_3);

//	//FlashReadData(FLASH_RACK_NAME_ADDR, (uint8_t*)usRegHoldingBuf4, 2*REG_HOLDING_NREGS_4);
//	
////如果机架信息部分为0xffff，则将其初始化为0x0000。	
//	if( (usRegHoldingBuf4[0]==0xffff) && (usRegHoldingBuf4[REG_HOLDING_NREGS_4-1]==0xffff) )
//	{		

//		memset(usRegHoldingBuf4,0,2*REG_HOLDING_NREGS_4);
//	
//		FlashWriteData(FLASH_RACK_NAME_ADDR, (uint8_t*)usRegHoldingBuf4, 2*REG_HOLDING_NREGS_4);		
//	}
//	memcpy(usRegHoldingBufBkp4,usRegHoldingBuf4,2*REG_HOLDING_NREGS_4);
//	

//	testbuf[0] = 	STMFLASH_ReadHalfWord(His_MSG_PAGE1 + Page_Erase_Time);
//	if(testbuf[0]==0xffff)
//	{
//		testbuf[0] = 1;
//		FlashWriteOnly_16(His_MSG_PAGE1 + Page_Erase_Time,&testbuf[0],1);
//	}
//	testbuf[0] = 	STMFLASH_ReadHalfWord(His_MSG_PAGE2 + Page_Erase_Time);
//	if(testbuf[0]==0xffff)
//	{
//		testbuf[0] = 1;
//		FlashWriteOnly_16(His_MSG_PAGE2 + Page_Erase_Time,&testbuf[0],1);
//	}
//	testbuf[0] = 	STMFLASH_ReadHalfWord(His_MSG_PAGE3 + Page_Erase_Time);
//	if(testbuf[0]==0xffff)
//	{
//		testbuf[0] = 1;
//		FlashWriteOnly_16(His_MSG_PAGE3 + Page_Erase_Time,&testbuf[0],1);
//	}	

//	memset(WtFlag,1,sizeof(WtFlag));	
//	memset(AuthenBuf,0xff,sizeof(AuthenBuf));
//  	memset(UW_Hight,0,sizeof(UW_Hight));
//	memset(Store,0,sizeof(Store));
//	memset(Up_Send_Flag,0,sizeof(Up_Send_Flag));
//	//fifo_init2();
//	Colour_Light_Ticks = 0;
//	To_Send_Next[up] =1;
//	To_Send_Next[down] =1;	

//  if( MINI_USE_DOG  == 1)
//	{
//	  IWDG_Init(6,625);		//分频数为256,重载值为625,溢出时间为4s
//	}
//	ser_ct = 80;
//}

void rt_init_thread_entry(void* parameter)
{
#ifdef RT_USING_COMPONENTS_INIT
    /* initialization RT-Thread Components */
    rt_components_init();
#endif

    /* Filesystem Initialization */
//#if defined(RT_USING_DFS) && defined(RT_USING_DFS_ELMFAT)
//    /* mount sd card fat partition 1 as root directory */
//    if (dfs_mount("sd0", "/", "elm", 0, 0) == 0)
//    {
//        rt_kprintf("File System initialized!\n");
//    }
//    else
//        rt_kprintf("File System initialzation failed!\n");
//#endif  /* RT_USING_DFS */

#ifdef RT_USING_RTGUI
    {
        extern void rt_hw_lcd_init();
        extern void rtgui_touch_hw_init(void);

        rt_device_t lcd;

        /* init lcd */
        rt_hw_lcd_init();

        /* init touch panel */
        rtgui_touch_hw_init();

        /* find lcd device */
        lcd = rt_device_find("lcd");

        /* set lcd device as rtgui graphic driver */
        rtgui_graphic_set_device(lcd);

#ifndef RT_USING_COMPONENTS_INIT
        /* init rtgui system server */
        rtgui_system_server_init();
#endif

        calibration_set_restore(cali_setup);
        calibration_set_after(cali_store);
        calibration_init();
    }
#endif /* #ifdef RT_USING_RTGUI */
}
extern void serial_com_check_thread_entry(void* parameter);
extern void modbus_thread_entry(void* parameter);
extern void check_moudle_entry(void* parameter);
int rt_application_init(void)
{
    rt_thread_t init_thread;
//	rt_thread_t serial_com_thread;
//	rt_thread_t modbus_thread;

//    rt_err_t result;

    /* init led thread */
//    result = rt_thread_init(&led_thread,
//                            "led",
//                            led_thread_entry,
//                            RT_NULL,
//                            (rt_uint8_t*)&led_stack[0],
//                            sizeof(led_stack),
//                            25,
//                            5);
//    if (result == RT_EOK)
//    {
//        rt_thread_startup(&led_thread);
//    }
	
	
	
#if (RT_THREAD_PRIORITY_MAX == 32)
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   1024, 8, 20);
#else
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   1024, 80, 20);
#endif
	
    if (init_thread != RT_NULL)
        rt_thread_startup(init_thread);
		
		/*******自定义线程********/

	rt_thread_t pub_sub_th;
			//线程3：MQTT订阅+发布消息
	pub_sub_th = rt_thread_create("pub_sub_th",
							   pub_sub_entry, RT_NULL,
							   2048, 7, 20);
	
	if (pub_sub_th != RT_NULL)
		rt_thread_startup(pub_sub_th);
			
//	//线程4：模拟在其他地方触发了发布标志
//	rt_thread_t lable_test_th;
//		lable_test_th = rt_thread_create("check_moudle_th", 
//							check_moudle_entry, RT_NULL,
//							512, 7, 10);
//	if (lable_test_th != RT_NULL) 
//		rt_thread_startup(lable_test_th);

//		
//	serial_com_thread = rt_thread_create("serial",
//                                   serial_com_check_thread_entry, RT_NULL,
//                                   512, 7, 10);

//		if (serial_com_thread != RT_NULL)
//        	rt_thread_startup(serial_com_thread);

//	modbus_thread = rt_thread_create("modbus",
//                                   modbus_thread_entry, RT_NULL,
//                                   512, 7, 10);

//		if (modbus_thread != RT_NULL)
//        	rt_thread_startup(modbus_thread);
		
    return 0;
}

/*@}*/
