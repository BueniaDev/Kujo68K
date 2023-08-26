if (clk_fall)
{
    reg_ipl = ((!current_pins.pin_ipl2n << 2) | (!current_pins.pin_ipl1n << 1) | (!current_pins.pin_ipl0n));
    m_ipl = reg_ipl;
    is_rberr = current_pins.pin_berrn;
}
else if (clk_rise)
{
    is_vpai = current_pins.pin_vpan;
    is_bei = is_rberr;
    bei_delay = is_bei;
}

bool is_nmi = (m_ipl == 7);
bool ipl_stable = (m_ipl == reg_ipl);
bool ipl_comp = (reg_ipl > ((reg_sr >> 8) & 0x7));

int reg_fc = ((current_pins.pin_fc2 << 2) | (current_pins.pin_fc1 << 1) | current_pins.pin_fc0);
is_iac = (reg_fc == 0x7);

if (clk_fall)
{
    is_nmi_occured = (!prev_nmi && is_nmi);

    if (ipl_stable && ((!prev_nmi && is_nmi) || ipl_comp))
    {
	is_intpend = true;
	updateInterrupts();
    }
    else if (((reg_inl == 0x7) && is_iac) || (ipl_stable && !is_nmi && !ipl_comp))
    {
	is_intpend = false;
	updateInterrupts();
    }

    prev_nmi = is_nmi;
}

if (clk_fall)
{
    e_counter += 1;

    if (e_counter == 6)
    {
	current_pins.pin_e = true;
    }

    if (e_counter == 10)
    {
	e_counter = 0;
	current_pins.pin_e = false;
    }
}

if (clk_rise)
{
    callFunc();
}

if (is_cpu_access)
{
    switch (bus_state)
    {
	case S0:
	{
	    current_pins.pin_udsn = false;
	    current_pins.pin_ldsn = false;
	    current_pins.pin_rnw = true;
	    bus_state = S1;
	}
	break;
	case S1:
	{
	    current_pins.addr = ((reg_aob >> 1) & 0x7FFFFF);
	    bus_state = S2;
	}
	break;
	case S2:
	{
	    current_pins.pin_asn = false;
	    bus_state = S3;
	}
	break;
	case S3:
	{
	    bus_state = S4;
	}
	break;
	case S4:
	{
	    is_spurious = (!bei_delay && is_iac);
	    is_autovec = (!is_vpai && is_iac);
	    bus_state = S5;
	}
	break;
	case S5:
	{
	    bus_state = S6;
	}
	break;
	case S6:
	{
	    bus_state = S7;
	}
	break;
	case S7:
	{
	    current_pins.pin_asn = true;
	    current_pins.pin_udsn = true;
	    current_pins.pin_ldsn = true;

	    if (is_autovec)
	    {
		int level = (current_pins.addr & 0x7);
		cout << "Autovectored interrupt of " << dec << int(level) << endl;
		reg_edb = (0x18 + level);
	    }
	    else if (is_spurious)
	    {
		cout << "Spurious interrupt" << endl;
		reg_edb = 0x18;
	    }
	    else
	    {
		cout << "Custom interrupt" << endl;
		reg_edb = current_pins.data;
	    }

	    is_cpu_access = false;
	    bus_state = Idle;
	}
	break;
	default:
	{
	    cout << "Unrecognized CPU bus state of " << dec << int(bus_state) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }
}

if (is_bus_access)
{
    switch (bus_state)
    {
	case S0:
	{
	    current_pins.pin_rnw = true;
	    bus_state = S1;
	}
	break;
	case S1:
	{
	    current_pins.addr = ((reg_aob >> 1) & 0x7FFFFF);
	    bus_state = S2;
	}
	break;
	case S2:
	{
	    current_pins.pin_asn = false;

	    if (is_read)
	    {
		if (is_word)
		{
		    current_pins.pin_udsn = false;
		    current_pins.pin_ldsn = false;
		}
		else
		{
		    current_pins.pin_udsn = testbit(reg_aob, 0);
		    current_pins.pin_ldsn = !testbit(reg_aob, 0);
		}
	    }
	    else if (is_rmc)
	    {
		cout << "RMC read occured, S2" << endl;
		throw runtime_error("Kujo68K error");
	    }
	    else
	    {
		current_pins.pin_rnw = false;
	    }

	    bus_state = S3;
	}
	break;
	case S3:
	{
	    if (!is_read && !is_rmc)
	    {
		current_pins.data = reg_dbout;
	    }

	    bus_state = S4;
	}
	break;
	case S4:
	{
	    if (!is_read && !is_rmc)
	    {
		if (is_word)
		{
		    current_pins.pin_udsn = false;
		    current_pins.pin_ldsn = false;
		}
		else
		{
		    current_pins.pin_udsn = testbit(reg_aob, 0);
		    current_pins.pin_ldsn = !testbit(reg_aob, 0);
		}
	    }

	    bool end_signal = !current_pins.pin_dtack;

	    if (!end_signal)
	    {
		cout << "Delay occuring..." << endl;
		throw runtime_error("Kujo68K error");
	    }
	    else
	    {
		bus_state = S5;
	    }
	}
	break;
	case S5:
	{
	    bus_state = S6;
	}
	break;
	case S6:
	{
	    if (is_read)
	    {
		reg_edb = current_pins.data;

		if (!is_word)
		{
		    if (!testbit(reg_aob, 0))
		    {
			reg_edb >>= 8;
		    }
		}

		current_pins.pin_asn = true;
		current_pins.pin_udsn = true;
		current_pins.pin_ldsn = true;
	    }
	    else if (is_rmc)
	    {
		cout << "RMC read occured, S6" << endl;
		throw runtime_error("Kujo68K error");
	    }
	    else
	    {
		current_pins.pin_asn = true;
		current_pins.pin_udsn = true;
		current_pins.pin_ldsn = true;
	    }
	    
	    bus_state = S7;
	}
	break;
	case S7:
	{
	    if (!is_read && !is_rmc)
	    {
		current_pins.pin_rnw = true;
		is_bus_access = false;
		bus_state = Idle;
	    }
	    else if (is_rmc)
	    {
		cout << "RMC read occured, S7" << endl;
		throw runtime_error("Kujo68K error");
	    }
	    else
	    {
		is_bus_access = false;
		bus_state = Idle;
	    }
	}
	break;
	default:
	{
	    cout << "Unrecognized bus state of " << dec << int(bus_state) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }
}