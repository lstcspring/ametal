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
 * \brief ZML165 WWDT �û������ļ�
 * \sa am_hwconf_zml165_wwdg.c
 * 
 * \internal
 * \par Modification history
 * - 1.00 15-07-07  sss, first implementation.
 * \endinternal
 */

#include "am_zml165.h"
#include "hw/amhw_zml165_rcc.h"
#include "am_zlg_wwdg.h"
#include "am_zml165_clk.h"

/**
 * \addtogroup am_if_src_hwconf_zml165_wwdg
 * \copydoc am_hwconf_zml165_wwdg.c
 * @{
 */

/** \brief WWDT ƽ̨��ʼ�� */
static void __zlg_wwdg_plfm_init (void)
{
    am_clk_enable(CLK_WWDG);
    am_zml165_clk_reset(CLK_WWDG);

    /* ��鸴λ�Ƿ��ɿ��Ź���ɵ� */
    if (amhw_zml165_rcc_reset_flag() & AMHW_ZML165_RCC_AHB_WWDGRSTF) {
        amhw_zml165_rcc_reset_flag_clear();
    }
}

/** \brief ���WWDT ƽ̨��ʼ�� */
static void __zlg_wwdg_plfm_deinit (void)
{
    am_clk_disable(CLK_WWDG);
}

/** \brief WWDT �豸��Ϣ */
static const am_zlg_wwdg_devinfo_t  __g_wwdg_devinfo = {
    ZML165_WWDG_BASE,       /**< \brief WWDT�Ĵ�����ַ */
    CLK_WWDG,               /**< \brief ʱ��ID */
    __zlg_wwdg_plfm_init,   /**< \brief WWDT ƽ̨��ʼ�� */
    __zlg_wwdg_plfm_deinit, /**< \brief ���WWDT ƽ̨��ʼ�� */
};

/** \brief WWDT�豸ʵ�� */
static am_zlg_wwdg_dev_t __g_wwdg_dev;

/**
 * \brief WWDT ʵ����ʼ�������WDT��׼������
 */
am_wdt_handle_t am_zml165_wwdg_inst_init (void)
{
    return am_zlg_wwdg_init(&__g_wwdg_dev, &__g_wwdg_devinfo);
}

/**
 * \brief WWDT ʵ�����ʼ��
 */
void am_zml165_wwdg_inst_deinit (am_wdt_handle_t handle)
{
    am_zlg_wwdg_deinit(handle);
}

/**
 * @}
 */

/* end of file */