/******************************************************************************

   Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
   File Name     : hi_unf_panel.h
   Version       : Initial Draft
   Author        : Hisilicon multimedia software group
   Created       : 2013/10/31
   Description   :
   History       :
   1.Date        : 2013/10/31
     Author      : z00208650

    Modification: Created file

 *******************************************************************************/


#ifndef  __HI_UNF_PANEL_H__
#define  __HI_UNF_PANEL_H__

/* add include here */
#include "hi_unf_disp.h"
#include "hi_unf_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

/*************************** Structure Definition ****************************/
/** \addtogroup      PANEL */
/** @{ */  /** <!-- [PANEL] */

/**LVDS voltage *//**CNcomment:LVDS��ģ��ѹ  */
typedef enum hiUNF_PANEL_LVDS_VOLTAGE_E
{
    HI_UNF_PANEL_LVDS_VOLTAGE_1250MV = 0,   /**<LVDS voltage value 1250MV*/ /**<CNcomment:LVDS ��ģ��ѹ1250MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1100MV,       /**<LVDS voltage value 1100MV*/ /**<CNcomment:LVDS ��ģ��ѹ1100MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1150MV,       /**<LVDS voltage value 1150MV*/ /**<CNcomment:LVDS ��ģ��ѹ1150MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1200MV,       /**<LVDS voltage value 1200MV*/ /**<CNcomment:LVDS ��ģ��ѹ1200MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1300MV,       /**<LVDS voltage value 1300MV*/ /**<CNcomment:LVDS ��ģ��ѹ1300MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1350MV,       /**<LVDS voltage value 1350MV*/ /**<CNcomment:LVDS ��ģ��ѹ1350MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1400MV,       /**<LVDS voltage value 1400MV*/ /**<CNcomment:LVDS ��ģ��ѹ1400MV */
    HI_UNF_PANEL_LVDS_VOLTAGE_1450MV,       /**<LVDS voltage value 1450MV*/ /**<CNcomment:LVDS ��ģ��ѹ1450MV */

    HI_UNF_PANEL_LVDS_VOLTAGE_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LVDS_VOLTAGE_E;


/**LVDS current *//**CNcomment:LVDS��������  */
typedef enum hiUNF_PANEL_LVDS_CURRENT_E
{
    HI_UNF_PANEL_LVDS_CURRENT_200MV = 0,    /**<LVDS current value 200MV*/ /**<CNcomment:LVDS ��������200MV */
    HI_UNF_PANEL_LVDS_CURRENT_150MV,        /**<LVDS current value 150MV*/ /**<CNcomment:LVDS ��������150MV */
    HI_UNF_PANEL_LVDS_CURRENT_250MV,        /**<LVDS current value 250MV*/ /**<CNcomment:LVDS ��������250MV */
    HI_UNF_PANEL_LVDS_CURRENT_300MV,        /**<LVDS current value 300MV*/ /**<CNcomment:LVDS ��������300MV */
    HI_UNF_PANEL_LVDS_CURRENT_350MV,        /**<LVDS current value 350MV*/ /**<CNcomment:LVDS ��������350MV */
    HI_UNF_PANEL_LVDS_CURRENT_400MV,        /**<LVDS current value 400MV*/ /**<CNcomment:LVDS ��������400MV */
    HI_UNF_PANEL_LVDS_CURRENT_450MV,        /**<LVDS current value 450MV*/ /**<CNcomment:LVDS ��������450MV */
    HI_UNF_PANEL_LVDS_CURRENT_500MV,        /**<LVDS current value 500MV*/ /**<CNcomment:LVDS ��������500MV */

    HI_UNF_PANEL_LVDS_CURRENT_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LVDS_CURRENT_E;


/**LVDS spread frequency *//**CNcomment:LVDSչƵƵ��  */
typedef enum hiUNF_PANEL_LVDS_SSFREQ_E
{
    HI_UNF_PANEL_LVDS_SSFREQ_93P75KHZ   = 2,    /**<LVDS spread frequency 93P75KHZ*/ /**<CNcomment:LVDSչƵƵ��93P75KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_62P5KHZ    = 3,    /**<LVDS spread frequency 62P5KHZ*/ /**<CNcomment:LVDSչƵƵ��62P5KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_46P875KHZ  = 4,    /**<LVDS spread frequency 46P875KHZ*/ /**<CNcomment:LVDSչƵƵ��46P875KHZ */
    HI_UNF_PANEL_LVDS_SSFREQ_37P5KHZ    = 5,    /**<LVDS spread frequency 37P5KHZ*/ /**<CNcomment:LVDSչƵƵ��37P5KHZ */

    HI_UNF_PANEL_LVDS_SSFREQ_BUTT,              /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LVDS_SSFREQ_E;

/**VBO spread frequency *//**CNcomment:VBOչƵƵ��  */
typedef enum hiUNF_PANEL_VBO_SSFREQ_E
{
    HI_UNF_PANEL_VBO_SSFREQ_46P875KHZ   = 2,    /**<VBO spread frequency 46P875KHZ*/ /**<CNcomment:VBOչƵƵ��46P875KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_31P250KHZ   = 3,    /**<VBO spread frequency 31P250KHZ*/ /**<CNcomment:VBOչƵƵ��31P250KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_23P438KHZ   = 4,    /**<VBO spread frequency 23P438KHZ*/ /**<CNcomment:VBOչƵƵ��23P438KHZ */
    HI_UNF_PANEL_VBO_SSFREQ_18P750KHZ   = 5,    /**<VBO spread frequency 18P750KHZ*/ /**<CNcomment:VBOչƵƵ��18P750KHZ */

    HI_UNF_PANEL_VBO_SSFREQ_BUTT,               /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_VBO_SSFREQ_E;

typedef struct hiUNF_PANEL_3DATTR_RANGE_S
{
    HI_RANGE_S stDepthRange;
    HI_RANGE_S stViewRange;
    
}HI_UNF_PANEL_3DATTR_RANGE_S;

/**Panel flip type *//**CNcomment:Panel�ķ�ת����*/
typedef enum hiUNF_PANEL_FLIP_TYPE_E
{
    HI_UNF_PANEL_FLIP_TYPE_NONE = 0,     /**<Panel flip type is none*/ /**<CNcomment: normal */
    HI_UNF_PANEL_FLIP_TYPE_FLIP,         /**<Panel flip type is flip*/ /**<CNcomment: only flip*/
    HI_UNF_PANEL_FLIP_TYPE_MIRROR,       /**<Panel flip type is mirror*/ /**<CNcomment: only mirror */
	HI_UNF_PANEL_FLIP_TYPE_FLIP_MIRROR,  /**<Panel flip type is flip & mirror*/ /**<CNcomment: flip and mirror  */
	
    HI_UNF_PANEL_FLIP_TYPE_BUTT,
} HI_UNF_PANEL_FLIP_TYPE_E;

/**Panel link type *//**CNcomment:Panel���������� */
typedef enum hiUNF_PANEL_LINKTYPE_E
{
    HI_UNF_PANEL_LINKTYPE_1LINK = 0,    /**<Panel link type is 1 link*/ /**<CNcomment:Panel����������Ϊ1��Link */
    HI_UNF_PANEL_LINKTYPE_2LINK,        /**<Panel link type is 2 link*/ /**<CNcomment:Panel����������Ϊ2��Link */
    HI_UNF_PANEL_LINKTYPE_4LINK,        /**<Panel link type is 4 link*/ /**<CNcomment:Panel����������Ϊ4��Link */
    HI_UNF_PANEL_LINKTYPE_8LINK,        /**<Panel link type is 8 link*/ /**<CNcomment:Panel����������Ϊ8��Link */
    
    HI_UNF_LVDS_LINKTYPE_BUTT,          /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LINKTYPE_E;

/**LVDS link map *//**CNcomment:Panel �ӿ�ΪLVDSʱÿһ��Link��������� */
typedef enum hiUNF_PANEL_LVDS_LINKMAP_E
{
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL0 = 0,   /**<output pixel 0 */ /**<CNcomment:������� 0+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL1,       /**<output pixel 1 */ /**<CNcomment:������� 1+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL2,       /**<output pixel 2 */ /**<CNcomment:������� 2+4*n */
    HI_UNF_PANEL_LVDS_LINKMAP_PIXEL3,       /**<output pixel 3 */ /**<CNcomment:������� 3+4*n */

    HI_UNF_PANEL_LVDS_LINKMAP_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LVDS_LINKMAP_E;

/**LVDS link map *//**CNcomment:Panel �ӿ�ΪLVDSʱ��Link����������ص�һ����� */
typedef struct hiUNF_PANEL_LVDS_LINKMAP_S
{
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink1;    /**<Link 1 */ /**<CNcomment:��1��Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink2;    /**<Link 2 */ /**<CNcomment:��2��Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink3;    /**<Link 3 */ /**<CNcomment:��3��Link */
    HI_UNF_PANEL_LVDS_LINKMAP_E enLink4;    /**<Link 4 */ /**<CNcomment:��4��Link */
} HI_UNF_PANEL_LVDS_LINKMAP_S;


/**LVDS bit width *//**CNcomment:LVDS������λ�� */
typedef enum hiUNF_PANEL_BITWIDTH_E
{
    HI_UNF_PANEL_BITWIDTH_8BIT = 0,     /**<bit width is 8 */ /**<CNcomment:λ��Ϊ8 */
    HI_UNF_PANEL_BITWIDTH_10BIT,        /**<bit width is 10 */ /**<CNcomment:λ��Ϊ10 */
    HI_UNF_PANEL_BITWIDTH_12BIT,        /**<bit width is 12 */ /**<CNcomment:λ��Ϊ12 */

    HI_UNF_PANEL_BITWIDTH_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_BITWIDTH_E;


/**LVDS format *//**CNcomment:LVDS�ĸ�ʽ */
typedef enum hiUNF_PANEL_LVDS_FMT_E
{
    HI_UNF_PANEL_LVDS_FMT_VESA = 0,     /**<LVDS format:VESA */ /**<CNcomment:LVDS��ʽΪVESA */
    HI_UNF_PANEL_LVDS_FMT_JEIDA,        /**<LVDS format:JEIDA  */ /**<CNcomment:LVDS��ʽΪJEIDA */
    HI_UNF_PANEL_LVDS_FMT_FP,           /**<LVDS format:FP  */ /**<CNcomment:LVDS��ʽΪFP */

    HI_UNF_PANEL_LVDS_FMT_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_LVDS_FMT_E;


/**Screen data type *//**CNcomment:����������������� */
typedef enum hiUNF_PANEL_PANEL_TYPE_E
{
    HI_UNF_PANEL_TYPE_FHD = 0,           /**<only support FHD output */ /**<CNcomment:ֻ֧��FHD��� */
    HI_UNF_PANEL_TYPE_4K,                /**<only support UHD output */ /**<CNcomment:ֻ֧��UHD 4k��� */
	  HI_UNF_PANEL_TYPE_FHD_4K_30_MISC,	 /**<support FHD and UHD 30 output */ /**<CNcomment: ֧��FHD 50/60 ��UHD24/25/30������ */
	  HI_UNF_PANEL_TYPE_FHD_4K_60_MISC,	 /**<support FHD and UHD 60 output */ /**<CNcomment: ֧��FHD 50/60 ��UHD50/60������ */
	  HI_UNF_PANEL_TYPE_4K_30_60_MISC,	 /**<support UHD Misc output */ /**<CNcomment: ֧��UHD 24/25/30/50/60������ */
	  HI_UNF_PANEL_TYPE_FHD_4K_30_60_MISC, /**<support FHD and UHD Misc output */ /**<CNcomment: ֧��FHD 50/60 ��UHD24/25/30/50/60������ */
    
    HI_UNF_PANEL_TYPE_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_TYPE_E;

/**Panel timing info *//**CNcomment:Panel ��timing��Ϣ */
typedef struct hiUNF_PANEL_TIMING_S
{
    HI_U32 u32PixelClk;     /**<output pixel clock */ /**<CNcomment:���������ʱ�� */
    HI_U32 u32Htotal;       /**<output Horizontal Frequency */ /**<CNcomment:�������Ƶ */
    HI_U32 u32Vtotal;       /**<output Vertical  Frequency */ /**<CNcomment:����ĳ�Ƶ */
    HI_U16 u16HsyncFP;      /**<hsync fp *//**CNcomment:Hsync ǰ���� */
    HI_U16 u16VsyncFP;      /**<vsync fp *//**CNcomment:Vsync ǰ���� */
    
}HI_UNF_PANEL_TIMING_S;

/**VBO data mode *//**CNcomment:VBO�����ݸ�ʽ */
typedef enum hiUNF_PANEL_VBO_DATAMODE_E
{
    HI_UNF_PANEL_VBO_DATAMODE_30BIT444 = 0, /**<VBO data mode is 30BIT444 */ /**<CNcomment:��ʽΪ30BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_36BIT444,     /**<VBO data mode is 36BIT444 */ /**<CNcomment:��ʽΪ36BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_24BIT444,     /**<VBO data mode is 24BIT444 */ /**<CNcomment:��ʽΪ24BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_18BIT444,     /**<VBO data mode is 18BIT444 */ /**<CNcomment:��ʽΪ18BIT444 */
    HI_UNF_PANEL_VBO_DATAMODE_24BIT422,     /**<VBO data mode is 24BIT422 */ /**<CNcomment:��ʽΪ24BIT422 */
    HI_UNF_PANEL_VBO_DATAMODE_20BIT422,     /**<VBO data mode is 20BIT422 */ /**<CNcomment:��ʽΪ20BIT422 */
    HI_UNF_PANEL_VBO_DATAMODE_16BIT422,     /**<VBO data mode is 16BIT422 */ /**<CNcomment:��ʽΪ16BIT422 */

    HI_UNF_PANEL_VBO_DATAMODE_BUTT,         /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_VBO_DATAMODE_E;

/**VBO pixel byte *//**CNcomment:VBOÿ������ռ���ֽ���*/
typedef enum hiUNF_PANEL_VBO_BYTE_NUM_E
{
    HI_UNF_PANEL_VBO_BYTE_NUM_3 = 3,    /**<pixel 3 byte */ /**<CNcomment:ÿ������ռ3���ֽ� */
    HI_UNF_PANEL_VBO_BYTE_NUM_4 = 4,    /**<pixel 3 byte */ /**<CNcomment:ÿ������ռ4���ֽ� */
    HI_UNF_PANEL_VBO_BYTE_NUM_5 = 5,    /**<pixel 5 byte */ /**<CNcomment:ÿ������ռ5���ֽ� */

    HI_UNF_PANEL_VBO_BYTE_NUM_BUTT,     /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_VBO_BYTE_NUM;


/**VBO current *//**CNcomment:VBO��������*/
typedef enum hiUNF_PANEL_VBO_CURRENT_E
{
    HI_UNF_PANEL_VBO_CURRENT_300MV = 0, /**<current is 300MV */ /**<CNcomment:��������Ϊ300MV */
    HI_UNF_PANEL_VBO_CURRENT_200MV,     /**<current is 200MV */ /**<CNcomment:��������Ϊ200MV */
    HI_UNF_PANEL_VBO_CURRENT_250MV,     /**<current is 250MV */ /**<CNcomment:��������Ϊ250MV */
    HI_UNF_PANEL_VBO_CURRENT_350MV,     /**<current is 350MV */ /**<CNcomment:��������Ϊ350MV */
    HI_UNF_PANEL_VBO_CURRENT_400MV,     /**<current is 400MV */ /**<CNcomment:��������Ϊ400MV */

    HI_UNF_PANEL_VBO_CURRENT_BUTT,      /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_VBO_CURRENT_E;


/**VBO Pre-emphasis *//**CNcomment:VBOԤ����*/
typedef enum hiUNF_PANEL_VBO_EMP_E
{
    HI_UNF_PANEL_VBO_EMP_0DB = 0,   /**<Pre-emphasis is 0DB */ /**<CNcomment:Ԥ����Ϊ0DB */
    HI_UNF_PANEL_VBO_EMP_2DB,       /**<Pre-emphasis is 3P5DB */ /**<CNcomment:Ԥ����Ϊ2DB */
    HI_UNF_PANEL_VBO_EMP_3P5DB,     /**<Pre-emphasis is 3P5DB */ /**<CNcomment:Ԥ����Ϊ3P5DB */
    HI_UNF_PANEL_VBO_EMP_6DB,       /**<Pre-emphasis is 6DB */ /**<CNcomment:Ԥ����Ϊ6DB */
    HI_UNF_PANEL_VBO_EMP_BUTT,      /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_VBO_EMP_E;


/**Panel interface type *//**CNcomment:Panel �Ľӿ�����*/
typedef enum hiUNF_PANEL_INTFTYPE_E
{
    HI_UNF_PANEL_PANEL_INTFTYPE_LVDS = 0,   /**<interface type is LVDS */ /**<CNcomment:�ӿ�����ΪLVDS */
    HI_UNF_PANEL_PANEL_INTFTYPE_VBONE,      /**<interface type is VBONE */ /**<CNcomment:�ӿ�����ΪVBONE */
    HI_UNF_PANEL_PANEL_INTFTYPE_MINLVDS,    /**<interface type is MINLVDS */ /**<CNcomment:�ӿ�����ΪMINLVDS */

    HI_UNF_PANEL_PANEL_INTFTYPE_BUTT,       /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
} HI_UNF_PANEL_INTFTYPE_E;

/**VBO interface attr *//**CNcomment:VBO �Ľӿ�����*/
typedef struct hiUNF_PANEL_VBOATTR_S
{
    HI_BOOL bGroupSwap;                             /**<screen left and right swap */ /**<CNcomment:����������Ұ������ݻ��� */
    HI_BOOL bLeftInternalSwap;                      /**<screen left internal swap */ /**<CNcomment:Lane0~3�ڲ������ݻ���, �����������ż���� */
    HI_BOOL bRightInternalSwap;                     /**<screen right internal swap */ /**<CNcomment:Lane4~7�ڲ������ݻ���, ���Ұ�������ż���� */
    HI_BOOL bBit0AtHighBit;                         /**<bit 0 at high bit */ /**<CNcomment:Bit0�Ƿ������λ,Ĭ����False */
    HI_UNF_PANEL_VBO_DATAMODE_E enDataMode;         /**<vbo data format */ /**<CNcomment:Vbone���ݸ�ʽ */
    HI_UNF_PANEL_VBO_BYTE_NUM   enVb1ByteNum;       /**<vbo pixel byte */ /**<CNcomment:Vboneÿ�����ص��ֽ��� */
    HI_UNF_PANEL_VBO_CURRENT_E  enVb1Current;       /**<Vbone Swing */ /**<CNcomment:Vbone��������ֵ */
    HI_UNF_PANEL_VBO_EMP_E      enVb1Emphasis;      /**<Vbone Pre-emphasis */ /**<CNcomment:VboneԤ���� */
    HI_U32                      u32Vb1SpreadRatio;  /**<Vb1 Spread Ratio from 0 to 31 */ /**<CNcomment:Vboneչ���� */
    HI_UNF_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;    /**<VBO spread frequency */ /**<CNcomment:VBOչƵƵ�� */
    
}HI_UNF_PANEL_VBOATTR_S;


/**LVDS interface attr *//**CNcomment:LVDS �Ľӿ�����*/
typedef struct hiUNF_PANEL_LVDSATTR_S
{
    HI_U32                       u32LvdsSpreadRatio;    /**<Spread Ratio from 0 to 31 */ /**<CNcomment:չƵ�ı���(10 ��ʾ 1% ) [0-31] */
    HI_UNF_PANEL_LVDS_SSFREQ_E   enLvdsSpreadFreq;      /**<spread frequency */ /**<CNcomment:չƵ��Ƶ��(��λ: KHz) */
    HI_UNF_PANEL_LVDS_FMT_E      enLvdsFmt;             /**<format */ /**<CNcomment:LVDS�ĸ�ʽ */
    HI_UNF_PANEL_LVDS_LINKMAP_S  stLvdsLinkMap;         /**<Lvds link map */ /**<CNcomment:LVDS 4��Link��24����� */
    HI_UNF_PANEL_LVDS_CURRENT_E  enLvdsDrvCurrent;      /**<LVDS Swing */ /**<CNcomment:LVDS �������� */
    HI_UNF_PANEL_LVDS_VOLTAGE_E  enLvdsComVoltage;      /**<LVDS voltage */ /**<CNcomment:LVDS ��ģ��ѹ */

        
}HI_UNF_PANEL_LVDSATTR_S;


/**panel interface attr *//**CNcomment:panel �Ľӿ�����*/
typedef struct hiUNF_PANEL_INTF_ATTR_S
{   
    HI_BOOL                     bIntfEnable;        /**<interface enable */ /**<CNcomment:�ӿ�ʹ�� */
    HI_BOOL                     bSpreadEnable;      /**<spread enable */ /**<CNcommentչ��ʹ�� */

    HI_U32                      u32LvdsSpreadRatio; /**<Spread Ratio from 0 to 31 */ /**<CNcomment:չƵ�ı���(10 ��ʾ 1% ) [0-31] */
    HI_UNF_PANEL_LVDS_SSFREQ_E  enLvdsSpreadFreq;   /**<spread frequency */ /**<CNcomment:չƵ��Ƶ��(��λ: KHz) */
    HI_UNF_PANEL_LVDS_CURRENT_E enLvdsDrvCurrent;   /**<LVDS Swing */ /**<CNcomment:LVDS �������� */
    HI_UNF_PANEL_LVDS_VOLTAGE_E enLvdsComVoltage;   /**<LVDS voltage */ /**<CNcomment:LVDS ��ģ��ѹ */
    
    HI_U32                      u32Vb1SpreadRatio;  /**<Vb1 Spread Ratio from 0 to 31 */ /**<CNcomment:Vboneչ���� */
    HI_UNF_PANEL_VBO_SSFREQ_E   enVb1SpreadFreq;    /**<VBO spread frequency */ /**<CNcomment:VBOչƵƵ�� */
    HI_UNF_PANEL_VBO_CURRENT_E  enVb1Current;       /**<Vbone Swing */ /**<CNcomment:Vbone��������ֵ */
    HI_UNF_PANEL_VBO_EMP_E      enVb1Emphasis;      /**<Vbone Pre-emphasis */ /**<CNcomment:VboneԤ���� */
}HI_UNF_PANEL_INTF_ATTR_S;

/**panel fixate type *//**CNcomment:panel �̶�֡������*/
typedef enum hiUNF_PANEL_FIXRATE_TYPE_E
{
	HI_UNF_PANEL_FIXRATE_TYPE_NONE	= 0,	 /**<fixrate type is none *//**CNcomment: ���̶����֡�� */
    HI_UNF_PANEL_FIXRATE_TYPE_FHD_50HZ,		 /**<fixrate type is fhd50 *//**CNcomment: �̶�FHD50��� */
    HI_UNF_PANEL_FIXRATE_TYPE_FHD_60HZ,      /**<fixrate type is fhd60 *//**CNcomment: �̶�FHD60��� */
	HI_UNF_PANEL_FIXRATE_TYPE_UHD_50HZ, 	 /**<fixrate type is uhd50 *//**CNcomment: �̶�UHD50��� */
	HI_UNF_PANEL_FIXRATE_TYPE_UHD_60HZ, 	 /**<fixrate type is uhd60 *//**CNcomment: �̶�UHD60��� */
    
    HI_UNF_PANEL_FIXRATE_TYPE_BUTT,       /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
}HI_UNF_PANEL_FIXRATE_TYPE_E;

/**panel Timming Change type *//**CNcomment:panel Timming��Ϣ�仯��ʽ */
typedef enum hiUNF_PANEL_TIMING_CHANGE_E
{
    HI_UNF_PANEL_TIMING_CHANGE_INSTANT = 0,  /* Normal mode change, instant change */
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_VT,   /* Vtotal change gradual */ 
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_HT,   /* Htotal change gradual */
    HI_UNF_PANEL_TIMING_CHANGE_GRADUAL_CLK,  /* PixelClk change gradual*/
    HI_UNF_PANEL_TIMING_CHANGE_BUTT,

}HI_UNF_PANEL_TIMING_CHANGE_E;

/**panel Division Mode *//**CNcomment:panel Division ģʽ */
typedef enum hiUNF_PANEL_DIVISION_MODE_E
{
    HI_UNF_PANEL_ONE_DIVISION_NORMAL_MODE,  /* one division normal mode */
    HI_UNF_PANEL_ONE_DIVISION_OE_MODE,      /* one division odd and even mode */
    HI_UNF_PANEL_TWO_DIVISION_MODE,         /* two division mode */

    HI_UNF_PANEL_DIVISION_MODE_BUTT,        /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/

}HI_UNF_PANEL_DIVISION_MODE_E;


/**panel info *//**CNcomment:panel��Ϣ*/
typedef struct hiUNF_PANEL_INFO_S
{
    HI_CHAR                     chName[48];         /**<Panel Name */ /**<CNcomment:���� */
    HI_U32                      u32PanelWidth;      /**<Panel Width */ /**<CNcomment:Panel ˮƽ�ֱ��� */
    HI_U32                      u32Panelheight;     /**<Panel height */ /**<CNcomment:Panel ��ֱ�ֱ��� */
    HI_U32                      u32FrameRateMax;    /**<output max framerate */ /**<CNcomment:Panel ������֡�� */
    HI_BOOL                     bSupport48Hz;       /**<48hz support */ /**<CNcomment:Panel �Ƿ�֧��48HZ  */
    HI_UNF_DISP_3D_E            en3DType;           /**<output 3D type */ /**<CNcomment:����������� */
    HI_UNF_PANEL_TYPE_E         enResolutionType;   /**<output Resolution type */ /**<CNcomment:��������ֱ������� */
    HI_UNF_PANEL_INTFTYPE_E     enIntfType;         /**<Panel interface type */ /**<CNcomment:���Ľӿ�����*/
    HI_UNF_PANEL_LINKTYPE_E     enPanelLinkType;    /**<Panel link type *//**CNcomment:Panel���������� */
    HI_UNF_PANEL_BITWIDTH_E     enPanelBitWidth;    /**<Panel bit width *//**CNcomment:Panel������λ��  */
    
    HI_UNF_PANEL_LVDSATTR_S     stLvdsAttr;         /**<LVDS interface attr *//**Lvds����������Lvds�ӿڵ�ʱ��ʹ�ô˲���*/
    HI_UNF_PANEL_VBOATTR_S      stVboAttr;          /**<VBO interface attr *//**Vbo����������VBO�ӿڵ�ʱ��ʹ�ô˲���*/

    HI_UNF_PANEL_TIMING_S       stTiming60Hz;       /**<Panel timing info 60Hz/120Hz *//**CNcomment:Panel ���60Hz/120Hz timing */
    HI_UNF_PANEL_TIMING_S       stTiming50Hz;       /**<Panel timing info 50Hz/100Hz *//**CNcomment:Panel ���50Hz/100Hz timing */
    HI_UNF_PANEL_TIMING_S       stTiming48Hz;       /**<Panel timing info 48Hz/96Hz  *//**CNcomment:Panel ���48Hz/96Hz timing  */
    HI_U16                      u16HsyncWidth;      /**<hsync width *//**CNcomment:Hsync ��� */
    HI_U16                      u16VsyncWidth;      /**<vsync width *//**CNcomment:Vsync ��� */

    HI_BOOL                     bHSyncOutput;       /**<Panel hsync output *//**CNcomment:Panel Vsync�Ƿ������0:Ϊ��ֹ���  1:Ϊ��� */
    HI_BOOL                     bVSyncOutput;       /**<Panel vsync output *//**CNcomment:Panel Hsync �Ƿ������0:Ϊ��ֹ���  1:Ϊ��� */
    HI_BOOL                     bHSyncNegative;     /**<hsync negative *//**CNcomment:Panel Hsync �Ƿ�Ϊ������ */
    HI_BOOL                     bVSyncNegative;     /**<vsync negative *//**CNcomment:Panel Vsync �Ƿ�Ϊ������ */
    HI_BOOL                     bDeNegative;        /**<DE negative *//**CNcomment:Panel DE �Ƿ�Ϊ������ */
        
    HI_BOOL                     bPwmPostive;        /**<Panel backlight pwm postive *//**CNcomment:Panel backlight pwm �Ƿ�Ϊ������ */
    HI_U32                      u32DimmingFreq60hz; /**<dimming frequence 60Hz/120Hz *//**CNcomment:����dimming ��60Hz/120Hz ���ʱ���Ƶ�� */
    HI_U32                      u32DimmingFreq50hz; /**<dimming frequence 50Hz/100Hz *//**CNcomment:����dimming ��50Hz/100Hz ���ʱ���Ƶ�� */
    HI_U32                      u32DimmingFreq48hz; /**<dimming frequence 48Hz/96Hz *//**CNcomment:����dimming ��48Hz/96Hz ���ʱ���Ƶ�� */
    
    HI_U32                      u32IntfSignalOnDelay; /**<open LVDS signal delay *//**CNcomment:�ڸ�TCON����֮����ʱ��LVDS�źŵ�ʱ�� */
    HI_U32                      u32BLOnDelay;         /**<open backlight delay *//**CNcomment:�ڴ�LVDS�ź�֮����ʱ�򿪱����ʱ�� */
    HI_U32                      u32BLOffDelay;        /**<close LVDS signal delay *//**CNcomment:�ڹرձ���֮����ʱ�ر�LVDS�źŵ�ʱ�� */
    HI_U32                      u32IntfSignalOffDelay;/**<close backlight delay *//**CNcomment: �ڹر�LVDS�ź�֮����ʱ�ر�TCON�����ʱ�� */

    HI_BOOL                     bFrmRateChangeBlack;    /**<framerate change screen mute *//**CNcomment: ֡�ʱ仯ʱ�Ƿ���� */
    HI_U32                      u32MuteTime;            /**<screen mute time *//**CNcomment: ������ʱ�䣬Ĭ��ֵ0~5000 Ms */

    HI_BOOL                     bLocalDimmingSupport;   /**<localdimming support *//**CNcomment: �Ƿ�֧��LocalDimming Ms */
    HI_U32                      u32HorAreaNum;          /**<localdimming horArea number *//**CNcomment: ֧��LocalDimmingʱˮƽ�����ĸ��� */
    HI_U32                      u32VerAreaNum;          /**<localdimming verArea number *//**CNcomment: ֧��LocalDimmingʱ��ֱ�����ĸ��� */

    HI_UNF_PANEL_FLIP_TYPE_E    enPanelFlipType;        /**<Panel Flip Type *//**CNcomment: Panel�ķ�ת����*/
    HI_UNF_PANEL_FIXRATE_TYPE_E enPanelFixRateType;

    HI_UNF_PANEL_TIMING_CHANGE_E enTimChangeType;       /**<Panel Timming change type *//**CNcomment: PanelTimming�仯��ʽ*/
    HI_U32                      u32ChangeStep;          /**<Panel Timming change step *//**CNcomment: PanelTimming�仯����*/

    HI_UNF_PANEL_DIVISION_MODE_E enDivisionMode;        /**<Panel division mode *//**CNcomment: Panel����ģʽ*/
        
    HI_U32                      u32Resove[5];          /**<reserved *//**CNcomment: 0~8��9��Reserved 32λ������Ĭ��ֵ0xffffffff */

}HI_UNF_PANEL_INFO_S;


/**panel aspect *//**CNcomment:panel��ʾ�ı���ģʽ*/
typedef enum hiUNF_PANEL_ASPECT_E
{
    HI_UNF_PANEL_ASPECT_4_3 = 0,    /**<aspect is 4:3 *//**CNcomment: 4:3 ��ʾ */
    HI_UNF_PANEL_ASPECT_16_9,       /**<aspect is 16:9 *//**CNcomment: 16:9 ��ʾ */
    HI_UNF_PANEL_ASPECT_14_9,       /**<aspect is 14:9 *//**CNcomment: 14:9 ��ʾ */
    HI_UNF_PANEL_ASPECT_21_9,       /**<aspect is 21:9 *//**CNcomment: 21:9 ��ʾ */
    HI_UNF_PANEL_ASPECT_16_10,      /**<aspect is 16:10 *//**CNcomment: 16:10 ��ʾ */
    
    HI_UNF_PANEL_ASPECT_BUTT,       /**<Invalid value*//**<CNcomment:�Ƿ��߽�ֵ*/
}HI_UNF_PANEL_ASPECT_E;


/**panel attr *//**CNcomment:panel����*/
typedef struct hiUNF_PANEL_ATTR_S
{   
    HI_U32                  u32Width;   /**<Width *//**CNcomment: Panel�Ŀ�� */
    HI_U32                  u32Height;  /**<Height *//**CNcomment: Panel�ĸ߶� */
    HI_UNF_PANEL_ASPECT_E   enAspect;   /**<aspect *//**CNcomment: Panel�ı���ģʽ */
    HI_UNF_DISP_3D_E        en3dMode;   /**<3D Mode *//**CNcomment: Panel��3D ģʽ */
}HI_UNF_PANEL_ATTR_S;

/*==== Structure Definition end ==== */


/*************************** API declaration ****************************/
/** \addtogroup      PANEL */
/** @{ */  /** <!-- [PANEL] */

/** 
\brief the whole initialization of the PANEL device. CNcomment:PANEL�ӿ����������ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS  success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_Init(HI_VOID);

/** 
\brief deinit the PANEL device. CNcomment:PANEL�ӿ�ȥ��ʼ�� CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_DeInit(HI_VOID);

/** 
\brief set path the PANEL device. CNcomment:PANEL����������ϵͳ�е�·�� CNend
\attention \n
\param[in] pcPath: panel param path.CNcomment:���ε�·�� CNend
\retval HI_SUCCESS     success.  CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetPath(HI_CHAR* pcPath);

/** 
\brief set default information the PANEL device. CNcomment:PANEL����ѡȡϵͳĬ�ϵ����� CNend
\attention  \n
\param[in] u32Index: panel index. CNcomment:���ε�index CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetIndex(HI_U32 u32Index);

/** 
\brief get default information count the PANEL device. CNcomment:��ȡPANELĬ�ϵ����θ��� CNend
\attention  \n
\param[out] pu32TotalNum: panel total number save address. CNcomment:���θ����Ĵ�ŵ�ַ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetTotalNum(HI_U32 *pu32TotalNum);

/** 
\brief set information the PANEL device. CNcomment:����������Ϣ CNend
\attention  \n
\param[in] pstPanelInfo: panel info address CNcomment:���Ҫ���õ����ε���Ϣ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetInfo(HI_UNF_PANEL_INFO_S *pstPanelInfo);

/** 
\brief get information the PANEL device. CNcomment:��ȡ������Ϣ CNend
\attention  \n
\param[out] pstPanelInfo: panel info address CNcomment:������ε���Ϣ�ĵ�ַ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetInfo(HI_UNF_PANEL_INFO_S *pstPanelInfo);

/** 
\brief set power on the PANEL device. CNcomment:�������磬���BOOT�ѵ���MW��ʼ�����ܵ���SetPowerOn�˽ӿ�,ֻ���л����κ͹ػ����ܵ��� CNend
\attention  \n
\param[in] bEnable: power state CNcomment:���������ʹ����Ϣ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetPowerOn(HI_BOOL bEnable);

/** 
\brief get power on the PANEL device. CNcomment:��ȡ������״�� CNend
\attention  \n
\param[out] pbEnable: power state CNcomment:����ǰ�Ĺ���״��CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetPowerOn( HI_BOOL *pbEnable);

/** 
\brief set back light the PANEL device. CNcomment:�������ı��� CNend
\attention  \n
\param[in] bEnable: back light state CNcomment:�����������״̬ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetBacklight(HI_BOOL bEnable);

/** 
\brief get back light the PANEL device. CNcomment:��ȡ���ı���״̬ CNend
\attention  \n
\param[out] pbEnable: back light state CNcomment:����ǰ�����״̬ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetBacklight(HI_BOOL *pbEnable);

/** 
\brief set interface attr the PANEL device. CNcomment:�������Ľӿ���Ϣ CNend
\attention  \n
\param[in] pstIntfAttr: interface attr address CNcomment:Ҫ���õ���Ϣ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetIntfAttr(HI_UNF_PANEL_INTF_ATTR_S *pstIntfAttr);

/** 
\brief get interface attr the PANEL device. CNcomment:��ȡ���Ľӿ���Ϣ CNend
\attention  \n
\param[out] pstIntfAttr: interface attr address CNcomment:������ӿ���Ϣ�ĵ�ַ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetIntfAttr(HI_UNF_PANEL_INTF_ATTR_S *pstIntfAttr);

/** 
\brief set fix frame rate the PANEL device. CNcomment:�������֡��Ϊ�̶�ֵ CNend
\attention  \n
\param[in] enFixRateType: FixRateType CNcomment:���֡������ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetFixOutRate(HI_UNF_PANEL_FIXRATE_TYPE_E enFixRateType);


/** 
\brief get fix frame rate the PANEL device. CNcomment:��ȡ���֡�ʵĹ̶�ֵ CNend
\attention  \n
\param[in] penFixRateType: FixRateType CNcomment:���֡������ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetFixOutRate(HI_UNF_PANEL_FIXRATE_TYPE_E *penFixRateType);

/** 
\brief get attr the PANEL device. CNcomment:��ȡ����������� CNend
\attention  \n
\param[out] pstPanelAttr: save panel attr address CNcomment:������ԵĴ�ŵ�ַ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetPanelAttr(HI_UNF_PANEL_ATTR_S *pstPanelAttr);

/** 
\brief print list the PANEL device. CNcomment:�������Ĭ��������Ϣ CNend
\attention  \n
\param CNcomment:�� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_DumpPanelList(HI_VOID);

/** 
\brief set dynamic backlight enable the PANEL device. CNcomment:�������Ķ�̬����ʹ�� CNend
\attention  \n
\param[out] pbEnable: dynamic back light state CNcomment:����ǰ��̬�����״̬ CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetDynamicBLEnable(HI_BOOL bEnable);

//ygf add it because sdk source has implement it, but no interface
HI_S32 HI_UNF_PANEL_GetDynamicBLEnable(HI_BOOL *pbEnable);


/** 
\brief set back light level the PANEL device. CNcomment:�������ı���ȼ� CNend
\attention  \n
\param[in] u32Level: back light level CNcomment:����ĵȼ� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetBacklightLevel(HI_U32 u32Level);

/** 
\brief set back light level the PANEL device. CNcomment:��ȡ���ı���ȼ� CNend
\attention  \n
\param[in] u32Level: back light level CNcomment:����ĵȼ� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetBacklightLevel(HI_U32 *pu32Level);

/** 
\brief set local dimming the PANEL device. CNcomment:������localdimming���� CNend
\attention  \n
\param[in] u32Level: local dimming open or close CNcomment:localdimming�ر� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_SetLocalDimmingEn(HI_BOOL bEnable);

/** 
\brief set local dimming the PANEL device. CNcomment:��ȡ��localdimming���� CNend
\attention  \n
\param[in] u32Level: local dimming open or close CNcomment:localdimming�ر� CNend
\retval HI_SUCCESS      success.CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\see \n
CNcomment:�� CNend
*/
HI_S32 HI_UNF_PANEL_GetLocalDimmingEn(HI_BOOL *pbEnable);

/*==== API declaration end ==== */
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
/************************************** The End Of File **************************************/
