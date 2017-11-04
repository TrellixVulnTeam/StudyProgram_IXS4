/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : drv_pq_ext.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/09
  Description   :

******************************************************************************/

#ifndef __DRV_PQ_EXT_H__
#define __DRV_PQ_EXT_H__

#include "hi_type.h"
#include "hi_drv_video.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define ZME_COEF_SIZE_HOR       384/*384Ϊ����ϵ��ռ���ڴ�*/
#define ZME_COEF_SIZE_VER       288/*288Ϊ����ϵ��ռ���ڴ�*/


/* VPSS��Ƶ��Ϣ */
typedef struct hiHI_VPSS_PQ_INFO_S
{ 
    HI_DRV_SOURCE_E  			enInputSrc;         /* �ź�Դ���� */
    HI_U32                      u32Width;           /* ͼ���� */
    HI_U32                      u32Height;          /* ͼ��߶� */  
    HI_U32                      u32FrameRate;       /* ����֡�� */
    HI_BOOL                     bInterlace;         /* �Ƿ�����ź� */
    HI_DRV_COLOR_SYS_E     		enColorSys;         /* ATV�źŵ�Color System */
	HI_BOOL      				bMcEnable;   		/*512M�汾����MCDI  �Ĳ�����������*/ 
} HI_VPSS_PQ_INFO_S;

/*VDP��Ƶ��Ϣ */
typedef struct hiHI_VDP_PQ_INFO_S
{ 
    HI_DRV_SOURCE_E  enInputSrc;         /* �ź�Դ���� */
    HI_U32                      u32Width;           /* ͼ���� */
    HI_U32                      u32Height;          /* ͼ��߶� */  
    HI_U32                      u32FrameRate;       /* ����֡�� */
    HI_BOOL                     bInterlace;         /* �Ƿ�����ź� */
    HI_BOOL                     b3dType;            /*�Ƿ�ԭ��3D����*/   
    HI_BOOL                     bPcTiming;          /* �Ƿ�ΪPC Timing */
    HI_DRV_COLOR_SYS_E     enColorSys;         /* ATV�źŵ�Color System */
} HI_VDP_PQ_INFO_S;

/*4K��Ƶ��Ϣ */
typedef struct hiHI_VDP_4K_INFO_S
{ 
    HI_U32                      u32Width;           /* ͼ���� */
    HI_U32                      u32Height;          /* ͼ��  �߶� */
	HI_U32						u32SrcWidth;		/* ͼ�� SRC��� */
	HI_U32						u32SrcHeight;		/* ͼ��SRC�߶� */
    HI_BOOL                     b3dType;            /*�Ƿ�3D���ţ�����2Dת3D��ԭ��3D*/   
    HI_BOOL                     bPcTiming;          /* �Ƿ�ΪPC Timing */
	HI_DRV_PIX_FORMAT_E 		eSrcFmt;			/*  ���ظ�ʽ��Ϣ */
	HI_DRV_COLOR_SPACE_E    	enColorSpace;		/*  ɫ�ʿռ���Ϣ */
 	HI_DRV_GAMMA_TYPE_E     	enGammaType;		/*  Gamma ����������Ϣ*/
} HI_VDP_4K_INFO_S;

typedef struct hiVDP_DHD_INFO_S
{
    HI_BOOL                     bValid;
	HI_DRV_COLOR_SPACE_E        enColorSpace;
	HI_DRV_GAMMA_TYPE_E			enGammaType;
    HI_DRV_VIDEO_HDR10_METADATA_STREAM_S stMetadata;
}HI_VDP_DHD_INFO_S;

/* PQģ�鿪����Ϣ */
typedef struct hiPQ_VPSS_MODULE_S
{ 
    HI_BOOL                     bFMD;         /* FMD����*/
    HI_BOOL                     bTNR;            /*NR����*/   
    HI_BOOL                     bCCCL;          /*CCCL����*/
} HI_PQ_VPSS_MODULE_S;

/*ɫ�ʿռ�ת������*/
typedef enum hiPQ_CSC_MODE_
{
    HI_PQ_CSC_YUV2RGB_601 = 0,       //YCbCr_601 LIMIT-> RGB FULL
    HI_PQ_CSC_YUV2RGB_709,              //YCbCr_709 LIMIT-> RGB FULL
    HI_PQ_CSC_RGB2YUV_601,              // RGB FULL->YCbCr_601 LIMIT  
    HI_PQ_CSC_RGB2YUV_709,              //RGB FULL->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2YUV_709_601,      //YCbCr_709 LIMIT->YCbCr_601 LIMIT
    HI_PQ_CSC_YUV2YUV_601_709,      //YCbCr_601 LIMIT->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2YUV,                      //YCbCr LIMIT->YCbCr LIMIT
    HI_PQ_CSC_YUV2RGB_601_FULL,       //YCbCr_601 FULL-> RGB FULL
    HI_PQ_CSC_YUV2RGB_709_FULL,        //YCbCr_709 FULL-> RGB FULL
    HI_PQ_CSC_RGB2YUV_601_FULL,        // RGB FULL->YCbCr_601 FULL  
    HI_PQ_CSC_RGB2YUV_709_FULL,        //RGB FULL->YCbCr_709 FULL
    HI_PQ_CSC_YUV2YUV_709_601_FULL,      //YCbCr_709 FULL->YCbCr_601 FULL
    HI_PQ_CSC_YUV2YUV_601_709_FULL,      //YCbCr_601 FULL->YCbCr_709 FULL
    HI_PQ_CSC_YUV2YUV_FULL,                      //YCbCr FULL->YCbCr FULL
    HI_PQ_CSC_YUV2YUV_LIMIT2FULL,           //YCbCr  LIMIT->YCbCr  FULL
    HI_PQ_CSC_YUV2YUV_601_709_LIMIT2FULL,           //YCbCr 601 LIMIT->YCbCr 709 FULL
    HI_PQ_CSC_YUV2YUV_709_601_LIMIT2FULL,           //YCbCr 709 LIMIT->YCbCr 601 FULL
    HI_PQ_CSC_YUV2YUV_FULL2LIMIT,                            //YCbCr  FULL->YCbCr  LIMIT
    HI_PQ_CSC_YUV2YUV_601_709_FULL2LIMIT,           //YCbCr 601 FULL->YCbCr 709 LIMIT
    HI_PQ_CSC_YUV2YUV_709_601_FULL2LIMIT,           //YCbCr 709 FULL->YCbCr 601 LIMIT
    HI_PQ_CSC_YUV2RGBL_601,      //YCbCr_601 LIMIT-> RGB LIMIT
    HI_PQ_CSC_YUV2RGBL_709,        //YCbCr_709 LIMIT-> RGB LIMIT
    HI_PQ_CSC_RGBL2YUV_601,        // RGB LIMIT->YCbCr_601 LIMIT  
    HI_PQ_CSC_RGBL2YUV_709,        //RGB LIMIT->YCbCr_709 LIMIT
    HI_PQ_CSC_YUV2RGBL_601_FULL,        //YCbCr_601 FULL-> RGB LIMIT
    HI_PQ_CSC_YUV2RGBL_709_FULL,        //YCbCr_709 FULL-> RGB LIMIT
    HI_PQ_CSC_RGBL2YUV_601_FULL,        // RGB LIMIT->YCbCr_601 FULL  
    HI_PQ_CSC_RGBL2YUV_709_FULL,        //RGB LIMIT->YCbCr_709 FULL
    HI_PQ_CSC_RGB2RGBL,                                            //RGB FULL->RGB LIMIT
    HI_PQ_CSC_RGBL2RGB,                                            //RGB LIMIT->RGB FULL
    HI_PQ_CSC_RGBL2RGBL,                                            //RGB LIMIT->RGB LIMIT
    HI_PQ_CSC_RGB2RGB,                                              //RGB FULL->RGB FULL
    HI_PQ_CSC_YUV2RGB_2020,					//YUV 2020 FULL->RGB  2020 FULL
    HI_PQ_CSC_RGB20202YUV709_FULL2LIMIT,
    HI_PQ_CSC_YUV7092RGB2020_LIMIT2FULL,
    HI_PQ_CSC_YUV7092RGB2020_FULL2FULL,
    HI_PQ_CSC_RGB7092YUV2020_FULL2LIMIT,
// Ϊ����SR ��ӵ�ģʽ
	HI_PQ_CSC_RGB7092YUV2020_FULL,        //BT709RGBFULL    ->  BT2020YUVFULL
    HI_PQ_CSC_RGB2YUV2020_FULL_LIMIT,     //BT2020RGBFULL   -> BT2020YUVLIMIT
    HI_PQ_CSC_RGB2YUV2020_FULL,           //BT2020RGBFULL   ->  BT2020YUVFULL
    HI_PQ_CSC_YUV2RGB2020_FULL,           //BT2020YUVFULL   ->  BT2020RGBFULL

    HI_PQ_CSC_BUTT
} HI_PQ_CSC_MODE_E;

/*VDP CSC ID*/
typedef enum hiPQ_CSC_ID_E
{
    HI_PQ_VDP_CSC_VP0 = 0,
    HI_PQ_VDP_CSC_VP1,
    HI_PQ_VDP_CSC_V0,
    HI_PQ_VDP_CSC_V1,

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
    HI_PQ_VDP_CSC_V0_PIC,
#endif
    HI_PQ_VDP_CSC_BUTT
} HI_PQ_CSC_ID_E;

/* VDP CSC ����*/
typedef struct  hiPQ_VDP_CSC_S
{
    HI_BOOL  bCSCEn;
    HI_PQ_CSC_MODE_E  enCSC;
} HI_PQ_VDP_CSC_S;


/*����YUV���ݽṹ��444 422 420*/
typedef enum hiPQ_ZME_FORMAT_E
{
    ALG_PIX_FORMAT_SP420 = 0,
    ALG_PIX_FORMAT_SP422,
    ALG_PIX_FORMAT_SP444,
    
    ALG_PIX_FORMAT_BUTT,
}ZME_FORMAT_E;

typedef enum hiPQ_SCALAR_LEVEL_E
{
    HI_PQ_SCALAR_LEVEL_0 = 0,//ģ��
    HI_PQ_SCALAR_LEVEL_1,
    HI_PQ_SCALAR_LEVEL_2,
    HI_PQ_SCALAR_LEVEL_3,
    HI_PQ_SCALAR_LEVEL_4,
    HI_PQ_SCALAR_LEVEL_5,//����
   HI_PQ_SCALAR_LEVEL_BUTT,
}HI_PQ_SCALAR_LEVEL_E;
/*  SCALER ��Ϣ */
typedef struct  hiPQ_SCALER_S
{
    HI_BOOL bHorizontal;
	HI_BOOL bYUV; 
	HI_BOOL b3Dtype;
    HI_U32 u32YRatio;
    HI_U32 u32CRatio;
    ZME_FORMAT_E enInFmt;
    ZME_FORMAT_E enOutFmt;
} HI_PQ_SCALER_S;

/*DCIֱ��ͼ�ṹ*/
typedef struct hiPQ_HISTGRAM_S
{
    HI_S32 s32HistGram[32];
}HI_PQ_HISTGRAM_S;

/*DCI����Ȩ������*/
typedef struct hiPQ_DCI_ADJ_LUT_S
{
    HI_S32 s32AdjLUT[33];
}HI_PQ_DCI_ADJ_LUT_S;

/*CSC ����ϵ���ṹ*/
typedef struct  hiPQ_CSC_COEF_S
{
    HI_S32 csc_coef00;
    HI_S32 csc_coef01;
    HI_S32 csc_coef02;

    HI_S32 csc_coef10;
    HI_S32 csc_coef11;
    HI_S32 csc_coef12;

    HI_S32 csc_coef20;
    HI_S32 csc_coef21;
    HI_S32 csc_coef22;
} HI_PQ_CSC_COEF_S;

typedef struct  hiPQ_CSC_DCCOEF_S
{
    HI_S32 csc_in_dc0;
    HI_S32 csc_in_dc1;
    HI_S32 csc_in_dc2;

    HI_S32 csc_out_dc0;
    HI_S32 csc_out_dc1;
    HI_S32 csc_out_dc2;
} HI_PQ_CSC_DCCOEF_S;

/*DCIͳ�ƴ���*/
typedef struct  hiPQ_DCI_WIN_S
{
    HI_U16      u16HStar;
    HI_U16      u16HEnd;
    HI_U16      u16VStar;
    HI_U16      u16VEnd;
} HI_PQ_DCI_WIN_S;

/*DEIֱ��ͼ��Ϣ*/
typedef struct hiPQ_MOTION_HISTGRAM_S
{
    //HI_U32 au32MotionHist[32];
    HI_S32 s32WidthY;
    HI_S32 s32HeightY;
    HI_U32 u32SmallMotionNum; //output of logic,32bit unsigned
    HI_U32 u32SmallMotionSum; //output of logic,32bit unsigned
    HI_U32 u32LargeMotionNum; //output of logic,32bit unsigned
    HI_U32 u32LargeMotionSum; //output of logic,32bit unsigned
    HI_U32 u32MiddlMotionNum; //output of logic,32bit unsigned
    HI_U32 u32MiddlMotionSum; //output of logic,32bit unsigned
}HI_PQ_MOTION_HISTGRAM_S;

/*DEI ȫ���˶���Ϣ*/
typedef struct hiPQ_MOTION_INFO_S
{
    HI_U32 u32GlobalMotion;
    HI_U32 u32AdjustGain;
}HI_PQ_MOTION_INFO_S;

/*DEI API�����������Ϣ*/
typedef struct hiPQ_MOTION_INPUT_S
{
    HI_U32 u32Width;
    HI_U32 u32Height;
	HI_U32 u32HandleNo;
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
	HI_U32 u32Scd;
#endif
	HI_VOID *pstMotionReg;

#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
    HI_VOID *pRGMV;
    HI_U32 stride;
#endif 
}HI_PQ_MOTION_INPUT_S;


//tnr global motion api ��������ṹ
typedef struct
{
	HI_U32 u32HdlNo;	//ʵ����ID
	HI_U32 u32Width;	//����ͼ����
	HI_U32 u32Height;	//����ͼ��߶�
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
	HI_U32 u32Scd;
#endif
	HI_VOID *pstMotionReg;
}HI_PQ_TNR_MOTION_PARAM_IN_S;

//Tnr global motion result
typedef struct
{
	HI_U32 u32GlobalMotion;
	HI_U32 u32AdjustGain;
}HI_PQ_TNR_MOTION_RESULT_S;

//DBǿ��ֵ,��ӦVPSS_DB_WEIGHT�Ĵ���
typedef struct
{
	HI_U8    u8HWeight;		// 6bits [0,63]
    HI_U8    u8VWeight;		// 6bits [0,63]
}HI_PQ_DB_WEIGHT_S;

//image signal type of interlacing or non-interlacing
typedef enum
{
	HI_PQ_DB_INTERLACE = 0,	//����DEI ,����
	HI_PQ_DB_PROGRESSIVE		//������DEI ,����
}HI_PQ_DB_SIG_TYPE_E;


//DBǿ�� API����������ṹ
typedef struct
{	
    HI_U8				u8SCDStr;		 //����SCD��api����ó���һ��ֵ[0,255]
	HI_U32				u32HdlNo; //ʵ����ID
	HI_PQ_DB_SIG_TYPE_E	eType;		 //����Դ���ͣ����л����У��Ƿ���DEI
	HI_VOID 	*pstReg;	 //global motion �Ĵ�����ַ
	
}HI_PQ_DB_STR_PARAM_IN_S;

/*IFMD���㷨�����������������VPSS->PQ*/
typedef struct hi_PQ_IFMD_CALC_S
{	
    //HI_U32	u32Stt_w_addr;//ͳ����Ϣ��д��ʼ��ַ
    HI_U32  u32HandleNo;
    HI_U32  u32WidthY;
    HI_U32  u32HeightY;
    HI_S32	s32FieldOrder; //���׳��� �������ȵ׳�����
    HI_S32	s32FieldMode; //	���׳���־???
    HI_U32  u32FrameRate;
	HI_VOID *pstIfmdHardOutReg;//��ȡifmd��״̬�Ĵ���
}HI_PQ_IFMD_CALC_S;



typedef struct
{
    HI_S32  die_reset;
    HI_S32  die_stop;
    HI_S32  dir_mch;
    HI_S32  die_out_sel;
    HI_S32  jud_en;
    //HI_S32  ChromaVertFltEn;
    /* added by c00190889  */ 
    HI_S32  s32FieldOrder;/* ���س��� */
	HI_S32  s32SceneChanged;/* �����л���Ϣ */
	HI_S32  s32FilmType;/* ��Ӱģʽ */
	HI_U32  u32KeyValue;/* �ؼ�֡ */
} HI_PQ_IFMD_PLAYBACK_S;


/*PFMD���㷨�����������������VPSS->PQ*/
typedef struct hi_PQ_PFMD_CALC_S
{	
    HI_U32  u32HandleNo;
    HI_U32  u32WidthY;
    HI_U32  u32HeightY;
	HI_S32	s32FieldOrder; //���׳��� �������ȵ׳�����
    HI_S32	s32FieldMode;
    HI_U32  u32FrameRate;
    HI_VOID *pstpfmdHardOutReg;//��ȡpfmd��״̬�Ĵ���
}HI_PQ_PFMD_CALC_S; 

typedef struct
{
	HI_S32  s32SceneChanged;/* �����л���Ϣ */
	HI_S32  s32FilmType;/* ��Ӱģʽ */
	HI_U32  u32KeyValue;/* �ؼ�֡ */
} HI_PQ_PFMD_PLAYBACK_S;

 /*TVD���º�������ӿ�
 */
  typedef struct
  {    
	  HI_S32 (*pUpdateTvd)(HI_VOID *pstRegTvd); 
  } TVD_UPDATE_FUNC_S;
/*Dim ǿ�ȵȼ�*/
typedef enum hiDIM_LEVEL_E
{
    HI_PQ_DIM_LEVEL_LOW = 0,
    HI_PQ_DIM_LEVEL_MID,
    HI_PQ_DIM_LEVEL_HIGH,

    HI_PQ_DIM_LEVEL_BUTT
} HI_PQ_DIM_LEVEL_E;


 /**
 \brief Timming�仯�����VPSS PQ��������
 \attention \n
��

 \param[in] *u32HandleNo:VPSSͨ����
 \param[in] *pstTimingInfo: Timming Info
 \param[in] *pstVPSSReg:VPSS ����Ĵ�����ַ�����ΪNULL�����ʾ���ٸ�·��ַ,
 һ��handleNo��Ӧһ����ַ������ַ�����仯���Ż����¸���ʼֵ�����򲻸���ʼֵ��
 \param[out] *pstPQModule:PQ���������Ŀ��ز���

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateVpssPQ(HI_U32 u32HandleNo, HI_VPSS_PQ_INFO_S* pstTimingInfo, HI_VOID *pstVPSSReg, HI_PQ_VPSS_MODULE_S* pstPQModule);

/**
 \brief Timming�仯�����VDP PQ��������
 \attention \n
��

 \param[in] u32DisplayId
 \param[in] pstTimingInfo: Timming Info
 \param[in] *pstVDPReg:VDP ����Ĵ�����ַ

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateVdpPQ(HI_U32 u32DisplayId, HI_VDP_PQ_INFO_S* pstTimingInfo, HI_VOID *pstVDPReg);
/**
 \brief TVD PQ��������
 \attention \n
��

 \param[in] *pstRegTvd:tvd ����Ĵ�����ַ
 \retval ::HI_SUCCESS
 */
 extern HI_S32 DRV_PQ_UpdateTvdPQ(HI_VOID *pstRegTvd);
/**
 \brief MEMC PQ��������
 \attention \n
��

 \param[in] *pstMeRegMem:MEMC ����Ĵ�����ַ
 \param[in] *pstfFiRegMem:MEMC ����Ĵ�����ַ
 \param[in] *pstIsrRegMem:MEMC ����Ĵ�����ַ

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_UpdateMemcPQ(HI_VOID *pstMeRegMem, HI_VOID *pstfFiRegMem, HI_VOID *pstIsrRegMem);

/**
 \brief ����4K Timing�µ�����
 \attention \n
��

 \param[in] u32DisplayId: display Id
 \param[in] pst4KInfo

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_Update4KSetting(HI_U32 u32DisplayId, HI_VDP_4K_INFO_S* pst4KInfo);

/**
 \brief ����DHD ������
 \attention \n
��

 \param[in] pstDHDInfo

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_UpdateDHDParam(HI_U32 u32DisplayId, HI_VDP_DHD_INFO_S *pstDHDInfo);

/**
 \brief ����VDP��ͨ����CSC
 \attention \n
��

 \param[in] enDisplayId:
 \param[in] pstCscMode: ɫ�ʿռ�

 \retval ::HI_SUCCESS

 */
 extern HI_S32 DRV_PQ_UpdateVdpCSC(HI_PQ_CSC_ID_E enDisplayId, HI_PQ_VDP_CSC_S *pstCscMode);

/**
 \brief ����DCIֱ��ͼͳ�ƴ���
 \attention \n
��

 \param[in] *pstWin;

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_UpdateDCIWin(HI_PQ_DCI_WIN_S *pstWin);

/**
 \brief ����VPSS scalerϵ��
 \attention \n
��

 \param[in] pstScalerInfo:������Ϣ
 \param[out] pvCoefAddr:����ϵ����ַ

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetVpssScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief ����VDP scalerϵ��
 \attention \n
��

 \param[in] pstScalerInfo:������Ϣ
 \param[out] pvCoefAddr:����ϵ����ַ

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief ����WBC scalerϵ��
 \attention \n
��

 \param[in] pstScalerInfo:������Ϣ
 \param[out] pvCoefAddr:����ϵ����ַ

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetWbcScalerCoef(HI_PQ_SCALER_S *pstScalerInfo, HI_VOID *pvCoefAddrY,HI_VOID *pvCoefAddrC);
/**
 \brief ����ǿ�Ȼ�ȡHorizontal scaler����ϵ��
 \attention \n
��

 \param[in] enScalarLevel:����ǿ��
 \param[out] pvCoefAddr:����ϵ����ַ

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetHorizontalScalerCoefByLevel(HI_PQ_SCALAR_LEVEL_E enScalarLevel, HI_VOID *pLCoefAddr, HI_VOID *pCCoefAddr);

/**
 \brief ��ȡCSCϵ��
 \attention \n
��

 \param[in] enCSCMode:
 \param[out] pstCSCCoef:
 \param[out] pstCSCDCCoef:

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_GetCSCCoef(HI_PQ_CSC_MODE_E  enCSCMode, HI_PQ_CSC_COEF_S *pstCSCCoef, HI_PQ_CSC_DCCOEF_S *pstCSCDCCoef);

/**
 \brief ��ȡ8bit CSCϵ��
 \attention \n
��

 \param[in] enCSCMode:
 \param[out] pstCSCCoef:
 \param[out] pstCSCDCCoef:

 \retval ::HI_SUCCESS

 */
extern HI_S32 DRV_PQ_Get8BitCSCCoef(HI_PQ_CSC_MODE_E  enCSCMode, HI_PQ_CSC_COEF_S *pstCSCCoef, HI_PQ_CSC_DCCOEF_S *pstCSCDCCoef);

/**
 \brief ���д�DEI��ȡ��Global Motion��Ϣ
 \attention \n
��

 \param[in] *pstMotionHist:ֱ��ͼ
 \param[out] *pstMotionResult:�˶���Ϣ

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_GetDeiGlobalMotion(HI_PQ_MOTION_INPUT_S *pstMotionInput,HI_PQ_MOTION_INFO_S *pstMotionResult);


/**
\brief     :Tnr��Global Motion���㷨API

\attention :
			���㷨�ο�DEIģ�������ֲ
			�㷨�ṩ���ᳯ�� p00188942����ֲ&ά���������� l00268071
			�㷨���Ѿ���u32GlobalMotion��u32AdjustGain�䵽��Ӧ�Ĵ�����

\param[in] :pstParamIn�ṹ����������Ԫ��
			u32HdlNo ʵ����ID
			u32Width ����ͼ����
			u32Height ����ͼ��߶�
			pstMotionReg �Ĵ�����ַ

\param[out]:pstMotionResult�ṹ����������Ԫ��
			u32GlobalMotion
			u32AdjustGain

\retval    :HI_SUCCESS/HI_FAILURE

*/
extern HI_S32 DRV_PQ_GetTnrGlobalMotion(HI_PQ_TNR_MOTION_PARAM_IN_S *pstParamIn, HI_PQ_TNR_MOTION_RESULT_S *pstMotionResult);


/**
\brief     :����Global Motion��ȡDB������Ӧǿ��ֵAPI

\attention :�����ڶԶ�ʵ����ID u32HdlNo ������Լ�⣬���ж���ֵ
			���л��������ź�Դ�����õ�Global Motion��ͬ��
			�㷨���Ѿ����������u8HWeight��u8VWeight�䵽�Ĵ���VPSS_DB_WEIGHT��
			�㷨�ṩ������÷ y00224511����ֲ&ά���������� l00268071

\param[in] :pstParamIn�ṹ����������Ԫ��
			u32HdlNo ʵ����ID
			u8SCDStr �Ǹ���SCD��api����ó���һ��ֵ[0,255]
			pstReg   global motion �Ĵ�����ַ
			eType ����Դ���ͣ����л����У��Ƿ���DEI

\param[out]:pstDBstr  DBǿ��ֵ����Ӧ�Ĵ���VPSS_DB_WEIGHT���ֱ�Ϊu8HWeight��u8VWeight

\retval    :HI_SUCCESS/HI_FAILURE

*/
extern HI_S32 DRV_PQ_GetAdaptiveDBStrength(HI_PQ_DB_STR_PARAM_IN_S *pstParamIn, HI_PQ_DB_WEIGHT_S *pstDBstr);

extern HI_S32 DRV_PQ_DBApi(HI_U32 u32HandleNo, const HI_VOID *pVpssSWBReg);

/**
 \brief ����FMDģʽ���
 \attention \n
��

 \param[in] pstVPSSReg: VPSS����Ĵ�����ַ

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_PfmdDetect(HI_PQ_PFMD_CALC_S *pstPfmdCalc,HI_PQ_PFMD_PLAYBACK_S *pstPfmdResult);

/**
 \brief ����FMDģʽ���
 \attention \n
��

 \param[in] pstVPSSReg: VPSS����Ĵ�����ַ

 \retval ::HI_SUCCESS

 */

extern HI_S32 DRV_PQ_IfmdDect(HI_PQ_IFMD_CALC_S *pstIfmdCalc,HI_PQ_IFMD_PLAYBACK_S *pstIfmdResult);

/**
 \brief ��ȡDCIֱ��ͼ
 \attention \n
��

 \param[in] *pstDciHist:0-255

 \retval ::HI_SUCCESS

 */
 
extern HI_S32 DRV_PQ_GetDciHistgram(HI_PQ_HISTGRAM_S *pstDciHist);

/**
 \brief ��ȡDCI����Ȩ������
 \attention \n
��

 \param[in] *pstDciLut

 \retval ::HI_SUCCESS

 */
 
HI_S32 DRV_PQ_GetDciFinalAdjLut(HI_PQ_DCI_ADJ_LUT_S *pstDciLut);
extern HI_S32 DRV_PQ_SetDimLevel(HI_PQ_DIM_LEVEL_E enDimLevel);

HI_S32 PQ_ModuleInit(HI_VOID);
HI_VOID PQ_ModuleExit(HI_VOID);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __DRV_PQ_EXT_H__ */
