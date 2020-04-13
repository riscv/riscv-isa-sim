//vfslide1up.vf vd, vs2, rs1
VI_CHECK_SLIDE(true);

VI_VFP_LOOP_BASE
if (i != 0) {
  switch (P.VU.vsew) {
    case e32: {
      VI_XI_SLIDEUP_PARAMS(e32, 1);
      vd = vs2;
    }
    break;
    case e64: {
      VI_XI_SLIDEUP_PARAMS(e64, 1);
      vd = vs2;
    }
    break;
  }
} else {
  switch (P.VU.vsew) {
    case e32:
      P.VU.elt<float32_t>(rd_num, 0) = f32(FRS1);
      break;
    case e64:
      P.VU.elt<float64_t>(rd_num, 0) = f64(FRS1);
      break;
  }
}
VI_VFP_LOOP_END
