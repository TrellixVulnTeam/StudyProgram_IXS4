/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_unf_pq.h
  Version       : Initial Draft
  Author        : l00212594/y00220178
  Created       : 2013/10/29
  Description   :

******************************************************************************/

#ifndef __HI_UNF_PQ_H__
#define __HI_UNF_PQ_H__

#include "hi_type.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PQ*/
/** @{ */  /** <!-- [PQ] */

/**PQ matket mode *//**CNcomment: PQ����ģʽ */
typedef enum hiUNF_PQ_DEMO_E
{
     HI_UNF_PQ_DEMO_DBDR,
     HI_UNF_PQ_DEMO_NR,
     HI_UNF_PQ_DEMO_SHARPNESS,
     HI_UNF_PQ_DEMO_DCI,
     HI_UNF_PQ_DEMO_WCG,
    // HI_UNF_PQ_DEMO_FRC,
     HI_UNF_PQ_DEMO_COLOR,
     HI_UNF_PQ_DEMO_SR,
     HI_UNF_PQ_DEMO_ALL,

     HI_UNF_PQ_DEMO_BUTT
}  HI_UNF_PQ_DEMO_E;

/**PQ on/off module *//**CNcomment: PQ����ģ��*/
typedef enum hiUNF_PQ_MODULE_E
{
     HI_UNF_PQ_MODULE_FMD = 0,
     HI_UNF_PQ_MODULE_TNR,
     HI_UNF_PQ_MODULE_SNR,
     HI_UNF_PQ_MODULE_DB,
     HI_UNF_PQ_MODULE_DR,
     HI_UNF_PQ_MODULE_HSHARPNESS,
     HI_UNF_PQ_MODULE_SHARPNESS,
     HI_UNF_PQ_MODULE_CCCL,
     HI_UNF_PQ_MODULE_COLOR_CORING,
     HI_UNF_PQ_MODULE_BLUE_STRETCH,
     HI_UNF_PQ_MODULE_GAMMA,
     HI_UNF_PQ_MODULE_DBC,
     HI_UNF_PQ_MODULE_DCI,
     HI_UNF_PQ_MODULE_COLOR,
     HI_UNF_PQ_MODULE_ES,
     HI_UNF_PQ_MODULE_SR,
     HI_UNF_PQ_MODULE_FRC,
     HI_UNF_PQ_MODULE_WCG,

     HI_UNF_PQ_MODULE_BUTT
}  HI_UNF_PQ_MODULE_E;

/**Color temperature information*//**CNcomment: ɫ����Ϣ*/
typedef struct hiUNF_PQ_COLOR_TEMP_S
{
    HI_U32 u32RedGain;
    HI_U32 u32GreenGain;
    HI_U32 u32BlueGain;
    HI_U32 u32RedOffset;
    HI_U32 u32GreenOffset;
    HI_U32 u32BlueOffset;
}  HI_UNF_PQ_COLOR_TEMP_S;

/**Flesh tone gain type*//**CNcomment: ��ɫ��������*/
typedef enum hiUNF_PQ_FLESHTONE_E
{
     HI_UNF_PQ_FLESHTONE_GAIN_OFF = 0,
     HI_UNF_PQ_FLESHTONE_GAIN_LOW,
     HI_UNF_PQ_FLESHTONE_GAIN_MID,
     HI_UNF_PQ_FLESHTONE_GAIN_HIGH,

     HI_UNF_PQ_FLESHTONE_GAIN_BUTT
}  HI_UNF_PQ_FLESHTONE_E;

/**Six base color type*//**CNcomment: ����ɫ����*/
typedef enum hiUNF_PQ_SIX_BASE_COLOR_E
{
    HI_UNF_PQ_SIX_BASE_COLOR_ALL_ON = 0,
    HI_UNF_PQ_SIX_BASE_COLOR_R_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_G_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_B_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_CYAN_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_MAGENTA_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_YELLOW_OFF,//��
    HI_UNF_PQ_SIX_BASE_COLOR_RGB_OFF,//������
    HI_UNF_PQ_SIX_BASE_COLOR_CMY_OFF,//���ϻ�
    HI_UNF_PQ_SIX_BASE_COLOR_ALL_OFF,//������ɫ�ر�

    HI_UNF_PQ_SIX_BASE_COLOR_BUTT
} HI_UNF_PQ_SIX_BASE_COLOR_E;

/**SR demo mode*//**CNcomment: SR��ʾģʽ*/
typedef enum hiUNF_PQ_SR_DEMO_E
{
     HI_UNF_PQ_SR_DISABLE  = 0,//�ص�SR,ֻZME
     HI_UNF_PQ_SR_ENABLE_R,  //  �ұ�SR
     HI_UNF_PQ_SR_ENABLE_L,  //���SR
     HI_UNF_PQ_SR_ENABLE_A,  //ȫ��

     HI_UNF_PQ_SR_DEMO_BUTT
}HI_UNF_PQ_SR_DEMO_E;

/**Brightness histgram information*//**CNcomment: ����ֱ��ͼ��Ϣ*/
typedef struct hiUNF_PQ_DCI_HISTGRAM_S
{
    HI_S32 s32HistGram[32];
}HI_UNF_PQ_DCI_HISTGRAM_S;

/****  �Զ���ƽ��������  ****/
typedef enum hiUNF_PQ_WHITE_BALANCE_TMP_E
{
   HI_UNF_PQ_WHITE_BALANCE_COOL,
   HI_UNF_PQ_WHITE_BALANCE_STANDARD,
   HI_UNF_PQ_WHITE_BALANCE_WARM,

   HI_UNF_PQ_WHITE_BALANCE_BUTT
 }HI_UNF_PQ_WHITE_BALANCE_TMP_E;

typedef struct hiUNF_PQ_WHITE_BALANCE_BALANCE_SINGLE_PARAM_S
{  
   HI_U32 u32RGain;
   HI_U32 u32GGain;
   HI_U32 u32BGain;
   HI_U32 u32ROffset;
   HI_U32 u32GOffset;
   HI_U32 u32BOffset;
}HI_UNF_PQ_WHITE_BALANCE_SINGLE_PARAM_S;

typedef struct hiUNF_PQ_WHITE_BALANCE_PARAM_S
{ 
   HI_UNF_PQ_WHITE_BALANCE_SINGLE_PARAM_S astTepParam[HI_UNF_PQ_WHITE_BALANCE_BUTT];
}HI_UNF_PQ_WHITE_BALANCE_PARAM_S;


/**Sharpen GAIN*//**CNcomment: �߼�����������*/
typedef struct hiUNF_PQ_SHARP_GAIN_S
{
	HI_U32 u32LtiGain; //��Χ[ 0 , 511]
	HI_U32 u32HPeakRatio; //��Χ[ 0 , 511]
	HI_U32 u32VPeakRatio; //��Χ[ 0 , 511]
	HI_U32 u32DPeakRatio; //��Χ[ 0 , 511]
	
}HI_UNF_PQ_SHARP_GAIN_S;

/**Color GAIN*//**CNcomment:Color   ����*/
typedef struct hiUNF_PQ_ACM_GAIN_S
{
	HI_U32 u32LumGain; //��Χ[ 0 , 1023]
	HI_U32 u32HueGain; //��Χ[ 0 , 1023]
	HI_U32 u32SatGain; //��Χ[ 0 , 1023]
	HI_U32 u32Reserved;
}HI_UNF_PQ_ACM_GAIN_S;

/**DCI GAIN*//**CNcomment:Color   ����*/
typedef struct hiUNF_PQ_DCI_GAIN_S
{
	HI_U32 u32LowGain; //��Χ[ 0 , 63]
	HI_U32 u32MiddleGain; //��Χ[ 0 , 63]
	HI_U32 u32HighGain; //��Χ[ 0 , 63]
	HI_U32 u32Reserved;
}HI_UNF_PQ_DCI_GAIN_S;

/* Color Space*//**CNcomment:ɫ��ռ�*/
typedef enum hiUNF_PQ_COLOR_SPACE_E
{
    HI_UNF_CS_UNKNOWN = 0,
    HI_UNF_CS_DEFAULT,
    HI_UNF_CS_BT601_YUV_LIMITED,/* ::::Current Used:::: BT.601  */
    HI_UNF_CS_BT601_YUV_FULL,
    HI_UNF_CS_BT601_RGB_LIMITED,
    HI_UNF_CS_BT601_RGB_FULL,
    HI_UNF_CS_NTSC1953,
    HI_UNF_CS_BT470_SYSTEM_M,    
    HI_UNF_CS_BT470_SYSTEM_BG,
    HI_UNF_CS_BT709_YUV_LIMITED,/* ::::Current Used:::: BT.709 */
    HI_UNF_CS_BT709_YUV_FULL,
    HI_UNF_CS_BT709_RGB_LIMITED,
    HI_UNF_CS_BT709_RGB_FULL,   /* ::::Current Used:::: */
    
    HI_UNF_CS_BT2020_YUV_LIMITED,/* ::::Current Used:::: BT.2020 */
    HI_UNF_CS_BT2020_YUV_FULL,
    HI_UNF_CS_BT2020_RGB_LIMITED,
    HI_UNF_CS_BT2020_RGB_FULL,   /* ::::Current Used:::: */
    
    HI_UNF_CS_REC709,      /* HD and modern captures. */
    
    HI_UNF_CS_SMPT170M, /* ITU-R 601 -- broadcast NTSC/PAL */
    HI_UNF_CS_SMPT240M, /* 1125-Line (US) HDTV */
    HI_UNF_CS_BT878,    
    HI_UNF_CS_XVYCC,
    HI_UNF_CS_JPEG,
    HI_UNF_CS_RGB,
   
    HI_UNF_CS_BUTT
} HI_UNF_PQ_COLOR_SPACE_E;

/* Gamma Type*//**CNcomment:Gamma ����*/
typedef enum hiUNF_PQ_GAMMA_TYPE_E
{              
    HI_UNF_GAMMA_TYPE_1886 = 0,
    HI_UNF_GAMMA_TYPE_2084,

    HI_UNF_GAMMA_TYPE_BUTT
} HI_UNF_PQ_GAMMA_TYPE_E;

typedef struct hiUNF_PQ_HDR10_METADATA_S
{
    HI_U32        u32DispPrimariesX0;
    HI_U32        u32DispPrimariesY0;
    HI_U32        u32DispPrimariesX1;
    HI_U32        u32DispPrimariesY1;
    HI_U32        u32DispPrimariesX2;
    HI_U32        u32DispPrimariesY2;
    HI_U32        u32WhitePointX;
    HI_U32        u32WhitePointY;
    HI_U32        u32MaxDispMasteringLuminance;
    HI_U32        u32MinDispMasteringLuminance;
    HI_U32        u32MaxContentLightLevel;
    HI_U32        u32MaxFrmAverageLightLevel;
}HI_UNF_PQ_HDR10_METADATA_S;

/* HDR INFO*//**CNcomment:HDR  ��Ϣ*/
typedef struct hiUNF_PQ_HDR_INFO_S
{
	HI_UNF_PQ_COLOR_SPACE_E    	eColorSpace;	
    HI_UNF_PQ_GAMMA_TYPE_E     	eGammaType;
    HI_UNF_PQ_HDR10_METADATA_S  stMetadata;
} HI_UNF_PQ_HDR_INFO_S;

/* HDR FIXMODE*//**CNcomment:FIXMODE  ��Ϣ*/
typedef struct hiUNF_PQ_HDR_FIXMODE_S
{  
   HI_BOOL bFixed;
   HI_UNF_PQ_HDR_INFO_S stHdrInfo;   
}HI_UNF_PQ_HDR_FIXMODE_S;

/* Color Section*//**CNcomment:��ɫ�ֶ����� */
typedef enum hiUNF_PQ_COLOR_E
{
    HI_UNF_PQ_COLOR_R,//��
    HI_UNF_PQ_COLOR_G,//��
   	HI_UNF_PQ_COLOR_B,//��
   	HI_UNF_PQ_COLOR_CYAN,//��
    HI_UNF_PQ_COLOR_PURPLE,//��
    HI_UNF_PQ_COLOR_YELLOW,//��
	HI_UNF_PQ_COLOR_FLESH,//��ɫ

    HI_UNF_PQ_COLOR_BUTT
} HI_UNF_PQ_COLOR_E;


/* Color SATGAIN*//**CNcomment:��ɫ���Ͷ�����  */
typedef struct hiUNF_PQ_SAT_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_SAT_GAIN_S;

/* Color HUEGAIN*//**CNcomment:��ɫɫ������ */
typedef struct hiUNF_PQ_HUE_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_HUE_GAIN_S;

/* Color YGAIN*//**CNcomment:��ɫ��������  */
typedef struct hiUNF_PQ_BRI_GAIN_S
{
	HI_UNF_PQ_COLOR_E enColorType;
	HI_S32 s32Gain;
}HI_UNF_PQ_BRI_GAIN_S;

/*gamma�ṹ*/
typedef struct hiUNF_GAMMA_TABLE_S
{
    HI_U32 au32R[257];
    HI_U32 au32G[257];
    HI_U32 au32B[257];
} HI_UNF_GAMMA_TABLE_S;

/*NR  str type Y/C*/
typedef enum hiUNF_PQ_NRSTR_E
{
     HI_UNF_PQ_NRSTR_Y = 0,
     HI_UNF_PQ_NRSTR_C,
     HI_UNFPQ_NRSTR_BUTT
} HI_UNF_PQ_NRSTR_E;

typedef struct hiUNF_PQ_NRSTR_GAIN_S
{
	HI_UNF_PQ_NRSTR_E enNRSTR;
	HI_U32 u32Gain;
}HI_UNF_PQ_NRSTR_GAIN_S;

/*COLOR ������*/
typedef enum hiUNF_PQ_COLOR_TYPE_E
{
    HI_UNF_PQ_COLOR_NORMAL =0,
    HI_UNF_PQ_COLOR_VIVID,
    HI_UNF_PQ_COLOR_HDR,
    HI_UNF_PQ_COLOR_TYPE_1,
    HI_UNF_PQ_COLOR_TYPE_2,   
    HI_UNF_PQ_COLOR_TYPE_3,
    HI_UNF_PQ_COLOR_TYPE_4,
    HI_UNF_PQ_COLOR_TYPE_5,

    HI_UNF_PQ_COLOR_TYPE_BUTT
} HI_UNF_PQ_COLOR_TYPE_E;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API declaration *****************************/
/** \addtogroup      PQ  */
/** @{ */  /** <!-- [PQ ] */


/**
 \brief the whole initialization of the PQ device. CNcomment:PQ�ӿ����������ʼ�� CNend
 \attention \n
 \param[in] pszPath.CNcomment:PQ�����ļ�·��CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_Init(HI_CHAR* pszPath);

/**
 \brief deinit the PQ device. CNcomment:PQ�ӿ��������ȥ��ʼ�� CNend
 \attention \n
 \param CNcomment:�� CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_DeInit(HI_VOID);

/**
 \brief get brightness. CNcomment:��ȡ���� CNend
 \attention \n
 \param[out] pu32Brightness.CNcomment:����ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetBrightness(HI_U32 *pu32Brightness);

/**
 \brief set brightness. CNcomment:�������� CNend
 \attention \n
 \param[in] u32Brightness.CNcomment:����ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetBrightness(HI_U32 u32Brightness);

/**
 \brief get contrast. CNcomment:��ȡ�Աȶ� CNend
 \attention \n
 \param[out] pu32Contrast.CNcomment:�Ա�ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetContrast(HI_U32 *pu32Contrast);

/**
 \brief set Contrast. CNcomment:���öԱȶ� CNend
 \attention \n
 \param[in] u32Contrast.CNcomment:�Աȶ�ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetContrast(HI_U32 u32Contrast);

/**
 \brief get saturation. CNcomment:��ȡ���Ͷ� CNend
 \attention \n
 \param[out] pu32Saturation.CNcomment:���Ͷ� ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetSaturation(HI_U32 *pu32Saturation);

/**
 \brief set saturation. CNcomment:���ñ��Ͷ� CNend
 \attention \n
 \param[in] u32Saturation.CNcomment:���Ͷ�ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetSaturation(HI_U32 u32Saturation);

/**
 \brief get hue. CNcomment:��ȡɫ��CNend
 \attention \n
 \param[out] pu32Hue.CNcomment:ɫ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetHue(HI_U32 *pu32Hue);

/**
 \brief set hue. CNcomment:����ɫ��CNend
 \attention \n
 \param[in] u32Hue.CNcomment:ɫ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetHue(HI_U32 u32Hue);

/**
 \brief get noise reduction level. CNcomment:��ȡ����ǿ��CNend
 \attention \n
 \param[out] pu32NRLevel.CNcomment:����ǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetNR(HI_U32 *pu32NRLevel);

/**
 \brief set noise reduction level. CNcomment:��ȡ����ǿ��CNend
 \attention \n
 \param[in] u32NRLevel.CNcomment:����ǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetNR(HI_U32 u32NRLevel);

/**
 \brief get  auto noise reduction status. CNcomment:��ȡ�Զ����뿪��״̬CNend
 \attention \n
 \param[out] pu32OnOff.CNcomment:����״̬ CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetNRAutoMode(HI_U32 *pu32OnOff);

/**
 \brief set  auto noise reduction status. CNcomment:�����Զ����뿪��״̬CNend
 \attention \n
 \param[in] u32OnOff.CNcomment:����״̬ CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetNRAutoMode(HI_U32 u32OnOff);

/**
 \brief get  SR demo type. CNcomment:��ȡ����SR��ʾ����CNend
 \attention \n
 \param[out] penType.CNcomment:��ʾ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetSRMode(HI_UNF_PQ_SR_DEMO_E *penType);

/**
 \brief set  SR demo type. CNcomment:���ó���SR��ʾ����CNend
 \attention \n
 \param[in] enType.CNcomment:��ʾ����CCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetSRMode(HI_UNF_PQ_SR_DEMO_E enType);

/**
 \brief get sharpness level. CNcomment:��ȡ������ǿ��CNend
 \attention \n
 \param[out] pu32Sharpness.CNcomment:������ǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetSharpness(HI_U32 *pu32Sharpness);

/**
 \brief set sharpness level. CNcomment:����������ǿ��CNend
 \attention \n
 \param[in] u32Sharpness.CNcomment:������ǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetSharpness(HI_U32 u32Sharpness);

/**
 \brief get de-blocking level. CNcomment:��ȡ�齵��De-blockingǿ��CNend
 \attention \n
 \param[out] pu32DBlevel.CNcomment:De-blockingǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetDeBlocking(HI_U32 *pu32DBlevel);

/**
 \brief set de-blocking level. CNcomment:���ÿ齵��De-blockingǿ��CNend
 \attention \n
 \param[in] u32DBlevel.CNcomment:De-blockingǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetDeBlocking(HI_U32 u32DBlevel);

/**
 \brief get de-ringing level. CNcomment:��ȡȥ���ó�����de-ringingǿ��CNend
 \attention \n
 \param[out] pu32DRlevel.CNcomment:De-ringingǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetDeRinging(HI_U32 *pu32DRlevel);

/**
 \brief set de-ringing level. CNcomment:����ȥ���ó�����de-ringingǿ��CNend
 \attention \n
 \param[in] u32DRlevel.CNcomment:De-ringingǿ��ֵ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetDeRinging(HI_U32 u32DRlevel);

/**
 \brief set color temperature. CNcomment:����ɫ��ֵCNend
 \attention \n
 \param[in] pstColorTemp.CNcomment:ɫ��ֵ ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief get color temperature. CNcomment:��ȡɫ��ֵCNend
 \attention \n
 \param[out] pstColorTemp.CNcomment:ɫ��ֵ ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief get color type. CNcomment:��ȡ��ɫ���������ļ�CNend
 \attention \n
 \param[out] pu32ColorType.CNcomment: �ο�HI_UNF_PQ_COLOR_TYPE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetColorGain(HI_UNF_PQ_COLOR_TYPE_E *penColorType);

/**
 \brief set color type. CNcomment:��̬���ز�ͬ��ɫ���������ļ�
 \attention \n
 \param[in] enColorType.CNcomment: �ο� HI_UNF_PQ_COLOR_TYPE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetColorGain(HI_UNF_PQ_COLOR_TYPE_E enColorType);
/**
 \brief get flesh tone level. CNcomment:��ȡ��ɫ��ǿǿ��CNend
 \attention \n
 \param[out] pu32FleshToneLevel.CNcomment:ǿ�� ,�ο� HI_UNF_PQ_FLESHTONE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetFleshTone(HI_UNF_PQ_FLESHTONE_E *pu32FleshToneLevel);

/**
 \brief set flesh tone level. CNcomment:���÷�ɫ��ǿǿ��CNend
 \attention \n
 \param[in] enFleshToneLevel.CNcomment:ǿ�� ,�ο� HI_UNF_PQ_FLESHTONE_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetFleshTone( HI_UNF_PQ_FLESHTONE_E enFleshToneLevel);

/**
 \brief get six base color demo type. CNcomment:��ȡ����ɫ��ʾ����CNend
 \attention \n
 \param[out] pu32SixBaseColor.CNcomment:����ɫ���� ,�ο� HI_UNF_PQ_SIX_BASE_COLOR_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetSixBaseColor(HI_UNF_PQ_SIX_BASE_COLOR_E *pu32SixBaseColor);

/**
 \brief set six base color demo type. CNcomment:��������ɫ��ʾ����CNend
 \attention \n
 \param[in] enSixBaseColor.CNcomment:����ɫ���� ,�ο� HI_UNF_PQ_SIX_BASE_COLOR_E CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetSixBaseColor(HI_UNF_PQ_SIX_BASE_COLOR_E enSixBaseColor);

/**
 \brief get back light level. CNcomment:��ȡ����ǿ��CNend
 \attention \n
 \param[out] pu32BackLightLevel.CNcomment:����ǿ�� ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetBackLight(HI_U32 *pu32BackLightLevel);

/**
 \brief set back light level. CNcomment:���ñ���ǿ��CNend
 \attention \n
 \param[in] u32BackLightLevel.CNcomment:����ǿ�� ,��Ч��ΧΪ0~255 CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetBackLight(HI_U32 u32BackLightLevel);

/**
 \brief get gamma total number. CNcomment:Gamma Table�п��ܴ��ڶ���Gamma����,�û��ɻ�ȡGamma��������CNend
 \attention \n
 \param[out] s32Num.CNcomment:gamma ���� CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
 
extern HI_S32 HI_UNF_PQ_GetGammaNum(HI_S32 *s32Num);

/**
 \brief set gamma by index. CNcomment:����gamma CNend
 \attention \n
 \param[in] s32GammaIndex.CNcomment:gamma index CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_SetGamma(HI_S32 s32GammaIndex);

/**
 \brief set all PQ module on/off status. CNcomment:���ø�PQ ģ�鿪�� CNend
 \attention \n
 \param[in] enFlags.CNcomment:ģ��ţ��ο�HI_UNF_PQ_MODULE_E CNend
 \param[in] u32OnOff.CNcomment:���� CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
 
extern HI_S32 HI_UNF_PQ_SetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 u32OnOff);

/**
 \brief get all PQ module on/off status. CNcomment:��ȡ��PQ ģ�鿪�� CNend
 \attention \n
 \param[in] enFlags.CNcomment:ģ��ţ��ο�HI_UNF_PQ_MODULE_E CNend
 \param[out] u32OnOff.CNcomment:����״̬ CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief set all PQ module demo status. CNcomment:���ø�PQ ģ������ģʽ CNend
 \attention \n
 \param[in] enFlags.CNcomment:ģ��ţ��ο�HI_UNF_PQ_DEMO_E CNend
 \param[in] u32OnOff.CNcomment:����ģʽ���� CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
 
extern HI_S32 HI_UNF_PQ_SetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 u32OnOff);

/**
 \brief get brightness histgram information. CNcomment:��ȡ����ֱ��ͼ��ϢCNend
 \attention \n
 \param[out] pstDCIHistgram.CNcomment:ֱ��ͼ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetHistgram( HI_UNF_PQ_DCI_HISTGRAM_S *pstDCIHistgram);

/**
 \brief get average brightness by histgram information. CNcomment:��ȡƽ������CNend
 \attention \n
 \param[out] pu32AvrBrigheness().CNcomment:ƽ������CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
 
extern HI_S32 HI_UNF_PQ_GetAvrBrightness(HI_U32 *pu32AvrBrigheness);

/**
 \brief get White balance information. CNcomment:��ȡ�Զ���ƽ������Ϣ�CNend
 \attention \n
 \param[out] pstWhiteBalanceParam.CNcomment:�Զ���ƽ������Ϣ�CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetWhiteBalanceParam(HI_UNF_PQ_WHITE_BALANCE_PARAM_S *pstWhiteBalanceParam);

 
  /**
   \brief get average brightness by histgram information. CNcomment:��ȡ�SSharpen ������CNend
   \attention \n
   \param[out] pstSharpenGain.CNcomment:Sharpen   ����CNend
   \retval HI_SUCCESS	  success.	CNcomment:�ɹ� CNend
   \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
   \see \n
   CNcomment:�� CNend
   */
 extern HI_S32 HI_UNF_PQ_GetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstSharpenGain);

 /**
 \brief get average brightness by histgram information. CNcomment:���áSSharpen  ��Ƶ ������CNend
 \attention \n
 \param[in] pstSharpenGain.CNcomment:Sharpen   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstSharpenGain);

 /**
 \brief get average brightness by histgram information. CNcomment:��ȡ��ɫ ������CNend
 \attention \n
 \param[out] pstAcmGain.CNcomment:ACM   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pstAcmGain);

 /**
 \brief get average brightness by histgram information. CNcomment:������ɫ ������CNend
 \attention \n
 \param[in] pstAcmGain.CNcomment:ACM   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pstAcmGain);

 /**
 \brief get average brightness by histgram information. CNcomment:��ȡ�Աȶ� ������CNend
 \attention \n
 \param[out] pstDciGain.CNcomment:dci  ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetDciGain(HI_UNF_PQ_DCI_GAIN_S *pstDciGain);

/**
 \brief get average brightness by histgram information. CNcomment:���öԱȶ� ������CNend
 \attention \n
 \param[in] pstDciGain.CNcomment:DCI   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetDciGain(HI_UNF_PQ_DCI_GAIN_S *pstDciGain);
/**
 \brief get average brightness by histgram information. CNcomment:����HDR  FIX ģʽCNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  FIX ģʽCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32  HI_UNF_PQ_SetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
/**
 \brief get average brightness by histgram information. CNcomment:��ȡHDR  FIX ģʽCNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  FIX ģʽCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32  HI_UNF_PQ_GetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
/**
 \brief get average brightness by histgram information. CNcomment: ��ȡHDR  Դ��ϢCNend
 \attention \n
 \param[in] pstDciGain.CNcomment:HDR  Դ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32  HI_UNF_PQ_GetSrcHdrInfo(HI_UNF_PQ_HDR_INFO_S  *pstHdrInfo);
/**
 \brief Set Saturation gain for section color. CNcomment: ���÷ֶ���ɫ���Ͷ����� ��ϢCNend
 \attention \n
 \param[in] pstSatGain.CNcomment:��ɫ���Ͷ�������ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern  HI_S32 HI_UNF_PQ_SetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);
/**
 \brief Get Saturation gain for section color. CNcomment: ��ȡ�ֶ���ɫ���Ͷ� ��ϢCNend
 \attention \n
 \param[in] pstSatGain.CNcomment:��ɫ���Ͷ�������ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern  HI_S32 HI_UNF_PQ_GetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

/**
 \brief Set HUE gain for section color. CNcomment: ���÷ֶ���ɫɫ����ϢCNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  Դ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

/**
 \brief Get HUE gain for section color. CNcomment: ��ȡ�ֶ���ɫɫ����ϢCNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM Դ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */

extern HI_S32 HI_UNF_PQ_GetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

/**
 \brief Set Y gain for section color. CNcomment: ���÷ֶ���ɫ������ϢCNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  Դ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

/**
 \brief Get Bright gain for section color. CNcomment: ���÷ֶ���ɫ������ϢCNend
 \attention \n
 \param[in] pstHueGain.CNcomment:ACM  Դ��ϢCNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
HI_S32 HI_UNF_PQ_GetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

/**
 \brief Set gamma table data. CNcomment: ��ȡGAMMA ������CNend
 \attention \n
 \param[in] pstGammaTable.CNcomment:gamma table ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_SetGammaTable(HI_UNF_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief Get gamma table data. CNcomment: ��ȡGAMMA ������CNend
 \attention \n
 \param[in] pstGammaTable.CNcomment:gamma table ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetGammaTable(HI_UNF_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief set cti gain. CNcomment:���� cti ������CNend
 \attention \n
 \param[in] pstCtiGain .CNcomment:Cti   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment: 0~128
 */
extern HI_S32 HI_UNF_PQ_SetCtiGain(HI_U32 u32CtiGain);

/**
 \brief get cti gain. CNcomment:��ȡ cti ������CNend
 \attention \n
 \param[out] pstCtiGain.CNcomment:Cti   ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetCtiGain(HI_U32 *pstCtiGain);

/**
 \brief Set NRStr . CNcomment: ���ý�������CNend
 \attention \n
 \param[in] pstNRStr .CNcomment:NR���� CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment: 0~64
 */
extern HI_S32 HI_UNF_PQ_SetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

/**
 \brief get NRStr.    CNcomment: ��ȡ��������CNend               
 \attention \n
 \param[out] pstNRStr.CNcomment:NR  ����CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

/** 
 \brief get RGBMax�� CNcomment: ��ȡRGB���ƽ��ֵCNend 
 \attention \n
 \param[out] pu32AvgRgbMax.CNcomment:��ȡRGB���ƽ��ֵ��Ч��ΧΪ0~255CNend
 \retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
 \retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
 \see \n
 CNcomment:�� CNend
 */
extern HI_S32 HI_UNF_PQ_GetAvgRGBMax(HI_U32 *pu32AvgRgbMax);
 
/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_UNF_PQ_H__ */


