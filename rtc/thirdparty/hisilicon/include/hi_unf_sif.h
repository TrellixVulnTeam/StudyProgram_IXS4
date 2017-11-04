/******************************************************************************

  Copyright (C), 2001-2011, HiSilicon Technologies Co., Ltd.
******************************************************************************
 File Name     : hi_unf_sif.h
Version       : Initial draft
Author        : HiSilicon multimedia software group
Created Date   : 2008-06-05
Last Modified by:
Description   : Application programming interfaces (APIs) of the external chip software (ECS)
Function List :
Change History:
******************************************************************************/
#ifndef __HI_UNF_SIF_H__
#define __HI_UNF_SIF_H__

#include "hi_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/********************************Macro Definition*****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */

#define HI_UNF_SIF_STANDARD_NUM_MAX HI_UNF_SIF_STANDARD_UNKNOW

/** @} */  /** <!-- ==== Macro Definition end ==== */


/*************************** Structure Definition ****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */

//============================================================
// AUDIO_ATV RELATIONAL API FUNCTION
//============================================================
///< Audio SIF Standard Type

/**Audio Standard Type of An SIF*/
/**CNcomment:��Ƶ�ڶ�������Ƶ��ʽ*/
typedef enum hiUNF_SIF_STANDARD_TYPE_E
{
    HI_UNF_SIF_STANDARD_BG = 0x00,                  /**<Audio standard BG*/ /**<CNcomment:��Ƶ������ʽBG*/
    HI_UNF_SIF_STANDARD_BG_A2,                      /**<Audio standard BG A2*/ /**<CNcomment:��Ƶ������ʽBG A2*/
    HI_UNF_SIF_STANDARD_BG_NICAM,                   /**<Audio standard BG NICAM*//**<CNcomment:��Ƶ������ʽBG NICAM*/
    HI_UNF_SIF_STANDARD_I,                          /**<Audio standard I*/ /**<CNcomment:��Ƶ������ʽI*/
    HI_UNF_SIF_STANDARD_DK,                         /**<Audio standard DK*/ /**<CNcomment:��Ƶ������ʽDK*/
    HI_UNF_SIF_STANDARD_DK1_A2,                     /**<Audio standard DK1 A2*/ /**<CNcomment:��Ƶ������ʽDK1 A2*/
    HI_UNF_SIF_STANDARD_DK2_A2,                     /**<Audio standard DK2 A2*/ /**<CNcomment:��Ƶ������ʽDK2 A2*/
    HI_UNF_SIF_STANDARD_DK3_A2,                     /**<Audio standard DK3 A2*/ /**<CNcomment:��Ƶ������ʽDK3 A2*/
    HI_UNF_SIF_STANDARD_DK_NICAM,                   /**<Audio standard DK NICAM*/ /**<CNcomment:��Ƶ������ʽDK NICAM*/
    HI_UNF_SIF_STANDARD_L,                          /**<Audio standard L*/ /**<CNcomment:��Ƶ������ʽL*/
    HI_UNF_SIF_STANDARD_M,                          /**<Audio standard M*/ /**<CNcomment:��Ƶ������ʽM*/
    HI_UNF_SIF_STANDARD_M_BTSC,                     /**<Audio standard M BTSC*/ /**<CNcomment:��Ƶ������ʽM BTSC*/
    HI_UNF_SIF_STANDARD_M_A2,                       /**<Audio standard M A2*/ /**<CNcomment:��Ƶ������ʽM A2*/
    HI_UNF_SIF_STANDARD_M_EIA_J,                    /**<Audio standard M EIA J*/ /**<CNcomment:��Ƶ������ʽM EIA J*/
    HI_UNF_SIF_STANDARD_NOTSTANDARD,
    HI_UNF_SIF_STANDARD_UNKNOW
} HI_UNF_SIF_STANDARD_TYPE_E;

/**Audio mode type*/
/**CNcomment:��Ƶ����ģʽ*/
typedef enum hiUNF_SIF_OUTMODE_E
{
    HI_UNF_SIF_OUTMODE_MONO = 0x00,                 /**<Audio Mode MONO*/ /**<CNcomment:��Ƶ����ģʽMONO*/
    HI_UNF_SIF_OUTMODE_STEREO,                      /**<Audio Mode G Stereo*/ /**<CNcomment:��Ƶ����ģʽStereo*/
    HI_UNF_SIF_OUTMODE_DUAL_A,                      /**<Audio Mode Dual A*/ /**<CNcomment:��Ƶ����ģʽDual A*/
    HI_UNF_SIF_OUTMODE_DUAL_B,                      /**<Audio Mode Dual B*/ /**<CNcomment:��Ƶ����ģʽDual B*/
    HI_UNF_SIF_OUTMODE_DUAL_AB,                     /**<Audio Mode Dual AB*/ /**<CNcomment:��Ƶ����ģʽDual AB*/    
    HI_UNF_SIF_OUTMODE_BTSC_MONO,                   /**<Audio Mode BTSC MONO*/ /**<CNcomment:��Ƶ����ģʽBTSC MONO*/
    HI_UNF_SIF_OUTMODE_BTSC_STEREO,                 /**<Audio Mode BTSC STEREO*/ /**<CNcomment:��Ƶ����ģʽBTSC STEREO*/
    HI_UNF_SIF_OUTMODE_BTSC_SAP,                    /**<Audio Mode BTSC SAP*/ /**<CNcomment:��Ƶ����ģʽBTSC SAP*/
    HI_UNF_SIF_OUTMODE_NICAM_FORCED_MONO,           /**<Audio Mode NICAM Forced MONO*/ /**<CNcomment:��Ƶ����ģʽForced Mono*/
    HI_UNF_SIF_OUTMODE_NICAM_MONO,                  /**<Audio Mode NICAM MONO*/ /**<CNcomment:��Ƶ����ģʽNICAM MONO*/
    HI_UNF_SIF_OUTMODE_NICAM_STEREO,                /**<Audio Mode NICAM Stereo*/ /**<CNcomment:��Ƶ����ģʽNICAM Stereo*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_A,                /**<Audio Mode NICAM DUAL A*/ /**<CNcomment:��Ƶ����ģʽNICAM DUAL A*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_B,                /**<Audio Mode NICAM DUAL B*/ /**<CNcomment:��Ƶ����ģʽNICAM DUAL B*/
    HI_UNF_SIF_OUTMODE_NICAM_DUAL_AB,               /**<Audio Mode NICAM DUAL AB*/ /**<CNcomment:��Ƶ����ģʽNICAM DUAL AB*/
    HI_UNF_SIF_OUTMODE_BUTT
} HI_UNF_SIF_OUTMODE_E;

/**Audio Carrier Status of An Sif*/
/**CNcomment:��Ƶ�ز�״̬*/
typedef enum hiUNF_SIF_AAOS_MODE_E 
{
    HI_UNF_SIF_AAOS_MODE_MONO = 0,                 /**<Audio AAOS Status MONO*/ /**<CNcomment:��Ƶ�ز�״̬MONO*/
    HI_UNF_SIF_AAOS_MODE_STEREO,                   /**<Audio AAOS Status STEREO*/ /**<CNcomment:��Ƶ�ز�״̬STEREO*/
    HI_UNF_SIF_AAOS_MODE_DUAL,                     /**<Audio AAOS Status DUAL*/ /**<CNcomment:��Ƶ�ز�״̬DUAL*/
    HI_UNF_SIF_AAOS_MODE_MONO_SAP,                 /**<Audio AAOS Status MONO_SAP*/ /**<CNcomment:��Ƶ�ز�״̬MONO_SAP*/
    HI_UNF_SIF_AAOS_MODE_STEREO_SAP,               /**<Audio AAOS Status STEREO_SAP*/ /**<CNcomment:��Ƶ�ز�״̬STEREO_SAP*/
    HI_UNF_SIF_AAOS_MODE_NICAM_MONO,               /**<Audio AAOS Status NICAM_MONO*/ /**<CNcomment:��Ƶ�ز�״̬NICAM_MONO*/
    HI_UNF_SIF_AAOS_MODE_NICAM_STEREO,             /**<Audio AAOS Status NICAM_STEREO*/ /**<CNcomment:��Ƶ�ز�״̬NICAM_STEREO*/
    HI_UNF_SIF_AAOS_MODE_NICAM_DUAL,               /**<Audio AAOS Status NICAM_DUAL*/ /**<CNcomment:��Ƶ�ز�״̬NICAM_DUAL*/
    HI_UNF_SIF_AAOS_MODE_NICAM_FM_MOMO,            /**<Audio AAOS Status NICAM_FM_MOMO*/ /**<CNcomment:��Ƶ�ز�״̬NICAM_FM_MOMO*/
    HI_UNF_SIF_AAOS_MODE_BUTT
} HI_UNF_SIF_AAOS_MODE_E;

/**Atuo Standard Detect Ctl of an SIF*/
/**CNcomment:�Զ���ʽ�����Ʋ���*/
typedef enum hiUNF_SIF_SYSCTL_E
{
    HI_UNF_SIF_SYSCTL_BTSC = 0,                     /**<Audio Detect Ctl BTSC*/ /**<CNcomment:��Ƶ��ʽ������BTSC,America M*/
    HI_UNF_SIF_SYSCTL_EIAJ,                         /**<Audio Detect Ctl EIA J*/ /**<CNcomment:��Ƶ��ʽ������EIAJ,Japan M*/
    HI_UNF_SIF_SYSCTL_M_KOREA,                      /**<Audio Detect Ctl Korea*/ /**<CNcomment:��Ƶ��ʽ������FM Korea,Korea M*/
    HI_UNF_SIF_SYSCTL_PAL_SUM,                      /**<Audio Detect Ctl PAL*/ /**<CNcomment:��Ƶ��ʽ������PAL*/
    HI_UNF_SIF_SYSCTL_SECAM_L,                      /**<Audio Detect Ctl L/L'*/ /**<CNcomment:��Ƶ��ʽ������L/L'*/
    HI_UNF_SIF_SYSCTL_FM_US,                        /**<Audio Detect Ctl FM-Stereo Radio US*/ /**<CNcomment:��Ƶ��ʽ������FM-Stereo Radio US*/
    HI_UNF_SIF_SYSCTL_FM_EUROPE,                    /**<Audio Detect Ctl FM-Stereo Radio Europe*/ /**<CNcomment:��Ƶ��ʽ������FM-Stereo Radio Europe'*/
    HI_UNF_SIF_SYSCTL_BUTT
} HI_UNF_SIF_SYSCTL_E;

/**AIF decoder mode*/
/**CNcomment:AIFģʽ*/
typedef enum hiUNF_SIF_AIF_MODE_E
{
    HI_UNF_SIF_AIF_MODE_INTERNEL = 0,               /**<AIF decoder mode internel*/ /**<CNcomment:AIF decoderģʽ ����*/
    HI_UNF_SIF_AIF_MODE_EXTERN,                     /**<AIF decoder mode external*/ /**<CNcomment:AIF decoderģʽ ����*/
    HI_UNF_SIF_AIF_MODE_BUTT
} HI_UNF_SIF_AIF_MODE_E;

/**Freqency error threshold of an SIF*/
/**CNcomment:Ƶ��ƫ����ֵ*/
typedef enum hiUNF_SIF_FREQ_ERR_THRESHOLD_E
{
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_10K = 0,          /**<Freqency error threshold 10K*/ /**<CNcomment:Ƶ��ƫ����ֵ 10K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_20K,              /**<Freqency error threshold 20K*/ /**<CNcomment:Ƶ��ƫ����ֵ 20K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_27K,              /**<Freqency error threshold 27K*/ /**<CNcomment:Ƶ��ƫ����ֵ 27K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_30K,              /**<Freqency error threshold 30K*/ /**<CNcomment:Ƶ��ƫ����ֵ 30K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_40K,              /**<Freqency error threshold 40K*/ /**<CNcomment:Ƶ��ƫ����ֵ 40K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_50K,              /**<Freqency error threshold 50K*/ /**<CNcomment:Ƶ��ƫ����ֵ 50K*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_BUTT
} HI_UNF_SIF_FREQ_ERR_THRESHOLD_E;

/*Over Devaiton Parameter of an SIF*/
/**CNcomment:������*/
typedef enum hiUNF_SIF_OVER_DEVIATION_E 
{
    HI_UNF_SIF_OVER_DEVIATION_50K  = 0x0,           /**<Over Devaiton 50K*/  /**<CNcomment:������ 50K*/
    HI_UNF_SIF_OVER_DEVIATION_100K,                 /**<Over Devaiton 100K*/ /**<CNcomment:������ 100K*/
    HI_UNF_SIF_OVER_DEVIATION_200K,                 /**<Over Devaiton 200K*/ /**<CNcomment:������ 200K*/
    HI_UNF_SIF_OVER_DEVIATION_384K,                 /**<Over Devaiton 384K*/ /**<CNcomment:������ 384K*/
    HI_UNF_SIF_OVER_DEVIATION_540K,                 /**<Over Devaiton 500K*/ /**<CNcomment:������ 500K*/
    HI_UNF_SIF_OVER_DEVIATION_BUTT
} HI_UNF_SIF_OVER_DEVIATION_E;

/*Open Parameters of an SIF*/
/**CNcomment:Open����*/
typedef struct
{
    HI_UNF_SIF_AIF_MODE_E enAIFMode;                /* internal/external aif *//**<CNcomment:��������AIF����ϵ��ʱ�ӵķ���*/
} HI_UNF_SIF_OPENPARMS_S;

/*Attributes of an SIF */
/**CNcomment:SIFģ������*/
typedef struct
{
    HI_BOOL bAutoMute;                              /**<Auto Mute*/ /**<CNcomment:�Զ�����*/
    HI_U32  u32PrescaleLevel;                       /**<Prescale level*/ /**<CNcomment:ǰ������ˮƽ*/
    HI_UNF_SIF_OUTMODE_E            enOutMode;      /**<SIF output mode*/ /**<CNcomment:SIF�ź����ģʽ*/
    HI_UNF_SIF_FREQ_ERR_THRESHOLD_E enFreqThreshold;/**<Freqency error Threshold*/ /**<CNcomment:Ƶ��ƫ����ֵ*/
    HI_U32 u32CarriMgntudeThreshold;                /**<Carrier Magnitude Threshold*/ /**<CNcomment:�ز�������ֵ*/
    HI_U32 u32CarriFMQualThreshold;                 /**<FM Quality Threshold*/ /**<CNcomment:FM������ֵ*/
    HI_U32 u32CarriAMNoiseThreshold;                /**<AM Noise Threshold*/ /**<CNcomment:AM������ֵ*/
    HI_U32 u32CarriNICAMNoiseThreshold;             /**<NICAM Noise Threshold*/ /**<CNcomment:NICAM������ֵ*/
} HI_UNF_SIF_ATTR_S;

/*Attributes of Carrier */
/**CNcomment:�ز����� */
typedef struct
{
    HI_UNF_SIF_STANDARD_TYPE_E  enStandardType;    /**<Standard Type*/ /**<CNcomment:�ز�������ʽ*/
    HI_U32 u32CarrierFreq;                         /**<Carrier Frequency*/ /**<CNcomment:�ز�Ƶ��*/
}HI_UNF_SIF_CARRIER_ATTR_S;

/*ID of an SIF device*/
/**CNcomment:SIF���*/
typedef enum
{
    HI_UNF_SIF_ID_0 = 0,       /* ID 0f SIF 0*//**<CNcomment:SIF0*/
    HI_UNF_SIF_ID_BUTT
} HI_UNF_SIF_ID_E;

/*Priority list of standard*/
/**CNcomment:��ʽ�����ȼ��б�*/
typedef struct hiHI_UNF_SIF_STANDARD_PRIORITY_LIST_S
{
    HI_U32 u32ListLen;
    HI_UNF_SIF_STANDARD_TYPE_E enPriorityList[HI_UNF_SIF_STANDARD_NUM_MAX];
} HI_UNF_SIF_STANDARD_PRIORITY_LIST_S;

/** @}*/  /** <!-- ==== Structure Definition End ====*/

/******************************* API Declaration *****************************/
/** \addtogroup      SIF */
/** @{*/  /** <!-- [SIF] */


/** 
\brief Get Basic Audio Standard. CNcomment:��ȡ��Ƶ����������ʽ CNend
\attention \n
\param[in] enOriginalStandard     Audio SIF Standard Type  CNcomment:��Ƶ�ڶ�������Ƶ��ʽ CNend
\param[out] penBasicStandard      Audio SIF Standard Type  CNcomment:��Ƶ�ڶ�������Ƶ������ʽ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_ERR_SIF_INVALID_ID	 The parameter enSound is invalid. CNcomment:��ЧSound ID CNend
\retval ::HI_ERR_SIF_NULL_PTR     The pointer is null. CNcomment:ָ�����Ϊ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_MapBasicAudioStandard(HI_UNF_SIF_STANDARD_TYPE_E enOriginalStandard,
                                           HI_UNF_SIF_STANDARD_TYPE_E *penBasicStandard);

/** 
\brief Initializes an SIF device. CNcomment:��ʼ��SIFģ�� CNend
\attention \n
Before calling the SIF module, you must call this application programming interface (API). CNcomment:����SIFģ��Ҫ�����ȵ��øýӿ� CNend
\param N/A
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Init(HI_VOID);

/** 
\brief Deinitializes an SIF device. CNcomment:ȥ��ʼ���豸 CNend
\attention \n
N/A
\param N/A
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend 
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_DeInit(HI_VOID);

/** 
\brief Open an SIF device. CNcomment:��SIF�豸 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] pstOpenPara     Prameter of an SIF device CNcomment:SIF�豸���� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Open(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OPENPARMS_S *pstOpenPara);

/** 
\brief Close an SIF device. CNcomment:�ر�SIF�豸 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Close(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Set The Attribute SIF device. CNcomment:����SIF�豸���� CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] pstSifAttr      Attribute of an SIF device CNcomment:SIF�豸���� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Get The Default Attribute SIF device. CNcomment:��ȡSIF�豸Ĭ������ CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] pstSifAttr     Default Attribute of an SIF device CNcomment:SIF�豸���� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetDefaultAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Get The Attribute SIF device. CNcomment:��ȡSIF�豸���� CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] pstSifAttr     Attribute of an SIF device CNcomment:SIF�豸���� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetAttr(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_ATTR_S *pstSifAttr);

/** 
\brief Start The SIF device. CNcomment:����SIF�豸 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Start(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Stop The SIF device. CNcomment:ֹͣSIF�豸 CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_Stop(HI_UNF_SIF_ID_E enSIf);

/** 
\brief Set The Audio Standard. CNcomment:������Ƶ������ʽ CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] enSifStandard   Audio Standard of an SIF device CNcomment:SIF��Ƶ������ʽ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E enSifStandard);

/** 
\brief Start The Auto Standard Detect. CNcomment:�����Զ���ʽ��� CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] enSifDetCtl     Auto Standard Detect of an SIF device CNcomment:SIF�Զ���ʽ������ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_StartAutoStandardDetection(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_SYSCTL_E enSifDetCtl);

/** 
\brief Get The Audio Standard Detect Complete Flag. CNcomment:��ȡ�Զ���ʽ�����ɱ�־ CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] pbAsdComplete  Audio Standard Detect Complete Flag of an SIF device CNcomment:SIFģ����ʽ�����ɱ�־ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetDetectComplete(HI_UNF_SIF_ID_E enSIf, HI_BOOL *pbAsdComplete);

/** 
\brief Get The Audio Standard . CNcomment:��ȡ������ʽ CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] penSifStandard  Audio Standard of an SIF device CNcomment:SIFģ����Ƶ������ʽ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetUserSettingStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E *penSifStandard);

/** 
\brief Get The Result of Auto Standard Detect. CNcomment:��ȡ�Զ���ʽ����� CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] penSifAutoStandard  The Result of Auto Standard Detect of an SIF device CNcomment:SIFģ���Զ�������ʽ����� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetAutoDetectStandard(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_TYPE_E *penSifAutoStandard);

/** 
\brief Set Audio Mode of SIF. CNcomment:������Ƶ����ģʽ CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] enSifOutmode    Aduio Standard of an SIF device CNcomment:SIFģ�����ģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetSoundMode(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OUTMODE_E enSifOutmode);

/** 
\brief Get Audio Mode of SIF. CNcomment:��ȡ��Ƶ����ģʽ CNend
\attention \n
N/A
\param[in] enSIf           ID of an SIF device CNcomment:SIF�豸�� CNend
\param[out] penSifOutmode  Aduio Mode of an SIF device CNcomment:SIFģ�����ģʽ CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetSoundMode(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_AAOS_MODE_E *penSifOutmode);

/** 
\brief Set Over Demulation Parameter of SIF. CNcomment:������Ƶ�����Ʋ��� CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] enOverDeviation  Over Devation Parameter of an SIF device CNcomment:SIFģ������Ʋ��� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetOverDeviation(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_OVER_DEVIATION_E enOverDeviation);

/** 
\brief Set Carrier Shift Parameter of SIF. CNcomment:������ƵƵ�� CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] u32CarriShift    Carrier Shift Parameter of an SIF device CNcomment:SIFģ��Ƶ�Ʋ��� CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_SetCarriShift(HI_UNF_SIF_ID_E enSIf, HI_U32 u32CarriShift);

/**
\brief Get The Audio carrier attribution. CNcomment:��ȡ�����ز����� CNend
\attention \n
N/A
\param[in] enSIf            ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] pstCarrierAttr    Attribution of Audio Carrier CNcomment:�����ز�����CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32    HI_UNF_SIF_GetStandardTry(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_CARRIER_ATTR_S *pstCarrierAttr);

/**
\brief Set the standard list for try interface. CNcomment:������ʽʶ�����ȼ��б��Try�ӿ� CNend
\attention \n
N/A
\param[in] enSIf             ID of an SIF device CNcomment:SIF�豸�� CNend
\param[in] pstPriorityList   STANDARD PRIORITY LIST CNcomment:��ʽ���ȼ��б�CNend
\retval ::HI_SUCCESS Success CNcomment:�ɹ� CNend
\retval ::HI_FAILURE FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_SIF_SetStandardTryPriority(HI_UNF_SIF_ID_E enSIf, HI_UNF_SIF_STANDARD_PRIORITY_LIST_S *pstPriorityList);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* __HI_UNF_SIF_H__ */
