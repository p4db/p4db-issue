/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PARREP_H__
#define __PIF_PARREP_H__

/* Generated C source defining layout of parsed representation */
/* Warning: your edits to this file may be lost */

/*
 * Parsed representation control data
 */
struct pif_parrep_ctldata {
    unsigned int valid:1;
    unsigned int t1_valid:1;
    unsigned int t1_dirty:1;
    unsigned int t1_orig_len:1;
    unsigned int t2_valid:1;
    unsigned int t2_type:1;
    unsigned int t2_dirty:1;
    unsigned int t2_orig_len:6;
    unsigned int t3_valid:1;
    unsigned int t3_type:2;
    unsigned int t3_dirty:1;
    unsigned int t3_orig_len:5;
};

#define PIF_PARREP_CTLDATA_OFF_LW 0
#define PIF_PARREP_CTLDATA_LEN_LW 1

/*
 * Parsed representation layout
 */

/* Parsed represention tier types */
/* tier 2 */
#define PIF_PARREP_TYPE_parse_ipv6 0
#define PIF_PARREP_TYPE_parse_ipv4 1
/* tier 3 */
#define PIF_PARREP_TYPE_parse_tcp 0
#define PIF_PARREP_TYPE_parse_udp 1
#define PIF_PARREP_TYPE_parse_icmp 2

/* Parse state values */
#define PIF_PARREP_STATE_DONE -1
#define PIF_PARREP_STATE_start 0
#define PIF_PARREP_STATE_parse_ethernet 1
#define PIF_PARREP_STATE_parse_ipv6 2
#define PIF_PARREP_STATE_parse_ipv4 3
#define PIF_PARREP_STATE_parse_tcp 4
#define PIF_PARREP_STATE_parse_udp 5
#define PIF_PARREP_STATE_parse_icmp 6
#define PIF_PARREP_STATE__condition_0 (PIF_PARREP_STATE_DONE)

/* Tier 0 */
#define PIF_PARREP_T0_OFF_LW 1
#define PIF_PARREP_T0_LEN_LW 0

/* Tier 1 */
#define PIF_PARREP_T1_OFF_LW 1
#define PIF_PARREP_T1_LEN_LW 4
#define PIF_PARREP_ethernet_OFF_LW (PIF_PARREP_T1_OFF_LW + 0)
#define PIF_PARREP_ethernet_LEN_LW 4
#define PIF_PARREP_ethernet_LEN_B 14

/* Tier 2 */
#define PIF_PARREP_T2_OFF_LW 5
#define PIF_PARREP_T2_LEN_LW 10
#define PIF_PARREP_ipv6_OFF_LW (PIF_PARREP_T2_OFF_LW + 0)
#define PIF_PARREP_ipv6_LEN_LW 10
#define PIF_PARREP_ipv6_LEN_B 40
#define PIF_PARREP_ipv4_OFF_LW (PIF_PARREP_T2_OFF_LW + 0)
#define PIF_PARREP_ipv4_LEN_LW 5
#define PIF_PARREP_ipv4_LEN_B 20

/* Tier 3 */
#define PIF_PARREP_T3_OFF_LW 15
#define PIF_PARREP_T3_LEN_LW 5
#define PIF_PARREP_tcp_OFF_LW (PIF_PARREP_T3_OFF_LW + 0)
#define PIF_PARREP_tcp_LEN_LW 5
#define PIF_PARREP_tcp_LEN_B 20
#define PIF_PARREP_udp_OFF_LW (PIF_PARREP_T3_OFF_LW + 0)
#define PIF_PARREP_udp_LEN_LW 2
#define PIF_PARREP_udp_LEN_B 8
#define PIF_PARREP_icmp_OFF_LW (PIF_PARREP_T3_OFF_LW + 0)
#define PIF_PARREP_icmp_LEN_LW 1
#define PIF_PARREP_icmp_LEN_B 4

/*
 * Metadata
 */

#define PIF_PARREP_standard_metadata_OFF_LW 20
#define PIF_PARREP_standard_metadata_LEN_LW 4

#define PIF_PARREP_LEN_LW 24

/* Parsing branches to a constant control entry point */
#define PIF_PARREP_NO_VARIABLE_EXIT

/* Control data macros */
#define PIF_PARREP_VALID(_ctl) (_ctl->valid)
#define PIF_PARREP_SET_VALID(_ctl) \
    do { _ctl->valid = 1; } while (0)

/* Tier 1 */
#define PIF_PARREP_T1_TYPE(ctl) ( ((ctl)->t1_type))
#define PIF_PARREP_T1_VALID(ctl) ( ((ctl)->t1_valid))
#define PIF_PARREP_ethernet_VALID(ctl) ( ((ctl)->t1_valid) )
#define PIF_PARREP_SET_ethernet_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ethernet_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 0; \
    } while(0);

#define PIF_PARREP_ethernet_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_T1_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_CLEAR_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_DIRTY(_ctl) \
    do { \
        (_ctl)->t1_dirty = 1; \
    } while(0);

#define PIF_PARREP_T1_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_SET_T1_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ethernet_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_CLEAR_ethernet_ORIG_LEN(ctl) \
    do { \
        (ctl)->t1_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = 1; \
    } while(0);

/* Tier 2 */
#define PIF_PARREP_T2_TYPE(ctl) ( ((ctl)->t2_type))
#define PIF_PARREP_T2_VALID(ctl) ( ((ctl)->t2_valid & 0x1) )
#define PIF_PARREP_ipv6_VALID(ctl) ( ((ctl)->t2_valid & 0x1) && ((ctl)->t2_type == PIF_PARREP_TYPE_parse_ipv6) )
#define PIF_PARREP_SET_ipv6_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
        (ctl)->t2_type = PIF_PARREP_TYPE_parse_ipv6; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv6_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);
#define PIF_PARREP_ipv4_VALID(ctl) ( ((ctl)->t2_valid & 0x1) && ((ctl)->t2_type == PIF_PARREP_TYPE_parse_ipv4) )
#define PIF_PARREP_SET_ipv4_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
        (ctl)->t2_type = PIF_PARREP_TYPE_parse_ipv4; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv4_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv6_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_ipv4_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_T2_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_CLEAR_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_ipv4_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);

#define PIF_PARREP_T2_ORIG_LEN(ctl) ((ctl)->t2_orig_len)
#define PIF_PARREP_SET_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len += len; \
    } while(0);
#define PIF_PARREP_ipv6_ORIG_LEN(ctl) ((ctl)->t2_orig_len)
#define PIF_PARREP_CLEAR_ipv6_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_ipv6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len += len; \
    } while(0);
#define PIF_PARREP_ipv4_ORIG_LEN(ctl) ((ctl)->t2_orig_len)
#define PIF_PARREP_CLEAR_ipv4_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len += len; \
    } while(0);

/* Tier 3 */
#define PIF_PARREP_T3_TYPE(ctl) ( ((ctl)->t3_type))
#define PIF_PARREP_T3_VALID(ctl) ( ((ctl)->t3_valid & 0x1) )
#define PIF_PARREP_tcp_VALID(ctl) ( ((ctl)->t3_valid & 0x1) && ((ctl)->t3_type == PIF_PARREP_TYPE_parse_tcp) )
#define PIF_PARREP_SET_tcp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
        (ctl)->t3_type = PIF_PARREP_TYPE_parse_tcp; \
    } while(0);
#define PIF_PARREP_CLEAR_tcp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);
#define PIF_PARREP_udp_VALID(ctl) ( ((ctl)->t3_valid & 0x1) && ((ctl)->t3_type == PIF_PARREP_TYPE_parse_udp) )
#define PIF_PARREP_SET_udp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
        (ctl)->t3_type = PIF_PARREP_TYPE_parse_udp; \
    } while(0);
#define PIF_PARREP_CLEAR_udp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);
#define PIF_PARREP_icmp_VALID(ctl) ( ((ctl)->t3_valid & 0x1) && ((ctl)->t3_type == PIF_PARREP_TYPE_parse_icmp) )
#define PIF_PARREP_SET_icmp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
        (ctl)->t3_type = PIF_PARREP_TYPE_parse_icmp; \
    } while(0);
#define PIF_PARREP_CLEAR_icmp_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);

#define PIF_PARREP_tcp_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_udp_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_icmp_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_T3_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_CLEAR_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_udp_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_icmp_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);

#define PIF_PARREP_T3_ORIG_LEN(ctl) ((ctl)->t3_orig_len)
#define PIF_PARREP_SET_T3_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T3_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len += len; \
    } while(0);
#define PIF_PARREP_tcp_ORIG_LEN(ctl) ((ctl)->t3_orig_len)
#define PIF_PARREP_CLEAR_tcp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len += len; \
    } while(0);
#define PIF_PARREP_udp_ORIG_LEN(ctl) ((ctl)->t3_orig_len)
#define PIF_PARREP_CLEAR_udp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len += len; \
    } while(0);
#define PIF_PARREP_icmp_ORIG_LEN(ctl) ((ctl)->t3_orig_len)
#define PIF_PARREP_CLEAR_icmp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_icmp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_icmp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len += len; \
    } while(0);



void pif_value_set_scan_configs();

#endif /* __PIF_PARREP_H__ */
