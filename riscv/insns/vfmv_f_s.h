// vfmv_f_s: rd = vs2[0] (rs1=0)
require_fp;
require(STATE.VU.vsew == e8 || STATE.VU.vsew == e16 || STATE.VU.vsew == e32 || STATE.VU.vsew == e64); 

reg_t rs2_num = insn.rs2(); 
uint64_t vs2_0 = 0;
const reg_t sew = STATE.VU.vsew;
switch(sew) {
case e8:
  vs2_0 = STATE.VU.elt<uint8_t>(rs2_num, 0);
  break;
case e16:
  vs2_0 = STATE.VU.elt<uint16_t>(rs2_num, 0);
  break;
case e32:
  vs2_0 = STATE.VU.elt<uint32_t>(rs2_num, 0);
  break;
default:
  vs2_0 = STATE.VU.elt<uint64_t>(rs2_num, 0);
  break;
}

// nan_extened
if (FLEN >= sew) {
  vs2_0 = vs2_0 | ~((1ul << sew) - 1);
}

if (FLEN == 64) {
  WRITE_FRD(f64(vs2_0));
} else {
  WRITE_FRD(f32(vs2_0));
}
