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
	bool pin_bgn = true;
	bool pin_berrn = true;
	bool pin_bgackn = true;
	bool pin_e = false;
    };

    class Kujo68K
    {
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
	    SLineF = 9
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

	public:
	    Kujo68K();
	    ~Kujo68K();

	    void init();
	    void reset();
	    void tickCLK(bool clk);
	    void debugOutput();

	    Kujo68KPins &getPins()
	    {
		return current_pins;
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

	    void resetInternal();
	    void tickInternal();

	    using progfunc = function<void()>;

	    #include "decode.inl"
	    #include "program_funcs.inl"
	    #include "programs.inl"

	    bool prev_clk = false;
	    bool prev_res = false;

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

	    bool is_bus_byte = false;
	    bool is_bus_write = false;
	    bool is_bus_rmc = false;
	    bool is_cpu_access = false;

	    bool is_rmc_reg = false;

	    bool is_dtack = false;

	    bool addr_oe = false;
	    bool data_oe = false;

	    bool bc_complete = false;

	    int e_counter = 0;

	    vector<uint16_t> decode_table;

	    void unrecognizedState()
	    {
		cout << "Unrecognized inst state of " << dec << int(inst_state) << ", cycle of " << dec << int(inst_cycle) << endl;
		throw runtime_error("Kujo68K error");
	    }
    };
};

#endif // KUJO68K_H