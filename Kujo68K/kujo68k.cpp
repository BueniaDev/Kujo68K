#include "kujo68k.h"
using namespace std;

namespace kujo68k
{
    Kujo68KCore::Kujo68KCore()
    {

    }

    Kujo68KCore::~Kujo68KCore()
    {

    }

    void Kujo68KCore::initDecodeTable()
    {
	decode_table.resize(0x10000, SIllegal);

	for (int i = 0; (ir_decode_table.at(i).mask != 0); i++)
	{
	    uint16_t value = ir_decode_table.at(i).val;
	    uint16_t mask = ir_decode_table.at(i).mask;
	    uint16_t state = ir_decode_table.at(i).state;

	    uint16_t cvalue = 0;

	    do
	    {
		if (decode_table.at(value | cvalue) == SIllegal)
		{
		    decode_table.at(value | cvalue) = state;
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

    void Kujo68KCore::clearDecodeTable()
    {
	decode_table.clear();
    }

    void Kujo68KCore::init()
    {
	reg_da.fill(0);
	reg_sr = 0;
	reg_isr = 0;
    }

    void Kujo68KCore::reset()
    {
	setReset(false);
	tickCLK(true);
	tickCLK(false);
	setReset(true);
    }

    void Kujo68KCore::resetInternal()
    {
	inst_state = SReset;
	inst_cycle = 0;
	updateSupervisor();
    }

    void Kujo68KCore::tickCLK(bool clk)
    {
	clk_rise = (!prev_clk && clk);
	clk_fall = (prev_clk && !clk);
	ext_res = !getReset();

	tickInternal();

	prev_clk = clk;
    }

    void Kujo68KCore::debugOutput()
    {
	for (int i = 0; i < 8; i++)
	{
	    cout << "D" << dec << int(i) << ": " << hex << int(reg_da.at(i)) << endl;
	}

	for (int i = 0; i < 7; i++)
	{
	    cout << "A" << dec << int(i) << ": " << hex << int(reg_da.at(8 + i)) << endl;
	}

	cout << "USP: " << hex << int (reg_da.at(15)) << endl;
	cout << "SP: " << hex << int (reg_da.at(16)) << endl;
	cout << "PC: " << hex << int(reg_pc) << endl;
	cout << "IRD: " << hex << int(reg_ird) << endl;
	cout << "IR: " << hex << int(reg_ir) << endl;
	cout << "IRC: " << hex << int(reg_irc) << endl;
	cout << "Bus state: " << dec << int(bus_state) << endl;
	cout << "Next bus state: " << dec << int(next_bus_state) << endl;
	cout << "Inst state: " << dec << int(inst_state) << endl;
	cout << "Inst cycle: " << dec << int(inst_cycle) << endl;
	cout << endl;
    }

    void Kujo68KCore::tickInternal()
    {
	return;
    }

    bool Kujo68KCore::busEnding()
    {
	return true;
    }

    bool Kujo68KCore::getReset()
    {
	return true;
    }

    void Kujo68KCore::setReset(bool)
    {
	return;
    }

    Kujo68000::Kujo68000()
    {
	initDecodeTable();
    }

    Kujo68000::~Kujo68000()
    {
	clearDecodeTable();
    }

    bool Kujo68000::getReset()
    {
	return current_pins.pin_nres;
    }

    void Kujo68000::setReset(bool val)
    {
	current_pins.pin_nres = val;
    }

    void Kujo68000::tickInternal()
    {
	#include "tick68000.inl"
    }
};