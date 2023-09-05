bool be_debounced = !(is_bei || bei_delay);

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

    is_bgack = current_pins.pin_bgackn;

    is_bri = current_pins.pin_brn;
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

bus_available = true;

bool is_access = (is_bus_access || is_cpu_access);
if (clk_rise && !is_access)
{
    callFunc();
}

bc_complete = (bus_state == S6);

bool bc_reset = false;

bool is_rmc_reset = (bc_complete && bc_reset && is_rmc_reg);

bool bus_end = !current_pins.pin_dtack;

if (clk_rise && (bus_state == S4) && is_cpu_access)
{
    is_spurious = (!bei_delay && is_iac);
    is_autovec = (!is_vpai && is_iac);
}

if (clk_fall && bc_complete && is_cpu_access)
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

bool is_bus_s6 = is_bus_access;

if (clk_fall && bc_complete)
{
    is_bus_access = false;
    is_cpu_access = false;
}

bool is_perm_start = (is_bus_access || is_cpu_access);

bus_can_start = (bus_available && is_perm_start && !bc_reset);

switch (bus_state)
{
    case Idle:
    {
	if (bus_can_start)
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
	if (bus_end)
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
	else if (bus_can_start)
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

bool bus_ending = ((next_bus_state == Idle) || (next_bus_state == S0));

if (clk_rise)
{
    bus_state = next_bus_state;
}

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

if (clk_fall && !is_read && (bus_state == S2))
{
    data_oe = true;
}
else if (clk_rise && (bus_ending || (bus_state == Idle)))
{
    data_oe = false;
}

if (clk_rise && bus_ending)
{
    current_pins.pin_rnw = true;
}
else if (clk_rise && !is_read)
{
    if (bus_state == S2)
    {
	current_pins.pin_rnw = false;
    }
}

if (addr_oe)
{
    if (true)
    {
	current_pins.addr = ((reg_aob >> 1) & 0x7FFFFF);
    }
    else
    {
	cout << "M68008 address OE" << endl;
	throw runtime_error("Kujo68K error");
    }
}

if (data_oe)
{
    if (true)
    {
	current_pins.data = reg_dbout;
    }
    else
    {
	cout << "M68008 data OE" << endl;
	throw runtime_error("Kujo68K error");
    }
}

if (clk_rise && (bus_state == S6) && is_read && is_bus_s6)
{
    if (true)
    {
	reg_edb = current_pins.data;

	if (!is_word && !testbit(reg_aob, 0))
	{
	    reg_edb >>= 8;
	}
    }
    else
    {
	cout << "M68008 data latch" << endl;
	throw runtime_error("Kujo68K error");
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
    if (is_read)
    {
	if (true)
	{
	    current_pins.pin_udsn = !(is_word || !testbit(reg_aob, 0));
	    current_pins.pin_ldsn = !(is_word || testbit(reg_aob, 0));
	}
	else
	{
	    cout << "M68008 DS pin read" << endl;
	    throw runtime_error("Kujo68K error");
	}
    }
}
else if (clk_rise && !is_read && (bus_state == S2))
{
    if (true)
    {
	current_pins.pin_udsn = !(is_word || !testbit(reg_aob, 0));
	current_pins.pin_ldsn = !(is_word || testbit(reg_aob, 0));
    }
    else
    {
	cout << "M68008 DS pin write" << endl;
	throw runtime_error("Kujo68K error");
    }
}
else if (clk_fall && bc_complete)
{
    current_pins.pin_udsn = true;
    current_pins.pin_ldsn = true;
}

