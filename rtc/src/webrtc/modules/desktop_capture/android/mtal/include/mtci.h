/*----------------------------------------------------------------------------*
 * Copyright Statement:                                                       *
 *                                                                            *
 *   This software/firmware and related documentation ("MediaTek Software")   *
 * are protected under international and related jurisdictions'copyright laws *
 * as unpublished works. The information contained herein is confidential and *
 * proprietary to MediaTek Inc. Without the prior written permission of       *
 * MediaTek Inc., any reproduction, modification, use or disclosure of        *
 * MediaTek Software, and information contained herein, in whole or in part,  *
 * shall be strictly prohibited.                                              *
 * MediaTek Inc. Copyright (C) 2010. All rights reserved.                     *
 *                                                                            *
 *   BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND     *
 * AGREES TO THE FOLLOWING:                                                   *
 *                                                                            *
 *   1)Any and all intellectual property rights (including without            *
 * limitation, patent, copyright, and trade secrets) in and to this           *
 * Software/firmware and related documentation ("MediaTek Software") shall    *
 * remain the exclusive property of MediaTek Inc. Any and all intellectual    *
 * property rights (including without limitation, patent, copyright, and      *
 * trade secrets) in and to any modifications and derivatives to MediaTek     *
 * Software, whoever made, shall also remain the exclusive property of        *
 * MediaTek Inc.  Nothing herein shall be construed as any transfer of any    *
 * title to any intellectual property right in MediaTek Software to Receiver. *
 *                                                                            *
 *   2)This MediaTek Software Receiver received from MediaTek Inc. and/or its *
 * representatives is provided to Receiver on an "AS IS" basis only.          *
 * MediaTek Inc. expressly disclaims all warranties, expressed or implied,    *
 * including but not limited to any implied warranties of merchantability,    *
 * non-infringement and fitness for a particular purpose and any warranties   *
 * arising out of course of performance, course of dealing or usage of trade. *
 * MediaTek Inc. does not provide any warranty whatsoever with respect to the *
 * software of any third party which may be used by, incorporated in, or      *
 * supplied with the MediaTek Software, and Receiver agrees to look only to   *
 * such third parties for any warranty claim relating thereto.  Receiver      *
 * expressly acknowledges that it is Receiver's sole responsibility to obtain *
 * from any third party all proper licenses contained in or delivered with    *
 * MediaTek Software.  MediaTek is not responsible for any MediaTek Software  *
 * releases made to Receiver's specifications or to conform to a particular   *
 * standard or open forum.                                                    *
 *                                                                            *
 *   3)Receiver further acknowledge that Receiver may, either presently       *
 * and/or in the future, instruct MediaTek Inc. to assist it in the           *
 * development and the implementation, in accordance with Receiver's designs, *
 * of certain softwares relating to Receiver's product(s) (the "Services").   *
 * Except as may be otherwise agreed to in writing, no warranties of any      *
 * kind, whether express or implied, are given by MediaTek Inc. with respect  *
 * to the Services provided, and the Services are provided on an "AS IS"      *
 * basis. Receiver further acknowledges that the Services may contain errors  *
 * that testing is important and it is solely responsible for fully testing   *
 * the Services and/or derivatives thereof before they are used, sublicensed  *
 * or distributed. Should there be any third party action brought against     *
 * MediaTek Inc. arising out of or relating to the Services, Receiver agree   *
 * to fully indemnify and hold MediaTek Inc. harmless.  If the parties        *
 * mutually agree to enter into or continue a business relationship or other  *
 * arrangement, the terms and conditions set forth herein shall remain        *
 * effective and, unless explicitly stated otherwise, shall prevail in the    *
 * event of a conflict in the terms in any agreements entered into between    *
 * the parties.                                                               *
 *                                                                            *
 *   4)Receiver's sole and exclusive remedy and MediaTek Inc.'s entire and    *
 * cumulative liability with respect to MediaTek Software released hereunder  *
 * will be, at MediaTek Inc.'s sole discretion, to replace or revise the      *
 * MediaTek Software at issue.                                                *
 *                                                                            *
 *   5)The transaction contemplated hereunder shall be construed in           *
 * accordance with the laws of Singapore, excluding its conflict of laws      *
 * principles.  Any disputes, controversies or claims arising thereof and     *
 * related thereto shall be settled via arbitration in Singapore, under the   *
 * then current rules of the International Chamber of Commerce (ICC).  The    *
 * arbitration shall be conducted in English. The awards of the arbitration   *
 * shall be final and binding upon both parties and shall be entered and      *
 * enforceable in any court of competent jurisdiction.                        *
 *---------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * $RCSfile: mtci.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 *
 * Description: Peripherals, such as NOR/NAND/SIF/RTC/PWM/GPIO (and others), are centralized in
 *                   this file
 *---------------------------------------------------------------------------*/

/** @file mtci.h
 *  This header file declares exported APIs of CI module.
 */

#ifndef _MTCI_H_
#define _MTCI_H_

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "mttype.h"

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------
/// Return values
typedef enum {
  CI_OK                          =     0,
  CI_NOT_INIT                    =    -1,
  CI_ALREADY_INIT                =    -2,
  CI_INIT_FAILED                 =    -3,
  CI_INV_ARG                     =    -4,
  CI_MODULE_NOT_INSERTED         =    -5,
  CI_CIS_ERROR                   =    -6,
  CI_REGISTER_ISR_FAILED         =    -7,
  CI_CHANNEL_RESET_FAILED        =    -8,
  CI_BUF_SIZE_NGO_FAILED         =    -9,
  CI_DA_FR_INT_ENABLE_FAILED     =   -10,
  CI_INVALID_ACCESS_MODE         =   -11,
  CI_EXCEED_MAX_BUF_SIZE         =   -12,
  CI_TIME_OUT                    =   -13,
  CI_CMD_ERROR                   =   -14,
  CI_READ_ERROR                  =   -15,
  CI_WRITE_ERROR                 =   -16,
  CI_DATA_AVAILABLE              =   -17,
  CI_POWER_CTRL_ERROR            =   -18,
  CI_REG_TEST_ERROR              =   -19,
  CI_CLI_ERROR                   =   -20,
  CI_DMA_BUF_NOT_ALLOC			=   -21,
  CI_UNKNOWN_COND                =   -22,
} MTCI_Error_T;

//-----------------------------------------------------------------------------
// Public functions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** MTCI_Init()  Common Interface Initialization Fucntion
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_Init (VOID);

//-----------------------------------------------------------------------------
/** MTCI_DetectCard()  Common Interface Card Detection Function
 *  @retval TRUE card inserted ,FALSE No Card 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_DetectCard (VOID);

//-----------------------------------------------------------------------------
/** MTCI_Reset()  Resets CI Device (PCMCIA reset), also called card/CAM reset
 *  @param fgReset, TRUE:Pull-high reset pin, FALSE:pull-down reset pin.
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_Reset (BOOL fgReset);

//-----------------------------------------------------------------------------
/** MTCI_CheckCIS()  Check CIS(Card Information Structure)
 * read CIS and check if it is compatible or not 
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_CheckCIS (VOID);

//-----------------------------------------------------------------------------
/** MTCI_WriteCor()  Write COR(Configuration Option Register) data into COR
 *  address. (Set u2CorAddress=0xFFFF and u1CorValue=0xFF to use values gather 
 *  from MTCI_CheckCIS().)
 *  @param u2CorAddress, Size beginning from u4Addr
 *  @param u1CorValue, Memory buffer storing check sum value
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_WriteCor (UINT16 u2CorAddress, UINT8 u1CorValue);

//-----------------------------------------------------------------------------
/** MTCI_Read()  Read data from CAM
 *  @param pu1Data, Buffer pointer [IN]
 *  @param pu2DataLen, Buffer size [IN/OUT]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_Read (UINT8* pu1Data, UINT16* pu2DataLen);

//-----------------------------------------------------------------------------
/** MTCI_Write()  Write data into CAM
 *  @param pu1Data, Buffer pointer [IN]
 *  @param pu2DataLen, Buffer size [IN]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_Write (UINT8* pu1Data, UINT16* pu2DataLen);

//-----------------------------------------------------------------------------
/** MTCI_NegoBuf()  negotiation buffer size
 *  @param pu2BufSize, Negotiated Buffer Size [OUT]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_NegoBuf (UINT16* pu2BufSize);

//-----------------------------------------------------------------------------
/** MTCI_ReadDAStatus()  query data available
 *  @retval TRUE DA=1 (data avaliable), FALSE DA=0 (Not avaliable)
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_ReadDAStatus (VOID);

//-----------------------------------------------------------------------------
/** MTCI_ReadReg()  Read Register
 *  @param u4RegAddr, Register Address 
 *  @param pu1Data, Buffer pointer [IN]
 *  @param pu2DataLen, Buffer size [IN]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_ReadReg(UINT32 u4RegAddr, UINT8* pu1Data, const UINT16* pu2DataLen);

//-----------------------------------------------------------------------------
/** MTCI_WriteReg()  Write Register
 *  @param u4RegAddr, Register Address 
 *  @param pu1Data, Buffer pointer [IN]
 *  @param u2DataLen, Buffer size [IN]
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_WriteReg(UINT32 u4RegAddr, const UINT8* pu1Data, UINT16 u2DataLen);

//-----------------------------------------------------------------------------
/** MTCI_ReadCor()  Read COR(Configuration Option Register)
 *  @param Cor Address
 *  @retval Cor Value
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_ReadCor(UINT16 u2CorAddress);

//-----------------------------------------------------------------------------
/** MTCI_TestCardReady()  Test Card Ready
 *  @param void
 *  @retval TRUE : Card Ready, FALSE : Card not ready
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_TestCardReady(VOID);

//-----------------------------------------------------------------------------
/** MTCI_EnableSlot()  Enable Slot
 *  @param fgPodCiMode, TRUE:Enable CI function, FALSE:Disable CI function
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_EnableSlot(BOOL fgPodCiMode);

//-----------------------------------------------------------------------------
/** MTCI_DetectPodActive()  Detect Pod Active
 *  @param 
 *  @retval MTR_POD_CI_ACTIVE:CI function enabled, MTR_OK:CI function disabled.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_DetectPodActive(VOID);

//-----------------------------------------------------------------------------
/** MTCI_PcmciaEnableTs()  PCMCIA Enable TS
 *  @param fgPcmciaEnableTS, TRUE:Enable TS, FALSE:Disable TS
 *  @param fgFromCA, The request is from CA or not.
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_PcmciaEnableTs(BOOL fgPcmciaEnableTS, BOOL fgFromCA);

//-----------------------------------------------------------------------------
/** MTCI_ResetCam()  Reset CAM (Pull-high reset pin and then pull-low it again.)
 *  @param 
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_ResetCam(VOID);

//-----------------------------------------------------------------------------
/** MTCI_SetCardDetectOnOff() (Not Implemented)
 *  @param 
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_SetCardDetectOnOff(BOOL b_cd_on_off);

//-----------------------------------------------------------------------------
/** MTCI_SetBypass() Set Bypass Mode
 *  @param fgBypass, TRUE:Enable TS bypass, FALSE:Disable TS bypass.
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_SetBypass(BOOL fgBypass);

//-----------------------------------------------------------------------------
/** MTCI_ExternalDemodOnOff()  Turn On/Off external demod
 * When external demo On,  TS will be from external demodulator
 * otherwise Bypass Mode Off,  TS will be from main chip
 *  @param fgOnOff, TRUE is on, and FALSE is off
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T  MTCI_ExternalDemodOnOff (BOOL fgOnOff);

//-----------------------------------------------------------------------------
/** MTCI_ClearInt() (Not Implemented)
 *  @param 
 *  @retval 
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_ClearInt(VOID);
//-----------------------------------------------------------------------------
/** MTCI_SetTsClk()
 *  @param i4ClkRate should be 63/72/81/108/135
 *  @retval MTR_OK successful,otherwise MTR_NOT_OK.
 */
//-----------------------------------------------------------------------------
EXTERN MT_RESULT_T MTCI_SetTsClk(INT32 i4ClkRate);
MT_RESULT_T MTCI_SetTsPath(BOOL fgExternalDemod, BOOL fgThroughCard);
MT_RESULT_T MTCI_CheckCIPLUSCapability(void);
EXTERN MT_RESULT_T MTCI0_Init(VOID);
EXTERN MT_RESULT_T MTCI0_DetectCard(VOID);
EXTERN BOOL MTCI0_DetectPodActive(VOID);
EXTERN BOOL MTCI0_TestCardReady(VOID);
EXTERN MT_RESULT_T MTCI0_SetPodCiAccessMode(INT32 eAccessMode);
EXTERN INT32 MTCI0_PcmciaToPod(BOOL fgPcmciaToPod);
EXTERN INT32 MTCI0_Read(INT32 eIoState, UINT8* pu1Data, UINT16* pu2DataLen);
EXTERN MT_RESULT_T MTCI0_Write(INT32 eIoState, const UINT8* pu1Data, UINT16 u2DataLen);
EXTERN MT_RESULT_T MTCI0_ReadReg(INT32 eIoState, UINT32 u4RegAddr, UINT8* pu1Data, UINT16 pu2DataLen);
EXTERN MT_RESULT_T MTCI0_WriteReg(INT32 eIoState, UINT32 u4RegAddr, const UINT8* pu1Data, UINT16 u2DataLen);
EXTERN MT_RESULT_T MTCI0_ReadCor(UINT16 u2CorAddress);
EXTERN MT_RESULT_T MTCI0_WriteCor(UINT16 u2CorAddress, UINT8 u1CorValue);
EXTERN MT_RESULT_T MTCI0_EnableIsr(VOID);
EXTERN MT_RESULT_T MTCI0_PcmciaEnableTS(BOOL fgPcmciaEnableTS);
EXTERN UINT32 MTCI0_GetTsType(VOID);
EXTERN MT_RESULT_T MTCI0_AutoSetTsRoutingPath(VOID);
EXTERN MT_RESULT_T MTCI0_Reset(BOOL fgReset);
EXTERN MT_RESULT_T MTCI0_ResetCam(VOID);
EXTERN MT_RESULT_T MTCI0_RegIsr(UINT16 u2IntNo, void * pfnIsr, void *ppfnOld);//need to add
EXTERN MT_RESULT_T MTCI0_CiCamWorkaround(INT32 eCiCamWorkaround, void* vParam);// need to add
EXTERN MT_RESULT_T MTCI0_SetBypass(BOOL fgBypass);
EXTERN MT_RESULT_T MTCI0_SetBypassTsRouting(BOOL fgBypass);
EXTERN MT_RESULT_T MTCI0_RegFBClk(void *pfnFbClk);
#ifdef CC_DUAL_TUNER_SUPPORT
EXTERN MT_RESULT_T MTCI0_SetDualTsPath(INT32 u1TsPath);
#endif
EXTERN MT_RESULT_T MTCI0_SetCamVer(UINT32 ui4Ver);

#ifdef __cplusplus
}
#endif

#endif //_MTCI_H_
