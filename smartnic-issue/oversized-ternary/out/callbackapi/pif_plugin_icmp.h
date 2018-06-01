/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_ICMP_H__
#define __PIF_PLUGIN_ICMP_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* icmp (4B) */
struct pif_plugin_icmp {
    unsigned int typeCode:16;
    unsigned int hdrChecksum:16;
};

/* icmp field accessor macros */
#define PIF_HEADER_GET_icmp___typeCode(_hdr_p) (((_hdr_p)->typeCode)) /* icmp.typeCode [16;0] */

#define PIF_HEADER_SET_icmp___typeCode(_hdr_p, _val) \
    do { \
        (_hdr_p)->typeCode = (unsigned)(((_val))); \
    } while (0) /* icmp.typeCode[16;0] */

#define PIF_HEADER_GET_icmp___hdrChecksum(_hdr_p) (((_hdr_p)->hdrChecksum)) /* icmp.hdrChecksum [16;0] */

#define PIF_HEADER_SET_icmp___hdrChecksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdrChecksum = (unsigned)(((_val))); \
    } while (0) /* icmp.hdrChecksum[16;0] */



#define PIF_PLUGIN_icmp_T __lmem struct pif_plugin_icmp

/*
 * Access function prototypes
 */

int pif_plugin_hdr_icmp_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_icmp_T *pif_plugin_hdr_get_icmp(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_icmp_T *pif_plugin_hdr_readonly_get_icmp(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_icmp_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_icmp_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

int pif_plugin_hdr_icmp_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_icmp_VALID(_ctl);
}

PIF_PLUGIN_icmp_T *pif_plugin_hdr_get_icmp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_icmp_DIRTY(_ctl);
    return (PIF_PLUGIN_icmp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_icmp_OFF_LW);
}

PIF_PLUGIN_icmp_T *pif_plugin_hdr_readonly_get_icmp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_icmp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_icmp_OFF_LW);
}

int pif_plugin_hdr_icmp_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not addable in the P4 design */
}

int pif_plugin_hdr_icmp_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    return -1; /* this header is not removable in the P4 design */
}

#endif /* __PIF_PLUGIN_ICMP_H__ */
