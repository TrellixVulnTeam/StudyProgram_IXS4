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
#ifndef __HI_UNF_HDMIRX_H__
#define __HI_UNF_HDMIRX_H__

/* add include here */
//#include <linux/ioctl.h>
//#include "hi_sdk_comm.h"
//#include "hi_module.h"
#include "hi_unf_common.h"
#include "hi_unf_ai.h"
#include "hi_unf_sound.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      HDMI */
/** @{ */  /** <!-- [HDMI] */

/**the config parameter of HDMI interface*/
/**CNcomment:HDMI �ӿڲ������� */
typedef struct hiUNF_HDMIRX_TIMING_INFO_S
{
    HI_U32                  			u32Width;           /**<HDMIRX Hactive*//**<CNcomment:HDMIRX ����Чֵ */
    HI_U32                  			u32Height;          /**<HDMIRX Vactive*//**<CNcomment:HDMIRX ����Чֵ */ 
    HI_U32                  			u32FrameRate;       /**<HDMIRX frequency of vsync*//**<CNcomment:HDMIRX ��Ƶ�� */
    HI_UNF_COLOR_SPACE_E    			enColorSpace;       /**<HDMIRX color space*//**<CNcomment:HDMIRX ɫ�ȿռ� */    
    HI_UNF_VIDEO_FORMAT_E   			enPixelFmt;         /**<HDMIRX video formate*//**<CNcomment:HDMIRX ��Ƶ��ʽ */
    HI_UNF_PIXEL_BITWIDTH_E     		enBitWidth;         /**<HDMIRX video BitWidth*//**<CNcomment:HDMIRX ��Ƶλ�� */
    HI_BOOL                 			bInterlace;         /**<HDMIRX video interlace or progressive*//**<CNcomment:HDMIRX HDMIRX��Ƶɨ�跽ʽ�����л��Ǹ��� */   
    HI_UNF_OVERSAMPLE_MODE_E    		enOversample;       /**<HDMIRX video Oversample*//**<CNcomment:HDMIRX ��Ƶ��������С */	
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E	en3dFmt;            /**<HDMIRX video 3D formate*//**<CNcomment:HDMIRX ��Ƶ3D��ʽ */  
    HI_BOOL                            	bHdmiMode;          /**<HDMIRX video HDMI or DVI*//**<CNcomment:HDMIRX��Ƶģʽ��HDMI����DVI */ 
    HI_U32                  			u32Vblank;          /**<HDMIRX video Vblank��the value must set when the 3D formate is Frame PACKING*//**<CNcomment:HDMIRX Vblankֵ��������Ƶ��ʽΪ3D Frame PACKINGʱ��Ч */
    HI_BOOL					            bPcMode;	    /**<HDMIRX PC Timing Mode flag*//**<CNcomment:HDMIRX PC Timing��־λ*/ 
    HI_UNF_RGB_RANGE_E                 	enRGBRange;         /**<HDMIRX RGB Quantization Range*//**<CNcomment:HDMIRX RGB ������Χ*/ 
    HI_U32                              u32TimingIdx;	    /**<HDMIRX Timing Inedex Table*//**<CNcomment:HDMIRX Timing ��Ӧ��Index*/	
    HI_BOOL                             bMHL;		    /**<HDMIRX MHL flag*//**<CNcomment:HDMIRX MHL��־λ*/ 	
}HI_UNF_HDMIRX_TIMING_INFO_S;

/**the config parameter of HDCP interface*/
/**CNcomment:HDCP �ӿڲ������� */
typedef struct hiUNF_HDMIRX_HDCP_S
{
    HI_U32				u32HdcpLength;
    HI_U8   			*pu8Hdcp;        /**<HDMIRX HDCP Value*//**<CNcomment:HDMIRX HDCP ֵ */    	
}HI_UNF_HDMIRX_HDCP_S;

typedef enum hiUNF_HDMIRX_HDCPTYPE_E
{
	HI_UNF_HDMIRX_HDCPTYPE_14,
	HI_UNF_HDMIRX_HDCPTYPE_22,
	HI_UNF_HDMIRX_HDCPTYPE_BUTT
}HI_UNF_HDMIRX_HDCPTYPE_E;

/**HDMI port ID *//**CNcomment:HDMI port��ID  */
typedef enum hiUNF_HDMIRX_PORT_E
{
    HI_UNF_HDMIRX_PORT0,					       /**<HDMIRX port 0*/ /**<CNcomment:HDMIRX port0 */
    HI_UNF_HDMIRX_PORT1,					       /**<HDMIRX port 1*/ /**<CNcomment:HDMIRX port1 */						
    HI_UNF_HDMIRX_PORT2,					       /**<HDMIRX port 2*/ /**<CNcomment:HDMIRX port2 */
    HI_UNF_HDMIRX_PORT3,					       /**<HDMIRX port 3*/ /**<CNcomment:HDMIRX port3 */
  //  HI_UNF_HDMIRX_PORT_ALL,					       /**<HDMIRX ALL port*/ /**<CNcomment:HDMIRX ����port�� */						
    HI_UNF_HDMIRX_PORT_BUTT
}HI_UNF_HDMIRX_PORT_E;

/**HDMI Format Type *//**CNcomment:HDMI �ź�����  */
typedef enum hiUNF_HDMIRX_FORMAT_E 
{ 
  HI_UNF_HDMIRX_FORMAT_HDMI, 
  HI_UNF_HDMIRX_FORMAT_DVI, 
  HI_UNF_HDMIRX_FORMAT_MHL, 

  HI_UNF_HDMIRX_FORMAT_BUTT 
}HI_UNF_HDMIRX_FORMAT_E;

/**the config parameter of EDID interface*/
/**CNcomment:EDID �ӿڲ������� */
typedef struct hiUNF_HDMIRX_EDID_S
{
    HI_UNF_HDMIRX_PORT_E enPort;
    HI_U32			u32EdidLength;
    HI_U32   		*pu32Edid;	     /**<HDMIRX EDID Value*//**<CNcomment:HDMIRX EDID ֵ */ 				
    HI_U32   		u32CecAddr;	     // ��port�ڶ�Ӧ��CEC��ַ	
}HI_UNF_HDMIRX_EDID_S;


/**the config parameter of OffLineDetect Status interface*/
/**CNcomment:���߼�� �ӿڲ������� */
typedef struct hiUNF_HDMIRX_OFF_LINE_DET_S
{
    HI_UNF_HDMIRX_PORT_E    			enPort;			/**<HDMIRX port ID */ /**<CNcomment:HDMIRX port ID */				
    HI_BOOL 		    			bConnected;		/**<HDMIRX OffLineDetect Status for callback*/ /**<CNcomment:HDMIRX ���߼��״̬�����ڷ���ֵ */
}HI_UNF_HDMIRX_OFF_LINE_DET_S;

/**the config parameter of MHL RCP Key*/
/**CNcomment:MHL RCP Key*/

typedef enum hiUNF_HDMIRX_RCP_KEY_E
{
    HI_UNF_HDMIRX_RCP_KEY_SELECT,
    HI_UNF_HDMIRX_RCP_KEY_UP,
    HI_UNF_HDMIRX_RCP_KEY_DOWN,
    HI_UNF_HDMIRX_RCP_KEY_LEFT,
    HI_UNF_HDMIRX_RCP_KEY_RIGHT,
    HI_UNF_HDMIRX_RCP_KEY_ROOT_MENU,
    HI_UNF_HDMIRX_RCP_KEY_EXIT,
    HI_UNF_HDMIRX_RCP_KEY_PLAY,
    HI_UNF_HDMIRX_RCP_KEY_STOP,
    HI_UNF_HDMIRX_RCP_KEY_PAUSE,
    HI_UNF_HDMIRX_RCP_KEY_REWIND,
    HI_UNF_HDMIRX_RCP_KEY_FAST_FWD,
    HI_UNF_HDMIRX_RCP_KEY_BUTT,
}HI_UNF_HDMIRX_RCP_KEY_E;

/**the config parameter of CEC OPCODE*/
/**CNcomment:CEC OPCODE*/

typedef enum hiUNF_HDMIRX_CEC_OPCODE_E
{
	HI_UNF_HDMIRX_CEC_OPCODE_SENDPING                  = 0x100,    
	HI_UNF_HDMIRX_CEC_OPCODE_FEATURE_ABORT             = 0x00,
	HI_UNF_HDMIRX_CEC_OPCODE_IMAGE_VIEW_ON             = 0x04,
	HI_UNF_HDMIRX_CEC_OPCODE_TUNER_STEP_INCREMENT      = 0x05,     
	HI_UNF_HDMIRX_CEC_OPCODE_TUNER_STEP_DECREMENT      = 0x06,     
	HI_UNF_HDMIRX_CEC_OPCODE_TUNER_DEVICE_STATUS       = 0x07,     
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_TUNER_DEVICE_STATUS  = 0x08,     
	HI_UNF_HDMIRX_CEC_OPCODE_RECORD_ON                 = 0x09,     
	HI_UNF_HDMIRX_CEC_OPCODE_RECORD_STATUS             = 0x0A,     
	HI_UNF_HDMIRX_CEC_OPCODE_RECORD_OFF                = 0x0B,     
	HI_UNF_HDMIRX_CEC_OPCODE_TEXT_VIEW_ON              = 0x0D,
	HI_UNF_HDMIRX_CEC_OPCODE_RECORD_TV_SCREEN          = 0x0F,     
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_DECK_STATUS          = 0x1A,
	HI_UNF_HDMIRX_CEC_OPCODE_DECK_STATUS               = 0x1B,
	HI_UNF_HDMIRX_CEC_OPCODE_SET_MENU_LANGUAGE         = 0x32,
	HI_UNF_HDMIRX_CEC_OPCODE_CLEAR_ANALOGUE_TIMER      = 0x33,     
	HI_UNF_HDMIRX_CEC_OPCODE_SET_ANALOGUE_TIMER        = 0x34,     
	HI_UNF_HDMIRX_CEC_OPCODE_TIMER_STATUS              = 0x35,     
	HI_UNF_HDMIRX_CEC_OPCODE_STANDBY                   = 0x36,
	HI_UNF_HDMIRX_CEC_OPCODE_PLAY                      = 0x41,
	HI_UNF_HDMIRX_CEC_OPCODE_DECK_CONTROL              = 0x42,
	HI_UNF_HDMIRX_CEC_OPCODE_TIMER_CLEARED_STATUS      = 0x43,     
	HI_UNF_HDMIRX_CEC_OPCODE_USER_CONTROL_PRESSED      = 0x44,
	HI_UNF_HDMIRX_CEC_OPCODE_USER_CONTROL_RELEASED     = 0x45,
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_OSD_NAME             = 0x46,
	HI_UNF_HDMIRX_CEC_OPCODE_SET_OSD_NAME              = 0x47,
	HI_UNF_HDMIRX_CEC_OPCODE_SET_OSD_STRING            = 0x64,
	HI_UNF_HDMIRX_CEC_OPCODE_SET_TIMER_PROGRAM_TITLE   = 0x67,    
	HI_UNF_HDMIRX_CEC_OPCODE_SYSTEM_AUDIO_MODE_REQUEST = 0x70,     
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_AUDIO_STATUS         = 0x71,     
	HI_UNF_HDMIRX_CEC_OPCODE_SET_SYSTEM_AUDIO_MODE     = 0x72,     
	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_AUDIO_STATUS       = 0x7A,     
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_SYSTEM_AUDIO_MODE_STATUS = 0x7D, 
	HI_UNF_HDMIRX_CEC_OPCODE_SYSTEM_AUDIO_MODE_STATUS  = 0x7E,     
	HI_UNF_HDMIRX_CEC_OPCODE_ROUTING_CHANGE            = 0x80,
	HI_UNF_HDMIRX_CEC_OPCODE_ROUTING_INFORMATION       = 0x81,
	HI_UNF_HDMIRX_CEC_OPCODE_ACTIVE_SOURCE             = 0x82,
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_PHYSICAL_ADDRESS     = 0x83,
	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_PHYSICAL_ADDRESS   = 0x84,
	HI_UNF_HDMIRX_CEC_OPCODE_REQUEST_ACTIVE_SOURCE     = 0x85,
	HI_UNF_HDMIRX_CEC_OPCODE_SET_STREAM_PATH           = 0x86,
	HI_UNF_HDMIRX_CEC_OPCODE_DEVICE_VENDOR_ID          = 0x87,
	HI_UNF_HDMIRX_CEC_OPCODE_VENDOR_COMMAND            = 0x89,
	HI_UNF_HDMIRX_CEC_OPCODE_VENDOR_REMOTE_BUTTON_DOWN = 0x8A,
	HI_UNF_HDMIRX_CEC_OPCODE_VENDOR_REMOTE_BUTTON_UP   = 0x8B,
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_DEVICE_VENDOR_ID     = 0x8C,
	HI_UNF_HDMIRX_CEC_OPCODE_MENU_REQUEST              = 0x8D,
	HI_UNF_HDMIRX_CEC_OPCODE_MENU_STATUS               = 0x8E,
	HI_UNF_HDMIRX_CEC_OPCODE_GIVE_DEVICE_POWER_STATUS  = 0x8F,
	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_POWER_STATUS       = 0x90,
	HI_UNF_HDMIRX_CEC_OPCODE_GET_MENU_LANGUAGE         = 0x91,
	HI_UNF_HDMIRX_CEC_OPCODE_SELECT_ANALOGUE_SERVICE   = 0x92,    
	HI_UNF_HDMIRX_CEC_OPCODE_SELECT_DIGITAL_SERVICE    = 0x93,     
	HI_UNF_HDMIRX_CEC_OPCODE_SET_DIGITAL_TIMER         = 0x97,     
	HI_UNF_HDMIRX_CEC_OPCODE_CLEAR_DIGITAL_TIMER       = 0x99,     
	HI_UNF_HDMIRX_CEC_OPCODE_SET_AUDIO_RATE            = 0x9A,    
	HI_UNF_HDMIRX_CEC_OPCODE_INACTIVE_SOURCE           = 0x9D,     
	HI_UNF_HDMIRX_CEC_OPCODE_CEC_VERSION               = 0x9E,     
	HI_UNF_HDMIRX_CEC_OPCODE_GET_CEC_VERSION           = 0x9F,     
	HI_UNF_HDMIRX_CEC_OPCODE_VENDOR_COMMAND_WITH_ID    = 0xA0,     
	HI_UNF_HDMIRX_CEC_OPCODE_CLEAR_EXTERNAL_TIMER      = 0xA1,     
	HI_UNF_HDMIRX_CEC_OPCODE_SET_EXTERNAL_TIMER        = 0xA2,     

	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_SHORT_AUDIO    	   = 0xA3,     
	HI_UNF_HDMIRX_CEC_OPCODE_REQUEST_SHORT_AUDIO       = 0xA4,     

	HI_UNF_HDMIRX_CEC_OPCODE_INITIATE_ARC              = 0xC0,
	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_ARC_INITIATED      = 0xC1,
	HI_UNF_HDMIRX_CEC_OPCODE_REPORT_ARC_TERMINATED     = 0xC2,

	HI_UNF_HDMIRX_CEC_OPCODE_REQUEST_ARC_INITIATION    = 0xC3,
	HI_UNF_HDMIRX_CEC_OPCODE_REQUEST_ARC_TERMINATION   = 0xC4,
	HI_UNF_HDMIRX_CEC_OPCODE_TERMINATE_ARC             = 0xC5,

	HI_UNF_HDMIRX_CEC_OPCODE_HEADER                    = 0xF8,
	HI_UNF_HDMIRX_CEC_OPCODE_ABORT                     = 0xFF,

} HI_UNF_HDMIRX_CEC_OPCODE_E;

/**the config parameter of CEC OPERAND*/
/**CNcomment:CEC OPERAND*/
typedef struct hiUNF_HDMIRX_CEC_OPERAND_S
{
	HI_U32          au32Args[16];
	HI_U32          u32ArgCount;
}HI_UNF_HDMIRX_CEC_OPERAND_S;

typedef struct hiUNF_HDMIRX_CEC_CMD_S
{
	HI_U32           				u32SrcAddr;       /**<logical address of source *//**<CNcomment:Դ���豸��ַ */
	HI_U32           				u32DstAddr;	      /**<logical address of destination*//**<CNcomment:Ŀ���豸��ַ */
	HI_UNF_HDMIRX_CEC_OPCODE_E      enOpcode;         /**<opration code*//**<CNcomment:������*/
	HI_UNF_HDMIRX_CEC_OPERAND_S     stOperand;        /**<operand*//**<CNcomment:������*/ 
}HI_UNF_HDMIRX_CEC_CMD_S;

/**the CEC command state of sending*/
/**CNcomment:CEC CMD STATE*/
typedef enum hiUNF_HDMIRX_CEC_CMD_STATE_E
{
	HI_UNF_HDMIRX_CEC_CMD_STATE_SUCCESS = 0,
	HI_UNF_HDMIRX_CEC_CMD_STATE_FAILED,

	HI_UNF_HDMIRX_CEC_CMD_STATE_BUTT,
}HI_UNF_HDMIRX_CEC_CMD_STATE_E;


typedef struct hiUNF_HDMIRX_CEC_CMD_STATE_S
{
	HI_UNF_HDMIRX_CEC_OPCODE_E      enCurOpcode;     /**<opration code*//**<CNcomment:������*/
	HI_UNF_HDMIRX_CEC_CMD_STATE_E	enCurState;	  
	HI_U32           				u32DstAddr;	      /**<logical address of destination*//**<CNcomment:Ŀ���豸��ַ */
}HI_UNF_HDMIRX_CEC_CMD_STATE_S;


typedef HI_VOID (*HI_UNF_HDMIRX_CEC_CALLBACK)(HI_UNF_HDMIRX_CEC_CMD_S *pstCECCmd, HI_VOID *pData);

/** 
\brief the whole initialization of the hdmirx. CNcomment:HDMIRX�ӿ����������ʼ�� CNend
\attention  this func should be called before vo_init and after disp_init. CNcomment:������DISP����Setup֮���VO����Setup֮ǰ�� CNend
\param CNcomment:�� CNend
\retval HI_SUCCESS  success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_Init(HI_VOID);

/** 
\brief deinit the hdmirx. CNcomment:HDMIRX�ӿ�ȥ��ʼ�� CNend
\attention  this must be called after vo exited and before disp  exited . CNcomment:������VO����Exit֮���DISP����Exit֮ǰ�� CNend
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_DeInit(HI_VOID);

/** 
\brief create hdmirx device.Select the input port. CNcomment:����HDMIRX�豸,ѡ������port�� CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  hdmirx device id. CNcomment:Ҫ�򿪵�HDMIRX port�� ID CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_Connect(HI_UNF_HDMIRX_PORT_E enPort);

/** 
\brief disConnect the handler created by  HI_UNF_HDMIRX_Connect. CNcomment:������HI_UNF_HDMIRX_Connect�����ľ�� CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_DisConnect(HI_VOID);

/** 
\brief Get the current HDCP authentication Status. CNcomment:��ѯ��ǰHDCP״̬
\attention \n
\param[in] *HI_BOOL  callback function CNcomment:�ص����� CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetHdcpStatus(HI_BOOL *pbHdcpSta);

/** 
\brief Get the current timing information. CNcomment:��ȡ��ǰTiming��Ϣ
\attention \n
\param[in] *HI_UNF_HDMIRX_TIMING_INFO_S  callback function CNcomment:�ص����� CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetTimingInfo(HI_UNF_HDMIRX_TIMING_INFO_S *pstTimingInfo);

/* Get the Timing hdcp authentication status */
/** 
\brief Get the current Audio information. CNcomment:��ȡ��ǰ��Ƶ��Ϣ
\attention \n
\param[in] *HI_UNF_AI_HDMI_ATTR_S  callback function CNcomment:�ص����� CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetAudioInfo(HI_UNF_AI_HDMI_ATTR_S *pstAudioInfo);

/** 
\brief Get the signal status like no signal/unstable/support . CNcomment:��ѯ��ǰ��Ƶ�ź�״̬�����źš����ȶ����ȶ�
\attention \n
\param[in] *HI_UNF_SIG_STATUS_E  callback function CNcomment:�ص����� CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetSignalStatus(HI_UNF_SIG_STATUS_E *penStatus);

/** 
\brief Get the Audio status like no signal/unstable/support . CNcomment:��ѯ��ǰ��Ƶ�ź�״̬�����źš����ȶ����ȶ�
\attention \n
\param[in] *HI_UNF_SIG_STATUS_E  callback function CNcomment:�ص����� CNend
\retval HI_SUCCESS   success.   CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetAudioStatus(HI_UNF_SIG_STATUS_E *penStatus);

/** 
\brief Update the EDID in SRAM. CNcomment:����EDID ��SRAM�� CNend
\attention \n
\param[in] *HI_UNF_HDMIRX_EDID_S  key struct point CNcomment: key�Ľṹָ��
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_UpdateEdid(HI_UNF_HDMIRX_EDID_S *pstEdid);

/** 
\brief Update the MHL EDID in SRAM. CNcomment:����MHL EDID ��SRAM�� CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port��ID
\param[in] u32Length  The EDID Length  CNcomment: EDID ���ݳ���
\param[in] pu32Edid   The EDID Data  CNcomment: EDID ����
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_UpdateMHLEdid(HI_UNF_HDMIRX_PORT_E enPort,HI_U32 u32Length,HI_U32 *pu32Edid);


/**
\brief Load HDCP key. CNcomment:����hdcpkey CNend
\attention \n
\param[in] *HI_UNF_HDMIRX_HDCP_S  key struct point CNcomment: key�Ľṹָ��
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_UpdateHdcp(HI_UNF_HDMIRX_HDCPTYPE_E enType,HI_UNF_HDMIRX_HDCP_S *pstHdcp);

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
HI_S32 HI_UNF_HDMIRX_GetOffLineDetStatus(HI_UNF_HDMIRX_PORT_E enPort, HI_BOOL *pbConnected);


/** 
\brief  Get the port OffLineDetect format CNcomment:��ȡport�����߼���ź����� CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  The port ID  CNcomment: HDMIRX port��ID
\param[in] *HI_UNF_HDMIRX_FORMAT_E  callback the port OffLineDetect format CNcomment:�ص����������ص�ǰ�����߼���ź����� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_GetOffLineDetFormat(HI_UNF_HDMIRX_PORT_E enPort, HI_UNF_HDMIRX_FORMAT_E *penFormat);

/** 
\brief send MHL RCP Key. CNcomment:����MHL RCP Key CNend
\attention \n
\param[in] HI_UNF_HDMIRX_RCP_KEY_E  Key. CNcomment:Ҫ���͵�MHL RCP Key CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_SendRcpKey(HI_UNF_HDMIRX_RCP_KEY_E enKey);

/**
\brief send MHL RCP Key. CNcomment:���� Release MHL RCP Key CNend
\attention \n
\param[in] HI_UNF_HDMIRX_RCP_KEY_E  Key. CNcomment:Ҫ����Release��MHL RCP Key CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_ReleaseRcpKey(HI_UNF_HDMIRX_RCP_KEY_E enKey);

/**
\brief Set HotPlug Value. CNcomment:����HDMI HotPlug ֵ CNend
\attention \n
\param[in] HI_UNF_HDMIRX_PORT_E  enPort. CNcomment: HDMIRX port��ID CNend
\param[in] HI_BOOL  bValue. CNcomment: HotPlug Value CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_SetHpdValue(HI_UNF_HDMIRX_PORT_E enPort,HI_BOOL bValue);

/**
\brief disable the cec func. CNcomment:CEC ʹ��CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_Enable(HI_BOOL bEnable);

/**
\brief send the cec data. CNcomment:����CEC ���� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pstCECCmd      the cec cmd data.CNcomment:Cec Command ���� CNend
\retval HI_SUCCESS     success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_SetCommand(HI_UNF_HDMIRX_CEC_CMD_S *pstCECCmd);

/** 
\brief get the cec data received. CNcomment:���յ�CEC ���� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pstCECCmd    the cec cmd data. CNcomment:Cec Command ���� CNend
\param[in] timeout    timeout for getting cec cmd, unit: 10ms;
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_GetCommand(HI_UNF_HDMIRX_CEC_CMD_S *pstCECCmd);
/**
\brief register CEC callback function. CNcomment:ע���ȡCEC�ص����� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pCECCallback    the cec callback handle. CNcomment:�ص�������� CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_GetARCCap(HI_UNF_SND_ARC_AUDIO_CAP_S *pstARCCap);
/**
\brief register CEC callback function. CNcomment:ע���ȡCEC�ص����� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pCECCallback    the cec callback handle. CNcomment:�ص�������� CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_SND_ARC_AUDIO_CAP_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_GetARCSupported(HI_BOOL *pbARCSupported);
/**
\brief get CEC command state of sending. CNcomment:��ȡCEC�����״̬ CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pCECCallback    the cec callback handle. CNcomment:�ص�������� CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_SND_ARC_AUDIO_CAP_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_GetCurCmdState(HI_UNF_HDMIRX_CEC_CMD_STATE_S *pstCmdState);

/**
\brief register CEC callback function. CNcomment:ע���ȡCEC�ص����� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pCECCallback    the cec callback handle. CNcomment:�ص�������� CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_BOOL\n
CNcomment:�� CNend
*/

 
HI_S32 HI_UNF_HDMIRX_CEC_RegCallBackFunc(HI_UNF_HDMIRX_CEC_CALLBACK pCECCallback);

/**
\brief unregister CEC callback function. CNcomment:��ע���ȡCEC�ص����� CNend
\attention \n
\param[in] enHdmi   hdmi device id. CNcomment:HDMI�豸ID CNend
\param[in] pCECCallback  the cec callback handle. CNcomment:�ص�������� CNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_UNF_HDMI_CEC_CMD_S\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_UnRegCallBackFunc(HI_UNF_HDMIRX_CEC_CALLBACK pCECCallback);

/**
\brief set the cec standby to TV one-touch play flag. CNcomment:����TV�������Ƿ���Ӧonetouchplay���� CNend
\attention \n
\param[in] bEnable    Flag from standby to TV one-touch play. CNcomment:TV�������Ƿ���Ӧonetouchplay������־λCNend
\retval HI_SUCCESS      success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see ::HI_BOOL\n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDMIRX_CEC_StandbyEnable(HI_BOOL bEnable);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif

