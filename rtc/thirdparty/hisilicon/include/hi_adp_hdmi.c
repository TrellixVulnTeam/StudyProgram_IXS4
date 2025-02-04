#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hi_unf_hdmi.h"
#include "hi_unf_edid.h"
#include "hi_unf_disp.h"
#include "hi_adp.h"
#include "hi_adp_hdmi.h"

#include "hi_adp_audio.h"

typedef struct hiHDMI_ARGS_S
{
    HI_UNF_HDMI_ID_E  enHdmi;
}HDMI_ARGS_S;

static HDMI_ARGS_S g_stHdmiArgs;
HI_U32 g_HDCPFlag         = HI_FALSE;
HI_U32 g_HDMI_Bebug       = HI_FALSE;
HI_U32 g_HDMIUserCallbackFlag = HI_FALSE;
HI_U32 g_enDefaultMode    = HI_UNF_HDMI_DEFAULT_ACTION_HDMI;//HI_UNF_HDMI_DEFAULT_ACTION_NULL;
 HI_UNF_HDMI_CALLBACK_FUNC_S g_stCallbackFunc;

User_HDMI_CallBack pfnHdmiUserCallback = NULL;
//#define HI_HDCP_SUPPORT
#ifdef HI_HDCP_SUPPORT
const HI_CHAR * pstencryptedHdcpKey = "EncryptedKey_332bytes.bin";
#endif

static HI_CHAR *g_pDispFmtString[HI_UNF_ENC_FMT_BUTT+1] = {
    "1080P_60", 
    "1080P_50", 
    "1080P_30", 
    "1080P_25",

    "1080P_24",        
    "1080i_60",        
    "1080i_50",        

    "720P_60",         
    "720P_50",         

    "576P_50",         
    "480P_60",         

    "PAL",             
    "PAL_N",           
    "PAL_Nc",          

    "NTSC",            
    "NTSC_J",          
    "NTSC_PAL_M",      

    "SECAM_SIN",       
    "SECAM_COS",
/*    
    "1080p_24FP",
    "720P_60FP",
    "720P_50FP",
    "640_480",
*/   
    "BUTT"
};


HI_UNF_ENC_FMT_E stringToUnfFmt(HI_CHAR *pszFmt)
{
    HI_S32 i;
    HI_UNF_ENC_FMT_E fmtReturn = HI_UNF_ENC_FMT_BUTT;

    if (NULL == pszFmt)
    {
        return HI_UNF_ENC_FMT_BUTT;
    }

    for (i = 0; i < HI_UNF_ENC_FMT_BUTT; i++)
    {
        if (strcasestr(pszFmt, g_pDispFmtString[i]))
    	{
    		fmtReturn = i;        
    		break;
    	}
    }

    if (i >= HI_UNF_ENC_FMT_BUTT)
    {
        i = HI_UNF_ENC_FMT_720P_50;
        fmtReturn = i;   
        printf("\n!!! Can NOT match format, set format to is '%s'/%d.\n\n", g_pDispFmtString[i], i);
    }
    else
    {
	    printf("\n!!! The format is '%s'/%d.\n\n", g_pDispFmtString[i], i);
    }
	return fmtReturn;
}


static HI_VOID HDMI_PrintAttr(HI_UNF_HDMI_ATTR_S *pstHDMIAttr)
{
    if (HI_TRUE != g_HDMI_Bebug)
    {
        return;
    }
    
    printf("=====HI_UNF_HDMI_SetAttr=====\n"
           "bEnableHdmi:%d\n"
           "bEnableVideo:%d\n"
           "enVidOutMode:%d\n"
           "enDeepColorMode:%d\n"
           "bxvYCCMode:%d\n\n"     
           "bEnableAudio:%d\n"            
           "bEnableAviInfoFrame:%d\n"
           "bEnableAudInfoFrame:%d\n"
           "bEnableSpdInfoFrame:%d\n"
           "bEnableMpegInfoFrame:%d\n\n"
           "==============================\n",
           pstHDMIAttr->bEnableHdmi,
           pstHDMIAttr->bEnableVideo,
           pstHDMIAttr->enVidOutMode,pstHDMIAttr->enDeepColorMode,pstHDMIAttr->bxvYCCMode,
           pstHDMIAttr->bEnableAudio,
           pstHDMIAttr->bEnableAudInfoFrame,pstHDMIAttr->bEnableAudInfoFrame,
           pstHDMIAttr->bEnableSpdInfoFrame,pstHDMIAttr->bEnableMpegInfoFrame);
    return;
}


void HDMI_HotPlug_Proc(HI_VOID *pPrivateData)
{
    HI_S32          ret = HI_SUCCESS;
#ifdef HI_HDMI_SUPPORT
    HDMI_ARGS_S     *pArgs  = (HDMI_ARGS_S*)pPrivateData;
    HI_UNF_HDMI_ID_E       hHdmi   =  pArgs->enHdmi;
    HI_UNF_HDMI_ATTR_S             stHdmiAttr;
    //HI_UNF_HDMI_INFOFRAME_S        stInfoFrame;
    HI_UNF_EDID_BASE_INFO_S        stSinkCap;
    HI_UNF_HDMI_STATUS_S           stHdmiStatus;

#ifdef HI_HDCP_SUPPORT
    static HI_U8 u8FirstTimeSetting = HI_TRUE;
#endif

    printf("\n --- Get HDMI event: HOTPLUG. --- \n"); 

    HI_UNF_HDMI_GetStatus(hHdmi,&stHdmiStatus);
    if (HI_FALSE == stHdmiStatus.bConnected)
    {
        printf("No Connect\n");
        return;
    }

    
    HI_UNF_HDMI_GetAttr(hHdmi, &stHdmiAttr);
    ret = HI_UNF_HDMI_GetSinkCapability(hHdmi, &stSinkCap); 


    if(ret == HI_SUCCESS)
    {
        //stHdmiAttr.enVidOutMode = HI_UNF_HDMI_VIDEO_MODE_YCBCR444;
        if(HI_TRUE == stSinkCap.bSupportHdmi)
        {
            stHdmiAttr.bEnableHdmi = HI_TRUE;
            if(HI_TRUE != stSinkCap.stColorSpace.bYCbCr444)
            {
                stHdmiAttr.enVidOutMode = HI_UNF_HDMI_VIDEO_MODE_RGB444;
            }
        }
        else
        {
            stHdmiAttr.enVidOutMode = HI_UNF_HDMI_VIDEO_MODE_RGB444;
            //读取到了edid，并且不支持hdmi则进入dvi模式
            //read real edid ok && sink not support hdmi,then we run in dvi mode
            stHdmiAttr.bEnableHdmi = HI_FALSE;
        }
    }
    else
    {
        //when get capability fail,use default mode 
        if(g_enDefaultMode == HI_UNF_HDMI_DEFAULT_ACTION_HDMI)
            stHdmiAttr.bEnableHdmi = HI_TRUE;
        else 
            stHdmiAttr.bEnableHdmi = HI_FALSE;
    }

    if(HI_TRUE == stHdmiAttr.bEnableHdmi)
    {
        stHdmiAttr.bEnableAudio = HI_TRUE;
        stHdmiAttr.bEnableVideo = HI_TRUE;
        stHdmiAttr.bEnableAudInfoFrame = HI_TRUE;
        stHdmiAttr.bEnableAviInfoFrame = HI_TRUE;
    }
    else
    {
        stHdmiAttr.bEnableAudio = HI_FALSE;
        stHdmiAttr.bEnableVideo = HI_TRUE;
        stHdmiAttr.bEnableAudInfoFrame = HI_FALSE;
        stHdmiAttr.bEnableAviInfoFrame = HI_FALSE;
        stHdmiAttr.enVidOutMode = HI_UNF_HDMI_VIDEO_MODE_RGB444;
    }

#ifdef HI_HDCP_SUPPORT
    if (u8FirstTimeSetting == HI_TRUE)
    {
        u8FirstTimeSetting = HI_FALSE;
        if (g_HDCPFlag == HI_TRUE)
        {
            stHdmiAttr.bHDCPEnable = HI_TRUE;//Enable HDCP
        }
        else
        {
            stHdmiAttr.bHDCPEnable= HI_FALSE;
        }
    }
    else
    {
        //HDCP Enable use default setting!!
    }
#endif

    ret = HI_UNF_HDMI_SetAttr(hHdmi, &stHdmiAttr);

    /* HI_UNF_HDMI_SetAttr must before HI_UNF_HDMI_Start! */
    ret = HI_UNF_HDMI_Start(hHdmi);

    HDMI_PrintAttr(&stHdmiAttr);
#endif
    return;

}

HI_VOID HDMI_UnPlug_Proc(HI_VOID *pPrivateData)
{
#ifdef HDMI_SUPPORT
    HDMI_ARGS_S     *pArgs  = (HDMI_ARGS_S*)pPrivateData;
    HI_UNF_HDMI_ID_E       hHdmi   =  pArgs->enHdmi;
    
    printf("\n --- Get HDMI event: UnPlug. --- \n");
    HI_UNF_HDMI_Stop(hHdmi);
#endif
    
    return;
}
static HI_U32 HDCPFailCount = 0;
HI_VOID HDMI_HdcpFail_Proc(HI_VOID *pPrivateData)
{
    //HI_UNF_HDMI_ATTR_S             stHdmiAttr;
    printf("\n --- Get HDMI event: HDCP_FAIL. --- \n");
    
    HDCPFailCount ++ ;
    if(HDCPFailCount >= 50)
    {
        HDCPFailCount = 0;
        printf("\nWarrning:Customer need to deal with HDCP Fail!!!!!!\n");
    }
#if 0
    HI_UNF_HDMI_GetAttr(0, &stHdmiAttr);

    stHdmiAttr.bHDCPEnable = HI_FALSE;

    HI_UNF_HDMI_SetAttr(0, &stHdmiAttr);
#endif
    return;
}

HI_VOID HDMI_HdcpSuccess_Proc(HI_VOID *pPrivateData)
{
    printf("\n --- Get HDMI event: HDCP_SUCCESS. --- \n");
    return;
}

HI_VOID HDMI_Event_Proc(HI_UNF_HDMI_EVENT_TYPE_E event, HI_VOID *pPrivateData)
{
    
    switch ( event )
    {
        case HI_UNF_HDMI_EVENT_HOTPLUG:
            HDMI_HotPlug_Proc(pPrivateData);
            break;
        case HI_UNF_HDMI_EVENT_NO_PLUG:
            HDMI_UnPlug_Proc(pPrivateData);
            break;
        case HI_UNF_HDMI_EVENT_EDID_FAIL:
            break;
        case HI_UNF_HDMI_EVENT_HDCP_FAIL:
            HDMI_HdcpFail_Proc(pPrivateData);
            break;
        case HI_UNF_HDMI_EVENT_HDCP_SUCCESS:
            HDMI_HdcpSuccess_Proc(pPrivateData);
            break;
        case HI_UNF_HDMI_EVENT_RSEN_CONNECT:
            //printf("HI_UNF_HDMI_EVENT_RSEN_CONNECT**********\n");
            break;
        case HI_UNF_HDMI_EVENT_RSEN_DISCONNECT:
            //printf("HI_UNF_HDMI_EVENT_RSEN_DISCONNECT**********\n");
            break;
        default:
            break;
    }
    /* Private Usage */
    if ((g_HDMIUserCallbackFlag == HI_TRUE) && (pfnHdmiUserCallback != NULL))
    {
        pfnHdmiUserCallback(event, NULL);
    }
    
    return;
}




#ifdef HI_HDCP_SUPPORT	
HI_S32 HIADP_HDMI_SetHDCPKey(HI_UNF_HDMI_ID_E enHDMIId)
{
	HI_UNF_HDMI_LOAD_KEY_S stLoadKey;
	FILE *pBinFile;
	HI_U32 u32Len;
	HI_U32 u32Ret;
	
	pBinFile = fopen(pstencryptedHdcpKey, "rb");
	if(HI_NULL == pBinFile)
	{
		printf("can't find key file\n");
		return HI_FAILURE;
	}
	fseek(pBinFile, 0, SEEK_END);
	u32Len = ftell(pBinFile);
	fseek(pBinFile, 0, SEEK_SET);

	stLoadKey.u32KeyLength = u32Len; //332
	stLoadKey.pu8InputEncryptedKey  = (HI_U8*)malloc(u32Len);
	if(HI_NULL == stLoadKey.pu8InputEncryptedKey)
	{	
		printf("malloc erro!\n");
		fclose(pBinFile);
		return HI_FAILURE;
	}
	if (u32Len != fread(stLoadKey.pu8InputEncryptedKey, 1, u32Len, pBinFile))
	{			
		printf("read file %d!\n", __LINE__);
		fclose(pBinFile);
		free(stLoadKey.pu8InputEncryptedKey);
		return HI_FAILURE;
	}
	
	u32Ret = HI_UNF_HDMI_LoadHDCPKey(enHDMIId,&stLoadKey);
	free(stLoadKey.pu8InputEncryptedKey);
	fclose(pBinFile);
	
	return u32Ret;
}
#endif

HI_S32 HIADP_HDMI_Init(HI_UNF_HDMI_ID_E enHDMIId, HI_UNF_ENC_FMT_E enWantFmt)
{
#ifdef HI_HDMI_SUPPORT
    HI_S32 Ret = HI_FAILURE;
    HI_UNF_HDMI_OPEN_PARA_S stOpenParam;
    HI_UNF_HDMI_DELAY_S  stDelay;
    
    g_stHdmiArgs.enHdmi       = enHDMIId;

    Ret = HI_UNF_HDMI_Init();
    if (HI_SUCCESS != Ret)
    {
        printf("HI_UNF_HDMI_Init failed:%#x\n",Ret);
        return HI_FAILURE;
    }
#ifdef HI_HDCP_SUPPORT	
	Ret = HIADP_HDMI_SetHDCPKey(enHDMIId);
	if (HI_SUCCESS != Ret)
    {
        printf("Set hdcp erro:%#x\n",Ret);
		//return HI_FAILURE;
    }
#endif

    HI_UNF_HDMI_GetDelay(0,&stDelay);
    stDelay.bForceFmtDelay = HI_TRUE;
    stDelay.bForceMuteDelay = HI_TRUE;
    stDelay.u32FmtDelay = 500;
    stDelay.u32MuteDelay = 120;
    HI_UNF_HDMI_SetDelay(0,&stDelay);


	g_stCallbackFunc.pfnHdmiEventCallback = HDMI_Event_Proc;
	g_stCallbackFunc.pPrivateData = &g_stHdmiArgs;
	
	Ret = HI_UNF_HDMI_RegCallbackFunc(enHDMIId, &g_stCallbackFunc);
	if (Ret != HI_SUCCESS)
    {
        printf("hdmi reg failed:%#x\n",Ret);
        HI_UNF_HDMI_DeInit();
        return HI_FAILURE;
    }

	stOpenParam.enDefaultMode = g_enDefaultMode;//HI_UNF_HDMI_FORCE_NULL;
    Ret = HI_UNF_HDMI_Open(enHDMIId, &stOpenParam);
    if (Ret != HI_SUCCESS)
    {
        printf("HI_UNF_HDMI_Open failed:%#x\n",Ret);
        HI_UNF_HDMI_DeInit();
        return HI_FAILURE;
    }
#endif	

    return HI_SUCCESS;
}


HI_S32 HIADP_HDMI_DeInit(HI_UNF_HDMI_ID_E enHDMIId)
{

#ifdef HI_HDMI_SUPPORT
    HI_UNF_HDMI_Stop(enHDMIId);

    HI_UNF_HDMI_Close(enHDMIId);

	HI_UNF_HDMI_UnRegCallbackFunc(enHDMIId, &g_stCallbackFunc);

    HI_UNF_HDMI_DeInit(); 
#endif
    return HI_SUCCESS;
}

