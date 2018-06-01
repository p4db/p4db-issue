/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/me.h>
#include "pif_common.h"

/****************************************
 * ingress_flow                         *
 ****************************************/

/* State transition functions */

static int handle_ingress_flow_forward_mat(__lmem uint32_t *parrep, __mem uint32_t *actbuf, unsigned int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_forward_mat");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_forward_mat, parrep, actbuf);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        ret = pif_action_execute(parrep, actbuf, *actlen);
        if (ret < 0)
            return -1;
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow_ternary_match_mat(__lmem uint32_t *parrep, __mem uint32_t *actbuf, unsigned int *actlen, int *state)
{
    __gpr int action_id, ret;
    int next_state = PIF_CTLFLOW_STATE_ingress_flow_DONE;

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow_ternary_match_mat");
#endif

    {
        struct pif_lookup_result result;
        result = pif_lookup(PIF_TABLE_ID_ternary_match_mat, parrep, actbuf);
        action_id = result.action_id;
        *actlen = result.action_len;
    }

    next_state = PIF_CTLFLOW_STATE_ingress_flow_exit_control_flow; /* always */

    if (*actlen > 0) {
        ret = pif_action_execute(parrep, actbuf, *actlen);
        if (ret < 0)
            return -1;
    }

    *state = next_state;
    return 0;
}

static int handle_ingress_flow__condition_0(__lmem uint32_t *parrep)
{
    unsigned int pif_expression__condition_0_register_2;
    __lmem struct pif_parrep_ctldata *prdata = (__lmem struct pif_parrep_ctldata *)(parrep + PIF_PARREP_CTLDATA_OFF_LW);

#ifdef PIF_DEBUG
    __debug_label("pif_ctlflow_state_ingress_flow__condition_0");
#endif

    //expression _condition_0: (valid(ipv6)) and (valid(tcp))
    {
    unsigned int pif_expression__condition_0_register_0;
    unsigned int pif_expression__condition_0_register_1;
    //subexpression 1: valid(ipv6)
    pif_expression__condition_0_register_0 = PIF_PARREP_ipv6_VALID(prdata);
    //subexpression 2: valid(tcp)
    pif_expression__condition_0_register_1 = PIF_PARREP_tcp_VALID(prdata);
    //subexpression 0: (valid(ipv6))and(valid(tcp))
    pif_expression__condition_0_register_2 = (pif_expression__condition_0_register_0) && (pif_expression__condition_0_register_1);
    }

    if (pif_expression__condition_0_register_2)
        return PIF_CTLFLOW_STATE_ingress_flow_ternary_match_mat;
    else
        return PIF_CTLFLOW_STATE_ingress_flow_forward_mat;
}

/* Control flow entry point */

int pif_ctlflow_ingress_flow(int *start_state, __lmem uint32_t *parrep, __mem uint32_t *actbuf)
{
    __gpr unsigned int actlen, totlen = 0;
    __gpr int ret;
    int pif_ctlflow_state_ingress_flow = PIF_CTLFLOW_STATE_ingress_flow__condition_0;

    while (pif_ctlflow_state_ingress_flow != PIF_CTLFLOW_STATE_ingress_flow_DONE) {
        PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_CONTROL, ((0 << 16) + pif_ctlflow_state_ingress_flow));
#ifdef PIF_DEBUG
        __debug_label("pif_ctlflow_state_ingress_flow");
#endif
        switch (pif_ctlflow_state_ingress_flow) {
        case PIF_CTLFLOW_STATE_ingress_flow_forward_mat:
            ret = handle_ingress_flow_forward_mat(parrep, actbuf + totlen, (unsigned int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow_ternary_match_mat:
            ret = handle_ingress_flow_ternary_match_mat(parrep, actbuf + totlen, (unsigned int *)&actlen, (int *)&pif_ctlflow_state_ingress_flow);
            break;
        case PIF_CTLFLOW_STATE_ingress_flow__condition_0:
            pif_ctlflow_state_ingress_flow = handle_ingress_flow__condition_0(parrep);
            continue;
        }
        totlen += actlen;
        if (ret < 0)
            return -totlen;
    }

    return totlen;
}

/* Empty control flow */
int pif_ctlflow_egress_flow(int *start_state, __lmem uint32_t *parrep, __mem uint32_t *actbuf)
{
    return 0;
}
