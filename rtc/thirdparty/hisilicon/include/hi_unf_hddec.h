/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_hddec.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/08
  Description   : 
  History       :
  1.Date        : 2013/10/08
    Author      : c00186004/x00185802
    Modification: Created file
******************************************************************************/

#ifndef __HI_UNF_HDDEC_H__
#define __HI_UNF_HDDEC_H__

/* add include here */
#include "hi_unf_atv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/********************************Macro Definition********************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/**VGA source EDID data size */
/**CNcomment:VGA�ź�ԴEDID���ݳ��ȡ�*/
#define HI_UNF_HDDEC_EDID_SIZE     128

/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/**HDDEC source type*/
/**CNcomment:HDDEC �ź�Դ���� */
typedef enum hiUNF_HDDEC_SRC_TYPE_E 
{
	HI_UNF_HDDEC_SRC_VGA = 0,   /**<VGA source *//**<CNcomment: VGA�ź�Դ*/
	HI_UNF_HDDEC_SRC_YPBPR,     /**<YPbPr source *//**<CNcomment: YPbPr�ź�Դ*/
	
	HI_UNF_HDDEC_SRC_BUTT       /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_HDDEC_SRC_TYPE_E;

/**HDDEC parameters adjust type*/
/**CNcomment:HDDEC�����ֶ��������� */
typedef enum hiUNF_HDDEC_ADJUST_TYPE_E 
{
	HI_UNF_HDDEC_ADJUST_HPOS = 0,  /**<H Position adjust *//**<CNcomment: ˮƽλ�õ���*/
	HI_UNF_HDDEC_ADJUST_VPOS,      /**<V Position adjust *//**<CNcomment: ��ֱλ�õ���*/
	HI_UNF_HDDEC_ADJUST_PHASE,     /**<Phase adjust *//**<CNcomment: ��λ����*/
	HI_UNF_HDDEC_ADJUST_CLOCK,     /**<Clock adjust *//**<CNcomment: ʱ�ӵ���*/
	
	HI_UNF_HDDEC_ADJUST_TYPE_BUTT  /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_HDDEC_ADJUST_TYPE_E;

/**Adjust state for color calibration and VGA auto adjust*/
/**CNcomment:�Զ���ɫУ����״̬/VGAͼ���Զ�������״̬  */
typedef enum hiUNF_HDDEC_ADJUST_STATE_E 
{
	HI_UNF_HDDEC_ADJUST_BEGIN = 0,   /**<Adjust begin *//**<CNcomment: ������ʼ*/
	HI_UNF_HDDEC_ADJUST_FINISH,      /**<Adjust finished *//**<CNcomment: �������*/
	HI_UNF_HDDEC_ADJUST_TIMEOUT,     /**<Adjust timeout *//**<CNcomment: ������ʱ*/
	HI_UNF_HDDEC_ADJUST_FAIL,        /**<Adjust failed *//**<CNcomment: ����ʧ��*/
	
	HI_UNF_HDDEC_ADJUST_STATE_BUTT   /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_HDDEC_ADJUST_STATE_E;

/**VGA auto adjust information */
/**CNcomment:VGAͼ���Զ���������Ϣ */
typedef struct hiUNF_HDDEC_ADJUST_INFO_S
{
	HI_UNF_HDDEC_ADJUST_STATE_E enAdjustState; /**<Adjust state *//**<CNcomment: �Զ�����״̬*/
	HI_U32 u32Clock;                           /**<Adjust clock information*//**<CNcomment: ʱ�ӵ�����Ϣ*/
	HI_U32 u32Phase;                           /**<Adjust phase information*//**<CNcomment: ��λ������Ϣ*/
	HI_U32 u32HPosition;                       /**<Adjust H position information*//**<CNcomment: Hλ�õ�����Ϣ*/
	HI_U32 u32VPosition;                       /**<Adjust V position information*//**<CNcomment: Vλ�õ�����Ϣ*/
} HI_UNF_HDDEC_ADJUST_INFO_S;

/**Signal timing information */
/**CNcomment:�ź�ʱ����Ϣ */
typedef struct hiUNF_HDDEC_TIMING_INFO_S
{
    HI_U32  u32TimingIndex;                /**<Timing ID in the timing table *//**<CNcomment: Timing��� */
    HI_BOOL bInterlace;                    /**<interlace or progressive *//**<CNcomment: �������Ϣ */
    HI_U32  u32Width;                      /**<Standard width *//**<CNcomment: ��׼�ź�һ֡�Ŀ�� */
    HI_U32  u32Height;                     /**<Standard height *//**<CNcomment: ��׼�ź�һ֡�ĸ߶ȣ��������ź��������ĸ߶ȣ������ź���һ֡�ĸ߶� */
    HI_U32  u32FrameRate;                  /**<Standard frame rate *//**<CNcomment: ��׼�ĳ�Ƶ������Ǹ����ź���Ϊ��Ƶ������������ź���Ϊ֡�� */
    HI_UNF_VIDEO_FORMAT_E    enPixFmt;     /**<Pixel format *//**<CNcomment: �������ظ�ʽ RGB444,YUV444/422 */ 
    HI_UNF_COLOR_SPACE_E     enColorSpace; /**<Color space *//**<CNcomment: ��ɫ�ռ� */
    HI_UNF_OVERSAMPLE_MODE_E enOversample; /**<Oversample information *//**<CNcomment: ��������Ϣ */
    HI_UNF_PIXEL_BITWIDTH_E  enBitWidth;   /**<Bit width information *//**<CNcomment: λ����Ϣ */
} HI_UNF_HDDEC_TIMING_INFO_S;

/**Source input pin select */
/**CNcomment:�ź�����ѡ�� */
typedef struct hiUNF_HDDEC_SRC_ATTR_S
{
    HI_UNF_HDDEC_SRC_TYPE_E    enSrcType;   /**<Source type *//**<CNcomment: �����ź�Դ */
    HI_UNF_INPUT_MUX_E         enRMux;      /**<R/Pr input Pin select *//**<CNcomment: R/Pr�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E         enGMux;      /**<G/Y input Pin select *//**<CNcomment: G/Y�ź�pin�ź� */
    HI_UNF_INPUT_MUX_E         enBMux;      /**<B/Pb input Pin select *//**<CNcomment: B/Pb�ź�pin�ź� */
    HI_UNF_INPUT_MUX_SOG_E     enSogMux;    /**<SOG/SOY input Pin select *//**<CNcomment: SOG/SOY�ź�pin�ź� */
    HI_UNF_INPUT_MUX_SYNC_E    enSyncMux;   /**<HV Sync input Pin select *//**<CNcomment: VGA����ͬ���ź�pin�ź� */
} HI_UNF_HDDEC_SRC_ATTR_S;

/**Offline input pin select */
/**CNcomment:���߼������ѡ�� */
typedef struct hiUNF_HDDEC_OFFLINE_S
{
    HI_UNF_HDDEC_SRC_TYPE_E    enSrcType;     /**<Source type *//**<CNcomment: �����ź�Դ */
    HI_UNF_INPUT_MUX_OFFLINE_E enOfflineMux;  /**<Offline input Pin select *//**<CNcomment: ������Դ���pin�ź� */
    HI_UNF_INPUT_MUX_SYNC_E    enSyncMux;     /**<VGA HV Sync Pin select *//**<CNcomment: VGA����ͬ���ź�pin�ź� */
} HI_UNF_HDDEC_OFFLINE_S;

/**VGA EDID data definition */
/**CNcomment:VGA EDID�Ĵ�С����Ϊ128Byte*/
typedef struct hiUNF_HDDEC_EDID_S
{
    HI_U8 u8Edid[HI_UNF_HDDEC_EDID_SIZE];   /**VGA EDID data *//**<CNcomment: VGA EDID���� */
} HI_UNF_HDDEC_EDID_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      HDDEC */
/** @{ */  /** <!-- [HDDEC] */

/** 
\brief the whole initialization of the HDDEC device. CNcomment:HDDEC�ӿ����������ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS  success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_Init(HI_VOID);

/** 
\brief deinit the HDDEC device. CNcomment:HDDEC�ӿ�ȥ��ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_DeInit(HI_VOID);

/** 
\Connect the HDDEC device if source switch to YPbPr or VGA. CNcomment:�л�HDDEC�ź�Դ��YPbPr��VGA��ʱ����HDDEC�豸 CNend
\attention \n
\param[in] pstSrcAttr Connected source attribute.CNcomment:���ӵ��ź�Դ���� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_Connect(HI_UNF_HDDEC_SRC_ATTR_S *pstSrcAttr);

/** 
\Disconnect the HDDEC device if  source switch to other source. CNcomment:�л��������ź�Դʱ�Ͽ�����HDDEC�豸 CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_DisConnect(HI_VOID);

/* ��ȡ������Դ���ź��Ƿ���ڣ������ӿ� */

/** 
\Check the signal is  exist or not with the non-current source. CNcomment:��ȡ������Դ���ź��Ƿ����,�������� CNend
\attention \n
\param[in] pstOffline source offline information. CNcomment:���߼���ź�Դ��Ϣ CNend
\param[out] pbExistSig signal exist information.CNcomment:�ź��Ƿ������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetOfflineSigStatus(HI_UNF_HDDEC_OFFLINE_S *pstOffline, HI_BOOL *pbExistSig);

/** 
\Get the signal status like no signal/unstable/support. CNcomment:��ȡ�ź�״̬�����ź�/���ȶ�/�ź��ȶ��� CNend
\attention \n
\param[out] penSigStatus signal status.CNcomment:��ȡ���ź�״̬ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetSigStatus(HI_UNF_SIG_STATUS_E *penSigStatus);

/** 
\Get the standard timing information of current signal. CNcomment:��ȡ�źű�׼ʱ����Ϣ CNend
\attention \n
\param[out] pstTimingInfo signal timing information.CNcomment:��ȡ���ź�ʱ����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetTimingInfo(HI_UNF_HDDEC_TIMING_INFO_S *pstTimingInfo);

/** 
\To check the nonstand signal information. CNcomment:��ȡ�Ǳ���Ϣ CNend
\attention \n
\param[out] pstNonStdInfo nonstand signal information.CNcomment:�Ǳ��ź���Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetNonStdInfo(HI_UNF_VIDEO_NONSTD_INFO_S *pstNonStdInfo);

/** 
\To start color calibration CNcomment:�����Զ���ɫУ�� CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_StartCalib(HI_VOID);

/** 
\Get Color calibration information CNcomment:��ȡ�Զ���ɫУ����Ϣ  CNend
\attention \n
\param[out] pstCalibInfo Color calibration information.CNcomment:�Զ���ɫУ����Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetCalibInfo(HI_UNF_COLOR_CALIB_INFO_S *pstCalibInfo);

/** 
\Get Color calibration data CNcomment:��ȡ�Զ���ɫУ������  CNend
\attention \n
\param[out] pstCalibParam Color calibration data.CNcomment:�Զ���ɫУ������ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/** 
\Set Color calibration data CNcomment:�ֶ������Զ���ɫУ��  CNend
\attention \n
\param[in] pstCalibParam Color calibration data.CNcomment:���õ���ɫУ������ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_SetCalibParam(HI_UNF_COLOR_CALIB_PARAM_S *pstCalibParam);

/** 
\To start VGA source auto adjust CNcomment:����VGAͼ���Զ�����CNend
\attention \n
\param CNcomment:�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_StartAutoAdjust(HI_VOID);

/** 
\Get VGA auto adjust information CNcomment:��ȡVGAͼ���Զ�����  CNend
\attention \n
\param[out] pstAdjustInfo VGA auto adjust information.CNcomment:VGAͼ���Զ�������Ϣ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustInfo(HI_UNF_HDDEC_ADJUST_INFO_S *pstAdjustInfo);

/** 
\Get adjust type range CNcomment:��ȡ�ֶ������ɵ���Χ  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:�������� CNend
\param[out] pstRange adjust type range.CNcomment:�ֶ������ɵ���Χ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustRange(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_RANGE_S *pstRange);

/** 
\Get adjust type data CNcomment:��ȡ����������ֵ  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:�������� CNend
\param[out] pu32Param adjust type data.CNcomment:����������ֵ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_GetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 *pu32Param);

/** 
\Set adjust type data CNcomment:���õ���������ֵ  CNend
\attention \n
\param[in]  enAdjust adjust type.CNcomment:�������� CNend
\param[in]  u32Param adjust type data.CNcomment:����������ֵ CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_SetAdjustParam(HI_UNF_HDDEC_ADJUST_TYPE_E enAdjust, HI_U32 u32Param);   

/** 
\Update the EDID data CNcomment:����EDID����  CNend
\attention \n
\param[out] pstEdid EDID data.CNcomment:EDID���� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_HDDEC_UpdateEdid(const HI_UNF_HDDEC_EDID_S *pstEdid);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif/* __HI_UNF_HDDEC_H__ */
