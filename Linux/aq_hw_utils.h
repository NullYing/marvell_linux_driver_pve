/* SPDX-License-Identifier: GPL-2.0-only */
/* Atlantic Network Driver
 *
 * Copyright (C) 2014-2019 aQuantia Corporation
 * Copyright (C) 2019-2020 Marvell International Ltd.
 */

/* File aq_hw_utils.h: Declaration of helper functions used across hardware
 * layer.
 */

#ifndef AQ_HW_UTILS_H
#define AQ_HW_UTILS_H

#include "aq_common.h"

#ifndef HIDWORD
#define LODWORD(_qw)    ((u32)(_qw))
#define HIDWORD(_qw)    ((u32)(((_qw) >> 32) & 0xffffffff))
#endif

#define AQ_HW_SLEEP(_US_) mdelay(_US_)

#define aq_pr_err(...) pr_err(AQ_CFG_DRV_NAME ": " __VA_ARGS__)
#define aq_pr_debug(...) pr_debug(AQ_CFG_DRV_NAME ": " __VA_ARGS__)
#define aq_pr_trace(...) pr_info(AQ_CFG_DRV_NAME ": " __VA_ARGS__)
#define aq_pr_verbose(__aq_nic, __mask, fmt, ...)		\
do {								\
	if (unlikely(__aq_nic->msg_enable & (__mask)))		\
		pr_notice("[%s:%d(%s)]" fmt,			\
			  __func__, __LINE__,			\
			  __aq_nic->ndev ? (__aq_nic->ndev->name) : "?", ## __VA_ARGS__); \
} while (0)

enum DP_LEVEL {
	AQ_MSG_DRV = NETIF_MSG_DRV,
	AQ_MSG_LINK = NETIF_MSG_LINK,
	AQ_MSG_DEBUG = 0x10000,
	AQ_MSG_PTP = 0x20000,
	/* to be added...up to 0x8000000 */
};

struct aq_hw_s;

void aq_hw_write_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk,
			 u32 shift, u32 val);
u32 aq_hw_read_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk, u32 shift);
u32 aq_hw_read_reg(struct aq_hw_s *hw, u32 reg);
void aq_hw_write_reg(struct aq_hw_s *hw, u32 reg, u32 value);
u64 aq_hw_read_reg64(struct aq_hw_s *hw, u32 reg);
void aq_hw_write_reg64(struct aq_hw_s *hw, u32 reg, u64 value);
int aq_hw_err_from_flags(struct aq_hw_s *hw);
int aq_hw_num_tcs(struct aq_hw_s *hw);
int aq_hw_q_per_tc(struct aq_hw_s *hw);

#endif /* AQ_HW_UTILS_H */
