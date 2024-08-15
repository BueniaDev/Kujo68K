if (ext_res)
{
    Kujo68KCore::resetInternal();
}
else if (clk_fall)
{
    is_dtack = current_pins.pin_dtack;
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
    addr_oe = false;
    data_oe = false;
}
else
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
	addr_oe = true;
    }
    else if (clk_rise && (bus_state == RmcRes))
    {
	addr_oe = false;
    }
    else if (clk_rise && !is_rmc_reg && is_bus_ending)
    {
	addr_oe = false;
    }

    if (clk_fall && (bus_state == S2) && is_bus_write)
    {
	data_oe = true;
    }
    else if (clk_rise && is_bus_ending)
    {
	data_oe = false;
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
	current_pins.pin_udsn = !(!is_bus_byte || !testbit(reg_aob, 0));
	current_pins.pin_ldsn = !(!is_bus_byte || testbit(reg_aob, 0));
    }
    else if (clk_rise && (bus_state == S4) && is_bus_write)
    {
	current_pins.pin_udsn = !(!is_bus_byte || !testbit(reg_aob, 0));
	current_pins.pin_ldsn = !(!is_bus_byte || testbit(reg_aob, 0));
    }
    else if (clk_fall && (bus_state == S6))
    {
	current_pins.pin_udsn = true;
	current_pins.pin_ldsn = true;
    }

    if (clk_rise && (bus_state == S6) && !is_bus_write)
    {
	reg_edb = current_pins.data;

	if (is_bus_byte && !testbit(reg_aob, 0))
	{
	    reg_edb >>= 8;
	}
    }
}

if (addr_oe)
{
    current_pins.addr = ((reg_aob >> 1) & 0x7FFFFF);
}

if (data_oe)
{
    current_pins.data = reg_dbout;
}

if (clk_rise && !ext_res)
{
    handlers[inst_state].func();
}

is_bus_available = true;

bool is_bus_retry = false;
bool is_bus_reset = ext_res;
bool is_rmc_reset = ((bus_state == S6) && is_bus_reset && is_rmc_reg);
bool is_next_inst = is_bus_begin;

bool can_start = (is_bus_available && (is_next_inst || is_bus_start) && !is_bus_retry && !is_bus_reset);
bool is_bus_end = (!is_dtack || is_stop);

if (clk_fall)
{
    bus_state = next_bus_state;
    is_bus_begin = false;
}

switch (bus_state)
{
    case Idle:
    {
	if (can_start)
	{
	    cout << "Starting bus..." << endl;
	    next_bus_state = S0;
	}
	else
	{
	    next_bus_state = Idle;
	}
    }
    break;
    case S0:
    {
	next_bus_state = S2;
    }
    break;
    case S2:
    {
	next_bus_state = S4;
    }
    break;
    case S4:
    {
	if (is_bus_end)
	{
	    next_bus_state = S6;
	}
	else
	{
	    next_bus_state = S4;
	}
    }
    break;
    case S6:
    {
	if (is_rmc_reset)
	{
	    next_bus_state = RmcRes;
	}
	else if (can_start)
	{
	    cout << "Next bus" << endl;
	    next_bus_state = S0;
	}
	else
	{
	    cout << "Idle bus" << endl;
	    next_bus_state = Idle;
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