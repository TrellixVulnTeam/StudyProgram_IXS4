/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_tvd.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/09/25
  Description   : 
  History       :
  1.Date        : 2013/09/25
    Author      : t00202585/x00185802
    Modification: Created file
******************************************************************************/
#ifndef __HI_UNF_TVD_H__
#define __HI_UNF_TVD_H__

/* add include here */
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      TVD */
/** @{ */  /** <!-- [TVD] */

/**TVD work mode *//**CNcomment:TVD����ģʽ  */
typedef enum hiUNF_TVD_WORK_MODE_E
{
    HI_UNF_TVD_WORK_MODE_NORMAL = 0,   /**<TVD work mode normal*/ /**<CNcomment:TVD��������ģʽ */
    HI_UNF_TVD_WORK_MODE_CHAN_SCAN,    /**<TVD RF channel scan mode*/ /**<CNcomment:TVD RF��̨ģʽ */
	
    HI_UNF_TVD_WORK_MODE_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_TVD_WORK_MODE_E;

/**TVD comb filter mode*//**CNcomment:TVD��״�˲���ģʽ  */
typedef enum hiUNF_TVD_COMB_MODE_E
{
    HI_UNF_TVD_COMB_ADAP = 0,          /**<TVD adaptive comb filter*/ /**<CNcomment:TVD����Ӧ��״�˲��� */
    HI_UNF_TVD_COMB_FORCE_3D,          /**<TVD 3D comb filter*/ /**<CNcomment:TVD 3D��״�˲��� */
    HI_UNF_TVD_COMB_FORCE_2D,          /**<TVD 2D comb filter*/ /**<CNcomment:TVD 2D��״�˲��� */
    HI_UNF_TVD_COMB_FORCE_1D,          /**<TVD 1D comb filter*/ /**<CNcomment:TVD 1D��״�˲��� */
    HI_UNF_TVD_COMB_BUTT               /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
}HI_UNF_TVD_COMB_MODE_E;

/**TVD source type*//**CNcomment:TVD�ź�Դ����  */
typedef enum hiUNF_TVD_SRC_TYPE_E 
{
    HI_UNF_TVD_SRC_RF_INTER = 0,       /**<RF source with Internal AIF*/ /**<CNcomment:RF�ź�Դ������AIF�� */
    HI_UNF_TVD_SRC_RF_EXTRA,           /**<RF source with extra AIF*/ /**<CNcomment:RF�ź�Դ������AIF�� */
    HI_UNF_TVD_SRC_AV,                 /**<Compsite video source*/ /**<CNcomment:������Ƶ */
    HI_UNF_TVD_SRC_SVIDEO,             /**<S-VIDEO source*/ /**<CNcomment:ɫ���ź�Դ */
    HI_UNF_TVD_SRC_SCART_FULL,         /**<Full SCART source*/ /**<CNcomment:Full SCART�ź�Դ */
    HI_UNF_TVD_SRC_SCART_HALF,         /**<Half SCART source*/ /**<CNcomment:Half SCART�ź�Դ */
    HI_UNF_TVD_SRC_BUTT                /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_TVD_SRC_TYPE_E;

/**TVD adjust position type *//**CNcomment:TVD ����λ������ */
typedef enum hiUNF_TVD_POS_TYPE_E
{
    HI_UNF_TVD_POS_H = 0,              /**<TVD adjust H position*/ /**<CNcomment:��������ʼλ�� */
    HI_UNF_TVD_POS_V,                  /**<TVD adjust V position*/ /**<CNcomment:���ڳ���ʼλ�� */
    HI_UNF_TVD_POS_BUTT                /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_TVD_POS_TYPE_E;

/**TVD timing information*/
/**CNcomment:TVD �ź�ʱ����Ϣ */
typedef struct hiUNF_TVD_TIMING_INFO_S 
{
    HI_BOOL             bInterlace;    /**<Flag of progressive or interlance *//**CNcomment:����б�־ */
    HI_U32              u32Width;      /**<Active width of input standard signal *//**CNcomment:�źű�׼��Ч���ؿ�� */
    HI_U32              u32Height;     /**<Active height of input standard signal *//**CNcomment:�źű�׼��Ч���ظ߶� */
    HI_U32              u32FrameRate;  /**<Frame Rate��fields per second *//**CNcomment:��Ƶ ��λΪÿ�볡��Ŀ��60��ʾ60Hz */
    
    HI_UNF_OVERSAMPLE_MODE_E     enOversample;   /**<Oversample information *//**CNcomment:��������Ϣ */
    HI_UNF_PIXEL_BITWIDTH_E      enBitWidth;     /**<Sample bit width *//**CNcomment:λ����Ϣ */
    HI_UNF_VIDEO_FORMAT_E        enPixelFmt;     /**<Pixel format *//**CNcomment:���ظ�ʽ */
} HI_UNF_TVD_TIMING_INFO_S;

/**SCART mux select*/
/**CNcomment:SCART�����źŸ���ѡ��*/
typedef struct hiUNF_TVD_SCART_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E    enRMux;    /**<R input pin select *//**CNcomment:R�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E    enGMux;    /**<G input pin select *//**CNcomment:G�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E    enBMux;    /**<B input pin select *//**CNcomment:B�ź�pin�ź� */
} HI_UNF_TVD_SCART_MUX_S;

/**S-VIDEO mux select*/
/**CNcomment:S-Video�����źŸ���ѡ��*/
typedef struct hiUNF_TVD_SVIDEO_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enSYMux;  /**<S-VIDEO Y input pin select *//**CNcomment:S-VIDEO Y�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E    enSCMux;  /**<S-VIDEO C input pin select *//**CNcomment:S-VIDEO C�ź�pin�ź� */
} HI_UNF_TVD_SVIDEO_MUX_S;

/**CVBS mux select*/
/**CNcomment:CVBS�����źŸ���ѡ��*/
typedef struct hiUNF_TVD_CVBS_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS�ź�pin�ź� */
} HI_UNF_TVD_CVBS_MUX_S;

/**RF with extra AIF mux select*/
/**CNcomment:����AIF RF�źŸ���ѡ��*/
typedef struct hiUNF_TVD_EXT_RF_MUX_S 
{
    HI_UNF_INPUT_MUX_E    enCvbsMux; /**<CVBS input pin select *//**CNcomment:CVBS�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E    enSifMux;  /**<SIF input pin select *//**CNcomment:����AIF��SIF�ź�pin�ź� */
} HI_UNF_TVD_EXT_RF_MUX_S;

/**TVD source attribute */
/**CNcomment:TVD�����ź����� */
typedef struct hiUNF_TVD_SRC_ATTR_S
{
    HI_UNF_TVD_SRC_TYPE_E  enType;             /**<TVD input source type *//**CNcomment: TVD�����ź����� */
    union
    {
        HI_UNF_TVD_SCART_MUX_S  stScartMux;    /**<For SCART source *//**CNcomment: SCART�ź�ѡ�� */
        HI_UNF_TVD_SVIDEO_MUX_S stSVideoMux;   /**<For S-VIDEO source *//**CNcomment: S-VIDEO�ź�ѡ�� */
        HI_UNF_TVD_CVBS_MUX_S   stCvbsMux;     /**<For RF and CVBS source *//**CNcomment: RF��CVBS�ź�ѡ�� */
        HI_UNF_TVD_EXT_RF_MUX_S stExtRfMux;    /**<For ext RF source *//**CNcomment: ����AIF��RF�ź�ѡ�� */
    } unMuxInfo;
} HI_UNF_TVD_SRC_ATTR_S;

/**TVD offline information definition*/
/**CNcomment:TVD���߼����Ϣ���� */
typedef struct hiUNF_TVD_OFFLINE_S
{
    HI_UNF_TVD_SRC_TYPE_E      enType;          /**<TVD input source type *//**CNcomment: TVD�����ź����� */
    HI_UNF_INPUT_MUX_OFFLINE_E enOfflineMux;    /**<TVD input offline pin select *//**CNcomment: TVD���߼������pin��ѡ�� */
} HI_UNF_TVD_OFFLINE_S;

/**TVD color system filter definition */
/**CNcomment:TVD��ɫ��ʽ���˶��� */
typedef struct hiUNF_TVD_SYS_FILTER_S
{
    HI_BOOL         bDisPalM;           /**<Disable PAL-M in RF source *//**CNcomment: ���˵�PAL-M��ɫ��ʽ */
    HI_BOOL         bDisPalN;           /**<Disable PAL-N in RF source *//**CNcomment: ���˵�PAL-N��ɫ��ʽ */
    HI_BOOL         bDisSecam;          /**<Disable SECAM in RF source *//**CNcomment: ���˵�SECAM��ɫ��ʽ */
    HI_BOOL         bDisPal60;          /**<Disable PAL-60 in RF source *//**CNcomment: ���˵�PAL-60��ɫ��ʽ */
    HI_BOOL         bDisNtsc443;        /**<Disable NTSC443 in RF source *//**CNcomment: ���˵�NTSC443��ɫ��ʽ */
} HI_UNF_TVD_SYS_FILTER_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      TVD */
/** @{ */  /** <!-- [TVD] */

/** 
\brief the whole initialization of the TVD device. CNcomment:TVD�ӿ����������ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS  success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_Init(HI_VOID);

/** 
\brief deinit the TVD device. CNcomment:TVD�ӿ�ȥ��ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_DeInit(HI_VOID);

/** 
\Connect the TVD device if source switch to RF or AV. CNcomment:�л�TVD�ź�Դ��RF��AV��ʱ����TVD�豸 CNend
\attention \n
\param[in] pstSrcAttr Connected source attribute.CNcomment:���ӵ��ź�Դ���� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_Connect(HI_UNF_TVD_SRC_ATTR_S *pstSrcAttr);

/** 
\Disconnect the TVD device if  source switch to other source. CNcomment:�л��������ź�Դʱ�Ͽ�����TVD�豸 CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_DisConnect(HI_VOID);

/** 
\Get the signal status like no signal/unstable/support. CNcomment:��ȡ�ź�״̬�����ź�/���ȶ�/�ź��ȶ��� CNend
\attention \n
\param[out] penSignalStatus signal status.CNcomment:��ȡ���ź�״̬ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetSigStatus(HI_UNF_SIG_STATUS_E *penSignalStatus);

/** 
\Get the standard timing information of current signal. CNcomment:��ȡ�źű�׼ʱ����Ϣ CNend
\attention \n
\param[out] pstTimingInfo signal timing information.CNcomment:��ȡ���ź�ʱ����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetStdTimingInfo(HI_UNF_TVD_TIMING_INFO_S *pstTimingInfo);

/** 
\Set the TVD color system. CNcomment:����TVD��ɫ��ʽ CNend
\attention \n
\param[in] enColorSys color system.CNcomment:��ɫ��ʽ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetColorSys(HI_UNF_COLOR_SYS_E enColorSys);

/** 
\Get the color system of current system. CNcomment:��ȡ��ɫ��ʽ��Ϣ CNend
\attention \n
\param[out] penColorSys color system.CNcomment:��ɫ��ʽ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetColorSys(HI_UNF_COLOR_SYS_E *penColorSys);

/** 
\To check the signal is locked or not in autosearch. CNcomment:��ȡ�ź�������Ϣ CNend
\attention \n
\param[out] pbLock locked or not.CNcomment:������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetSignalLock(HI_BOOL *pbLock);

/** 
\Get the Noise level of signal. CNcomment:��ȡ��������ֵ CNend
\attention \n
\param[out] pu32Level noise level.CNcomment:��������ֵ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetNoiseLevel(HI_U32 *pu32Level);

/** 
\To check the signal is Macrovision copyright or not. CNcomment:��ȡMacrovision��Ȩ��Ϣ CNend
\attention \n
\param[out] pbStatus Macrovision copyright information.CNcomment:Macrovision��Ȩ��Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetMacrovisionStatus(HI_BOOL *pbStatus);

/** 
\To check the nonstand signal information. CNcomment:��ȡ�Ǳ���Ϣ CNend
\attention \n
\param[out] pstNstdInfo nonstand signal information.CNcomment:�Ǳ��ź���Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetNstdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNstdInfo);

/** 
\Get the range of H/V adjust. CNcomment:��ȡH/V������Χ CNend
\attention \n
\param[in] enType  adjust type��H or V. CNcomment:����λ������ CNend
\param[out] pstRange adjust range.CNcomment:���ڷ�Χ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetRange(HI_UNF_TVD_POS_TYPE_E enType, HI_RANGE_S *pstRange);

/** 
\Get the current H/V position of tvd output. CNcomment:��ȡTVD�����H/Vλ����Ϣ CNend
\attention \n
\param[in] enType position type. CNcomment:λ����Ϣ���� CNend
\param[out] pu32Pos position information.CNcomment:λ����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 *pu32Pos);

/** 
\Set the H/V position of tvd output. CNcomment:����TVD�����H/Vλ�� CNend
\attention \n
\param[in] enType position type. CNcomment:λ����Ϣ���� CNend
\param[in] u32Pos position information.CNcomment:λ����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetPos(HI_UNF_TVD_POS_TYPE_E enType, HI_U32 u32Pos);

/** 
\Check the signal is exist or not with the non-current source. CNcomment:��ȡTVDԴ���߼��״̬ CNend
\attention \n
\param[in] pstOffline source offline information. CNcomment:���߼���ź�Դ��Ϣ CNend
\param[out] pbStatus signal exist information.CNcomment:�ź��Ƿ������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetOfflineDetStatus(HI_UNF_TVD_OFFLINE_S *pstOffline, HI_BOOL *pbStatus);

/** 
\Enable/disable the Pedestal setting for NTSC/PAL M. CNcomment:����NTSC/PAL M��ʽ�ڵ�ƽ7.5IRE CNend
\attention \n
\param[in] bEnable HI_TRUE:enable, HI_FALSE:disable.CNcomment:HI_TRUE:ʹ��, HI_FALSE:�ر� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetPedestal(HI_BOOL bEnable);

/** 
\Set color system filter. CNcomment:���ò�ɫ��ʽ���� CNend
\attention \n
\param[in] pstSysFilter color system filter information.CNcomment:��ɫ��ʽ������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);

/** 
\Get color system filter. CNcomment��ȡ��ɫ��ʽ���� CNend
\attention \n
\param[in] pstSysFilter color system filter information.CNcomment:��ɫ��ʽ������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_GetColorSysFilter(HI_UNF_TVD_SYS_FILTER_S *pstSysFilter);

/** 
\turn on/off the TVD main thread for debug usage. CNcomment�ر�/�� TVD ���߳����ڵ���  CNend
\attention \n
\param[in] bEnable HI_TRUE:enable, HI_FALSE:disable.CNcomment:HI_TRUE:ʹ��, HI_FALSE:�ر� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_EnMonitor(HI_BOOL bEnable);

/** 
\Set the comb working mode like 3d/2d. CNcomment:������״�˲�������ģʽ CNend
\attention \n
\param[in] enMode the comb working mode.CNcomment:��״�˲�������ģʽ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetCombMode(HI_UNF_TVD_COMB_MODE_E enMode);

/** 
\Get the signal 625 lines information,For ATV Rf scan signal. CNcomment:��ȡ�ź��Ƿ���625�� CNend
\attention \n
\param[out] pbIs625 625 lines information.CNcomment:625����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_Get625Mode(HI_BOOL *pbIs625);

/** 
\Set the TVD working mode. CNcomment:����TVD����ģʽ CNend
\attention \n
\param[in] enWorkMode the TVD working mode.CNcomment:TVD����ģʽ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_SetWorkMode(HI_UNF_TVD_WORK_MODE_E enWorkMode);

/**
\Set the TVD/AIF Non-std Set. CNcomment:TVD/AIF �Ǳ����� CNend
\attention \n
\param[in] u32CmdType  Cmd type. CNcomment:��������
\param[in] pu32Attr1   Cmd Attr1.CNcomment:��������1 CNend
\param[in] pu32Attr2   Cmd Attr2.CNcomment:��������2 CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_TVD_HandleCmd(HI_U32 u32CmdType, HI_U32 *pu32Attr1, HI_U32 *pu32Attr2);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_TVD_H__ */

