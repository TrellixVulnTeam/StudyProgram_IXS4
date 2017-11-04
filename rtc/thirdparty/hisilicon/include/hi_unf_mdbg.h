/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : mpi_mdbg.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/15
  Description   :

******************************************************************************/

#ifndef __HI_UNF_MDBG_H__
#define __HI_UNF_MDBG_H__

#include "hi_type.h"
#include <asm/ioctl.h>

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/**
 \brief Debugģ���ʼ�� ;
 \attention \n
  ��

 \param[in] none

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_Init();

/**
 \brief Debugģ��ȥ��ʼ��  ;
 \attention \n
  ��

 \param[in] none

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_DeInit();

/**
 \brief �������ģʽ  ;
 \attention \n
  ��

 \param[in] bOnOff

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_UNF_MDBG_EnterDebugMode(HI_BOOL bOnOff);

/**
 \brief ��ȡ����ģʽ  ;
 \attention \n
  ��

 \param[in] none

 \retval ::HI_BOOL

 */
extern HI_BOOL  HI_UNF_MDBG_GetDebugMode();

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_MDBG_H__ */
