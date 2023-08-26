#define getCycle(state, cycle)    (((cycle) << 6) | (state))

void m68kResetDpProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2 rstp3
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 296 rstp4
	    reg_ird = reg_ir;
	    setIntState();
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    setTrace();
	    // 27e rstp5
	    trapExcept(0x00);
	    reg_ftu = 0x0000;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 27f rstp6
	    initST();
	    reg_sr |= 0x700;
	    updateInterrupts();
	    reg_au = ext32(reg_ftu);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 2fb rstp7
	    reg_aob = reg_au;
	    setReg16High(reg_da[16], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, true);
	    setCritical();
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2ff rstp8
	    reg_aob = reg_au;
	    setReg16High(reg_da[16], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, true);
	    setCritical();
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 300 rstp9
	    reg_aob = reg_au;
	    initST();
	    setReg16Low(reg_da[16], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, true);
	    setCritical();
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    clearTrace();
	    // 11e rstpa
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, true);
	    setCritical();
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 2b7 trap8
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, true);
	    setCritical();
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    // 11c trap9
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, true);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kDoubleFaultDpProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1 halt1
	    return;
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kInterruptDpProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c4 itlx1
	    reg_ftu = reg_sr;
	    reg_au = reg_pc - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 234 itlx2
	    initST();
	    reg_alub = reg_ftu;
	    reg_pc = reg_au;
	    reg_sr = ((reg_sr & ~0x700) | ((next_state >> 16) & 0x700));
	    updateInterrupts();
	    runALU(AluAnd, reg_au, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 235 itlx3
	    reg_ftu = (0xfff0 | ((next_state >> 23) & 0xE));
	    reg_au = reg_da[16] - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // eb itlx4
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_at = ext32(reg_ftu);
	    reg_au = reg_au - 4;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(true, false, false, true);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 236 itlx5
	    reg_aob = reg_at;
	    setFC(true, true, true, true);
	    startIRQVectorLookup();
	    readWordCPU();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    endIRQVectorLookup();
	    reg_irc = reg_edb;
	    // 118 itlx6
	    reg_ir = reg_irc;
	    updateIPL();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 292 itlx7
	    reg_ird = reg_ir;
	    setIntState();
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    setTrace();
	    // 360 trap4
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    trapExcept(reg_int_vec);
	    reg_da[16] = reg_au;
	    reg_ftu = reg_int_vec;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_pc), 0xFFFF);
	    setFC(true, false, false, true);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    // ef trap5
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_at = ext32(reg_ftu);
	    reg_au = reg_au - 4;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(true, false, false, true);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 367 trap6
	    reg_aob = reg_at;
	    reg_pc = reg_at;
	    reg_au = reg_at + 2;
	    setFC(true, false, true, true);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    reg_dbin = reg_edb;
	    // 11a trap7
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(true, false, true, true);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    reg_dbin = reg_edb;
	    // 2b7 trap8
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, true);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 37):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 38):
	{
	    reg_irc = reg_edb;
	    // 11c trap9
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 39):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 40):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, true);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 41):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 42):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 43):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 44):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluOrByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kOriByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kOriByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kOriByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriImm8CcrProgram()
{
    unknownInstr();
}

void m68kOriWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluOr, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kOriWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kOriWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kOriWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOr, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOr, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriI16uSrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1cc stiw1
	    reg_ftu = reg_sr;
	    reg_au = reg_pc - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 307 stiw2
	    runALU(AluOr, reg_ftu, reg_dt);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 320 stiw3
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_aluo;
	    reg_au = reg_au + 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 10c roal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluOr, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluOr, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluOr, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kOriLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluOr, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluOr, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kOriLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOr, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluOr, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kOriLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOr, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOr, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluOr, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdDsProgram()
{
    unknownInstr();
}

void m68kMovepWordDasDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1d2 mpiw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 29a mpiw2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    setReg8High(reg_dbin, reg_edb);
	    // 368 mpiw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setReg8(reg_dbin, reg_edb);
	    // 36a mpiw4
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdAisProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdAipsProgram()
{
    unknownInstr();
}

void m68kBtstDdPaisProgram()
{
    unknownInstr();
}

void m68kBtstDdDasProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdDaisProgram()
{
    unknownInstr();
}

void m68kBtstDdAdr16Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdAdr32Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdDpcProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstDdDpciProgram()
{
    unknownInstr();
}

void m68kBtstDdImmProgram()
{
    unknownInstr();
}

void m68kBchgDdDsProgram()
{
    unknownInstr();
}

void m68kMovepLongDasDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1d6 mpil1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 29e mpil2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    setReg8High(reg_dbin, reg_edb);
	    // 34e mpil3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setReg8(reg_dbin, reg_edb);
	    // 34f mpil4
	    reg_aob = reg_au;
	    setReg16High(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setReg8High(reg_dbin, reg_edb);
	    // 368 mpiw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setReg8(reg_dbin, reg_edb);
	    // 36a mpiw4
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgDdAisProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgDdAipsProgram()
{
    unknownInstr();
}

void m68kBchgDdPaisProgram()
{
    unknownInstr();
}

void m68kBchgDdDasProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgDdDaisProgram()
{
    unknownInstr();
}

void m68kBchgDdAdr16Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgDdAdr32Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrDdDsProgram()
{
    unknownInstr();
}

void m68kMovepWordDdDasProgram()
{
    unknownInstr();
}

void m68kBclrDdAisProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrDdAipsProgram()
{
    unknownInstr();
}

void m68kBclrDdPaisProgram()
{
    unknownInstr();
}

void m68kBclrDdDasProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrDdDaisProgram()
{
    unknownInstr();
}

void m68kBclrDdAdr16Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOrByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrDdAdr32Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOrByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetDdDsProgram()
{
    unknownInstr();
}

void m68kMovepLongDdDasProgram()
{
    unknownInstr();
}

void m68kBsetDdAisProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetDdAipsProgram()
{
    unknownInstr();
}

void m68kBsetDdPaisProgram()
{
    unknownInstr();
}

void m68kBsetDdDasProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetDdDaisProgram()
{
    unknownInstr();
}

void m68kBsetDdAdr16Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOrByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetDdAdr32Program()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOrByte, reg_da[rx_index], reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluOrByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAndByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kAndiByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kAndiByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kAndiByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiImm8CcrProgram()
{
    unknownInstr();
}

void m68kAndiWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAnd, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kAndiWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kAndiWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kAndiWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiI16uSrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1cc stiw1
	    reg_ftu = reg_sr;
	    reg_au = reg_pc - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 307 stiw2
	    runALU(AluAnd, reg_ftu, reg_dt);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 320 stiw3
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_aluo;
	    reg_au = reg_au + 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 10c roal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAnd, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluAnd, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAnd, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kAndiLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAnd, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAnd, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kAndiLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAnd, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAndiLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAnd, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSubByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kSubiByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kSubiByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kSubiByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSub, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kSubiWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kSubiWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kSubiWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 10c roal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSub, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluSubc, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrXNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kSubiLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kSubiLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubiLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAddByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kAddiByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kAddiByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kAddiByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAdd, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kAddiWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kAddiWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kAddiWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 10c roal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluAdd, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluAddc, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrXNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kAddiLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kAddiLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddiLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAdd, reg_dt, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8DsProgram()
{
    unknownInstr();
}

void m68kBtstImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8AipsProgram()
{
    unknownInstr();
}

void m68kBtstImm8PaisProgram()
{
    unknownInstr();
}

void m68kBtstImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8DaisProgram()
{
    unknownInstr();
}

void m68kBtstImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8DpcProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 215 btsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBtstImm8DpciProgram()
{
    unknownInstr();
}

void m68kBchgImm8DsProgram()
{
    unknownInstr();
}

void m68kBchgImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgImm8AipsProgram()
{
    unknownInstr();
}

void m68kBchgImm8PaisProgram()
{
    unknownInstr();
}

void m68kBchgImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgImm8DaisProgram()
{
    unknownInstr();
}

void m68kBchgImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBchgImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrImm8DsProgram()
{
    unknownInstr();
}

void m68kBclrImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrImm8AipsProgram()
{
    unknownInstr();
}

void m68kBclrImm8PaisProgram()
{
    unknownInstr();
}

void m68kBclrImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrImm8DaisProgram()
{
    unknownInstr();
}

void m68kBclrImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBclrImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 69 bclm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_ftu = reg_sr;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    // 67 bclm2
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_aluo, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetImm8DsProgram()
{
    unknownInstr();
}

void m68kBsetImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetImm8AipsProgram()
{
    unknownInstr();
}

void m68kBsetImm8PaisProgram()
{
    unknownInstr();
}

void m68kBsetImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetImm8DaisProgram()
{
    unknownInstr();
}

void m68kBsetImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kBsetImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 81 bcsm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluXorByte, reg_dbin, (1 << (reg_dcr & 0x7)));
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 82 bcsm2
	    reg_aob = reg_at;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    runALU(AluAndByte, reg_alub, (1 << (reg_dcr & 0x7)));
	    updateCCR(CcrZ);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluXorByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kEoriByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kEoriByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kEoriByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXorByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriImm8CcrProgram()
{
    unknownInstr();
}

void m68kEoriWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 100 roaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluXor, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kEoriWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kEoriWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kEoriWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXor, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXor, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 299 morw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriI16uSrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1cc stiw1
	    reg_ftu = reg_sr;
	    reg_au = reg_pc - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 307 stiw2
	    runALU(AluXor, reg_ftu, reg_dt);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 320 stiw3
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_aluo;
	    reg_au = reg_au + 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 10c roal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluXor, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluXor, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluXor, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kEoriLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluXor, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluXor, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kEoriLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluXor, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluXor, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kEoriLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluXor, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 29d morl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluXor, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluXor, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiByteImm8DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 108 rcaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSubByte, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 23a rcaw2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiByteImm8AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiByteImm8AipsProgram()
{
    unknownInstr();
}

void m68kCmpiByteImm8PaisProgram()
{
    unknownInstr();
}

void m68kCmpiByteImm8DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiByteImm8DaisProgram()
{
    unknownInstr();
}

void m68kCmpiByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubByte, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiWordImm16DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 108 rcaw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSub, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 23a rcaw2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiWordImm16AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiWordImm16AipsProgram()
{
    unknownInstr();
}

void m68kCmpiWordImm16PaisProgram()
{
    unknownInstr();
}

void m68kCmpiWordImm16DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiWordImm16DaisProgram()
{
    unknownInstr();
}

void m68kCmpiWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 87 cpdw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 104 rcal1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSub, reg_dt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 239 rcal2
	    runALU(AluSubc, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8d rcal3
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 8f cpdl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 171 cpdl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32AipsProgram()
{
    unknownInstr();
}

void m68kCmpiLongImm32PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_dbin = reg_edb;
	    // 8f cpdl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 171 cpdl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 8f cpdl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 171 cpdl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32DaisProgram()
{
    unknownInstr();
}

void m68kCmpiLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 8f cpdl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 171 cpdl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kCmpiLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e0 o#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b9 o#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_dbin = reg_edb;
	    // 8f cpdl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_dt, reg_dbin);
	    updateCCR(CcrNZVC);
	    // 171 cpdl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluSubc, high16(reg_dt), reg_alue);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 121 rrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 27a rrgw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[rx_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg8(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsDdProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisDdProgram()
{
    unknownInstr();
}

void m68kMoveByteDasDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg8(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisDdProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg8(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg8(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg8(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciDdProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 121 rrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_dt;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 27a rrgw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[rx_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fa rmrw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsAidProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisAidProgram()
{
    unknownInstr();
}

void m68kMoveByteDasAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisAidProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciAidProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2fa rmrw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dt);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fe rmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsAipdProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveByteDasAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dbin);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciAipdProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2fe rmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dt);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index];
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAisPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAipsPaidProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDasPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16PaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr32PaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDpcPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDpciPaidProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8PaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDsDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2da rmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2db rmdw2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_da[ry_index]);
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsDadProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisDadProgram()
{
    unknownInstr();
}

void m68kMoveByteDasDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisDadProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciDadProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2da rmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 2db rmdw2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_dt);
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAisDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAipsDaidProgram()
{
    unknownInstr();
}

void m68kMoveBytePaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDasDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr16DaidProgram()
{
    unknownInstr();
}

void m68kMoveByteAdr32DaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDpcDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDpciDaidProgram()
{
    unknownInstr();
}

void m68kMoveByteImm8DaidProgram()
{
    unknownInstr();
}

void m68kMoveByteDsAdr16Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d9 raww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsAdr16Program()
{
    unknownInstr();
}

void m68kMoveBytePaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveByteDasAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveByteAdr16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciAdr16Program()
{
    unknownInstr();
}

void m68kMoveByteImm8Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2d9 raww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDsAdr32Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1ea ralw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bb ralw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAisAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAipsAdr32Program()
{
    unknownInstr();
}

void m68kMoveBytePaisAdr32Program()
{
    unknownInstr();
}

void m68kMoveByteDasAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDaisAdr32Program()
{
    unknownInstr();
}

void m68kMoveByteAdr16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteAdr32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpcAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveByteDpciAdr32Program()
{
    unknownInstr();
}

void m68kMoveByteImm8Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1ea ralw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bb ralw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAndByte, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    reg_da[rx_index] = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisDdProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsDdProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisDdProgram()
{
    unknownInstr();
}

void m68kMoveLongDasDdProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisDdProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16DdProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32DdProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcDdProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciDdProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_dt;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaLongDsAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaLongAsAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    reg_da[rx_index] = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaLongAisAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongAipsAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongPaisAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongDasAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongDaisAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongAdr16AdProgram()
{
    unknownInstr();
}

void m68kMoveaLongAdr32AdProgram()
{
    unknownInstr();
}

void m68kMoveaLongDpcAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongDpciAdProgram()
{
    unknownInstr();
}

void m68kMoveaLongImm32AdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 129 rrgl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_dt;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2f9 rmrl1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 23f rmrl2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2f9 rmrl1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 23f rmrl2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisAidProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsAidProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisAidProgram()
{
    unknownInstr();
}

void m68kMoveLongDasAidProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisAidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16AidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32AidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcAidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciAidProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2f9 rmrl1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_dt);
	    reg_alub = high16(reg_dt);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 23f rmrl2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_au = reg_pc;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fd rmil1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 23c rmil2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 23d rmil3
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fd rmil1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 23c rmil2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 23d rmil3
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongDasAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16AipdProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32AipdProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciAipdProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2fd rmil1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = high16(reg_dt);
	    reg_alub = high16(reg_dt);
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 23c rmil2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 23d rmil3
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAsPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAisPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDasPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16PaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32PaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciPaidProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32PaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDsDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2de rmdl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2be rmdl2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 2df rmdl3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2de rmdl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2be rmdl2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 2df rmdl3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisDadProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsDadProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisDadProgram()
{
    unknownInstr();
}

void m68kMoveLongDasDadProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisDadProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16DadProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32DadProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcDadProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciDadProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2de rmdl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 2be rmdl2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_dt);
	    reg_alub = high16(reg_dt);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 2df rmdl3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 258 rmrl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAsDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAisDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAipsDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongPaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDasDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr16DaidProgram()
{
    unknownInstr();
}

void m68kMoveLongAdr32DaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpcDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDpciDaidProgram()
{
    unknownInstr();
}

void m68kMoveLongImm32DaidProgram()
{
    unknownInstr();
}

void m68kMoveLongDsAdr16Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2dd rawl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2dd rawl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongAipsAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongPaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongDasAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongDaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongAdr16Adr16Program()
{
    unknownInstr();
}

void m68kMoveLongAdr32Adr16Program()
{
    unknownInstr();
}

void m68kMoveLongDpcAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongDpciAdr16Program()
{
    unknownInstr();
}

void m68kMoveLongImm32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2dd rawl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_dt);
	    reg_alub = high16(reg_dt);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDsAdr32Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1ee rall1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bf rall2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAsAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1ee rall1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bf rall2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_da[ry_index]);
	    reg_alub = high16(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAisAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAipsAdr32Program()
{
    unknownInstr();
}

void m68kMoveLongPaisAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDasAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDaisAdr32Program()
{
    unknownInstr();
}

void m68kMoveLongAdr16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongAdr32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 33):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 34):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 35):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 36):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDpcAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 30f mall1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 329 mall2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_dbout = reg_aluo;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    runALU(AluAnd, reg_at, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 32a mall3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 29):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 30):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 31):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 32):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveLongDpciAdr32Program()
{
    unknownInstr();
}

void m68kMoveLongImm32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a7 e#l1
	    reg_aob = reg_au;
	    setReg16High(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1ee rall1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bf rall2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 2ba rall3
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_dt);
	    reg_alub = high16(reg_dt);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 121 rrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 27a rrgw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[rx_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 121 rrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 27a rrgw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[rx_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsDdProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisDdProgram()
{
    unknownInstr();
}

void m68kMoveWordDasDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisDdProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_da[rx_index];
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcDdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 29b mrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciDdProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16DdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 121 rrgw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_dt;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 27a rrgw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[rx_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordDsAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 279 rrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = ext32(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordAsAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 279 rrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = ext32(reg_da[ry_index]);
	    reg_au = reg_au + 2;
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    reg_da[rx_index] = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordAisAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 158 mrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordAipsAdProgram()
{
    unknownInstr();
}

void m68kMoveaWordPaisAdProgram()
{
    unknownInstr();
}

void m68kMoveaWordDasAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 158 mrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordDaisAdProgram()
{
    unknownInstr();
}

void m68kMoveaWordAdr16AdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 158 mrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordAdr32AdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 158 mrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordDpcAdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 158 mrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveaWordDpciAdProgram()
{
    unknownInstr();
}

void m68kMoveaWordImm16AdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 279 rrgm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = ext32(reg_dt);
	    reg_au = reg_au + 2;
	    // 278 rrgl2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    runALU(AluAnd, high16(reg_dt), 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fa rmrw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fa rmrw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsAidProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisAidProgram()
{
    unknownInstr();
}

void m68kMoveWordDasAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisAidProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcAidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3ab mmrw1
	    reg_aob = reg_da[rx_index];
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciAidProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16AidProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2fa rmrw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 25 mmrw2
	    reg_aob = reg_pc;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_au = reg_pc + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fe rmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2fe rmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsAipdProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveWordDasAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisAipdProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcAipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3af mmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dbin;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciAipdProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16AipdProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2fe rmiw1
	    reg_aob = reg_da[rx_index];
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_pc = reg_au;
	    reg_au = reg_da[rx_index] + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAsPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAisPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAipsPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDasPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDaisPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16PaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr32PaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDpcPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDpciPaidProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16PaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDsDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2da rmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2db rmdw2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2da rmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 2db rmdw2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_da[ry_index];
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsDadProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisDadProgram()
{
    unknownInstr();
}

void m68kMoveWordDasDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisDadProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcDadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 38a mmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_da[rx_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciDadProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16DadProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2da rmdw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[rx_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 2db rmdw2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_dt;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAsDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAisDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAipsDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordPaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDasDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDaisDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr16DaidProgram()
{
    unknownInstr();
}

void m68kMoveWordAdr32DaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDpcDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDpciDaidProgram()
{
    unknownInstr();
}

void m68kMoveWordImm16DaidProgram()
{
    unknownInstr();
}

void m68kMoveWordDsAdr16Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d9 raww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d9 raww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsAdr16Program()
{
    unknownInstr();
}

void m68kMoveWordPaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveWordDasAdr16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisAdr16Program()
{
    unknownInstr();
}

void m68kMoveWordAdr16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 388 maww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciAdr16Program()
{
    unknownInstr();
}

void m68kMoveWordImm16Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2d9 raww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = ext32(reg_dbin);
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDsAdr32Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1ea ralw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bb ralw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAsAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1ea ralw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bb ralw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_da[ry_index]);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAisAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAipsAdr32Program()
{
    unknownInstr();
}

void m68kMoveWordPaisAdr32Program()
{
    unknownInstr();
}

void m68kMoveWordDasAdr32Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDaisAdr32Program()
{
    unknownInstr();
}

void m68kMoveWordAdr16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordAdr32Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpcAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 32b malw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_aluo);
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 32e malw2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveWordDpciAdr32Program()
{
    unknownInstr();
}

void m68kMoveWordImm16Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 1ea ralw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bb ralw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dt);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluAnd, reg_dt, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 389 maww2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubxByte, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubxByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxByteAipsProgram()
{
    unknownInstr();
}

void m68kNegxBytePaisProgram()
{
    unknownInstr();
}

void m68kNegxByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubxByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxByteDaisProgram()
{
    unknownInstr();
}

void m68kNegxByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubxByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubxByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubx, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxWordAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxWordAipsProgram()
{
    unknownInstr();
}

void m68kNegxWordPaisProgram()
{
    unknownInstr();
}

void m68kNegxWordDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxWordDaisProgram()
{
    unknownInstr();
}

void m68kNegxWordAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxWordAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 137 nnrl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubx, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 15e nnrl2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    runALU(AluSubc, high16(reg_da[ry_index]), 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongAipsProgram()
{
    unknownInstr();
}

void m68kNegxLongPaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongDaisProgram()
{
    unknownInstr();
}

void m68kNegxLongAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegxLongAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubx, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveSrDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3a5 strw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_ftu = reg_sr;
	    // 340 strw2
	    setReg16Low(reg_da[ry_index], reg_ftu);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8d rcal3
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveSrAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 3a1 stmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_ftu = reg_sr;
	    // 324 sftm2
	    reg_au = reg_at;
	    runALU(AluAnd, reg_ftu, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveSrAipsProgram()
{
    unknownInstr();
}

void m68kMoveSrPaisProgram()
{
    unknownInstr();
}

void m68kMoveSrDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3a1 stmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_ftu = reg_sr;
	    // 324 sftm2
	    reg_au = reg_at;
	    runALU(AluAnd, reg_ftu, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveSrDaisProgram()
{
    unknownInstr();
}

void m68kMoveSrAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3a1 stmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_ftu = reg_sr;
	    // 324 sftm2
	    reg_au = reg_at;
	    runALU(AluAnd, reg_ftu, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveSrAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3a1 stmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_ftu = reg_sr;
	    // 324 sftm2
	    reg_au = reg_at;
	    runALU(AluAnd, reg_ftu, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kChkWordDsDdProgram()
{
    unknownInstr();
}

void m68kChkWordAisDdProgram()
{
    unknownInstr();
}

void m68kChkWordAipsDdProgram()
{
    unknownInstr();
}

void m68kChkWordPaisDdProgram()
{
    unknownInstr();
}

void m68kChkWordDasDdProgram()
{
    unknownInstr();
}

void m68kChkWordDaisDdProgram()
{
    unknownInstr();
}

void m68kChkWordAdr16DdProgram()
{
    unknownInstr();
}

void m68kChkWordAdr32DdProgram()
{
    unknownInstr();
}

void m68kChkWordDpcDdProgram()
{
    unknownInstr();
}

void m68kChkWordDpciDdProgram()
{
    unknownInstr();
}

void m68kChkWordImm16DdProgram()
{
    unknownInstr();
}

void m68kLeaAisAdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2f1 leaa1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_ftu = reg_dbin;
	    // 66 leaa2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[rx_index] = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kLeaDasAdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2f2 lead1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    // 309 lead2
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kLeaDaisAdProgram()
{
    unknownInstr();
}

void m68kLeaAdr16AdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 275 laaw1
	    reg_aob = reg_au;
	    reg_da[rx_index] = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kLeaAdr32AdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 3e4 laal1
	    reg_aob = reg_au;
	    setReg16High(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2bd laal2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_da[rx_index], reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kLeaDpcAdProgram()
{
    rx_index = ((reg_irdi >> 9) & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2f2 lead1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    // 309 lead2
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kLeaDpciAdProgram()
{
    unknownInstr();
}

void m68kClrByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_da[ry_index], 0x0000);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrByteAipsProgram()
{
    unknownInstr();
}

void m68kClrBytePaisProgram()
{
    unknownInstr();
}

void m68kClrByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrByteDaisProgram()
{
    unknownInstr();
}

void m68kClrByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAndByte, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0x0000);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrWordAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrWordAipsProgram()
{
    unknownInstr();
}

void m68kClrWordPaisProgram()
{
    unknownInstr();
}

void m68kClrWordDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrWordDaisProgram()
{
    unknownInstr();
}

void m68kClrWordAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrWordAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 137 nnrl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0x0000);
	    updateCCR(CcrNZVC);
	    // 15e nnrl2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    runALU(AluAnd, high16(reg_da[ry_index]), 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluAnd, reg_alub, 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongAipsProgram()
{
    unknownInstr();
}

void m68kClrLongPaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluAnd, reg_alub, 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluAnd, reg_alub, 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongDaisProgram()
{
    unknownInstr();
}

void m68kClrLongAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluAnd, reg_alub, 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kClrLongAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluAnd, reg_alub, 0x0000);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSubByte, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegByteAipsProgram()
{
    unknownInstr();
}

void m68kNegBytePaisProgram()
{
    unknownInstr();
}

void m68kNegByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegByteDaisProgram()
{
    unknownInstr();
}

void m68kNegByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSubByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegWordAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegWordAipsProgram()
{
    unknownInstr();
}

void m68kNegWordPaisProgram()
{
    unknownInstr();
}

void m68kNegWordDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegWordDaisProgram()
{
    unknownInstr();
}

void m68kNegWordAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegWordAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 137 nnrl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSub, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVC);
	    // 15e nnrl2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    runALU(AluSubc, high16(reg_da[ry_index]), 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongAipsProgram()
{
    unknownInstr();
}

void m68kNegLongPaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongDaisProgram()
{
    unknownInstr();
}

void m68kNegLongAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNegLongAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluSub, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluSubc, reg_alub, 0x0000);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveDsCcrProgram()
{
    unknownInstr();
}

void m68kMoveAisCcrProgram()
{
    unknownInstr();
}

void m68kMoveAipsCcrProgram()
{
    unknownInstr();
}

void m68kMovePaisCcrProgram()
{
    unknownInstr();
}

void m68kMoveDasCcrProgram()
{
    unknownInstr();
}

void m68kMoveDaisCcrProgram()
{
    unknownInstr();
}

void m68kMoveAdr16CcrProgram()
{
    unknownInstr();
}

void m68kMoveAdr32CcrProgram()
{
    unknownInstr();
}

void m68kMoveDpcCcrProgram()
{
    unknownInstr();
}

void m68kMoveDpciCcrProgram()
{
    unknownInstr();
}

void m68kMoveImm8CcrProgram()
{
    unknownInstr();
}

void m68kNotByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluNotByte, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndBytex, reg_dbin, 0xFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNotByte, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotByteAipsProgram()
{
    unknownInstr();
}

void m68kNotBytePaisProgram()
{
    unknownInstr();
}

void m68kNotByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndBytex, reg_dbin, 0xFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNotByte, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotByteDaisProgram()
{
    unknownInstr();
}

void m68kNotByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndBytex, reg_dbin, 0xFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNotByte, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndBytex, reg_dbin, 0xFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNotByte, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluNot, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotWordAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotWordAipsProgram()
{
    unknownInstr();
}

void m68kNotWordPaisProgram()
{
    unknownInstr();
}

void m68kNotWordDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotWordDaisProgram()
{
    unknownInstr();
}

void m68kNotWordAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotWordAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2b8 nnmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 137 nnrl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluNot, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 15e nnrl2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    runALU(AluNot, high16(reg_da[ry_index]));
	    updateCCR(CcrNZVCU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluNot, reg_alub);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongAipsProgram()
{
    unknownInstr();
}

void m68kNotLongPaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluNot, reg_alub);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluNot, reg_alub);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongDaisProgram()
{
    unknownInstr();
}

void m68kNotLongAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluNot, reg_alub);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNotLongAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 2bc nnml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluNot, reg_dbin);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 15d nnml2
	    reg_aob = reg_at;
	    reg_dbout = reg_aluo;
	    reg_au = reg_at - 2;
	    runALU(AluNot, reg_alub);
	    updateCCR(CcrNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveDsSrProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 301 rstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_da[ry_index];
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveAisSrProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 159 mstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveAipsSrProgram()
{
    unknownInstr();
}

void m68kMovePaisSrProgram()
{
    unknownInstr();
}

void m68kMoveDasSrProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 159 mstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveDaisSrProgram()
{
    unknownInstr();
}

void m68kMoveAdr16SrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 159 mstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveAdr32SrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 159 mstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveDpcSrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndx, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 159 mstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveDpciSrProgram()
{
    unknownInstr();
}

void m68kMoveI16uSrProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // ea e#w1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    setReg16Low(reg_dt, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 301 rstw1
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dt;
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 321 stiw4
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 1e1 malw3
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNbcdByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 13b nbcr1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluSbcdByte, reg_da[ry_index], 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 117 nbcr2
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 253 nbcr3
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNbcdByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 15c nbcm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSbcdByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 113 asbb6
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNbcdByteAipsProgram()
{
    unknownInstr();
}

void m68kNbcdBytePaisProgram()
{
    unknownInstr();
}

void m68kNbcdByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 15c nbcm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSbcdByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 113 asbb6
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNbcdByteDaisProgram()
{
    unknownInstr();
}

void m68kNbcdByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 15c nbcm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSbcdByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 113 asbb6
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kNbcdByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 15c nbcm1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    runALU(AluSbcdByte, reg_dbin, 0x0000);
	    updateCCR(CcrXNZVCU);
	    // 113 asbb6
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSwapDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 341 swap1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_da[ry_index];
	    reg_pc = reg_au;
	    setReg16High(reg_at, reg_da[ry_index]);
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 342 swap2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[ry_index] = merge32(high16(reg_at), reg_aluo);
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaAisProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 17c peaa1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_da[rx_index] - 4;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 106 peax6
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_at);
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaDasProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 17d pead1
	    reg_aob = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 17e pead2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_at;
	    // 17f pead3
	    reg_at = reg_au;
	    runALU(AluAnd, reg_au, 0xFFFF);
	    reg_au = reg_da[rx_index] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 106 peax6
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_at);
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaDaisProgram()
{
    unknownInstr();
}

void m68kPeaAdr16Program()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 178 paaw1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_at = ext32(reg_dbin);
	    reg_au = reg_da[rx_index] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 10a paaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_at);
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaAdr32Program()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1fa paal1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 15f paal2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = reg_da[rx_index] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 10a paaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_at);
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 348 mawl3
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    setTrace();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaDpcProgram()
{
    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 17d pead1
	    reg_aob = reg_au;
	    reg_at = reg_pc;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 17e pead2
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = ext32(reg_aluo) + reg_at;
	    // 17f pead3
	    reg_at = reg_au;
	    runALU(AluAnd, reg_au, 0xFFFF);
	    reg_au = reg_da[rx_index] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 106 peax6
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_at);
	    reg_da[rx_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kPeaDpciProgram()
{
    unknownInstr();
}

void m68kExtWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 133 nnrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluExt, reg_da[ry_index]);
	    updateCCR(CcrNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMovemWordListAisProgram()
{
    unknownInstr();
}

void m68kMovemWordListpPaisProgram()
{
    unknownInstr();
}

void m68kMovemWordListDasProgram()
{
    unknownInstr();
}

void m68kMovemWordListDaisProgram()
{
    unknownInstr();
}

void m68kMovemWordListAdr16Program()
{
    unknownInstr();
}

void m68kMovemWordListAdr32Program()
{
    unknownInstr();
}

void m68kExtLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 232 extr1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = ext32(reg_da[ry_index]);
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 233 extr2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[ry_index] = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMovemLongListAisProgram()
{
    unknownInstr();
}

void m68kMovemLongListpPaisProgram()
{
    unknownInstr();
}

void m68kMovemLongListDasProgram()
{
    unknownInstr();
}

void m68kMovemLongListDaisProgram()
{
    unknownInstr();
}

void m68kMovemLongListAdr16Program()
{
    unknownInstr();
}

void m68kMovemLongListAdr32Program()
{
    unknownInstr();
}

void m68kTstByteDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 12d tsrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstByteAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstByteAipsProgram()
{
    unknownInstr();
}

void m68kTstBytePaisProgram()
{
    unknownInstr();
}

void m68kTstByteDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstByteDaisProgram()
{
    unknownInstr();
}

void m68kTstByteAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstByteAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstWordDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 12d tsrw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstWordAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstWordAipsProgram()
{
    unknownInstr();
}

void m68kTstWordPaisProgram()
{
    unknownInstr();
}

void m68kTstWordDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstWordDaisProgram()
{
    unknownInstr();
}

void m68kTstWordAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstWordAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3c3 tsmw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 125 tsrl1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 362 tsrl2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, high16(reg_da[ry_index]), 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 3cb tsml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 361 tsml2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongAipsProgram()
{
    unknownInstr();
}

void m68kTstLongPaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 3cb tsml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 361 tsml2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3cb tsml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 361 tsml2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongDaisProgram()
{
    unknownInstr();
}

void m68kTstLongAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 3cb tsml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 361 tsml2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTstLongAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 3cb tsml1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    // 361 tsml2
	    reg_ird = reg_ir;
	    setIntState();
	    runALU(AluAnd, reg_alub, 0xFFFF);
	    updateCCR(CcrNZU);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTasDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 345 tasr1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_alub = reg_da[ry_index];
	    reg_pc = reg_au;
	    runALU(AluOrByte, reg_ftu, reg_da[ry_index]);
	    // 346 tasr2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_au + 2;
	    runALU(AluAndByte, reg_alub, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTasAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 343 tasm1
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_ftu, reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 344 tasm2
	    reg_aob = reg_au;
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTasAipsProgram()
{
    unknownInstr();
}

void m68kTasPaisProgram()
{
    unknownInstr();
}

void m68kTasDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = 0;
	    setFC(true, false, true, false);
	    readRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 343 tasm1
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_ftu, reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 344 tasm2
	    reg_aob = reg_au;
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTasDaisProgram()
{
    unknownInstr();
}

void m68kTasAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 343 tasm1
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_ftu, reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 344 tasm2
	    reg_aob = reg_au;
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTasAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = 0;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 343 tasm1
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_ftu, reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 344 tasm2
	    reg_aob = reg_au;
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    updateCCR(CcrNZVC);
	    setFC(true, false, false, false);
	    writeRMC();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    checkExcept();
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMovemWordAisListProgram()
{
    unknownInstr();
}

void m68kMovemWordAipsListProgram()
{
    unknownInstr();
}

void m68kMovemWordDasListProgram()
{
    unknownInstr();
}

void m68kMovemWordDaisListProgram()
{
    unknownInstr();
}

void m68kMovemWordAdr16ListProgram()
{
    unknownInstr();
}

void m68kMovemWordAdr32ListProgram()
{
    unknownInstr();
}

void m68kMovemWordDpcListProgram()
{
    unknownInstr();
}

void m68kMovemWordDpciListProgram()
{
    unknownInstr();
}

void m68kMovemLongAisListProgram()
{
    unknownInstr();
}

void m68kMovemLongAipsListProgram()
{
    unknownInstr();
}

void m68kMovemLongDasListProgram()
{
    unknownInstr();
}

void m68kMovemLongDaisListProgram()
{
    unknownInstr();
}

void m68kMovemLongAdr16ListProgram()
{
    unknownInstr();
}

void m68kMovemLongAdr32ListProgram()
{
    unknownInstr();
}

void m68kMovemLongDpcListProgram()
{
    unknownInstr();
}

void m68kMovemLongDpciListProgram()
{
    unknownInstr();
}

void m68kTrapImm4Program()
{
    unknownInstr();
}

void m68kLinkAsImm16Program()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 30b link1
	    reg_aob = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    // 2b5 link2
	    reg_pc = reg_au;
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 30c link3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = high16(reg_at);
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 30d link4
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 349 mmiw2
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kUnlkAsProgram()
{
    unknownInstr();
}

void m68kMoveAsUspProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 2f5 lusp1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_at = reg_da[ry_index];
	    reg_ftu = reg_dbin;
	    // 66 leaa2
	    reg_ird = reg_ir;
	    setIntState();
	    reg_da[15] = reg_at;
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kMoveUspAsProgram()
{
    unknownInstr();
}

void m68kResetProgram()
{
    unknownInstr();
}

void m68kNopProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStopI16uProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 3a2 stop1
	    reg_ird = reg_ir;
	    setIntState();
	    reg_movemr = reg_dbin;
	    reg_pc = reg_au;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0x0000);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 327 aaa01
	    reg_ird = reg_ir;
	    setIntState();
	    reg_pc = reg_au;
	    reg_sr = reg_isr = (reg_ftu & 0xA71F);
	    updateSupervisor();
	    updateInterrupts();
	    reg_au = reg_au - 2;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    nextInst();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kRteProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    if (!checkPriv())
	    {
		setPriv();
		return;
	    }

	    // 12a rtr1
	    reg_aob = reg_da[reg_sp];
	    reg_au = reg_da[reg_sp] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 12b rtr2
	    reg_aob = reg_au;
	    reg_movemr = reg_dbin;
	    reg_ftu = reg_dbin;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 3c5 rtr3
	    reg_aob = reg_au;
	    reg_at = ext32(reg_dbin);
	    reg_au = reg_au + 2;
	    // 302 rtr4
	    setReg16High(reg_at, reg_dbin);
	    reg_da[reg_sp] = reg_au;
	    reg_new_sr = reg_isr = (reg_ftu & 0xA71F);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    updateSR();
	    reg_dbin = reg_edb;
	    // 2b3 jmal2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kRtsProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 126 rts1
	    reg_aob = reg_da[reg_sp];
	    reg_au = reg_da[reg_sp] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 116 rts2
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 303 rts3
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_da[reg_sp] = reg_au;
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kTrapvProgram()
{
    unknownInstr();
}

void m68kRtrProgram()
{
    unknownInstr();
}

void m68kJsrAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 273 jsra1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 271 jsaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_pc);
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    // 272 jsaw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_pc;
	    reg_au = reg_at + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJsrDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b0 jsrd1
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 274 jsrd2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    // 2b1 jsrd3
	    reg_pc = reg_au;
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    // 271 jsaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_pc);
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 272 jsaw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_pc;
	    reg_au = reg_at + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJsrDaisProgram()
{
    unknownInstr();
}

void m68kJsrAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 293 jsaw0
	    reg_at = ext32(reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 270 jsaw1
	    reg_aob = reg_at;
	    reg_pc = reg_au;
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    // 271 jsaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_pc);
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 272 jsaw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_pc;
	    reg_au = reg_at + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJsrAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1f2 jsal1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 256 jsal2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_pc = reg_au;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 271 jsaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_pc);
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    // 272 jsaw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_pc;
	    reg_au = reg_at + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJsrDpcProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b0 jsrd1
	    reg_au = ext32(reg_dbin) + reg_pc;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 274 jsrd2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    // 2b1 jsrd3
	    reg_pc = reg_au;
	    reg_au = reg_da[reg_sp] - 4;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    // 271 jsaw2
	    reg_aob = reg_au;
	    reg_dbout = high16(reg_pc);
	    reg_da[reg_sp] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    // 272 jsaw3
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_dbout = reg_pc;
	    reg_au = reg_at + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJsrDpciProgram()
{
    unknownInstr();
}

void m68kJmpAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 255 jmpa1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJmpDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b4 jmpd1
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // c5 bbci3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJmpDaisProgram()
{
    unknownInstr();
}

void m68kJmpAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 297 jmaw1
	    reg_at = ext32(reg_dbin);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 2b3 jmal2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJmpAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1f6 jmal1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2b3 jmal2
	    reg_aob = merge32(high16(reg_at), reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin) + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJmpDpcProgram()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2b4 jmpd1
	    reg_au = ext32(reg_dbin) + reg_pc;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // c5 bbci3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kJmpDpciProgram()
{
    unknownInstr();
}

void m68kAddqByteImm3DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d8 raqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluAddByte, reg_ftu, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqByteImm3AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqByteImm3AipsProgram()
{
    unknownInstr();
}

void m68kAddqByteImm3PaisProgram()
{
    unknownInstr();
}

void m68kAddqByteImm3DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqByteImm3DaisProgram()
{
    unknownInstr();
}

void m68kAddqByteImm3Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqByteImm3Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAddByte, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d8 raqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluAdd, reg_ftu, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3AsProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2dc raql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluAdd, reg_ftu, reg_da[ry_index]);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluAddc, high16(reg_dt), high16(reg_da[ry_index]));
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3AipsProgram()
{
    unknownInstr();
}

void m68kAddqWordImm3PaisProgram()
{
    unknownInstr();
}

void m68kAddqWordImm3DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3DaisProgram()
{
    unknownInstr();
}

void m68kAddqWordImm3Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqWordImm3Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2f3 maqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2dc raql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluAdd, reg_ftu, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluAddc, high16(reg_dt), high16(reg_da[ry_index]));
	    updateCCR(CcrXNZVCU);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3AsProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2dc raql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluAdd, reg_ftu, reg_da[ry_index]);
	    // 259 roal2
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 25a roal3
	    runALU(AluAddc, high16(reg_dt), high16(reg_da[ry_index]));
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    // 25b roal4
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16High(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3AisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // b adrl1
	    reg_aob = reg_da[ry_index];
	    reg_au = reg_da[ry_index] + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 2f7 maql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3AipsProgram()
{
    unknownInstr();
}

void m68kAddqLongImm3PaisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 179 pdcl1
	    reg_au = reg_da[ry_index] - 4;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    // 17a pdcl2
	    reg_aob = reg_au;
	    reg_da[ry_index] = reg_au;
	    reg_au = reg_au + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    reg_dbin = reg_edb;
	    // 2f7 maql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3DasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c6 adsl1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // c adsl2
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 26 adsl3
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2f7 maql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3DaisProgram()
{
    unknownInstr();
}

void m68kAddqLongImm3Adr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // e abww1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 2f7 maql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kAddqLongImm3Adr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e6 ablw1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // d ablw2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 8 ablw3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    runALU(AluAnd, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    reg_dbin = reg_edb;
	    // 5 adrl2
	    reg_aob = reg_au;
	    reg_alub = reg_dbin;
	    reg_alue = reg_dbin;
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    setFC(true, false, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 13):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 14):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 15):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 16):
	{
	    reg_dbin = reg_edb;
	    // 2f7 maql1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    reg_au = reg_at;
	    runALU(AluAdd, reg_ftu, reg_dbin);
	    updateCCR(CcrXNZVC);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 17):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 18):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 19):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 20):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 34d morl2
	    reg_aob = reg_au;
	    reg_dbout = reg_aluo;
	    reg_au = reg_au - 2;
	    runALU(AluAddc, high16(reg_dt), reg_alue);
	    updateCCR(CcrXNZVCU);
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 21):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 22):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 23):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 24):
	{
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_dbout = reg_aluo;
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 25):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 26):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 27):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 28):
	{
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStDsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 384 sccr1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_t = 1;
	    reg_pc = reg_au;
	    runALU(AluAndByte, 0x0000, 0x0000);
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // roaw2
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	case getCycle(2, 0):
	{
	    // sccr2
	    // cb sccr2
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_aluo, 0xFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 253 nbcr3
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 6):
	{
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kDbtDsRel16Program()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6c dbcc1
	    reg_t = 1;
	    reg_au = ext32(reg_dbin) + reg_pc;
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // dbcc2
	    // 46 dbcc2
	    reg_aob = reg_au;
	    reg_alub = reg_da[ry_index];
	    reg_at = reg_au;
	    reg_au = reg_pc + 2;
	    runALU(AluAnd, reg_da[ry_index], 0xFFFF);
	    // 175 dbcc3
	    reg_t = testbit(reg_isr, 2);
	    reg_pc = reg_au;
	    reg_au = reg_at + 2;
	    runALU(AluAdd, reg_alub, 0xFFFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    jumpCond2(4, 3);
	}
	break;
	case getCycle(2, 0):
	{
	    // dbcc6
	    // c6 dbcc6
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFTUConst();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    setTrace();
	    // c5 bbci3
	    reg_aob = reg_au;
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 6):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 363 b
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 34c mmrw3
	    reg_ird = reg_ir;
	    setIntState();
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 8):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 10):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	case getCycle(3, 0):
	{
	    // dbcc4
	    // c7 dbcc4
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_au = reg_au + 2;
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg16Low(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    nextTrace();
	}
	break;
	case getCycle(4, 0):
	{
	    // dbcc5
	    // 7 dbcc5
	    reg_aob = reg_pc;
	    reg_ird = reg_ir;
	    setIntState();
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(4, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(4, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(4, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(4, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    setFTUConst();
	    setTrace();
	    jump(3);
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStAisProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 6 adrw1
	    reg_aob = reg_da[ry_index];
	    reg_at = reg_da[ry_index];
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 380 sccb1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_t = 1;
	    reg_pc = reg_au;
	    runALU(AluAndByte, 0x0000, 0x0000);
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // sccb3
	    // 4f sccb3
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(2, 0):
	{
	    // sccb2
	    // cf sccb2
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_aluo, 0xFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(3, 0):
	{
	    // morw2
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 4):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStAipsProgram()
{
    unknownInstr();
}

void m68kStPaisProgram()
{
    unknownInstr();
}

void m68kStDasProgram()
{
    ry_index = mapSP((reg_irdi & 0x7) | 8);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1c2 adsw1
	    reg_aob = reg_au;
	    reg_au = ext32(reg_dbin) + reg_da[ry_index];
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 2a adsw2
	    reg_aob = reg_au;
	    reg_at = reg_au;
	    reg_au = reg_pc + 4;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    // 24 adrw2
	    reg_dcr = reg_dt;
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 380 sccb1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_t = 1;
	    reg_pc = reg_au;
	    runALU(AluAndByte, 0x0000, 0x0000);
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // sccb3
	    // 4f sccb3
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(2, 0):
	{
	    // sccb2
	    // cf sccb2
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_aluo, 0xFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(3, 0):
	{
	    // morw2
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 4):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStDaisProgram()
{
    unknownInstr();
}

void m68kStAdr16Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // a abwl1
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    reg_at = ext32(reg_dbin);
	    reg_au = ext32(reg_dbin);
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 380 sccb1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_t = 1;
	    reg_pc = reg_au;
	    runALU(AluAndByte, 0x0000, 0x0000);
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // sccb3
	    // 4f sccb3
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(2, 0):
	{
	    // sccb2
	    // cf sccb2
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_aluo, 0xFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(3, 0):
	{
	    // morw2
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 4):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kStAdr32Program()
{
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 1e2 abll1
	    reg_aob = reg_au;
	    setReg16High(reg_at, reg_dbin);
	    reg_au = reg_au + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 4):
	{
	    reg_dbin = reg_edb;
	    // 9 abll2
	    reg_aob = reg_au;
	    reg_pc = reg_au;
	    reg_dcr = reg_dt;
	    setReg16Low(reg_at, reg_dbin);
	    reg_au = merge32(high16(reg_at), reg_dbin);
	    runALU(AluOrByte, reg_dt, reg_dbin);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 5):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 6):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 7):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 8):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    // 4 abll3
	    reg_aob = reg_at;
	    reg_au = reg_pc + 2;
	    runALU(AluAndByte, reg_dbin, 0xFFFF);
	    setFC(true, false, true, false);
	    readByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 9):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 10):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 11):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(0, 12):
	{
	    checkExcept();
	    reg_dbin = reg_edb;
	    // 380 sccb1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_t = 1;
	    reg_pc = reg_au;
	    runALU(AluAndByte, 0x0000, 0x0000);
	    jumpCond2(2, 1);
	}
	break;
	case getCycle(1, 0):
	{
	    // sccb3
	    // 4f sccb3
	    reg_pc = reg_au;
	    reg_au = reg_at;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(1, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(2, 0):
	{
	    // sccb2
	    // cf sccb2
	    reg_au = reg_at;
	    runALU(AluOrByte, reg_aluo, 0xFF);
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(2, 4):
	{
	    reg_irc = reg_edb;
	    reg_dbin = reg_edb;
	    jump(3);
	}
	break;
	case getCycle(3, 0):
	{
	    // morw2
	    // 38d morw2
	    reg_aob = reg_au;
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8ExLow(reg_dbout, reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(true, false, false, false);
	    writeByte();
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 1):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 2):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 3):
	{
	    inst_cycle += 1;
	}
	break;
	case getCycle(3, 4):
	{
	    checkExcept();
	    setFTUConst();
	    nextTrace();
	}
	break;
	default:
	{
	    unrecognizedState();
	}
	break;
    }
}

void m68kSubqByteImm3DsProgram()
{
    ry_index = (reg_irdi & 0x7);
    switch ((inst_cycle << 6) | inst_state)
    {
	case getCycle(0, 0):
	{
	    // 2d8 raqw1
	    reg_aob = reg_au;
	    reg_ir = reg_irc;
	    updateIPL();
	    reg_pc = reg_au;
	    reg_dt = ext32(reg_ftu);
	    runALU(AluSubByte, reg_ftu, reg_da[ry_index]);
	    updateCCR(CcrXNZVC);
	    // 8b roaw2
	    reg_ird = reg_ir;
	    setIntState();
	    setReg8(reg_da[ry_index], reg_aluo);
	    reg_au = reg_pc + 2;
	    setFC(false, true, true, false);
	    readWord();
	    inst_cycle += 1;
	}