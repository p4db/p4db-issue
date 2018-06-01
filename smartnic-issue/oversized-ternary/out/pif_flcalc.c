/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include "pif_common.h"

uint16_t ipv4_checksum(__lmem uint32_t *parrep, __lmem struct pif_parrep_ctldata *ctldata)
{
    __gpr uint16_t calc_fld = PIF_FLCALC_CSUM16_INIT;
    __lmem struct pif_field_list_ipv4_checksum_list_packed input_ipv4_checksum_list;
    __lmem struct pif_header_ipv4 *ipv4 = (__lmem struct pif_header_ipv4 *)(parrep + PIF_PARREP_ipv4_OFF_LW);

    input_ipv4_checksum_list.ipv4__version = ipv4->version;
    input_ipv4_checksum_list.ipv4__ihl = ipv4->ihl;
    input_ipv4_checksum_list.ipv4__diffserv = ipv4->diffserv;
    input_ipv4_checksum_list.ipv4__totalLen = ipv4->totalLen;
    input_ipv4_checksum_list.ipv4__identification = ipv4->identification;
    input_ipv4_checksum_list.ipv4__flags = ipv4->flags;
    input_ipv4_checksum_list.ipv4__fragOffset = ipv4->fragOffset;
    input_ipv4_checksum_list.ipv4__ttl = ipv4->ttl;
    input_ipv4_checksum_list.ipv4__protocol = ipv4->protocol;
    input_ipv4_checksum_list.ipv4__srcAddr = ipv4->srcAddr;
    input_ipv4_checksum_list.ipv4__dstAddr = ipv4->dstAddr;

    calc_fld = pif_flcalc_csum16_lmem(calc_fld, (__lmem uint32_t *) input_ipv4_checksum_list._raw, 18);
    calc_fld = (~calc_fld & 0xffff);
    return calc_fld;
}

int pif_flcalc_verify(__lmem uint32_t *parrep)
{
    __lmem struct pif_parrep_ctldata *ctldata = (__lmem struct pif_parrep_ctldata *)(parrep + PIF_PARREP_CTLDATA_OFF_LW);

    /* ipv4.hdrChecksum */
    {
        __lmem struct pif_header_ipv4 *ipv4 = (__lmem struct pif_header_ipv4 *)(parrep + PIF_PARREP_ipv4_OFF_LW);
        if (PIF_PARREP_ipv4_VALID(ctldata) && (ipv4->ihl == 0x5)) {
            uint16_t calc_fld;
            calc_fld = ipv4_checksum(parrep, ctldata);
            if (calc_fld != ipv4->hdrChecksum)
                return -PIF_PARSE_ERROR_CHECKSUM;
        }
    }

    /* Enable incremental updates for supported calculated fields. */
    PIF_FLCALC_UPD_INCR_SET(PIF_FLCALC_IPV4_CHECKSUM);

    return 0;
}

void pif_flcalc_update(__lmem uint32_t *parrep)
{
    __lmem struct pif_parrep_ctldata *ctldata = (__lmem struct pif_parrep_ctldata *)(parrep + PIF_PARREP_CTLDATA_OFF_LW);

    /* ipv4.hdrChecksum */
    if (PIF_FLCALC_UPD_INCR(PIF_FLCALC_IPV4_CHECKSUM) == 0) {
        {
            __lmem struct pif_header_ipv4 *ipv4 = (__lmem struct pif_header_ipv4 *)(parrep + PIF_PARREP_ipv4_OFF_LW);
            if (PIF_PARREP_ipv4_VALID(ctldata)) {
                if (PIF_PARREP_ipv4_DIRTY(ctldata)) {
                    uint16_t calc_fld;
                    calc_fld = ipv4_checksum(parrep, ctldata);
                    ipv4->hdrChecksum = calc_fld;
                }
            }
        }
    }

}

