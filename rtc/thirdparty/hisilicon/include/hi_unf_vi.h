/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_vi.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/11/15
  Description   : 
  History       :
  1.Date        : 2013/11/15
    Author      : c00186004/w00248302
    Modification: Created file
******************************************************************************/
/** 
 * \file
 * \brief Describes the information about the video input (VI) module.
          CNcomment:�ṩVI�������Ϣ CNend
 */
#ifndef __HI_UNF_VI_H__
#define __HI_UNF_VI_H__

#include "hi_unf_atv.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Macro Definition ****************************/
/** \addtogroup     VI */
/** @{ */  /** <!-- [VI] */

/** @} */  /*! <!-- Macro Definition End */

/*************************** Structure Definition ****************************/
/** \addtogroup     VI */
/** @{ */  /** <!-- [VI] */

/**Defines the vi type required in a VI.*/
/**CNcomment:����VI����ö�� */
typedef enum hiUNF_VI_TYPE_E
{
    HI_UNF_VI_MAIN,  /**<The main vi*//**<CNcomment: ��ͨ· */
    HI_UNF_VI_SUB,   /**<The main vi*//**<CNcomment: ��ͨ·�� һ��˫��ʱʹ�� */
    HI_UNF_VI_VIRTUAL,/* ����VI��־*/

    HI_UNF_VI_BUTT                        
} HI_UNF_VI_TYPE_E;
/**Defines the Interface mode required in a VI.*/
/**CNcomment:����VI�Խ�ʱ�� */
typedef enum hiUNF_VI_INTF_MODE_E
{
    HI_UNF_VI_INTF_FVHDE = 0,/**<The FVHDE*//**<CNcomment: FVHDEʱ�� */
    HI_UNF_VI_INTF_BT601,   /**<The BT601*//**<CNcomment: BT601ʱ�� */  
    HI_UNF_VI_INTF_BT656,  /**<The BT656*//**<CNcomment: BT656ʱ�� */
    HI_UNF_VI_INTF_BT1120, /**<The BT1120*//**<CNcomment: BT1120ʱ�� */
    
    HI_UNF_VI_INTF_BUTT
} HI_UNF_VI_INTF_MODE_E;
/**Defines the access type required in a VI.*/
/**CNcomment:����VI�Խӽӿ� */
typedef enum hiUNF_VI_ACCESS_TYPE_E
{
    HI_UNF_VI_ACCESS_TVD = 0,  /**<The access of TVD*//**<CNcomment: TVD�ӿ� */
    HI_UNF_VI_ACCESS_HDDEC,    /**<The access of HDDEC*//**<CNcomment: HDDEC�ӿ� */
    HI_UNF_VI_ACCESS_HDMI,     /**<The access of HDMI*//**<CNcomment: HDMI�ӿ� */
    HI_UNF_VI_ACCESS_EXTERN,   /**<The BT1120*//**<CNcomment: �ⲿ�ӿڣ�����:CAMERA */
    
    HI_UNF_VI_ACCESS_BUTT
} HI_UNF_VI_ACCESS_TYPE_E;

/**Defines the attribute of video frame format detect.*/
/**CNcomment: ������Ƶ֡��ʽ������Խṹ��*/
typedef struct hiUNF_VI_3D_DETECT_ATTR_S
{
    HI_BOOL               bEnable;  /**<Is 3d detect enable or not*//**<CNcomment: 3d��ʽ����Ƿ�ʹ��*/
}HI_UNF_VI_3D_DETECT_ATTR_S;


/**Defines the type of VI csc type.*/
/**CNcomment: ����VI�������Csc����*/
typedef enum hiUNF_VI_SOURCE_CSC_TYPE_E
{
    HI_UNF_VI_SOURCE_CSC_TYPE_AUTO,                   /**< Auto Type:what type in and what type out */
    HI_UNF_VI_SOURCE_CSC_TYPE_RGB_FULL,               /**< Full Range:force full range in rgb csc*/
    HI_UNF_VI_SOURCE_CSC_TYPE_RGB_LIMIT,              /**< Limit Range:force limit range in rgb csc*/
    
    HI_UNF_VI_SOURCE_CSC_TYPE_BUTT
}HI_UNF_VI_SOURCE_CSC_TYPE_E;


/**Defines the created parameters of vi*/
/** CNcomment:����ͬ��״̬��������Ľṹ�� */
typedef struct hiUNF_VI_ATTR_S
{   
    HI_UNF_VI_TYPE_E                  enType;          /**<The type of vi*//**<CNcomment: vi���ͣ�ʵ��vi��ഴ����·2D����һ·3D*/     
    HI_BOOL                           bBypassVpss;     /**<Is bypassvpss true or false*//**<CNcomment: �Ƿ�bypass��Ƶ������ϵͳ*/
    HI_UNF_VI_ACCESS_TYPE_E           enAccess;        /**<The access of vi*//**<CNcomment: ʵ��vi�Խӵ���������Դ*/ 
    HI_BOOL                           bGraphicMode;    /**<Is Graphic Mode true or false*//**<CNcomment: Graphic Timing/VideoTiming*/
    HI_UNF_VIDEO_FRAME_PACKING_TYPE_E en3dFmt;         /**<The 2d/3d format*//**<CNcomment: 2D/3D ��ʽ*/
    HI_UNF_VI_INTF_MODE_E             enIntfMode;      /**<The interface mode of vi*//**<CNcomment: ʵ��vi�ԽӵĽӿ�ʱ������*/
    HI_BOOL                           bInterlace;      /**<Is interlace or progressive*//**<CNcomment: ���и�����Ϣ*/
    HI_RECT_S                         stInputRect;     /**<The crop rect of input window*//**<CNcomment: ���봰�ڵĲü�����*/
    HI_U32                            u32Width;        /**<The width of source image*//**<CNcomment: Դͼ��һ֡�Ŀ��,3D��ʽΪ���ۿ��*/
    HI_U32                            u32Height;       /**<The height of source height*//**<CNcomment: Դͼ��һ֡�ĸ߶ȣ��������ź��������ĸ߶ȣ������ź���һ֡�ĸ߶ȣ�3D��ʽΪ���ۿ��*/
    HI_U32                            u32FrameRate;    /**<The input framerate*//**<CNcomment: ����֡�� [24Hz,85]*/
    HI_UNF_COLOR_SPACE_E              enColorSpace;    /**<The color spacet*//**<CNcomment: ��ɫ�ռ�*/
    HI_UNF_VIDEO_FORMAT_E             enPixFmt;        /**<The pixel of Format,for example,RGB444 YUV444/YUV422*//**<CNcomment: �������ظ�ʽ RGB444,YUV444/422*/
    HI_UNF_PIXEL_BITWIDTH_E           enBitWidth;      /**<The bit width,max 12bit*//**<CNcomment: ����λ�� 8/10/12BIT*/
    HI_UNF_OVERSAMPLE_MODE_E          enOverSample;    /**<The oversample mode*//**<CNcomment: ������ģʽ*/     
    HI_U32                            u32Vblank;       /**<The vblank,for the framepacking*//**<CNcomment: ����������ȣ����ڴ���3D��ʽFP*/
    HI_UNF_INPUT_SOURCE_TYPE_E        enSourceType;    /**<The input soure type*//**<CNcomment: ������Դ����*/
    HI_UNF_COLOR_SYS_E                enColorSys;      /**<The color system*//**<CNcomment: ATV/CVBS��Դ�µĲ�ɫ��ʽ*/
    HI_BOOL                           bUserOut;        /**<Is support userout ture or false*//**<CNcomment: �Ƿ�֧���û���ȡ֡����*/
} HI_UNF_VI_ATTR_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      VI*/
/** @{*/  /** <!-- -VI=*/

/**
\brief Initializes the VI module.CNcomment:��ʼ��VIģ�� CNend
\attention \n
Before calling ::HI_UNF_VI_Create to create a VI, you must call this application programming interface (API).
CNcomment �ڵ���VIģ�������ӿ�ǰ��Ҫ�����ȵ��ñ��ӿ� CNend
\param  N/A
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Init(HI_VOID);
/**
\brief Deinitializes the VI module. CNcomment:ȥ��ʼ��VIģ�� CNend
\attention \n
After calling ::HI_UNF_VI_Destroy, and Destroy all vi,Please call this API function. 
CNcomment: �ڵ���::HI_UNF_VI_Destroy�ӿ��������е�VIͨ·�󣬵��ñ��ӿ� CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_DeInit(HI_VOID);
/**
\brief Obtains the default configuration of a VI. CNcomment:��ȡȱʡ��VI���� CNend
\attention \n
It is recommended that you call this API to obtain the default vi attributes before creating a vi. This avoids creation failures due to incomplete or incorrect parameters.
CNcomment:����VIǰ������ñ��ӿڣ���ȡ��VIĬ�����ԣ����ⴴ��VIʱ���ڲ�����ȫ�����������VI�������ɹ����� CNend
\param[IN] pstViAttr  Pointer to VI attributes. For details, see the description of ::HI_UNF_VI_ATTR_S. CNcomment: ָ�����ͣ�VI�������ԣ���μ�::HI_UNF_VI_ATTR_S. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_VI_GetDefaultAttr(HI_UNF_VI_ATTR_S *pstViAttr);
/**
\brief Create a VI. CNcomment:����VI CNend
\attention \n
 You can call this API to create a vi. input created attributes, This API return the created vi handle.
CNcomment:����VIʱ���ñ��ӿڣ����봴�����ԣ�����������VI�ľ�� CNend
\param[in] pstViAttr  Pointer to VI attributes. For details, see the description of ::HI_UNF_VI_ATTR_S. CNcomment: ָ�����ͣ�VI�������ԣ���μ�::HI_UNF_VI_ATTR_S. CNend
\param[out] phVi  Pointer to VI handle. CNcomment: ָ�����ͣ�VI���. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Create(HI_UNF_VI_ATTR_S *pstViAttr, HI_HANDLE *phVi);
/**
\brief Destroy a VI. CNcomment:����VI CNend
\attention \n
 You can call this API to destroy a vi. input VI handle.
CNcomment:����VIʱ���ñ��ӿڣ����������ٵ�VI��� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Destroy(HI_HANDLE hVi);
/**
\brief Start a VI. CNcomment:����VI CNend
\attention \n
 You can call this API to start a vi. input VI handle.
CNcomment:����VIʱ���ñ��ӿڣ�������������VI��� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Start(HI_HANDLE hVi);
/**
\brief Stop a VI. CNcomment:ֹͣVI CNend
\attention \n
 You can call this API to stop a vi. input VI handle.
CNcomment:ֹͣVIʱ���ñ��ӿڣ�������ֹͣ��VI��� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Stop(HI_HANDLE hVi);

/**
\brief Update the no standard Information of a VI��special for TV. CNcomment:����VI�ķǱ���Ϣ��TV���� CNend
\attention \n
 When you need update the no standard Information of a VI, You can call this API.
CNcomment:����VI�ķǱ���Ϣ CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pstNstdInfo  Pointer to VI no standard Information. For details, see the description of ::HI_UNF_VIDEO_NONSTD_INFO_S. CNcomment: ָ�����ͣ��Ǳ���Ϣ���ԣ���μ�::HI_UNF_VIDEO_NONSTD_INFO_S. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_UpdateNstdInfo(HI_HANDLE hVi, HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);

/**
\brief User acquired frame from vi. CNcomment:�û�̬��VI��ȡ֡��һ�����������Ĭ��dump�͸�win��ͼ�� CNend
\attention \n
 When you need acquired a frame from VI, You can call this API.
CNcomment:�û�̬��VI��ȡ֡ CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pFrameInfo  Pointer to VI frame Information. For details, see the description of ::HI_UNF_VIDEO_FRAME_INFO_S. CNcomment: ָ�����ͣ�֡��Ϣ���ԣ���μ�::HI_UNF_VIDEO_FRAME_INFO_S. CNend
\param[in] u32TimeoutMs  The time of timeout. CNcomment: �û�̬��ȡ֡��ʱʱ��. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_AcquireFrame(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo, HI_U32 u32TimeoutMs);
/**
\brief User release frame to vi. CNcomment:�û�̬�ͷŻ�ȡ����֡ CNend
\attention \n
 When you need release a frame to VI, You can call this API.
CNcomment:�û�̬�ͷŻ�ȡ����֡ CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pFrameInfo  Pointer to VI frame Information. For details, see the description of ::HI_UNF_VIDEO_FRAME_INFO_S. CNcomment: ָ�����ͣ�֡��Ϣ���ԣ���μ�::HI_UNF_VIDEO_FRAME_INFO_S. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_ReleaseFrame(HI_HANDLE hVi, const HI_UNF_VIDEO_FRAME_INFO_S *pFrameInfo);

/**
\brief Enable or disable the 3D dectect. CNcomment:ʹ��/ȥʹ��3D��� CNend
\attention \n
 When you need Enable or disable the 3D dectect of a VI, You can call this API.
CNcomment:ʹ��/ȥʹ��3D��� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pstVi3dDetectAttr  Pointer to VI 3d detect attr. For details, see the description of ::HI_UNF_VI_3D_DETECT_ATTR_S. CNcomment: ָ�����ͣ�3d������ԣ���μ�::HI_UNF_VI_3D_DETECT_ATTR_S. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Set3DDetect(HI_HANDLE hVi, HI_UNF_VI_3D_DETECT_ATTR_S *pstVi3dDetectAttr);
/**
\brief Get the 3D dectect result. CNcomment:��ȡ3D����� CNend
\attention \n
 When you need Get the 3D dectect result of a VI, You can call this API.
CNcomment:��ȡ3D����� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pEframeType  Pointer to frame type. For details, see the description of ::HI_UNF_VIDEO_FRAME_PACKING_TYPE_E. CNcomment: ָ�����ͣ�3d���������μ�::HI_UNF_VIDEO_FRAME_PACKING_TYPE_E. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_Get3DResult(HI_HANDLE hVi, HI_UNF_VIDEO_FRAME_PACKING_TYPE_E  *pEframeType);
/** @} */  /** <!-- ==== API declaration end ==== */


/**
\brief Set VI source csc type. CNcomment:����VI��Csc���� CNend
\attention \n
 When you want to set VI Csc, You can call this API.
CNcomment:����VI������Դ��Csc���� CNend
\param[in] hVi  VI handle. CNcomment: 32λ������VI���. CNend
\param[in] pECscType  Pointer to Csc Range type. For details, see the description of ::HI_UNF_VI_CSC_TYPE_E. CNcomment: ָ�����ͣ�Csc���ͣ���μ�::HI_UNF_VI_CSC_TYPE_E. CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE Failure. CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_VI_SetSrcCscType(HI_HANDLE hVi, HI_UNF_VI_SOURCE_CSC_TYPE_E *pEcscType);
/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_UNF_VI_H__ */
