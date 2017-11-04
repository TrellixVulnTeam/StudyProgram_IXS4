/******************************************************************************

  Copyright (C), 2015-2050, HiSilicon Technologies Co., Ltd.
 ******************************************************************************
 File Name     : hi_unf_vbi.h
 Version       : Initial draft
 Author        : HiSilicon multimedia software group
 Created       : 2015-07-01
 Description   : Application programming interfaces (APIs) of the external chip software (ECS)
  History       :
  1.Date        : 2015-07-01
    Author      : yinxiaohui WX218173
    Modification: Created file
    
 ******************************************************************************/
 
#ifndef __HI_UNF_VBI_H__
#define __HI_UNF_VBI_H__

/* add include here */
#include "hi_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define VBI_DATA_MAX    4096
#define VBI_DATA_SIZE   0x10000//4096/

/********************************Macro Definition********************************/
/** \addtogroup      VBI */
/** @{ */  /** <!--VBI */

/** Signal type of the vbi*/
/** CNcomment:VBI�ź�����*/
typedef enum    hiVBI_SIG_TYPE_E
{
    HI_UNF_VBI_TYPE_CC_VChip = 0  , /**<Closed Caption*/           /**<CNcomment:CC��ʽ*/
    HI_UNF_VBI_TYPE_TT ,            /**<Teletext*/                 /**<CNcomment:ͼ�ĵ���*/
    HI_UNF_VBI_TYPE_WSS  ,          /**<Widescreen Signalling*/    /**<CNcomment:����Ļ�ź�*/
    HI_UNF_VBI_TYPE_VPS  ,          /**<VPS*/                    /**<CNcomment:VPS��ʽ*/

    HI_UNF_VBI_TYPE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_SIG_TYPE_E;

/** Source type of the vbi*/
/** CNcomment:VBI�ź���Դ*/
typedef enum    hiVBI_SRC_TYPE_E
{
    HI_UNF_VBI_SRC_TYPE_HDDEC = 0  ,     /**<source form hddec*/       /**<CNcomment:����Դ��Ypbprģʽ*/
    HI_UNF_VBI_SRC_TYPE_TVD ,            /**<source form tvd*/         /**<CNcomment:����Դ��cvbsģʽ*/

    HI_UNF_VBI_SRC_TYPE_BUTT             /**<Invalid value*/            /**<CNcomment:�Ƿ��߽�ֵ*/
}HI_UNF_VBI_SRC_TYPE_E;

/**VBI source attribute */
/**CNcomment:VBI�����ź����� */
typedef struct hiUNF_VBI_SRC_ATTR_S
{
    HI_UNF_VBI_SIG_TYPE_E  enType;             /**<VBI input signal type *//**CNcomment: VBI�����ź����� */
    HI_UNF_VBI_SRC_TYPE_E  enSrcType;          /**<VBI input source type *//**CNcomment: VBI����Դ���� */
} HI_UNF_VBI_SRC_ATTR_S;

/**============================CC data type=============================*/
/** CNcomment:CC�������ͷ��� */
typedef enum hiUNF_VBI_CC_DATA_TYPE_E
{
    HI_UNF_VBI_CC_DATA_TYPE_608,        /**<CC608*//**<CNcomment:CC608���� */
    HI_UNF_VBI_CC_DATA_TYPE_708,        /**<CC708*//**<CNcomment:CC708���� */
    HI_UNF_VBI_CC_DATA_TYPE_ARIB,       /**<ARIB CC*//**<CNcomment:ARIB CC���� */

    HI_UNF_VBI_CC_DATA_TYPE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_DATA_TYPE_E;

/**CC608 data type*//** CNcomment:CC608��line 21���������ͷ��� */
typedef enum hiUNF_VBI_CC_608_DATATYPE_E
{
    HI_UNF_VBI_CC_608_DATATYPE_CC1,       /**<CC1*//**<CNcomment:CC1 */
    HI_UNF_VBI_CC_608_DATATYPE_CC2,       /**<CC2*//**<CNcomment:CC2 */
    HI_UNF_VBI_CC_608_DATATYPE_CC3,       /**<CC3*//**<CNcomment:CC3 */
    HI_UNF_VBI_CC_608_DATATYPE_CC4,       /**<CC4*//**<CNcomment:CC4 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT1,     /**<TEXT1*//**<CNcomment:TEXT1 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT2,     /**<TEXT2*//**<CNcomment:TEXT2 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT3,     /**<TEXT3*//**<CNcomment:TEXT3 */
    HI_UNF_VBI_CC_608_DATATYPE_TEXT4,     /**<TEXT4*//**<CNcomment:TEXT4 */

    HI_UNF_VBI_CC_608_DATATYPE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_608_DATATYPE_E;

/**standard color*//** CNcomment:��׼��ɫ */
typedef enum hiUNF_VBI_CC_COLOR_E
{
    HI_UNF_VBI_CC_COLOR_DEFAULT=0x00000000,       /**<default color*//**<CNcomment:Ĭ����ɫ */
    HI_UNF_VBI_CC_COLOR_BLACK=0xff000000,         /**<black*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_WHITE=0xffffffff,         /**<white*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_RED=0xffff0000,           /**<red*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_GREEN=0xff00ff00,         /**<green*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_BLUE=0xff0000ff,          /**<blue*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_YELLOW=0xffffff00,        /**<yellow*//**<CNcomment:��ɫ */
    HI_UNF_VBI_CC_COLOR_MAGENTA=0xffff00ff,       /**<magenta*//**<CNcomment:Ʒ�� */
    HI_UNF_VBI_CC_COLOR_CYAN=0xff00ffff,          /**<cyan*//**<CNcomment:��ɫ */
}HI_UNF_VBI_CC_COLOR_E;

/**opacity*//** CNcomment:͸���� */
typedef enum hiUNF_VBI_CC_OPACITY_E
{
    HI_UNF_VBI_CC_OPACITY_DEFAULT,         /**<default*//**<CNcomment:Ĭ��͸���� */
    HI_UNF_VBI_CC_OPACITY_SOLID,           /**<opaque*//**<CNcomment:��͸�� */
    HI_UNF_VBI_CC_OPACITY_FLASH,           /**<flash*//**<CNcomment:��˸ */
    HI_UNF_VBI_CC_OPACITY_TRANSLUCENT,     /**<translucent*//**<CNcomment:��͸�� */
    HI_UNF_VBI_CC_OPACITY_TRANSPARENT,     /**<transparent*//**<CNcomment:͸�� */

    HI_UNF_VBI_CC_OPACITY_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_OPACITY_E;

/**justify*//** CNcomment:�Ű�*/
typedef enum hiUNF_VBI_CC_JUSTIFY_E
{
    HI_UNF_VBI_CC_JUSTIFY_LEFT,        /**<left*//**<CNcomment:���� */
    HI_UNF_VBI_CC_JUSTIFY_RIGHT,       /**<rigth*//**<CNcomment:���� */
    HI_UNF_VBI_CC_JUSTIFY_CENTER,      /**<center*//**<CNcomment:���� */
    HI_UNF_VBI_CC_JUSTIFY_FULL,        /**<full*//**<CNcomment:���˶��� */
    HI_UNF_VBI_CC_JUSTIFY_BUTT
}HI_UNF_VBI_CC_JUSTIFY_E;


/**font style*//** CNcomment:������ */
typedef enum hiUNF_VBI_CC_FONTSTYLE_E
{
    HI_UNF_VBI_CC_FONTSTYLE_DEFAULT,         /**<default*//**<CNcomment:Ĭ�������� */
    HI_UNF_VBI_CC_FONTSTYLE_NORMAL,          /**<normal*//**<CNcomment:���� */
    HI_UNF_VBI_CC_FONTSTYLE_ITALIC,          /**<italic*//**<CNcomment:б�� */
    HI_UNF_VBI_CC_FONTSTYLE_UNDERLINE,       /**<underline*//**<CNcomment:�»��� */
    HI_UNF_VBI_CC_FONTSTYLE_ITALIC_UNDERLINE,/**<italic&underline*//**<CNcomment:б�岢�Ҵ��»��� */

    HI_UNF_VBI_CC_FONTSTYLE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_FONTSTYLE_E;

/**display format of caption display screen*//** CNcomment:��ʾ���ڵ���ʾģʽ */
typedef enum hiUNF_VBI_VBI_CC_DF_E
{
    HI_UNF_VBI_CC_DF_720X480,       /**<caption display screen is 720*480*//**<CNcomment:��ʾ���ڵĿ����720*480 */
    HI_UNF_VBI_CC_DF_720X576,       /**<caption display screen is 720*576*//**<CNcomment:��ʾ���ڵĿ����720*576 */
    HI_UNF_VBI_CC_DF_960X540,       /**<caption display screen is 960*540*//**<CNcomment:��ʾ���ڵĿ����960*540 */
    HI_UNF_VBI_CC_DF_1280X720,      /**<caption display screen is 1280*720*//**<CNcomment:��ʾ���ڵĿ����1280*720 */
    HI_UNF_VBI_CC_DF_1920X1080,     /**<caption display screen is 1920*1080*//**<CNcomment:��ʾ���ڵĿ����1920*1080 */

    HI_UNF_VBI_CC_DF_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
} HI_UNF_VBI_CC_DF_E;

/**CC display operation*//** CNcomment:CC��ʾ���� */
typedef enum hiUNF_VBI_CC_OPT_E
{
     HI_UNF_VBI_CC_OPT_DRAWTEXT = 0x1, /**<draw text *//**<CNcomment:�����ı� */
     HI_UNF_VBI_CC_OPT_DRAWBITMAP,     /**<draw bitmap *//**<CNcomment:����λͼ */
     HI_UNF_VBI_CC_OPT_FILLRECT,       /**<fill rect *//**<CNcomment:���������� */
     HI_UNF_VBI_CC_OPT_BUTT
} HI_UNF_VBI_CC_OPT_E;

/**CC rect*//** CNcomment:����CC��������*/
typedef struct hiUNF_VBI_CC_RECT_S
{
    HI_U16 x;           /**<x cordinate *//**<CNcomment:�������Ͻǵ�x���� */
    HI_U16 y;           /**<y cordinate *//**<CNcomment:�������Ͻǵ�y���� */
    HI_U16 width;       /**<rect width *//**<CNcomment:���εĿ�� */
    HI_U16 height;      /**<rect heigth *//**<CNcomment:���εĸ߶� */
}HI_UNF_VBI_CC_RECT_S;

/**CC color components*//** CNcomment:CC������ɫ�ṹ */
typedef struct hiUNF_VBI_CC_COLOR_S
{
    HI_U8 u8Blue;       /**<blue component *//**<CNcomment:B������ɫֵ */
    HI_U8 u8Green;      /**<green component *//**<CNcomment:G������ɫֵ */
    HI_U8 u8Red;        /**<red component *//**<CNcomment:R������ɫֵ */
    HI_U8 u8Alpha;      /**<alpha component *//**<CNcomment:͸���ȣ�ֵΪ0Ϊ͸����0xFFΪ��͸�� */
} HI_UNF_VBI_CC_COLOR_S;

/**font size*//** CNcomment:�����С */
typedef enum hiUNF_VBI_CC_FONTSIZE_E
{
    HI_UNF_VBI_CC_FONTSIZE_DEFAULT,       /**<default font size *//**<CNcomment:Ĭ�������С */
    HI_UNF_VBI_CC_FONTSIZE_SMALL,         /**<small*//**<CNcomment:С */
    HI_UNF_VBI_CC_FONTSIZE_STANDARD,      /**<standard*//**<CNcomment:��׼ */
    HI_UNF_VBI_CC_FONTSIZE_LARGE,         /**<large*//**<CNcomment:�� */

    HI_UNF_VBI_CC_FONTSIZE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
} HI_UNF_VBI_CC_FONTSIZE_E;

/**font edge type*//** CNcomment:�����Ե���� */
typedef enum hiUNF_VBI_CC_EdgeType_E
{
    HI_UNF_VBI_CC_EDGETYPE_DEFAULT,            /**<default *//**<CNcomment:Ĭ�������Ե���� */
    HI_UNF_VBI_CC_EDGETYPE_NONE,               /**<none edge type *//**<CNcomment:û�б�Ե */
    HI_UNF_VBI_CC_EDGETYPE_RAISED,             /**<raised *//**<CNcomment:��Եͻ�� */
    HI_UNF_VBI_CC_EDGETYPE_DEPRESSED,          /**<depressed *//**<CNcomment:��Ե���� */
    HI_UNF_VBI_CC_EDGETYPE_UNIFORM,            /**<uniform *//**<CNcomment:��Եͳһ */
    HI_UNF_VBI_CC_EDGETYPE_LEFT_DROP_SHADOW,   /**<left drop shadow *//**<CNcomment:������Ӱ */
    HI_UNF_VBI_CC_EDGETYPE_RIGHT_DROP_SHADOW,  /**<right drop shadow *//**<CNcomment:������Ӱ */

    HI_UNF_VBI_CC_EDGETYPE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_EdgeType_E;

/**CC data with text format*//** CNcomment:�ı���ʽ��CC���� */
typedef struct hiUNF_VBI_CC_TEXT_S
{
    HI_U16                 *pu16Text;    /**<cc data,2 bytes,unicode *//**<CNcomment:cc���ݣ�unicode���룬2���ֽ� */
    HI_U8                  u8TextLen;    /**<cc data length *//**<CNcomment:Ҫ��ʾ��cc���ݳ��� */

    HI_UNF_VBI_CC_COLOR_S      stFgColor;    /**<cc foregroud color*//**<CNcomment:Ҫ��ʾ��cc����ǰ��ɫ */
    HI_UNF_VBI_CC_COLOR_S      stBgColor;    /**<cc backgroud color*//**<CNcomment:Ҫ��ʾ��cc�������屳��ɫ */
    HI_UNF_VBI_CC_COLOR_S      stEdgeColor;   /**<cc edge color*//**<CNcomment:Ҫ��ʾ��cc���������Ե��ɫ*/

    HI_U8                  u8Justify;    /*see HI_UNF_CC_JUSTIFY_E,used when decode cc708*//**<CNcomment:cc������ʾʱ���Ű淽ʽ */
    HI_U8                  u8WordWrap;   /*see HI_UNF_CC_WORDWRAP_E,used when decode cc708*//**<CNcomment:�Զ����� */
    HI_UNF_VBI_CC_FONTSTYLE_E  enFontStyle;  /*font style ,see HI_UNF_CC_FONTSTYLE_E*//**<CNcomment:Ҫ��ʾ��cc���ݵ������� */
    HI_UNF_VBI_CC_FONTSIZE_E   enFontSize;   /*font size ,see HI_UNF_CC_FONTSIZE_E*//**<CNcomment:Ҫ��ʾ��cc���ݵ������С */
    HI_UNF_VBI_CC_EdgeType_E    enEdgetype;  /**<cc edge type*//**<CNcomment:Ҫ��ʾ��cc���������Ե����*/
} HI_UNF_VBI_CC_TEXT_S;

/**CC data with bitmap format*//** CNcomment:λͼ��ʽ��CC���� */
typedef struct hiUNF_VBI_CC_BITMAP_S
{
    HI_S32                 s32BitWidth;         /**<bit width, is 2/4/8/16/24/32 *//**<CNcomment:λ��,ֵ��2/4/8/16/24/32 */
    HI_U8                  *pu8BitmapData;      /**<pixel data *//**<CNcomment:ͼ������ */
    HI_U32                 u32BitmapDataLen;    /**<length of pixel data *//**<CNcomment:ͼ�����ݳ��� */
    HI_UNF_VBI_CC_COLOR_S      astPalette[256];     /**<palette data *//**<CNcomment:��ɫ������ */
    HI_U32                 u32PaletteLen;       /**<length of palette data *//**<CNcomment:��ɫ�����ݳ��� */
} HI_UNF_VBI_CC_BITMAP_S;

/**parameter of fill rect*//** CNcomment:����������Ĳ��� */
typedef struct hiUNF_VBI_CC_FILLRECT_S
{
    HI_UNF_VBI_CC_COLOR_S      stColor;      /**<color *//**<CNcomment:��ɫֵ */
} HI_UNF_VBI_CC_FILLRECT_S;

/**CC608 config param *//** CNcomment:CC608 ������Ϣ���� */
/**CC608 just support 8 stardard colors*//**CNcomment:CC608ֻ֧��8�ֱ�׼��ɫ*/
typedef struct hiUNF_VBI_CC_608_CONFIGPARAM_S
{
    HI_UNF_VBI_CC_608_DATATYPE_E    enCC608DataType;        /**<CC608 data type *//**<CNcomment:����cc608�������� */
    HI_U32                      u32CC608TextColor;      /**<CC608 text color *//**<CNcomment:����cc608������ɫ */
    HI_UNF_VBI_CC_OPACITY_E         enCC608TextOpac;        /**<CC608 text opacity *//**<CNcomment:����cc608����͸���� */
    HI_U32                      u32CC608BgColor;        /**<CC608 background color *//**<CNcomment:����cc608����ɫ */
    HI_UNF_VBI_CC_OPACITY_E         enCC608BgOpac;          /**<CC608 background opacity *//**<CNcomment:����cc608����͸���� */
    HI_UNF_VBI_CC_FONTSTYLE_E       enCC608FontStyle;       /**<CC608 font style *//**<CNcomment:����cc608������ */
    HI_UNF_VBI_CC_DF_E              enCC608DispFormat;      /**<CC608 display format of caption display screen *//**<CNcomment:����cc608��ʾģʽ */
    HI_BOOL                     bLeadingTailingSpace;   /**< CC608 leading/tailing space flag*//**<CNcomment: �Ƿ���ʾleading/tailing space*/
} HI_UNF_VBI_CC_608_CONFIGPARAM_S;

/**font name*/
/** CNcomment:������ʽ */
typedef enum  hiUNF_VBI_CC_FONTNAME_E
{
    HI_UNF_VBI_CC_FN_DEFAULT,                  /**<default *//**<CNcomment:Ĭ��������ʽ */
    HI_UNF_VBI_CC_FN_MONOSPACED,               /**<monospaced*//**<CNcomment:monospaced���� */
    HI_UNF_VBI_CC_FN_PROPORT,                  /**<proport*//**<CNcomment:proport���� */
    HI_UNF_VBI_CC_FN_MONOSPACED_NO_SERIAFS,    /**<monospaced with no seriafs*//**<CNcomment:monospaced����(�޳���) */
    HI_UNF_VBI_CC_FN_PROPORT_NO_SERIAFS,       /**<proport with no seriafs*//**<CNcomment:proport����(�޳���) */
    HI_UNF_VBI_CC_FN_CASUAL,                   /**<casual*//**<CNcomment:casual���� */
    HI_UNF_VBI_CC_FN_CURSIVE,                  /**<cursive*//**<CNcomment:cursive���� */
    HI_UNF_VBI_CC_FN_SMALL_CAPITALS,           /**<small capitals*//**<CNcomment:Сд���� */

    HI_UNF_VBI_CC_FN_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_FONTNAME_E;

/**708CC service channel*//** CNcomment:708CC�ķ���ͨ����*/
typedef enum hiUNF_VBI_CC_708_SERVICE_NUM_E
{
    HI_UNF_VBI_CC_708_SERVICE1 = 0x1, /**<708CC service 1*//**<CNcomment:708CC����1 */
    HI_UNF_VBI_CC_708_SERVICE2,       /**<708CC service 2*//**<CNcomment:708CC����2 */
    HI_UNF_VBI_CC_708_SERVICE3,       /**<708CC service 3*//**<CNcomment:708CC����3 */
    HI_UNF_VBI_CC_708_SERVICE4,       /**<708CC service 4*//**<CNcomment:708CC����4 */
    HI_UNF_VBI_CC_708_SERVICE5,       /**<708CC service 5*//**<CNcomment:708CC����5 */
    HI_UNF_VBI_CC_708_SERVICE6,       /**<708CC service 6*//**<CNcomment:708CC����6 */

    HI_UNF_VBI_CC_708_SERVICE_BUTT      /**<Invalid value*/            /**<CNcomment:�Ƿ�ֵ*/
}HI_UNF_VBI_CC_708_SERVICE_NUM_E;

/**CC708 config param *//** CNcomment:CC708 ������Ϣ���� */
/**CC708 support 64 colors.one of RGB color components can be 0x00,0x5f,0xaf,0xff*//**CNcomment:CC708֧��64����ɫ,һ��RGB������ȡ��ֵ��0x00,0x5f,0xaf,0xff��4��*/
typedef struct hiUNF_VBI_CC_708_CONFIGPARAM_S
{
    HI_UNF_VBI_CC_708_SERVICE_NUM_E enCC708ServiceNum;      /**<CC708 service number *//**<CNcomment:����cc708����ͨ���� */
    HI_UNF_VBI_CC_FONTNAME_E        enCC708FontName;        /**<CC708 font name *//**<CNcomment:����cc708���� */
    HI_UNF_VBI_CC_FONTSTYLE_E       enCC708FontStyle;       /**<CC708 font style *//**<CNcomment:����cc708������ */
    HI_UNF_VBI_CC_FONTSIZE_E        enCC708FontSize;        /**<CC708 font size *//**<CNcomment:����cc708�����С */
    HI_U32                      u32CC708TextColor;      /**<CC708 text color *//**<CNcomment:����cc708������ɫ */
    HI_UNF_VBI_CC_OPACITY_E         enCC708TextOpac;        /**<CC708 text opacity *//**<CNcomment:����cc708����͸���� */
    HI_U32                      u32CC708BgColor;        /**<CC708 background color *//**<CNcomment:����cc708������ɫ */
    HI_UNF_VBI_CC_OPACITY_E         enCC708BgOpac;          /**<CC708 background opacity *//**<CNcomment:����cc708����͸���� */
    HI_U32                      u32CC708WinColor;       /**<CC708 window color *//**<CNcomment:����cc708������ɫ */
    HI_UNF_VBI_CC_OPACITY_E         enCC708WinOpac;         /**<CC708 window opacity *//**<CNcomment:����cc708����͸���� */
    HI_UNF_VBI_CC_EdgeType_E        enCC708TextEdgeType;    /**<CC708 text egde type *//**<CNcomment:����cc708�����Ե���� */
    HI_U32                      u32CC708TextEdgeColor;  /**<CC708 text edge color *//**<CNcomment:����cc708�����Ե��ɫ */
    HI_UNF_VBI_CC_DF_E              enCC708DispFormat;      /**<CC708 display format of caption display screen *//**<CNcomment:����cc708��ʾģʽ */
} HI_UNF_VBI_CC_708_CONFIGPARAM_S;

/**ARIB CC config param *//** CNcomment:ARIB CC ������Ϣ���� */
typedef struct hiUNF_VBI_CC_ARIB_CONFIGPARAM_S
{
    HI_U32      u32BufferSize;   /**<size of buffer which used to cache pes data,Recommends its value is 64K ~ 512K.note:This value can only be set when created,does not support dynamic setting*/
                                 /**<CNcomment:����PES���ݵĻ�������С��ȡֵΪ64k~512K��ע��:���ֵֻ���ڴ���ʱ���ã���֧�ֶ�̬����*/
} HI_UNF_VBI_CC_ARIB_CONFIGPARAM_S;

/**CC data attribution */
/** CNcomment:CC������Ϣ */
typedef struct hiUNF_VBI_CC_ATTR_S
{
    HI_UNF_VBI_CC_DATA_TYPE_E enCCDataType;   /**<cc data type *//**<CNcomment:cc�������� */
    union
    {
        HI_UNF_VBI_CC_608_CONFIGPARAM_S  stCC608ConfigParam;   /**<CC608 config param *//**<CNcomment:CC608 ������Ϣ���� */
        HI_UNF_VBI_CC_708_CONFIGPARAM_S  stCC708ConfigParam;   /**<CC708 config param *//**<CNcomment:CC708 ������Ϣ���� */
        HI_UNF_VBI_CC_ARIB_CONFIGPARAM_S stCCARIBConfigParam;  /**<ARIB CC config param *//**<CNcomment:ARIB CC ������Ϣ���� */
    } unConfig;
} HI_UNF_VBI_CC_ATTR_S;

/** CNcomment:VBI�ź���Ϣ*/
typedef struct hiUNF_VBI_ATTR_S
{
    HI_UNF_VBI_SIG_TYPE_E enVbiType;                /**<Signal transmission type*/    /**<CNcomment:�ź�����*/

    union
    {
        HI_UNF_VBI_CC_ATTR_S         stCC;         /**<Signal info of cc*/    /**<CNcomment:closed caption������Ϣ*/
        HI_UNF_VBI_CC_ATTR_S         stTT;         /**<Signal info of tt*/     /**<CNcomment:Teletext ������Ϣ*/
        HI_UNF_VBI_CC_ATTR_S         stWSS;        /* wss���ò���*/
        HI_UNF_VBI_CC_ATTR_S         stVPS;        /* vps���ò�������*/
    } unAttr;
} HI_UNF_VBI_ATTR_S;

/**CC data*/
/** CNcomment:CC�ź�������Ϣ*/
typedef struct hiUNF_VBI_CC_DATA_S
{
    HI_BOOL boddevenflag;         /**<parity field flag*/ /**<CNcomment:��ż�� ��־λ*/
	HI_U16 u16VbiData;            /**<cc data   */ /**<CNcomment:cc����*/
    HI_U32 u32LineCnt;            /**<Line Count  */ /**<CNcomment:cc�м���*/
    HI_U32 u32VSyncCnt;           /**<Vsync Count  */ /**<CNcomment:cc���жϼ���*/
	HI_U32 u32DataSize ;          /**<cc data  size  */ /**<CNcomment:cc���ݴ�С*/
}HI_UNF_VBI_CC_DATA_S;

/** CNcomment:TT�ź�������Ϣ*/
typedef struct hiUNF_VBI_TT_DATA_S
{
   HI_U32 u32BufPhyAddr;            /**<Teletxt Signal buffer physical address*/    /**<CNcomment:�źŻ������뵽���׵�ַ*/
   HI_U32 u32BufSize;               /**<Teletxt Signal buffer size*/    /**<CNcomment:�źŻ����С*/
   HI_U32 u32PreBufWritePhyAddr;    /**<Previous  buffer physical address*/    /**<CNcomment:֮ǰд�������ַ*/
   HI_U32 u32BufWritePhyAddr;       /**<Current buffer physical address*/    /**<CNcomment:��ǰд�������ַ*/
}HI_UNF_VBI_TT_DATA_S;

/** CNcomment:WSS�ź�������Ϣ*/
typedef struct hiUNF_VBI_WSS_DATA_S
{
   HI_U32 u32Data;            /**<wss data*/    /**<CNcomment WSS �ź�����*/
}HI_UNF_VBI_WSS_DATA_S;

/** CNcomment:VPS�ź�������Ϣ*/
typedef struct hiUNF_VBI_VPS_DATA_S
{
   HI_U32 u32Data;            /**<vps data*/    /**<CNcomment VPS �ź�����*/
}HI_UNF_VBI_VPS_DATA_S;

typedef struct hiUNF_VBI_TT_INFO_S
{
    HI_BOOL boddevenflag;         /**<parity field flag*/ /**<CNcomment:��ż�� ��־λ*/

    HI_U32 u32LineCnt;            /**<tt line count*/ /**<CNcomment:TT �ź��м���*/
    HI_U32 u32VSyncCnt;           /**<tt Vsync count*/ /**<CNcomment:TT �źų�����*/
}HI_UNF_VBI_TT_INFO_S;

/** CNcomment:VBI�ź���Ϣ*/
typedef struct hiUNF_VBI_SIGNALINFO_S
{
    HI_UNF_VBI_SIG_TYPE_E enVbiType;                /**<Signal transmission type*/    /**<CNcomment:�ź�����*/

    union
    {
        HI_UNF_VBI_CC_DATA_S         stCC;         /**<Signal info of cc*/    /**<CNcomment:�ź���Ϣ*/
        HI_UNF_VBI_TT_DATA_S         stTT;         /**<Signal info of tt*/     /**<CNcomment:�ź���Ϣ*/
        HI_UNF_VBI_WSS_DATA_S        stWSS;        /* wss�ź���Ϣ*/
        HI_UNF_VBI_VPS_DATA_S        stVPS;        /* vps�źŲ���*/
    } unSignalInfo;
} HI_UNF_VBI_SIGNALINFO_S;

/** @} */  /** <!-- ==== Structure Definition end ==== */

/******************************* API Declaration *****************************/
/** \addtogroup      VBI */
/** @{ */  /** <!-- [VBI] */
/**
\brief Initialize VBI module. CNcomment: ��ʼ��VBIģ�顣CNend
\attention \n
none. CNcomment: �ޡ�CNend
\retval ::HI_SUCCESS initialize success. CNcomment: ��ʼ���ɹ���CNend
\retval ::HI_FAILURE initialize failure. CNcomment: ��ʼ��ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_Init(HI_VOID);


/**
\brief DeInitialize VBI module. CNcomment: ȥ��ʼ��VBIģ�顣CNend
\attention \n
none. CNcomment: �ޡ�CNend
\retval ::HI_SUCCESS deinitialize success. CNcomment: ȥ��ʼ���ɹ���CNend
\retval ::HI_FAILURE deinitialize failure. CNcomment: ȥ��ʼ��ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_DeInit(HI_VOID);


/**
\brief start VBI module. CNcomment: ��ʼVBIģ�顣CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  enType  Signal type of the VBI. CNcomment: VBI �ź�����CNend
\param[in]  enSrcType Select VBI WorkMode for TVD or HDDEC.CNcomment:ѡ��VBI������Դ����TVD��CVBS�źŻ�������HDDEC�ĸ����ź�CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_Connect(HI_UNF_VBI_SRC_ATTR_S *pstSrcAttr);


/**
\brief stop VBI module. CNcomment: ����VBIģ�顣CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  hVBI  VBI handle. CNcomment: ģ������CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_DisConnect(HI_VOID);


/**
\brief reset VBI module. CNcomment: ��λVBIģ�顣CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  hVBI  VBI handle. CNcomment: ģ������CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_Reset(HI_VOID);


/**
\brief Get VBI Signal Information . CNcomment:��ȡVBI�ź���Ϣ��CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  pstVbiAttr  cc signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_GetSignalInfo(HI_UNF_VBI_SIGNALINFO_S *pstVbiAttr);


/**
\brief Get VBI Signal Information . CNcomment:��ȡCC Buffer���ݡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  pstVbiAttr  cc signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_AcquireCCBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_CC_DATA_S **pstCCData);

	
/**
\brief Get VBI Signal Information . CNcomment:��ȡTT Buffer ���ݡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  u32AcquireNum  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\param[in]  pu32AcquiredNum  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\param[in]  pu8Data  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_AcquireTTBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_U8 *pu8Data);

/**
\brief Get VBI Signal Information . CNcomment:��ȡTT Buffer ��Ϣ��CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  u32AcquireNum  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\param[in]  pu32AcquiredNum  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\param[in]  pstTTData  tt signal information structure. CNcomment:VBI �ź���Ϣ�ṹ�塣CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_AcquireTTInfoBuf(HI_U32 u32AcquireNum,HI_U32 *pu32AcquiredNum,HI_UNF_VBI_TT_INFO_S **pstTTData);

/**
\brief set VBI attribution before connect vbi module. CNcomment:��ȡVBIģ���ֽ�����ת�����ԡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  bDataInvEn  cc attribution flag. CNcomment�����Ƿ�����ת��־CNend
\param[in]  bByteInvEn  cc attribution flag. CNcomment�����Ƿ��ֽڷ�ת��־CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_SetDataInvEN(HI_BOOL bDataInvEn,HI_BOOL bByteInvEn);


/**
\brief Get data byte invert attribution in VBI module. CNcomment: ��ȡVBIģ���ֽ�����ת�����ԡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  bDataInvEn  cc attribution flag. CNcomment�����Ƿ�����ת��־CNend
\param[in]  bByteInvEn  cc attribution flag. CNcomment�����Ƿ��ֽڷ�ת��־CNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_GetDataInvEN(HI_BOOL *bDataInvEn,HI_BOOL *bByteInvEn);

/**
\brief set VBI attribution before connect vbi module. CNcomment:����VBIģ��QTC����ʹ�ܡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  bQtcEn  tt attribution flag. CNcomment:QTC�Ƿ����ʹ�ܱ�־λCNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_SetQtcEn(HI_BOOL bQtcEn);

/**
\brief set VBI attribution before connect vbi module. CNcomment:��ȡVBIģ��QTC�����Ƿ�ʹ�ܡ�CNend
\attention \n
none. CNcomment: �ޡ�CNend
\param[in]  bQtcEn  tt attribution flag. CNcomment:QTC�Ƿ����ʹ�ܱ�־λCNend
\retval ::HI_SUCCESS success. CNcomment: �ɹ���CNend
\retval ::HI_FAILURE failure. CNcomment: ʧ�ܡ�CNend
\see \n
none. CNcomment: �ޡ�CNend
*/
HI_S32 HI_UNF_VBI_GetQtcEn(HI_BOOL *bQtcEn);

/** @} */  /** <!-- ==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_VBI_H__ */

