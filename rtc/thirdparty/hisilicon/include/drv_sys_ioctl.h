/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : drv_sys_ioctl.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2007/1/31
  Description   : hi3511 system private Head File
  History       :
  1.Date        : 2007/1/31
    Author      : c42025
    Modification: Created file

******************************************************************************/
#ifndef  __DRV_SYS_IOCTL_H__
#define  __DRV_SYS_IOCTL_H__

#ifdef __cplusplus
extern "C"{
#endif /* End of #ifdef __cplusplus */

#include "hi_debug.h"
#include "hi_drv_sys.h"

typedef enum hiIOC_NR_SYS_E
{
    IOC_NR_SYS_INIT = 0,
    IOC_NR_SYS_EXIT,
    IOC_NR_SYS_SETCONFIG,
    IOC_NR_SYS_GETCONFIG,
    IOC_NR_SYS_GETVERSION,
    IOC_NR_SYS_GETTIMESTAMPMS,
    IOC_NR_SYS_GETDDPSUPPORT,
    IOC_NR_SYS_GETDTSSUPPORT,
    IOC_NR_SYS_GETADVCASUPPORT,
    IOC_NR_SYS_GETMACROVISIONSUPPORT,
    IOC_NR_SYS_GETDDRCONFIG,
	IOC_NR_SYS_GETDDSUPPORT,
    IOC_NR_SYS_GETDBXSUPPORT,
    IOC_NR_SYS_GETDIEID
} IOC_NR_SYS_E;


#define SYS_INIT_CTRL         _IO (HI_ID_SYS, IOC_NR_SYS_INIT)
#define SYS_EXIT_CTRL         _IO (HI_ID_SYS, IOC_NR_SYS_EXIT)
#define SYS_SET_CONFIG_CTRL   _IOW(HI_ID_SYS, IOC_NR_SYS_SETCONFIG, HI_SYS_CONF_S)
#define SYS_GET_CONFIG_CTRL   _IOR(HI_ID_SYS, IOC_NR_SYS_GETCONFIG, HI_SYS_CONF_S)
#define SYS_GET_SYS_VERSION   _IOR(HI_ID_SYS, IOC_NR_SYS_GETVERSION, HI_SYS_VERSION_S)
#define SYS_GET_TIMESTAMPMS   _IOR(HI_ID_SYS, IOC_NR_SYS_GETTIMESTAMPMS, HI_U32)
#define SYS_GET_DDPSUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETDDPSUPPORT, HI_U32)
#define SYS_GET_DDSUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETDDSUPPORT, HI_U32)
#define SYS_GET_DBXSUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETDBXSUPPORT, HI_U32)
#define SYS_GET_DTSSUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETDTSSUPPORT, HI_U32)
#define SYS_GET_ADVCASUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETADVCASUPPORT, HI_U32)
#define SYS_GET_MACROVISIONSUPPORT   _IOR(HI_ID_SYS, IOC_NR_SYS_GETMACROVISIONSUPPORT, HI_U32)
#define SYS_GET_DDRCONFIG         _IOR(HI_ID_SYS, IOC_NR_SYS_GETDDRCONFIG, HI_SYS_MEM_CONFIG_S)
#define SYS_GET_DIEID                  _IOR(HI_ID_SYS, IOC_NR_SYS_GETDIEID, HI_U64)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __DRV_SYS_IOCTL_H__ */

