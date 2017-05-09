/*
 * mmchc.h
 *
 *  Created on: 16 juin 2012
 *  Author: Evangelina Lolivier-Exler
 *  Register definitions for the DM3730 microcontroller and for the SD card
 *  MMC/SD/SDIO Card Interface - Host Controller
 *
 */

#ifndef MMCHC_H_
#define MMCHC_H_

/* BASE ADDRESS */
#define MMCHS1_BASE_ADD		0x4809C000


/* ACCESS MACROS */
#define MMCHS1_REG(_x_)  *(vulong *)(MMCHS1_BASE_ADD + _x_) // _x_ is an offset with respect to the base address


/* OMAP3 MMCHS registers offsets */
#define MMCHS_SYSCONFIG		0x0010		
#define MMCHS_SYSSTATUS		0x0014		
#define MMCHS_CSRE		0x0024
#define MMCHS_CON		0x002C		
#define MMCHS_BLK		0x0104		
#define MMCHS_ARG		0x0108
#define MMCHS_CMD		0x010C		
#define MMCHS_RSP10   	0x0110
#define MMCHS_RSP32   	0x0114
#define MMCHS_RSP54   	0x0118
#define MMCHS_RSP76   	0x011C
#define MMCHS_DATA		0x0120		
#define MMCHS_PSTATE	0x0124
#define MMCHS_HCTL		0x0128		
#define MMCHS_SYSCTL	0x012C
#define MMCHS_STAT		0x0130
#define MMCHS_IE		0x0134		
#define MMCHS_CAPA		0x0140


/**************************************************************************\
 * Field Definition Macros
\**************************************************************************/
/* SYSCONFIG */
#define MMCHS_SYSCONFIG_AUTOIDLE   (0x00000001u)
#define MMCHS_SYSCONFIG_AUTOIDLE_SHIFT   (0x00000000u)
#define MMCHS_SYSCONFIG_AUTOIDLE_OFF   (0x0u)
#define MMCHS_SYSCONFIG_AUTOIDLE_ON   (0x1u << MMCHS_SYSCONFIG_AUTOIDLE_SHIFT)

#define MMCHS_SYSCONFIG_CLOCKACTIVITY   (0x00000300u)
#define MMCHS_SYSCONFIG_CLOCKACTIVITY_SHIFT   (0x00000008u)
#define MMCHS_SYSCONFIG_CLOCKACTIVITY_BOTH   (0x3u << MMCHS_SYSCONFIG_CLOCKACTIVITY_SHIFT)
#define MMCHS_SYSCONFIG_CLOCKACTIVITY_FUNC   (0x2u << MMCHS_SYSCONFIG_CLOCKACTIVITY_SHIFT)
#define MMCHS_SYSCONFIG_CLOCKACTIVITY_NONE   (0x0u)
#define MMCHS_SYSCONFIG_CLOCKACTIVITY_IFCE   (0x1u << MMCHS_SYSCONFIG_CLOCKACTIVITY_SHIFT)

#define MMCHS_SYSCONFIG_ENAWAKEUP   (0x00000004u)
#define MMCHS_SYSCONFIG_ENAWAKEUP_SHIFT   (0x00000002u)
#define MMCHS_SYSCONFIG_ENAWAKEUP_DISABLED   	(0x0u)
#define MMCHS_SYSCONFIG_ENAWAKEUP_ENABLED   	(0x1u << MMCHS_SYSCONFIG_ENAWAKEUP_SHIFT)

#define MMCHS_SYSCONFIG_SIDLEMODE   (0x00000018u)
#define MMCHS_SYSCONFIG_SIDLEMODE_SHIFT   (0x00000003u)
#define MMCHS_SYSCONFIG_SIDLEMODE_FORCE   (0x0u)
#define MMCHS_SYSCONFIG_SIDLEMODE_NOIDLE  (0x1u << MMCHS_SYSCONFIG_SIDLEMODE_SHIFT)
#define MMCHS_SYSCONFIG_SIDLEMODE_SMART   (0x2u << MMCHS_SYSCONFIG_SIDLEMODE_SHIFT)

#define MMCHS_SYSCONFIG_SOFTRESET   (0x00000002u)
#define MMCHS_SYSCONFIG_SOFTRESET_SHIFT   (0x00000001u)
#define MMCHS_SYSCONFIG_SOFTRESET_NORESET   (0x0u)
#define MMCHS_SYSCONFIG_SOFTRESET_ONRESET   (0x1u << MMCHS_SYSCONFIG_SOFTRESET_SHIFT)  



/* SYSSTATUS */
#define MMCHS_SYSSTATUS_RESETDONE_SHIFT   (0x00000000u)
#define MMCHS_SYSSTATUS_RESETDONE_DONE   	(0x1u << MMCHS_SYSSTATUS_RESETDONE_SHIFT)
#define MMCHS_SYSSTATUS_RESETDONE_ONGOING   	(0x0u)


/* CON */
#define MMCHS_CON_CDP   (0x00000080u)
#define MMCHS_CON_CDP_SHIFT   		(0x00000007u)
#define MMCHS_CON_CDP_ACTIVEHIGH   	(0x0u)
#define MMCHS_CON_CDP_ACTIVELOW   	(0x1u << MMCHS_CON_CDP_SHIFT)

#define MMCHS_CON_CEATA_SHIFT   (0x0000000Cu)
#define MMCHS_CON_CEATA_CEATAMODE   (0x1u)
#define MMCHS_CON_CEATA_NORMALMODE   (0x0u)

#define MMCHS_CON_CLKEXTFREE_SHIFT   (0x00000010u)
#define MMCHS_CON_CLKEXTFREE_AUTOGATING   (0x0u)
#define MMCHS_CON_CLKEXTFREE_FREERUNNING   (0x1u)

#define MMCHS_CON_CTPL_SHIFT   (0x0000000Bu)
#define MMCHS_CON_CTPL_MMC_SD   (0x0u)
#define MMCHS_CON_CTPL_SDIO   (0x1u)

#define MMCHS_CON_DVAL_SHIFT   (0x00000009u)
#define MMCHS_CON_DVAL_1MSDEBOUNCE   (0x2u)
#define MMCHS_CON_DVAL_231USDEBOUNCE   (0x1u)
#define MMCHS_CON_DVAL_33USDEBOUNCE   (0x0u)
#define MMCHS_CON_DVAL_8_4MSDEBOUNCE   (0x3u)

#define MMCHS_CON_DW8_SHIFT   (0x00000005u)
#define MMCHS_CON_DW8_1_4BITMODE   (0x0u)
#define MMCHS_CON_DW8_8BITMODE   (0x1u)

#define MMCHS_CON_HR_SHIFT   (0x00000002u)
#define MMCHS_CON_HR_HOSTRESP   (0x1u)
#define MMCHS_CON_HR_NOHOSTRESP   (0x0u)

#define MMCHS_CON_INIT   (0x00000002u)
#define MMCHS_CON_INIT_SHIFT   (0x00000001u)
#define MMCHS_CON_INIT_INITSTREAM   (0x1u << MMCHS_CON_INIT_SHIFT)
#define MMCHS_CON_INIT_NOINIT   (0x0u)

#define MMCHS_CON_MIT_SHIFT   (0x00000006u)
#define MMCHS_CON_MIT_CTO   (0x0u)
#define MMCHS_CON_MIT_NO_CTO   (0x1u)

#define MMCHS_CON_MODE_SHIFT   (0x00000004u)
#define MMCHS_CON_MODE_FUNC   (0x0u)
#define MMCHS_CON_MODE_SYSTEST   (0x1u)

#define MMCHS_CON_OBIE_SHIFT   (0x0000000Eu)
#define MMCHS_CON_OBIE_NORMALMODE   (0x0u)
#define MMCHS_CON_OBIE_OBINTMODE   (0x1u)

#define MMCHS_CON_OBIP_SHIFT   (0x0000000Du)
#define MMCHS_CON_OBIP_ACTIVEHIGH   (0x0u)
#define MMCHS_CON_OBIP_ACTIVELOW   (0x1u)

#define MMCHS_CON_OD_SHIFT   (0x00000000u)
#define MMCHS_CON_OD_NOOPENDRAIN   (0x0u)
#define MMCHS_CON_OD_OPENDRAIN   (0x1u)

#define MMCHS_CON_PADEN_SHIFT   (0x0000000Fu)
#define MMCHS_CON_PADEN_DISABLE   (0x0u)
#define MMCHS_CON_PADEN_ENABLE   (0x1u)

#define MMCHS_CON_STR_SHIFT   (0x00000003u)
#define MMCHS_CON_STR_BLOCK   (0x0u)
#define MMCHS_CON_STR_STREAM   (0x1u)

#define MMCHS_CON_WPP   (0x00000100u)
#define MMCHS_CON_WPP_SHIFT   		(0x00000008u)
#define MMCHS_CON_WPP_ACTIVEHIGH   	(0x0u)
#define MMCHS_CON_WPP_ACTIVELOW   	(0x1u << MMCHS_CON_WPP_SHIFT)

/* BLK */
#define MMCHS_BLK_BLEN   (0x00000FFFu)
#define MMCHS_BLK_BLEN_SHIFT   (0x00000000u)
#define MMCHS_BLK_BLEN_1024BYTESLEN   (0x400u)
#define MMCHS_BLK_BLEN_1BYTELEN   (0x1u)
#define MMCHS_BLK_BLEN_2BYTESLEN   (0x2u)
#define MMCHS_BLK_BLEN_3BYTESLEN   (0x3u)
#define MMCHS_BLK_BLEN_511BYTESLEN   (0x1FFu)
#define MMCHS_BLK_BLEN_512BYTESLEN   (0x200u)
#define MMCHS_BLK_BLEN_NOTRANSFER   (0x0u)

#define MMCHS_BLK_NBLK   (0xFFFF0000u)
#define MMCHS_BLK_NBLK_SHIFT   (0x00000010u)
#define MMCHS_BLK_NBLK_STPCNT   (0x0u)

/* CMD */
#define MMCHS_CMD_ACEN   (0x00000004u)
#define MMCHS_CMD_ACEN_SHIFT   (0x00000002u)
#define MMCHS_CMD_ACEN_DISABLE   (0x0u)
#define MMCHS_CMD_ACEN_ENABLE   (0x1u)

#define MMCHS_CMD_BCE   (0x00000002u)
#define MMCHS_CMD_BCE_SHIFT   (0x00000001u)
#define MMCHS_CMD_BCE_DISABLE   (0x0u)
#define MMCHS_CMD_BCE_ENABLE   (0x1u << MMCHS_CMD_BCE_SHIFT)

#define MMCHS_CMD_CCCE   (0x00080000u)
#define MMCHS_CMD_CCCE_SHIFT   (0x00000013u)
#define MMCHS_CMD_CCCE_CHECK   (0x1u << MMCHS_CMD_CCCE_SHIFT)
#define MMCHS_CMD_CCCE_NOCHECK   (0x0u)

#define MMCHS_CMD_CICE   (0x00100000u)
#define MMCHS_CMD_CICE_SHIFT   (0x00000014u)
#define MMCHS_CMD_CICE_CHECK   (0x1u << MMCHS_CMD_CICE_SHIFT)
#define MMCHS_CMD_CICE_NOCHECK   (0x0u)

#define MMCHS_CMD_CMD_TYPE   (0x00C00000u)
#define MMCHS_CMD_CMD_TYPE_SHIFT   (0x00000016u)
#define MMCHS_CMD_CMD_TYPE_ABORT   (0x3u)
#define MMCHS_CMD_CMD_TYPE_FUNC_SELECT   (0x2u)
#define MMCHS_CMD_CMD_TYPE_NORMAL   (0x0u)
#define MMCHS_CMD_CMD_TYPE_SUSPEND   (0x1u)

#define MMCHS_CMD_DDIR   (0x00000010u)
#define MMCHS_CMD_DDIR_SHIFT   (0x00000004u)
#define MMCHS_CMD_DDIR_READ   (0x1u << MMCHS_CMD_DDIR_SHIFT)
#define MMCHS_CMD_DDIR_WRITE   (0x0u)

#define MMCHS_CMD_DE   (0x00000001u)
#define MMCHS_CMD_DE_SHIFT   (0x00000000u)
#define MMCHS_CMD_DE_DISABLE   (0x0u)
#define MMCHS_CMD_DE_ENABLE   (0x1u)

#define MMCHS_CMD_DP   (0x00200000u)
#define MMCHS_CMD_DP_SHIFT   (0x00000015u)
#define MMCHS_CMD_DP_DATA   (0x1u << MMCHS_CMD_DP_SHIFT)
#define MMCHS_CMD_DP_NODATA   (0x0u)

#define MMCHS_CMD_INDX   (0x3F000000u)
#define MMCHS_CMD_INDX_SHIFT   (0x00000018u)

#define MMCHS_CMD_MSBS   (0x00000020u)
#define MMCHS_CMD_MSBS_SHIFT   (0x00000005u)
#define MMCHS_CMD_MSBS_MULTIBLK   (0x1u << MMCHS_CMD_MSBS_SHIFT)
#define MMCHS_CMD_MSBS_SGLEBLK   (0x0u)

#define MMCHS_CMD_RSP_TYPE   (0x00030000u)
#define MMCHS_CMD_RSP_TYPE_SHIFT   (0x00000010u)
#define MMCHS_CMD_RSP_TYPE_136BITS   (0x1u << MMCHS_CMD_RSP_TYPE_SHIFT)
#define MMCHS_CMD_RSP_TYPE_48BITS    (0x2u << MMCHS_CMD_RSP_TYPE_SHIFT)
#define MMCHS_CMD_RSP_TYPE_48BITS_BUSY (0x3u << MMCHS_CMD_RSP_TYPE_SHIFT)
#define MMCHS_CMD_RSP_TYPE_NORSP   (0x0u)

/* RSP10 */
#define MMCHS_RSP10_RSP0   (0x0000FFFFu)
#define MMCHS_RSP10_RSP0_SHIFT   (0x00000000u)

#define MMCHS_RSP10_RSP1   (0xFFFF0000u)
#define MMCHS_RSP10_RSP1_SHIFT   (0x00000010u)


/* RSP32 */
#define MMCHS_RSP32_RSP2   (0x0000FFFFu)
#define MMCHS_RSP32_RSP2_SHIFT   (0x00000000u)

#define MMCHS_RSP32_RSP3   (0xFFFF0000u)
#define MMCHS_RSP32_RSP3_SHIFT   (0x00000010u)


/* RSP54 */
#define MMCHS_RSP54_RSP4   (0x0000FFFFu)
#define MMCHS_RSP54_RSP4_SHIFT   (0x00000000u)

#define MMCHS_RSP54_RSP5   (0xFFFF0000u)
#define MMCHS_RSP54_RSP5_SHIFT   (0x00000010u)


/* RSP76 */
#define MMCHS_RSP76_RSP6   (0x0000FFFFu)
#define MMCHS_RSP76_RSP6_SHIFT   (0x00000000u)

#define MMCHS_RSP76_RSP7   (0xFFFF0000u)
#define MMCHS_RSP76_RSP7_SHIFT   (0x00000010u)


/* PSTATE */
#define MMCHS_PSTATE_BRE   (0x00000800u)
#define MMCHS_PSTATE_BRE_SHIFT   (0x0000000Bu)
#define MMCHS_PSTATE_BRE_RDDISABLE   (0x0u)
#define MMCHS_PSTATE_BRE_RDENABLE   (0x1u)

#define MMCHS_PSTATE_BWE   (0x00000400u)
#define MMCHS_PSTATE_BWE_SHIFT   (0x0000000Au)
#define MMCHS_PSTATE_BWE_WRDISABLE   (0x0u)
#define MMCHS_PSTATE_BWE_WRENABLE   (0x1u)

#define MMCHS_PSTATE_CLEV   (0x01000000u)
#define MMCHS_PSTATE_CLEV_SHIFT   (0x00000018u)
#define MMCHS_PSTATE_CLEV_ONE   (0x1u)
#define MMCHS_PSTATE_CLEV_ZERO   (0x0u)

#define MMCHS_PSTATE_CMDI   (0x00000001u)
#define MMCHS_PSTATE_CMDI_SHIFT   (0x00000000u)
#define MMCHS_PSTATE_CMDI_CMDDIS   (0x1u)
#define MMCHS_PSTATE_CMDI_CMDEN   (0x0u)

#define MMCHS_PSTATE_DATI   (0x00000002u)
#define MMCHS_PSTATE_DATI_SHIFT   (0x00000001u)
#define MMCHS_PSTATE_DATI_CMDDIS   (0x1u << MMCHS_PSTATE_DATI_SHIFT)
#define MMCHS_PSTATE_DATI_CMDEN   (0x0u)

#define MMCHS_PSTATE_DLA   (0x00000004u)
#define MMCHS_PSTATE_DLA_SHIFT   (0x00000002u)
#define MMCHS_PSTATE_DLA_ACTIVE   (0x1u)
#define MMCHS_PSTATE_DLA_INACTIVE   (0x0u)

#define MMCHS_PSTATE_DLEV   (0x00F00000u)
#define MMCHS_PSTATE_DLEV_SHIFT   (0x00000014u)

#define MMCHS_PSTATE_RTA   (0x00000200u)
#define MMCHS_PSTATE_RTA_SHIFT   (0x00000009u)
#define MMCHS_PSTATE_RTA_NOTRANSFER   (0x0u)
#define MMCHS_PSTATE_RTA_TRANSFER   (0x1u)

#define MMCHS_PSTATE_WTA   (0x00000100u)
#define MMCHS_PSTATE_WTA_SHIFT   (0x00000008u)
#define MMCHS_PSTATE_WTA_NOTRANSFER   (0x0u)
#define MMCHS_PSTATE_WTA_TRANSFER   (0x1u)


/* HCTL */
#define MMCHS_HCTL_CR_SHIFT   (0x00000011u)
#define MMCHS_HCTL_CR_NONE   (0x0u)
#define MMCHS_HCTL_CR_RESTART   (0x1u)

#define MMCHS_HCTL_DTW_SHIFT   (0x00000001u)
#define MMCHS_HCTL_DTW_1_BITMODE   (0x0u)
#define MMCHS_HCTL_DTW_4_BITMODE   (0x1u  << MMCHS_HCTL_DTW_SHIFT)

#define MMCHS_HCTL_IBG_SHIFT   (0x00000013u)
#define MMCHS_HCTL_IBG_ITDIABLE   (0x0u)
#define MMCHS_HCTL_IBG_ITENABLE   (0x1u)

#define MMCHS_HCTL_INS_SHIFT   (0x00000019u)
#define MMCHS_HCTL_INS_DISABLE   (0x0u)
#define MMCHS_HCTL_INS_ENABLE   (0x1u)

#define MMCHS_HCTL_IWE_SHIFT   (0x00000018u)
#define MMCHS_HCTL_IWE_DISABLE   (0x0u)
#define MMCHS_HCTL_IWE_ENABLE   (0x1u)

#define MMCHS_HCTL_OBWE_SHIFT   (0x0000001Bu)
#define MMCHS_HCTL_OBWE_DISABLE   (0x0u)
#define MMCHS_HCTL_OBWE_ENABLE   (0x1u)

#define MMCHS_HCTL_REM_SHIFT   (0x0000001Au)
#define MMCHS_HCTL_REM_DISABLE   (0x0u)
#define MMCHS_HCTL_REM_ENABLE   (0x1u)

#define MMCHS_HCTL_RWC_SHIFT   (0x00000012u)
#define MMCHS_HCTL_RWC_NORW   (0x0u)
#define MMCHS_HCTL_RWC_RW   (0x1u)

#define MMCHS_HCTL_SBGR_SHIFT   (0x00000010u)
#define MMCHS_HCTL_SBGR_STPBLK   (0x1u)
#define MMCHS_HCTL_SBGR_TRANSFER   (0x0u)

#define MMCHS_HCTL_SDBP_SHIFT   (0x00000008u)
#define MMCHS_HCTL_SDBP_PWROFF  (0x0u)
#define MMCHS_HCTL_SDBP_PWRON	(0x1u  << MMCHS_HCTL_SDBP_SHIFT)

#define MMCHS_HCTL_SDVS   (0x00000E00u)
#define MMCHS_HCTL_SDVS_SHIFT   (0x00000009u)
#define MMCHS_HCTL_SDVS_1V8   (0x5u << MMCHS_HCTL_SDVS_SHIFT)
#define MMCHS_HCTL_SDVS_3V0   (0x6u << MMCHS_HCTL_SDVS_SHIFT)
#define MMCHS_HCTL_SDVS_3V3   (0x7u << MMCHS_HCTL_SDVS_SHIFT)


/* SYSCTL */
#define MMCHS_SYSCTL_CEN   (0x00000004u)
#define MMCHS_SYSCTL_CEN_SHIFT   (0x00000002u)
#define MMCHS_SYSCTL_CEN_DISABLE   (0x0u)
#define MMCHS_SYSCTL_CEN_ENABLE   (0x1u << MMCHS_SYSCTL_CEN_SHIFT)

#define MMCHS_SYSCTL_CLKD   		(0x0000FFC0u)
#define MMCHS_SYSCTL_CLKD_SHIFT   	(0x00000006u)
#define MMCHS_SYSCTL_CLKD_BYPASS0   	(0x0u) 
#define MMCHS_SYSCTL_CLKD_BYPASS1   	(0x1u	 << MMCHS_SYSCTL_CLKD_SHIFT)
#define MMCHS_SYSCTL_CLKD_DIV1023   	(0x3FFu	 << MMCHS_SYSCTL_CLKD_SHIFT)
#define MMCHS_SYSCTL_CLKD_DIV2   	(0x2u	 << MMCHS_SYSCTL_CLKD_SHIFT)
#define MMCHS_SYSCTL_CLKD_DIV3   	(0x3u	 << MMCHS_SYSCTL_CLKD_SHIFT)
#define MMCHS_SYSCTL_CLKD_DIV4   	(0x4u	 << MMCHS_SYSCTL_CLKD_SHIFT)
#define MMCHS_SYSCTL_CLKD_DIV480   	(0x78u	 << MMCHS_SYSCTL_CLKD_SHIFT)

#define MMCHS_SYSCTL_DTO   (0x000F0000u)
#define MMCHS_SYSCTL_DTO_SHIFT   (0x00000010u)
#define MMCHS_SYSCTL_DTO_TCF27   (0xEu << MMCHS_SYSCTL_DTO_SHIFT)
#define MMCHS_SYSCTL_DTO_TCF13   (0x0u)
#define MMCHS_SYSCTL_DTO_TCF14   (0x1u << MMCHS_SYSCTL_DTO_SHIFT)
#define MMCHS_SYSCTL_DTO_RSVD   (0xFu)

#define MMCHS_SYSCTL_ICE   (0x00000001u)
#define MMCHS_SYSCTL_ICE_SHIFT   (0x00000000u)
#define MMCHS_SYSCTL_ICE_OSCILLATE   	(0x1u << MMCHS_SYSCTL_ICE_SHIFT)
#define MMCHS_SYSCTL_ICE_STOP   	(0x0u << MMCHS_SYSCTL_ICE_SHIFT)

#define MMCHS_SYSCTL_ICS   (0x00000002u)
#define MMCHS_SYSCTL_ICS_SHIFT   	(0x00000001u)
#define MMCHS_SYSCTL_ICS_NOTREADY   	(0x0u << MMCHS_SYSCTL_ICS_SHIFT)
#define MMCHS_SYSCTL_ICS_READY   	(0x1u << MMCHS_SYSCTL_ICS_SHIFT)

#define MMCHS_SYSCTL_SRA   (0x01000000u)
#define MMCHS_SYSCTL_SRA_SHIFT   (0x00000018u)
#define MMCHS_SYSCTL_SRA_RSTCOMPLETED   (0x0u)
#define MMCHS_SYSCTL_SRA_RSTFORALLDESIGN   (0x1u << MMCHS_SYSCTL_SRA_SHIFT)

#define MMCHS_SYSCTL_SRC   (0x02000000u)
#define MMCHS_SYSCTL_SRC_SHIFT   (0x00000019u)
#define MMCHS_SYSCTL_SRC_RSTCOMPLETED   (0x0u)
#define MMCHS_SYSCTL_SRC_RSTFORCMD   (0x1u)

#define MMCHS_SYSCTL_SRD   (0x04000000u)
#define MMCHS_SYSCTL_SRD_SHIFT   (0x0000001Au)
#define MMCHS_SYSCTL_SRD_RSTCOMPLETED   (0x0u)
#define MMCHS_SYSCTL_SRD_RSTFORDAT   (0x1u)

/* STAT */
#define MMCHS_STAT_ACE   (0x01000000u)
#define MMCHS_STAT_ACE_SHIFT   (0x00000018u)
#define MMCHS_STAT_ACE_CMD12ERROR   (0x1u)
#define MMCHS_STAT_ACE_NOERROR   (0x0u)
#define MMCHS_STAT_ACE_STS_CLEAR   (0x1u)

#define MMCHS_STAT_BADA   (0x20000000u)
#define MMCHS_STAT_BADA_SHIFT   (0x0000001Du)
#define MMCHS_STAT_BADA_BADACCESS   (0x1u)
#define MMCHS_STAT_BADA_NOERROR   (0x0u)
#define MMCHS_STAT_BADA_STS_CLEAR   (0x1u)

#define MMCHS_STAT_BRR   (0x00000020u)
#define MMCHS_STAT_BRR_SHIFT   (0x00000005u)
#define MMCHS_STAT_BRR_NOTREADY   (0x0u)
#define MMCHS_STAT_BRR_READYTOREAD   (0x1u)
#define MMCHS_STAT_BRR_STS_CLEAR   (0x1u)

#define MMCHS_STAT_BWR   (0x00000010u)
#define MMCHS_STAT_BWR_SHIFT   (0x00000004u)
#define MMCHS_STAT_BWR_NOTREADY   (0x0u)
#define MMCHS_STAT_BWR_READYTOWRITE   (0x1u)
#define MMCHS_STAT_BWR_STS_CLEAR   (0x1u << MMCHS_STAT_BWR_SHIFT)

#define MMCHS_STAT_CC   (0x00000001u)
#define MMCHS_STAT_CC_SHIFT   (0x00000000u)

#define MMCHS_STAT_CCRC   (0x00020000u)
#define MMCHS_STAT_CCRC_SHIFT   (0x00000011u)
#define MMCHS_STAT_CCRC_CCRCERROR   (0x1u)
#define MMCHS_STAT_CCRC_NOERROR   (0x0u)
#define MMCHS_STAT_CCRC_STS_CLEAR   (0x1u)

#define MMCHS_STAT_CEB   (0x00040000u)
#define MMCHS_STAT_CEB_SHIFT   (0x00000012u)
#define MMCHS_STAT_CEB_CEBERROR   (0x1u)
#define MMCHS_STAT_CEB_NOERROR   (0x0u)
#define MMCHS_STAT_CEB_STS_CLEAR   (0x1u)

#define MMCHS_STAT_CERR   (0x10000000u)
#define MMCHS_STAT_CERR_SHIFT   (0x0000001Cu)
#define MMCHS_STAT_CERR_CARDERROR   (0x1u)
#define MMCHS_STAT_CERR_NOERROR   (0x0u)
#define MMCHS_STAT_CERR_STS_CLEAR   (0x1u)

#define MMCHS_STAT_CIE   (0x00080000u)
#define MMCHS_STAT_CIE_SHIFT   (0x00000013u)
#define MMCHS_STAT_CIE_CMDINDEXERROR   (0x1u)
#define MMCHS_STAT_CIE_NOERROR   (0x0u)
#define MMCHS_STAT_CIE_STS_CLEAR   (0x1u)

#define MMCHS_STAT_CIRQ   (0x00000100u)
#define MMCHS_STAT_CIRQ_SHIFT   (0x00000008u)
#define MMCHS_STAT_CIRQ_GENCARDINT   (0x1u)
#define MMCHS_STAT_CIRQ_NOCARDINT   (0x0u)

#define MMCHS_STAT_CTO   (0x00010000u)
#define MMCHS_STAT_CTO_SHIFT   (0x00000010u)
#define MMCHS_STAT_CTO_NOERROR   (0x0u)
#define MMCHS_STAT_CTO_STS_CLEAR   	(0x1u)
#define MMCHS_STAT_CTO_TIMEOUT   	(0x1u)

#define MMCHS_STAT_DCRC   		(0x00200000u)
#define MMCHS_STAT_DCRC_SHIFT   	(0x00000015u)
#define MMCHS_STAT_DCRC_DCRCERROR   	(0x1u)
#define MMCHS_STAT_DCRC_NOERROR   	(0x0u)
#define MMCHS_STAT_DCRC_STS_CLEAR   	(0x1u)

#define MMCHS_STAT_DEB   		(0x00400000u)
#define MMCHS_STAT_DEB_SHIFT   		(0x00000016u)
#define MMCHS_STAT_DEB_DEBERROR   	(0x1u)
#define MMCHS_STAT_DEB_NOERROR   	(0x0u)
#define MMCHS_STAT_DEB_STS_CLEAR   	(0x1u)

#define MMCHS_STAT_DTO   		(0x00100000u)
#define MMCHS_STAT_DTO_SHIFT   		(0x00000014u)
#define MMCHS_STAT_DTO_NOERROR   	(0x0u)
#define MMCHS_STAT_DTO_STS_CLEAR   	(0x1u)
#define MMCHS_STAT_DTO_TIMEOUT   	(0x1u)

#define MMCHS_STAT_ERRI   		(0x00008000u)
#define MMCHS_STAT_ERRI_SHIFT   	(0x0000000Fu)
#define MMCHS_STAT_ERRI_ERRINTEVNT   	(0x1u)
#define MMCHS_STAT_ERRI_NOERROR   	(0x0u)
#define MMCHS_STAT_ERRI_STS_CLEAR   	(0x1u)

#define MMCHS_STAT_OBI   		(0x00000200u)
#define MMCHS_STAT_OBI_SHIFT   		(0x00000009u)
#define MMCHS_STAT_OBI_NOERROR   	(0x0u)
#define MMCHS_STAT_OBI_OBIINT   	(0x1u)
#define MMCHS_STAT_OBI_STS_CLEAR   	(0x1u)

#define MMCHS_STAT_TC   		(0x00000002u)
#define MMCHS_STAT_TC_SHIFT   		(0x00000001u)


/* IE */
#define MMCHS_IE_ACE_ENABLE   		(0x01000000u)
#define MMCHS_IE_ACE_ENABLE_SHIFT   	(0x00000018u)
#define MMCHS_IE_ACE_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_ACE_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_BADA_ENABLE   		(0x20000000u)
#define MMCHS_IE_BADA_ENABLE_SHIFT   	(0x0000001Du)
#define MMCHS_IE_BADA_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_BADA_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_BGE_ENABLE   		(0x00000004u)
#define MMCHS_IE_BGE_ENABLE_SHIFT   	(0x00000002u)
#define MMCHS_IE_BGE_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_BGE_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_BRR_ENABLE   		(0x00000020u)
#define MMCHS_IE_BRR_ENABLE_SHIFT   	(0x00000005u)
#define MMCHS_IE_BRR_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_BRR_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_BWR_ENABLE   		(0x00000010u)
#define MMCHS_IE_BWR_ENABLE_SHIFT   	(0x00000004u)
#define MMCHS_IE_BWR_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_BWR_ENABLE_MASKED  	(0x0u)

#define MMCHS_IE_CCRC_ENABLE   		(0x00020000u)
#define MMCHS_IE_CCRC_ENABLE_SHIFT   	(0x00000011u)
#define MMCHS_IE_CCRC_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CCRC_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CC_ENABLE   		(0x00000001u)
#define MMCHS_IE_CC_ENABLE_SHIFT   	(0x00000000u)
#define MMCHS_IE_CC_ENABLE_ENABLED   	(0x1u << MMCHS_IE_CC_ENABLE_SHIFT)
#define MMCHS_IE_CC_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CEB_ENABLE   		(0x00040000u)
#define MMCHS_IE_CEB_ENABLE_SHIFT   	(0x00000012u)
#define MMCHS_IE_CEB_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CEB_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CERR_ENABLE   		(0x10000000u)
#define MMCHS_IE_CERR_ENABLE_SHIFT   	(0x0000001Cu)
#define MMCHS_IE_CERR_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CERR_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CIE_ENABLE   		(0x00080000u)
#define MMCHS_IE_CIE_ENABLE_SHIFT   	(0x00000013u)
#define MMCHS_IE_CIE_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CIE_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CIRQ_ENABLE   		(0x00000100u)
#define MMCHS_IE_CIRQ_ENABLE_SHIFT   	(0x00000008u)
#define MMCHS_IE_CIRQ_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CIRQ_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_CTO_ENABLE   		(0x00010000u)
#define MMCHS_IE_CTO_ENABLE_SHIFT   	(0x00000010u)
#define MMCHS_IE_CTO_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_CTO_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_DCRC_ENABLE   		(0x00200000u)
#define MMCHS_IE_DCRC_ENABLE_SHIFT   	(0x00000015u)
#define MMCHS_IE_DCRC_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_DCRC_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_DEB_ENABLE   		(0x00400000u)
#define MMCHS_IE_DEB_ENABLE_SHIFT   	(0x00000016u)
#define MMCHS_IE_DEB_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_DEB_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_DTO_ENABLE   		(0x00100000u)
#define MMCHS_IE_DTO_ENABLE_SHIFT   	(0x00000014u)
#define MMCHS_IE_DTO_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_DTO_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_NULL   		(0x00008000u)
#define MMCHS_IE_NULL_SHIFT   		(0x0000000Fu)

#define MMCHS_IE_OBI_ENABLE   		(0x00000200u)
#define MMCHS_IE_OBI_ENABLE_SHIFT   	(0x00000009u)
#define MMCHS_IE_OBI_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_OBI_ENABLE_MASKED   	(0x0u)

#define MMCHS_IE_TC_ENABLE   		(0x00000002u)
#define MMCHS_IE_TC_ENABLE_SHIFT   	(0x00000001u)
#define MMCHS_IE_TC_ENABLE_ENABLED   	(0x1u)
#define MMCHS_IE_TC_ENABLE_MASKED   	(0x0u)

/* CAPA */
#define MMCHS_CAPA_BCF_SHIFT   	(0x00000008u)
#define MMCHS_CAPA_BCF_OMETH   	(0x0u)

#define MMCHS_CAPA_DS_SHIFT   		(0x00000016u)
#define MMCHS_CAPA_DS_NOTSUPPORTED   	(0x0u)
#define MMCHS_CAPA_DS_SUPPORTED   	(0x1u)

#define MMCHS_CAPA_HSS_SHIFT   		(0x00000015u)
#define MMCHS_CAPA_HSS_NOTSUPPORTED   	(0x0u)
#define MMCHS_CAPA_HSS_SUPPORTED   	(0x1u)

#define MMCHS_CAPA_MBL_SHIFT   	(0x00000010u)
#define MMCHS_CAPA_MBL_1024   	(0x1u)
#define MMCHS_CAPA_MBL_2048   	(0x2u)
#define MMCHS_CAPA_MBL_512   	(0x0u)

#define MMCHS_CAPA_SRS_NOTSUPPORTED   	(0x0u)
#define MMCHS_CAPA_SRS_SUPPORTED   	(0x1u)

#define MMCHS_CAPA_TCF_SHIFT   	(0x00000000u)
#define MMCHS_CAPA_TCF_OMETH   	(0x0u)

#define MMCHS_CAPA_TCU_SHIFT   	(0x00000007u)
#define MMCHS_CAPA_TCU_KHZ   	(0x0u << MMCHS_CAPA_TCU_SHIFT)
#define MMCHS_CAPA_TCU_MHZ   	(0x1u << MMCHS_CAPA_TCU_SHIFT)

#define MMCHS_CAPA_VS18_SHIFT   	(0x0000001Au)
#define MMCHS_CAPA_VS18_1V8_NOTSUP   	(0x0u << MMCHS_CAPA_VS18_SHIFT)
#define MMCHS_CAPA_VS18_1V8_SUP   	(0x1u << MMCHS_CAPA_VS18_SHIFT)
#define MMCHS_CAPA_VS18_ST_1V8NOTSUP   	(0x0u << MMCHS_CAPA_VS18_SHIFT)
#define MMCHS_CAPA_VS18_ST_1V8SUP   	(0x1u << MMCHS_CAPA_VS18_SHIFT)

#define MMCHS_CAPA_VS30_SHIFT   	(0x00000019u)
#define MMCHS_CAPA_VS30_3V0_NOTSUP   	(0x0u << MMCHS_CAPA_VS30_SHIFT)
#define MMCHS_CAPA_VS30_3V0_SUP   	(0x1u << MMCHS_CAPA_VS30_SHIFT)
#define MMCHS_CAPA_VS30_ST_3V0NOTSUP   	(0x0u << MMCHS_CAPA_VS30_SHIFT)
#define MMCHS_CAPA_VS30_ST_3V0SUP   	(0x1u << MMCHS_CAPA_VS30_SHIFT)

#define MMCHS_CAPA_VS33_SHIFT   	(0x00000018u)
#define MMCHS_CAPA_VS33_3V3_NOTSUP   	(0x0u << MMCHS_CAPA_VS33_SHIFT)
#define MMCHS_CAPA_VS33_3V3_SUP   	(0x1u << MMCHS_CAPA_VS33_SHIFT)
#define MMCHS_CAPA_VS33_ST_3V3NOTSUP   	(0x0u << MMCHS_CAPA_VS33_SHIFT)
#define MMCHS_CAPA_VS33_ST_3V3SUP   	(0x1u << MMCHS_CAPA_VS33_SHIFT)

/* SD specification definitions */

/* VHS field of the interface command (CMD8) */
#define SD_VOLT_2P7_3P6                 (0x000100u)
/* Check pattern that can be used for card response validation */
#define SD_CHECK_PATTERN   0xAA

/* SD OCR register definitions - used for ACMD41 command */
/* Card power Up Status (busy) */
#define SD_OCR_CCS_BUSY    	BIT31
/* Card Capacity Status */
#define SD_OCR_HIGH_CAPACITY    	BIT30
/* Voltage */                                
#define SD_OCR_VDD_2P7_2P8		BIT15
#define SD_OCR_VDD_2P8_2P9		BIT16
#define SD_OCR_VDD_2P9_3P0		BIT17
#define SD_OCR_VDD_3P0_3P1		BIT18
#define SD_OCR_VDD_3P1_3P2		BIT19
#define SD_OCR_VDD_3P2_3P3		BIT20
#define SD_OCR_VDD_3P3_3P4		BIT21
#define SD_OCR_VDD_3P4_3P5		BIT22
#define SD_OCR_VDD_3P5_3P6		BIT23
/* This is for convenience only. Sets all the VDD fields */
#define SD_OCR_VDD_WILDCARD		(0x1FF << 15)

/* check RCA/status - response R6 */
#define SD_RCA_ADDR(rca)        ((rca & 0xFFFF0000) >> 16)
#define SD_RCA_STAT(rca)        (rca & 0xFFFF)


/* Bus width definition used for ACMD6 command */
#define		SD_BUS_WIDTH_1BIT	0
#define		SD_BUS_WIDTH_4BIT	0x2

/* Block length in bytes for SDHC cards */
#define		SD_BLOCK_LENGTH		512



#endif /* MMCHC_H_ */