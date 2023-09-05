#include "kujo68k.h"
using namespace std;

namespace kujo68k
{
    Kujo68K::Kujo68K()
    {
	decode_table.resize(0x10000, {getFunction(DoubleFaultDp), true});

	for (int i = 0; (ir_decode_table.at(i).mask != 0); i++)
	{
	    uint16_t value = ir_decode_table.at(i).val;
	    uint16_t mask = ir_decode_table.at(i).mask;
	    auto func = ir_decode_table.at(i).func;

	    uint16_t cvalue = 0;

	    do
	    {
		if (decode_table.at(value | cvalue).is_illegal)
		{
		    decode_table.at(value | cvalue).func = func;
		    decode_table.at(value | cvalue).is_illegal = false;
		}
		else if (((value | cvalue) & 0xF0FF) != 0x6000)
		{
		    cout << "Decode collision occured" << endl;
		    throw runtime_error("Kujo68K error");
		}

		cvalue = (((cvalue | mask) + 1) & ~mask);
	    } while (cvalue != 0);
	}
    }

    Kujo68K::~Kujo68K()
    {
	decode_table.clear();
    }

    void Kujo68K::init()
    {
	current_pins = {};
	reg_da.fill(0);
	reg_sr = 0;
	reg_isr = 0;
	updateSupervisor();
    }

    void Kujo68K::tick()
    {
	tickCLK(true);
	tickCLK(false);
    }

    void Kujo68K::reset()
    {
	inst_state = 0;
	inst_cycle = 0;
	reg_inl = 7;
	is_reset = true;
    }

    void Kujo68K::tickCLK(bool clk)
    {
	static bool prev_clk = false;
	static bool prev_res = false;
	clk_rise = (!prev_clk && clk);
	clk_fall = (prev_clk && !clk);

	if (!current_pins.pin_nres)
	{
	    reset();
	}
	else if (!prev_res && current_pins.pin_nres)
	{
	    is_reset = false;
	    instr_decode = getFunction(ResetDp);
	    // instr_decode = getFunction(Test);
	}
	else if (prev_clk != clk)
	{
	    tickInternal();
	}

	prev_clk = clk;
	prev_res = current_pins.pin_nres;
    }

    void Kujo68K::tickInternal()
    {
	#include "tick.inl"
    }
};