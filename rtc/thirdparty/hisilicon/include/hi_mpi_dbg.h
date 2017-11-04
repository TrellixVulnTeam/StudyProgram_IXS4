/******************************************************************************

  Copyright (C), 2012-2050, Hisilicon Tech. Co., Ltd.

******************************************************************************
  File Name     : mpi_pq_dbg.h
  Version       : Initial Draft
  Author        : l00212594
  Created       : 2013/10/15
  Description   :

******************************************************************************/

#ifndef __MPI_PQ_DBG_H__
#define __MPI_PQ_DBG_H__

#include "hi_type.h"
#include "hi_drv_pq.h"
#include "hi_mpi_pq.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#define PQ_CMD_SIZE sizeof(HI_U32)

/* PQ�������� */
typedef enum hiPQ_DBG_CMD
{
    PQ_CMD_READ_REG = 0,
    PQ_CMD_WRITE_REG,
    PQ_CMD_READ_REGS,
    PQ_CMD_WRITE_REGS,
    PQ_CMD_READ_I2C,
    PQ_CMD_WRITE_I2C,
    PQ_CMD_READ_I2CS,
    PQ_CMD_WRITE_I2CS,

    PQ_CMD_READ_GAMMA = 0x100,
    PQ_CMD_WRITE_GAMMA,

    PQ_CMD_READ_ACM,
    PQ_CMD_WRITE_ACM,

    PQ_CMD_READ_3DCE,
    PQ_CMD_WRITE_3DCE,

    PQ_CMD_MODULE_ENABLE,
    PQ_CMD_MODULE_DISABLE,

    PQ_CMD_PATTERN_ON,
    PQ_CMD_PATTERN_OFF,

    PQ_CMD_READ_CSC_MODE,
    PQ_CMD_WRITE_CSC_MODE,

    PQ_CMD_READ_ABC_LUT,
    PQ_CMD_WRITE_ABC_LUT,

    PQ_CMD_READ_TNR_PIXMEAN_TO_RATIO_LUMA,//270
    PQ_CMD_WRITE_TNR_PIXMEAN_TO_RATIO_LUMA,
    
    PQ_CMD_READ_TNR_PIXMEAN_TO_RATIO_CHROMA,
    PQ_CMD_WRITE_TNR_PIXMEAN_TO_RATIO_CHROMA,
    
    PQ_CMD_READ_TNR_MOTION_MAPPING_LUMA,
    PQ_CMD_WRITE_TNR_MOTION_MAPPING_LUMA,

    PQ_CMD_READ_TNR_MOTION_MAPPING_CHROMA,
    PQ_CMD_WRITE_TNR_MOTION_MAPPING_CHROMA,
    
    PQ_CMD_READ_TNR_FINAL_MOTION_MAPPING_LUMA,
    PQ_CMD_WRITE_TNR_FINAL_MOTION_MAPPING_LUMA,

    PQ_CMD_READ_TNR_FINAL_MOTION_MAPPING_CHROMA,
    PQ_CMD_WRITE_TNR_FINAL_MOTION_MAPPING_CHROMA,

    PQ_CMD_READ_SNR_PIXMEAN_TO_RATIO,
    PQ_CMD_WRITE_SNR_PIXMEAN_TO_RATIO,

    PQ_CMD_READ_SNR_PIXDIFF_TO_EDGESTR,
    PQ_CMD_WRITE_SNR_PIXDIFF_TO_EDGESTR,

    PQ_CMD_READ_DIM_LED_0DADTUST,
    PQ_CMD_WRITE_DIM_LED_0DADTUST,

    PQ_CMD_READ_DCI_LUT,
    PQ_CMD_WRITE_DCI_LUT,
    PQ_CMD_READ_HIST,//��ȡֱ��ͼ

    PQ_CMD_READ_CSC_COEF,
    PQ_CMD_WRITE_CSC_COEF,

    PQ_CMD_READ_SHARPEN_ADPGAIN,
    PQ_CMD_WRITE_SHARPEN_ADPGAIN,

    PQ_CMD_READ_DCI_FINAL_LUT,//��ȡDCI���յ�������
    PQ_CMD_READ_DCI_WEIGHT,
    PQ_CMD_WRITE_DCI_WEIGHT,

	PQ_CMD_WRITE_WHITE_BALANCE_PARAM, //д�Զ���ƽ�������� 

	PQ_CMD_READ_SHARPEN_YRATIO,    //��дSharpen��YValue-Ratio ���߲���
    PQ_CMD_WRITE_SHARPEN_YRATIO,

	PQ_CMD_READ_TNR_FMOTIONMAPPING,   //��дTNR	��Y FMOTION-MAPPING ���߲���
    PQ_CMD_WRITE_TNR_FMOTIONMAPPING,

	PQ_CMD_READ_2D_DIMMING,
	PQ_CMD_WRITE_2D_DIMMING,
    PQ_CMD_READ_CHIP_VERSION,

	PQ_CMD_READ_4KSHARPEN_LIMITCURVE,
	PQ_CMD_WRITE_4KSHARPEN_LIMITCURVE,

	PQ_CMD_READ_FHDSHARPEN_LIMITCURVE,
	PQ_CMD_WRITE_FHDSHARPEN_LIMITCURVE,
	
    PQ_CMD_BUTT,
} PQ_DBG_CMD_E;

/* ����PQ�Ĵ�����*/
typedef struct hiPQ_DBG_R_REG
{
    HI_U32 u32CMD;     
    HI_U32 u32Addr;    /**<  �Ĵ�����ַ  */
} PQ_DBG_REG_R_S;

/* ����PQ�Ĵ���д */
typedef struct hiPQ_DBG_W_REG
{
    HI_U32 u32CMD;     
    HI_U32 u32Addr;    /**<  �Ĵ�����ַ  */
    HI_U32 u32Data;    /**<  �Ĵ���ֵ*/
} PQ_DBG_REG_W_S;

/* �����߽ṹ��*/
typedef struct hiPQ_DBG_CMD_READ_S
{
    HI_U32 u32CMD;     
} PQ_DBG_CMD_READ_S;

/* д����Pattern*/
typedef struct hiPQ_DBG_PATTERN
{
    HI_U32 u32CMD;     
    HI_U32 u32RLevel;   
    HI_U32 u32GLevel;   
    HI_U32 u32BLevel;   
} PQ_DBG_PATTERN_S;

/* Pattern�ر�*/
typedef struct hiPQ_DBG_PATTERN_OFF
{
    HI_U32 u32CMD;     
} PQ_DBG_PATTERN_OFF_S;

/* Gamma����д ������HAL��Gammaģ��Ľṹ�� */
typedef struct hiPQ_DBG_GAMMA_W_S
{
    HI_U32 u32CMD;       
    HI_PQ_GAMMA_TABLE_S stGammaTbl;
} PQ_DBG_GAMMA_W_S;

/* ACM����д ������HAL��ACMģ��Ľṹ�� */
typedef struct hiPQ_DBG_ACM_W_S
{
    HI_U32 u32CMD;     
    MPI_COLOR_PARAM_S stColorParam;
} PQ_DBG_ACM_W_S;

/*TNR ����д*/
typedef struct hiPQ_DBG_TNR_W_S
{
    HI_U32 u32CMD;      
    HI_PQ_TNR_S stTnrTbl;
}PQ_DBG_TNR_W_S;

/*SNR ��pixmean-ratioӳ������д������HAL��TNRģ��Ľṹ�� */
typedef struct hiPQ_DBG_SNR_PIXMEAN_2_RATIO_W_S
{
    HI_U32 u32CMD;      
    HI_PQ_SNR_PIXMEAN_2_RATIO_S stSnrPixMeanToRatio;
}PQ_DBG_SNR_PIXMEAN_2_RATIO_W_S;

/*SNR ��pixdiff-edgestrӳ������д������HAL��TNRģ��Ľṹ�� */
typedef struct hiPQ_DBG_SNR_PIXDIFF_2_EDGESTR_W_S
{
    HI_U32 u32CMD;     
    HI_PQ_SNR_PIXDIFF_2_EDGESTR_S stSnrPixDiffToEdgeStr;
}PQ_DBG_SNR_PIXDIFF_2_EDGESTR_W_S;

/*��̬����ֶε���ӳ������д������HAL��DIMģ��Ľṹ�� */
typedef struct hiPQ_DBG_OD_DIM_W_S
{
    HI_U32 u32CMD;
    HI_PQ_DIM_LUT_S stDimLut;
}PQ_DBG_OD_DIM_W_S;

/*DCI�������ñ�д*/
typedef struct hiPQ_DBG_DCI_WGT_W_S
{
    HI_U32 u32CMD; 
    HI_PQ_DCI_WGT_S stDciWgt;
}PQ_DBG_DCI_WGT_W_S;

/*CSCϵ��д*/
typedef struct hiPQ_DBG_CSC_W_S
{
    HI_U32 u32CMD; 
    HI_PQ_CSC_S stCscCoef;
}PQ_DBG_CSC_W_S;

/*sHARPEN AdpGain ����д*/
typedef struct hiPQ_DBG_SHARPEN_W_S
{
    HI_U32 u32CMD; 
    HI_PQ_SHARPEN_TABLE_S stSharpAdpGain;
}PQ_DBG_SHARPEN_W_S;

typedef struct hiPQ_DBG_DCI_WEIGHT_W_S
{
   HI_U32 u32CMD;
   HI_PQ_DCI_WEIGHT_S stDciWeight;
}PQ_DBG_DCI_WEIGHT_W_S;

/* �Զ���ƽ�����д*/
typedef struct hiPQ_DBG_WHITE_BALANCE_W_S
{
   HI_U32 u32CMD;
   MPI_WHITE_BALANCE_PARAM_S stWhiteBalance;
}PQ_DBG_WHITE_BALANCE_W_S;

/* Sharpen ��Yvalue-Ratio ӳ������д  */
typedef struct hiPQ_DBG_SHARPEN_YVALUE_W_S
{
   HI_U32 u32CMD;
#if defined(CHIP_TYPE_hi3751v600)||defined(CHIP_TYPE_hi3751lv500)
   HI_PQ_SHARPEN_YRATIO_S stYvalueParam;
#endif
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
	HI_PQ_SHARPEN_YRATIOGROUP_S stYvalueParam;
#endif
}PQ_DBG_SHARPEN_YVALUE_W_S;

typedef struct hiPQ_DBG_TNR_FMTION_MAPPING_W_S
{
   HI_U32 u32CMD;
   HI_PQ_TNR_FMOTION_MAPPING_S stTnrFmotionMapping;
}PQ_DBG_TNR_FMTION_MAPPING_W_S;
#if defined(CHIP_TYPE_hi3751v500)||defined(CHIP_TYPE_hi3751v300)
typedef struct hiPQ_DBG_SHARPEN_LIMIT_W_S
{
	HI_U32 u32CMD;
	HI_PQ_SHARPEN_LIMITLUT_GROUP_S stlimitCurve;
}PQ_DBG_SHARPEN_LIMIT_W_S;
#endif


//оƬ�ͺŽṹ����
typedef struct hiPQ_DBG_VERSION_S
{
    HI_CHAR   s8ChipVersion[12];
} HI_DBG_CHIP_VERSION_S;
/*PQ ����ʵ�ֽṹ*/
typedef struct hiPQ_DBG_CMD_FUN_S
{
    HI_CHAR *pPqCmdName;
    PQ_DBG_CMD_E enDbgCmd;    
    void (*pfCmdFunction)(HI_U8 * pu8Buffer,HI_U32 u32BufferLen); /*PQ DBG CMD��Ӧ��ʵ�ֺ���*/
} PQ_DBG_CMD_FUN_S;

/* Debugģ����ص����� */
typedef void (* HI_MDBG_UART_READ_CALLBACK_FN_PTR)(HI_U8* pu8Buffer, HI_S32 s32BufferLen, HI_S32* ps32ReadSize);

/* Debugģ��д�ص����� */
typedef void (* HI_MDBG_UART_WRITE_CALLBACK_FN_PTR)(HI_U8* pu8Buffer, HI_S32 s32BufferLen);


/* PQ Debug�������� */
HI_S32 MPI_PQ_DBG_Parser(HI_U8* pu8Buffer, HI_U32 u32BufferLen);

/* ע�ᴮ�ڶ�д���� */
HI_VOID MPI_PQ_DBG_RegisterUartFunc(HI_MDBG_UART_READ_CALLBACK_FN_PTR pfnUartRead,HI_MDBG_UART_WRITE_CALLBACK_FN_PTR pfnUartWrite);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif /* End of #ifndef __MPI_PQ_DBG_H__ */
