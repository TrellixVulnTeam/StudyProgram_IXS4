/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_vicap.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2014/07/25
  Description   : 
  History       :
  1.Date        : 2014/07/25
    Author      : w00248302
    Modification: Created file
******************************************************************************/
#ifndef __HI_DRV_VICAP_H__
#define __HI_DRV_VICAP_H__

#include "hi_drv_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

typedef enum hiDRV_VICAP_TYPE_E
{
    HI_DRV_VICAP_MAIN = 0,  
    HI_DRV_VICAP_SUB,    /* һ��˫��ʱʹ�� */
    
    HI_DRV_VICAP_BUTT                        
} HI_DRV_VICAP_TYPE_E;

typedef enum hiDRV_VICAP_3DT2D_MODE_E 
{
    HI_DRV_VICAP_3DT2D_OFF = 0,/* ����3D��ʽ����������������ͼ�� */
    HI_DRV_VICAP_3DT2D_L,      /* ����3D��ʽ������ͼ�� */
    HI_DRV_VICAP_3DT2D_R,      /* ����3D��ʽ������ͼ�� */
    
    HI_DRV_VICAP_3DT2D_BUTT,
} HI_DRV_VICAP_3DT2D_MODE_E;

typedef enum hi_DRV_VICAP_ACCESS_TYPE_E
{
    HI_DRV_VICAP_ACCESS_TVD = 0,
    HI_DRV_VICAP_ACCESS_HDDEC,
    HI_DRV_VICAP_ACCESS_HDMI,
    
    HI_DRV_VICAP_ACCESS_BUTT
} HI_DRV_VICAP_ACCESS_TYPE_E;

/* Interface mode */
typedef enum hiDRV_VICAP_INTF_MODE_E
{
    HI_DRV_VICAP_INTF_FVHDE = 0,
    HI_DRV_VICAP_INTF_BT601,     
    HI_DRV_VICAP_INTF_BT656,  
    HI_DRV_VICAP_INTF_BT1120, 
    
    HI_DRV_VICAP_INTF_BUTT
} HI_DRV_VICAP_INTF_MODE_E;

typedef enum hiDRV_VICAP_BUF_SENDTYPE_E
{
    HI_DRV_VICAP_BUF_SENDTYPE_FRAME = 0,       /**<Vicap Buf SendType by Frame*//**<CNcomment: Vicap����֡����Ϊ��֡���� */
    HI_DRV_VICAP_BUF_SENDTYPE_FIELD,           /**<Vicap Buf SendType by Field*//**<CNcomment: Vicap����֡����Ϊ�������� */
    
    HI_DRV_VICAP_BUF_SENDTYPE_BUTT
} HI_DRV_VICAP_BUF_SENDTYPE_E;

typedef enum hiDRV_VICAP_SOURCE_CSC_TYPE_E
{
    HI_DRV_VICAP_SOURCE_CSC_TYPE_AUTO,               /**< Auto Type:what type in and what type out */
    HI_DRV_VICAP_SOURCE_CSC_TYPE_RGB_FULL,               /**< Full Range:force full range in rgb csc*/
    HI_DRV_VICAP_SOURCE_CSC_TYPE_RGB_LIMIT,              /**< Limit Range:force limit range in rgb csc*/
    
    HI_DRV_VICAP_CSC_TYPE_BUTT
}HI_DRV_VICAP_SOURCE_CSC_TYPE_E;


typedef struct hi_DRV_VICAP_OUTPUT_ATTR_S
{   
    HI_DRV_VICAP_3DT2D_MODE_E en3DT2DMode;     /* ��̬,3D����ģʽ���ɰ�ģ��(VENC/VDP)ȷ�� */  
    HI_RECT_S                 stCapRect;       /* ��̬,stCapRect�ü���������overscan�ͷǱ� */
    HI_U32                    u32DestWidth;    /* ��̬,�ɰ�ģ��ȷ�����ͼ���� */
    HI_U32                    u32DestHeight;   /* ��̬,�ɰ�ģ��ȷ�����ͼ��߶� */    
    HI_DRV_PIX_FORMAT_E       enVideoFmt;      /* ��̬,�����ʽ RGB_SP444,YUV_SP444/422/420,��VI�ڲ����ݰ�ģ��(VENC/VDP)ȷ�������ʽ */
    HI_U32                    u32DstFrameRate; /* ��̬,Ĭ��Ϊ����֡�ʴ���60����60��С��60���䣻�����ɰ�ģ��ȷ�����֡�� */
    HI_DRV_PIXEL_BITWIDTH_E   enDstBitWidth;   /* ��̬,����Ϊ����λ��Ϊ8bit��8bit���������8bit��10bit����������ɰ�ģ��ȷ�����֡�� */ 
} HI_DRV_VICAP_OUTPUT_ATTR_S;

typedef struct hiDRV_VICAP_CREATE_ATTR_S
{
    HI_DRV_VICAP_TYPE_E               enType;               /* ʵ��vi��ഴ����·2D����һ·3D */   
    HI_DRV_VICAP_ACCESS_TYPE_E        enAccess;             /* ʵ��vi�Խӵ���������Դ */      
    HI_DRV_FRAME_TYPE_E               en3dFmt;              /* 2D/3D ��ʽ */
    HI_DRV_VICAP_INTF_MODE_E          enIntfMode;           /* ʵ��vi�ԽӵĽӿ�ʱ�����ͣ� */
    HI_BOOL                           bInterlace;           /* ���и�����Ϣ */
    HI_U32                            u32Width;             /* Դͼ��һ֡�Ŀ��,3D��ʽΪ���ۿ�� */
    HI_U32                            u32Height;            /* Դͼ��һ֡�ĸ߶ȣ��������ź��������ĸ߶ȣ������ź���һ֡�ĸ߶ȣ�3D��ʽΪ���ۿ�� */
    HI_U32                            u32Vblank;	        /* ����������ȣ����ڴ���3D��ʽFP */
    HI_U32                            u32FrameRate;         /* ����֡�� [24Hz,85] */
    HI_DRV_PIX_FORMAT_E               enPixFmt;             /* �������ظ�ʽ RGB444,YUV444/422 */ 
    HI_DRV_PIXEL_BITWIDTH_E           enSrcBitWidth;        /* ����λ�� 8/10/12BIT */
    HI_DRV_OVERSAMPLE_MODE_E          enOverSample;         /* ������ģʽ */ 
    HI_DRV_COLOR_SPACE_E              enColorSpace;         /* ɫ�ʿռ� */
    HI_DRV_SOURCE_E                   enSourceType;         /* ������Դ���� */
    HI_DRV_COLOR_SYS_E                enColorSys;           /* ATV/CVBS��Դ�µĲ�ɫ��ʽ */
    HI_BOOL                           bGraphicMode;         /* PC timming /Video timming*/  
    HI_U32                            u32BufNum;            /* Buf��Ŀ��һ��2ʱ�ɶ������� */
    HI_DRV_VICAP_OUTPUT_ATTR_S        stOutAttr;            /* ������ԣ�һ��2ʱ�ɶ������� */ 
    HI_DRV_VICAP_BUF_SENDTYPE_E       eBufSendType;         /* Vicap��Buf����ģʽ */
    HI_BOOL                           bUserOut;             /* �Ƿ�֧���û���ȡ֡���� */ 
    HI_DRV_VICAP_SOURCE_CSC_TYPE_E    enSrcCscMode;        /* �û���������Դ��CSCģʽ[AUTO/FULL/LIMIT]*/
} HI_DRV_VICAP_CREATE_ATTR_S;

/**defines the vicap source input type from hdmirx.*/
/**CNcomment:����VICAP��HDMIRX������Դ��������*/
typedef enum hiDRV_VICAP_SOURCE_INPUT_TYPE_E{
   HI_DRV_VICAP_SOURCE_INPUT_TYPE_SDR = 0,
   HI_DRV_VICAP_SOURCE_INPUT_TYPE_HDR10,
   HI_DRV_VICAP_SOURCE_INPUT_TYPE_UNKNOWN,

   HI_DRV_VICAP_SOURCE_INPUT_TYPE_BUTT
}HI_DRV_VICAP_SOURCE_INPUT_TYPE_E;

/**defines the vicap source input struct from hdmirx.*/
/**CNcomment:����VICAP��HDMIRX������Դ���ݽṹ*/
typedef struct hiDRV_VICAP_DYNAMIC_SOURCE_DATA_S {

    HI_DRV_VICAP_SOURCE_INPUT_TYPE_E        enSrcType;              /*������������*/
    HI_DRV_PIX_FORMAT_E                     enPixFmt;               /*���ص��ʽ*/
    HI_DRV_PIXEL_BITWIDTH_E                 enBitWidth;             /*λ��*/
    HI_DRV_COLOR_SPACE_E                    enColorSpace;           /*ɫ�ʿռ�*/
    HI_DRV_VIDEO_HDR10_METADATA_STREAM_S    stMetadata;             /*HDR10��̬metadata����*/
}HI_DRV_VICAP_DYNAMIC_SOURCE_DATA_S;

/**defines the vicap process buf event.*/
/**CNcomment:����VICAP����BUF�¼�*/
typedef enum
{   
    VICAP_EVENT_BUFLIST_FULL,
    VICAP_EVENT_NEW_FRAME,
    VICAP_EVENT_BUTT,
}HI_DRV_VICAP_EVENT_E;

/**defines the vicap process buf event callback.*/
/**CNcomment:����VICAP����BUF�¼��ص�
    VICAP_EVENT_BUFLIST_FULL:�ɼ�֡����
    VICAP_EVENT_NEW_FRAME:��֡�ɼ����*/
typedef HI_S32 (*PFN_VICAP_CALLBACK)(HI_HANDLE hDst, HI_DRV_VICAP_EVENT_E enEventID, HI_VOID *pstArgs);


HI_S32  HI_DRV_VICAP_Init(HI_VOID);
HI_VOID HI_DRV_VICAP_DeInit(HI_VOID);
HI_S32  HI_DRV_VICAP_Create(HI_DRV_VICAP_CREATE_ATTR_S *pstVicapAttr, HI_HANDLE *phVicap);
HI_S32  HI_DRV_VICAP_Destroy(HI_HANDLE hVicap);
HI_S32  HI_DRV_VICAP_Start(HI_HANDLE hVicap);
HI_S32  HI_DRV_VICAP_Stop(HI_HANDLE hVicap);
HI_S32  HI_DRV_VICAP_GetOutputAttr(HI_HANDLE hVicap, HI_DRV_VICAP_OUTPUT_ATTR_S *pstOutAttr);
HI_S32  HI_DRV_VICAP_SetOutputAttr(HI_HANDLE hVicap, HI_DRV_VICAP_OUTPUT_ATTR_S *pstOutAttr);
HI_S32  HI_DRV_VICAP_AcquireFrame(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
HI_S32  HI_DRV_VICAP_ReleaseFrame(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
HI_S32  HI_DRV_VICAP_UserAcquireFrame(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo, HI_U32 u32TimeoutMs);
HI_S32  HI_DRV_VICAP_UserReleaseFrame(HI_HANDLE hVicap, HI_DRV_VIDEO_FRAME_S *pFrameInfo);
HI_S32  HI_DRV_VICAP_UpdataDynamicSourceData(HI_U32 u32VicapId, HI_DRV_VICAP_DYNAMIC_SOURCE_DATA_S *pstDynamicSourceData);
HI_S32  HI_DRV_VICAP_RegistHook(HI_HANDLE hVicap, HI_HANDLE hDst, PFN_VICAP_CALLBACK pfVicapCallback);
HI_S32  HI_DRV_VICAP_SetSrcCscType(HI_HANDLE hVicap, HI_DRV_VICAP_SOURCE_CSC_TYPE_E *pEcscType);
HI_S32  HI_DRV_VICAP_UpdataDynamicSourceData(HI_U32 u32VicapId, HI_DRV_VICAP_DYNAMIC_SOURCE_DATA_S *pstDynamicSourceData);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_DRV_VICAP_H__ */
