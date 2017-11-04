/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_winh
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/12/17
  Description   :
  History       :
  1.Date        : 2009/12/17
    Author      : w58735
    Modification: Created file

*******************************************************************************/


#ifndef __HI_MPI_WIN_H__
#define __HI_MPI_WIN_H__

#include "hi_drv_win.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif

typedef struct
{
    HI_S32                  SrcImgH;         //src img w-h
    HI_S32                  SrcImgW;
    HI_U32                  AspectWidth;     //src img w-h-aspecratio
    HI_U32                  AspectHeight;
    HI_U32                  DeviceWidth;     //device w-h-aspecratio
    HI_U32                  DeviceHeight;
    HI_DRV_ASP_RAT_MODE_E   eAspMode;
    HI_RECT_S               stInWnd;      //rect after vpss revise
    HI_RECT_S               stOutWnd;     //(1)port w-h ;(2) src img w-h(case (1)invalid).
    HI_RECT_S               stScreen;     //device w-h
}HI_MPI_WIN_RATIO_PARA_S;

HI_S32 HI_MPI_WIN_Init(HI_VOID);
HI_S32 HI_MPI_WIN_DeInit(HI_VOID);

HI_S32 HI_MPI_WIN_Create(const HI_DRV_WIN_ATTR_S *pWinAttr, HI_HANDLE *phWin);
HI_S32 HI_MPI_WIN_Destroy(HI_HANDLE hWin);

HI_S32 HI_MPI_WIN_SetAttr(HI_HANDLE hWin, const HI_DRV_WIN_ATTR_S *pWinAttr);
HI_S32 HI_MPI_WIN_GetAttr(HI_HANDLE hWin, HI_DRV_WIN_ATTR_S *pWinAttr);

HI_S32 HI_MPI_WIN_DequeueFrame(HI_HANDLE hWindow, HI_DRV_WIN_FRAME_NODE_S *pstNode);
HI_S32 HI_MPI_WIN_QueueFrame(HI_HANDLE hWindow, HI_DRV_WIN_FRAME_NODE_S *pstNode);

HI_S32 HI_MPI_WIN_QueueUselessFrame(HI_HANDLE hWindow, HI_DRV_WIN_FRAME_NODE_S *pstNode);
HI_S32 HI_MPI_WIN_QueueSyncFrame(HI_HANDLE hWindow, HI_DRV_VIDEO_FRAME_S *pFrame, HI_U32 *pu32FenceFd);



//get info for source
HI_S32 HI_MPI_WIN_GetInfo(HI_HANDLE hWin, HI_DRV_WIN_INFO_S * pstInfo);

HI_S32 HI_MPI_WIN_SetSource(HI_HANDLE hWin, HI_DRV_WIN_SRC_INFO_S *pstSrc);
HI_S32 HI_MPI_WIN_GetSource(HI_HANDLE hWin, HI_DRV_WIN_SRC_INFO_S *pstSrc);

HI_S32 HI_MPI_WIN_Reset(HI_HANDLE hWin, HI_DRV_WIN_SWITCH_E eRst);

HI_S32 HI_MPI_WIN_Pause(HI_HANDLE hWin, HI_BOOL bEnable);

HI_S32 HI_MPI_WIN_GetPlayInfo(HI_HANDLE hWin, HI_DRV_WIN_PLAY_INFO_S *pstInfo);

HI_S32 HI_MPI_WIN_SetStepMode(HI_HANDLE hWin, HI_BOOL bStepMode);
HI_S32 HI_MPI_WIN_SetStepPlay(HI_HANDLE hWin);

/* only for virtual window */
HI_S32 HI_MPI_WIN_SetExtBuffer(HI_HANDLE hWin, HI_DRV_VIDEO_BUFFER_POOL_S* pstBuf);
HI_S32 HI_MPI_WIN_AcquireFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);
HI_S32 HI_MPI_WIN_ReleaseFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);

HI_S32 HI_MPI_WIN_CapturePicture(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pstPic);
HI_S32 HI_MPI_WIN_CapturePictureRelease(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pstPic);

HI_S32 HI_MPI_WIN_SetRotation(HI_HANDLE hWin, HI_DRV_ROT_ANGLE_E enRotation);
HI_S32 HI_MPI_WIN_GetRotation(HI_HANDLE hWin, HI_DRV_ROT_ANGLE_E *penRotation);

/* when source info include flip info, we need to use Window Flip Function to get original picture */
HI_S32 HI_MPI_WIN_SetFlip(HI_HANDLE hWin, HI_BOOL bHoriFlip, HI_BOOL bVertFlip);
HI_S32 HI_MPI_WIN_GetFlip(HI_HANDLE hWin, HI_BOOL *pbHoriFlip, HI_BOOL *pbVertFlip);

HI_S32 HI_MPI_WIN_Suspend(HI_VOID);
HI_S32 HI_MPI_WIN_Resume(HI_VOID);

HI_S32 HI_MPI_WIN_GetLatestFrameInfo(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S  *frame_info);

HI_S32 HI_MPI_WIN_SetQuickOutput(HI_HANDLE hWin, HI_BOOL bEnable);
HI_S32 HI_MPI_WIN_GetQuickOutput(HI_HANDLE hWin, HI_BOOL *pbEnable);

HI_S32 HI_MPI_WIN_SendFrame(HI_HANDLE hWin, HI_DRV_VIDEO_FRAME_S *pFrameinfo);

HI_S32 HI_MPI_WIN_Freeze(HI_HANDLE hWin, HI_BOOL bEnable, HI_DRV_WIN_SWITCH_E eRst);

HI_S32 HI_MPI_WIN_SetZorder(HI_HANDLE hWin, HI_DRV_DISP_ZORDER_E ZFlag);
HI_S32 HI_MPI_WIN_GetZorder(HI_HANDLE hWin, HI_U32 *pu32Zorder);

//HI_S32 HI_DRV_WIN_UpdatePqData(HI_U32 u32UpdateType, PQ_PARAM_S* pstPqParam);
//HI_S32 HI_DRV_WIN_DQFrame(HI_HANDLE hWindow, HI_DRV_VIDEO_FRAME_S *pFrame);
HI_S32 HI_MPI_WIN_SetEnable(HI_HANDLE hWindow, HI_BOOL bEnable);
HI_S32 HI_MPI_WIN_GetEnable(HI_HANDLE hWindow, HI_BOOL *pbEnable);

/* These APIs are For VENC maybe usless in TV and Android STB*/
HI_S32 HI_MPI_WIN_GetWinParam(HI_HANDLE hWin, HI_DRV_WIN_INTF_S *pstWinIntf);
HI_S32 HI_MPI_WIN_AttachWinSink(HI_HANDLE hWin, HI_HANDLE hSink);
HI_S32 HI_MPI_WIN_DetachWinSink(HI_HANDLE hWin, HI_HANDLE hSink);


//New Add for TV Only

//����mute��ɫ��tvҪ��mute��ɫ������
HI_S32 HI_MPI_WIN_SetMuteColor(HI_HANDLE hWindow, HI_COLOR_S *pstColor);
HI_S32 HI_MPI_WIN_SetTiming(HI_HANDLE hWindow, HI_DRV_TIMING_INFO_S *pstTiming);

//������ATV���ŵ�ʱ����Ҫ���ô˽ӿ�
//��ȡwindow�ϲ��ŵ���Ƶ��������Ƶ����ͨ·�ϵ���ʱ����λΪms
HI_S32 HI_MPI_WIN_GetVideoDelay(HI_HANDLE hWin, HI_U32 *pu32VideoDelay);


/*========================һ��˫�Ե���API===========================*/

//����win֮ǰ��Ҫ����һ��˫�ԵĿ���������Ĭ�����ۻ�����Ϊ������
HI_S32 HI_MPI_WIN_SetDualDisplay(HI_BOOL bEnable, HI_BOOL bDefaultLeft);

//����win֮���Ҫ���ñ�ʾ��win��ʾ�����ۻ�������,�������������ʾ�˽ӿڱ���Ҫ����
HI_S32 HI_MPI_WIN_SetDisplayOnLeft(HI_HANDLE hWin, HI_BOOL bLeft);

HI_S32 HI_MPI_WIN_SetOwner(HI_HANDLE hWindow,
    HI_DRV_WIN_OWNER_S *pstWinHandleOwner);
HI_S32 HI_MPI_WIN_GetOwner(HI_HANDLE hWindow,
    HI_DRV_WIN_OWNER_S *pstWinHandleOwner);


HI_S32 HI_MPI_WIN_CalMediaRect(HI_RECT_S stStreamRect, HI_RECT_S *pstMediaRect);

HI_S32 HI_MPI_WIN_CalAspectRegion(HI_MPI_WIN_RATIO_PARA_S stInPara,HI_RECT_S *pstRevisedRect);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

