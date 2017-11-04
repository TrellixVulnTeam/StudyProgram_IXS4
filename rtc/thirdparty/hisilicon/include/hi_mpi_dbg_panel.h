/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : mpi_panel_dbg.h
  Version       : Initial Draft
  Author        : t00357080
  Created       : 2015/12/3
  Description   :

******************************************************************************/

#ifndef __MPI_PANEL_DBG_H__
#define __MPI_PANEL_DBG_H__

#include "hi_type.h"
#include "hi_drv_panel.h"
#include "hi_mpi_panel.h"
#include "hi_mpi_dbg.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define PANEL_CMD_SIZE sizeof(HI_U32)

/* PQ�������� */
typedef enum hiPANEL_DBG_CMD
{
	PANEL_CMD_READ_INFO = 0,									//��PanelInfo
	PANEL_CMD_WRITE_INFO,										//дPanelInfo
	   
	PANEL_CMD_BUTT
} PANEL_DBG_CMD_E;

typedef struct hiPANEL_DBG_INFO_W_S
{
    HI_U32 u32CMD;
    HI_DRV_PANEL_INFO_S stPanelInfo;
}PANEL_DBG_INFO_W_S;


/*PQ ����ʵ�ֽṹ*/
typedef struct hiPANEL_DBG_CMD_FUN_S
{
    HI_CHAR *pPanelCmdName;
    PANEL_DBG_CMD_E enDbgCmd;    
    void (*pfCmdFunction)(HI_U8 * pu8Buffer,HI_U32 u32BufferLen); /*PANEL DBG CMD��Ӧ��ʵ�ֺ���*/
} PANEL_DBG_CMD_FUN_S;

/* Debugģ����ص����� */
//typedef void (* HI_MDBG_UART_READ_CALLBACK_FN_PTR)(HI_U8* pu8Buffer, HI_S32 s32BufferLen, HI_S32* ps32ReadSize);

/* Debugģ��д�ص����� */
//typedef void (* HI_MDBG_UART_WRITE_CALLBACK_FN_PTR)(HI_U8* pu8Buffer, HI_S32 s32BufferLen);


/* PQ Debug�������� */
HI_S32 MPI_PANEL_DBG_Parser(HI_U8* pu8Buffer, HI_U32 u32BufferLen);

/* ע�ᴮ�ڶ�д���� */
HI_VOID MPI_PANEL_DBG_RegisterUartFunc(HI_MDBG_UART_READ_CALLBACK_FN_PTR pfnUartRead,HI_MDBG_UART_WRITE_CALLBACK_FN_PTR pfnUartWrite);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __MPI_PQ_DBG_H__ */
