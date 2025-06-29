#ifndef KUJO68K_H
#define KUJO68K_H

#include <iostream>
#include <cstdint>
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
    struct Kujo68000Pins
    {
	bool pin_nres = true;
	uint32_t addr = 0;
	uint16_t data = 0;
	bool pin_rnw = true;
	bool pin_asn = true;
	bool pin_udsn = true;
	bool pin_ldsn = true;
	bool pin_dtack = false;
	bool pin_e = false;
	bool pin_vpan = true;
	bool pin_vman = true;
	bool pin_ipl0n = true;
	bool pin_ipl1n = true;
	bool pin_ipl2n = true;
	bool pin_fc0 = false;
	bool pin_fc1 = false;
	bool pin_fc2 = false;
	bool pin_brn = true;
	bool pin_bgn = true;
	bool pin_bgackn = true;
	bool pin_berrn = true;
    };

    class Kujo68KCore
    {
	public:
	    Kujo68KCore();
	    ~Kujo68KCore();

	    void init();
	    void reset();
	    void tickCLK(bool clk);

	    bool isInstEnd()
	    {
		return (inst_cycle == 0);
	    }

	    void debugOutput();

	    uint32_t getDataReg(int reg)
	    {
		reg &= 0x7;
		return reg_da.at(reg);
	    }

	    uint32_t getAddrReg(int reg)
	    {
		reg &= 0x7;

		if (reg == 7)
		{
		    // TODO: Implement stack pointer selection
		    return getSP();
		}
		else
		{
		    return reg_da.at(8 + reg);
		}
	    }

	    uint32_t getIPC()
	    {
		if (inst_state >= SFirstInstruction)
		{
		    return (reg_pc - 2);
		}
		else
		{
		    return 0;
		}
	    }

	    uint32_t getPC()
	    {
		return reg_pc;
	    }

	    virtual void tickInternal();
	    virtual bool busEnding();
	    virtual uint32_t getSP();

	    virtual bool getReset();
	    virtual void setReset(bool val);

	protected:
	    enum : int
	    {
		SReset = 0,
		SBusError = 1,
		SAddrError = 2,
		SDoubleFault = 3,
		SInterrupt = 4,
		STrace = 5,
		SIllegal = 6,
		SPrivilege = 7,
		SLineA = 8,
		SLineF = 9,
		SFirstInstruction
	    };

	    enum DMAPhase
	    {
		DmaReset = 0,
		DmaIdle,
		DmaD1,
		DmaBr,
		DmaBa,
		DmaBra,
		DmaD3,
		DmaD2
	    };

	    enum BusState
	    {
		Idle = 0,
		S0,
		S2,
		S4,
		S6,
		RmcRes
	    };

	    enum : int
	    {
		SrCarry = (1 << 0),
		SrOverflow = (1 << 1),
		SrZero = (1 << 2),
		SrSign = (1 << 3),
		SrExtend = (1 << 4)
	    };

	    struct Kujo68KDecode
	    {
		uint16_t val = 0;
		uint16_t mask = 0;
		uint16_t state = 0;
	    };

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

	    void initDecodeTable();
	    void clearDecodeTable();

	    void resetInternal();

	    using progfunc = function<void()>;

	    struct Kujo68KHandler
	    {
		progfunc func;
		bool is_first_step = false;
	    };

	    #include "decode.inl"
	    #include "program_funcs.inl"
	    #include "programs.inl"

	    bool prev_clk = false;

	    bool clk_rise = false;
	    bool clk_fall = false;

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
	    uint32_t reg_movems = 0;

	    int rx_index = 0;
	    int ry_index = 0;

	    int reg_t = 0;

	    uint16_t inst_cycle = 0;
	    uint16_t inst_state = 0;

	    uint32_t next_state = 0;
	    uint32_t int_next_state = 0;

	    uint8_t reg_int_vec = 0;

	    uint16_t reg_ssw = 0;
	    uint16_t base_ssw = 0;

	    BusState bus_state = Idle;
	    BusState next_bus_state = Idle;

	    bool is_bus_available = false;
	    bool is_bus_start = false;

	    bool is_last_bus_cycle = false;
	    bool is_next_inst = false;

	    bool is_end_of_bus = false;
	    bool is_bus_disable = false;

	    bool is_bus_begin = false;

	    bool is_bus_byte = false;
	    bool is_bus_write = false;
	    bool is_bus_rmc = false;
	    bool is_cpu_access = false;

	    bool is_rmc_reg = false;

	    bool is_dtack = false;
	    bool is_vpai = false;
	    bool is_xvma = false;
	    bool is_stop = false;

	    bool addr_oe = false;
	    bool data_oe = false;

	    bool ext_res = false;

	    int e_counter = 0;

	    vector<uint16_t> decode_table;

	    void unrecognizedState()
	    {
		cout << "Unrecognized inst state of " << dec << int(inst_state) << ", cycle of " << dec << int(inst_cycle) << endl;
		throw runtime_error("Kujo68K error");
	    }
    };

    class Kujo68000 : public Kujo68KCore
    {
	public:
	    Kujo68000();
	    ~Kujo68000();

	    void tickInternal();
	    bool getReset();
	    void setReset(bool val);

	    uint32_t getSP()
	    {
		if (testbit(reg_sr, 13))
		{
		    return reg_da.at(16);
		}
		else
		{
		    return reg_da.at(15);
		}
	    }

	    Kujo68000Pins &getPins()
	    {
		return current_pins;
	    }

	private:
	    Kujo68000Pins current_pins;
    };
};

#endif // KUJO68K_H