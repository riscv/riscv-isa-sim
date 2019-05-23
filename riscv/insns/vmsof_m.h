// vmsof.m rd, vs2, vm
require(p->VU.vsew >= e8 && p->VU.vsew <= e64);
require(!p->VU.vill);
reg_t vl = p->VU.vl;
reg_t sew = p->VU.vsew;
reg_t rd_num = insn.rd();
reg_t rs1_num = insn.rs1();
reg_t rs2_num = insn.rs2();

bool has_one = false;
for (reg_t i = P.VU.vstart ; i < vl; ++i) {
  const int mlen = p->VU.vmlen;
  const int midx = (mlen * i) / 64;
  const int mpos = (mlen * i) % 64;
  const uint64_t mmask = (UINT64_MAX << (64 - mlen)) >> (64 - mlen - mpos);

  bool vs2_lsb = ((p->VU.elt<uint64_t>(rs2_num, midx ) >> mpos) & 0x1) == 1;
  bool do_mask = (p->VU.elt<uint64_t>(0, midx) >> mpos) & 0x1;
  uint64_t &vd = P.VU.elt<uint64_t>(rd_num, midx);

  if (insn.v_vm() == 1 || (insn.v_vm() == 0 && do_mask)) {
    uint64_t res = 0;
    if(!has_one && vs2_lsb) {
      has_one = true;
      res = 1;
    }
    vd = (vd & ~mmask) | ((res << mpos) & mmask);
  }
}

VI_TAIL_ZERO_MASK;
p->VU.vstart = 0;
VI_CHECK_1905
