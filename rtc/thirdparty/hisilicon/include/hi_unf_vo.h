/******************************************************************************

  Copyright (C), 2001-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_vo.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/29
  Description   :
  History       :
  1.Date        : 2013/10/29
    Author      : z00208650
    Modification: Created file

*******************************************************************************/
/**
 * \file
 * \brief  supply info of vo module.
 */

#ifndef  __HI_UNF_VO_H__
#define  __HI_UNF_VO_H__

#include "hi_unf_common.h"
#include "hi_unf_disp.h"
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*************************** Structure Definition ****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */



/**defines the ROTATION type.*/
/**CNcomment:������Ƶ��ת�Ƕ�*/
typedef enum hiUNF_VO_ROTATION_E
{
    HI_UNF_VO_ROTATION_0, /**< 0 degree rotation*//**<CNcomment: 0����ת*/
    HI_UNF_VO_ROTATION_90, /**< 90 degree rotation*//**<CNcomment: 90����ת*/
    HI_UNF_VO_ROTATION_180, /**< 180 degree rotation*//**<CNcomment: 180����ת*/
    HI_UNF_VO_ROTATION_270, /**< 270 degree rotation*//**<CNcomment: 270����ת*/
    HI_UNF_VO_ROTATION_BUTT
}HI_UNF_VO_ROTATION_E;


/**conversion mode of AspectRatio.*/
/**CNcomment:��߱�ת��ģʽ*/
typedef enum hiUNF_VO_ASPECT_CVRS_E
{
    HI_UNF_VO_ASPECT_CVRS_IGNORE = 0x0,
    HI_UNF_VO_ASPECT_CVRS_LETTERBOX,      /**<Add black borders*//**<CNcomment: �Ӻڱ�*/
    HI_UNF_VO_ASPECT_CVRS_PAN_SCAN,      /**<Clip the picture*//**<CNcomment: �ü�*/
    HI_UNF_VO_ASPECT_CVRS_COMBINED,       /**<Add black borders and clip the picture*//**<CNcomment: �ӺڱߺͲü����*/

    HI_UNF_VO_ASPECT_CVRS_HORIZONTAL_FULL,  /**<keep picture's HORIZONTAL be full*//**<CNcomment: ����ˮƽ��������*/
    HI_UNF_VO_ASPECT_CVRS_VERTICAL_FULL,    /**<keep picture's VERTICAL be full*//**<CNcomment: ���ִ�ֱ��������*/

    /**<These mode ONLY for TV*//**<CNcomment: ����ģʽ��������TV*/
    //HI_UNF_VO_ASPECT_CVRS_TV,               /**TV����ONLY*/
    HI_UNF_VO_ASPECT_CVRS_CUSTOM,    /**<user define the output region and video region*//**<CNcomment: �û�ָ����ʾ�������Ƶ����*/
    HI_UNF_VO_ASPECT_CVRS_P2P,       /**<point to point mode*//**<CNcomment: ��Ե�ģʽ*/
    HI_UNF_VO_ASPECT_CVRS_NONLINEAR, /**<nonlinear scaler mode*//**<CNcomment: ����������ģʽ*/

    HI_UNF_VO_ASPECT_CVRS_BUTT,
} HI_UNF_VO_ASPECT_CVRS_E;


/**enum define about Window Type */
/**CNcomment:����Window����ö��*/
typedef enum hiUNF_VO_WIN_PRIORITY_E
{
    HI_UNF_VO_WIN_PRIORITY_AUTO = 0,
    HI_UNF_VO_WIN_PRIORITY_MAIN,
    HI_UNF_VO_WIN_PRIORITY_SUB,
    
    HI_UNF_VO_WIN_PRIORITY_BUTT,    
}HI_UNF_VO_WIN_PRIORITY_E;

typedef struct hiUNF_VO_NONLINEAR_SCL_S
{
    HI_BOOL     bEnable;            /**<Nonlinear enable *//**<CNcomment: ������ʹ��*/
    HI_U32      u32SrcWidth;        /**<source width of linear zone ,it should be in 0~10000 *//**<CNcomment: ������������������������Դ�Ŀ�ȣ�ȡֵ[0~10000]*/
    HI_U32      u32DstWidth;        /**<dest width of linear zone ,it should be in 0~10000 *//**<CNcomment: ������������������������Ŀ�Ŀ�ȣ�ȡֵ[0~10000]*/
} HI_UNF_VO_NONLINEAR_SCL_S;


/** AspectRatio attribute.*/
/**CNcomment:��߱�����*/
typedef struct hiUNF_WINDOW_ASPECT_ATTR_S
{
    HI_UNF_VO_ASPECT_CVRS_E   enAspectCvrs;  /**<the method to the aspect ratio transfer.\n*//**<CNcomment: ���ڵĿ��ת����ʽ */
    HI_BOOL                   bUserDefAspectRatio;  /**<use or not user define aspectratio. \n
                                                     if this is true, u32UserAspectWidth and u32UserAspectHeight will be effective.\n*/
                                                    /**<CNcomment: �Ƿ�ʹ���û��趨�Ŀ�߱�, ΪTRUEʱ��u32UserAspectWidth��u32UserAspectHeight��Ч*/
    HI_U32                    u32UserAspectWidth; /**<aspect width of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                  /**<CNcomment: �û�������ʾ����Ƶ��� \n
                                                   ����ֵ��Χ��0~3840֮�� \n
                                                   0����ʹ����ƵԴ�ֱ���*/
    HI_U32                    u32UserAspectHeight; /**<aspect height of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                    /**<CNcomment: �û�������ʾ����Ƶ�߶� \n
                                                    ����ֵ��Χ��Ҫ��0~3840�ķ�Χ�� \n
                                                    0����ʹ����ƵԴ�ֱ���*/

    HI_RECT_S                 stVideoRect;         /**<the actual video output window *//**<CNcomment: ��Ƶ������ʾ�Ĵ�С����*/
    
    HI_UNF_VO_NONLINEAR_SCL_S stNonLinearInfo;     /**<Nonlinear*//**<CNcomment: ����������*/

} HI_UNF_WINDOW_ASPECT_ATTR_S;

/**define the attribution of window.*/
/**CNcomment:����WINDOW����*/
typedef struct hiUNF_WINDOW_ATTR_S
{
    HI_UNF_DISP_E             enDisp;          /**<the display channel where window locate in. can not be modified.\n*//**<CNcomment: �������ڵ���ʾͨ��, �����󲻿��޸� */
    /* 
     * Channel type: Main/Sub/Auto, if Auto Driver 
     * will alocated Video Layer Automatically
     */
    HI_UNF_VO_WIN_PRIORITY_E    enPriority;
    HI_BOOL                   bVirtual;      /**< whether is virtual window or not. can not be modified.\n*//**<CNcomment: �Ƿ�Ϊ���ⴰ�ڣ������󲻿��޸� */
    HI_UNF_VIDEO_FORMAT_E     enVideoFormat; /**<the data format of virtual window.\n*//**<CNcomment: ���ⴰ�����ݸ�ʽ */
    HI_UNF_WINDOW_ASPECT_ATTR_S     stWinAspectAttr;  /**<the AspectRatio of window.\n*//**<CNcomment:  ���ڵĿ�߱�����*/
    HI_BOOL                   bUseCropRect;     /**<cut video frame as stCropRect struct or as stInputRect struct \n
                                                    if this is TRUE, stCropRect will be effective \n
                                                    if this is false, stInputRect will be effective.*/
                                                   /**<CNcomment: �Ƿ�ʹ��stCropRect����Ƶ������вü� \n
                                                    ΪTRUEʱ��stCropRect������Ч \n
                                                    ΪFALSEʱ��stInputRect������Ч*/

    HI_UNF_CROP_RECT_S        stCropRect;   /**<clip window of user define ,clip pix num of top,buttom,left,right.\n*/
                                            /**<CNcomment: �û��������Ƶ�ü��ṹ������, �������Ҳü������ظ���*/

    HI_RECT_S                 stInputRect;       /**<the crop area .\n
                                                  all values are zero indicate outputing whole video stream \n
                                                  if the value is bigger than video frame, the whole video frame will be displayed \n
                                                  width and height should not be less than 64.\n*/
                                                 /**<CNcomment: ���ڵĲü�����  \n
                                                  ����ֵΪ0������ʾ������Ƶͼ�� \n
                                                  ������ƵԴ��С������, ��ʾ������Ƶͼ��\n
                                                  ��Ⱥ͸߶Ȳ���С��64�������Ƶ�64*64*/

    HI_RECT_S                 stOutputRect;  /**<the window display area on the virtual screen. \n
                                                The width and height of display area should not larger than virtual screen,\n
                                                and all parameters are zero means to fill whole virtual screen.\n
                                                The area could move out of virtual screen, and the outside part will not display.\n*/
                                                /**<CNcomment: ������������Ļ�ϵ���ʾ����\n
                                                ��ʾ����Ŀ����߶Ȳ��ܴ���������Ļ�Ŀ�Ⱥ͸߶ȣ�ȫ��Ϊ0��ʾ����������Ļ��\n
                                                ��ʾ��������Ƴ�������Ļ���Ƴ���Ļ���ֲ���ʾ*/

    HI_BOOL                     bOnLeftForDualDisplay; /* Left-eye window OR Right-eye window for dual display on one screen*/
} HI_UNF_WINDOW_ATTR_S;


/**define user buffer management attribute.*/
/**CNcomment:�����û���������������*/
typedef struct hiUNF_BUFFER_ATTR_S
{
    HI_S32              s32Stride;          /**<the stride of the buffer.*//**<CNcomment: ����������*/
    HI_U32              u32PhyAddr[16];     /**<start physics addrss of the buffer.*//**<CNcomment: ������������ʼ��ַ*/
    HI_U32              u32BuffIndex[16];   /**<Stride of the buffer.*//**<CNcomment: �������������*/
    HI_S32              s32BuffNum;         /**<the number of the buffer.*//**<CNcomment: ����������*/
} HI_UNF_BUFFER_ATTR_S;

/** the running mode of vo*/
/**CNcomment:VO�豸������ģʽ */
typedef enum hiUNF_VO_DEV_MODE_E
{
    HI_UNF_VO_DEV_MODE_NORMAL,      /**<normal mode: 
                                     3716 V100/V200 :no more than 2 windows to be created.
                                     3716 v300:no more than 3 windows to be created.
                                     3712 v300:no more than 1 windows to be created.*/
                                    /**<CNcomment: ����ģʽ��
                                     3716 V100/V200:ֻ�ܴ���2��WINDOW 
                                     3716 v300: ֻ�ܴ���3��WINDOW
                                     3712 v300: ֻ�ܴ���1��WINDOW*/
    HI_UNF_VO_DEV_MODE_MOSAIC,      /**<mosaic mode: can create more than 2 windows.
                                     3712 v300: not support*/
                                    /**<CNcomment: ������ģʽ�����Դ������WINDOW 
                                     3712 v300: ��֧��*/
    HI_UNF_VO_DEV_MODE_STANDALONE,  /**<seperate mode,only 1 window can be created,and  the aspect ratio set seperately.
                                        3716 v300: not support*/
                                    /**<CNcomment: standaloneģʽ���߱�����ʾ��߱�ת����������ģʽ 
                                     3716 v300 : ��֧��*/
    HI_UNF_VO_DEV_MODE_BUTT
} HI_UNF_VO_DEV_MODE_E;

/**define the freeze mode enumeration.*/
/**CNcomment:����Freezeģʽö��*/
typedef enum hiUNF_WINDOW_FREEZE_MODE_E
{
    HI_UNF_WINDOW_FREEZE_MODE_LAST = 0,   /**<display the last frame when freeze.*//**<CNcomment: freezeʱ��ʾ���һ֡*/
    HI_UNF_WINDOW_FREEZE_MODE_BLACK = 1,  /**<display a black frame when freeze.*//**<CNcomment: freezeʱ��ʾ�����*/
    HI_UNF_WINDOW_FREEZE_MODE_BUTT
} HI_UNF_WINDOW_FREEZE_MODE_E;

typedef struct hiUNF_VO_HANDLE_S
{
    HI_HANDLE   hMainWin;                 /**<handle of main window.*//**<CNcomment: �����ھ��*/
    HI_HANDLE   hSlaveWin;                /**<handle of sub window.*//**<CNcomment: �Ӵ��ھ��*/
}HI_UNF_VO_HANDLE_S;

/**define the freeze mode enumeration.*/
/**CNcomment:����Freezeģʽö��*/
typedef enum hiUNF_VO_OWNER_E
{
    HI_UNF_WINDOW_OWNER_DTV   = 0xaa55,
    HI_UNF_WINDOW_OWNER_ATV   = 0x55aa,
    HI_UNF_WINDOW_OWNER_MEDIA = 0xa55a,
    HI_UNF_WINDOW_OWNER_BUTT  = 3
}HI_UNF_VO_OWNER_E;

/**define window owner attribute.*/
/**CNcomment:����window��owner����*/
typedef struct hiUNF_VO_OWNER_S
{
    HI_UNF_VO_OWNER_E enWinHandleOwner;
}HI_UNF_VO_OWNER_S;

typedef enum hiUNF_VO_SOURCE_E
{              
    HI_UNF_VO_SOURCE_DTV = 0,
    HI_UNF_VO_SOURCE_USB,
    HI_UNF_VO_SOURCE_ATV,
    HI_UNF_VO_SOURCE_SCART,
    HI_UNF_VO_SOURCE_SVIDEO,
    HI_UNF_VO_SOURCE_CVBS,         
    HI_UNF_VO_SOURCE_VGA,
    HI_UNF_VO_SOURCE_YPBPR,
    HI_UNF_VO_SOURCE_HDMI,
    HI_UNF_VO_SOURCE_GRAPHIC,

    HI_UNF_VO_SOURCE_BUTT
} HI_UNF_VO_SOURCE_E;

/* video frame type */
typedef enum hiUNF_VO_FRAME_3D_TYPE_E
{
    HI_UNF_VO_FT_NOT_STEREO = 0,
    HI_UNF_VO_FT_SBS,
    HI_UNF_VO_FT_TAB,
    HI_UNF_VO_FT_FPK,
    HI_UNF_VO_FT_FS,
    HI_UNF_VO_FT_BUTT
}HI_UNF_VO_FRAME_3D_TYPE_E;

/**define video timing attribute.*/
/**CNcomment:������Ƶtiming��owner����*/
typedef struct hiUNF_VO_TIMING_INFO_S
{
    HI_UNF_VO_SOURCE_E           enSource;       //DTV Default HI_UNF_SOURCE_DTV
    HI_U32                       u32Width;       //source width
    HI_U32                       u32Height;      //source height
    HI_U32                       u32FrmRate;     //source framerate
    HI_UNF_VO_FRAME_3D_TYPE_E    en3dType;       //source 3D Type
    HI_UNF_COLOR_SPACE_E         enSrcColorSpace;
    HI_UNF_COLOR_SYS_E           enColorSys;     
    HI_BOOL                      bGraphicMode;   //DTV default HI_FALSE
    HI_BOOL                      bInterlace;     //source is Interlace or Progress
}HI_UNF_VO_TIMING_INFO_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      VO */
/** @{ */  /** <!-- [VO] */

/**
\brief  init vo module.CNcomment:��ʼ��VOģ�� CNend
\attention \n
call this func before any other vo funcs .
CNcomment:����VOģ��Ҫ�����ȵ��ñ��ӿ� CNend
\param[in]   enDevMode  the vo running mode.  CNcomment:VOģ�������ģʽ CNend
\retval ::HI_SUCCESS successs.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_DEV_NOT_EXIST  vo device not exist. CNcomment:VO�豸������ CNend
\retval ::HI_ERR_VO_NOT_DEV_FILE   not vo device. CNcomment:VO���豸 CNend
\retval ::HI_ERR_VO_DEV_OPEN_ERR   open vo failed. CNcomment:VO��ʧ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal param. CNcomment:��������Ƿ� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

/**
\brief  deinit vo module.CNcomment:ȥ��ʼ��VOģ�� CNend
\attention \n
before calling this func ,you should call HI_UNF_VO_Close to close all the windows first.
CNcomment:�ڵ���::HI_UNF_VO_Close�ӿڹر����д򿪵�VO����ñ��ӿ� CNend
\param CNcomment:�� CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_DEV_CLOSE_ERR  vo deinited failed. CNcomment:VO�ر�ʧ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_DeInit(HI_VOID);

/**
\brief create the window.CNcomment:����WINDOW CNend
\attention \n
CNcomment:�� CNend
\param[in] pWinAttr   a pointer typeof HI_UNF_WINDOW_ATTR_S.CNcomment:WINDO���Խṹָ�� CNend
\param[in] phWindow   the window handler to be created.CNcomment:������WINDOW��� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_CREATE_ERR     CNcomment:����ʧ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_CreateWindow(const HI_UNF_WINDOW_ATTR_S *pWinAttr, HI_HANDLE *phWindow);

/**
\brief  destroy the given window.CNcomment:����WINDOW CNend
\attention \n
user should disable window before call this func
CNcomment:���ȵ��ýӿ�disable���ڣ� �ٵ��ô˽ӿ� CNend
\param[in] hWindow    the input window handler. CNcomment:WINDOW��� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_DestroyWindow(HI_HANDLE hWindow);

/**
\brief to enable or disable the given window.CNcomment:ʹ��/��ֹWINDOW CNend
\attention \n
Window can only be disabled after the corresponding avplay is stopped, else data will overflow.
CNcomment:ֻ���Ƚ�AVPLAY��VIDͨ��stop�󣬲��ܽ�ֹwindow�������������ݵ���� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] bEnable     the flag  of enable or disable window. CNcomment:ʹ��/��ֹ��־ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetWindowEnable(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief get the status of the given window: enable or not.CNcomment:��ȡWINDOW��ʹ��״̬ CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] pbEnable    the status of window:enable or disable.CNcomment:ʹ��/��ֹ��־. CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_GetWindowEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);

/**
\brief set the attribution of the given window.CNcomment:����WINDOW���� CNend
\attention \n
the two members of pWinAttr:enDisp and bVirtual are fixed when window created, and they can't be modified here.
Each value as HI_UNF_WINDOW_ATTR_S Definition
CNcomment:enDisp��bVirtual����һ��������Ͳ����ٽ����޸ġ������޸Ĳ���HI_UNF_WINDOW_ATTR_S�Ĳ���˵���� CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW��� CNend
\param[in] pWinAttr   the pointer of windows attr.CNcomment:WINDO���Խṹָ�� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetWindowAttr(HI_HANDLE hWindow, const HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the attribution of the given window.CNcomment:��ȡWINDOW���� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] pWinAttr    the pointer of windows attr. CNcomment:WINDO���Խṹָ�� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_GetWindowAttr(HI_HANDLE hWindow, HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the frame from given window.CNcomment:��ȡWINDOW��Frame��Ϣ CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[out] pstFrameinfo  frame information. CNcomment:Frame��Ϣ CNend
\param[in] u32TimeoutMs wait time in ms.CNcomment:�ȴ�ʱ�䣬����Ϊ��λ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited.CNcomment: VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_AcquireFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo, HI_U32 u32TimeoutMs);

/**
\brief return the frame back to the given window, used for 3d graphics testing.CNcomment:�ͷ��û���ȡWINDOW��Frame��ר������3Dͼ�β��� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_ReleaseFrame(HI_HANDLE hWindow,HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);

/**
\brief set the zorder of the given window.CNcomment:����WINDOW��Z�� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW��� CNend
\param[in] enZFlag    how to adjust zorder. CNcomment:Z����ڷ�ʽ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetWindowZorder(HI_HANDLE hWindow, HI_LAYER_ZORDER_E enZFlag);

/**
\brief get the zorder of the given window.CNcomment:��ȡWINDOW��Z�� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow       the input window handler.CNcomment:WINDOW��� CNend
\param[in] pu32Zorder    value of zoder, bigger value means higher prioty. CNcomment:Z����ֵ����ֵԽ�����ȼ�Խ�� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_GetWindowZorder(HI_HANDLE hWindow, HI_U32 *pu32Zorder);

/**
\brief attach the window with video source such as vi/avplay.CNcomment:��WINDOW��ָ����AVPLAY/VI�� CNend
\attention \n
it can attach the handler of avplay or vi to the window.
CNcomment:���Խ�AVPLAY��VI�ľ���󶨵�WINDOW�ϡ� CNend
\param[in] hWindow     the input window handler. CNcomment:WINDOW��� CNend
\param[in] hSrc        the handler of video source. CNcomment:����Դ��� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params. CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_AttachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief detach the window from the video source such as avplay or vi.CNcomment:��WINDOW��ָ����AVPLAY/VI��� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] hSrc        the handler of video source.CNcomment:����Դ��� CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: ����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_DetachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief  to freeze the video content of given window.CNcomment:����WINDOW����ʾ���� CNend
\attention \n
the display will be freezed after calling this func, but backgrounddly,the data flow is normal from video decoder.
so when freezing is cacelled, the newest video content can be display at once.
CNcomment:�˹��������ڲ��Ź����ж�����Ļ��ʾ���ݣ���ʱWINDOW�е��������������У�\n
���ȡ������󣬻�������ʾ���µ����ݡ� CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW��� CNend
\param[in] bEnable           shows whether to freeze window.CNcomment:ʹ��/��ֹ��־ CNend
\param[in] enWinFreezeMode   the mode of freeze.CNcomment:����ķ�ʽ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: ����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_FreezeWindow(HI_HANDLE hWindow, HI_BOOL bEnable, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief reset the window.CNcomment:��λWINDOW CNend
\attention \n
this function can reset buffers of the given window, and black frame or the last frame will be displayed according configuration.
CNcomment:�˹������window�еĻ��壬���ݲ�����ʾ��֡�����һ֡�� CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW��� CNend
\param[in] enWinFreezeMode   method of freeze the window.CNcomment:��λ�ķ�ʽ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_ResetWindow(HI_HANDLE hWindow, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief pass the external allocated buffer to this function to test 3d graphics.CNcomment:��WINDOW�����û��ⲿ�����buffer��ר������3Dͼ�β��� CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] pstBufAttr  external buffer.CNcomment:�ⲿ��buffer CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
//HI_S32 HI_UNF_VO_AttachExternBuffer(HI_HANDLE hWindow,HI_UNF_BUFFER_ATTR_S* pstBufAttr);

/**
\brief to set the work mode of window: quick output or not. Deinterlace alg will be disabled when quick output is enabled.
CNcomment:����WINDOW�Ƿ����ڿ������ģʽ���������ģʽǿ�ƹر�ȥ�����㷨 CNend
\attention \n
CNcomment:�� CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW��� CNend
\param[in] bQuickOutputEnable  whether determine the output mode of window. CNcomment:�������ģʽʹ��/��ֹ��־ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: ��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetQuickOutputEnable(HI_HANDLE hWindow, HI_BOOL bQuickOutputEnable);



/**
\brief  to set the filed mode of given window.CNcomment:���ô��ڵĳ�����ģʽ CNend
\attention \n
when fast-backward playing, there will be no abnormity through calling this func. But calling of this
func is forbidden when normal playing. It should be called after HI_UNF_VO_AttachWindow.
CNcomment:ͨ�����ô˽ӿ�ʹ�ܣ���֤���˲�����ֳ�ͼ����˵���������������ʱ��\n
������Ϊ��ֹ��Ĭ��Ϊ��ֹ��HI_UNF_VO_AttachWindow����֮��ʹ����Ч�� CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW��� CNend
\param[in] bEnable           wether to enable field play.CNcomment:ʹ��/��ֹ��־ CNend
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:�����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\retval ::HI_ERR_VO_WIN_UNSUPPORT  unsupported operation.CNcomment:������֧�� CNend
\see \n
CNcomment:�� CNend
*/
//HI_S32 HI_UNF_VO_SetWindowFieldMode(HI_HANDLE hWindow, HI_BOOL bEnable);


/**
\brief capture the current frame of given window.CNcomment:����WINDOW�ĵ�ǰ֡ CNend
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW��� CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: ��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: �����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_CapturePicture(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);

/**
\brief if you capture picture is finished, release the memory.CNcomment:������ϣ��ͷŲ�����ڴ����� CNend
\attention \n
this function will release captured picture, so user should call this function
after you used this captured picture.
CNcomment:���ڸú������ͷű������һ֡�������û���Ҫ�����겶��֮֡���ٵ��ô˽ӿ� CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW��� CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: ��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: �����Ƿ� CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:���ڲ����� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_CapturePictureRelease(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);

/**
\brief set window rotion type.CNcomment:���ô��ڵ���ת���� CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712��֧�� CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] enRotation    rotion type.CNcomment:��ת���� CNend
\retval ::HI_SUCCESS openned success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E enRotation);


/**
\brief get window rotion type.CNcomment:��ȡ���ڵ���ת��� CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712��֧�� CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] enRotation    rotion type.CNcomment:��ת���� CNend
\retval ::HI_SUCCESS openned success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_GetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E *penRotation);

/**
\brief flip window.CNcomment:��תwindow CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712��֧�� CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] bHoriFlip    horizon flip.CNcomment:ˮƽ��ת CNend
\param[in] bVertFlip    vertical flip.CNcomment:��ֱ��ת CNend
\retval ::HI_SUCCESS openned success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_SetFlip(HI_HANDLE hWindow, HI_BOOL bHoriFlip, HI_BOOL bVertFlip);

/**
\brief get fliping tpye of window.CNcomment:��ô��ڵķ�ת���� CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712��֧�� CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] bHoriFlip    horizon flip flag.CNcomment:ˮƽ��ת��־ CNend
\param[in] bVertFlip    vertical flip flag.CNcomment:��ֱ��ת��־ CNend
\retval ::HI_SUCCESS openned success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VOδ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:��������Ƿ� CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:����ָ��Ϊ�� CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_GetFlip(HI_HANDLE hWindow, HI_BOOL *pbHoriFlip, HI_BOOL *pbVertFlip);

/**
\brief set video stereo depth for 3D output.CNcomment:����3D�����Ƶ���� CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] s32Depth Depth of filed. the range is [-50,50].CNcomment:���ȡֵΪ[-50,50]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO δ��ʼ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_SetStereoDetpth(HI_HANDLE hWindow, HI_U32 s32Depth);

/**
\brief get video stereo depth for 3D output.CNcomment:��ȡ3D�����Ƶ���� CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pu32DepthLevel Depth of filed. the range is [0,20].CNcomment:���ȡֵΪ[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_GetStereoDetpth(HI_HANDLE hWindow, HI_U32 *pu32DepthLevel);

/**
\brief get video stereo depth range for 3D output.CNcomment:��ȡ3D�����Ƶ���Χ CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pstDepthRange Depth range of filed. the range is [0,20].CNcomment:���ȡֵΪ[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_GetStereoDetpthRange(HI_HANDLE hWindow, HI_RANGE_S *pstDepthRange);

/**
\brief get video view range for 3D output.CNcomment:��ȡ3D����ӵ㷶Χ CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pstViewRange View range. the range is [0,20].CNcomment:�ӵ㣬ȡֵΪ[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_Get3DViewRange(HI_HANDLE hWindow, HI_RANGE_S * pstViewRange);

/**
\brief set video view range for 3D output.CNcomment:����3D����ӵ� CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] u32ViewLevel View range. the range is [0,20].CNcomment:�ӵ㣬ȡֵΪ[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_Set3DViewLevel(HI_HANDLE hWindow, HI_U32 u32ViewLevel);

/**
\brief get video view for 3D output.CNcomment:��ȡ3D����ӵ�ֵ CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712��֧�� .����3D���ʱ��Ч CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pu32ViewLevel View range. the range is [0,20].CNcomment:�ӵ㣬ȡֵΪ[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:��������Ƿ� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_Get3DViewLevel(HI_HANDLE hWindow, HI_U32 *pu32ViewLevel);

/**get the default attribute of window*//**CNcomment:��ȡwindow��Ĭ������*/
/**
\get the default attribute of window.CNcomment:��ȡwindow��Ĭ���� CNend
\attention \n
\param[in] pWinAttr    data structure of winow .CNcomment:Window �����ݽṹ CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment: ���ݽṹΪ�� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_GetDefaultWindowAttr(HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\set mute color,the color is configable.CNcomment:����mute��ɫ��mute��ɫ������ CNend
\attention \n
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pstColor color to set.CNcomment:Ҫ���õ���ɫ. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:��ָ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:��Ч��� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_SetMuteColor(HI_HANDLE hWindow, HI_COLOR_S *pstColor);

/**
\acquire whole delay of video channel in ms.CNcomment:��ȡwindow�ϲ��ŵ���Ƶ��������Ƶ����ͨ·�ϵ���ʱ����λΪms CNend
\attention \n
this interface is only called in ATV
CNcomment: ������ATV���ŵ�ʱ����Ҫ���ô˽ӿ� CNend
\param[in] hWindow    window handle .CNcomment:���ھ�� CNend
\param[in] pu32VideoDelay Delay of video.CNcomment:��Ƶͨ·��ʱ. CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:��ָ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:��Ч��� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_QueryVideoDelay(HI_HANDLE hWin, HI_U32 *pu32VideoDelay);

/**
\set dual display enable.CNcomment:����һ��˫�� CNend
\attention \n
the window that has been created should exit when enable or disable dual display
CNcomment: ����һ��˫�ԵĿ��ع����У��������Ѿ�������win���� CNend
\param[in] bEnable  enable or disable dual display.CNcomment:ʹ�ܻ��߽�ֹһ��˫�� CNend
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:��ָ�� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:��Ч��� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_SetDualDisplay(HI_BOOL bEnable);

/**
\get all window handles.CNcomment:��ȡ���еĴ��ھ�� CNend
\attention \n
\param[in] enDisp  display channel select.CNcomment:��ʾͨ��ѡ�� CNend
\param[in] pWinHandle the handle to get.CNcomment:��ȡ�ľ�� 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid display channel.CNcomment:��Ч����ʾͨ�� CNend
\see \n
none.CNcomment:�� CNend
 */

HI_S32 HI_UNF_VO_GetHandle(HI_UNF_DISP_E enDisp, HI_UNF_VO_HANDLE_S
        *pWinHandle);

/**
\set window handle owner.CNcomment:����win�ľ����ӵ���� CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window ��� CNend
\param[in] pstWinHandleOwner handle owner info.CNcomment: ���ӵ���ߵ���Ϣ CNend 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:��Ч���� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_SetOwner(HI_HANDLE hWindow, HI_UNF_VO_OWNER_S *pstWinHandleOwner);

/**
\get window handle owner.CNcomment:��ȡwin�ľ����ӵ���� CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window ��� CNend
\param[in] pstWinHandleOwner handle owner info.CNcomment: ���ӵ���ߵ���Ϣ CNend 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:��Ч���� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_GetOwner(HI_HANDLE hWindow, HI_UNF_VO_OWNER_S *pstWinHandleOwner);

/**
\set video timing info.CNcomment:������Ƶ��timing ��Ϣ CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window ��� CNend
\param[in] pstTiminginfo timing info.CNcomment: timing��Ϣ CNend 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:��Ч���� CNend
\see \n
none.CNcomment:�� CNend
 */
HI_S32 HI_UNF_VO_SetTiming(HI_HANDLE hWindow, HI_UNF_VO_TIMING_INFO_S* pstTiminginfo);

/**
\queue vo user frame .CNcomment:�û�̬que֡�ӿ� CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window ��� CNend
\param[in] pstFrameinfo frame info.CNcomment: ֡��Ϣ CNend 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:��Ч���� CNend
\see \n
none.CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_QueueFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S* pstFrameinfo);

/**
\dequeue vo user frame .CNcomment:�û�̬deque֡�ӿ� CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window ��� CNend
\param[in] pstFrameinfo frame info.CNcomment: ֡��Ϣ CNend 
\retval ::HI_SUCCESS  success.CNcomment:�ɹ� CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:��Ч���� CNend
\see \n
none.CNcomment:�� CNend
*/
HI_S32 HI_UNF_VO_DeQueueFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S* pstFrameinfo, HI_U32 u32TimeoutMs);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
/************************************** The End Of File **************************************/
