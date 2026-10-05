/*
 * Copyright (c) 2026, Qualcomm Technologies, Inc. and/or its subsidiaries.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stddef.h>
#include <lib/utils_def.h>
#include <xpu3.h>
#include <xpu_target_info.h>

#include <platform_def.h>

/*
 * LLCC MPU protection for the EL3 carve-out.
 *
 * Keep the reference port's BL31-only protection in broadcast RG0. The other
 * DDR partitions belong to OP-TEE and images this port does not load.
 */
struct rg_domain_ownership llcc_mpu_rgs[] = {
	{ 0, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN },
};

struct rg_partition_range llcc_mpu_rg_addr[] = {
	{ 0, BL31_BASE & 0xffffffffUL,
	  (BL31_BASE + BL31_SIZE) & 0xffffffffUL },
};

/* Generation limitations (no driver changes):
 * XML VMID masks are retained as comments only: rg_domain_ownership has no VMID fields. The current HAL uses its own VMID defaults, not these masks; this output is not full XML policy enforcement.
 */

/* DC_NOC_BROADCAST_MPU_MPU32Q2N7S1V0_40_CL36M27L12_AHB: enabled, static, explicit default profile. */
struct rg_domain_ownership dc_noc_broadcast_mpu_rgs[] = {
	{  1, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  2, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{  3, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  4, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  5, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  6, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  7, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  8, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  9, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ 10, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 12, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 13, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ 15, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 17, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 18, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 19, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 20, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 22, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 23, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 25, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 26, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ 28, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 29, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 30, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 31, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 32, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 33, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 34, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 35, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 36, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 37, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 38, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range dc_noc_broadcast_mpu_rg_addr[] = {
	{  1, 0x00e20000, 0x00e30000 },
	{  2, 0x00e34000, 0x00e41000 },
	{  3, 0x00e3d000, 0x00e40000 },
	{  4, 0x00e40000, 0x00e46000 },
	{  5, 0x00e3d000, 0x00e3e000 },
	{  6, 0x00e3f000, 0x00e40000 },
	{  7, 0x00e58000, 0x00e60000 }, /* SECACCESS-8674: [Shikra] LLCC0_LCP aperture RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{  8, 0x00e40000, 0x00e45000 },
	{  9, 0x00e25000, 0x00e27000 },
	{ 10, 0x00e27000, 0x00e28000 },
	{ 12, 0x00e49000, 0x00e4c000 },
	{ 13, 0x00e28000, 0x00e2a000 },
	{ 15, 0x00e6b000, 0x00e6c000 },
	{ 17, 0x01020000, 0x01028000 },
	{ 18, 0x01034000, 0x0103c000 },
	{ 19, 0x0103c000, 0x01040000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- widened from 0x0103d000-0x0103e000 to full LLCC_BROADCAST_BERC range 0x0103c000-0x01040000. */
	{ 20, 0x01048000, 0x0104c000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- widened from 0x01049000-0x0104a000 to full LLCC_BROADCAST_FERC range 0x01048000-0x0104c000. */
	{ 22, 0x0104d000, 0x0104e000 },
	{ 23, 0x01050000, 0x01055000 },
	{ 25, 0x01061000, 0x01064000 },
	{ 26, 0x01030000, 0x01032000 },
	{ 28, 0x0108b000, 0x0108c000 },
	{ 29, 0x00e50000, 0x00e56000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC0_DRP RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 30, 0x00f00000, 0x00f30000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC1_TRP RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 31, 0x00f4c000, 0x00f50000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC1_PMGR RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 32, 0x00f36000, 0x00f38000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC1_PERFMON RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 33, 0x00f58000, 0x00f6a000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC1_LLCC_BEAC0 RW for HLOS(HYP) on DC_NOC_BROADCAST. Widened from 0x00f60000-0x00f6a000 to 0x00f58000-0x00f6a000 per SECACCESS-8674 to also cover LLCC1_LCP. */
	{ 34, 0x01040000, 0x01046000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC_BROADCAST_FEAC RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 35, 0x01028000, 0x01030000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC_BROADCAST_TRP (tail, RG17 covers 0x01020000-0x01028000) RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 36, 0x01055000, 0x01056000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC_BROADCAST_DRP (tail, RG23 covers 0x01050000-0x01055000) RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 37, 0x01064000, 0x0106a000 }, /* SECACCESS-8624: [Shikra] LLCC aperture permission missing -- LLCC_BROADCAST_LLCC_BEAC0 (tail, RG25 covers 0x01061000-0x01064000) RW for HLOS(HYP) on DC_NOC_BROADCAST. */
	{ 38, 0x01058000, 0x01060000 }, /* SECACCESS-8674: [Shikra] LLCC_BROADCAST_LCP aperture RW for HLOS(HYP) on DC_NOC_BROADCAST. */
};

/* DC_NOC_NON_BROADCAST_MPU_MPU32Q2N7S1V0_16_CL36M27L12_AHB: enabled, static, explicit default profile. */
struct rg_domain_ownership dc_noc_qhs_non_broadcast_mpu_rgs[] = {
	{  0, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{  2, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  3, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  4, APPS_S_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	{  5, APPS_S_DOMAIN, APPS_NS_DOMAIN, NO_DOMAIN }, /* HYP RD / None WR */
	{  7, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{  9, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 10, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range dc_noc_qhs_non_broadcast_mpu_rg_addr[] = {
	{  0, 0x00d00000, 0x00d28000 }, /* SECACCESS-7689 */
	{  2, 0x00d2a000, 0x00d40000 }, /* SECACCESS-7689 */
	{  3, 0x00c35000, 0x00c36000 }, /* SHRM_CSR */
	{  4, 0x00c36000, 0x00c37000 },
	{  5, 0x00c10000, 0x00c20000 },
	{  7, 0x01b8e000, 0x01b91000 }, /* BWMON_THROTTLE - APPS, GPU and CDSP */
	{  9, 0x00c90000, 0x00c94000 },
	{ 10, 0x00d40000, 0x00d44000 }, /* SECACCESS-7689 */
};

/* QM_MPU_CFG_QM_MPU_CFG_QM_MPU_CFG_MPU32Q2N7S1V0_4_CL36M23L12_AHB: enabled, static, explicit default profile. */
struct rg_domain_ownership qm_mpu_cfg_rgs[] = {
	{  0, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	/* XML VMIDs (metadata only): rvmids='ALL_HYP' (0xffffffff), wvmids='ALL_HYP' (0xffffffff) */
	{  1, APPS_NS_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	/* XML VMIDs (metadata only): rvmids='ALL_HYP' (0xffffffff), wvmids='ALL_HYP' (0xffffffff) */
	{  2, APPS_NS_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	{  3, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range qm_mpu_cfg_rg_addr[] = {
	{  0, 0x01b80000, 0x01b81000 }, /* DownTime (DT) related Registers that impact BIMC/DDR */
	{  1, 0x01b81000, 0x01b82000 }, /* QM Configuration registers */
	{  2, 0x01b82000, 0x01b83000 }, /* Debug registers */
	{  3, 0x01b83000, 0x01b84000 }, /* Secured registers */
};

/* CNOC_SNOC_MS_MPU_CFG: enabled, static, explicit default profile. */
struct rg_domain_ownership cnoc_snoc_ms_mpu_rgs[] = {
	{  7, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ 18, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ 19, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 25, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 26, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 27, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 30, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ 31, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ 32, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN }, /* HYP */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range cnoc_snoc_ms_mpu_rg_addr[] = {
	{  7, 0x01900000, 0x01902000 }, /* Used for Debug. SW WA CR2032950 for QCTDD04028203 */
	{ 18, 0x045f4000, 0x045f5000 },
	{ 19, 0x0a66e000, 0x0a670000 }, /* SECACCESS-1219: HLOS access to LPM memory */
	{ 25, 0x04b00000, 0x04b01000 }, /* SECACCESS-7733 */
	{ 26, 0x04b01000, 0x04b02000 }, /* SECACCESS-7733 */
	{ 27, 0x04b10000, 0x04b20000 }, /* SECACCESS-7733 */
	{ 30, 0x045f5000, 0x045f6000 }, /* SECACCESS-7725 */
	{ 31, 0x0b384000, 0x0b385000 }, /* SECACCESS-7760 */
	{ 32, 0x00d44000, 0x00d73000 }, /* SECACCESS-7726 */
};

/* CNOC_SNOC_QDSS_MPU_CFG_MPU32Q2N7S1V0_120_CL36M35L12_AHB: enabled, static, explicit default profile. */
struct rg_domain_ownership cnoc_snoc_qdss_mpu_rgs[] = {
	{  6, APPS_S_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	{ 10, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range cnoc_snoc_qdss_mpu_rg_addr[] = {
	{  6, 0x018b3000, 0x018b4000 }, /* SNOC DCD control. TZ is not a client but needs protecting. */
	{ 10, 0x0b925000, 0x0b928000 }, /* SECACCESS-7760 [Shikra] Not able to find XPU details for CDSP/MPSS/MCU WDOG Registers in IPCAT */
};

/* OCIMEM_MPU: enabled, static, explicit default profile. */
struct rg_domain_ownership ocimem_mpu_rgs[] = {
	/* XML VMIDs (metadata only): rvmids='ALL_HYP' (0xffffffff), wvmids='' (0x00000000) */
	{  0, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	/* XML VMIDs (metadata only): rvmids='' (0x00000000), wvmids='' (0x00000000) */
	{  1, APPS_S_DOMAIN, APPS_S_DOMAIN, APPS_S_DOMAIN }, /* TZ */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range ocimem_mpu_rg_addr[] = {
	{  0, 0x0c111000, 0x0c114000 }, /* SECACCESS-7727 */
	{  1, 0x0c100000, 0x0c111000 }, /* SECACCESS-7727 */
};

/* RPM_MSTR_MPU: enabled, static, explicit default profile. */
struct rg_domain_ownership rpm_mstr_mpu_rgs[] = {
	/* XML VMIDs (metadata only): rvmids='' (0x00000000), wvmids='' (0x00000000) */
	{  0, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	/* XML VMIDs (metadata only): rvmids='' (0x00000000), wvmids='' (0x00000000) */
	{  1, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	/* XML VMIDs (metadata only): rvmids='' (0x00000000), wvmids='' (0x00000000) */
	{  2, APPS_S_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN, APPS_S_DOMAIN | APPS_NS_DOMAIN }, /* HYP,TZ */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range rpm_mstr_mpu_rg_addr[] = {
	{  0, 0x04b00000, 0x04b01000 }, /* SECACCESS-7733 */
	{  1, 0x04b01000, 0x04b02000 }, /* SECACCESS-7733 */
	{  2, 0x04b10000, 0x04b20000 }, /* SECACCESS-7733 */
};

/* MCU_RVCP_SLV_RVCP_SLV_MPU32Q2N7S1V1_8_CL36M21L12_AHB: enabled, static, explicit default profile. */
struct rg_domain_ownership mcu_rvcp_slv_rgs[] = {
	/* XML VMIDs (metadata only): rvmids='ALL_HYP' (0xffffffff), wvmids='ALL_HYP' (0xffffffff) */
	{  2, APPS_S_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	/* XML VMIDs (metadata only): rvmids='' (0x00000000), wvmids='' (0x00000000) */
	{  3, APPS_S_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	/* XML VMIDs (metadata only): rvmids='ALL_HYP' (0xffffffff), wvmids='ALL_HYP' (0xffffffff) */
	{  6, APPS_S_DOMAIN, NO_DOMAIN, NO_DOMAIN }, /* None */
	{ XPU_UMR_RG, APPS_S_DOMAIN, APPS_NS_DOMAIN, APPS_NS_DOMAIN },
};

struct rg_partition_range mcu_rvcp_slv_rg_addr[] = {
	{  2, 0x0b840000, 0x0b88f00c }, /* CSR space */
	{  3, 0x0b900000, 0x0b93fffc }, /* RISC-V Core CSR space */
	{  6, 0x0b940000, 0x0b9ffffc }, /* DLS space */
};

/* Fixed LLCC plus all eligible XML XPU instances. */
struct xpu_instance msm_xpu_cfg[] = {
	{ HWIO_LLC_BROADCAST_LLCC_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(llcc_mpu_rgs), llcc_mpu_rgs,
	  ARRAY_SIZE(llcc_mpu_rg_addr), llcc_mpu_rg_addr,
	  XPU_TYPE_LLCC_BROADCAST_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_DC_NOC_BROADCAST_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(dc_noc_broadcast_mpu_rgs), dc_noc_broadcast_mpu_rgs,
	  ARRAY_SIZE(dc_noc_broadcast_mpu_rg_addr), dc_noc_broadcast_mpu_rg_addr,
	  XPU_TYPE_DC_NOC_BROADCAST_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_DC_NOC_QHS_NON_BROADCAST_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(dc_noc_qhs_non_broadcast_mpu_rgs), dc_noc_qhs_non_broadcast_mpu_rgs,
	  ARRAY_SIZE(dc_noc_qhs_non_broadcast_mpu_rg_addr), dc_noc_qhs_non_broadcast_mpu_rg_addr,
	  XPU_TYPE_DC_NOC_NON_BROADCAST_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_QM_MPU_CFG_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(qm_mpu_cfg_rgs), qm_mpu_cfg_rgs,
	  ARRAY_SIZE(qm_mpu_cfg_rg_addr), qm_mpu_cfg_rg_addr,
	  XPU_TYPE_QM_MPU_CFG, XPU_PROTECTION_STATIC },
	{ HWIO_CNOC_SNOC_MS_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(cnoc_snoc_ms_mpu_rgs), cnoc_snoc_ms_mpu_rgs,
	  ARRAY_SIZE(cnoc_snoc_ms_mpu_rg_addr), cnoc_snoc_ms_mpu_rg_addr,
	  XPU_TYPE_CNOC_SNOC_MS_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_CNOC_SNOC_QDSS_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(cnoc_snoc_qdss_mpu_rgs), cnoc_snoc_qdss_mpu_rgs,
	  ARRAY_SIZE(cnoc_snoc_qdss_mpu_rg_addr), cnoc_snoc_qdss_mpu_rg_addr,
	  XPU_TYPE_CNOC_SNOC_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_OCIMEM_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(ocimem_mpu_rgs), ocimem_mpu_rgs,
	  ARRAY_SIZE(ocimem_mpu_rg_addr), ocimem_mpu_rg_addr,
	  XPU_TYPE_IMEM_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_RPM_MSTR_MPU_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(rpm_mstr_mpu_rgs), rpm_mstr_mpu_rgs,
	  ARRAY_SIZE(rpm_mstr_mpu_rg_addr), rpm_mstr_mpu_rg_addr,
	  XPU_TYPE_RPM_MSTR_MPU, XPU_PROTECTION_STATIC },
	{ HWIO_MCU_RVCP_SLV_XPU3_GCR0_ADDR,
	  ARRAY_SIZE(mcu_rvcp_slv_rgs), mcu_rvcp_slv_rgs,
	  ARRAY_SIZE(mcu_rvcp_slv_rg_addr), mcu_rvcp_slv_rg_addr,
	  XPU_TYPE_LMCU_MPU, XPU_PROTECTION_STATIC },
};

const uint32_t msm_xpu_cfg_count = ARRAY_SIZE(msm_xpu_cfg);

/* No runtime modem/subsystem-restart MPU ranges are managed by this port. */
struct mpu_ranges msm_mpu_ranges[] = {
};

const uint32_t msm_mpu_ranges_count = ARRAY_SIZE(msm_mpu_ranges);
