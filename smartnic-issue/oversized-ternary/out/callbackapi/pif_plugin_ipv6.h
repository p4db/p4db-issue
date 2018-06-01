/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_IPV6_H__
#define __PIF_PLUGIN_IPV6_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* ipv6 (40B) */
struct pif_plugin_ipv6 {
    unsigned int version:4;
    unsigned int trafficClass:8;
    unsigned int flowLabel:20;
    unsigned int payloadLen:16;
    unsigned int nextHdr:8;
    unsigned int hopLimit:8;
    /* srcAddr [32;96] */
    unsigned int __srcAddr_0:32;
    /* srcAddr [32;64] */
    unsigned int __srcAddr_1:32;
    /* srcAddr [32;32] */
    unsigned int __srcAddr_2:32;
    /* srcAddr [32;0] */
    unsigned int __srcAddr_3:32;
    /* dstAddr [32;96] */
    unsigned int __dstAddr_0:32;
    /* dstAddr [32;64] */
    unsigned int __dstAddr_1:32;
    /* dstAddr [32;32] */
    unsigned int __dstAddr_2:32;
    /* dstAddr [32;0] */
    unsigned int __dstAddr_3:32;
};

/* ipv6 field accessor macros */
#define PIF_HEADER_GET_ipv6___version(_hdr_p) (((_hdr_p)->version)) /* ipv6.version [4;0] */

#define PIF_HEADER_SET_ipv6___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv6.version[4;0] */

#define PIF_HEADER_GET_ipv6___trafficClass(_hdr_p) (((_hdr_p)->trafficClass)) /* ipv6.trafficClass [8;0] */

#define PIF_HEADER_SET_ipv6___trafficClass(_hdr_p, _val) \
    do { \
        (_hdr_p)->trafficClass = (unsigned)(((_val))); \
    } while (0) /* ipv6.trafficClass[8;0] */

#define PIF_HEADER_GET_ipv6___flowLabel(_hdr_p) (((_hdr_p)->flowLabel)) /* ipv6.flowLabel [20;0] */

#define PIF_HEADER_SET_ipv6___flowLabel(_hdr_p, _val) \
    do { \
        (_hdr_p)->flowLabel = (unsigned)(((_val))); \
    } while (0) /* ipv6.flowLabel[20;0] */

#define PIF_HEADER_GET_ipv6___payloadLen(_hdr_p) (((_hdr_p)->payloadLen)) /* ipv6.payloadLen [16;0] */

#define PIF_HEADER_SET_ipv6___payloadLen(_hdr_p, _val) \
    do { \
        (_hdr_p)->payloadLen = (unsigned)(((_val))); \
    } while (0) /* ipv6.payloadLen[16;0] */

#define PIF_HEADER_GET_ipv6___nextHdr(_hdr_p) (((_hdr_p)->nextHdr)) /* ipv6.nextHdr [8;0] */

#define PIF_HEADER_SET_ipv6___nextHdr(_hdr_p, _val) \
    do { \
        (_hdr_p)->nextHdr = (unsigned)(((_val))); \
    } while (0) /* ipv6.nextHdr[8;0] */

#define PIF_HEADER_GET_ipv6___hopLimit(_hdr_p) (((_hdr_p)->hopLimit)) /* ipv6.hopLimit [8;0] */

#define PIF_HEADER_SET_ipv6___hopLimit(_hdr_p, _val) \
    do { \
        (_hdr_p)->hopLimit = (unsigned)(((_val))); \
    } while (0) /* ipv6.hopLimit[8;0] */

#define PIF_HEADER_GET_ipv6___srcAddr___0(_hdr_p) (((_hdr_p)->__srcAddr_3)) /* ipv6.srcAddr [32;0] */

#define PIF_HEADER_SET_ipv6___srcAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6.srcAddr[32;0] */

#define PIF_HEADER_GET_ipv6___srcAddr___1(_hdr_p) (((_hdr_p)->__srcAddr_2)) /* ipv6.srcAddr [32;32] */

#define PIF_HEADER_SET_ipv6___srcAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6.srcAddr[32;32] */

#define PIF_HEADER_GET_ipv6___srcAddr___2(_hdr_p) (((_hdr_p)->__srcAddr_1)) /* ipv6.srcAddr [32;64] */

#define PIF_HEADER_SET_ipv6___srcAddr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6.srcAddr[32;64] */

#define PIF_HEADER_GET_ipv6___srcAddr___3(_hdr_p) (((_hdr_p)->__srcAddr_0)) /* ipv6.srcAddr [32;96] */

#define PIF_HEADER_SET_ipv6___srcAddr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->__srcAddr_0 = (unsigned)(((_val))); \
    } while (0) /* ipv6.srcAddr[32;96] */

#define PIF_HEADER_GET_ipv6___dstAddr___0(_hdr_p) (((_hdr_p)->__dstAddr_3)) /* ipv6.dstAddr [32;0] */

#define PIF_HEADER_SET_ipv6___dstAddr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dstAddr_3 = (unsigned)(((_val))); \
    } while (0) /* ipv6.dstAddr[32;0] */

#define PIF_HEADER_GET_ipv6___dstAddr___1(_hdr_p) (((_hdr_p)->__dstAddr_2)) /* ipv6.dstAddr [32;32] */

#define PIF_HEADER_SET_ipv6___dstAddr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dstAddr_2 = (unsigned)(((_val))); \
    } while (0) /* ipv6.dstAddr[32;32] */

#define PIF_HEADER_GET_ipv6___dstAddr___2(_hdr_p) (((_hdr_p)->__dstAddr_1)) /* ipv6.dstAddr [32;64] */

#define PIF_HEADER_SET_ipv6___dstAddr___2(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dstAddr_1 = (unsigned)(((_val))); \
    } while (0) /* ipv6.dstAddr[32;64] */

#define PIF_HEADER_GET_ipv6___dstAddr___3(_hdr_p) (((_hdr_p)->__dstAddr_0)) /* ipv6.dstAddr [32;96] */

#define PIF_HEADER_SET_ipv6___dstAddr___3(_hdr_p, _val) \
    do { \
        (_hdr_p)->__dstAddr_0 = (unsigned)(((_val))); \
    } while (0) /* ipv6.dstAddr[32;96] */



#define PIF_PLUGIN_ipv6_T __lmem struct pif_plugin_ipv6

/*
 * Access function prototypes
 */

int pif_plugin_hdr_ipv6_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv6_T *pif_plugin_hdr_get_ipv6(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv6_T *pif_plugin_hdr_readonly_get_ipv6(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv6_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv6_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

int pif_plugin_hdr_ipv6_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_ipv6_VALID(_ctl);
}

PIF_PLUGIN_ipv6_T *pif_plugin_hdr_get_ipv6(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_ipv6_DIRTY(_ctl);
    return (PIF_PLUGIN_ipv6_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv6_OFF_LW);
}

PIF_PLUGIN_ipv6_T *pif_plugin_hdr_readonly_get_ipv6(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_ipv6_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv6_OFF_LW);
}

int pif_plugin_hdr_ipv6_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

int pif_plugin_hdr_ipv6_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_IPV6_H__ */
