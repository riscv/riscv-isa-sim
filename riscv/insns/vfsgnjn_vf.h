// vfsgnn
VFP_VF_LOOP
({
  switch(p->VU.vsew){
  case e32:
    vd = fsgnj32(rs1.v, vs2.v, true, false);
    break;
  case e16:
  case e8:
  default:
    softfloat_exceptionFlags = 1;
  };
})
