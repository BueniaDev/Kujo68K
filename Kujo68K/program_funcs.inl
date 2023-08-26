void unknownInstr()
{
    cout << "Unrecognized M68000 instruction of " << hex << int(reg_ird) << endl;
    throw runtime_error("Kujo68K error");
}

void setIntState()
{
    if (next_state != Trace)
    {
	next_state = int_next_state;
    }
}

void setFTUConst()
{
    int line = ((reg_ird >> 12) & 0xF);

    switch (line)
    {
	case 0x4: reg_ftu = 0x80; break;
	case 0x5:
	case 0xE:
	{
	    reg_ftu = ((reg_ird >> 9) & 0x7);

	    if (reg_ftu == 0)
	    {
		reg_ftu = 8;
	    }
	}
	break;
	case 0x6:
	case 0x7:
	{
	    reg_ftu = int8_t(reg_ird);
	}
	break;
	case 0x8:
	case 0xC: reg_ftu = 0xF; break;
	default: reg_ftu = 0; break;
    }
}

void checkExcept()
{
    if (testbit(reg_aob, 0))
    {
	cout << "Possible address error occured" << endl;
	throw runtime_error("Kujo68K error");
    }
}

void halt()
{
    return;
}

void setSR()
{
    return;
}

void setFC(bool fc0, bool fc1, bool is_r, bool is_n)
{
    current_pins.pin_fc0 = fc0;
    current_pins.pin_fc1 = fc1;
    current_pins.pin_fc2 = testbit(reg_sr, 13);

    base_ssw = ((is_n << 4) | (is_r << 3) | (fc1 << 1) | fc0);
}

void busEnd(bool)
{
    return;
}

void setCritical()
{
    base_ssw |= 0x20;
}

void setReg16High(uint32_t &reg, uint16_t value)
{
    reg = ((reg & 0xFFFF) | (value << 16));
}

void setReg16Low(uint32_t &reg, uint16_t value)
{
    reg = ((reg & 0xFFFF0000) | value);
}

void setReg16Low(uint16_t &reg, uint16_t value)
{
    reg = value;
}

void setReg8(uint32_t &reg, uint8_t value)
{
    reg = ((reg & 0xFFFFFF00) | value);
}

void setReg8(uint16_t &reg, uint8_t value)
{
    reg = ((reg & 0xFF00) | value);
}

void setReg8High(uint16_t &reg, uint8_t value)
{
    reg = ((reg & 0xFF) | (value << 8));
}

void setReg8ExLow(uint16_t &reg, uint16_t value)
{
    uint8_t val8 = (value & 0xFF);
    uint16_t val16 = (val8 | (val8 << 8));
    reg = val16;
}

void readWordCPU()
{
    bus_state = S0;
    is_cpu_access = true;
}

void readWord()
{
    bus_state = S0;
    is_read = true;
    is_word = true;
    is_rmc = false;
    is_bus_access = true;
}

void writeWord()
{
    bus_state = S0;
    is_read = false;
    is_word = true;
    is_rmc = false;
    is_bus_access = true;
}

void readByte()
{
    bus_state = S0;
    is_read = true;
    is_word = false;
    is_rmc = false;
    is_bus_access = true;
}

void writeByte()
{
    bus_state = S0;
    is_read = false;
    is_word = false;
    is_rmc = false;
    is_bus_access = true;
}

void readRMC()
{
    bus_state = S0;
    is_read = true;
    is_word = false;
    is_rmc = true;
    is_bus_access = true;
}

void writeRMC()
{
    bus_state = S0;
    is_read = false;
    is_word = false;
    is_rmc = true;
    is_bus_access = true;
}

void startIRQVectorLookup()
{
    int level = (next_state >> 24);

    if (level == 7)
    {
	is_nmi_occured = false;
	updateInterrupts();
    }
}

void endIRQVectorLookup()
{
    reg_int_vec = ((reg_edb & 0xFF) << 2);
    int_next_state = 0;
}

void runALU(Kujo68KALUOp alu_op, uint32_t val1, uint32_t val2 = 0)
{
    uint16_t alu_res = 0;
    switch (alu_op)
    {
	case AluAnd:
	{
	    alu_res = (val2 & val1);

	    reg_isr = (testbit(reg_sr, 4) << 4);

	    if (alu_res == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 15))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }
	}
	break;
	case AluAndByte:
	{
	    alu_res = uint8_t(val2 & val1);

	    reg_isr = (testbit(reg_sr, 4) << 4);

	    if ((alu_res & 0xFF) == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 7))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }
	}
	break;
	case AluOrByte:
	{
	    alu_res = uint8_t(val2 | val1);

	    reg_isr = (testbit(reg_sr, 4) << 4);

	    if ((alu_res & 0xFF) == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 7))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }
	}
	break;
	case AluXorByte:
	{
	    alu_res = uint8_t(val2 ^ val1);

	    reg_isr = (testbit(reg_sr, 4) << 4);

	    if ((alu_res & 0xFF) == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 7))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }
	}
	break;
	case AluAdd:
	{
	    alu_res = (val2 + val1);

	    reg_isr = 0;

	    if (alu_res == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 15))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }

	    if (testbit(alu_res, 16))
	    {
		reg_isr = setbit(reg_isr, 4);
		reg_isr = setbit(reg_isr, 0);
	    }

	    uint32_t overflow_calc = ((val2 & val1 & ~alu_res) | ((~val2) & (~val1) & alu_res));

	    if (testbit(overflow_calc, 15))
	    {
		reg_isr = setbit(reg_isr, 1);
	    }
	}
	break;
	case AluSub:
	{
	    alu_res = (val2 - val1);

	    reg_isr = 0;

	    if (alu_res == 0)
	    {
		reg_isr = setbit(reg_isr, 2);
	    }

	    if (testbit(alu_res, 15))
	    {
		reg_isr = setbit(reg_isr, 3);
	    }

	    if (testbit(alu_res, 16))
	    {
		reg_isr = setbit(reg_isr, 4);
		reg_isr = setbit(reg_isr, 0);
	    }

	    uint32_t overflow_calc = ((val2 & (~val1) & ~alu_res) | ((~val2) & val1 & alu_res));

	    if (testbit(overflow_calc, 15))
	    {
		reg_isr = setbit(reg_isr, 1);
	    }
	}
	break;
	default:
	{
	    cout << "Unrecognized ALU opcode of " << dec << int(alu_op) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }

    reg_aluo = alu_res;
}

void updateCCR(Kujo68KCCR ccr_op)
{
    switch (ccr_op)
    {
	case CcrZ:
	{
	    reg_sr = ((reg_sr & ~0x4) | (reg_isr & 0x4));
	}
	break;
	case CcrNZVC:
	{
	    reg_sr = ((reg_sr & ~0xF) | (reg_isr & 0xF));
	}
	break;
	case CcrXNZVC:
	{
	    reg_sr = ((reg_sr & ~0x1F) | (reg_isr & 0x1F));
	}
	break;
	case CcrNZU:
	{
	    reg_sr = (((reg_sr & ~0x8) & (reg_isr | ~0x4)) | (reg_isr & 0x8));
	}
	break;
	default:
	{
	    cout << "Unrecognized CCR opcode of " << dec << int(ccr_op) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }
}

void updateSR()
{
    reg_sr = reg_new_sr;
    updateSupervisor();
    updateInterrupts();
}

void updateSupervisor()
{
    if (testbit(reg_sr, 13))
    {
	reg_sp = 16;
    }
    else
    {
	reg_sp = 15;
    }
}

void updateIPL()
{
    reg_inl = reg_ipl;
}

void updateInterrupts()
{
    if (is_intpend)
    {
	if (is_nmi_occured)
	{
	    int_next_state = (Interrupt | (7 << 24));
	}
	else
	{
	    int_next_state = (Interrupt | (reg_inl << 24));
	}
    }
    else
    {
	int_next_state = 0;
    }
}

void initST()
{
    reg_sr = ((reg_sr & 0x7FFF) | 0x2000);
    updateSupervisor();
    updateInterrupts();
}

void setSRI7()
{
    reg_sr |= 0x700;
}

void setTrace()
{
    if (testbit(reg_sr, 15))
    {
	next_state = Trace;
    }
}

void clearTrace()
{
    if (next_state == Trace)
    {
	next_state = 0;
    }
}

bool checkPriv()
{
    return testbit(reg_sr, 13);
}

void setPriv()
{
    cout << "Privilege exception occured..." << endl;
    throw runtime_error("Kujo68K error");
}

void nextInst()
{
    reg_irdi = reg_ird;
    inst_state = 0;
    inst_cycle = 0;

    if (next_state != 0)
    {
	instr_decode = getStateFunc(next_state);
    }
    else
    {
	instr_decode = decode_table.at(reg_ird).func;
    }

    callFunc();
}

void nextTrace()
{
    reg_irdi = reg_ird;
    inst_state = 0;
    inst_cycle = 0;

    if (next_state != 0)
    {
	instr_decode = getStateFunc(next_state);
    }
    else
    {
	instr_decode = decode_table.at(reg_ird).func;
    }

    if (testbit(reg_sr, 15))
    {
	cout << "Calling trace..." << endl;
	throw runtime_error("Kujo68K error");
    }

    callFunc();
}

uint32_t ext32(uint16_t value)
{
    return int32_t(int16_t(value));
}

uint16_t high16(uint32_t value)
{
    return (value >> 16);
}

uint32_t merge32(uint16_t high, uint16_t low)
{
    return ((high << 16) | low);
}

void trapExcept(uint8_t)
{
    return;
}

void jumpCond2(int state1, int state0)
{
    if (reg_t != 0)
    {
	inst_state = state1;
    }
    else
    {
	inst_state = state0;
    }

    inst_cycle = 0;
    callFunc();
}

void jump(int state_num)
{
    inst_state = state_num;
    inst_cycle = 0;
    callFunc();
}

int mapSP(int val)
{
    if (val == 15)
    {
	return reg_sp;
    }

    return val;
}