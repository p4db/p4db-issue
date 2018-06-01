/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_GLOBAL_H__
#define __PIF_GLOBAL_H__

#define PIF_GLOBAL_FLOWKEY_MAX_LW 10
__packed_bits struct pif_global_flowkey_parse_ipv6 {
    unsigned int ipv6____dstAddr_0:32;
    unsigned int ipv6____dstAddr_1:32;
    unsigned int ipv6____dstAddr_2:32;
    unsigned int ipv6____dstAddr_3:32;
    unsigned int ipv6____srcAddr_0:32;
    unsigned int ipv6____srcAddr_1:32;
    unsigned int ipv6____srcAddr_2:32;
    unsigned int ipv6____srcAddr_3:32;
};

__packed_bits struct pif_global_flowkey_parse_tcp {
    unsigned int tcp__srcPort:16;
    unsigned int tcp__dstPort:16;
};


void pif_global_metadata_init(__lmem uint32_t *parrep);

unsigned int pif_global_get_stdmd_egress_spec(__lmem uint32_t *parrep);
unsigned int pif_global_get_stdmd_egress_port(__lmem uint32_t *parrep);
void pif_global_set_stdmd_egress_port(__lmem uint32_t *parrep, unsigned int port_spec);
void pif_global_set_stdmd_instance_type(__lmem uint32_t *parrep, unsigned int instance_type);
void pif_global_set_stdmd_egress_instance(__lmem uint32_t *parrep, unsigned int egress_instance);

#endif /* __PIF_GLOBAL_H__ */
