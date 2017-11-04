/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : hi_mpi_pq.h
  Version       : Initial Draft
  Author        : y00220178
  Created       : 2013/11/13
  Description   :

******************************************************************************/

#ifndef __HI_MPI_PQ_H__
#define __HI_MPI_PQ_H__

#include "hi_type.h"
#include "hi_unf_pq.h"
#include "hi_drv_pq.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/*ACM table�ṹ*/
typedef struct hiMPI_COLOR_PARAM_S
{
    HI_U16 u16Stretch;
    HI_U16 u16ClipRange;
    HI_U16 u16HueGain;         /*��ʾ��Hue�����棬��Χ0-1023*/
    HI_U16 u16SatGain;         /*��ʾ��Saturation������*/
    HI_U16 u16LumaGain;        /*��ʾ��Luma������*/
    HI_U16 u16CbCrThre;        /*CbCr������ֵ������������ֵ�Ͳ���Color����*/
    HI_S16 as16Luma[9][13][29]; /*Luma���ұ�*/
    HI_S16 as16Hue[9][13][29];  /*Hue���ұ�*/
    HI_S16 as16Sat[9][13][29];  /*Saturation���ұ�*/
    #if 1
    HI_S16 as16YHSbyH[3][29];           /*YbyH[29],    HbyH[]29,    SbyH[29]     delta  curve*/
    HI_S16 as16YHSbyHSgain[3][29][13];  /*YbyH[29][13],HbyH[29][13],SbyH[29][13] S gain curve*/
    HI_S16 as16YHSbyHYgain[3][29][9];   /*YbyH[29][9], HbyH[29][9], SbyH[29][9]  Y gain curve*/
    #endif
} MPI_COLOR_PARAM_S;

/****  �Զ���ƽ��������  ****/
typedef enum hiMPI_WHITE_BALANCE_TMP_E
{
 
   HI_MPI_PQ_WHITE_BALANCE_COOL,
   HI_MPI_PQ_WHITE_BALANCE_STANDARD,
   HI_MPI_PQ_WHITE_BALANCE_WARM,

   HI_MPI_PQ_WHITE_BALANCE_BUTT 
}MPI_WHITE_BALANCE_TMP_E;

typedef struct hiMPI_WHITE_BALANCE_SINGLE_PARAM_S
{
   HI_U32 u32RGain;
   HI_U32 u32GGain;
   HI_U32 u32BGain;
   HI_U32 u32ROffset;
   HI_U32 u32GOffset;
   HI_U32 u32BOffset;  
}MPI_WHITE_BALANCE_SINGLE_PARAM_S;


typedef struct hiMPI_WHITE_BALANCE_PARAM_S
{ 
   MPI_WHITE_BALANCE_SINGLE_PARAM_S astTmpParam[HI_MPI_PQ_WHITE_BALANCE_BUTT];
}MPI_WHITE_BALANCE_PARAM_S;



/**
 \PQ��ʼ��
 \attention \n

 \param[in] pszPath:PQ�����ļ�·��
 \param[out] 

 \retval ::HI_SUCCESS

 */
HI_S32 HI_MPI_PQ_Init(HI_CHAR* pszPath);

/**
 \PQȥ��ʼ��
 \attention \n

 \param[in] 
 \param[out] 

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_DeInit(HI_VOID);

/**
 \brief ��ȡ����
 \attention \n
��

 \param[in] pu32Brightness������ֵ,��Ч��Χ: 0~255;
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetBrightness(HI_U32 *pu32Brightness);

/**
 \brief ��������
 \attention \n
��

 \param[in] u32Brightness������ֵ,��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetBrightness(HI_U32 u32Brightness);

/**
 \brief ��ȡ�Աȶ�
 \attention \n
��

 \param[in] 
 \param[out] pu32Contrast���Աȶ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetContrast(HI_U32 *pu32Contrast);

/**
 \brief ���öԱȶ�
 \attention \n
��

 \param[in] u32Contrast���Աȶ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetContrast(HI_U32 u32Contrast);

/**
 \brief ��ȡɫ��
 \attention \n
��

 \param[in] 
 \param[out] pu32Hue��ɫ��, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetHue(HI_U32 *pu32Hue);

/**
 \brief ����ɫ��
 \attention \n
��

 \param[in] u32Hue��ɫ��, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetHue(HI_U32 u32Hue);

/**
 \brief ��ȡ���Ͷ�
 \attention \n
��

 \param[out] pu32Saturation�����Ͷ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetSaturation(HI_U32 *pu32Saturation);

/**
 \brief ���ñ��Ͷ�
 \attention \n
��

 \param[in] u32Saturation�����Ͷ�,��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSaturation(HI_U32 u32Saturation);

/**
 \brief ��ȡ����ǿ��
 \attention \n
��

 \param[out] pu32NRLevel: ����ȼ�, ��Ч��Χ: 0~255


 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetNR(HI_U32 *pu32NRLevel);

/**
 \brief ���ý���ǿ��
 \attention \n
��

 \param[in] u32NRLevel: ����ȼ�, ��Ч��Χ: 0~255

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetNR(HI_U32 u32NRLevel);

/**
 \brief ��ȡ�Զ����뿪��״̬
 \attention \n
��

 \param[out] pu32OnOff


 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetNRAutoMode(HI_U32 *pu32OnOff);

/**
 \brief ���ý����Զ�ģʽ����
 \attention \n
��

 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetNRAutoMode(HI_U32 u32OnOff);

/**
 \brief ��ȡSR��ʾ����
 \attention \n
��

 \param[out] *penType


 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetSRMode(HI_PQ_SR_DEMO_E *penType);

/**
 \brief ����SR��ʾ����
 \attention \n
��

 \param[in] enType

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetSRMode(HI_PQ_SR_DEMO_E enType);

/**
 \brief ��ȡ������
 \attention \n
��

 \param[out] pu32Sharpness��������, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetSharpness(HI_U32 *pu32Sharpness);

/**
 \brief ����������
 \attention \n
��

 \param[in] u32Sharpness��������, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSharpness(HI_U32 u32Sharpness);

/**
 \brief ��ȡ�齵��De-blockingǿ��
 \attention \n
��

 \param[out] pu32DBlevel������ȼ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDeBlocking(HI_U32 *pu32DBlevel);

/**
 \brief ���ÿ齵��De-blockingǿ��
 \attention \n
��

 \param[in] u32DBlevel:����ȼ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDeBlocking(HI_U32 u32DBlevel);

/**
 \brief ��ȡȥ���ó�����de-ringingǿ��
 \attention \n
��

 \param[out] pu32DRlevel:����ȼ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDeRinging(HI_U32 *pu32DRlevel);

/**
 \brief ����ȥ���ó�����de-ringingǿ��
 \attention \n
��

 \param[in] u32DRlevel:����ȼ�, ��Ч��Χ: 0~255;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDeRinging(HI_U32 u32DRlevel);

/**
 \brief ����ɫ�²���
 \attention \n
��

 \param[in] pstColorTemp:ɫ�²���
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief ��ȡɫ�²���
 \attention \n
��

 \param[in] pstColorTemp��ɫ�²���
 \param[out] 

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetColorTemp( HI_UNF_PQ_COLOR_TEMP_S *pstColorTemp);

/**
 \brief ��ȡ��ɫ��������
 \attention \n
��

 \param[out] pu32ColorType

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetColorGain(HI_UNF_PQ_COLOR_TYPE_E *penColorType);

/**
 \brief ������ɫ��������
 \attention \n
��

 \param[in] enColorType

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetColorGain(HI_UNF_PQ_COLOR_TYPE_E enColorType);

/**
 \brief ��ȡ��ɫ��ǿ
 \attention \n
  ��

 \param[out] pu32FleshToneLevel

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetFleshTone(HI_U32 *pu32FleshToneLevel);

/**
 \brief ���÷�ɫ��ǿ
 \attention \n
  ��

 \param[in] enFleshToneLevel���ο�HI_COLOR_GAIN_E

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetFleshTone( HI_UNF_PQ_FLESHTONE_E enFleshToneLevel);

/**
 \brief ��ȡ����ɫ����
 \attention \n
  ��

 \param[out] pu32SixBaseColor

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_GetSixBaseColor(HI_U32 *pu32SixBaseColor);

/**
 \brief ��������ɫ����
 \attention \n
  ��

 \param[in] enSixBaseColor

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetSixBaseColor( HI_UNF_PQ_SIX_BASE_COLOR_E enSixBaseColor);

/**
 \brief ��ȡ��̬����ǿ��
 \attention \n
��

 \param[in] none
 \param[out] pu32BackLightLevel

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetBackLight(HI_U32 *pu32BackLightLevel);

/**
 \brief ���þ�̬����ǿ��
 \attention \n
��

 \param[in] u32BackLightLevel

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetBackLight(HI_U32 u32BackLightLevel);

/**
 \brief ��ȡ3D Sharpenģʽ
 \attention \n
��

 \param[out] *pu32OnOff

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_Get3DSharpen(HI_U32 *pu32OnOff);

/**
 \brief ����3D Sharpenģʽ
 \attention \n
��

 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_Set3DSharpen(HI_U32 u32OnOff);

/**
 \brief Gamma Table�п��ܴ��ڶ���Gamma����,�û��ɻ�ȡGamma��������; (��չ�ӿ�)
 \attention \n
��

 \param[out] *s32Num: Gamma���ߵ�����;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetGammaNum(HI_S32 *ps32Num);

/**
 \brief ����Gamma
 \attention \n
��

 \param[in] s32GammaIndex: Gamma���ߵ�����ֵ;

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetGamma(HI_S32 s32GammaIndex);

/**
 \brief ����PQģ�鿪��
 \attention \n
  ��

 \param[in] enFlags
 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 HI_MPI_PQ_SetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 u32OnOff);

/**
 \brief ��ȡPQģ�鿪��
 \attention \n
  ��

 \param[in] enFlags
 \param[in] pu32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetPQModule( HI_UNF_PQ_MODULE_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief ��ȡ����ģʽ����
 \attention \n
  ��

 \param[in] enFlags
 \param[in] pu32OnOff

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 *pu32OnOff);

/**
 \brief ��������ģʽ����
 \attention \n
��

 \param[in] enFlags
 \param[in] u32OnOff

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 HI_MPI_PQ_SetDemo( HI_UNF_PQ_DEMO_E enFlags, HI_U32 u32OnOff);

/**
 \brief ����PQ�Ĵ���
 \attention \n
��

 \param[in] u32RegAddr
 \param[in] u32Data

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_WritePQRegister(HI_U32 u32RegAddr,HI_U32 u32Data);

/**
 \brief ��ȡPQ�Ĵ���
 \attention \n
��

 \param[in] u32RegAddr
 \param[in] *pu32Value

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_ReadPQRegister(HI_U32 u32RegAddr, HI_U32 *pu32Value);

/**
 \brief ��ȡGAMMA����
 \attention \n
  ��

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetGammaTable( HI_PQ_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief ����GAMMA����
 \attention \n
  ��

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetGammaTable( HI_PQ_GAMMA_TABLE_S *pstGammaTable);

/**
 \brief ��ȡACM����
 \attention \n
  ��

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetAcmTable( MPI_COLOR_PARAM_S *pstColorTable);

/**
 \brief ����ACM����
 \attention \n
  ��

 \param[in] *pstGammaTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetAcmTable( MPI_COLOR_PARAM_S *pstColorTable);

/**
 \brief ��ȡDCI����
 \attention \n
  ��

 \param[in] *pstDCITable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDciTable( HI_PQ_DCI_WGT_S *pstDCITable);

/**
 \brief ����DCI����
 \attention \n
  ��

 \param[in] *pstDCITable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDciTable( HI_PQ_DCI_WGT_S *pstDCITable);

/**
 \brief ��ȡDCIֱ��ͼ
 \attention \n
  ��

 \param[in] *pstDCIHistgram

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetHistgram( HI_PQ_DCI_HISTGRAM_S *pstDCIHistgram);

/**
 \brief ��ȡDCI���յ�������
 \attention \n
  ��

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDciFinalLut( HI_PQ_DCI_FINAL_LUT_S *pstData);

/**
 \brief ��ȡDIM����
 \attention \n
  ��

 \param[in] *pstDIMTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_GetDimTable( HI_PQ_DIM_LUT_S *pstDIMTable);

/**
 \brief ����DIM����
 \attention \n
  ��

 \param[in] *pstDIMTable

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetDimTable( HI_PQ_DIM_LUT_S *pstDIMTable);

/**
 \brief ��ȡTNR������PixMean-to-Ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR������PixMean-to-Ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);


/**
 \brief ��ȡTNR��ɫ��PixMean-to-Ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR��ɫ��PixMean-to-Ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromPixMean2Ratio( HI_PQ_TNR_S *pstTnrData);


/**
 \brief ��ȡTNR������MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR������MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief ��ȡTNR��ɫ��MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR��ɫ��MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief ��ȡTNR������FINAL MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRLumaFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR������FINAL MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRLumaFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);


/**
 \brief ��ȡTNR��ɫ��FINAL MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetTNRChromFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ����TNR��ɫ��FINAL MotionMapping����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetTNRChromFinalMotionMapping( HI_PQ_TNR_S *pstTnrData);

/**
 \brief ��ȡSNR��pixmean-ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetSNRPixmean2Ratio( HI_PQ_SNR_PIXMEAN_2_RATIO_S *pstSnrData);

/**
 \brief ����SNR��pixmean-ratio����
 \attention \n
  ��

 \param[in] *pstTnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSNRPixmean2Ratio( HI_PQ_SNR_PIXMEAN_2_RATIO_S *pstSnrData);

/**
 \brief ��ȡSNR��pixdiff-edgestr����
 \attention \n
  ��

 \param[in] *pstSnrData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetSNRPixdiff2Edgestr( HI_PQ_SNR_PIXDIFF_2_EDGESTR_S *pstSnrData);

/**
 \brief ����SNR��pixdiff-edgestr����
 \attention \n
  ��

 \param[in] *pstSnrData

 \retval ::HI_SUCCESS

 */

extern HI_S32 HI_MPI_PQ_SetSNRPixdiff2Edgestr( HI_PQ_SNR_PIXDIFF_2_EDGESTR_S *pstSnrData);

/**
 \brief ��ȡCSC��ϵ��
 \attention \n
  ��

 \param[in] *pstCscData

 \retval ::HI_SUCCESS

 */
extern HI_S32 HI_MPI_PQ_GetCSCCoef( HI_PQ_CSC_S *pstCscData);

/**
 \brief ����CSC��ϵ��
 \attention \n
  ��

 \param[in] *pstCscData

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetCSCCoef( HI_PQ_CSC_S *pstCscData);

/**
 \brief ��ȡPFMD�Ŀɵ�����
 \attention \n
  ��

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */
HI_S32 HI_MPI_PQ_GetPfmdParam( HI_PQ_PFMD_DBG_S *pstData);

/**
 \brief ����PFMD�Ŀɵ�����
 \attention \n
  ��

 \param[in] *pstData

 \retval ::HI_SUCCESS

 */

HI_S32 HI_MPI_PQ_SetPfmdParam( HI_PQ_PFMD_DBG_S *pstData);

//****Sharpeness AdpGain �����д�����ӿ�*/
HI_S32 HI_MPI_PQ_SetSharpAdpGainParam(HI_PQ_SHARPEN_TABLE_S *pstData);

HI_S32 HI_MPI_PQ_GetSharpAdpGainParam(HI_PQ_SHARPEN_TABLE_S *pstData);

HI_S32 HI_MPI_PQ_SetDciWeightParam(HI_PQ_DCI_WEIGHT_S *pstData);
HI_S32 HI_MPI_PQ_GetDciWeightParam(HI_PQ_DCI_WEIGHT_S *pstData);

HI_S32 HI_MPI_PQ_SetWhiteBalanceParam(MPI_WHITE_BALANCE_PARAM_S *pstData);
HI_S32 HI_MPI_PQ_GetWhiteBalanceParam(MPI_WHITE_BALANCE_PARAM_S *pstData);

HI_S32 HI_MPI_PQ_GetSharpenYvalueParam(HI_PQ_SHARPEN_YRATIO_S *pstData);
HI_S32 HI_MPI_PQ_SetSharpenYvalueParam(HI_PQ_SHARPEN_YRATIO_S *pstData);

HI_S32 HI_MPI_PQ_GetTnrFmotionMapping(HI_PQ_TNR_FMOTION_MAPPING_S *pstData);
HI_S32 HI_MPI_PQ_SetTnrFmotionMapping(HI_PQ_TNR_FMOTION_MAPPING_S *pstData);

HI_S32 HI_MPI_PQ_Get2DDimming(HI_PQ_DIM_LUT_S *pstData);
HI_S32 HI_MPI_PQ_Set2DDimming(HI_PQ_DIM_LUT_S *pstData);

//��ȡ�Զ��ο��޸�TNR FMotion  �ӿ�
HI_S32 HI_MPI_PQ_GetAutoFMotion(HI_U32 *pstData);
HI_S32 HI_MPI_PQ_SetAutoFMotion(HI_U32 *pstData);

HI_S32 HI_MPI_PQ_GetAutoNR(HI_U32 *pu32Data);
HI_S32 HI_MPI_PQ_SetAutoNR(HI_U32 *pu32Data);

//av500����Sharpen   �����������
HI_S32 HI_MPI_Get4KSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);
HI_S32 HI_MPI_Set4KSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);

HI_S32 HI_MPI_GetFHDSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);
HI_S32 HI_MPI_SetFHDSharpenLimitCurve(HI_PQ_SHARPEN_LIMITLUT_GROUP_S *pu32Data);

//���ö���Gamma���ߵ�Index
HI_S32 HI_MPI_PQ_SetGammaIndex(HI_U32 pu32Data);
HI_S32 HI_MPI_PQ_GetGammaIndex(HI_U32 *pu32Data);

//���ø߼�����������
HI_S32 HI_MPI_PQ_SetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_GetSharpenGain(HI_UNF_PQ_SHARP_GAIN_S *pstData);


//���ö���acm���ߵ�Gain
HI_S32 HI_MPI_PQ_GetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_SetAcmGain(HI_UNF_PQ_ACM_GAIN_S *pu32Data);

//���ö���dci���ߵ�Gain
HI_S32 HI_MPI_PQ_GetDciGain(HI_UNF_PQ_DCI_GAIN_S *pu32Data);
HI_S32 HI_MPI_PQ_SetDciGain(HI_UNF_PQ_DCI_GAIN_S *pu32Data);

//ǿ�����ó���
HI_S32 HI_MPI_PQ_GetFieldOrderMode(HI_U32 *u32FieldOrderMode);
HI_S32 HI_MPI_PQ_SetFieldOrderMode(HI_U32 u32FieldOrderMode);

//????HDR ???
HI_S32 HI_MPI_PQ_SetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);
HI_S32 HI_MPI_PQ_GetHdrFixMode(HI_UNF_PQ_HDR_FIXMODE_S  *pstHdrFixMode);

//?????HDR ??
HI_S32 HI_MPI_PQ_GetHdrInfo(HI_UNF_PQ_HDR_INFO_S  *pstHdrInfo);

//���÷ֶ�ɫ���µı��Ͷ�
HI_S32 HI_MPI_PQ_SetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

//��ȡ�ֶ�ɫ���µı��Ͷ�
HI_S32 HI_MPI_PQ_GetSatGain(HI_UNF_PQ_SAT_GAIN_S *pstSatGain);

//���÷ֶ�ɫ���µ�ɫ������
HI_S32 HI_MPI_PQ_SetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

//��ȡ�ֶ�ɫ���µ�ɫ������
HI_S32 HI_MPI_PQ_GetHueGain(HI_UNF_PQ_HUE_GAIN_S *pstHueGain);

//���÷ֶ�ɫ���µ�����
HI_S32 HI_MPI_PQ_SetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

//��ȡ�ֶ�ɫ���µ�����
HI_S32 HI_MPI_PQ_GetBriGain(HI_UNF_PQ_BRI_GAIN_S *pstBriGain);

//����CTI Gain
HI_S32 HI_MPI_PQ_SetCtiGain(HI_U32 u32CtiGain);

//��ȡCTI Gain
HI_S32 HI_MPI_PQ_GetCtiGain(HI_U32 *pu32CtiGain);

//����NR STR
HI_S32 HI_MPI_PQ_SetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

//��ȡNR STR
HI_S32 HI_MPI_PQ_GetNRStr(HI_UNF_PQ_NRSTR_GAIN_S *pstNRStr);

//��ȡ����ͳ��ֵ
HI_S32 HI_MPI_PQ_GetAvgRGBMax(HI_U32 *pu32AvgRgbMax);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __HI_MPI_PQ_H__ */



