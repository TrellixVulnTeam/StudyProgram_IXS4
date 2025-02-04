#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "hi_type.h"

#define HISI_SAMPLE_FIFO "/dev/hisi_sample_fifo"

#ifdef CONFIG_SUPPORT_CA_RELEASE
#define sample_common_printf
#else
#if defined(ANDROID)
#define sample_common_printf 
#else
#define sample_common_printf printf
#endif
#endif

#define HIAPI_RUN(api, ret) \
    do {\
        HI_S32 errCode; \
        errCode = api; \
        if (errCode != 0)\
        {\
            ret |= errCode; \
            printf("\033[0;31m" "[Function: %s line: %d] %s failed ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__, # api, errCode); \
        } \
    } while (0)

#define HIAPI_RUN_RETURN(api) \
    do {\
        HI_S32 errCode; \
        errCode = api; \
        if (errCode != 0)\
        {\
            printf("\033[0;31m" "[Function: %s line: %d] %s failed ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__, # api, errCode); \
            return HI_FAILURE; \
        } \
    } while (0)

#define HIAPI_RUN_RETURN_FN(api, fn) \
    do {\
        HI_S32 errCode; \
        errCode = api; \
        if (errCode != 0)\
        {\
            printf("\033[0;31m" "[Function: %s line: %d] %s failed ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__, # api, errCode); \
            fn; \
            return HI_FAILURE; \
        } \
    } while (0)

#define HIAPI_ERR_PRINTF(ret) \
    do {\
        printf("\033[0;31m" " [Function: %s line: %d]  ret = 0x%x \n" "\033[0m", __FUNCTION__, __LINE__, ret); \
    } while (0)\


#define PRINT_SMP(fmt...) printf(fmt)

#define SAMPLE_RUN(api, ret) \
    do { \
        HI_S32 l_ret = api; \
        if (l_ret != HI_SUCCESS) \
        { \
            PRINT_SMP("run %s failed, ERRNO:%#x.\n", # api, l_ret); \
        } \
        else \
        {\
            /*printf("sample %s: run %s ok.\n", __FUNCTION__, #api);}*/ \
        } \
        ret = l_ret; \
    } while (0)

#define SAMPLE_CheckNullPTR(pointer) \
    do  \
    { \
        if (NULL == pointer) \
        {   \
            PRINT_SMP("%s failed:NULL Pointer in Line:%d!\n", __FUNCTION__, __LINE__); \
            return HI_FAILURE;  \
        }   \
    } while (0)

#if defined (ANDROID_SAMPLE_USE_FIFO)
 #define SAMPLE_GET_INPUTCMD(InputCmd)   \
    do { \
        int t_fd; \
        unlink(HISI_SAMPLE_FIFO); \
        if (mkfifo(HISI_SAMPLE_FIFO, 0777) != -1) \
        { \
            t_fd = open(HISI_SAMPLE_FIFO, O_RDONLY); \
            if (t_fd != -1)  \
            { \
                memset(InputCmd, 0, sizeof(InputCmd));   \
                read(t_fd, InputCmd, sizeof(InputCmd));  \
                close(t_fd); \
            } \
            else  \
            { \
                perror("Can't open the FIFO:");  \
                exit(0); \
            } \
        } \
        else  \
        { \
            perror("Can't create FIFO channel:"); \
            exit(0); \
        } \
    } while (0)

#else
 #define SAMPLE_GET_INPUTCMD(InputCmd) fgets((char *)(InputCmd), (sizeof(InputCmd) - 1), stdin)
#endif

#endif
