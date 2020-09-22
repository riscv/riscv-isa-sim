require_extension('S');
if (STATE.v && (STATE.prv == PRV_U || get_field(STATE.hstatus, HSTATUS_VTVM)))
  require_novirt();
require_privilege(get_field(STATE.mstatus, MSTATUS_TVM) ? PRV_M : PRV_S);
MMU.flush_tlb();
