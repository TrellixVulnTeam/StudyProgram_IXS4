/******************************************************************************

  Copyright (C), 2001-2050, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_atv.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2013/10/6
  Description   :
  History       :
  1.Date        : 2013/10/6
    Author      : ATV
    Modification: Created file

*******************************************************************************/
#ifndef __HI_UNF_ATV_H__
#define __HI_UNF_ATV_H__

/* add include here */
#include "hi_type.h"
#include "hi_common.h"
#include "hi_unf_common.h"
#include "hi_unf_video.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      ATV */
/** @{ */  /** <!-- [ATV] */

/**Defines input source type enum*/
/**CNcomment:��������Դ���ö��*/
typedef enum hiUNF_INPUT_SOURCE_TYPE_E
{
    HI_UNF_INPUT_SOURCE_DTV = 0,    
    HI_UNF_INPUT_SOURCE_USB,
        
    HI_UNF_INPUT_SOURCE_ATV,
    HI_UNF_INPUT_SOURCE_SCART,
    HI_UNF_INPUT_SOURCE_SVIDEO,
    HI_UNF_INPUT_SOURCE_CVBS,
    HI_UNF_INPUT_SOURCE_VGA,
    HI_UNF_INPUT_SOURCE_YPBPR,
    HI_UNF_INPUT_SOURCE_HDMI,
 
    HI_UNF_INPUT_SOURCE_BUTT
} HI_UNF_INPUT_SOURCE_TYPE_E;

/**Defines NonStandard image infomation num*/
/**CNcomment: ����Ǳ��ź���Ϣö��*/
typedef struct hiUNF_VIDEO_NONSTD_INFO_S
{
    HI_BOOL bNonStd;            /**<NonStd or not *//**<CNcomment: �Ƿ�Ǳ�*/                          
    HI_U32  u32Height;          /**<height of NonStd *//**<CNcomment: �Ǳ�ͼ��߶�*/   
    HI_U32  u32VFreq;           /**<field frequency,use number of fields per 1000 secend as unit,for example,61050 is 60.5Hz *//**<CNcomment: �Ǳ����볡Ƶ ��λΪÿǧ�볡��Ŀ������61050��ʾ61.05Hz*/ 
} HI_UNF_VIDEO_NONSTD_INFO_S;

/**Defines TV format enum*/
/**CNcomment: ���������ʽö��*/
typedef enum hiUNF_COLOR_SYS_E
{
    HI_UNF_COLOR_SYS_AUTO = 0,
    HI_UNF_COLOR_SYS_PAL,
    HI_UNF_COLOR_SYS_NTSC,
    HI_UNF_COLOR_SYS_SECAM,
    HI_UNF_COLOR_SYS_PAL_M,
    HI_UNF_COLOR_SYS_PAL_N,
    HI_UNF_COLOR_SYS_PAL_60,
    HI_UNF_COLOR_SYS_NTSC443,
    HI_UNF_COLOR_SYS_NTSC_50,
    
    HI_UNF_COLOR_SYS_BUTT
} HI_UNF_COLOR_SYS_E;

/**Defines source type enum*/
/**CNcomment: ��������Դö��*/
typedef enum hiUNF_SOURCE_TYPE_E
{
    HI_UNF_SOURCE_TVD = 0,
    HI_UNF_SOURCE_HDDEC,
    HI_UNF_SOURCE_HDMI,
    HI_UNF_SOURCE_EXTERN,           /**<extern interface*//**<CNcomment: �ⲿ�ӿ�*/
    
    HI_UNF_SOURCE_TYPE_BUTT
} HI_UNF_SOURCE_TYPE_E;

/**Defines the state of the color calibration.*/
/**CNcomment: ����ɫ��У����״̬ */
typedef enum hiUNF_COLOR_CALIB_STATE_E 
{
	HI_UNF_COLOR_CALIB_BEGIN = 0, /**<Color calibration begin*//**<CNcomment:��ɫУ����ʼ */
	HI_UNF_COLOR_CALIB_FINISH,    /**<Color calibration finished*//**<CNcomment:��ɫУ����� */
	HI_UNF_COLOR_CALIB_TIMEOUT,   /**<Color calibration timeout*//**<CNcomment:��ɫУ����ʱ����*/
	HI_UNF_COLOR_CALIB_FAIL,	    /**<Color calibration failed*//**<CNcomment:��ɫУ��ʧ�� */
	HI_UNF_COLOR_CALIB_BUTT       /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_COLOR_CALIB_STATE_E;

/**Defines the result data of the color calibration.*/
/**CNcomment: ������ɫУ���Ľ������ */
typedef struct hiUNF_COLOR_CALIB_PARAM_S 
{
    HI_U32 u32RGain;           /**<R Gain*/ /**<CNcomment:Rͨ������*/
    HI_U32 u32GGain;           /**<G Gain*/ /**<CNcomment:Gͨ������*/
    HI_U32 u32BGain;           /**<B Gain*/ /**<CNcomment:Bͨ������*/
    HI_U32 u32ROffset;         /**<R Offset*/ /**<CNcomment:Rͨ��ƫ��*/
    HI_U32 u32GOffset;         /**<G Offset*/ /**<CNcomment:Gͨ��ƫ��*/
    HI_U32 u32BOffset;         /**<B Offset*/ /**<CNcomment:Bͨ��ƫ��*/
} HI_UNF_COLOR_CALIB_PARAM_S;

/**Defines the info of the color calibration.*/
/**CNcomment: ������ɫУ������Ϣ */
typedef struct hiUNF_COLOR_CALIB_INFO_S 
{
    HI_UNF_COLOR_CALIB_STATE_E   enCalibState;   /**<Color calibration state */ /**<CNcomment:��ɫУ��״̬��Ϣ */
    HI_UNF_COLOR_CALIB_PARAM_S   stCalibParam;   /**<Color calibration parmeters */ /**<CNcomment:��ɫУ������ */
} HI_UNF_COLOR_CALIB_INFO_S;

/**Input signal Pin definition.*/
/**CNcomment: �ź��������Ŷ��� */
typedef enum hiUNF_INPUT_MUX_E
{
    HI_UNF_INPUT_MUX_CVBS0 = 0, /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF����ѡ���*/
    HI_UNF_INPUT_MUX_CVBS1,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF����ѡ���*/
    HI_UNF_INPUT_MUX_CVBS2,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF����ѡ���*/
    HI_UNF_INPUT_MUX_CVBS3,     /**<CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF MUX input Pin */ /**<CNcomment: CVBS, SVideo Y/C, SCART CVBS, SCART Y/C, SIF����ѡ���*/

    HI_UNF_INPUT_MUX_R,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_PR0,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_PR1,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    
    HI_UNF_INPUT_MUX_G,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_Y0,        /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_Y1,        /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/

    HI_UNF_INPUT_MUX_B,         /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_PB0,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/
    HI_UNF_INPUT_MUX_PB1,       /**<VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B MUX input Pin */ /**<CNcomment: VGA R/G/B, YPbPr Y/Pb/Pr, SCART R/G/B����ѡ���*/

    HI_UNF_INPUT_MUX_BUTT,      /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_INPUT_MUX_E;

/**SOG Pin definition.*/
/**CNcomment: SOG�ź��������Ŷ��� */
typedef enum hiUNF_INPUT_MUX_SOG_E 
{
    HI_UNF_INPUT_MUX_SOG = 0,    /**<SOG Pin */  /**<CNcomment:SOG���� */
    HI_UNF_INPUT_MUX_SOY0,       /**<SOY0 Pin */ /**<CNcomment:SOY0���� */
    HI_UNF_INPUT_MUX_SOY1,       /**<SOY1 Pin */ /**<CNcomment:SOY1���� */

    HI_UNF_INPUT_MUX_SOG_BUTT,   /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_INPUT_MUX_SOG_E;

/**HV separate SYNC Pin definition.*/
/**CNcomment: HV����ͬ����������ѡ�� */
typedef enum hiUNF_INPUT_MUX_SYNC_E 
{
    HI_UNF_INPUT_MUX_SYNC_HVS0 = 0,  /**<HVS0 Pin */  /**<CNcomment:HVS0���� */
    HI_UNF_INPUT_MUX_SYNC_HVS1,      /**<HVS1 Pin */  /**<CNcomment:HVS1���� */
 
    HI_UNF_INPUT_MUX_SYNC_BUTT,      /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_INPUT_MUX_SYNC_E;

/**Offline Pin definition*/
/**CNcomment: HV����ͬ����������ѡ�� */
typedef enum hiUNF_INPUT_MUX_OFFLINE_E 
{
    HI_UNF_INPUT_MUX_OFFLINE_SOG = 0,     /**<Offline SOG Pin */  /**<CNcomment:���߼��SOG��*/
    HI_UNF_INPUT_MUX_OFFLINE_SOY0,        /**<Offline SOY0 Pin */  /**<CNcomment:���߼��SOY0��*/
    HI_UNF_INPUT_MUX_OFFLINE_SOY1,        /**<Offline SOY1 Pin */  /**<CNcomment:���߼��SOY1��*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS0,       /**<Offline CVBS0 Pin */  /**<CNcomment:���߼��CVBS0��*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS1,       /**<Offline CVBS1 Pin */  /**<CNcomment:���߼��CVBS1��*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS2,       /**<Offline CVBS2 Pin */  /**<CNcomment:���߼��CVBS2��*/
    HI_UNF_INPUT_MUX_OFFLINE_CVBS3,       /**<Offline CVBS3 Pin */  /**<CNcomment:���߼��CVBS3��*/ 
    //HI_UNF_INPUT_MUX_OFFLINE_SCART_0,   /**<Offline SCART0 Pin */  /**<CNcomment:���߼��SCART0��*/
    //HI_UNF_INPUT_MUX_OFFLINE_SCART_1,   /**<Offline SCART1 Pin */  /**<CNcomment:���߼��SCART1��*/

    HI_UNF_INPUT_MUX_OFFLINE_BUTT,        /**<Invalid value*/ /**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_INPUT_MUX_OFFLINE_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_ATV_ H*/


