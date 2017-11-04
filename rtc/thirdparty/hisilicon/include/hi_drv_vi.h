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

#ifndef __HI_DRV_VI_H__
#define __HI_DRV_VI_H__

#include "hi_debug.h"
#include "hi_module.h"
#include "hi_drv_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define HI_FATAL_VI(fmt...) HI_FATAL_PRINT(HI_ID_VI, fmt)
#define HI_ERR_VI(fmt...)   HI_ERR_PRINT(HI_ID_VI, fmt)
#define HI_WARN_VI(fmt...)  HI_WARN_PRINT(HI_ID_VI, fmt)
#define HI_INFO_VI(fmt...)  HI_INFO_PRINT(HI_ID_VI, fmt)
#define HI_DEBUG_VI(fmt...) HI_DBG_PRINT(HI_ID_VI, fmt)

#define MAX_VI_EXT_BUF_NUM  16

typedef enum hiDRV_VI_TYPE_E
{
    HI_DRV_VI_MAIN,   
    HI_DRV_VI_SUB,    /* һ��˫�Ի��򵥶���Դת��ʱʹ�� */
    HI_DRV_VI_VIRTUAL,/* STB����VI */   

    HI_DRV_VI_BUTT                        
} HI_DRV_VI_TYPE_E;

typedef enum hiDRV_VI_BUF_MGMT_E
{
    HI_DRV_VI_BUF_ALLOC = 0,  /* VI����֡BUF */
    HI_DRV_VI_BUF_MMAP,       /* �û�����֡BUF����ӳ���VI */
    HI_DRV_VI_BUF_AUTO,       /* VI�ڲ���������֡BUF��Ŀ */
    
    HI_DRV_VI_BUF_BUTT
} HI_DRV_VI_BUF_MGMT_E;

/* Interface mode */
typedef enum hiDRV_VI_INTF_MODE_E
{
    HI_DRV_VI_INTF_FVHDE = 0,
    HI_DRV_VI_INTF_BT601,     
    HI_DRV_VI_INTF_BT656,  
    HI_DRV_VI_INTF_BT1120, 
    
    HI_DRV_VI_INTF_BUTT
} HI_DRV_VI_INTF_MODE_E;

typedef enum hiDRV_VI_ACCESS_TYPE_E
{
    HI_DRV_VI_ACCESS_TVD = 0,
    HI_DRV_VI_ACCESS_HDDEC,
    HI_DRV_VI_ACCESS_HDMI,
    HI_DRV_VI_ACCESS_EXTERN,/* �ⲿ�ӿڣ�����:CAMERA */
    
    HI_DRV_VI_ACCESS_BUTT
} HI_DRV_VI_ACCESS_TYPE_E;

typedef struct hiDRV_VI_BUF_ATTR_S
{
    HI_U32 u32UsrVirAddr[MAX_VI_EXT_BUF_NUM];  /**<User virtual address *//**<CNcomment: �û�̬�����ַ*/
    HI_U32 u32PhyAddr[MAX_VI_EXT_BUF_NUM];     /**<Physical address *//**<CNcomment: �����ַ*/
    HI_U32 u32BufNum;                          /**<Buffer number *//**<CNcomment: ����������*/
    HI_U32 u32Stride;                          /**<Stride of external frame buffer *//**<CNcomment:�ⲿ֡���stride*/
} HI_DRV_VI_BUF_ATTR_S;

typedef enum hiDRV_VI_SOURCE_CSC_TYPE_E
{
    HI_DRV_VI_SOURCE_CSC_TYPE_AUTO = 0,                
    HI_DRV_VI_SOURCE_CSC_TYPE_RGB_FULL,                    
    HI_DRV_VI_SOURCE_CSC_TYPE_RGB_LIMIT,        

    HI_DRV_VI_SOURCE_CSC_TYPE_BUTT
}HI_DRV_VI_SOURCE_CSC_TYPE_E;

typedef struct hiDRV_VI_ATTR_S
{   
    HI_DRV_VI_TYPE_E          enType;       /* ʵ��vi��ഴ����·2D����һ·3D */       
    HI_BOOL                   bBypassVpss;  /* �Ƿ�bypass��Ƶ������ϵͳ */
    HI_DRV_VI_ACCESS_TYPE_E   enAccess;     /* ʵ��vi�Խӵ���������Դ */    
    HI_BOOL                   bGraphicMode; /* Graphic Timing/VideoTiming */
    HI_DRV_FRAME_TYPE_E       en3dFmt;      /* 2D/3D ��ʽ */ 
    HI_DRV_VI_INTF_MODE_E     enIntfMode;   /* ʵ��vi�ԽӵĽӿ�ʱ�����ͣ� */
    HI_BOOL                   bInterlace;   /* ���и�����Ϣ */
    HI_RECT_S                 stInputRect;  /* ���봰�ڵĲü����� */
    HI_U32                    u32Width;     /* Դͼ��һ֡�Ŀ��,3D��ʽΪ���ۿ�� */
    HI_U32                    u32Height;    /* Դͼ��һ֡�ĸ߶ȣ��������ź��������ĸ߶ȣ������ź���һ֡�ĸ߶ȣ�3D��ʽΪ���ۿ�� */
    HI_U32                    u32FrameRate; /* ����֡�� [24Hz,85] */  
    HI_DRV_COLOR_SPACE_E      enColorSpace; /* ��ɫ�ռ� */
    HI_DRV_PIX_FORMAT_E       enPixFmt;     /* �������ظ�ʽ RGB444,YUV444/422 */ 
    HI_DRV_PIXEL_BITWIDTH_E   enBitWidth;   /* ����λ�� 8/10/12BIT */
    HI_DRV_OVERSAMPLE_MODE_E  enOverSample; /* ������ģʽ */      
    HI_U32                    u32Vblank;    /* ����������ȣ����ڴ���3D��ʽFP */      
    HI_DRV_SOURCE_E           enSourceType; /* ������Դ���� */
    HI_DRV_COLOR_SYS_E        enColorSys;   /* ATV/CVBS��Դ�µĲ�ɫ��ʽ */
    HI_DRV_VI_BUF_MGMT_E      enBufMgmtMode;/* ALLOC VI�ڲ����䣬Buf���ڲ����߻����ȡdefaultֵ */    
    HI_U32                    u32BufNum;    /* VI��Ҫ��buffer��Ŀ���������������buffer */        
    HI_BOOL                   bUserOut;     /* �Ƿ�֧���û���ȡ֡���� */ 
} HI_DRV_VI_ATTR_S;

HI_S32 HI_DRV_VI_Create(HI_DRV_VI_ATTR_S *pstViAttr, HI_HANDLE *phVi);

HI_S32 HI_DRV_VI_Destroy(HI_HANDLE hVi);

HI_S32 HI_DRV_VI_Attach(HI_HANDLE hVi, HI_HANDLE hDest);

HI_S32 HI_DRV_VI_Detach(HI_HANDLE hVi, HI_HANDLE hDest);

HI_S32 HI_DRV_VI_Start(HI_HANDLE hVi);

HI_S32 HI_DRV_VI_Stop(HI_HANDLE hVi);

HI_S32 HI_DRV_VI_UpdateNstdInfo(HI_HANDLE hVi, HI_DRV_VIDEO_NONSTD_INFO_S *pstNstdInfo);

HI_S32 HI_DRV_VI_ChangeWinInfo(HI_HANDLE hPath, HI_DRV_PRE_PROCESS_INFO_S *pstWinInfo);
HI_S32 HI_DRV_VI_ReleaseImage(HI_HANDLE hPath, HI_DRV_VIDEO_FRAME_S *pstFrame);

HI_S32 HI_DRV_VI_AcquireFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame, HI_U32 u32TimeoutMs);

HI_S32 HI_DRV_VI_ReleaseFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);

HI_S32 HI_DRV_VI_DequeueFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);

HI_S32 HI_DRV_VI_QueueFrame(HI_HANDLE hVi, HI_DRV_VIDEO_FRAME_S *pstViFrame);

HI_S32 HI_DRV_VI_SetExtBuf(HI_HANDLE hVi, HI_DRV_VI_BUF_ATTR_S *pstBufAttr);

HI_S32 HI_DRV_VI_UserChangeWinInfo(HI_HANDLE hVi, HI_HANDLE hDest, 
                                             HI_DRV_PRE_PROCESS_INFO_S *pstWinInfo);

HI_S32 HI_DRV_VI_UserChangeVencInfo(HI_HANDLE hVi, HI_HANDLE hDest
                                              , HI_U32 u32Width, HI_U32 u32Height);

HI_S32 HI_DRV_VI_UserChangeDstFrmRate(HI_HANDLE hVi, HI_HANDLE hDest, HI_U32 u32DstFrmRate);

HI_S32 HI_DRV_VI_3DDectEnable(HI_HANDLE hVi, HI_BOOL bEnable);

HI_S32 HI_DRV_VI_3DDectQueryResult(HI_HANDLE hVi, HI_DRV_FRAME_TYPE_E *pEframeType);

HI_S32 HI_DRV_VI_SetSrcCscType(HI_HANDLE hVi, HI_DRV_VI_SOURCE_CSC_TYPE_E *pEcscType);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_DRV_VI_H__ */
