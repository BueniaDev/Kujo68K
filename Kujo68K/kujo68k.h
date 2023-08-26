#ifndef KUJO68K_H
#define KUJO68K_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include <cassert>
#include <array>
#include <vector>
#include <deque>
#include <unordered_map>
#include <optional>
#include <functional>
using namespace std;
using namespace std::placeholders;

namespace kujo68k
{
    enum Kujo68KState : int
    {
	None = 0,
	Reset = 1,
	DoubleFault = 4,
	Interrupt = 5,
	Trace = 6,
    };

    enum Kujo68KALUOp
    {
	AluNone = 0,
	AluAnd,
	AluAndx,
	AluAndByte,
	AluAndBytex,
	AluOr,
	AluOrByte,
	AluXor,
	AluXorByte,
	AluAdd,
	AluAddc,
	AluAddByte,
	AluAddx,
	AluAddxByte,
	AluSub,
	AluSubByte,
	AluSubx,
	AluSubxByte,
	AluSubc,
	AluNot,
	AluNotByte,
	AluExt,
	AluAbcd,
	AluAbcdByte,
	AluSbcd,
	AluSbcdByte,
	AluLsl,
	AluLsr,
	AluAsl,
	AluAsr,
	AluRol,
	AluRor,
	AluRoxl,
	AluRoxr,
	AluRoxrLong,
    };

    enum Kujo68KCCR
    {
	CcrNone = 0,
	CcrZ,
	CcrNZU,
	CcrNZVC,
	CcrNZVCU,
	CcrXNZVC,
	CcrXNZVCU
    };

    using progfunc = function<void()>;

    struct Kujo68KDecode
    {
	uint16_t val = 0;
	uint16_t mask = 0;
	progfunc func;
    };

    struct Kujo68KInstruction
    {
	progfunc func;
	bool is_illegal = true;
    };

    struct Kujo68KPins
    {
	bool pin_nres = true;
	uint32_t addr = 0;
	uint16_t data = 0;
	bool pin_rnw = true;
	bool pin_asn = true;
	bool pin_udsn = true;
	bool pin_ldsn = true;
	bool pin_dtack = false;
	bool pin_vpan = true;
	bool pin_ipl0n = true;
	bool pin_ipl1n = true;
	bool pin_ipl2n = true;
	bool pin_fc0 = false;
	bool pin_fc1 = false;
	bool pin_fc2 = false;
	bool pin_brn = true;
	bool pin_berrn = true;
	bool pin_bgackn = true;
	bool pin_e = false;
    };

    enum BusState
    {
	Idle = 0,
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7
    };

    class Kujo68K
    {
	public:
	    Kujo68K();
	    ~Kujo68K();

	    void init();
	    void tick();
	    void tickCLK(bool clk);

	    Kujo68KPins &getPins()
	    {
		return current_pins;
	    }

	    uint32_t getDataReg(int reg)
	    {
		reg &= 0x7;
		return reg_da.at(reg);
	    }

	    uint32_t getAddrReg(int reg)
	    {
		reg &= 0x7;
		return reg_da.at(reg + 8);
	    }

	    void debugOutput()
	    {
		for (int i = 0; i < 8; i++)
		{
		    cout << "D" << dec << int(i) << ": " << hex << int(getDataReg(i)) << endl;
		}

		for (int i = 0; i < 7; i++)
		{
		    cout << "A" << hex << int(i) << ": " << hex << int(getAddrReg(i)) << endl;
		}

		cout << "USP: " << hex << int (reg_da.at(15)) << endl;
		cout << "SP: " << hex << int (reg_da.at(16)) << endl;

		cout << "PC: " << hex << int(reg_pc) << endl;
		cout << "IRD: " << hex << int(reg_ird) << endl;
		cout << "IR: " << hex << int(reg_ir) << endl;
		cout << "IRC: " << hex << int(reg_irc) << endl;

		cout << endl;
	    }

	private:
	    template<typename T>
	    bool testbit(T reg, int bit)
	    {
		return ((reg >> bit) & 0x1) ? true : false;
	    }

	    template<typename T>
	    T setbit(T reg, int bit)
	    {
		return (reg | (1 << bit));
	    }

	    template<typename T>
	    T resetbit(T reg, int bit)
	    {
		return (reg & ~(1 << bit));
	    }

	    Kujo68KPins current_pins;

	    void reset();
	    void tickInternal();

	    #include "program_funcs.inl"
	    #include "programs.inl"
	    #include "ir_decode.inl"

	    bool is_bus_access = false;
	    bool is_read = false;
	    bool is_rmc = false;
	    bool is_word = false;
	    bool clk_rise = false;
	    bool clk_fall = false;

	    bool is_cpu_access = false;
	    bool is_spurious = false;
	    bool is_autovec = false;

	    int e_counter = 0;

	    int inst_cycle = 0;
	    int inst_state = 0;

	    BusState bus_state = Idle;

	    uint16_t reg_irdi = 0;
	    uint16_t reg_ird = 0;
	    uint16_t reg_ir = 0;
	    uint16_t reg_irc = 0;
	    uint16_t reg_ftu = 0;
	    uint32_t reg_au = 0;
	    uint16_t reg_alub = 0;
	    uint16_t reg_alue = 0;
	    uint32_t reg_aob = 0;
	    uint16_t reg_edb = 0;
	    uint16_t reg_dbin = 0;
	    uint16_t reg_dbout = 0;
	    uint32_t reg_at = 0;
	    uint32_t reg_dt = 0;
	    uint32_t reg_pc = 0;
	    uint16_t reg_sr = 0;
	    uint16_t reg_isr = 0;
	    uint16_t reg_aluo = 0;
	    uint16_t reg_movemr = 0;
	    array<uint32_t, 18> reg_da;
	    uint32_t reg_sp = 0;
	    uint8_t reg_dcr = 0;
	    uint16_t reg_new_sr = 0;

	    int sp_index = 0;

	    int rx_index = 0;
	    int ry_index = 0;

	    int reg_t = 0;

	    uint32_t next_state = 0;
	    uint32_t int_next_state = 0;

	    int reg_ipl = 0;
	    int m_ipl = 0;
	    int reg_inl = 0;

	    uint8_t reg_int_vec = 0;

	    bool bei_delay = false;
	    bool is_bei = false;
	    bool is_rberr = false;
	    bool is_vpai = false;

	    bool prev_nmi = false;
	    bool is_nmi_occured = false;
	    bool is_iac = false;
	    bool is_intpend = false;

	    uint32_t base_ssw = 0;

	    vector<Kujo68KInstruction> decode_table;

	    progfunc instr_decode;

	    progfunc getStateFunc(uint32_t state)
	    {
		Kujo68KState valid_state = static_cast<Kujo68KState>((state & 0xFFFF));

		switch (valid_state)
		{
		    case Reset: return getFunction(ResetDp); break;
		    case DoubleFault: return getFunction(DoubleFaultDp); break;
		    case Interrupt: return getFunction(InterruptDp); break;
		    default: return getFunction(DoubleFaultDp); break;
		}
	    }

	    void callFunc()
	    {
		instr_decode();
	    }

	    void unrecognizedState()
	    {
		cout << "Unrecognized inst state of " << dec << int(inst_state) << ", cycle of " << dec << int(inst_cycle) << endl;
		throw runtime_error("Kujo68K error");
	    }
    };
};



#endif // KUJO68K_H