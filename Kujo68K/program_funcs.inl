// TODO: Implement remaining program functions

void unknownInstr()
{
    cout << "Unrecognized M68000 instruction of " << hex << int(reg_irdi) << endl;
    throw runtime_error("Kujo68K error");
}

void initST()
{
    reg_sr = ((reg_sr & 0x7FFF) | 0x2000);
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

void updateInterrupts()
{
    // TODO: Implement this function
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

void setFC(bool fc0, bool fc1, bool is_r, bool is_n)
{
    current_pins.pin_fc0 = fc0;
    current_pins.pin_fc1 = fc1;
    current_pins.pin_fc2 = testbit(reg_sr, 13);

    base_ssw = (0x20 | (is_n << 4) | (is_r << 3) | (fc1 << 1) | fc0);
}

void dropCritical()
{
    base_ssw = resetbit(base_ssw, 5);
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

void readRMC()
{
    // TODO: Implement this function
    cout << "readRMC" << endl;
    throw runtime_error("Kujo68K error");
}

void readByte()
{
    is_bus_byte = true;
    is_bus_write = false;
    is_bus_rmc = false;
    is_cpu_access = false;
}

void readWord()
{
    is_bus_byte = false;
    is_bus_write = false;
    is_bus_rmc = false;
    is_cpu_access = false;
}

void readWordCPU()
{
    // TODO: Implement this function
    cout << "readWordCPU" << endl;
    throw runtime_error("Kujo68K error");
}

void writeRMC()
{
    // TODO: Implement this function
    cout << "writeRMC" << endl;
    throw runtime_error("Kujo68K error");
}

void writeByte()
{
    is_bus_byte = true;
    is_bus_write = true;
    is_bus_rmc = false;
    is_cpu_access = false;
}

void writeWord()
{
    is_bus_byte = false;
    is_bus_write = true;
    is_bus_rmc = false;
    is_cpu_access = false;
}

void startIRQVectorLookup()
{
    // TODO: Implement this function
    cout << "startIRQVectorLookup" << endl;
    throw runtime_error("Kujo68K error");
}

void endIRQVectorLookup()
{
    // TODO: Implement this function
    cout << "endIRQVectorLookup" << endl;
    throw runtime_error("Kujo68K error");
}

void startBus()
{
    is_bus_start = true;
    is_rmc_reg = (is_bus_rmc && !is_bus_write);
}

void endBus()
{
    is_bus_start = false;
}

bool readBusStart()
{
    return (bus_state == S0);
}

bool readBusEnd()
{
    return (bus_state == S6);
}

void updateIPL()
{
    // TODO: Implement this function
    return;
}

void trapExcept(uint8_t)
{
    return;
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
}

bool isAddrError()
{
    return testbit(reg_aob, 0);
}

void throwAddrError()
{
    if (testbit(reg_ssw, 5))
    {
	inst_state = SDoubleFault;
    }
    else
    {
	inst_state = SAddrError;
    }

    inst_cycle = 0;
}

int mapSP(int val)
{
    if (val == 15)
    {
	return reg_sp;
    }

    return val;
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

void aluAnd(uint16_t src1, uint16_t src2)
{
    uint16_t res = (src2 & src1);
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

void aluAndx(uint16_t, uint16_t)
{
    cout << "aluAndx" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAndByte(uint16_t src1, uint16_t src2)
{
    uint16_t res = (src2 & src1);
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

void aluAndBytex(uint8_t, uint8_t)
{
    cout << "aluAndBytex" << endl;
    throw runtime_error("Kujo68K error");
}

void aluOr(uint16_t, uint16_t)
{
    cout << "aluOr" << endl;
    throw runtime_error("Kujo68K error");
}

void aluOrByte(uint8_t src1, uint8_t src2)
{
    uint8_t res = (src2 | src1);
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

void aluXor(uint16_t src1, uint16_t src2)
{
    uint16_t res = (src2 ^ src1);
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

void aluXorByte(uint8_t src1, uint8_t src2)
{
    uint8_t res = (src2 ^ src1);
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

void aluAdd(uint16_t src1, uint16_t src2)
{
    uint32_t res = (src2 + src1);
    uint32_t overflow_res = ((src2 & src1 & ~res) | (~src2 & ~src1 & res));
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

    if (testbit(overflow_res, 15))
    {
	reg_isr |= SrOverflow;
    }

    reg_aluo = res;
}

void aluAddByte(uint8_t, uint8_t)
{
    cout << "aluAddByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAddc(uint16_t, uint16_t)
{
    cout << "aluAddc" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAddx(uint16_t, uint16_t)
{
    cout << "aluAddx" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAddxByte(uint8_t, uint8_t)
{
    cout << "aluAddxByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSub(uint16_t src1, uint16_t src2)
{
    uint32_t res = (src2 - src1);
    uint32_t overflow_res = ((src2 & ~src1 & ~res) | (~src2 & src1 & res));
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

    if (testbit(overflow_res, 15))
    {
	reg_isr |= SrOverflow;
    }

    reg_aluo = res;
}

void aluSubByte(uint8_t, uint8_t)
{
    cout << "aluSubByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSubc(uint16_t, uint16_t)
{
    cout << "aluSubc" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSubx(uint16_t, uint16_t)
{
    cout << "aluSubx" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSubxByte(uint8_t, uint8_t)
{
    cout << "aluSubxByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAbcdByte(uint8_t, uint8_t)
{
    cout << "aluAbcdByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSbcdByte(uint8_t, uint8_t)
{
    cout << "aluSbcdByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluExt(uint16_t)
{
    cout << "aluExt" << endl;
    throw runtime_error("Kujo68K error");
}

void aluNot(uint16_t src)
{
    uint16_t res = ~src;
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

void aluNotByte(uint8_t)
{
    cout << "aluNotByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluSla0(uint16_t src)
{
    uint32_t res = ((src << 17) | (reg_alue << 1) | 0);
    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 31))
    {
	reg_isr |= SrSign;
    }

    if (testbit(src, 15))
    {
	reg_isr |= SrCarry;
    }

    reg_alue = res;
    reg_aluo = (res >> 16);
}

void aluSla1(uint16_t src)
{
    uint32_t res = ((src << 17) | (reg_alue << 1) | 1);
    reg_isr = (reg_sr & SrExtend);

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    if (testbit(res, 31))
    {
	reg_isr |= SrSign;
    }

    if (testbit(src, 15))
    {
	reg_isr |= SrCarry;
    }

    reg_alue = res;
    reg_aluo = (res >> 16);
}

void aluOver(uint16_t)
{
    cout << "aluOver" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAsl(uint16_t)
{
    cout << "aluAsl" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAslByte(uint8_t)
{
    cout << "aluAslByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAslLong(uint16_t)
{
    cout << "aluAslLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAsr(uint16_t)
{
    cout << "aluAsr" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAsrByte(uint8_t)
{
    cout << "aluAsrByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluAsrLong(uint16_t src)
{
    uint32_t res = ((reg_alue << 15) | (src >> 1));
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

    if (testbit(src, 0))
    {
	reg_isr |= (SrExtend | SrCarry);
    }

    reg_aluo = res;
    reg_alue = (res >> 16);
}

void aluLsl(uint16_t)
{
    cout << "aluLsl" << endl;
    throw runtime_error("Kujo68K error");
}

void aluLslByte(uint8_t)
{
    cout << "aluLslByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluLslLong(uint16_t)
{
    cout << "aluLslLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluLsr(uint16_t)
{
    cout << "aluLsr" << endl;
    throw runtime_error("Kujo68K error");
}

void aluLsrByte(uint8_t)
{
    cout << "aluLsrByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluLsrLong(uint16_t)
{
    cout << "aluLsrLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRol(uint16_t)
{
    cout << "aluRol" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRolByte(uint8_t)
{
    cout << "aluRolByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRolLong(uint16_t)
{
    cout << "aluRolLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRor(uint16_t src)
{
    uint16_t res = (src >> 1);
    reg_isr = 0;

    if (testbit(src, 0))
    {
	reg_isr |= (SrExtend | SrCarry | SrSign);
	res = setbit(res, 15);
    }

    if (res == 0)
    {
	reg_isr |= SrZero;
    }

    reg_aluo = res;
}

void aluRorByte(uint8_t)
{
    cout << "aluRorByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRorLong(uint16_t)
{
    cout << "aluRorLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxl(uint16_t)
{
    cout << "aluRoxl" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxlByte(uint8_t)
{
    cout << "aluRoxlByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxlLong(uint16_t)
{
    cout << "aluRoxlLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxr(uint16_t)
{
    cout << "aluRoxr" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxrByte(uint8_t)
{
    cout << "aluRoxrByte" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxrLong(uint32_t)
{
    cout << "aluRoxrLong" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxrLongMs(uint16_t)
{
    cout << "aluRoxrLongMs" << endl;
    throw runtime_error("Kujo68K error");
}

void aluRoxrLongMu(uint16_t src)
{
    uint32_t res = ((src << 15) | (reg_alue >> 1) | ((reg_isr & SrCarry) ? (1 << 31) : 0));
    reg_isr = 0;

    if (testbit(src, 0))
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

void updateZ()
{
    auto mask = SrZero;
    reg_sr = ((reg_sr & ~mask) | (reg_isr & mask));
}

void updateNZU()
{
    auto mask = SrSign;
    reg_sr = ((reg_sr & ~mask & (reg_isr | ~SrZero)) | (reg_isr & mask));
}

void updateNZVC()
{
    auto mask = (SrSign | SrZero | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask) | (reg_isr & mask));
}

void updateNZVCU()
{
    auto mask = (SrSign | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask & (reg_isr | ~SrZero)) | (reg_isr & mask));
}

void updateXNZVC()
{
    auto mask = (SrExtend | SrSign | SrZero | SrOverflow | SrCarry);
    reg_sr = ((reg_sr & ~mask) | (reg_isr & mask));
}

void updateXNZVCU()
{
    cout << "updateXNZVCU" << endl;
    throw runtime_error("Kujo68K error");
}