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
 * \brief GPIO �����ж����̣�ͨ�� HW ��ӿ�ʵ��
 *
 * - �������裺
 *   1. �� J14 �� KEY �� PIOA_8 �̽���һ��
 *
 * - ʵ������
 *   1. ��һ�ΰ��� LED0 ��Ϩ���ٰ�һ�ΰ��� LED0 ��������˷�����
 *   2. ÿ�ΰ���ʱ���ڴ�ӡ "the gpio interrupt happen!"��
 *
 * \note
 *    1. LED0 ��Ҫ�̽� J9 ����ñ�����ܱ� PIOB_1 ���ƣ�
 *    2. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_am116_core_hw_gpio_trigger.c src_am116_core_hw_gpio_trigger
 *
 * \internal
 * \par Modification History
 * - 1.00 17-04-15  nwt, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_am116_core_hw_gpio_trigger
 * \copydoc demo_am116_core_hw_gpio_trigger.c
 */

/** [src_am116_core_hw_gpio_trigger] */
#include "ametal.h"
#include "am_clk.h"
#include "am_vdebug.h"
#include "am_zlg116.h"
#include "hw/amhw_zlg_exti.h"
#include "hw/amhw_zlg_syscfg.h"
#include "demo_zlg_entries.h"

/**
 * \brief �������
 */
void demo_am116_core_hw_gpio_trigger_entry (void)
{
    AM_DBG_INFO("demo am116_core hw gpio trigger!\r\n");

    /* ʹ��ʱ�� */
    am_clk_enable(CLK_GPIOA);
    am_clk_enable(CLK_SYSCFG);

    demo_zlg_hw_gpio_trigger_entry(ZLG116_GPIO,
                                   ZLG116_SYSCFG,
                                   ZLG116_EXTI,
                                   PIOA_8,
                                   AMHW_ZLG_SYSCFG_EXTI_PORTSOURCE_GPIOA,
                                   AMHW_ZLG_SYSCFG_EXTI_PINSOURCE_8,
                                   AMHW_ZLG_EXTI_LINE_NUM8);
}
/** [src_am116_core_hw_gpio_trigger] */

/* end of file */