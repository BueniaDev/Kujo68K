if (ext_res)
{
    Kujo68KCore::resetInternal();
    is_dtack = false;
}
else if (clk_fall)
{
    int_ipl = reg_ipl;
    reg_ipl = ((!current_pins.pin_ipl2n << 2) | (!current_pins.pin_ipl1n << 1) | !current_pins.pin_ipl0n);
    is_dtack = current_pins.pin_dtack;
    is_rberr = current_pins.pin_berrn;
}
else if (clk_rise)
{
    is_vpai = current_pins.pin_vpan;
    bei_delay = is_bei;
    is_bei = is_rberr;
    is_bri = current_pins.pin_brn;
    is_bgacki = current_pins.pin_bgackn;
}

if (clk_fall)
{
    if (e_counter == 9)
    {
	current_pins.pin_e = false;
    }
    else if (e_counter == 5)
    {
	current_pins.pin_e = true;
    }

    e_counter += 1;

    if (e_counter == 10)
    {
	e_counter = 0;
    }
}

if (clk_fall)
{
    bool is_ipl_stable = (int_ipl == reg_ipl);
    bool is_nmi = (int_ipl == 7);
    bool ipl_comp = (reg_ipl > ((reg_sr >> 8) & 0x7));

    is_nmi_occured = (!prev_nmi && is_nmi);

    bool is_iac = (current_pins.pin_fc2 && current_pins.pin_fc1 && current_pins.pin_fc0);

    if (is_ipl_stable && (is_nmi_occured || ipl_comp))
    {
	is_intpend = true;
	updateInterrupts();
    }
    else if (((reg_inl == 0x7) && is_iac) || (is_ipl_stable && !is_nmi && !ipl_comp))
    {
	is_intpend = false;
	updateInterrupts();
    }

    prev_nmi = is_nmi;
}

if (clk_rise && (bus_state == S4) && is_cpu_access)
{
    bool is_iac = (current_pins.pin_fc2 && current_pins.pin_fc1 && current_pins.pin_fc0);
    is_spurious = (!bei_delay && is_iac);
    is_autovec = (!is_vpai && is_iac);
}

if (clk_rise && (bus_state == S6) && is_cpu_access)
{
    if (is_autovec)
    {
	int level = ((reg_aob >> 1) & 0x7);
	reg_edb = (0x18 + level);
    }
    else if (is_spurious)
    {
	reg_edb = 0x18;
    }
    else
    {
	reg_edb = current_pins.data;
    }
}

if (ext_res)
{
    current_pins.pin_asn = true;
    current_pins.pin_rnw = true;
    current_pins.pin_udsn = true;
    current_pins.pin_ldsn = true;
    current_pins.pin_fc0 = false;
    current_pins.pin_fc1 = false;
    current_pins.pin_fc2 = false;
}
else if (is_bus_active)
{
    bool is_bus_ending = ((bus_state == S0) || (bus_state == Idle));

    if (clk_rise && (bus_state == S0))
    {
	current_pins.pin_fc0 = testbit(base_ssw, 0);
	current_pins.pin_fc1 = testbit(base_ssw, 1);
	current_pins.pin_fc2 = testbit(reg_sr, 13);
    }

    if (clk_fall && (bus_state == S0))
    {
	current_pins.addr = ((reg_aob >> 1) & 0x7FFFFF);
    }

    if (clk_fall && (bus_state == S2) && is_bus_write)
    {
	current_pins.data = reg_dbout;
    }

    if (clk_rise && (bus_state == S2))
    {
	current_pins.pin_asn = false;
    }
    else if (clk_fall && (bus_state == RmcRes))
    {
	current_pins.pin_asn = true;
    }
    else if (clk_fall && (bus_state == S6) && !is_rmc_reg)
    {
	current_pins.pin_asn = true;
    }

    if (clk_rise && is_bus_ending)
    {
	current_pins.pin_rnw = true;
    }
    else if (clk_rise && (bus_state == S2) && is_bus_write)
    {
	current_pins.pin_rnw = false;
    }

    if (clk_rise && (bus_state == S2) && !is_bus_write)
    {
	current_pins.pin_udsn = (is_bus_byte && testbit(reg_aob, 0));
	current_pins.pin_ldsn = (is_bus_byte && !testbit(reg_aob, 0));
    }
    else if (clk_rise && (bus_state == S4) && is_bus_write)
    {
	current_pins.pin_udsn = (is_bus_byte && testbit(reg_aob, 0));
	current_pins.pin_ldsn = (is_bus_byte && !testbit(reg_aob, 0));
    }
    else if (clk_fall && (bus_state == S6))
    {
	current_pins.pin_udsn = true;
	current_pins.pin_ldsn = true;
    }

    if (clk_rise && (bus_state == S6) && !is_bus_write && !is_cpu_access)
    {
	reg_edb = current_pins.data;

	if (is_bus_byte && !testbit(reg_aob, 0))
	{
	    reg_edb >>= 8;
	}
    }
}

if (clk_rise && !ext_res && is_bus_active)
{
    (this->*(handlers[inst_state].func))();
}

bool bg_block = (((bus_state == S0) && current_pins.pin_asn) || (bus_state == RmcRes));

if (ext_res)
{
    dma_phase = DmaReset;
    is_bus_granted = false;
    current_pins.pin_bgn = true;
}
else if (clk_fall)
{
    switch (dma_phase)
    {
	case DmaReset:
	{
	    dma_phase = DmaIdle;
	    is_bus_granted = false;
	}
	break;
	case DmaIdle:
	{
	    if (!bg_block)
	    {
		if (!is_bgacki)
		{
		    // cout << "Switching to DMA state of BA" << endl;
		    // throw runtime_error("Kujo68K error");
		    dma_phase = DmaBa;
		    is_bus_granted = false;
		}
		else if (!is_bri)
		{
		    dma_phase = DmaD1;
		    is_bus_granted = true;
		    // cout << "Switching to DMA state of D1" << endl;
		    // throw runtime_error("Kujo68K error");
		}
	    }
	}
	break;
	case DmaBa:
	{
	    if (!is_bri && !bg_block)
	    {
		dma_phase = DmaD3;
		is_bus_granted = true;
	    }
	    else if (is_bgacki || bg_block)
	    {
		dma_phase = DmaIdle;
		is_bus_granted = false;
	    }
	}
	break;
	case DmaD1:
	{
	    dma_phase = DmaBr;
	    is_bus_granted = true;
	}
	break;
	case DmaD3:
	{
	    dma_phase = DmaBra;
	    is_bus_granted = true;
	}
	break;
	case DmaBr:
	{
	    if (is_bri || !is_bgacki)
	    {
		dma_phase = DmaBa;
		is_bus_granted = false;
	    }
	}
	break;
	case DmaBra:
	{
	    if (is_bgacki)
	    {
		dma_phase = (is_bri) ? DmaIdle : DmaBr;
		is_bus_granted = !is_bri;
	    }
	    else if (is_bri)
	    {
		dma_phase = DmaD2;
		is_bus_granted = false;
	    }
	}
	break;
	case DmaD2:
	{
	    dma_phase = DmaBa;
	    is_bus_granted = false;
	}
	break;
	default:
	{
	    cout << "Unrecognized DMA state of " << dec << int(dma_phase) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }
}
else if (clk_rise)
{
    current_pins.pin_bgn = !is_bus_granted;
}

if (ext_res)
{
    is_bus_active = true;
}
else
{
    is_bus_active = (is_bri && is_bgacki && !is_bus_granted);
}

if (ext_res)
{
    bus_state = Idle;
}
else if (clk_fall)
{
    switch (bus_state)
    {
	case Idle:
	{
	    is_bus_available = (is_bri && is_bgacki && !is_bus_granted);
	    bool is_bus_retry = false;
	    bool is_bus_reset = ext_res;
	    bool is_next_inst = is_bus_begin;

	    bool can_start = (is_bus_available && (is_next_inst || is_bus_start) && !is_bus_retry && !is_bus_reset);

	    if (can_start)
	    {
		bus_state = S0;
	    }
	}
	break;
	case S0:
	{
	    bus_state = S2;
	}
	break;
	case S2:
	{
	    bus_state = S4;
	}
	break;
	case S4:
	{
	    if (!is_dtack || is_stop)
	    {
		bus_state = S6;
	    }
	}
	break;
	case S6:
	{
	    is_bus_available = (is_bri && is_bgacki && !is_bus_granted);
	    bool is_bus_retry = false;
	    bool is_bus_reset = ext_res;
	    bool is_next_inst = is_bus_begin;

	    bool is_rmc_reset = (is_bus_reset && is_rmc_reg);

	    bool can_start = (is_bus_available && (is_next_inst || is_bus_start) && !is_bus_retry && !is_bus_reset);

	    if (is_rmc_reset)
	    {
		bus_state = RmcRes;
	    }
	    else if (can_start)
	    {
		bus_state = S0;
	    }
	    else
	    {
		bus_state = Idle;
	    }
	}
	break;
	case RmcRes: bus_state = Idle; break;
	default:
	{
	    cout << "Unrecognized bus state of " << dec << int(bus_state) << endl;
	    throw runtime_error("Kujo68K error");
	}
	break;
    }

    is_bus_begin = false;
}