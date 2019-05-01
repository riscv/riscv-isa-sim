// vsw.v and vsseg[2-8]w.v
require(p->VU.vsew >= e32);
reg_t nf = insn.v_nf() + 1;
require((nf >= 2 && p->VU.vlmul == 1) || nf == 1);
reg_t vl = p->VU.vl;
reg_t baseAddr = RS1;
reg_t vs3 = insn.rd();
for (reg_t i = p->VU.vstart; i < vl; ++i){
  V_LOOP_ELEMENT_SKIP;

  for (reg_t fn = 0; fn < nf; ++fn){
    uint32_t val = 0;
    switch (p->VU.vsew) {
    case e32:
      val = p->VU.elt<uint32_t>(vs3 + fn, i);
      break;
    defaualt:
      val = p->VU.elt<uint64_t>(vs3 + fn, i);
      break;
    }
    MMU.store_uint32(baseAddr + (i * nf + fn) * 4, val);
  }
}
p->VU.vstart = 0;
