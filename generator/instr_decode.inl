struct KujoPLA
{
    uint16_t val = 0;
    uint16_t mask = 0;
};

struct KujoPLA1Extend
{
    uint16_t maddr = 0;
    uint16_t val = 0;
    uint16_t mask = 0;
    int line = 0;
    vector<int> lines;
};

struct KujoPLA23Extend
{
    uint16_t a2_addr = 0;
    uint16_t a3_addr = 0;
    uint16_t val = 0;
    uint16_t mask = 0;
    int line = 0;
    vector<int> lines;
};

vector<KujoPLA> priv_pla = { { 0x46c0, 0xffc0 }, { 0x4e70, 0xfffd }, { 0x4e72, 0xfffe }, { 0x007c, 0xf5ff }, { 0x4e60, 0xfff0 } };

vector<KujoPLA> a1_pla_long =
{
    { 0x9180, 0x9180 }, { 0x9080, 0x90c0 }, { 0x8080, 0xa0c0 }, { 0x5080, 0xf0c0 },
    { 0x4a80, 0xffc0 }, { 0x4080, 0xf9c0 }, { 0x2000, 0xf000 }
};

vector<KujoPLA> a1_pla_byte_short = {
    { 0xe0c0, 0xf8c0 }, { 0x5040, 0xf040 }, { 0x5000, 0xf080 }, { 0x9040, 0x9140 },
    { 0x9000, 0x9080 }, { 0x8040, 0xb040 }, { 0x8000, 0xb080 }, { 0x4a40, 0xff40 },
    { 0x4040, 0xf940 }, { 0x4000, 0xf1c0 }, { 0x4180, 0xf1c0 }, { 0x1000, 0xd000 },
    { 0x0100, 0xf100 }
};

vector<KujoPLA1Extend> a1_pla = {
    { 0x2b9, 0x0880, 0xff80, 0, {}},
    { 0x0a9, 0x6100, 0xffff, 0, {}},
    { 0x089, 0x6100, 0xff00, 0, {-1 } },
    { 0x068, 0x6000, 0xf0ff, 0, {-2 } },
    { 0x308, 0x6000, 0xf000, 0, {-3, -2, -1 } },
    { 0x3e0, 0x0080, 0xf1c0, 0, {-5 } },
    { 0x3a6, 0x4e70, 0xffff, 0, {}},
    { 0x341, 0x4840, 0xfff8, 0, {}},
    { 0x230, 0x4e68, 0xfff8, 0, {}},
    { 0x3a5, 0x40c0, 0xfff8, 0, {}},
    { 0x3a2, 0x4e72, 0xffff, 0, {}},
    { 0x325, 0x48b0, 0xffb8, 0, {}},
    { 0x3a0, 0x4890, 0xffb8, 0, {}},
    { 0x1f1, 0x48a8, 0xffb8, 0, {}},
    { 0x382, 0xe020, 0xf0a0, 0, {}},
    { 0x386, 0xe0a0, 0xf0e0, 0, {}},
    { 0x381, 0xe000, 0xf0a0, 0, {}},
    { 0x385, 0xe080, 0xf0e0, 0, {}},
    { 0x1ed, 0x48b8, 0xffbf, 0, {}},
    { 0x1e5, 0x48b9, 0xffbf, 0, {}},
    { 0x384, 0x50c0, 0xf0f8, 0, {}},
    { 0x126, 0x4e75, 0xffff, 0, {}},
    { 0x12a, 0x4e73, 0xfffb, 0, {}},
    { 0x301, 0x44c0, 0xfdf8, 0, {}},
    { 0x121, 0x1000, 0xd1f0, 0, {}},
    { 0x279, 0x3040, 0xf1f0, 0, {}},
    { 0x129, 0x2000, 0xf1b0, 0, {}},
    { 0x1c1, 0x9100, 0xb1b8, 0, {}},
    { 0x1c1, 0x8000, 0xa1b0, 0, {}},
    { 0x1c9, 0x90c0, 0xb1f0, 0, {}},
    { 0x1c5, 0x91c0, 0xb1f0, 0, {}},
    { 0x1c5, 0x9180, 0xb1b8, 0, {}},
    { 0x1c5, 0x8080, 0xa1f0, 0, {}},
    { 0x100, 0xb100, 0xf1b8, 0, {}},
    { 0x10c, 0xb180, 0xf1f8, 0, {}},
    { 0x1eb, 0x1180, 0xd1f0, 0, {}},
    { 0x1ef, 0x2180, 0xf1f0, 0, {}},
    { 0x2fa, 0x1080, 0xd1f0, 0, {}},
    { 0x2f9, 0x2080, 0xf1f0, 0, {}},
    { 0x2f8, 0x1100, 0xd1f0, 0, {}},
    { 0x2fc, 0x2100, 0xf1f0, 0, {}},
    { 0x2fe, 0x10c0, 0xd1f0, 0, {}},
    { 0x2fd, 0x20c0, 0xf1f0, 0, {}},
    { 0x2da, 0x1140, 0xd1f0, 0, {}},
    { 0x2de, 0x2140, 0xf1f0, 0, {}},
    { 0x23b, 0x7000, 0xf100, 0, {}},
    { 0x1cd, 0x8100, 0xb1f8, 0, {}},
    { 0x2d9, 0x11c0, 0xdff0, 0, {}},
    { 0x2dd, 0x21c0, 0xfff0, 0, {}},
    { 0x2d8, 0x5000, 0xf0b8, 0, {}},
    { 0x2dc, 0x5048, 0xf0f8, 0, {}},
    { 0x2dc, 0x5080, 0xf0f0, 0, {}},
    { 0x1ea, 0x13c0, 0xdff0, 0, {}},
    { 0x1ee, 0x23c0, 0xfff0, 0, {}},
    { 0x3a4, 0x48a0, 0xffb8, 0, {}},
    { 0x123, 0x4c98, 0xffb8, 0, {}},
    { 0x21c, 0x0018, 0x0038, 2, {}},
    { 0x00f, 0x0018, 0x0038, 1, {}},
    { 0x1ff, 0x487b, 0xffff, 0, {}},
    { 0x1ff, 0x4870, 0xfff8, 0, {}},
    { 0x17d, 0x487a, 0xffff, 0, {}},
    { 0x17d, 0x4868, 0xfff8, 0, {}},
    { 0x17c, 0x4850, 0xfff8, 0, {}},
    { 0x103, 0x0020, 0x0038, 2, {}},
    { 0x179, 0x0020, 0x0038, 1, {}},
    { 0x178, 0x4878, 0xffff, 0, {}},
    { 0x1fa, 0x4879, 0xffff, 0, {}},
    { 0x119, 0x4e58, 0xfff8, 0, {}},
    { 0x2b9, 0x0000, 0xf180, 0, {}},
    { 0x12d, 0x4a00, 0xffb8, 0, {}},
    { 0x133, 0x4880, 0xfff8, 0, {}},
    { 0x133, 0x4000, 0xf9b8, 0, {}},
    { 0x137, 0x4080, 0xf9f8, 0, {}},
    { 0x13b, 0x4800, 0xfff8, 0, {}},
    { 0x15b, 0xc0c0, 0xf0f8, 0, {}},
    { 0x1ca, 0x0188, 0xf1f8, 0, {}},
    { 0x1ce, 0x01c8, 0xf1f8, 0, {}},
    { 0x1d2, 0x0108, 0xf1f8, 0, {}},
    { 0x1d6, 0x0148, 0xf1f8, 0, {}},
    { 0x2f5, 0x4e60, 0xfff8, 0, {}},
    { 0x1f9, 0x4cb8, 0xffbf, 0, {}},
    { 0x1e9, 0x4cb9, 0xffbf, 0, {}},
    { 0x30b, 0x4e50, 0xfff8, 0, {}},
    { 0x1fb, 0x41fb, 0xf1ff, 0, {}},
    { 0x1fb, 0x41f0, 0xf1f8, 0, {}},
    { 0x2f2, 0x41fa, 0xf1ff, 0, {}},
    { 0x2f2, 0x41e8, 0xf1f8, 0, {}},
    { 0x2f1, 0x41d0, 0xf1f8, 0, {}},
    { 0x1f5, 0x4cbb, 0xffbf, 0, {}},
    { 0x1f5, 0x4cb0, 0xffb8, 0, {}},
    { 0x127, 0x4c90, 0xffb8, 0, {}},
    { 0x1fd, 0x4cba, 0xffbf, 0, {}},
    { 0x1fd, 0x4ca8, 0xffb8, 0, {}},
    { 0x275, 0x41f8, 0xf1ff, 0, {}},
    { 0x3e4, 0x41f9, 0xf1ff, 0, {}},
    { 0x1f3, 0x4ebb, 0xffff, 0, {}},
    { 0x1f3, 0x4eb0, 0xfff8, 0, {}},
    { 0x2b0, 0x4eba, 0xffff, 0, {}},
    { 0x2b0, 0x4ea8, 0xfff8, 0, {}},
    { 0x273, 0x4e90, 0xfff8, 0, {}},
    { 0x293, 0x4eb8, 0xffff, 0, {}},
    { 0x1f2, 0x4eb9, 0xffff, 0, {}},
    { 0x1f7, 0x4efb, 0xffff, 0, {}},
    { 0x1f7, 0x4ef0, 0xfff8, 0, {}},
    { 0x2b4, 0x4efa, 0xffff, 0, {}},
    { 0x2b4, 0x4ee8, 0xfff8, 0, {}},
    { 0x255, 0x4ed0, 0xfff8, 0, {}},
    { 0x297, 0x4ef8, 0xffff, 0, {}},
    { 0x1f6, 0x4ef9, 0xffff, 0, {}},
    { 0x0ea, 0x003c, 0x003f, 2, {}},
    { 0x0a7, 0x003c, 0x003f, 1, {}},
    { 0x232, 0x48c0, 0xfff8, 0, {}},
    { 0x3e3, 0xc188, 0xf1f8, 0, {}},
    { 0x3e3, 0xc140, 0xf1f0, 0, {}},
    { 0x0a6, 0x80c0, 0xf1f8, 0, {}},
    { 0x0ae, 0x81c0, 0xf1f8, 0, {}},
    { 0x06c, 0x50c8, 0xf0f8, 0, {}},
    { 0x1d1, 0xb000, 0xf1b0, 0, {}},
    { 0x1d9, 0xb0c0, 0xf1f0, 0, {}},
    { 0x1d5, 0xb1c0, 0xf1f0, 0, {}},
    { 0x1d5, 0xb080, 0xf1f0, 0, {}},
    { 0x06f, 0xb188, 0xf1f8, 0, {}},
    { 0x06b, 0xb108, 0xf1b8, 0, {}},
    { 0x152, 0x4180, 0xf1f8, 0, {}},
    { 0x3e7, 0x0100, 0xf1f8, 0, {}},
    { 0x125, 0x4a80, 0xfff8, 0, {}},
    { 0x3ef, 0x0140, 0xf178, 0, {}},
    { 0x3eb, 0x0180, 0xf1f8, 0, {}},
    { 0x06d, 0x4e76, 0xffff, 0, {}},
    { 0x1d0, 0x4e40, 0xfff0, 0, {}},
    { 0x345, 0x4ac0, 0xfff8, 0, {}},
    { 0x363, 0x4e71, 0xffff, 0, {}},
    { 0x10f, 0x9108, 0xb1b8, 0, {}},
    { 0x10b, 0x9188, 0xb1f8, 0, {}},
    { 0x107, 0x8108, 0xb1f8, 0, {}},
    { 0x1e3, 0x003b, 0x003f, 2, {}},
    { 0x1e3, 0x0030, 0x0038, 2, {}},
    { 0x1e7, 0x003b, 0x003f, 1, {}},
    { 0x1e7, 0x0030, 0x0038, 1, {}},
    { 0x1c2, 0x003a, 0x003f, 2, {}},
    { 0x1c2, 0x0028, 0x0038, 2, {}},
    { 0x1c6, 0x003a, 0x003f, 1, {}},
    { 0x1c6, 0x0028, 0x0038, 1, {}},
    { 0x006, 0x0010, 0x0038, 2, {}},
    { 0x00b, 0x0010, 0x0038, 1, {}},
    { 0x00a, 0x0038, 0x003f, 2, {}},
    { 0x00e, 0x0038, 0x003f, 1, {}},
    { 0x1e2, 0x0039, 0x003f, 2, {}},
    { 0x1e6, 0x0039, 0x003f, 1, {}}
};

vector<KujoPLA23Extend> a23_pla = {
    { 0x15b, 0x15a, 0xc0c0, 0xf0c0, 0, {}},
    { 0x1d9, 0x1cf, 0xb0c0, 0xf1c0, 0, {}},
    { 0x1d1, 0x1d3, 0xb000, 0xf180, 0, {}},
    { 0x1d5, 0x1d7, 0xb1c0, 0xf1c0, 0, {}},
    { 0x2f8, 0x38b, 0x1100, 0xd1c0, 0, {}},
    { 0x0ae, 0x0ac, 0x81c0, 0xf1c0, 0, {}},
    { 0x0a6, 0x0a4, 0x80c0, 0xf1c0, 0, {}},
    { 0x1c5, 0x1cb, 0x91c0, 0xb1c0, 0, {}},
    { 0x2fe, 0x3af, 0x10c0, 0xd1c0, 0, {}},
    { 0x1c9, 0x1c7, 0x90c0, 0xb1c0, 0, {}},
    { 0x1c1, 0x1c3, 0x8000, 0xa180, 0, {}},
    { 0x3ff, 0x380, 0x50c0, 0xf0c0, 0, {}},
    { 0x3ff, 0x2f7, 0x5080, 0xf0c0, 0, {}},
    { 0x3ff, 0x2f3, 0x5000, 0xf080, 0, {}},
    { 0x152, 0x151, 0x4180, 0xf1c0, 0, {}},
    { 0x3ff, 0x343, 0x4ac0, 0xffc0, 0, {}},
    { 0x3ff, 0x29d, 0x8180, 0x81c0, 0, {}},
    { 0x3ff, 0x3c3, 0x4a00, 0xff80, 0, {}},
    { 0x3ff, 0x15c, 0x4800, 0xffc0, 0, {}},
    { 0x301, 0x159, 0x44c0, 0xfdc0, 0, {}},
    { 0x3ff, 0x3a1, 0x40c0, 0xffc0, 0, {}},
    { 0x1ea, 0x32b, 0x13c0, 0xdfc0, 0, {}},
    { 0x3ff, 0x2b8, 0x4000, 0xf980, 0, {}},
    { 0x1ee, 0x30f, 0x23c0, 0xffc0, 0, {}},
    { 0x2dd, 0x38c, 0x21c0, 0xffc0, 0, {}},
    { 0x1ef, 0x29c, 0x2180, 0xf1c0, 0, {}},
    { 0x2de, 0x38e, 0x2140, 0xf1c0, 0, {}},
    { 0x2fc, 0x38f, 0x2100, 0xf1c0, 0, {}},
    { 0x2fd, 0x3ad, 0x20c0, 0xf1c0, 0, {}},
    { 0x121, 0x29b, 0x1000, 0xd1c0, 0, {}},
    { 0x129, 0x29f, 0x2000, 0xf180, 0, {}},
    { 0x279, 0x158, 0x3040, 0xf1c0, 0, {}},
    { 0x2d9, 0x388, 0x11c0, 0xdfc0, 0, {}},
    { 0x1eb, 0x298, 0x1180, 0xd1c0, 0, {}},
    { 0x2da, 0x38a, 0x1140, 0xd1c0, 0, {}},
    { 0x1d5, 0x1d7, 0xb000, 0xf000, 2, {}},
    { 0x1c5, 0x1cb, 0x8000, 0xa000, 2, {}},
    { 0x2fa, 0x3ab, 0x1000, 0xd000, 2, {}},
    { 0x3ff, 0x2bc, 0x4000, 0xf800, 2, {}},
    { 0x2f9, 0x3a9, 0x2000, 0xf000, 2, {}},
    { 0x3ff, 0x3cb, 0x4a00, 0xfe00, 2, {}},
    { 0x3ff, 0x29d, 0x0000, 0x0000, 3, { 2, 3 } },
    { 0x3ff, 0x069, 0x0180, 0x01c0, 1, {}},
    { 0x3ff, 0x08f, 0x0c00, 0x0e00, 3, {}},
    { 0x3ff, 0x069, 0x0800, 0x0e00, 3, {}},
    { 0x3ff, 0x3c7, 0xe0c0, 0xf8c0, 0, {}},
    { 0x3ff, 0x299, 0x8100, 0x8180, 0, {}},
    { 0x3ff, 0x299, 0x0000, 0x0180, 1, { 1, 3, 4 } },
    { 0x3ff, 0x087, 0x0c00, 0x0f80, 1, {}},
    { 0x3ff, 0x081, 0x0140, 0x0140, 1, {}},
    { 0x3ff, 0x081, 0x0840, 0x0f40, 1, {}},
    { 0x3ff, 0x215, 0x0800, 0x0fc0, 1, {}},
    { 0x0ab, 0x215, 0x0100, 0x01c0, 1, {}},
    { 0x104, 0x3ff, 0x0c00, 0x0e38, 3, {}},
    { 0x10c, 0x3ff, 0x0000, 0x0038, 3, { -1, 1 } },
    { 0x3eb, 0x3ff, 0x0800, 0x0e38, 3, {}},
    { 0x1cc, 0x3ff, 0x003c, 0x01bf, 1, {}},
    { 0x100, 0x3ff, 0x0000, 0x01b8, 1, { 1, 2, 3 } },
    { 0x3ef, 0x3ff, 0x0840, 0x0f78, 1, {}},
    { 0x3e7, 0x3ff, 0x0800, 0x0ff8, 1, {}},
    { 0x108, 0x3ff, 0x0c00, 0x0fb8, 1, {}},
    { 0x1e2, 0x3ff, 0x0039, 0x013f, 1, { 1 } },
    { 0x1e6, 0x3ff, 0x0039, 0x003f, 3, { 14 } },
    { 0x00a, 0x3ff, 0x0038, 0x013f, 1, { 1 } },
    { 0x00e, 0x3ff, 0x0038, 0x003f, 3, { 12 } },
    { 0x1e3, 0x3ff, 0x0030, 0x0138, 1, { 2 } },
    { 0x1e3, 0x3ff, 0x083b, 0x0fff, 1, {}},
    { 0x1e7, 0x3ff, 0x0030, 0x0038, 3, { 9 } },
    { 0x1c2, 0x3ff, 0x0028, 0x0138, 1, { 2 } },
    { 0x1c2, 0x3ff, 0x083a, 0x0fff, 1, {}},
    { 0x1c6, 0x3ff, 0x0028, 0x0038, 3, { 6 } },
    { 0x103, 0x3ff, 0x0020, 0x0138, 1, { 1 } },
    { 0x179, 0x3ff, 0x0020, 0x0038, 3, { 4 } },
    { 0x21c, 0x3ff, 0x0018, 0x0138, 1, { 1 } },
    { 0x00f, 0x3ff, 0x0018, 0x0038, 3, { 2 } },
    { 0x006, 0x3ff, 0x0010, 0x0138, 1, { 2 } },
    { 0x3ff, 0x3ff, 0x0800, 0x0e00, 3, {}},
    { 0x00b, 0x3ff, 0x0010, 0x0038, 3, { -1 } }
};

bool simplePlaTest(uint16_t ir, vector<KujoPLA> pla)
{
    for (size_t i = 0; i < pla.size(); i++)
    {
	auto pla_val = pla.at(i);
	if ((ir & pla_val.mask) == pla_val.val)
	{
	    return true;
	}
    }

    return false;
}

bool a1PalTest(uint16_t ir, int line, bool a1_pl, bool a1_psw)
{
    auto pla = a1_pla.at(line);
    if ((ir & pla.mask) != pla.val)
    {
	return false;
    }

    if ((pla.line == 1) && !a1_pl)
    {
	return false;
    }

    if ((pla.line == 2) && !a1_psw)
    {
	return false;
    }

    if (!pla.lines.empty())
    {
	for (size_t i = 0; i < pla.lines.size(); i++)
	{
	    auto line_pla = pla.lines.at(i);
	    if (a1PalTest(ir, (line + line_pla), a1_pl, a1_psw))
	    {
		return false;
	    }
	}
    }

    return true;
}

bool a23PalTest(uint16_t ir, int line, bool a23_p1, bool a23_p2)
{
    auto pla = a23_pla.at(line);
    if ((ir & pla.mask) != pla.val)
    {
	return false;
    }

    if (((pla.line & 1) != 0) && !a23_p1)
    {
	return false;
    }

    if (((pla.line & 2) != 0) && !a23_p2)
    {
	return false;
    }

    if (!pla.lines.empty())
    {
	for (size_t i = 0; i < pla.lines.size(); i++)
	{
	    auto line_pla = pla.lines.at(i);
	    if (a23PalTest(ir, (line + line_pla), a23_p1, a23_p2))
	    {
		return false;
	    }
	}
    }

    return true;
}

uint16_t a1PalApply(uint16_t ir)
{
    bool a1_pl = simplePlaTest(ir, a1_pla_long);
    bool a1_psw = simplePlaTest(ir, a1_pla_byte_short);

    for (size_t i = 0; i < a1_pla.size(); i++)
    {
	if (a1PalTest(ir, i, a1_pl, a1_psw))
	{
	    return a1_pla.at(i).maddr;
	}
    }

    return 0x3FF;
}

array<uint16_t, 2> a23PalApply(uint16_t ir)
{
    bool a23_p1 = ((ir & 0xF000) == 0x0000);
    bool a23_p2 = ((ir & 0x01C0) == 0x0080);

    uint16_t r1 = 0x3FF;
    uint16_t r2 = 0x3FF;

    for (size_t i = 0; i < a23_pla.size(); i++)
    {
	if (a23PalTest(ir, i, a23_p1, a23_p2))
	{
	    r1 = (r1 & a23_pla.at(i).a2_addr);
	    r2 = (r2 & a23_pla.at(i).a3_addr);
	}
    }

    return {r1, r2};
}

bool privTest(uint16_t ir)
{
    return simplePlaTest(ir, priv_pla);
}