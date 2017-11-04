/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_drv_vfe.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/08/15
  Description   : 
  History       :
  1.Date        : 2012/08/15
    Author      : c00186004/t00202585/x00185802
    Modification: Created file
******************************************************************************/

#ifndef __HI_DRV_VFE_EXT_H__
#define __HI_DRV_VFE_EXT_H__

#include "hi_type.h"
#include <linux/fs.h>
#include "hi_unf_hddec.h"
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

/************************** Macro Definition Start***************************/
#define VFE_INVALID_HANDLE          0xFF
/*************************** Macro Definition End****************************/

/************************* Variable Definition Start*************************/
/* ͬ������ */
typedef enum hiDRV_VFE_SYNC_TYPE_E 
{
    HI_DRV_VFE_SYNC_NONSEP = 0,
    HI_DRV_VFE_SYNC_SEP,       /* ��ͬ�� */
    
    HI_DRV_VFE_SYNC_BUTT,
} HI_DRV_VFE_SYNC_TYPE_E;

/* ���������ͨ�� */
typedef enum hiDRV_VFE_DATA_CHN_TYPE_E 
{
    HI_DRV_VFE_DATA_CHN_R = 0, /* R/Pr/SIF����ͨ· */
    HI_DRV_VFE_DATA_CHN_G,     /* G/Y����ͨ· */
    HI_DRV_VFE_DATA_CHN_B,     /* B/Pb����ͨ· */
    HI_DRV_VFE_DATA_CHN_COM,   /* CVBS�����ź�����ͨ· */
    
    HI_DRV_VFE_DATA_CHN_BUTT,
} HI_DRV_VFE_DATA_CHN_TYPE_E;

/* ��Slicerͬ��������ͨ����Ŀǰֻ��ʹ��ͨ��0 */
typedef enum hiDRV_VFE_SYNC_CHN_TYPE_E 
{
    HI_DRV_VFE_SYNC_CHN_1 = 0, /* SLICER SYNCͨ·1 */
    HI_DRV_VFE_SYNC_CHN_2,     /* SLICER SYNCͨ·2 */
    
    HI_DRV_VFE_SYNC_CHN_BUTT,
} HI_DRV_VFE_SYNC_CHN_TYPE_E;

/* ��ͨ�˲���LPF��ģʽ */
typedef enum hiDRV_VFE_LPF_MODE_E
{
    HI_DRV_VFE_LPF_MODE_163M = 0,/* ��ͨ�˲�������163M */
    HI_DRV_VFE_LPF_MODE_107M,   
    HI_DRV_VFE_LPF_MODE_80M,
    HI_DRV_VFE_LPF_MODE_62M,
    HI_DRV_VFE_LPF_MODE_45M,
    HI_DRV_VFE_LPF_MODE_36M,
    HI_DRV_VFE_LPF_MODE_28M,
    HI_DRV_VFE_LPF_MODE_20M,
    HI_DRV_VFE_LPF_MODE_OFF,
    
    HI_DRV_VFE_LPF_MODE_BUTT,
} HI_DRV_VFE_LPF_MODE_E;

/* Ƕλ�������͵������ƻ��ǵ�ѹ���� */
typedef enum hiDRV_VFE_CLAMP_SEL_E 
{
    HI_DRV_VFE_CLAMP_I = 0,/* iclamp */
    HI_DRV_VFE_CLAMP_V,    /* vclamp */
    HI_DRV_VFE_CLAMP_I_V,  /* iclamp��vclamp */
    
    HI_DRV_VFE_CLAMP_BUTT,
} HI_DRV_VFE_CLAMP_SEL_E;

/* Ƕλλ��:������ƽ���м����� */
typedef enum hiDRV_VFE_VCLAMP_TYPE_E
{
    HI_DRV_VFE_VCLAMP_ON_BLANK = 0,/* Ƕλ��������ƽ */
    HI_DRV_VFE_VCLAMP_ON_MIDDLE,   /* Ƕλ���м����� */
    
    HI_DRV_VFE_VCLAMP_ON_BUTT,
} HI_DRV_VFE_VCLAMP_TYPE_E;

/*Ƕλ������ƽ�ĵ�ѹ*/
typedef enum hiDRV_VFE_VCLAMP_BLK_LEVEL_E
{
    HI_DRV_VFE_VCLAMP_BLK_0_25V = 0,/* Ƕλ������ƽ��ѹ0.25V */
    HI_DRV_VFE_VCLAMP_BLK_0_30V,
    HI_DRV_VFE_VCLAMP_BLK_0_35V,
    HI_DRV_VFE_VCLAMP_BLK_0_40V,
    HI_DRV_VFE_VCLAMP_BLK_0_45V,
    HI_DRV_VFE_VCLAMP_BLK_0_50V,
    HI_DRV_VFE_VCLAMP_BLK_0_55V,
    HI_DRV_VFE_VCLAMP_BLK_0_60V,
    
    HI_DRV_VFE_VCLAMP_BLK_BUTT,
} HI_DRV_VFE_VCLAMP_BLK_LEVEL_E;

/* Ƕλ������ƽ�ĵ�ѹ */
typedef enum hiDRV_VFE_VCLAMP_MID_LEVEL_E
{
    HI_DRV_VFE_VCLAMP_MID_0_7V = 0,/* Ƕλ�м��ѹ0.7V */
    HI_DRV_VFE_VCLAMP_MID_0_8V,
    HI_DRV_VFE_VCLAMP_MID_0_9V,
    HI_DRV_VFE_VCLAMP_MID_1_0V,
    
    HI_DRV_VFE_VCLAMP_MID_BUTT,
} HI_DRV_VFE_VCLAMP_MID_LEVEL_E;

/* ����ǯλiclamp������С����ʼ�����Ͳ��� */
typedef enum hiDRV_VFE_IMAX_TYPE_E 
{
    HI_DRV_VFE_IMAX_TYPE_100 = 0,   /* ��ʼ����Ϊ100uA,ÿһ�ȼ�����Ϊ250uA */        
    HI_DRV_VFE_IMAX_TYPE_25,/* ��ʼ����Ϊ25uA,ÿһ�ȼ�����Ϊ25uA */
    
    HI_DRV_VFE_IMAX_TYPE_BUTT,
} HI_DRV_VFE_IMAX_TYPE_E;

/* ����ģʽ */
typedef enum hiDRV_VFE_WORK_MODE_E 
{
    HI_DRV_VFE_WORK_MODE_HDDEC = 0,
    HI_DRV_VFE_WORK_MODE_TVD,
    HI_DRV_VFE_WORK_MODE_TVD_RF,
    
    HI_DRV_VFE_WORK_MODE_BUTT,
} HI_DRV_VFE_WORK_MODE_E;

/* comͨ��fiter��ƫ�õ��� */
typedef enum hiDRV_VFE_FILTER_IB_E 
{
    HI_DRV_VFE_FILTER_IB_10 = 0,/* 10ua */
    HI_DRV_VFE_FILTER_IB_20,
    HI_DRV_VFE_FILTER_IB_30,
    HI_DRV_VFE_FILTER_IB_40,
    
    HI_DRV_VFE_FILTER_IB_BUTT,
} HI_DRV_VFE_FILTER_IB_E;

typedef enum hiDRV_VFE_FILTER_R_E 
{
    HI_DRV_VFE_FILTER_R_11K = 0,/* �������11K */
    HI_DRV_VFE_FILTER_R_13K,
    HI_DRV_VFE_FILTER_R_15K,
    HI_DRV_VFE_FILTER_R_17K,
    
    HI_DRV_VFE_FILTER_R_BUTT,
} HI_DRV_VFE_FILTER_R_E;

typedef enum hiDRV_VFE_FILTER_GAIN_E 
{
    HI_DRV_VFE_FILTER_GAIN_MINUS_6DB = 0,/* �������11K */
    HI_DRV_VFE_FILTER_GAIN_0DB,
    HI_DRV_VFE_FILTER_GAIN_6DB,
    HI_DRV_VFE_FILTER_GAIN_12DB,
    
    HI_DRV_VFE_FILTER_GAIN_BUTT,
} HI_DRV_VFE_FILTER_GAIN_E;

typedef enum hiDRV_VFE_VIDEO_OUT_CHN_E 
{
    HI_DRV_VFE_VIDEO_OUT_CHN_1 = 0, /* VIDEO OUTͨ·1 */
    HI_DRV_VFE_VIDEO_OUT_CHN_2,     /* VIDEO OUTͨ·2 */
    
    HI_DRV_VFE_VIDEO_OUT_CHN_BUTT,
} HI_DRV_VFE_VIDEO_OUT_CHN_E;

typedef struct hiDRV_VFE_INPUT_ATTR_S 
{
	HI_UNF_HDDEC_SRC_TYPE_E enSrcType;    /* Equator???? */
    HI_DRV_VFE_WORK_MODE_E  enWorkMode;   /* Equator�Ĺ���ģʽ */
    HI_UNF_INPUT_MUX_E      enRChnMux;    /* R/PR       [0,3] */
    HI_UNF_INPUT_MUX_E      enGChnMux;    /* G/Y�����ź� [0,3] */
    HI_UNF_INPUT_MUX_E      enBChnMux;    /* B/PB�����ź� [0,3] */
    HI_UNF_INPUT_MUX_E      enCvbsChnMux; /* CVBS���������źţ�[0,3] */
    HI_UNF_INPUT_MUX_SOG_E  enSogChnMux;  /* sync slicerͬ�������źţ�����sog/soyͬ������ */
    HI_UNF_INPUT_MUX_SYNC_E enSyncChnMux; /* VGA����ͬ��sepͬ������ */
} HI_DRV_VFE_SOURCE_ATTR_S;

typedef struct hiDRV_VFE_PLL_ATTR_S
{	
    HI_BOOL  bBypassDpll;  /* �Ƿ�ֱ�����������DPLL */
    HI_U32   u32SampleClk; /* Ŀ���������ʱ�ӣ���λΪKHz */
    HI_U32   u32HTotal;   /* ͨ��DPLLʱ�ķ�Ƶ������Ϊʱ���HTOTAL */	
} HI_DRV_VFE_PLL_ATTR_S;

typedef struct hiDRV_VFE_VCLAMP_ATTR_S
{
    HI_DRV_VFE_VCLAMP_TYPE_E      enVclampType;/* Ƕλģʽ */
    HI_DRV_VFE_VCLAMP_BLK_LEVEL_E enBlkLevel;  /* Ƕλ������ƽ�ĵ�ѹ */
    HI_DRV_VFE_VCLAMP_MID_LEVEL_E enMidLevel;  /* Ƕλ�м��ƽ�ĵ�ѹ */
} HI_DRV_VFE_VCLAMP_ATTR_S;

typedef struct hiDRV_VFE_ICLAMP_ATTR_S
{
    HI_DRV_VFE_IMAX_TYPE_E   enImaxType;     /* ����Ƕλ�ĵ�����С�ĵ��ڷ�Χѡ����iclamp_level���ʹ�� */
    HI_U32 u32IclampLevel;  /* ����Ƕλ�ĵ�����С��0-16��0����ʾ25/250u�������� */
} HI_DRV_VFE_ICLAMP_ATTR_S;

/* ͨ��ǯλ���������� */
typedef struct hiDRV_VFE_CLAMP_ATTR_S
{	
    HI_DRV_VFE_CLAMP_SEL_E   enClampType;    /* Ƕλ�������͵������ƻ��ǵ�ѹ���� */
    HI_DRV_VFE_VCLAMP_ATTR_S stVclampAttr;   /* ��ѹǶλ���� */
    HI_DRV_VFE_ICLAMP_ATTR_S stIclampAttr;   /* ����Ƕλ���� */
} HI_DRV_VFE_CLAMP_ATTR_S;

/* ��ͨ�˲���LPF��ģʽ */
typedef struct hiDRV_VFE_FILTER_ATTR_S
{
    HI_BOOL bFilterEn;
    HI_DRV_VFE_FILTER_GAIN_E enFilterGain;
    HI_DRV_VFE_FILTER_IB_E   enFilterIb;
    HI_DRV_VFE_FILTER_R_E    enFilterR;
} HI_DRV_VFE_FILTER_ATTR_S;

/* �ĸ�����ͨ�����˲���ģʽ */
typedef union hiDRV_VFE_LPF_FILTER_ATTR_U
{
    HI_DRV_VFE_LPF_MODE_E    enRGBChnLpfMode;
    HI_DRV_VFE_FILTER_ATTR_S stComChnFilter;
} HI_DRV_VFE_LPF_FILTER_ATTR_U;

typedef enum hiHI_DRV_VFE_SYNC2_IN_SEL_E 
{
    VFE_SYNC2_IN_SEL_SOG = 0,
    VFE_SYNC2_IN_SEL_SOY0,
    VFE_SYNC2_IN_SEL_SOY1,
    VFE_SYNC2_IN_SEL_CVBS0,
    VFE_SYNC2_IN_SEL_CVBS1,   
    VFE_SYNC2_IN_SEL_CVBS2,
    
    VFE_SYNC2_IN_SEL_BUTT,
} HI_DRV_VFE_SYNC2_IN_SEL_E;

typedef enum hiHI_DRV_VFE_SCART_PIN8_SEL_E 
{
    VFE_SCART_PIN8_SEL_ADC0 = 0,
    VFE_SCART_PIN8_SEL_ADC1,
    
    VFE_SCART_PIN8_SEL_BUTT,
} HI_DRV_VFE_SCART_PIN8_SEL_E;

typedef struct hiHI_DRV_VFE_OFFLINE_ATTR_S
{
    HI_DRV_VFE_WORK_MODE_E     enVfeWorkMode;
    HI_UNF_INPUT_MUX_OFFLINE_E enOfflineMux;
    HI_UNF_INPUT_MUX_SYNC_E    enHVSyncMux;
} HI_DRV_VFE_OFFLINE_ATTR_S;

/************************** Variable Definition End**************************/

/* VFE�ĳ�ʼ����ȥ��ʼ�� */
HI_S32 HI_DRV_VFE_Init(HI_VOID);
HI_S32 HI_DRV_VFE_DeInit(HI_VOID);

HI_S32 HI_DRV_VFE_AdcCal(HI_VOID);
HI_S32 HI_DRV_VFE_ApllCfg7(HI_U32 u32ApllCfg1, HI_U32 u32ApllCfg2);

/* VFE�����ӺͶϿ� */
HI_S32 HI_DRV_VFE_Connect(HI_HANDLE *phVfe, HI_DRV_VFE_SOURCE_ATTR_S *pstSource);
HI_S32 HI_DRV_VFE_Disconnect(HI_HANDLE hVfe);

/* ����PLL��ʱ�� */
HI_S32 HI_DRV_VFE_SetPllAttr(HI_HANDLE hVfe, HI_DRV_VFE_PLL_ATTR_S *pstPllAttr);
HI_S32 HI_DRV_VFE_GetPllAttr(HI_HANDLE hVfe, HI_DRV_VFE_PLL_ATTR_S *pstPllAttr);

/* iclamp��vclamp */
HI_S32 HI_DRV_VFE_SetClamp(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_CLAMP_ATTR_S *pstClamp);
HI_S32 HI_DRV_VFE_GetClamp(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_CLAMP_ATTR_S *pstClamp);

/* ͬ������ѡ�� */
HI_S32 HI_DRV_VFE_SetSyncType(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_TYPE_E enSyncType, HI_BOOL bSepSyncInv);
HI_S32 HI_DRV_VFE_GetSyncType(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_TYPE_E *penSyncType);

HI_S32 HI_DRV_VFE_SetGain(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 u32Gain);
HI_S32 HI_DRV_VFE_GetGain(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 *pu32Gain);

HI_S32 HI_DRV_VFE_SetOffset(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 u32Offset);
HI_S32 HI_DRV_VFE_GetOffset(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_U32 *pu32Offset);

HI_S32 HI_DRV_VFE_SetHtotal(HI_HANDLE hVfe, HI_U32 u32Htotal);
HI_S32 HI_DRV_VFE_GetHtotal(HI_HANDLE hVfe, HI_U32 *pu32Htotal);

HI_S32 HI_DRV_VFE_SetPhase(HI_HANDLE hVfe, HI_U32 u32Phase);
HI_S32 HI_DRV_VFE_GetPhase(HI_HANDLE hVfe, HI_U32 *pu32Phase);

/* �ڱ�׼�ź�ʱ����Ĭ��ֵ���Ǳ�Ѷ�ſ�΢��slicer level,һ��16����ΧΪ0-15��Ŀǰֻ��ʹ��ͨ��0 */
HI_S32 HI_DRV_VFE_SetSlicerLevel(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_CHN_TYPE_E enSyncChn, HI_U32 u32Level);
HI_S32 HI_DRV_VFE_GetSlicerLevel(HI_HANDLE hVfe, HI_DRV_VFE_SYNC_CHN_TYPE_E enSyncChn, HI_U32 *pu32Level);

/* ��������ͨ���ĵ�ͨ�˲��Ĺ���ģʽ */
HI_S32 HI_DRV_VFE_SetLpfAttr(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_LPF_FILTER_ATTR_U *puLpfAttr);
HI_S32 HI_DRV_VFE_GetLpfAttr(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_DRV_VFE_LPF_FILTER_ATTR_U *puLpfAttr);

/* sif��������ƣ�����Sifģʽʱ��Rͨ����������� */
HI_S32 HI_DRV_VFE_SetSifGain(HI_HANDLE hVfe, HI_U32 u32SifGain);
HI_S32 HI_DRV_VFE_GetSifGain(HI_HANDLE hVfe, HI_U32 *pu32SifGain);

HI_S32 HI_DRV_VFE_SetSifOffset(HI_HANDLE hVfe, HI_U32 u32SifOffset);
HI_S32 HI_DRV_VFE_GetSifOffset(HI_HANDLE hVfe, HI_U32 *pu32SifOffset);

/* �ĸ�����ͨ����PGA��ADC��power���� */
HI_S32 HI_DRV_VFE_PowerCtrl(HI_HANDLE hVfe, HI_DRV_VFE_DATA_CHN_TYPE_E enDataChn, HI_BOOL bEnable);

/* Video Out���� */
HI_S32 HI_DRV_VFE_SetVideoOutGain(HI_DRV_VFE_VIDEO_OUT_CHN_E enVideoOutChn, HI_U32 u32Gain);
HI_S32 HI_DRV_VFE_CfgVideoOut(HI_DRV_VFE_VIDEO_OUT_CHN_E enVideoOutChn, HI_BOOL bEnable);

HI_U32 HI_DRV_VFE_GetCvbsSampleRate(HI_VOID);

/* ���߼�� */
HI_S32 HI_DRV_VFE_SetOfflineSlicerLevel(HI_U32 u32Level);
HI_S32 HI_DRV_VFE_CheckOfflineSigStatus(HI_DRV_VFE_OFFLINE_ATTR_S *psOfflineAttr, HI_BOOL *pbSigStable, HI_BOOL bSyncTypeCheck);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __HI_DRV_VFE_EXT_H__ */

