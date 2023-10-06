void unknownInstr()
{
    cout << "Unrecognized M68000 instruction of " << hex << int(reg_ird) << endl;
    throw runtime_error("Kujo68K error");
}

void setIntState()
{
    if (next_state != STrace)
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

int countRegZero(uint16_t value)
{
    for (int i = 0; i != 16; i++)
    {
	if (testbit(value, i))
	{
	    return i;
	}
    }

    return 16;
}

void stepMovem()
{
    int num_regs = countRegZero(reg_movemr);

    if (num_regs > 15)
    {
	num_regs = 0;
    }

    reg_movems = mapSP(num_regs);
    reg_movemr &= ~(1 << num_regs);
}

void stepMovemPredec()
{
    int num_regs = countRegZero(reg_movemr);

    if (num_regs > 15)
    {
	num_regs = 0;
    }

    reg_movems = mapSP(num_regs ^ 0xF);
    reg_movemr &= ~(1 << num_regs);
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

static void setReg16High(uint32_t &reg, uint16_t value)
{
    reg = ((reg & 0xFFFF) | (value << 16));
}

static void setReg16Low(uint32_t &reg, uint16_t value)
{
    reg = ((reg & 0xFFFF0000) | value);
}

static void setReg16Low(uint16_t &reg, uint16_t value)
{
    reg = value;
}

static void setReg8(uint32_t &reg, uint8_t value)
{
    reg = ((reg & 0xFFFFFF00) | value);
}

static void setReg8(uint16_t &reg, uint8_t value)
{
    reg = ((reg & 0xFF00) | value);
}

static void setReg8High(uint16_t &reg, uint8_t value)
{
    reg = ((reg & 0xFF) | (value << 8));
}

static void setReg8ExLow(uint16_t &reg, uint16_t value)
{
    uint8_t val8 = (value & 0xFF);
    uint16_t val16 = (val8 | (val8 << 8));
    reg = val16;
}

static void setReg8ExHigh(uint16_t &reg, uint16_t value)
{
    uint8_t val8 = (value >> 8);
    uint16_t val16 = (val8 | (val8 << 8));
    reg = val16;
}

void readWordCPU()
{
    startMemIO();
    is_read = true;
    is_word = true;
    is_rmc = false;
    is_cpu_access = true;
}

void readWord()
{
    startMemIO();
    is_read = true;
    is_word = true;
    is_rmc = false;
    is_bus_access = true;
}

void writeWord()
{
    startMemIO();
    is_read = false;
    is_word = true;
    is_rmc = false;
    is_bus_access = true;
}

void readByte()
{
    startMemIO();
    is_read = true;
    is_word = false;
    is_rmc = false;
    is_bus_access = true;
}

void writeByte()
{
    startMemIO();
    is_read = false;
    is_word = false;
    is_rmc = false;
    is_bus_access = true;
}

void readRMC()
{
    startMemIO();
    is_read = true;
    is_word = false;
    is_rmc = true;
    is_bus_access = true;
}

void writeRMC()
{
    startMemIO();
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

inline void updateZ()
{
    reg_sr = ((reg_sr & ~SrZero) | (reg_isr & SrZero));
}

inline void updateNZU()
{
    int mask = SrSign;
    reg_sr = ((reg_sr & ~mask & (reg_isr | ~SrZero)) | (reg_isr & mask));
}

inline void updateNZVC()
{
    int mask = (SrSign | SrZero | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask) | (reg_isr & mask));
}

inline void updateNZVCU()
{
    int mask = (SrSign | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask & (reg_isr | ~SrZero)) | (reg_isr & mask));
}

inline void updateXNZVC()
{
    int mask = (SrExtend | SrSign | SrZero | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask) | (reg_isr & mask));
}

inline void updateXNZVCU()
{
    int mask = (SrExtend | SrSign | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask & (reg_isr | ~SrZero)) | (reg_isr & mask));
}

inline void aluAnd(uint16_t val1, uint16_t val2)
{
    uint16_t res = (val2 & val1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluAndx(uint16_t val1, uint16_t val2)
{
    cout << "AluAndx" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAndByte(uint16_t val1, uint16_t val2)
{
    uint16_t res = (val2 & val1);
    reg_isr = (reg_sr & SrExtend);

    if ((res & 0xFF) == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 7))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluAndBytex(uint16_t val1, uint16_t val2)
{
    cout << "AluAndBytex" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluOr(uint16_t val1, uint16_t val2)
{
    uint16_t res = (val2 | val1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluOrByte(uint8_t val1, uint8_t val2)
{
    uint8_t res = (val2 | val1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 7))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluXor(uint16_t val1, uint16_t val2)
{
    uint16_t res = (val2 ^ val1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluXorByte(uint16_t val1, uint16_t val2)
{
    uint8_t res = (val2 ^ val1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 7))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluAdd(uint16_t val1, uint16_t val2)
{
    uint32_t res = (val2 + val1);
    uint32_t ov_res = ((val2 & val1 & ~res) | (~val2 & ~val1 & res));

    reg_isr = 0;

    if ((res & 0xFFFF) == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    if (testbit(res, 16))
    {
	reg_isr |= (SrExtend | SrCarry);
    }

    if (testbit(ov_res, 15))
    {
	reg_isr |= SrOverflow;
    }

    reg_aluo = res;
}

inline void aluAddx(uint16_t val1, uint16_t val2)
{
    cout << "AluAddx" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAddc(uint16_t val1, uint16_t val2)
{
    cout << "AluAddc" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAddByte(uint8_t val1, uint8_t val2)
{
    cout << "AluAddByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAddxByte(uint8_t val1, uint8_t val2)
{
    cout << "AluAddxByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSub(uint16_t val1, uint16_t val2)
{
    uint32_t res = (val2 - val1);
    uint32_t ov_res = ((val2 & ~val1 & ~res) | (~val2 & val1 & res));

    reg_isr = 0;

    if ((res & 0xFFFF) == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    if (testbit(res, 16))
    {
	reg_isr |= (SrExtend | SrCarry);
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrOverflow;
    }

    reg_aluo = res;
}

inline void aluSubx(uint16_t val1, uint16_t val2)
{
    cout << "AluSubx" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSubc(uint16_t val1, uint16_t val2)
{
    cout << "AluSubc" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSubByte(uint8_t val1, uint8_t val2)
{
    cout << "AluSubByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSubxByte(uint8_t val1, uint8_t val2)
{
    cout << "AluSubxByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluExt(uint16_t val1)
{
    cout << "AluExt" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluNot(uint16_t val)
{
    uint16_t res = ~val;
    reg_isr = 0;

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluNotByte(uint8_t val)
{
    uint8_t res = ~val;
    reg_isr = 0;

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 7))
    {
	reg_isr |= SrSign;
    }

    reg_aluo = res;
}

inline void aluLsl(uint16_t val)
{
    cout << "AluLsl" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluLslByte(uint8_t val)
{
    cout << "AluLslByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluLslLong(uint16_t val)
{
    cout << "AluLslLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluLsr(uint16_t val)
{
    cout << "AluLsr" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluLsrByte(uint8_t val)
{
    cout << "AluLsrByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluLsrLong(uint16_t val)
{
    cout << "AluLsrLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAsl(uint16_t val)
{
    cout << "AluAsl" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAslByte(uint8_t val)
{
    cout << "AluAslByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAslLong(uint16_t val)
{
    cout << "AluAslLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAsr(uint16_t val)
{
    cout << "AluAsr" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAsrByte(uint8_t val)
{
    cout << "AluAsrByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAsrLong(uint16_t val)
{
    uint32_t res = ((reg_alue << 15) | (val >> 1));
    reg_isr = 0;

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(reg_alue, 15))
    {
	res = setbit(res, 31);
	reg_isr |= SrSign;
    }

    if (testbit(val, 0))
    {
	reg_isr |= (SrExtend | SrCarry);
    }

    reg_aluo = res;
    reg_alue = (res >> 16);
}

inline void aluRol(uint16_t val)
{
    cout << "AluRol" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRolByte(uint8_t val)
{
    cout << "AluRolByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRolLong(uint16_t val)
{
    cout << "AluRolLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRor(uint16_t val)
{
    uint16_t res = (val >> 1);
    reg_isr = 0;

    if (testbit(val, 0))
    {
	reg_isr |= (SrExtend | SrCarry | SrZero);
	res = setbit(res, 15);
    }

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    reg_aluo = res;
}

inline void aluRorByte(uint8_t val)
{
    cout << "AluRorByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRorLong(uint16_t val)
{
    cout << "AluRorLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxl(uint16_t val)
{
    cout << "AluRoxl" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxlByte(uint8_t val)
{
    cout << "AluRoxlByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxlLong(uint16_t val)
{
    cout << "AluRoxlLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxr(uint16_t val)
{
    cout << "AluRoxr" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxrByte(uint8_t val)
{
    cout << "AluRoxrByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxrLong(uint32_t val)
{
    cout << "AluRoxrLong" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluRoxrLongMu(uint16_t val)
{
    uint32_t res = ((val << 15) | (reg_alue >> 1) | ((reg_isr & SrCarry) ? 0x80000000 : 0));

    reg_isr = 0;

    if (testbit(val, 0))
    {
	reg_isr |= SrExtend;
    }

    if (testbit(res, 31))
    {
	reg_isr |= SrSign;
    }

    if ((res & 0xFFFF0000) == 0)
    {
	reg_isr |= SrZero;
    }

    reg_aluo = (res >> 16);
    reg_alue = res;
}

inline void aluRoxrLongMs(uint16_t val)
{
    cout << "AluRoxrLongMs" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluAbcdByte(uint8_t val1, uint8_t val2)
{
    cout << "AluAbcdByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSbcdByte(uint8_t val1, uint8_t val2)
{
    cout << "AluSbcdByte" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluOver(uint16_t val)
{
    cout << "AluOver" << endl;
    throw runtime_error("Kujo68K error");
}

inline void aluSla0(uint16_t val)
{
    uint32_t res = ((val << 17) | (reg_alue << 1));

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 31))
    {
	reg_isr |= SrSign;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrCarry;
    }

    reg_alue = res;
    reg_aluo = (res >> 16);
}

inline void aluSla1(uint16_t val)
{
    uint32_t res = ((val << 17) | (reg_alue << 1) | 1);

    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 31))
    {
	reg_isr |= SrSign;
    }

    if (testbit(res, 15))
    {
	reg_isr |= SrCarry;
    }

    reg_alue = res;
    reg_aluo = (res >> 16);
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
	    int_next_state = (SInterrupt | (7 << 24));
	}
	else
	{
	    int_next_state = (SInterrupt | (reg_inl << 24));
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
	int_next_state = STrace;
    }
}

void clearTrace()
{
    if (int_next_state == STrace)
    {
	int_next_state = 0;
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
    inst_state = (next_state != 0) ? next_state : decode_table.at(reg_ird);
    inst_cycle = 0;

    // callFunc();
}

void nextTrace()
{
    reg_irdi = reg_ird;
    inst_state = (next_state != 0) ? next_state : decode_table.at(reg_ird);
    inst_cycle = 0;

    if (testbit(reg_sr, 15))
    {
	cout << "Calling trace..." << endl;
	throw runtime_error("Kujo68K error");
    }

    // callFunc();
}

static uint32_t ext32(uint16_t value)
{
    return int32_t(int16_t(value));
}

static uint16_t high16(uint32_t value)
{
    return (value >> 16);
}

static uint32_t merge32(uint16_t high, uint16_t low)
{
    return ((high << 16) | low);
}

void trapExcept(uint8_t)
{
    return;
}

int mapSP(int val)
{
    if (val == 15)
    {
	return reg_sp;
    }

    return val;
}