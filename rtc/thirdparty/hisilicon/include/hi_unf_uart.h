#ifndef  __HI_UNF_UART_H__
#define  __HI_UNF_UART_H__

#include "hi_unf_common.h"
#include "hi_error_mpi.h"

#ifdef __cplusplus
 #if __cplusplus
extern "C" {
 #endif
#endif /* __cplusplus */

/**
\brief  get working uart NO. CNcomment:��ȡ��ǰ���������ĸ����� CNend
\retval uart NO success. CNcomment:���ں� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_GetUart(HI_VOID);


/**
\brief switch to specific uart. CNcomment:�л���ָ������ CNend
\param[in] ttyAMA   spec uart. CNcomment:ָ�����ں� CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
CNcomment:�� CNend
*/
HI_S32 HI_UNF_UART_Switch(HI_S32 ttyAMA);


/**
\brief initialize uart. CNcomment:�򿪲���ʼ������ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
\attention
\brief uart1 operation will not be effective until initialization except HI_UNF_UART_Switch and HI_UNF_UART_GetUart
 CNcomment:��������1֮ǰҪ�ȳ�ʼ�����л����ںͻ�ȡ���ڲ������� CNend
\brief default received buff size of uart is 1000B, you can change it with -DHI_UART_BUFLEN=XXX in Makefile
 CNcomment:Ĭ�ϵ�uart���ջ���Ϊ1000�ֽڣ�����ͨ����Makefie�����ô�С-DHI_UART_BUFLEN=XXX CNend
*/
HI_S32 HI_UNF_UART_Init(HI_VOID);


/**
\brief get uart attribute. CNcomment:��ȡ�������� CNend
\param[out] databits   data bits. CNcomment:����λ CNend
\param[out] stopbits   stop bits. CNcomment:ֹͣλ CNend
\param[out] parity   parity. CNcomment:��żλ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_GetAttribute(HI_S32 *databits, HI_S32 *stopbits, HI_CHAR *parity);


/**
\brief set uart attribute. CNcomment:���ô������� CNend
\param[in] databits   data bits. CNcomment:����λ CNend
\param[in] stopbits   stop bits. CNcomment:ֹͣλ CNend
\param[in] parity   parity. CNcomment:��żλ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_SetAttribute(HI_S32 databits, HI_S32 stopbits, HI_CHAR parity);


/**
\brief get uart baud speed. CNcomment:��ȡ���ڲ����� CNend
\param[out] speed   baud speed. CNcomment:������ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_GetSpeed(HI_S32 *speed);


/**
\brief set uart baud speed. CNcomment:���ô��ڲ����� CNend
\param[in] speed   baud speed. CNcomment:������ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_SetSpeed(HI_S32 speed);


/**
\brief set interval of reading data.
 CNcomment:�������ݳ�ʱֵ CNend
\param[in] tmout   interval(ms). CNcomment:��ʱֵ CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_SetTimeOut(HI_S32 tmout);


/**
\brief read data from uart. CNcomment:��ȡ�������� CNend
\param[out] buff   data buffer. CNcomment:���ݻ��� CNend
\param[in] len   buffer length. CNcomment:�����С CNend
\retval number of read data success. CNcomment:���ض�ȡ�������ݴ�С CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_Read(HI_PCHAR buff, HI_U32 len);


/**
\brief get total number of received. CNcomment:��ȡ���ڽ����������� CNend
\retval number of received data success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_GetTotal(HI_VOID);


/**
\brief reset total number of received. CNcomment:���ڽ����������� CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_ResetTotal(HI_VOID);


/**
\brief discard uart data in FIFO and reset total number. CNcomment:�������ڻ����е����ݲ�������� CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_Flush(HI_VOID);


/**
\brief wirte data to uart. CNcomment:д������������ CNend
\param[in] buff   data buffer. CNcomment:���ݻ��� CNend
\param[in] len   buffer length. CNcomment:���ʹ�С CNend
\retval number of written data success. CNcomment:�ɹ��������ݴ�С CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_Write(HI_PCHAR buff, HI_U32 len);


/**
\brief de-initialize uart. CNcomment:�رղ���մ��� CNend
\retval HI_SUCCESS success. CNcomment:�ɹ� CNend
\retval please refer to the err code definitino of mpi.CNcomment:��ο�MPI������ CNend
*/
HI_S32 HI_UNF_UART_DeInit(HI_VOID);

#ifdef __cplusplus
 #if __cplusplus
}
 #endif
#endif /* __cplusplus */

#endif  /*__HI_UNF_AI_H__*/
