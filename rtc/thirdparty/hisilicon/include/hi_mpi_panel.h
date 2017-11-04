/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_mpi_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/10/31
   Description   :
   History       :
   1.Date        : 2013/10/31
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


#ifndef  __HI_MPI_PANEL_H__
#define  __HI_MPI_PANEL_H__

#include "hi_unf_common.h"
#include "hi_drv_panel.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**Panel Dim strength Range*//**CNcomment:Panel PANEL Dim��ǿ�ȷ�Χ */
typedef struct hiUNF_PANEL_DIM_STRENGTH_RANGE_S
{
    HI_U32 u32MinStrength;                  /**<Dim strength Min Range */ /**<CNcomment:��Χ��Сֵ */
    HI_U32 u32MaxStrength;                  /**<Dim strength Max Range */ /**<CNcomment:��Χ���ֵ */
    
}HI_UNF_PANEL_DIM_STRENGTH_RANGE_S;

/**Panel Dim Demo mode*//**CNcomment:Panel LocalDimming��Demoģʽ */
typedef enum hiUNF_PANEL_LDM_DEMO_MODE_E
{
    HI_UNF_PANEL_LDM_DEMO_OFF,              /**<LDM type is off */ /**<CNcomment:Ldm�ر�Demoģʽ */
    HI_UNF_PANEL_LDM_DEMO_HORSELIGHT,       /**<LDM type is HORSELIGHT */ /**<CNcomment:LdmDemoģʽΪHORSELIGHT */
    HI_UNF_PANEL_LDM_DEMO_LEFT_HALF,        /**<LDM type is LEFT HALF */ /**<CNcomment:LdmDemoģʽΪLEFT HALF */
    HI_UNF_PANEL_LDM_DEMO_RIGHT_HALF,       /**<LDM type is RIGHT HALF */ /**<CNcomment:LdmDemoģʽΪRIGHT HALF */
    HI_UNF_PANEL_LDM_DEMO_TOP_HALF,         /**<LDM type is TOP HALF */ /**<CNcomment:LdmDemoģʽΪTOP HALF */
    HI_UNF_PANEL_LDM_DEMO_BOTTOM_HALF,      /**<LDM type is BOTTOM HALF */ /**<CNcomment:LdmDemoģʽΪBOTTOM HALF */
    
    HI_UNF_PANEL_LDM_DEMO_BUTT              /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
}HI_UNF_PANEL_LDM_DEMO_MODE_E;


/*************************** API declaration ****************************/
HI_S32 HI_MPI_PANEL_Init(HI_VOID);
HI_S32 HI_MPI_PANEL_DeInit(HI_VOID);

/* ������ļ�ϵͳ���������ϲ������ô˽ӿ������������ļ�ϵͳ�е�path */
HI_S32 HI_MPI_PANEL_SetPath(HI_CHAR* pcPath);

/* �ϲ�ͨ���˽ӿ�ѡ�����α�������Ӧ������ */
HI_S32 HI_MPI_PANEL_SetIndex(HI_U32 u32Index);

/* �ϲ�ͨ�����ô˽ӿڻ�ȡ���α��������εĸ��� */
HI_S32 HI_MPI_PANEL_GetTotalNum(HI_U32 *pu32TotalNum);

/* MW�ڳ�ʼ����ʱ��Ҫ���ô˽ӿ����õ�ǰʹ�õ�������Ϣ */
HI_S32 HI_MPI_PANEL_SetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);
HI_S32 HI_MPI_PANEL_GetInfo(HI_DRV_PANEL_INFO_S *pstPanelInfo);

/* ���BOOT�ѵ���MW��ʼ�����ܵ���SetPowerOn�˽ӿ�,ֻ���л����κ͹ػ����ܵ��� */
HI_S32 HI_MPI_PANEL_SetPowerOn(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetPowerOn( HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_SetBacklightEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetBacklightEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_SetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr);
HI_S32 HI_MPI_PANEL_GetIntfAttr(HI_DRV_PANEL_INTF_ATTR_S *pstIntfAttr);


HI_S32 HI_MPI_PANEL_SetFixOutRate(HI_DRV_PANEL_FIXRATE_TYPE_E enFixRateType);
HI_S32 HI_MPI_PANEL_GetFixOutRate(HI_DRV_PANEL_FIXRATE_TYPE_E *penFixRateType);

HI_S32 HI_MPI_PANEL_GetPanelAttr(HI_DRV_PANEL_ATTR_S *pstPanelAttr);

HI_S32 HI_MPI_PANEL_SetDynamicBLEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetDynamicBLEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_GetDynamicDimStrengthRange(HI_DRV_PANEL_DIM_STRENGTH_RANGE_S *pstRange);
HI_S32 HI_MPI_PANEL_SetDynamicDimStrengthLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetDynamicDimStrengthLevel(HI_U32 *pu32Level);

HI_S32 HI_MPI_PANEL_SetBacklightLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetBacklightLevel(HI_U32 *pu32Level);
HI_S32 HI_MPI_PANEL_SetLocalDimmingEnable(HI_BOOL bEnable);
HI_S32 HI_MPI_PANEL_GetLocalDimmingEnable(HI_BOOL *pbEnable);

HI_S32 HI_MPI_PANEL_GetLocalDimmingStrengthRange(HI_DRV_PANEL_DIM_STRENGTH_RANGE_S *pstRange);
HI_S32 HI_MPI_PANEL_SetLocalDimmingStrengthLevel(HI_U32 u32Level);
HI_S32 HI_MPI_PANEL_GetLocalDimmingStrengthLevel(HI_U32 *pu32Level);
HI_S32 HI_MPI_PANEL_SetLocalDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E enDemoMode);
HI_S32 HI_MPI_PANEL_GetLocalDimmingDemoMode(HI_DRV_PANEL_LDM_DEMO_MODE_E *penDemoMode);
HI_S32 HI_MPI_PANEL_GetDivideBlData(HI_U8 *pDivideBlData);

/*==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
