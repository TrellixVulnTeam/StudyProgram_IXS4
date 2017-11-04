/******************************************************************************
  Copyright (C), 2004-2050, Hisilicon Tech. Co., Ltd.
******************************************************************************
  File Name     : hi_unf_sound.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2009/1/22
  Last Modified :
  Description   : header file for audio and video output control
  Function List :
  History       :
  1.Date        :
  Author        : z67193
  Modification  : Created file
******************************************************************************/
/**
 * \file
 * \brief Describes the information about the SOUND (SND) module. CNcomment:�ṩSOUND�������Ϣ CNend
 */

#ifndef  __HI_UNF_AMP_H__
#define  __HI_UNF_AMP_H__

#include "hi_unf_common.h"
#include "hi_board.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

#ifndef HI_BOARD_AMP_TYPE
/*************************** Structure Definition ****************************/
/** \addtogroup      AMP*/
/** @{ */  /** <!--  ��AMP�� */

/**Defines the info of amp config. */
/**CNcomment:���幦�ŵ�������Ϣ*/
typedef struct AmpInfo{
    HI_U8 u8DeviceType;      /** <device type of amp*/ /** <CNcomment:���ŵ��ͺ�*/
    HI_U8 u8DeviceAddr;      /** <device address of amp when communicate with i2c */ /** <CNcomment:����ʹ��I2Cͨ��ʱʹ�õ�������ַ */
    HI_U8 u8GPIOOutputPolarity; /**<GPIO output mode polarity,it is 0 normally*/ /**<CNcomment:GPIO����Ϊ���ģʽ�����ã�һ������Ϊ0 */
    HI_U8 u8ResetGPIONum;   /** <GPIO number of amp reset pin,if it is GPIO1_5,then the result is 1*8+5=13*/ /** <CNcomment:���ŵĸ�λ�ܽŵ�GPIO�ţ���GPIO1_5,��Ϊ1*8+5=13 */
    HI_U8 u8ResetPolarity;  /** <Polarity of reset pin when amp reset  */ /** <CNcomment:���Ÿ�λʱ��λ�ܽŵĵ�ƽ */
    HI_U8 u8HWMuteGPIONum;  /** <GPIO number of amp mute pin,if it is GPIO1_5, then the result is 1*8+5=13*/ /** <CNcomment:���ŵľ����ܽŵ�GPIO�ţ���GPIO1_5,��Ϊ1*8+5=13 */
    HI_U8 u8HWMutePolarity; /** <Polarity of mute pin when amp mute is enable*/ /** <CNcomment:���ž���ʱ��λ�ܽŵĵ�ƽ */
    HI_U8 u8I2CNum;         /** <I2C channel number that amp use */ /** <CNcomment:����ʹ�õ�I2Cͨ���� */
}AMP_INFO_S;
#endif

/******************************* API declaration *****************************/
/** \addtogroup      AMP */
/** @{ */  /** <!-- [AMP] */

/**
\brief Initializes an AMP device. CNcomment:��ʼ�������豸���� CNend
\attention \n
\param[in] the pointer to the infomation of amp CNcomment: ָ�򹦷���Ϣ��ָ��
\retval ::HI_SUCCESS Success CNcomment:�ɹ�  CNend
\see \n
N/A
*/
#ifdef HI_BOARD_AMP_TYPE
HI_S32 HI_AMP_Init(HI_VOID);
#else
HI_S32 HI_AMP_Init(AMP_INFO_S *stAmpInfo);
#endif
/**
\brief Deinitializes an AMP device. CNcomment:ȥ��ʼ�������豸���� CNend
\attention \n
\param N/A
\retval ::HI_SUCCESS Success CNcomment:�ɹ�  CNend
\see \n
N/A
*/
HI_S32 HI_AMP_DeInit(HI_VOID);

/**
\brief Mute an AMP device. CNcomment: ���ù��ž��� CNend
\attention \n
\param[in] bMute Mute control CNcomment: �Ƿ��� CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
 */
HI_S32 HI_AMP_SetMute(HI_BOOL bMute);

/**
\brief Obtains the Mute state of an AMP device. CNcomment: ��ȡ���ž���״̬ CNend
\attention \n
\param[out] pbMute Pointer to AMP's Mute state CNcomment: �Ƿ��� CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
 */
HI_S32 HI_AMP_GetMute(HI_BOOL *pbMute);

/**
\brief Set SubWoofer volume of an AMP device. CNcomment: ���ù���SubWoofer���� CNend
\attention \n
\param[in] u32Volume SubWoofer volume CNcomment: ������С CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
 */
HI_S32 HI_AMP_SetSubWooferVol(HI_U32 u32Volume);

/**
\brief Obtains the SubWoofer volume of an AMP device. CNcomment: ��ȡ����SubWoofer���� CNend
\attention \n
\param[out] pu32Volume Pointer to AMP's SubWoofer volume CNcomment: ������С CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
 */
HI_S32 HI_AMP_GetSubWooferVol(HI_U32 *pu32Volume);

/**
\brief write value to AMP device's register. CNcomment: �����żĴ�����ֵ CNend
\attention \n
\param[in] u32RegAddr register address CNcomment: �Ĵ�����ַ CNend
\param[in] u32ByteSize how many bytes to write.CNcomment:д����ٸ��ֽ� CNend
\param[in] pu8Value register value CNcomment: �Ĵ���ֵ CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
*/
HI_S32 HI_AMP_WriteReg(HI_U32 u32RegAddr, HI_U32 u32ByteSize, HI_U8 *pu8Value);

/**
\brief read value of AMP device's register. CNcomment: ��ȡ���żĴ���ֵ CNend
\attention \n
\param[in] u32RegAddr register address CNcomment: �Ĵ�����ַ CNend
\param[in] u32ByteSize how many bytes to read.CNcomment:�����ٸ��ֽ� CNend
\param[out] pu8Value register value CNcomment: �Ĵ���ֵ CNend
\retval ::0 if success CNcomment: �ɹ� CNend
\retval ::otherwise error code CNcomment: ���� CNend
\see \n
N/A CNcomment: �� CNend
*/
HI_S32 HI_AMP_ReadReg(HI_U32 u32RegAddr, HI_U32 u32ByteSize, HI_U8 *pu8Value);

HI_S32 HI_AMP_SetAMP_EQ(HI_U8 u8AmpEqType,HI_U8 u8AmpEqValue);

/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AMP_H__*/

