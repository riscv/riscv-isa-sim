// vsgt.vi  vd, vs2, simm5
VI_VI_LOOP_CMP
({
  res = vs2 > vsext(simm5, 5);
})
VI_CHECK_1905
