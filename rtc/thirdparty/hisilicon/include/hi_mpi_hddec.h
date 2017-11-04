/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_mpi_hddec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/08
  Description   : 
  History       :
  1.Date        : 2013/10/08
    Author      : c00186004
    Modification: Created file
******************************************************************************/

#ifndef __HI_MPI_HDDEC_H__
#define __HI_MPI_HDDEC_H__

#include "hi_unf_hddec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/* HDDEC��ʼ�� */
HI_S32 HI_MPI_HDDEC_Init(HI_VOID);

/* HDDECȥ��ʼ�� */
HI_S32 HI_MPI_HDDEC_DeInit(HI_VOID);

/* ����edid */
HI_S32 HI_MPI_HDDEC_UpdateEdid(const HI_UNF_HDDEC_EDID_S *pstEdid);

/* ��Դ���� */
HI_S32 HI_MPI_HDDEC_Connect(HI_UNF_HDDEC_SRC_ATTR_S *pstSrcAttr);

/* �Ͽ����� */
HI_S32 HI_MPI_HDDEC_DisConnect(HI_VOID);

/* ��ȡ������Դ���ź��Ƿ���ڣ������ӿ� */
HI_S32 HI_MPI_HDDEC_GetOfflineSigStatus(HI_UNF_HDDEC_OFFLINE_S *pstOffline, HI_BOOL *pbExistSig);

/* ��⵱ǰ��decode״̬ */
HI_S32 HI_MPI_HDDEC_GetSigStatus(HI_UNF_SIG_STATUS_E *penSigStatus);

/* ��⵱ǰ��decodeTiming��Ϣ */
HI_S32 HI_MPI_HDDEC_GetTimingInfo(HI_UNF_HDDEC_TIMING_INFO_S *pstTimingInfo);

/* ��⵱ǰ��decode�Ǳ���Ϣ */
HI_S32 HI_MPI_HDDEC_GetNonStdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNonStdInfo);

/* �����Զ���ɫУ�� */
HI_S32 HI_MPI_HDDEC_StartCalib(HI_VOID);

/* ��ȡ�Զ���ɫУ��״̬ */
HI_S32 HI_MPI_HDDEC_GetCalibInfo(HI_UNF_COLOR_CALIB_INFO_S *pstCalibInfo);

/* ��ȡ�ֶ������Զ���ɫУ������ */
HI_S32 HI_MPI_HDDEC_GetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/* �ֶ������Զ���ɫУ�� */
HI_S32 HI_MPI_HDDEC_SetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/* ����VGAͼ���Զ����� */
HI_S32 HI_MPI_HDDEC_StartAutoAdjust(HI_VOID);

/* ��ȡVGAͼ���Զ�����״̬ */
HI_S32 HI_MPI_HDDEC_GetAdjustInfo(HI_UNF_HDDEC_ADJUST_INFO_S *pstAdjustInfo);

/* ��ȡ�ֶ������ɵ���Χ */
HI_S32 HI_MPI_HDDEC_GetAdjustRange(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_RANGE_S *pstRange);

/* ��ȡ�����Ĳ��� */
HI_S32 HI_MPI_HDDEC_GetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 *pu32Param);

/* �����ֶ���������*/
HI_S32 HI_MPI_HDDEC_SetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 u32Param);   

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_MPI_HDDEC_H__ */

