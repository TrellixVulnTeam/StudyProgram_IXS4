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
 * $RCSfile: ioctl_direct_call.h,v $
 * $Revision: #1 $
 * $Date: 2014/11/18 $
 * $Author: dtvbm11 $
 * $CCRevision: /main/DTV_X_HQ_int/1 $
 * $SWAuthor: Wang Yan $
 * $MD5HEX: d881270375c7a59a646516302ed43c0e $
 *
 * Description:
 *         rm_ioctl_direct_call.h
 *---------------------------------------------------------------------------*/
#ifndef IOCTL_DIRECT_CALL_H_
#define IOCTL_DIRECT_CALL_H_

#include "u_drv_cust.h"
#include "x_buf_agt.h" /* MHF Linux - Basara */

#if 0

typedef struct
{
    UINT32 u4X;
    UINT32 u4Y;
    UINT32 u4Width;
    UINT32 u4Height;
} VDP_REGION_T;
#endif

typedef struct
{
    DRV_CUSTOM_AUD_TYPE_T     e_aud_type;
    VOID*                     pv_set_type;
    SIZE_T                    z_size;
    BOOL                      b_store;
    INT32                     i4_ret;
}D_CUSTOM_AUD_SET_T;

typedef struct
{
    DRV_CUSTOM_AUD_TYPE_T     e_aud_type;
    VOID*                     pv_get_type;
    SIZE_T*                   pz_size;
    INT32                     i4_ret;
}D_CUSTOM_AUD_GET_T;

typedef struct
{
    DRV_CUSTOM_AUD_TYPE_T     e_aud_type;
    INT16*                    pui2_min;
    INT16*                    pui2_max;
    INT32                     i4_ret;
}D_CUSTOM_AUD_GET_MIN_MAX_T;

typedef struct
{
    DRV_CUSTOM_TUNER_TYPE_T         e_tuner_type;
    DRV_CUSTOM_TUNER_SET_TYPE_T     e_tuner_set_type;
    VOID*                           pv_set_info;
    SIZE_T                          z_size;
    INT32                           i4_ret;
}D_CUSTOM_TUNER_SET_T;

typedef struct
{
    DRV_CUSTOM_TUNER_TYPE_T         e_tuner_type;
    DRV_CUSTOM_TUNER_GET_TYPE_T     e_tuner_get_type;
    VOID*                           pv_get_info;
    SIZE_T*                         pz_size;
    INT32                           i4_ret;
}D_CUSTOM_TUNER_GET_T;

#if 0
typedef struct
{
    UCHAR ucVdpId;
    UCHAR ucOutFullRegion;
    VDP_REGION_T rOutRegion;
    UINT32       ui4_ret;
}MW_VDP_SETOUTREGION_T;
#endif

typedef struct
{
    UINT32 u4_idx;    
    UINT32 u4_order;
}D_PLANE_SET_ORDER_T;

/* MHF Linux - Basara */
typedef struct
{
    UINT16                        ui2_buf_agt_id;
    BUF_AGT_DATA_REQ_ACK_COND_T   e_ack_cond;
    BUF_AGT_DATA_BLK_T*           pt_data_blk;
    BOOL       b_ret;
}D_AGT_REQ_ACK_T;

/* Flash bulk write */
typedef struct
{
    UINT32    ui4_part_id;
    UINT32    ui4_offset;
    UINT32    ui4_size;
    UINT8     ui1_value;
}D_PART_BULK_WRITE_T;

/* --- TEST COMMAND PARAM STRUCTURE --- */
typedef struct
{
    UINT32    ui4_test_id;
}D_TEST_COMMAND_STRUCT_T;


#endif /*IOCTL_DIRECT_CALL_H_*/

