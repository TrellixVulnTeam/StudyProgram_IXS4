/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_hdmirx.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/09/27
  Description   : 
  History       :
  1.Date        : 2013/09/27
  Author        : t00202585
  Modification  : Created file
******************************************************************************/
#ifndef __HI_UNF_SWITCH_H__
#define __HI_UNF_SWITCH_H__

/* add include here */
//#include <linux/ioctl.h>
//#include "hi_sdk_comm.h"
//#include "hi_module.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      HDMI */
/** @{ */  /** <!-- [HDMI] */
/**HDMI port ID *//**CNcomment:HDMI port��ID  */
typedef enum hiUNF_SWITCH_PORT_E
{
    HI_UNF_SWITCH_PORT0,					       /**<SWITCH port 0*/ /**<CNcomment:HDMIRX port0 */
    HI_UNF_SWITCH_PORT1,					       /**<SWITCH port 1*/ /**<CNcomment:HDMIRX port1 */						
    HI_UNF_SWITCH_PORT2,					       /**<SWITCH port 2*/ /**<CNcomment:HDMIRX port2 */
    HI_UNF_SWITCH_PORT3,					       /**<SWITCH port 3*/ /**<CNcomment:HDMIRX port3 */
    HI_UNF_SWITCH_PORT_BUTT
}HI_UNF_SWITCH_PORT_E;

/**the config parameter of EDID interface*/
/**CNcomment:EDID �ӿڲ������� */
typedef struct hiUNF_SWITCH_EDID_S
{
    HI_U8 u8SwitchId;
    HI_UNF_SWITCH_PORT_E enSwitchPort;
    HI_U32			u32EdidLength;
    HI_U32   		*pu32Edid;	     /**<HDMIRX EDID Value*//**<CNcomment:HDMIRX EDID ֵ */ 				
    HI_U32   		u32CecAddr;	     // ��port�ڶ�Ӧ��CEC��ַ	
}HI_UNF_SWITCH_EDID_S;

/** 
\brief the whole initialization of the switch. CNcomment:SWITCH�ӿ����������ʼ�� CNend
\attention  this func should be called before vo_init and after disp_init. CNcomment:������DISP����Setup֮���VO����Setup֮ǰ�� CNend
\param CNcomment:�� CNend
\retval HI_SUCCESS  success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_Init(HI_VOID);

/** 
\brief deinit the switch. CNcomment:SWITCH�ӿ�ȥ��ʼ�� CNend
\attention  this must be called after vo exited and before disp  exited . CNcomment:������VO����Exit֮���DISP����Exit֮ǰ�� CNend
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_DeInit(HI_VOID);

/** 
\brief create SWITCH device.Select the switch ID and input port. CNcomment:����SWITCH�豸,ѡ�������SWITCH ID �����ӵ� port�� CNend
\attention \n
\param[in] HI_U8                 switch id. CNcomment:Ҫ�򿪵�switch ID CNend
\param[in] HI_UNF_SWITCH_PORT_E  switch device id. CNcomment:Ҫ�򿪵�switch port�� ID CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_Connect(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);

/** 
\brief  set hdmiout mode end
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port��ID
\param[in] *HI_BOOL  callback the port OffLineDetect Status CNcomment:�ص����������ص�ǰ�����߼��״̬ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_SetHDMIOutmode(HI_U8 u8hdmiout);
/** 
\brief disConnect the handler created by  HI_UNF_SWITCH_Connect. CNcomment:������HI_UNF_SWITCH_Connect�����ľ�� CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_DisConnect(HI_VOID);

/** 
\brief Set the Map bewteen HDMI Port and Switch id and port. CNcomment:����HDMI Port �ں�Switch ID ��������
\attention \n
\param[in] HI_U8                 Hdmi Port. CNcomment:HDMI Port CNend
\param[in] HI_U8                 switch id. CNcomment:switch ID CNend
\param[in] HI_UNF_SWITCH_PORT_E  switch port id. CNcomment:Ҫ�򿪵�switch port�� ID CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_SetMapPort(HI_U8 u8HdmiPort,HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enSwitchPort);

/** 
\brief Update the EDID in SRAM. CNcomment:����EDID ��SRAM�� CNend
\attention \n
\param[in] *HI_UNF_HDMIRX_EDID_S  key struct point CNcomment: key�Ľṹָ��
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_UpdateEdid(HI_UNF_SWITCH_EDID_S *pstEdid);

/** 
\brief  Get the port OffLineDetect Status CNcomment:��ȡport�����߼��״̬ CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port��ID
\param[in] *HI_BOOL  callback the port OffLineDetect Status CNcomment:�ص����������ص�ǰ�����߼��״̬ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_SWITCH_GetOffLineDetStatus(HI_U8 u8SwitchId,HI_UNF_SWITCH_PORT_E enPort, HI_BOOL *pbConnected);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

