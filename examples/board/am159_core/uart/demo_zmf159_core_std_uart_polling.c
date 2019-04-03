/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief UART ��ѯ��ʽ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - ʵ������
 *   1. ������� "STD-UART test in polling mode:"��
 *   2. ����������յ����ַ�����
 *
 * \note
 *    1. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_10 �������� PC ���ڵ� TXD��
 *       PIOA_9 �������� PC ���ڵ� RXD��
 *    2. ������Դ���ʹ���뱾������ͬ����Ӧ�ں�������ʹ�õ�����Ϣ�������
 *      ���磺AM_DBG_INFO()����
 *
 * \par Դ����
 * \snippet demo_zmf159_std_uart_polling.c src_zmf159_std_uart_polling
 *
 * \internal
 * \par Modification History
 * - 1.01 17-04-17  ari, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_zmf159_std_uart_polling
 * \copydoc demo_zmf159_std_uart_polling.c
 */

/** [src_zmf159_std_uart_polling] */
#include <demo_zmf159_core_entries.h>
#include "ametal.h"
#include "am_board.h"
#include "am_zmf159_inst_init.h"
#include "demo_std_entries.h"

/**
 * \brief �������
 */
void demo_zmf159_core_std_uart_polling_entry (void)
{
    AM_DBG_INFO("demo zmf159_core std uart polling!\r\n");

     /* �ȴ������������ */
    am_mdelay(100);

    demo_std_uart_polling_entry(am_zmf159_uart1_inst_init());
}
/** [src_zmf159_std_uart_polling] */

/* end of file */