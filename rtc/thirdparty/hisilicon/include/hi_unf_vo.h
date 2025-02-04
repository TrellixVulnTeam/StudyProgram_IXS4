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
/**CNcomment:定义视频旋转角度*/
typedef enum hiUNF_VO_ROTATION_E
{
    HI_UNF_VO_ROTATION_0, /**< 0 degree rotation*//**<CNcomment: 0度旋转*/
    HI_UNF_VO_ROTATION_90, /**< 90 degree rotation*//**<CNcomment: 90度旋转*/
    HI_UNF_VO_ROTATION_180, /**< 180 degree rotation*//**<CNcomment: 180度旋转*/
    HI_UNF_VO_ROTATION_270, /**< 270 degree rotation*//**<CNcomment: 270度旋转*/
    HI_UNF_VO_ROTATION_BUTT
}HI_UNF_VO_ROTATION_E;


/**conversion mode of AspectRatio.*/
/**CNcomment:宽高比转换模式*/
typedef enum hiUNF_VO_ASPECT_CVRS_E
{
    HI_UNF_VO_ASPECT_CVRS_IGNORE = 0x0,
    HI_UNF_VO_ASPECT_CVRS_LETTERBOX,      /**<Add black borders*//**<CNcomment: 加黑边*/
    HI_UNF_VO_ASPECT_CVRS_PAN_SCAN,      /**<Clip the picture*//**<CNcomment: 裁减*/
    HI_UNF_VO_ASPECT_CVRS_COMBINED,       /**<Add black borders and clip the picture*//**<CNcomment: 加黑边和裁减混合*/

    HI_UNF_VO_ASPECT_CVRS_HORIZONTAL_FULL,  /**<keep picture's HORIZONTAL be full*//**<CNcomment: 保持水平方向铺满*/
    HI_UNF_VO_ASPECT_CVRS_VERTICAL_FULL,    /**<keep picture's VERTICAL be full*//**<CNcomment: 保持垂直方向铺满*/

    /**<These mode ONLY for TV*//**<CNcomment: 以下模式仅适用于TV*/
    //HI_UNF_VO_ASPECT_CVRS_TV,               /**TV场景ONLY*/
    HI_UNF_VO_ASPECT_CVRS_CUSTOM,    /**<user define the output region and video region*//**<CNcomment: 用户指定显示区域和视频区域*/
    HI_UNF_VO_ASPECT_CVRS_P2P,       /**<point to point mode*//**<CNcomment: 点对点模式*/
    HI_UNF_VO_ASPECT_CVRS_NONLINEAR, /**<nonlinear scaler mode*//**<CNcomment: 非线性缩放模式*/

    HI_UNF_VO_ASPECT_CVRS_BUTT,
} HI_UNF_VO_ASPECT_CVRS_E;


/**enum define about Window Type */
/**CNcomment:定义Window类型枚举*/
typedef enum hiUNF_VO_WIN_PRIORITY_E
{
    HI_UNF_VO_WIN_PRIORITY_AUTO = 0,
    HI_UNF_VO_WIN_PRIORITY_MAIN,
    HI_UNF_VO_WIN_PRIORITY_SUB,
    
    HI_UNF_VO_WIN_PRIORITY_BUTT,    
}HI_UNF_VO_WIN_PRIORITY_E;

typedef struct hiUNF_VO_NONLINEAR_SCL_S
{
    HI_BOOL     bEnable;            /**<Nonlinear enable *//**<CNcomment: 非线性使能*/
    HI_U32      u32SrcWidth;        /**<source width of linear zone ,it should be in 0~10000 *//**<CNcomment: 非线性缩放中线性缩放区域源的宽度，取值[0~10000]*/
    HI_U32      u32DstWidth;        /**<dest width of linear zone ,it should be in 0~10000 *//**<CNcomment: 非线性缩放中线性缩放区域目的宽度，取值[0~10000]*/
} HI_UNF_VO_NONLINEAR_SCL_S;


/** AspectRatio attribute.*/
/**CNcomment:宽高比属性*/
typedef struct hiUNF_WINDOW_ASPECT_ATTR_S
{
    HI_UNF_VO_ASPECT_CVRS_E   enAspectCvrs;  /**<the method to the aspect ratio transfer.\n*//**<CNcomment: 窗口的宽高转换方式 */
    HI_BOOL                   bUserDefAspectRatio;  /**<use or not user define aspectratio. \n
                                                     if this is true, u32UserAspectWidth and u32UserAspectHeight will be effective.\n*/
                                                    /**<CNcomment: 是否使用用户设定的宽高比, 为TRUE时，u32UserAspectWidth和u32UserAspectHeight生效*/
    HI_U32                    u32UserAspectWidth; /**<aspect width of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                  /**<CNcomment: 用户期望显示的视频宽度 \n
                                                   设置值范围在0~3840之间 \n
                                                   0代表使用视频源分辨率*/
    HI_U32                    u32UserAspectHeight; /**<aspect height of user \n
                                                    this value should be in 0~3840 \n
                                                    zero indicate using video resolution.*/
                                                    /**<CNcomment: 用户期望显示的视频高度 \n
                                                    设置值范围需要在0~3840的范围内 \n
                                                    0代表使用视频源分辨率*/

    HI_RECT_S                 stVideoRect;         /**<the actual video output window *//**<CNcomment: 视频内容显示的大小窗口*/
    
    HI_UNF_VO_NONLINEAR_SCL_S stNonLinearInfo;     /**<Nonlinear*//**<CNcomment: 非线性缩放*/

} HI_UNF_WINDOW_ASPECT_ATTR_S;

/**define the attribution of window.*/
/**CNcomment:定义WINDOW属性*/
typedef struct hiUNF_WINDOW_ATTR_S
{
    HI_UNF_DISP_E             enDisp;          /**<the display channel where window locate in. can not be modified.\n*//**<CNcomment: 窗口所在的显示通道, 创建后不可修改 */
    /* 
     * Channel type: Main/Sub/Auto, if Auto Driver 
     * will alocated Video Layer Automatically
     */
    HI_UNF_VO_WIN_PRIORITY_E    enPriority;
    HI_BOOL                   bVirtual;      /**< whether is virtual window or not. can not be modified.\n*//**<CNcomment: 是否为虚拟窗口，创建后不可修改 */
    HI_UNF_VIDEO_FORMAT_E     enVideoFormat; /**<the data format of virtual window.\n*//**<CNcomment: 虚拟窗口数据格式 */
    HI_UNF_WINDOW_ASPECT_ATTR_S     stWinAspectAttr;  /**<the AspectRatio of window.\n*//**<CNcomment:  窗口的宽高比属性*/
    HI_BOOL                   bUseCropRect;     /**<cut video frame as stCropRect struct or as stInputRect struct \n
                                                    if this is TRUE, stCropRect will be effective \n
                                                    if this is false, stInputRect will be effective.*/
                                                   /**<CNcomment: 是否使用stCropRect对视频输入进行裁剪 \n
                                                    为TRUE时，stCropRect设置生效 \n
                                                    为FALSE时，stInputRect设置生效*/

    HI_UNF_CROP_RECT_S        stCropRect;   /**<clip window of user define ,clip pix num of top,buttom,left,right.\n*/
                                            /**<CNcomment: 用户定义的视频裁剪结构体类型, 上下左右裁剪的像素个数*/

    HI_RECT_S                 stInputRect;       /**<the crop area .\n
                                                  all values are zero indicate outputing whole video stream \n
                                                  if the value is bigger than video frame, the whole video frame will be displayed \n
                                                  width and height should not be less than 64.\n*/
                                                 /**<CNcomment: 窗口的裁减区域  \n
                                                  所有值为0代表显示整个视频图像 \n
                                                  大于视频源大小的设置, 显示整个视频图像。\n
                                                  宽度和高度不能小于64，将限制到64*64*/

    HI_RECT_S                 stOutputRect;  /**<the window display area on the virtual screen. \n
                                                The width and height of display area should not larger than virtual screen,\n
                                                and all parameters are zero means to fill whole virtual screen.\n
                                                The area could move out of virtual screen, and the outside part will not display.\n*/
                                                /**<CNcomment: 窗口在虚拟屏幕上的显示区域。\n
                                                显示区域的宽度与高度不能大于虚拟屏幕的宽度和高度，全部为0表示填满虚拟屏幕。\n
                                                显示区域可以移出虚拟屏幕，移出屏幕部分不显示*/

    HI_BOOL                     bOnLeftForDualDisplay; /* Left-eye window OR Right-eye window for dual display on one screen*/
} HI_UNF_WINDOW_ATTR_S;


/**define user buffer management attribute.*/
/**CNcomment:定义用户缓冲区管理属性*/
typedef struct hiUNF_BUFFER_ATTR_S
{
    HI_S32              s32Stride;          /**<the stride of the buffer.*//**<CNcomment: 缓冲区步长*/
    HI_U32              u32PhyAddr[16];     /**<start physics addrss of the buffer.*//**<CNcomment: 缓冲区物理起始地址*/
    HI_U32              u32BuffIndex[16];   /**<Stride of the buffer.*//**<CNcomment: 缓冲区索引编号*/
    HI_S32              s32BuffNum;         /**<the number of the buffer.*//**<CNcomment: 缓冲区个数*/
} HI_UNF_BUFFER_ATTR_S;

/** the running mode of vo*/
/**CNcomment:VO设备的运行模式 */
typedef enum hiUNF_VO_DEV_MODE_E
{
    HI_UNF_VO_DEV_MODE_NORMAL,      /**<normal mode: 
                                     3716 V100/V200 :no more than 2 windows to be created.
                                     3716 v300:no more than 3 windows to be created.
                                     3712 v300:no more than 1 windows to be created.*/
                                    /**<CNcomment: 正常模式，
                                     3716 V100/V200:只能创建2个WINDOW 
                                     3716 v300: 只能创建3个WINDOW
                                     3712 v300: 只能创建1个WINDOW*/
    HI_UNF_VO_DEV_MODE_MOSAIC,      /**<mosaic mode: can create more than 2 windows.
                                     3712 v300: not support*/
                                    /**<CNcomment: 马赛克模式，可以创建多个WINDOW 
                                     3712 v300: 不支持*/
    HI_UNF_VO_DEV_MODE_STANDALONE,  /**<seperate mode,only 1 window can be created,and  the aspect ratio set seperately.
                                        3716 v300: not support*/
                                    /**<CNcomment: standalone模式，高标清显示宽高比转换单独处理模式 
                                     3716 v300 : 不支持*/
    HI_UNF_VO_DEV_MODE_BUTT
} HI_UNF_VO_DEV_MODE_E;

/**define the freeze mode enumeration.*/
/**CNcomment:定义Freeze模式枚举*/
typedef enum hiUNF_WINDOW_FREEZE_MODE_E
{
    HI_UNF_WINDOW_FREEZE_MODE_LAST = 0,   /**<display the last frame when freeze.*//**<CNcomment: freeze时显示最后一帧*/
    HI_UNF_WINDOW_FREEZE_MODE_BLACK = 1,  /**<display a black frame when freeze.*//**<CNcomment: freeze时显示后黑屏*/
    HI_UNF_WINDOW_FREEZE_MODE_BUTT
} HI_UNF_WINDOW_FREEZE_MODE_E;

typedef struct hiUNF_VO_HANDLE_S
{
    HI_HANDLE   hMainWin;                 /**<handle of main window.*//**<CNcomment: 主窗口句柄*/
    HI_HANDLE   hSlaveWin;                /**<handle of sub window.*//**<CNcomment: 从窗口句柄*/
}HI_UNF_VO_HANDLE_S;

/**define the freeze mode enumeration.*/
/**CNcomment:定义Freeze模式枚举*/
typedef enum hiUNF_VO_OWNER_E
{
    HI_UNF_WINDOW_OWNER_DTV   = 0xaa55,
    HI_UNF_WINDOW_OWNER_ATV   = 0x55aa,
    HI_UNF_WINDOW_OWNER_MEDIA = 0xa55a,
    HI_UNF_WINDOW_OWNER_BUTT  = 3
}HI_UNF_VO_OWNER_E;

/**define window owner attribute.*/
/**CNcomment:定义window的owner属性*/
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
/**CNcomment:定义视频timing的owner属性*/
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
\brief  init vo module.CNcomment:初始化VO模块 CNend
\attention \n
call this func before any other vo funcs .
CNcomment:调用VO模块要求首先调用本接口 CNend
\param[in]   enDevMode  the vo running mode.  CNcomment:VO模块的运行模式 CNend
\retval ::HI_SUCCESS successs.CNcomment:成功 CNend
\retval ::HI_ERR_VO_DEV_NOT_EXIST  vo device not exist. CNcomment:VO设备不存在 CNend
\retval ::HI_ERR_VO_NOT_DEV_FILE   not vo device. CNcomment:VO非设备 CNend
\retval ::HI_ERR_VO_DEV_OPEN_ERR   open vo failed. CNcomment:VO打开失败 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal param. CNcomment:输入参数非法 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_Init(HI_UNF_VO_DEV_MODE_E enDevMode);

/**
\brief  deinit vo module.CNcomment:去初始化VO模块 CNend
\attention \n
before calling this func ,you should call HI_UNF_VO_Close to close all the windows first.
CNcomment:在调用::HI_UNF_VO_Close接口关闭所有打开的VO后调用本接口 CNend
\param CNcomment:无 CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_DEV_CLOSE_ERR  vo deinited failed. CNcomment:VO关闭失败 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_DeInit(HI_VOID);

/**
\brief create the window.CNcomment:创建WINDOW CNend
\attention \n
CNcomment:无 CNend
\param[in] pWinAttr   a pointer typeof HI_UNF_WINDOW_ATTR_S.CNcomment:WINDO属性结构指针 CNend
\param[in] phWindow   the window handler to be created.CNcomment:创建的WINDOW句柄 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_CREATE_ERR     CNcomment:创建失败 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_CreateWindow(const HI_UNF_WINDOW_ATTR_S *pWinAttr, HI_HANDLE *phWindow);

/**
\brief  destroy the given window.CNcomment:销毁WINDOW CNend
\attention \n
user should disable window before call this func
CNcomment:请先调用接口disable窗口， 再调用此接口 CNend
\param[in] hWindow    the input window handler. CNcomment:WINDOW句柄 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_DestroyWindow(HI_HANDLE hWindow);

/**
\brief to enable or disable the given window.CNcomment:使能/禁止WINDOW CNend
\attention \n
Window can only be disabled after the corresponding avplay is stopped, else data will overflow.
CNcomment:只有先将AVPLAY的VID通道stop后，才能禁止window，否则将引起数据的溢出 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] bEnable     the flag  of enable or disable window. CNcomment:使能/禁止标志 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetWindowEnable(HI_HANDLE hWindow, HI_BOOL bEnable);

/**
\brief get the status of the given window: enable or not.CNcomment:获取WINDOW的使能状态 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pbEnable    the status of window:enable or disable.CNcomment:使能/禁止标志. CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_GetWindowEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);

/**
\brief set the attribution of the given window.CNcomment:设置WINDOW属性 CNend
\attention \n
the two members of pWinAttr:enDisp and bVirtual are fixed when window created, and they can't be modified here.
Each value as HI_UNF_WINDOW_ATTR_S Definition
CNcomment:enDisp和bVirtual参数一旦创建后就不能再进行修改。参数修改参照HI_UNF_WINDOW_ATTR_S的参数说明。 CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pWinAttr   the pointer of windows attr.CNcomment:WINDO属性结构指针 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetWindowAttr(HI_HANDLE hWindow, const HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the attribution of the given window.CNcomment:获取WINDOW属性 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pWinAttr    the pointer of windows attr. CNcomment:WINDO属性结构指针 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_GetWindowAttr(HI_HANDLE hWindow, HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\brief get the frame from given window.CNcomment:获取WINDOW的Frame信息 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[out] pstFrameinfo  frame information. CNcomment:Frame信息 CNend
\param[in] u32TimeoutMs wait time in ms.CNcomment:等待时间，毫秒为单位 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited.CNcomment: VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_AcquireFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo, HI_U32 u32TimeoutMs);

/**
\brief return the frame back to the given window, used for 3d graphics testing.CNcomment:释放用户获取WINDOW的Frame，专门用于3D图形测试 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_ReleaseFrame(HI_HANDLE hWindow,HI_UNF_VIDEO_FRAME_INFO_S *pstFrameinfo);

/**
\brief set the zorder of the given window.CNcomment:设置WINDOW的Z序 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow    the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] enZFlag    how to adjust zorder. CNcomment:Z序调节方式 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT   VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetWindowZorder(HI_HANDLE hWindow, HI_LAYER_ZORDER_E enZFlag);

/**
\brief get the zorder of the given window.CNcomment:获取WINDOW的Z序 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow       the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pu32Zorder    value of zoder, bigger value means higher prioty. CNcomment:Z序数值，数值越大优先级越高 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_GetWindowZorder(HI_HANDLE hWindow, HI_U32 *pu32Zorder);

/**
\brief attach the window with video source such as vi/avplay.CNcomment:把WINDOW与指定的AVPLAY/VI绑定 CNend
\attention \n
it can attach the handler of avplay or vi to the window.
CNcomment:可以将AVPLAY或VI的句柄绑定到WINDOW上。 CNend
\param[in] hWindow     the input window handler. CNcomment:WINDOW句柄 CNend
\param[in] hSrc        the handler of video source. CNcomment:数据源句柄 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params. CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_AttachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief detach the window from the video source such as avplay or vi.CNcomment:把WINDOW与指定的AVPLAY/VI解绑定 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] hSrc        the handler of video source.CNcomment:数据源句柄 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: 输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_DetachWindow(HI_HANDLE hWindow, HI_HANDLE hSrc);

/**
\brief  to freeze the video content of given window.CNcomment:冻结WINDOW的显示内容 CNend
\attention \n
the display will be freezed after calling this func, but backgrounddly,the data flow is normal from video decoder.
so when freezing is cacelled, the newest video content can be display at once.
CNcomment:此功能用于在播放过程中冻结屏幕显示内容，此时WINDOW中的数据流继续运行，\n
因此取消冻结后，会立刻显示最新的内容。 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] bEnable           shows whether to freeze window.CNcomment:使能/禁止标志 CNend
\param[in] enWinFreezeMode   the mode of freeze.CNcomment:冻结的方式 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR      null pointer.CNcomment: 输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_FreezeWindow(HI_HANDLE hWindow, HI_BOOL bEnable, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief reset the window.CNcomment:复位WINDOW CNend
\attention \n
this function can reset buffers of the given window, and black frame or the last frame will be displayed according configuration.
CNcomment:此功能清空window中的缓冲，根据参数显示黑帧或最后一帧。 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] enWinFreezeMode   method of freeze the window.CNcomment:复位的方式 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_ResetWindow(HI_HANDLE hWindow, HI_UNF_WINDOW_FREEZE_MODE_E enWinFreezeMode);

/**
\brief pass the external allocated buffer to this function to test 3d graphics.CNcomment:向WINDOW传递用户外部分配的buffer，专门用于3D图形测试 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pstBufAttr  external buffer.CNcomment:外部的buffer CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
//HI_S32 HI_UNF_VO_AttachExternBuffer(HI_HANDLE hWindow,HI_UNF_BUFFER_ATTR_S* pstBufAttr);

/**
\brief to set the work mode of window: quick output or not. Deinterlace alg will be disabled when quick output is enabled.
CNcomment:设置WINDOW是否工作在快速输出模式，快速输出模式强制关闭去隔行算法 CNend
\attention \n
CNcomment:无 CNend
\param[in] hWindow     the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] bQuickOutputEnable  whether determine the output mode of window. CNcomment:快速输出模式使能/禁止标志 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetQuickOutputEnable(HI_HANDLE hWindow, HI_BOOL bQuickOutputEnable);



/**
\brief  to set the filed mode of given window.CNcomment:设置窗口的场播放模式 CNend
\attention \n
when fast-backward playing, there will be no abnormity through calling this func. But calling of this
func is forbidden when normal playing. It should be called after HI_UNF_VO_AttachWindow.
CNcomment:通过设置此接口使能，保证快退不会出现场图像回退的现象，在正常播放时，\n
请设置为禁止，默认为禁止。HI_UNF_VO_AttachWindow调用之后使用有效。 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] bEnable           wether to enable field play.CNcomment:使能/禁止标志 CNend
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT    illegal operation.CNcomment:操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\retval ::HI_ERR_VO_WIN_UNSUPPORT  unsupported operation.CNcomment:操作不支持 CNend
\see \n
CNcomment:无 CNend
*/
//HI_S32 HI_UNF_VO_SetWindowFieldMode(HI_HANDLE hWindow, HI_BOOL bEnable);


/**
\brief capture the current frame of given window.CNcomment:捕获WINDOW的当前帧 CNend
\attention \n
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: 操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_CapturePicture(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);

/**
\brief if you capture picture is finished, release the memory.CNcomment:捕获完毕，释放捕获的内存区域 CNend
\attention \n
this function will release captured picture, so user should call this function
after you used this captured picture.
CNcomment:由于该函数会释放被捕获的一帧，所以用户需要在用完捕获帧之后再调用此接口 CNend
\param[in] hWindow           the input window handler.CNcomment:WINDOW句柄 CNend
\param[in] pstCapPicture
\retval ::HI_SUCCESS CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO not inited.CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment: 输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\retval ::HI_ERR_VO_INVALID_OPT   illegal operation.CNcomment: 操作非法 CNend
\retval ::HI_ERR_VO_WIN_NOT_EXIST  windows not exist.CNcomment:窗口不存在 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_CapturePictureRelease(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S *pstCapPicture);

/**
\brief set window rotion type.CNcomment:设置窗口的旋转类型 CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712不支持 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] enRotation    rotion type.CNcomment:旋转类型 CNend
\retval ::HI_SUCCESS openned success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E enRotation);


/**
\brief get window rotion type.CNcomment:获取窗口的旋转句柄 CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712不支持 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] enRotation    rotion type.CNcomment:旋转类型 CNend
\retval ::HI_SUCCESS openned success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_GetRotation(HI_HANDLE hWindow, HI_UNF_VO_ROTATION_E *penRotation);

/**
\brief flip window.CNcomment:翻转window CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712不支持 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] bHoriFlip    horizon flip.CNcomment:水平翻转 CNend
\param[in] bVertFlip    vertical flip.CNcomment:垂直翻转 CNend
\retval ::HI_SUCCESS openned success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_SetFlip(HI_HANDLE hWindow, HI_BOOL bHoriFlip, HI_BOOL bVertFlip);

/**
\brief get fliping tpye of window.CNcomment:获得窗口的翻转类型 CNend
\attention \n
3716/3712: not support
CNcomment:3716/3712不支持 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] bHoriFlip    horizon flip flag.CNcomment:水平翻转标志 CNend
\param[in] bVertFlip    vertical flip flag.CNcomment:垂直翻转标志 CNend
\retval ::HI_SUCCESS openned success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT  VO not inited. CNcomment:VO未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA  illegal params.CNcomment:输入参数非法 CNend
\retval ::HI_ERR_VO_NULL_PTR       null pointer.CNcomment:输入指针为空 CNend
\see \n
CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_GetFlip(HI_HANDLE hWindow, HI_BOOL *pbHoriFlip, HI_BOOL *pbVertFlip);

/**
\brief set video stereo depth for 3D output.CNcomment:设置3D输出视频景深 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] s32Depth Depth of filed. the range is [-50,50].CNcomment:景深，取值为[-50,50]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NO_INIT    VO uninitialization.CNcomment:VO 未初始化 CNend
\retval ::HI_ERR_VO_INVALID_PARA   invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_SetStereoDetpth(HI_HANDLE hWindow, HI_U32 s32Depth);

/**
\brief get video stereo depth for 3D output.CNcomment:获取3D输出视频景深 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pu32DepthLevel Depth of filed. the range is [0,20].CNcomment:景深，取值为[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_GetStereoDetpth(HI_HANDLE hWindow, HI_U32 *pu32DepthLevel);

/**
\brief get video stereo depth range for 3D output.CNcomment:获取3D输出视频景深范围 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pstDepthRange Depth range of filed. the range is [0,20].CNcomment:景深，取值为[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_GetStereoDetpthRange(HI_HANDLE hWindow, HI_RANGE_S *pstDepthRange);

/**
\brief get video view range for 3D output.CNcomment:获取3D输出视点范围 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pstViewRange View range. the range is [0,20].CNcomment:视点，取值为[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_Get3DViewRange(HI_HANDLE hWindow, HI_RANGE_S * pstViewRange);

/**
\brief set video view range for 3D output.CNcomment:设置3D输出视点 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] u32ViewLevel View range. the range is [0,20].CNcomment:视点，取值为[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_Set3DViewLevel(HI_HANDLE hWindow, HI_U32 u32ViewLevel);

/**
\brief get video view for 3D output.CNcomment:获取3D输出视点值 CNend
\attention \n
3716/3712: not support.Only take effect in 3D output mode.
CNcomment: 3716/3712不支持 .仅在3D输出时有效 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pu32ViewLevel View range. the range is [0,20].CNcomment:视点，取值为[0,20]. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  invalid input parameter.CNcomment:输入参数非法 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_Get3DViewLevel(HI_HANDLE hWindow, HI_U32 *pu32ViewLevel);

/**get the default attribute of window*//**CNcomment:获取window的默认属性*/
/**
\get the default attribute of window.CNcomment:获取window的默认属 CNend
\attention \n
\param[in] pWinAttr    data structure of winow .CNcomment:Window 的数据结构 CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment: 数据结构为空 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_GetDefaultWindowAttr(HI_UNF_WINDOW_ATTR_S *pWinAttr);

/**
\set mute color,the color is configable.CNcomment:设置mute颜色，mute颜色可配置 CNend
\attention \n
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pstColor color to set.CNcomment:要设置的颜色. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:空指针 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:无效句柄 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_SetMuteColor(HI_HANDLE hWindow, HI_COLOR_S *pstColor);

/**
\acquire whole delay of video channel in ms.CNcomment:获取window上播放的视频在整个视频播放通路上的延时，单位为ms CNend
\attention \n
this interface is only called in ATV
CNcomment: 仅仅在ATV播放的时候需要调用此接口 CNend
\param[in] hWindow    window handle .CNcomment:窗口句柄 CNend
\param[in] pu32VideoDelay Delay of video.CNcomment:视频通路延时. CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:空指针 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:无效句柄 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_QueryVideoDelay(HI_HANDLE hWin, HI_U32 *pu32VideoDelay);

/**
\set dual display enable.CNcomment:设置一屏双显 CNend
\attention \n
the window that has been created should exit when enable or disable dual display
CNcomment: 设置一屏双显的开关过程中，不能有已经创建的win存在 CNend
\param[in] bEnable  enable or disable dual display.CNcomment:使能或者禁止一屏双显 CNend
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_NULL_PTR  NULL pointer.CNcomment:空指针 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid handle.CNcomment:无效句柄 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_SetDualDisplay(HI_BOOL bEnable);

/**
\get all window handles.CNcomment:获取所有的窗口句柄 CNend
\attention \n
\param[in] enDisp  display channel select.CNcomment:显示通道选择 CNend
\param[in] pWinHandle the handle to get.CNcomment:获取的句柄 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid display channel.CNcomment:无效的显示通道 CNend
\see \n
none.CNcomment:无 CNend
 */

HI_S32 HI_UNF_VO_GetHandle(HI_UNF_DISP_E enDisp, HI_UNF_VO_HANDLE_S
        *pWinHandle);

/**
\set window handle owner.CNcomment:设置win的句柄的拥有者 CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window 句柄 CNend
\param[in] pstWinHandleOwner handle owner info.CNcomment: 句柄拥有者的信息 CNend 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:无效参数 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_SetOwner(HI_HANDLE hWindow, HI_UNF_VO_OWNER_S *pstWinHandleOwner);

/**
\get window handle owner.CNcomment:获取win的句柄的拥有者 CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window 句柄 CNend
\param[in] pstWinHandleOwner handle owner info.CNcomment: 句柄拥有者的信息 CNend 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:无效参数 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_GetOwner(HI_HANDLE hWindow, HI_UNF_VO_OWNER_S *pstWinHandleOwner);

/**
\set video timing info.CNcomment:设置视频的timing 信息 CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window 句柄 CNend
\param[in] pstTiminginfo timing info.CNcomment: timing信息 CNend 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:无效参数 CNend
\see \n
none.CNcomment:无 CNend
 */
HI_S32 HI_UNF_VO_SetTiming(HI_HANDLE hWindow, HI_UNF_VO_TIMING_INFO_S* pstTiminginfo);

/**
\queue vo user frame .CNcomment:用户态que帧接口 CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window 句柄 CNend
\param[in] pstFrameinfo frame info.CNcomment: 帧信息 CNend 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:无效参数 CNend
\see \n
none.CNcomment:无 CNend
*/
HI_S32 HI_UNF_VO_QueueFrame(HI_HANDLE hWindow, HI_UNF_VIDEO_FRAME_INFO_S* pstFrameinfo);

/**
\dequeue vo user frame .CNcomment:用户态deque帧接口 CNend
\attention \n
\param[in] hWindow window handle.CNcomment:window 句柄 CNend
\param[in] pstFrameinfo frame info.CNcomment: 帧信息 CNend 
\retval ::HI_SUCCESS  success.CNcomment:成功 CNend
\retval ::HI_ERR_VO_INVALID_PARA  Invalid para.CNcomment:无效参数 CNend
\see \n
none.CNcomment:无 CNend
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
