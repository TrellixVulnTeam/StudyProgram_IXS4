/******************************************************************************

  Copyright (C), 2011-2021, HiSilicon Technologies Co., Ltd.

 ******************************************************************************
  File Name     : hi_unf_pdm.h
  Version       : Initial Draft
  Author        : HiSilicon multimedia software group
  Created       : 2011-xx-xx
  Description   : hi_unf_pdm.h header file
  History       :
  1.Date        : 2011/xx/xx
    Author      : 
    Modification: This file is created.

******************************************************************************/

#ifndef __HI_UNF_PDM_H__
#define __HI_UNF_PDM_H__

#include "hi_unf_common.h"
#include "hi_unf_mce.h"
#include "hi_unf_sound.h"
#include "hi_unf_panel.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif  /* End of #ifdef __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */

/**Defines the base config parameter*/
/** CNcomment:�������ò����ṹ��*/
typedef struct hiUNF_PDM_DISP_PARAM_S
{
    HI_UNF_DISP_E               enSrcDisp;          /**<source display*//**<CNcomment: ͬԴdisplayö��*/
    HI_UNF_ENC_FMT_E            enFormat;           /**<Format*//**<CNcomment: ��ʽ*/
    HI_U32                      u32Brightness;      /**<Brightness*//**<CNcomment: ����*/ 
    HI_U32                      u32Contrast;        /**<Contrast*//**<CNcomment: �Աȶ�*/ 
    HI_U32                      u32Saturation;      /**<Saturation*//**<CNcomment: ���Ͷ�*/
    HI_U32                      u32HuePlus;         /**<HuePlus*//**<CNcomment: ɫ��*/
    HI_BOOL                     bGammaEnable;       /**<Is Gamma enable*//**<CNcomment: �Ƿ�ʹ��gamma*/   
    HI_UNF_DISP_BG_COLOR_S      stBgColor;          /**<Background Color*//**<CNcomment: ����ɫ*/
    HI_UNF_DISP_INTF_S          stIntf[HI_UNF_DISP_INTF_TYPE_BUTT];     /**<configuration of display interface*//**<CNcomment: ��ʾ�ӿ�����*/
    HI_UNF_DISP_TIMING_S        stDispTiming;       /**<Display timeing*//**<CNcomment: ��ʾʱ��*/
    
    HIGO_PF_E                   enPixelFormat;      /**<Pixel format*//**<CNcomment: ���ظ�ʽ*/
    HI_UNF_DISP_OFFSET_S        stDispOffset;       /**<Display margin info*//**<CNcomment: ��ʾ�հ�����*/
    HI_U32                      u32VirtScreenWidth; /**<Virtual screen width*//**<CNcomment: ������Ļ��*/
    HI_U32                      u32VirtScreenHeight;    /**<Virtual screen height*//**<CNcomment: ������Ļ��*/
    
    HI_UNF_DISP_ASPECT_RATIO_S  stAspectRatio;      /**<The device aspect ratio*//**<CNcomment: �豸��߱�*/
}HI_UNF_PDM_DISP_PARAM_S;

/**PDM sound parameters *//**CNcomment:PDM��Ƶ�������ݽṹ  */
typedef struct hiUNF_PDM_SOUND_PARAM_S
{
    HI_U32                    u32PortNum;  /**<Outport number attached sound*/ /**<CNcomment:�󶨵�Sound�豸������˿���*/
    HI_UNF_SND_OUTPORT_S stOutport[HI_UNF_SND_OUTPUTPORT_MAX];  /**<Outports attached sound*/ /**<CNcomment:�󶨵�Sound�豸������˿�*/
}HI_UNF_PDM_SOUND_PARAM_S;

/**PDM base parameter's type *//**CNcomment:PDM BASE�������ݽṹ  */
typedef enum hiUNF_PDM_BASEPARAM_TYPE_E
{
    HI_UNF_PDM_BASEPARAM_DISP0 = 0,     /**<DISPLAY0*/ /**<CNcomment:DISPLAY0*/
    HI_UNF_PDM_BASEPARAM_DISP1,         /**<DISPLAY1*/ /**<CNcomment:DISPLAY1*/
    HI_UNF_PDM_BASEPARAM_SOUND0 = 10,   /**<SOUND0*/ /**<CNcomment:SOUND0*/
    HI_UNF_PDM_BASEPARAM_SOUND1,        /**<SOUND1*/ /**<CNcomment:SOUND1*/
    HI_UNF_PDM_BASEPARAM_SOUND2,        /**<SOUND2*/ /**<CNcomment:SOUND2*/

    HI_UNF_PDM_BASEPARAM_BUTT
}HI_UNF_PDM_BASEPARAM_TYPE_E;


/**PDM bootmusic parameters */
/**CNcomment:PDM�������ֲ������ݽṹ  */
typedef struct hiUNF_BOOT_MUSIC_PARAM_S 
{ 
    HI_BOOL                 bEnable;            /**<Whether bootmusic is enable*//**<CNcomment: ���������Ƿ�ʹ��*/
    HI_U32                  u32Volume;          /* volume of bootmusic */ /**<CNcomment: ������������*/
    HI_U32                  u32DataLen;         /**<bootmusic data*//**<CNcomment: �����������ݳ��� */
    HI_U32                  u32DataPlayLen;     /**<bootmusic data len*//**<CNcomment: �������ֲ������ݳ��� */
}HI_UNF_BOOT_MUSIC_PARAM_S;

/** @} */  /*! <!-- Structure Definition end */

/******************************* API declaration *****************************/
/** \addtogroup      PDM */
/** @{ */  /** <!-- [PDM] */
/** 
\brief Obtains the basic configuration information.  CNcomment:��ȡBASE��������Ϣ CNend
\attention \n
N/A
\param[in]  pstBaseParam   Pointer to the basic parameters.  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);


/** 
\brief Modifies the basic configuration information.  CNcomment:����BASE��������Ϣ CNend
\attention \n
N/A
\param[in]  pstBaseParam Pointer to the basic parameters.  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBaseParam(HI_UNF_PDM_BASEPARAM_TYPE_E enType, HI_VOID *pData);

/** 
\brief Obtains the basic configuration information from the flash memory.  
CNcomment:��ȡLOGO��������Ϣ CNend
\attention \n
N/A
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);

/** 
\brief Modifies the configuration of the logo parameter.  CNcomment:����LOGO��������Ϣ CNend
\attention \n
Update logo parameter, you must invoke this function befor update data of logo
\CNcomment:����logo���� CNend
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoParam(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);


/** 
\brief Obtains the logo data from the flash memory. CNcomment:��ȡLOGO��������Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the logo data that is written from the flash memory CNcomment:����bufָ�� CNend
\param[in]  u32Size  Size of the logo data to be written  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Modifies the logo data.  CNcomment:����LOGO��������Ϣ CNend
\attention \n
Update data in logo partition, You must invoke HI_UNF_PDM_UpdateLogoParam to update logo parameter before invoke this function
\CNcomment:����logo���� CNend
\param[in]  pu8Content   Pointer to the logo data that is read from the flash memory  CNcomment:����bufָ�� CNend
\param[in]  u32Size   Size of the logo data to be read  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoContent(HI_U8 *pu8Content, HI_U32 u32Size);

/** 
\brief Obtains the basic configuration information from the flash memory.  
CNcomment:��ȡLOGO��������Ϣ CNend
\attention \n
N/A
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoParamExt(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);

/** 
\brief Modifies the configuration of the logo parameter.  CNcomment:����LOGO��������Ϣ CNend
\attention \n
Update logo parameter, you must invoke this function befor update data of logo
\CNcomment:����logo���� CNend
\param[in]  pstLogoParam   Pointer to the logo parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoParamExt(HI_UNF_MCE_LOGO_PARAM_S *pstLogoParam);


/** 
\brief Obtains the logo data from the flash memory. CNcomment:��ȡLOGO��������Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the logo data that is written from the flash memory CNcomment:����bufָ�� CNend
\param[in]  u32Size  Size of the logo data to be written  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetLogoContentExt(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Modifies the logo data.  CNcomment:����LOGO��������Ϣ CNend
\attention \n
Update data in logo partition, You must invoke HI_UNF_PDM_UpdateLogoParam to update logo parameter before invoke this function
\CNcomment:����logo���� CNend
\param[in]  pu8Content   Pointer to the logo data that is read from the flash memory  CNcomment:����bufָ�� CNend
\param[in]  u32Size   Size of the logo data to be read  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateLogoContentExt(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Obtains the playing configuration information.  CNcomment:��ȡPLAY��������Ϣ CNend
\attention \n
N/A
\param[in]  pstPlayParam   Playing configuration information  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/** 
\brief   Modifies the playing configuration information.  CNcomment:����PLAY��������Ϣ CNend
\attention \n 
Update play parameter, you must invoke this function befor update data of play
\CNcomment:����play�������ڸ���play����ǰ�����ȵ��ô˺��� CNend
\param[in]  pstPlayParam  Playing configuration information  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayParam(HI_UNF_MCE_PLAY_PARAM_S *pstPlayParam);

/** 
\brief Obtains the data being playing from the flash memory.  CNcomment:��ȡPLAY��������Ϣ CNend
\attention \n
N/A
\param[in]  pu8Content Pointer to the data that is read from the flash memory  CNcomment:����bufָ�� CNend
\param[in]  u32Size  Size of the data being played that is read from the flash memory  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetPlayContent(HI_U8 *pu8Content, HI_U32 u32Size);


/** 
\brief Updates the playing data part. CNcomment:����PLAY��������Ϣ CNend
\attention \n
Update data in play partition, You must invoke HI_UNF_PDM_UpdatePlayParam to update plat parameter before invoke this function
\CNcomment:����play���ݣ��ڴ˺���֮ǰ�����ȵ���HI_UNF_PDM_UpdatePlayParam��������play���� CNend
\param[in]  pu8Content  Pointer to the data that is written to the flash memroy  CNcomment:����bufָ�� CNend
\param[in]  u32Size  Size of the data being played  CNcomment:���ݳ��� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdatePlayContent(HI_U8 *pu8Content, HI_U32 u32Size);

/** 
\brief Get panel index data. CNcomment:��ȡ����������Ϣ CNend
\attention \n
N/A
\param[in]  pu32Total  Pointer to the data that is the total number of panel index  CNcomment:panel index����Ŀ����ָ�� CNend
\param[in]  pu32Index  Pointer to the data that is the value of current panel index  CNcomment:��ǰpanel index��������ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelIndex(HI_U32 *pu32Total, HI_U32 *pu32Index);

/** 
\brief Set current panel index data. CNcomment:����ϵͳʹ�õ�����������Ϣ CNend
\attention \n
This will effective after restart system
\CNcomment:�ýӿ���Ҫ��������Ч CNend
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelIndex(HI_U32 u32Index);

/** 
\brief Get panel param of special panel index. CNcomment:��ȡ�ض�����ֵ���������� CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pstPanelParm  Pointer to the data of panel param  CNcomment:��������ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelParam(HI_U32 u32Index, HI_UNF_PANEL_INFO_S *pstPanelParm);

/** 
\brief Get panel param of special panel index. CNcomment:�����ض�����ֵ���������� CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pstPanelParm  Pointer to the data of panel param  CNcomment:��������ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelParam(HI_U32 u32Index, HI_UNF_PANEL_INFO_S *pstPanelParm);

/** 
\brief Get PQ config file path of special panel index. CNcomment:��ȡ�ض�����ֵ��PQ�����ļ�·�� CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pcPqPath  Pointer to the data of PQ config file path  CNcomment:PQ�����ļ�·������ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelPqPath(HI_U32 u32Index, HI_CHAR *pcPqPath);

/** 
\brief Get PQ config file path of special panel index. CNcomment:�����ض�����ֵ��PQ�����ļ�·�� CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pcPqPath  Pointer to the data of PQ config file path  CNcomment:PQ�����ļ�·������ָ�룬·�������֧��100 ���ֽ� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelPqPath(HI_U32 u32Index, HI_CHAR *pcPqPath);

/** 
\brief Get back light PWM value of special panel index. CNcomment:��ȡ�ض�����ֵ�ľ�̬����PWMֵ CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pu32BlPwm  Pointer to the data of back light PWM  CNcomment:��̬����PWM����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelBlPwm(HI_U32 u32Index, HI_U32 *pu32BlPwm);

/** 
\brief Set back light PWM value of special panel index. CNcomment:�����ض�����ֵ�ľ�̬����PWMֵ CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] u32BlPwm  back light PWM value  CNcomment:��̬����PWMֵ CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelBlPwm(HI_U32 u32Index, HI_U32 u32BlPwm);

/** 
\brief Get back light PWM range value of special panel index. CNcomment:��ȡ�ض�����ֵ�ľ�̬����PWM��Χֵ CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pu32BlPwmUserMin  Pointer to the data that is back light PWM minimum value  CNcomment:��̬����PWM��Сֵ����ָ�� CNend
\param[in] pu32BlPwmUserMax  Pointer to the data that is back light PWM maximum value  CNcomment:��̬����PWM���ֵ����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_GetPanelBlPwmRange(HI_U32 u32Index, HI_U32 *pu32BlPwmUserMin, HI_U32 *pu32BlPwmUserMax);

/** 
\brief Get back light PWM range value of special panel index. CNcomment:�����ض�����ֵ�ľ�̬����PWM��Χֵ CNend
\attention \n
N/A
\param[in] u32Index  Panel index value  CNcomment:panel index����ֵ CNend
\param[in] pu32BlPwmUserMin  Pointer to the data that is back light PWM minimum value  CNcomment:��̬����PWM��Сֵ����ָ�� CNend
\param[in] pu32BlPwmUserMax  Pointer to the data that is back light PWM maximum value  CNcomment:��̬����PWM���ֵ����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_PDM_SetPanelBlPwmRange(HI_U32 u32Index, HI_U32 u32BlPwmUserMin, HI_U32 u32BlPwmUserMax);

/** 
\brief Obtains the bootmusic configuration information from the flash memory.  
CNcomment:��ȡ��һ������������Ϣ���ڸ��µ�һ������������Ϣǰ�������������� CNend
\attention \n
N/A
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBMParam(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Modifies the configuration of the bootmusic parameter.  CNcomment:���¿���������������Ϣ CNend
\attention \n
Update bootmusic parameter, you must invoke this function befor update data of bootmusic
\CNcomment:���µ�һ���������ֲ��� CNend
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBMParam(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Obtains the bootmusic configuration information from the flash memory.  
CNcomment:��ȡ�ڶ�������������Ϣ���ڸ��µڶ�����������ʱ�������������� CNend
\attention \n
N/A
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_GetBMParamExt(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

/** 
\brief Modifies the configuration of the bootmusic parameter.  CNcomment:���¿���������������Ϣ CNend
\attention \n
Update bootmusic parameter, you must invoke this function befor update data of bootmusic
\CNcomment:���µڶ����������ֲ��� CNend
\param[in]  pstBMParam   Pointer to the bootmusic parameter  CNcomment:����ָ�� CNend
\retval ::HI_SUCCESS       Success. CNcomment:�ɹ� CNend
\retval :: HI_ERR_PDM_PTR_NULL      Pointer is null. CNcomment:��ָ�� CNend
\retval :: HI_ERR_PDM_GET_MTDINFO_ERR      Get flash pation infomation error. CNcomment:��ȡFlash������Ϣʧ�� CNend
\retval :: HI_ERR_PDM_MTD_OPEN      Open flash pation error. CNcomment:��Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_MEM_ALLC      Alloc memory error. CNcomment:�����ڴ�ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_READ      Read flash pation error. CNcomment:��ȡFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_WRITE      Write flash pation error. CNcomment:дFlash����ʧ�� CNend
\retval :: HI_ERR_PDM_MTD_ERASE      Erase flash pation error. CNcomment:����Flash����ʧ�� CNend
\retval :: HI_ERR_PDM_INVALID_OPT      The operation is invalid. CNcomment:��Ч���� CNend
\see \n
N/A
*/
HI_S32  HI_UNF_PDM_UpdateBMParamExt(HI_UNF_BOOT_MUSIC_PARAM_S *pstBMParam);

//���¿�������������Ϣ
HI_S32  HI_UNF_PDM_UpdateBootMusicContent(HI_U8 *pu8Content, HI_U32 u32Size);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif




