vector<string> microcode_instruction_names = {
    "rstp1", "halt1", "rstp3", "bser1", "abll3", "adrl2", "adrw1", "dbcc5", "ablw3", "abll2", "abwl1", "adrl1", "adsl2", "ablw2", "abww1", "pinl1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "mulm6", "ldmx3", "trpv3", "dvum3", "adrw2", "mmrw2", "adsl3", "ldmx1", "mmxw2", "jsrx2", "adsw2", "ldmx2", "mmxl2", "jmpx2", "ldmx5", "stmx3",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "asbb5", "dvs16", "dvs07", "push3", "btsr3", "bbci2", "dbcc2", "asxl6", "asxl2", "dvs20", "asxw4", "smaw3", "asxl5", "dvs17", "asbb4", "sccb3",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "mulm3", "asxl7", "asxl8", "dvs05", "rset5", "asxw5", "leaa2", "bclm2", "bbcw1", "bclm1", "bcsr2", "cmmw1", "dbcc1", "trpv1", "bclr2", "cmml1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvumf", "bcsm1", "bcsm2", "push5", "bcsr3", "bbcw3", "cmmw2", "cpdw1", "bser6", "bsri1", "dvs1f", "roaw2", "bclr3", "rcal3", "cmml2", "cpdl1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "mulm5", "bcsr5", "bser4", "dvs04", "dvum1", "stmr5", "dvur1", "e#l1",  "bsri3", "bsrw1", "bsrw3", "btsi1", "dvs01", "stmr6", "dvs02", "lmal2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvumd", "dvs1d", "dvs10", "push4", "bcsr4", "bbci3", "dbcc6", "dbcc4", "bclr5", "dvs03", "dvs1e", "sccr2", "bclr4", "dvs1a", "dvs1b", "sccb2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "mulm4", "ldmx4", "trpv2", "dvur2", "rset3", "stmr4", "dvuma", "btsr2", "mmxw3", "jsrx3", "e#w1",  "itlx4", "mmxl3", "jmpx3", "lmal3", "trap5",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "roaw1", "mmxw1", "bsri2", "pdcw1", "rcal1", "rmxl1", "peax6", "asbb1", "rcaw1", "rmxw1", "paaw2", "asxl1", "roal1", "mmxl1", "bsrw2", "asxw1",
    "chkr3", "ldmr2", "smal2", "asbb6", "rset4", "popm2", "rts2",  "nbcr2", "itlx6", "unlk1", "trap7", "rbrb2", "trap9", "zzz00", "rstpa", "zzz01",
    "aixl2", "rrgw1", "cmmw3", "popm1", "aixw2", "tsrl1", "rts1",  "ldmr1", "rmxw2", "rrgl1", "rtr1",  "rtr2",  "rmxl2", "tsrw1", "cmml4", "zzz02",
    "leax2", "asxw2", "asxw3", "nnrw1", "peax2", "asbb2", "asbb3", "nnrl1", "stmx4", "asxl3", "asxl4", "nbcr1", "zzz03", "zzz04", "zzz05", "zzz06",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "chkr4", "chkm1", "chkr1", "chkr2", "cmml3", "cmml5", "cmml6", "cmml7", "mrgm1", "mstw1", "mulm1", "mulr1", "nbcm1", "nnml2", "nnrl2", "paal2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "cmmw4", "cpdl2", "cpml2", "cprl2", "cprm2", "dbcc3", "dvs06", "dvs11", "paaw1", "pdcl1", "pdcl2", "pdcw2", "peaa1", "pead1", "pead2", "pead3",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "trac1", "rorw1", "adsw1", "romw1", "itlx1", "rorl1", "adsl1", "romm1", "rstp2", "rorm1", "mpow1", "roml1", "stiw1", "rbrb1", "mpol1", "cpmm1",
    "trap1", "cprw1", "mpiw1", "cpmw1", "zzz08", "cprl1", "mpil1", "cpml1", "zzz09", "cprm1", "zzz0a", "zzz0b", "zzz0c", "zzz0d", "zzz0e", "zzz0f",
    "aixl5", "malw3", "abll1", "aixl0", "aixw4", "smal1", "ablw1", "aixw0", "rmxw3", "lmal1", "ralw1", "rmxw0", "rmxl3", "smaw1", "rall1", "rmxl0",
    "leax3", "stmd1", "jsal1", "jsrx0", "peax3", "ldmx0", "jmal1", "jmpx0", "stmx5", "lmaw1", "paal1", "leax0", "zzz10", "ldmd1", "unlk2", "peax0",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvs14", "dvs15", "dvum0", "dvum2", "dvs12", "btsm1", "dvs08", "dvur3", "peax4", "peax5", "pinl2", "pinl3", "pinw1", "pinw2", "push2", "push5",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "susp1", "exge2", "extr1", "extr2", "itlx2", "itlx3", "itlx5", "ldmd4", "rbrb3", "rcal2", "rcaw2", "rlql1", "rmil2", "rmil3", "rmml2", "rmrl2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvum9", "dvs1c", "dvum8", "nbcr3", "dvs13", "jmpa1", "jsal2", "srrl4", "rmrl3", "roal2", "roal3", "roal4", "roml2", "roml3", "rorl3", "rorm3",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "jsaw1", "jsaw2", "jsaw3", "jsra1", "jsrd2", "laaw1", "ldmd3", "ldmx6", "rrgl2", "rrgm1", "rrgw2", "rset2", "unlk3", "unlk4", "rstp5", "rstp6",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvume", "dvum5", "itlx7", "jsaw0", "dvs0f", "dvs09", "rstp4", "jmaw1", "mmxw0", "morw1", "mpiw2", "mrgw1", "mmxl0", "morl1", "mpil2", "mrgl1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "jsrd1", "jsrd3", "jsrx1", "jmal2", "jmpd1", "link2", "jmpx1", "trap8", "nnmw1", "o#w1",  "rall3", "ralw2", "nnml1", "laal2", "rmdl2", "rall2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "dvum6", "dvum4", "dvum7", "srrw3", "dvs0a", "dvumz", "dvs0c", "srrl3", "raqw1", "raww1", "rmdw1", "rmdw2", "raql1", "rawl1", "rmdl1", "rmdl3",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "ldmr5", "leaa1", "lead1", "maqw1", "popm5", "lusp1", "ldmd2", "maql1", "rmmw1", "rmrl1", "rmrw1", "rstp7", "rmml1", "rmil1", "rmiw1", "rstp8",
    "rstp9", "rstw1", "rtr4",  "rts3",  "stmw2", "smal3", "srrl5", "stiw2", "bbci1", "lead2", "leax4", "link1", "link3", "link4", "lmaw2", "mall1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "stiw3", "stiw4", "stmd3", "stmr2", "sftm2", "stmx1", "stmx2", "aaa01", "mmaw2", "mall2", "mall3", "malw1", "popm6", "dvs0e", "malw2", "mawl2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "strw2", "swap1", "swap2", "tasm1", "tasm2", "tasr1", "tasr2", "trap2", "mawl3", "mmiw2", "mmml2", "mmmw2", "mmrw3", "morl2", "mpil3", "mpil4",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "trap4", "tsml2", "tsrl2", "b",     "zzz11", "zzz12", "zzz13", "trap6", "mpiw3", "dvumc", "mpiw4", "mpol2", "mpol3", "mpow2", "mpow3", "mrgl2",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "sccb1", "srrw1", "sriw1", "srrw2", "sccr1", "srrl1", "sril1", "srrl2", "maww1", "maww2", "mmdw1", "mmmw1", "mawl1", "morw2", "mmdl1", "mmml1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "stmr1", "stmw1", "stop1", "trac2", "push1", "strw1", "rset1", "bser2", "ldmr4", "mmrl1", "mmrl2", "mmrw1", "popm4", "mmil1", "mmil2", "mmiw1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "rorl2", "smaw2", "trap3", "tsmw1", "mulm2", "rtr3",  "bser5", "sftm1", "rorm2", "stmd2", "bser3", "tsml1", "zzz14", "zzz15", "zzz16", "zzz17",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",
    "o#l1",  "zzz18", "aixl1", "exge1", "laal1", "zzz19", "aixw1", "btsr1", "ldmr3", "dvumb", "leax1", "bclr1", "popm3", "dvs0d", "peax1", "bcsr1",
    "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-",     "-"
};