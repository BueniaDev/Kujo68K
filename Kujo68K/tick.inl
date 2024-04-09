if (clk_fall)
{
    is_dtack = current_pins.pin_dtack;
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
    handlers[inst_state]();
}

is_bus_available = true;

bool can_start = ((is_bus_available) && (is_bus_start));
bool is_bus_end = !is_dtack;
bool bc_complete = (bus_state == S6);
bool is_rmc_reset = (bc_complete && is_rmc_reg);

switch (bus_state)
{
    case Idle:
    {
	if (can_start)
	{
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
	    cout << "RMC reset state..." << endl;
	    throw runtime_error("Kujo68K error");
	}
	else if (can_start)
	{
	    next_bus_state = S0;
	}
	else
	{
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

if (clk_rise)
{
    bus_state = next_bus_state;
}

bc_complete = (bus_state == S6);

bool bus_ending = ((next_bus_state == Idle) || (next_bus_state == S0));

if (clk_fall && (bus_state == S0))
{
    addr_oe = true;
}
else if (clk_rise && (bus_state == RmcRes))
{
    addr_oe = false;
}
else if (clk_rise && !is_rmc_reg && bus_ending)
{
    addr_oe = false;
}

if (clk_rise && bus_ending)
{
    current_pins.pin_rnw = true;
}
else if (clk_rise && is_bus_write)
{
    if (bus_state == S2)
    {
	current_pins.pin_rnw = false;
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

if (clk_rise && (bus_state == S6) && !is_bus_write)
{
    reg_edb = current_pins.data;

    if (is_bus_byte && !testbit(reg_aob, 0))
    {
	reg_edb >>= 8;
    }
}

if (clk_rise && (bus_state == S0))
{
    current_pins.pin_asn = false;
}
else if (clk_fall && (bus_state == RmcRes))
{
    current_pins.pin_asn = true;
}
else if (clk_fall && bc_complete)
{
    if (!is_rmc_reg)
    {
	current_pins.pin_asn = true;
    }
}

if (clk_rise && (bus_state == S0))
{
    if (!is_bus_write)
    {
	current_pins.pin_udsn = !(!is_bus_byte || !testbit(reg_aob, 0));
	current_pins.pin_ldsn = !(!is_bus_byte || testbit(reg_aob, 0));
    }
}
else if (clk_rise && is_bus_write && (bus_state == S2))
{
    current_pins.pin_udsn = !(!is_bus_byte || !testbit(reg_aob, 0));
    current_pins.pin_ldsn = !(!is_bus_byte || testbit(reg_aob, 0));
}
else if (clk_fall && bc_complete)
{
    current_pins.pin_udsn = true;
    current_pins.pin_ldsn = true;
}