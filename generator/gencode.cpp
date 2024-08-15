#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <cassert>
#include <cctype>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <iterator>
#include <set>
#include <map>
#include <optional>
#include <unordered_map>
#include <algorithm>
using namespace std;

template<typename T>
bool testbit(T reg, int bit)
{
    return ((reg >> bit) & 0x1) ? true : false;
}

uint16_t toU16(string str)
{
    uint16_t val = 0;
    stringstream ss;
    ss << hex << str;
    ss >> val;
    return val;
}

string& ltrim(string &s, const char *t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

string& rtrim(string &s, const char *t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

string& trim(string &s, const char *t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

vector<string> split(string const &str, const char delim)
{
    vector<string> out;
    stringstream ss(str);

    string s;

    while (getline(ss, s, delim))
    {
	if (s.empty())
	{
	    continue;
	}

	out.push_back(s);
    }

    return out;
}

void replace(string &str, string sub, string replace)
{
    auto pos = str.find(sub);

    if (pos != string::npos)
    {
	str.replace(pos, sub.size(), replace);
    }
}

void printCode(deque<deque<string>> code)
{
    for (auto &ci : code)
    {
	cout << "[";

	for (auto iter = ci.begin(); iter != ci.end(); iter++)
	{
	    if (iter != ci.begin())
	    {
		cout << ", ";
	    }

	    auto val = *iter;
	    cout << val;
	}

	cout << "]" << endl;
    }
}

struct microcode_t {
  uint16_t val, mask;
  uint32_t code[16];
};

struct nanocode_t {
  uint16_t val, mask;
  uint32_t code[4][3];
};

const struct microcode_t microcode_entry[34] = {
    { 0x000, 0x3f0, { 0x12160, 0x10800, 0x052d0, 0x07cc0, 0x0800c, 0x0800c, 0x08480, 0x118e0, 0x08880, 0x10080, 0x10080, 0x08880, 0x01480, 0x10100, 0x10100, 0x0d300 } },
    { 0x020, 0x3f0, { 0x00004, 0x01580, 0x07060, 0x04a4a, 0x0000c, 0x161a1, 0x0000c, 0x01d00, 0x06940, 0x046a0, 0x00480, 0x10c02, 0x07d80, 0x008e0, 0x05ea0, 0x12702 } },
    { 0x040, 0x3f0, { 0x13a00, 0x00996, 0x05280, 0x161a1, 0x00004, 0x07c20, 0x12ea0, 0x08c20, 0x0af00, 0x1149a, 0x08ca1, 0x00cba, 0x098a0, 0x11497, 0x08021, 0x069c0 } },
    { 0x060, 0x3f0, { 0x00460, 0x09421, 0x169c0, 0x036a0, 0x10004, 0x169c0, 0x00004, 0x01040, 0x008e6, 0x11ca1, 0x000f2, 0x090c0, 0x010a6, 0x11437, 0x001f2, 0x091c0 } },
    { 0x080, 0x3f0, { 0x15201, 0x11041, 0x08004, 0x0987a, 0x00c40, 0x02c60, 0x03400, 0x161a1, 0x0f060, 0x03000, 0x00921, 0x00004, 0x00160, 0x00004, 0x022a0, 0x12e21 } },
    { 0x0a0, 0x3f0, { 0x00460, 0x00004, 0x0f0e0, 0x036a0, 0x05a00, 0x08cba, 0x05a00, 0x11560, 0x0ac60, 0x03180, 0x0ac60, 0x11ce1, 0x00960, 0x08cba, 0x00960, 0x115e0 } },
    { 0x0c0, 0x3f0, { 0x15201, 0x01156, 0x03ea0, 0x0db80, 0x00004, 0x17c20, 0x008e0, 0x11941, 0x00c40, 0x01c12, 0x04a16, 0x05a20, 0x000e0, 0x011e0, 0x04a1a, 0x069c0 } },
    { 0x0e0, 0x3f0, { 0x00422, 0x01580, 0x00004, 0x05a80, 0x0a280, 0x08dc0, 0x00004, 0x000b2, 0x06940, 0x046a0, 0x10008, 0x0d680, 0x07d80, 0x008e0, 0x12a00, 0x0fca0 } },
    { 0x100, 0x3f0, { 0x11941, 0x10502, 0x08540, 0x03f20, 0x14f01, 0x12582, 0x0e9c0, 0x02e80, 0x15701, 0x12502, 0x0e120, 0x00120, 0x14b21, 0x10582, 0x09540, 0x02e00 } },
    { 0x120, 0x3f0, { 0x01500, 0x15721, 0x0a621, 0x12a80, 0x00180, 0x17421, 0x0b280, 0x12a00, 0x05b60, 0x14721, 0x0bd00, 0x0e8e0, 0x057c0, 0x161a1, 0x0aaa1, 0x00000 } },
    { 0x110, 0x3f0, { 0x02216, 0x0e53a, 0x16880, 0x069c0, 0x08486, 0x0e5bb, 0x0f800, 0x05a20, 0x05251, 0x0b7e0, 0x0dec0, 0x04700, 0x07c30, 0x00000, 0x15ec0, 0x00000 } },
    { 0x130, 0x3f0, { 0x07100, 0x0b600, 0x01120, 0x11941, 0x04300, 0x0b680, 0x011a0, 0x133a1, 0x00cba, 0x0b700, 0x001a0, 0x13a81, 0x00000, 0x00000, 0x00000, 0x00000 } },
    { 0x150, 0x3f0, { 0x161a1, 0x03a20, 0x03a20, 0x0222e, 0x0b580, 0x0b2a0, 0x13aa0, 0x00004, 0x161a1, 0x06c00, 0x160e1, 0x160e1, 0x13a01, 0x0e9c0, 0x05b20, 0x13100 } },
    { 0x170, 0x3f0, { 0x10004, 0x00004, 0x009c0, 0x009c0, 0x009c0, 0x018aa, 0x01016, 0x05280, 0x13100, 0x03720, 0x08880, 0x0800c, 0x13081, 0x137a0, 0x13fa1, 0x03080 } },
    { 0x1c0, 0x3f0, { 0x07c40, 0x15721, 0x11500, 0x15721, 0x04680, 0x16061, 0x10180, 0x16161, 0x00000, 0x16161, 0x16da0, 0x143a1, 0x07880, 0x13b01, 0x17d20, 0x126a1 } },
    { 0x1e0, 0x3f0, { 0x01500, 0x17c20, 0x10900, 0x07460, 0x00180, 0x13200, 0x10980, 0x074e0, 0x05b60, 0x11dc0, 0x15f40, 0x02900, 0x057c0, 0x16860, 0x15fc0, 0x02880 } },
    { 0x1d0, 0x3f0, { 0x078a0, 0x15701, 0x15340, 0x15701, 0x00000, 0x13e21, 0x153c0, 0x13621, 0x00000, 0x126a1, 0x00000, 0x00000, 0x00000, 0x00000, 0x00000, 0x00000 } },
    { 0x1f0, 0x3f0, { 0x07100, 0x16960, 0x152a0, 0x05640, 0x04300, 0x11c80, 0x15e40, 0x056c0, 0x00cba, 0x17180, 0x13ba0, 0x07560, 0x00000, 0x156e0, 0x0c7a1, 0x075e0 } },
    { 0x210, 0x3f0, { 0x04a00, 0x00816, 0x00004, 0x01c0e, 0x04200, 0x161a1, 0x04aca, 0x07060, 0x04b01, 0x13080, 0x0db00, 0x0000c, 0x0cb80, 0x0000c, 0x0187a, 0x0987a } },
    { 0x230, 0x3f0, { 0x15e01, 0x009c0, 0x15e01, 0x00004, 0x04e80, 0x01d60, 0x1a300, 0x0653a, 0x00004, 0x009c0, 0x00004, 0x161a1, 0x0cf81, 0x10004, 0x0f920, 0x0c321 } },
    { 0x250, 0x3f0, { 0x00060, 0x114a1, 0x06d06, 0x00004, 0x04200, 0x17c20, 0x14e20, 0x07080, 0x10004, 0x05320, 0x05b20, 0x00004, 0x04ba0, 0x00004, 0x04ba0, 0x04ba0 } },
    { 0x270, 0x3f0, { 0x14e20, 0x0d620, 0x0fc21, 0x14e20, 0x14e40, 0x17c20, 0x05e80, 0x0653a, 0x00004, 0x14721, 0x00004, 0x004e1, 0x14fa0, 0x00004, 0x05fa0, 0x05f60 } },
    { 0x290, 0x3f0, { 0x04a40, 0x05216, 0x06420, 0x04620, 0x04ac0, 0x052e0, 0x057b0, 0x05e40, 0x02800, 0x169c1, 0x0e520, 0x161a1, 0x02980, 0x169a1, 0x0f1a0, 0x17da1 } },
    { 0x2b0, 0x3f0, { 0x046a0, 0x04e20, 0x00d02, 0x17c20, 0x008e0, 0x06180, 0x00d82, 0x12380, 0x169c1, 0x10008, 0x0e120, 0x16940, 0x12ba1, 0x17c20, 0x0dbe0, 0x15740 } },
    { 0x2d0, 0x3f0, { 0x05216, 0x114e1, 0x04206, 0x05a06, 0x052e0, 0x114e1, 0x06dc6, 0x05a86, 0x11941, 0x16940, 0x15b60, 0x0fc21, 0x14b21, 0x15740, 0x157c0, 0x0c321 } },
    { 0x2f0, 0x3f0, { 0x0653a, 0x114a1, 0x16900, 0x169c1, 0x0e5ba, 0x114a1, 0x156a0, 0x169a1, 0x17921, 0x0df80, 0x08c81, 0x15fe0, 0x15781, 0x0c780, 0x0e921, 0x16000 } },
    { 0x300, 0x3f0, { 0x13380, 0x06c00, 0x05e40, 0x17c20, 0x069c0, 0x11920, 0x00004, 0x06400, 0x008a6, 0x07c20, 0x07c20, 0x14ec0, 0x0e981, 0x0e920, 0x12a00, 0x16d00 } },
    { 0x320, 0x3f0, { 0x06c00, 0x02c60, 0x00cba, 0x00cba, 0x069c0, 0x17480, 0x01d80, 0x00004, 0x161a1, 0x0f500, 0x0ac61, 0x17580, 0x161a0, 0x0428a, 0x0ac61, 0x0e120 } },
    { 0x340, 0x3f0, { 0x009c0, 0x17021, 0x00004, 0x060a0, 0x0fc20, 0x170a1, 0x00004, 0x07060, 0x0fc20, 0x10004, 0x0f920, 0x08004, 0x00004, 0x0e9c0, 0x0f9a0, 0x0e520 } },
    { 0x360, 0x3f0, { 0x09de0, 0x00004, 0x00004, 0x161a1, 0x00000, 0x00000, 0x00000, 0x0b300, 0x0f521, 0x0004a, 0x10004, 0x0e5a0, 0x0eda0, 0x0f5a1, 0x0fc20, 0x00004 } },
    { 0x380, 0x3f0, { 0x119a7, 0x17841, 0x17841, 0x05a06, 0x11967, 0x178c1, 0x178c1, 0x05a86, 0x16940, 0x0fc20, 0x16940, 0x17921, 0x17d80, 0x08004, 0x17d80, 0x17121 } },
    { 0x3a0, 0x3f0, { 0x17c00, 0x16481, 0x07c81, 0x07060, 0x15380, 0x16021, 0x05f20, 0x07170, 0x0653a, 0x0f540, 0x08c81, 0x08c80, 0x0e5ba, 0x0f5c0, 0x0e921, 0x0e921 } },
    { 0x3c0, 0x3f0, { 0x053a0, 0x11920, 0x0e420, 0x161a1, 0x0041e, 0x0f000, 0x08140, 0x16081, 0x05ba0, 0x17400, 0x09440, 0x16c21, 0x00000, 0x00000, 0x00000, 0x00000 } },
    { 0x3e0, 0x3f0, { 0x14f40, 0x00000, 0x12402, 0x14e01, 0x14fc0, 0x00000, 0x12482, 0x11ce1, 0x04660, 0x0424a, 0x12602, 0x115a1, 0x0c6e0, 0x042ca, 0x12682, 0x11521 } },
};

const struct nanocode_t nanocode_entry[84] = {
    { 0x000, 0x3fc, { { 0x0, 0x00010000, 0x00000000 }, { 0x0, 0x00010000, 0x00000000 }, { 0x0, 0x00010000, 0x00000000 }, { 0x8, 0x25000398, 0x10000000 } } },
    { 0x020, 0x3fc, { { 0x8, 0x532200e5, 0x08418425 }, { 0x0, 0x008c400a, 0x01000002 }, { 0x0, 0x20062f89, 0x4c018084 }, { 0xc, 0x08280211, 0x00018044 } } },
    { 0x004, 0x3fc, { { 0x9, 0x26020058, 0x12218084 }, { 0x9, 0x24024018, 0x10140180 }, { 0x0, 0xa1010028, 0x02218004 }, { 0x8, 0xa0020088, 0x10000083 } } },
    { 0x024, 0x3fc, { { 0x0, 0x08010000, 0x62000680 }, { 0x8, 0xa0020008, 0x10000000 }, { 0x9, 0x240a4018, 0x10140180 }, { 0x0, 0x00010000, 0x00210014 } } },
    { 0x008, 0x3f8, { { 0x0, 0x80028000, 0x00218084 }, { 0x1, 0x8b00c022, 0x60100682 }, { 0x1, 0x8980c022, 0x60100682 }, { 0x0, 0xa0020008, 0x00218084 } } },
    { 0x028, 0x3f8, { { 0x0, 0x008c400a, 0x01218046 }, { 0x0, 0x004c8001, 0x49000000 }, { 0x9, 0x240a4018, 0x12218004 }, { 0x1, 0xa04c0009, 0x00400000 } } },
    { 0x040, 0x3fc, { { 0x8, 0xa0010008, 0x10120048 }, { 0x0, 0x01110060, 0x00038044 }, { 0x0, 0x00010062, 0x00020048 }, { 0x8, 0xb6022059, 0x98000000 } } },
    { 0x060, 0x3fc, { { 0x0, 0x00010000, 0x0082002c }, { 0x1, 0x80800002, 0x00104800 }, { 0x5, 0x0b000060, 0x441200ae }, { 0xc, 0x08280211, 0x00858044 } } },
    { 0x044, 0x3fc, { { 0x0, 0x08212081, 0x00000345 }, { 0x8, 0x20020088, 0x10000001 }, { 0x9, 0x24024018, 0x58098004 }, { 0x0, 0xc102a024, 0x085000c8 } } },
    { 0x064, 0x3fc, { { 0x8, 0xa0020088, 0x10000083 }, { 0x5, 0x0b000060, 0x441200ca }, { 0x8, 0x360200d9, 0x90000083 }, { 0x8, 0x40028004, 0x10400392 } } },
    { 0x048, 0x3f8, { { 0x0, 0x80068000, 0x00280080 }, { 0x8, 0xa0020019, 0x10418044 }, { 0x0, 0xc101a024, 0x0a140080 }, { 0x0, 0x0300c560, 0x00000082 } } },
    { 0x068, 0x3f8, { { 0x4, 0x088c0002, 0x44100000 }, { 0x1, 0x80010380, 0x00280308 }, { 0x8, 0x20020009, 0x5808038a }, { 0x0, 0xa008c008, 0x02000000 } } },
    { 0x080, 0x3fc, { { 0x8, 0xb0220058, 0x10498010 }, { 0x8, 0xc0028004, 0x1028038a }, { 0x0, 0x830100e0, 0x02024b45 }, { 0x0, 0x81068521, 0x40000800 } } },
    { 0x0a0, 0x3fc, { { 0x0, 0x00010000, 0x00820028 }, { 0x0, 0x10212081, 0x00420345 }, { 0x4, 0x88228481, 0x0001c804 }, { 0xc, 0x08280211, 0x00018044 } } },
    { 0x084, 0x3f4, { { 0x0, 0x08212001, 0x00080308 }, { 0x8, 0x20020088, 0x10000001 }, { 0x0, 0x41028024, 0x02000080 }, { 0x8, 0xc0028005, 0x50100048 } } },
    { 0x0a4, 0x3f4, { { 0x0, 0x0421c009, 0x08298144 }, { 0x0, 0x80028501, 0x40000800 }, { 0x0, 0x0421c009, 0x48098144 }, { 0x0, 0x9022a001, 0x00200080 } } },
    { 0x088, 0x3fc, { { 0x4, 0x960685d1, 0x8401c805 }, { 0x4, 0x2c042019, 0x4c018004 }, { 0x0, 0x00010000, 0x00030048 }, { 0x8, 0x20020089, 0xb8400083 } } },
    { 0x0a8, 0x3fc, { { 0x5, 0x888c0200, 0x44004800 }, { 0x0, 0x24046019, 0x08018004 }, { 0x5, 0x888c0002, 0x44104800 }, { 0x1, 0xcb01c000, 0x60000600 } } },
    { 0x0c0, 0x3fc, { { 0x8, 0xa0020008, 0x10498018 }, { 0x0, 0x01110060, 0x00038044 }, { 0x0, 0x08210001, 0x0081010c }, { 0x0, 0x81068021, 0x40000800 } } },
    { 0x0e0, 0x3fc, { { 0xc, 0x000e8050, 0x84418030 }, { 0x0, 0x200c400a, 0x01000002 }, { 0x8, 0x40028084, 0x10000083 }, { 0x8, 0x20060388, 0x10000000 } } },
    { 0x0c4, 0x3fc, { { 0x0, 0x00010081, 0x88420345 }, { 0x0, 0x80028000, 0x00000082 }, { 0x8, 0x20020088, 0x10000001 }, { 0x8, 0xc0028004, 0x10000000 } } },
    { 0x0e4, 0x3fc, { { 0x0, 0x00068000, 0x00000000 }, { 0x0, 0x88228001, 0x00000800 }, { 0x0, 0x00010080, 0x000000d7 }, { 0x8, 0x20020009, 0x58098086 } } },
    { 0x0c8, 0x3f8, { { 0x0, 0x00010000, 0x00400310 }, { 0x0, 0x00010000, 0x00030048 }, { 0x0, 0x06210023, 0x00850008 }, { 0x0, 0x03000060, 0x0041808a } } },
    { 0x0e8, 0x3f8, { { 0x0, 0x200c400a, 0x01218046 }, { 0x0, 0x080ca001, 0x49000000 }, { 0x8, 0xc4228005, 0x98200082 }, { 0x0, 0x84448410, 0x0003c804 } } },
    { 0x100, 0x3f0, { { 0x1, 0x8001c00b, 0x40000048 }, { 0x1, 0xa04ce009, 0x08400000 }, { 0x0, 0xc622a007, 0x08000800 }, { 0x0, 0x280ec008, 0x60140600 } } },
    { 0x120, 0x3f0, { { 0x0, 0x008c450a, 0x01000082 }, { 0x8, 0xcc02a015, 0x58018044 }, { 0x0, 0xa0082008, 0x0a218084 }, { 0x0, 0x80028601, 0x00200082 } } },
    { 0x110, 0x3f0, { { 0x0, 0x00010000, 0x00000000 }, { 0x0, 0xa102c52a, 0x00000080 }, { 0x0, 0x84228001, 0x00200080 }, { 0x0, 0x03000060, 0x004080ae } } },
    { 0x130, 0x3f0, { { 0x0, 0x008c450a, 0x01000082 }, { 0x1, 0x10016000, 0x8a218004 }, { 0x0, 0x200e2008, 0x0a000080 }, { 0x8, 0xc0028005, 0x58010048 } } },
    { 0x150, 0x3fc, { { 0x8, 0xc0028004, 0x10000000 }, { 0x0, 0x00068000, 0x40180048 }, { 0x0, 0x00068008, 0x40080048 }, { 0x8, 0x40028004, 0x10038044 } } },
    { 0x170, 0x3fc, { { 0x8, 0xb0024088, 0x905000cb }, { 0x0, 0x08210081, 0x000004af }, { 0x0, 0x20112002, 0x000200ae }, { 0x0, 0x28312003, 0x000000ae } } },
    { 0x154, 0x3fc, { { 0x1, 0x46018054, 0x00280080 }, { 0x0, 0x80028000, 0x00100180 }, { 0x8, 0xb0024008, 0x90500048 }, { 0x0, 0x00010080, 0x000204af } } },
    { 0x174, 0x3fc, { { 0x0, 0x26312003, 0x000000ae }, { 0x0, 0x0302c060, 0x0003800e }, { 0x0, 0x00010001, 0x40010008 }, { 0x0, 0x00010022, 0x00820048 } } },
    { 0x158, 0x3fc, { { 0x8, 0xd0428005, 0x90200000 }, { 0x0, 0x00068601, 0x00200000 }, { 0x1, 0x04004210, 0x40190144 }, { 0x1, 0x04004218, 0x40090144 } } },
    { 0x178, 0x3fc, { { 0x1, 0xa444e019, 0x08200002 }, { 0x0, 0x20040008, 0x00218004 }, { 0x0, 0xc0028004, 0x00000080 }, { 0x9, 0x34006018, 0x9a038084 } } },
    { 0x15c, 0x3fc, { { 0x1, 0x8001c000, 0x00210048 }, { 0x0, 0x83060060, 0x0003482c }, { 0x0, 0x08212007, 0x008100ae }, { 0x1, 0xa004e019, 0x08200002 } } },
    { 0x17c, 0x3fc, { { 0x1, 0xac04e019, 0x48018086 }, { 0x0, 0x8c02a010, 0x48218086 }, { 0x1, 0x868cc052, 0x00800000 }, { 0x0, 0x24046019, 0x08018086 } } },
    { 0x1c0, 0x3e0, { { 0x8, 0x20060388, 0x10000000 }, { 0x1, 0x8441c01b, 0x48000048 }, { 0x1, 0x888c2002, 0x48100082 }, { 0x1, 0x8441c01b, 0x08200048 } } },
    { 0x1e0, 0x3e0, { { 0x0, 0x200c450a, 0x01000082 }, { 0x8, 0xc0028605, 0x10200082 }, { 0x0, 0x84228001, 0x00200080 }, { 0x0, 0x00010000, 0x00210014 } } },
    { 0x210, 0x3fc, { { 0x0, 0x06210001, 0x00018044 }, { 0x0, 0x08210001, 0x00058444 }, { 0x0, 0x00010086, 0x080204cb }, { 0x0, 0x20112002, 0x00020048 } } },
    { 0x230, 0x3fc, { { 0x1, 0xac00c01b, 0x40000600 }, { 0x0, 0x53014067, 0x80000082 }, { 0x1, 0x8441c011, 0x4801804c }, { 0x8, 0x360220d9, 0x98000083 } } },
    { 0x214, 0x3fc, { { 0xc, 0x000e8000, 0x00418010 }, { 0x8, 0xc0028004, 0x10200344 }, { 0x0, 0x00010051, 0x00018044 }, { 0x4, 0x30066f89, 0x8c018004 } } },
    { 0x234, 0x3fc, { { 0x4, 0x10014303, 0x84058004 }, { 0x0, 0x20062a88, 0x08000000 }, { 0x1, 0x06010050, 0x00000002 }, { 0x0, 0x8302c560, 0x00000080 } } },
    { 0x218, 0x3fc, { { 0x8, 0x240a4019, 0x10018004 }, { 0x1, 0xa004e008, 0x08000082 }, { 0x0, 0x81028020, 0x00140100 }, { 0x8, 0x30026008, 0x98000080 } } },
    { 0x238, 0x3fc, { { 0x8, 0x20020089, 0xb0400001 }, { 0x0, 0x28310003, 0x000000ae }, { 0x8, 0x20020088, 0x10000083 }, { 0x8, 0xd0428405, 0x90018044 } } },
    { 0x21c, 0x3fc, { { 0x0, 0xa9080028, 0x62140600 }, { 0x8, 0x30026008, 0x9a038084 }, { 0x0, 0x2106c528, 0x00000002 }, { 0x0, 0x89268521, 0x00000800 } } },
    { 0x23c, 0x3fc, { { 0x0, 0x80028001, 0x48018844 }, { 0x8, 0xb0024088, 0x900380a7 }, { 0x0, 0x8826a001, 0x0001c824 }, { 0x9, 0xa0000009, 0x58018844 } } },
    { 0x250, 0x3fc, { { 0x0, 0x10210001, 0x00410004 }, { 0x8, 0xa4220009, 0x10438044 }, { 0x0, 0x00010022, 0x00820048 }, { 0x8, 0x20020088, 0xb8400001 } } },
    { 0x270, 0x3fc, { { 0x1, 0x2604e058, 0x08000002 }, { 0x4, 0xc822a007, 0x08000800 }, { 0x1, 0x83020061, 0x44000800 }, { 0x1, 0x2c042018, 0x48000002 } } },
    { 0x254, 0x3fc, { { 0x0, 0x00010011, 0x00418018 }, { 0x0, 0xa0020008, 0x00000002 }, { 0x1, 0x2604e019, 0x08200002 }, { 0x0, 0x40110002, 0x88440400 } } },
    { 0x274, 0x3fc, { { 0x9, 0x24024018, 0x10000000 }, { 0x0, 0x90428001, 0x80200002 }, { 0x8, 0x240a4018, 0x10000002 }, { 0x0, 0x0302c560, 0x00000080 } } },
    { 0x258, 0x3fc, { { 0x8, 0xc0028084, 0x100380a7 }, { 0x0, 0x00010001, 0x88400082 }, { 0x0, 0x28310003, 0x0000002c }, { 0x8, 0x30222089, 0x10400001 } } },
    { 0x278, 0x3fc, { { 0x0, 0x4b2120e7, 0x080180a7 }, { 0x8, 0xc4428015, 0x58000000 }, { 0x8, 0x20020089, 0xb0400083 }, { 0x0, 0x00860002, 0x00800000 } } },
    { 0x25c, 0x3fc, { { 0x0, 0x20112003, 0x804200ae }, { 0x8, 0x30220089, 0x10400001 }, { 0x0, 0x28312003, 0x0000002c }, { 0x0, 0x26312003, 0x0000002c } } },
    { 0x27c, 0x3fc, { { 0x8, 0xb0024009, 0x90000000 }, { 0x0, 0x16012081, 0x88200083 }, { 0x0, 0x00010680, 0x00000000 }, { 0x0, 0x00800300, 0x00000000 } } },
    { 0x290, 0x3f8, { { 0x0, 0x00010051, 0x00018044 }, { 0xc, 0x000e8000, 0x00418010 }, { 0x0, 0x00010080, 0x00000001 }, { 0x0, 0x04410011, 0x00200000 } } },
    { 0x2b0, 0x3f8, { { 0x0, 0x088c2002, 0x48100000 }, { 0x0, 0x2004e008, 0x08000002 }, { 0x0, 0x088c2002, 0x48800000 }, { 0x0, 0x83020002, 0x00100002 } } },
    { 0x298, 0x3f8, { { 0x0, 0x00010000, 0x00410014 }, { 0x1, 0x8300c061, 0x401000ca }, { 0x0, 0x80028000, 0x02001080 }, { 0x8, 0xc0028005, 0xb0218044 } } },
    { 0x2b8, 0x3f8, { { 0x1, 0x8300c060, 0x002100ca }, { 0x8, 0xc0028005, 0x90200082 }, { 0x0, 0x8822a001, 0x00098824 }, { 0x1, 0x8300c013, 0x48118046 } } },
    { 0x2d0, 0x3f8, { { 0xc, 0x000e8000, 0x00418018 }, { 0x8, 0xa0020008, 0x10000000 }, { 0x0, 0x00010022, 0x00820048 }, { 0xc, 0x000e8000, 0x00418050 } } },
    { 0x2f0, 0x3f8, { { 0x0, 0x81028521, 0x80200080 }, { 0x1, 0xa101c629, 0x00200000 }, { 0x1, 0x888c2002, 0x48100000 }, { 0x1, 0x9340c461, 0x801000ca } } },
    { 0x2d8, 0x3f8, { { 0x1, 0x9041c40b, 0x80000048 }, { 0x1, 0x8080c013, 0x48118046 }, { 0x1, 0x888cc002, 0x40100002 }, { 0x9, 0xa0020009, 0x5a018844 } } },
    { 0x2f8, 0x3f8, { { 0x1, 0xa00ee009, 0x480180c6 }, { 0x0, 0xa822e009, 0x08080800 }, { 0x0, 0xa008e009, 0x4a018844 }, { 0x0, 0x90228801, 0x00200080 } } },
    { 0x300, 0x3fc, { { 0x0, 0x80028f01, 0x80200080 }, { 0x0, 0x0806a601, 0x48000000 }, { 0x0, 0x4421a107, 0x082000e0 }, { 0x0, 0x93024003, 0x80100002 } } },
    { 0x320, 0x3fc, { { 0x0, 0x00028601, 0x00400000 }, { 0x0, 0x00010100, 0x00000060 }, { 0x0, 0x204cc509, 0x00200002 }, { 0x0, 0x2000c508, 0x00000002 } } },
    { 0x304, 0x3fc, { { 0x0, 0x03000060, 0x004180d2 }, { 0x0, 0x80028011, 0x00200000 }, { 0x8, 0x20020088, 0x10038025 }, { 0x0, 0x00010409, 0x08000008 } } },
    { 0x324, 0x3fc, { { 0x0, 0x03000461, 0x00018086 }, { 0x0, 0x800a8601, 0x00200082 }, { 0x8, 0x40068015, 0x10210014 }, { 0x8, 0x40068104, 0x10000061 } } },
    { 0x308, 0x3fc, { { 0x8, 0x204c0408, 0x10000000 }, { 0x8, 0x300a4009, 0x90000002 }, { 0x8, 0x300a4009, 0x90000000 }, { 0x0, 0x8c02a011, 0x48018004 } } },
    { 0x328, 0x3fc, { { 0x8, 0xa0020008, 0x10000000 }, { 0x0, 0x83020053, 0x0011c844 }, { 0x9, 0xa0020008, 0x1003c824 }, { 0x1, 0x8111c002, 0x00a180c4 } } },
    { 0x30c, 0x3fc, { { 0x0, 0xc6228005, 0x00000800 }, { 0x1, 0x888c2002, 0x48104800 }, { 0x0, 0x9042a001, 0x88200002 }, { 0x1, 0x8111c013, 0x00a38084 } } },
    { 0x32c, 0x3fc, { { 0x8, 0xb6022059, 0x98000000 }, { 0x0, 0x00010000, 0x00000000 }, { 0x9, 0x26020009, 0x12204800 }, { 0x0, 0x80028011, 0x0043c424 } } },
    { 0x340, 0x3fc, { { 0x0, 0x00010401, 0x88000082 }, { 0x1, 0x8931e00b, 0x00058044 }, { 0x0, 0x1602a084, 0x008380a7 }, { 0x0, 0x0300c461, 0x00100008 } } },
    { 0x360, 0x3fc, { { 0x4, 0xc822ae85, 0x0801c804 }, { 0x0, 0x00010080, 0x000380a7 }, { 0x0, 0x08212081, 0x000180a7 }, { 0x8, 0xc0028004, 0x10000000 } } },
    { 0x344, 0x3fc, { { 0x9, 0xa0000008, 0x1221c844 }, { 0x1, 0x8001c409, 0x00040008 }, { 0x0, 0x00028081, 0xa84380c7 }, { 0x0, 0x20062f89, 0x4c018004 } } },
    { 0x364, 0x3fc, { { 0x0, 0x00010000, 0x00000000 }, { 0x0, 0x00010000, 0x00000000 }, { 0x0, 0x00010000, 0x00000000 }, { 0x8, 0xc3020064, 0x10000080 } } },
    { 0x348, 0x3fc, { { 0x9, 0xa00200d9, 0x10000801 }, { 0x8, 0xb0024088, 0x90000083 }, { 0x0, 0x80068000, 0x0003c824 }, { 0x9, 0x30024088, 0x92004801 } } },
    { 0x368, 0x3fc, { { 0x9, 0xa00a0008, 0x12002080 }, { 0x0, 0x10210001, 0x00410004 }, { 0x8, 0xc0028084, 0x90200083 }, { 0x0, 0x88228001, 0x02001800 } } },
    { 0x34c, 0x3fc, { { 0x0, 0x00010080, 0x00000083 }, { 0x0, 0x88268001, 0x00004c2c }, { 0x0, 0x80028000, 0x02002080 }, { 0x0, 0x90228001, 0x02201080 } } },
    { 0x36c, 0x3fc, { { 0x0, 0x88228001, 0x02002800 }, { 0x0, 0x80028008, 0x0a005000 }, { 0x9, 0xa00a0008, 0x52002800 }, { 0x0, 0x40112082, 0x000384a7 } } },
    { 0x380, 0x3f8, { { 0x8, 0xc0018004, 0x10010004 }, { 0x1, 0x88a0e201, 0x00018004 }, { 0x1, 0x88a0e00b, 0x08018004 }, { 0xc, 0x000e8000, 0x488181c6 } } },
    { 0x3a0, 0x3f8, { { 0x0, 0x80028601, 0x00200000 }, { 0x1, 0x8001c380, 0x00000000 }, { 0x8, 0x40028605, 0x10210005 }, { 0x4, 0x30066f09, 0x8c018004 } } },
    { 0x388, 0x3f8, { { 0x1, 0x8080c002, 0x00a18046 }, { 0x9, 0xa0020088, 0x12004801 }, { 0x1, 0x888cc002, 0x40a18046 }, { 0x1, 0xa00ee008, 0x082180c6 } } },
    { 0x3a8, 0x3f8, { { 0x0, 0x91428521, 0x80200080 }, { 0x0, 0xa002e008, 0x0821c444 }, { 0x0, 0x80028000, 0x0003c824 }, { 0x0, 0xa008e008, 0x0a218844 } } },
    { 0x3c0, 0x3f0, { { 0x0, 0x00010006, 0x08800082 }, { 0x0, 0x84428011, 0x00200000 }, { 0x0, 0x80048401, 0x0001c804 }, { 0x8, 0xc0028004, 0x10218044 } } },
    { 0x3e0, 0x3f0, { { 0x0, 0x90228001, 0x00200080 }, { 0x0, 0x00010000, 0x00000000 }, { 0x1, 0xa04c0009, 0x00400000 }, { 0x1, 0xac00c01b, 0x40000600 } } },
};

#include "instr_names.inl"

string labelName(uint16_t maddr)
{
    return microcode_instruction_names.at(maddr);
}

vector<uint32_t> microcode_table;
vector<array<uint32_t, 3>> nanocode_table;

struct IrDecoded
{
    bool is_pc_rel;
    bool is_tas;
    bool implicit_sp;
    bool to_ccr;
    bool rx_is_dt;
    bool ry_is_dt;
    bool rx_is_usp;
    bool rx_is_movem;
    bool movem_pre_decr;
    bool is_byte;
    bool is_movep;
    int rx;
    int ry;
    bool rx_is_areg;
    bool ry_is_areg;
    uint16_t ftu_const;
    int macro_tvn;
    bool inhibit_ccr;
    int alu_row;
    bool no_ccr_en;
    bool is_ar_x;
    bool is_long;
    bool is_mul_signed;
};

struct NanoDecoded
{
    bool perm_start;
    bool wait_bus_finish;
    bool is_write;
    bool bus_byte;
    bool is_rmc;
    bool no_low_byte;
    bool no_high_byte;
    bool upd_tp_end;
    bool clr_tp_end;
    bool tvn_2_ftu;
    bool const_2_ftu;
    bool ftu_2_dbl;
    bool ftu_2_abl;
    bool abl_2_pren;
    bool upd_pren;
    bool inl_2_psw;
    bool ftu_2_sr;
    bool sr_2_ftu;
    bool ftu_2_ccr;
    bool psw_i_2_ftu;
    bool ird_2_ftu;
    bool ssw_2_ftu;
    bool init_st;
    bool ir_2_ird;
    bool au_clk_en;
    bool no_sp_align;
    int au_ctrl;
    bool to_dbin;
    bool to_irc;
    bool dbl_2_atl;
    bool abl_2_atl;
    bool atl_2_abl;
    bool atl_2_dbl;
    bool abh_2_ath;
    bool dbh_2_ath;
    bool ath_2_dbh;
    bool ath_2_abh;
    bool db_2_aob;
    bool ab_2_aob;
    bool au_2_aob;
    bool aob_2_ab;
    bool upd_ssw;
    int dob_ctrl;
    bool abh_2_reg;
    bool abl_2_reg;
    bool reg_2_abl;
    bool reg_2_abh;
    bool dbh_2_reg;
    bool dbl_2_reg;
    bool reg_2_dbl;
    bool reg_2_dbh;
    bool ssp;
    bool pch_dbh;
    bool pcl_dbl;
    bool pcl_abl;
    bool pch_abh;
    bool rxh_2_dbh;
    bool rxh_2_abh;
    bool dbl_2_rxl;
    bool dbh_2_rxh;
    bool rxl_2_db;
    bool rxl_2_ab;
    bool abl_2_rxl;
    bool abh_2_rxh;
    bool dbh_2_ryh;
    bool abh_2_ryh;
    bool ryl_2_db;
    bool ryl_2_ab;
    bool ryh_2_dbh;
    bool ryh_2_abh;
    bool dbl_2_ryl;
    bool abl_2_ryl;
    bool rz;
    bool rxl_dbl;
    int alu_column;
    int alu_dctrl;
    bool alu_actrl;
    bool alu_init;
    bool alu_finish;
    bool abd_2_dcr;
    bool dcr_2_dbd;
    bool dbd_2_alue;
    bool alue_2_dbd;
    bool dbd_2_alub;
    bool abd_2_alub;
    bool alu_2_dbd;
    bool alu_2_abd;
    bool au_2_db;
    bool au_2_ab;
    bool au_2_pc;
    bool dbin_2_abd;
    bool dbin_2_dbd;
    bool ext_dbh;
    bool ext_abh;
    bool abl_abd;
    bool abl_abh;
    bool dbl_dbd;
    bool dbl_dbh;
    bool adb_is_byte;
};

uint32_t nanox(array<uint32_t, 3> nano, int start, int count = 1)
{
    uint32_t res = 0;

    for (int i = 0; i < count; i++)
    {
	int bit = (start + i);

	uint32_t base = 0;

	if (bit >= 64)
	{
	    base = nano[0];
	}
	else if (bit >= 32)
	{
	    base = nano[1];
	}
	else
	{
	    base = nano[2];
	}

	int final_bit = (bit & 0x1F);

	if ((base & (1 << final_bit)) != 0)
	{
	    res |= (1 << i);
	}
    }

    return res;
}

int getBits(uint16_t ir, int start, int count = 1)
{
    int bits = 0;
    for (int i = 0; i < count; i++)
    {
	int bit = (start + i);

	if (testbit(ir, bit))
	{
	    bits |= (1 << i);
	}
    }

    return bits;
}

IrDecoded decodeIR(uint16_t ir)
{
    IrDecoded decoded;

    int line = ((ir >> 12) & 0xF);

    bool is_reg_shift = ((line == 14) && (getBits(ir, 6, 2) != 3));
    bool is_dyn_shift = (is_reg_shift && testbit(ir, 5));

    decoded.is_pc_rel = ((getBits(ir, 3, 3) == 7) && !is_dyn_shift && !testbit(ir, 2) && testbit(ir, 1));
    decoded.is_tas = ((line == 4) && (getBits(ir, 6, 6) == 0b101011));
    decoded.rx = getBits(ir, 9, 3);
    decoded.ry = getBits(ir, 0, 3);

    bool is_pre_decr = (getBits(ir, 3, 3) == 0b100);
    bool ea_areg = (getBits(ir, 3, 3) == 0b001);

    switch (line)
    {
	case 0x6: decoded.implicit_sp = (getBits(ir, 8, 4) == 0b0001); break;
	case 0x4: decoded.implicit_sp = ((getBits(ir, 8, 4) == 0b1110) || (getBits(ir, 6, 6) == 0b100001)); break;
	default: decoded.implicit_sp = false; break;
    }

    decoded.rx_is_movem = (line == 4) && !testbit(ir, 8) && !decoded.implicit_sp;

    decoded.movem_pre_decr = (decoded.rx_is_movem && is_pre_decr);

    decoded.rx_is_dt = ((line == 5) || ((line == 0) && !testbit(ir, 8)));
    decoded.rx_is_usp = ((line == 4) && (getBits(ir, 4, 8) == 0xE6));

    bool ea_imm_or_abs = ((getBits(ir, 3, 3) == 0x7) && !testbit(ir, 1));
    decoded.ry_is_dt = (ea_imm_or_abs && !is_reg_shift);

    switch (line)
    {
	case 0x4:
	{
	    decoded.implicit_sp = ((getBits(ir, 8, 4) == 0xE) || (getBits(6, 6) == 0x21));
	}
	break;
	case 0x6:
	{
	    decoded.implicit_sp = (getBits(ir, 8, 4) == 1);
	}
	break;
	default:
	{
	    decoded.implicit_sp = false;
	}
	break;
    }

    switch (line)
    {
	case 0x1:
	case 0x2:
	case 0x3:
	{
	    decoded.rx_is_areg = (getBits(ir, 6, 3) != 0);
	}
	break;
	case 0x4:
	{
	    decoded.rx_is_areg = (getBits(ir, 6, 3) == 0b111);
	}
	break;
	case 0x8:
	{
	    decoded.rx_is_areg = (ea_areg && testbit(ir, 8) && !testbit(ir, 7));
	}
	break;
	case 0xC:
	{
	    decoded.rx_is_areg = (ea_areg && testbit(ir, 8) && !testbit(ir, 7));
	}
	break;
	case 0x9:
	case 0xB:
	case 0xD:
	{
	    decoded.rx_is_areg = ((testbit(ir, 7) && testbit(ir, 6)) || (ea_areg && testbit(ir, 8) && (getBits(ir, 6, 2) != 3)));
	}
	break;
	default:
	{
	    decoded.rx_is_areg = decoded.implicit_sp;
	}
	break;
    }

    bool ea_is_areg = (getBits(ir, 3, 3) != 0) && (getBits(ir, 3, 3) != 7);

    switch (line)
    {
	case 0x6:
	case 0x7: decoded.ry_is_areg = false; break;
	case 0xE: decoded.ry_is_areg = !is_reg_shift; break;
	case 0x5: decoded.ry_is_areg = (ea_is_areg && (getBits(ir, 3, 5) != 0b11001)); break;
	default: decoded.ry_is_areg = ea_is_areg; break;
    }

    bool x_is_scc = (getBits(ir, 6, 2) == 3) && (getBits(ir, 3, 3) != 0b001);
    bool x_static_mem = (getBits(ir, 8, 4) == 0b1000) && (getBits(ir, 4, 2) == 0);

    switch (line)
    {
	case 0x0:
	{
	    decoded.is_byte = (
		(testbit(ir, 8) && (getBits(ir, 4, 2) != 0)) ||
		((getBits(ir, 8, 4) == 0b1000) && (getBits(ir, 4, 2) != 0)) ||
		((getBits(ir, 7, 2) == 0b10) && (getBits(ir, 3, 3) == 0b001)) ||
		((getBits(ir, 6, 3) == 0b000) && !x_static_mem)
	    );
	}
	break;
	case 0x1: decoded.is_byte = true; break;
	case 0x4: decoded.is_byte = ((getBits(ir, 6, 2) == 0) || decoded.is_tas); break;
	case 0x5: decoded.is_byte = ((getBits(ir, 6, 2) == 0) || x_is_scc); break;
	case 0x8:
	case 0x9:
	case 0xB:
	case 0xC:
	case 0xD:
	case 0xE: decoded.is_byte = (getBits(ir, 6, 2) == 0); break;
	default: decoded.is_byte = false; break;
    }

    decoded.is_movep = ((line == 0) && testbit(ir, 8) && ea_areg);

    decoded.to_ccr = 
	((line == 4) && ((getBits(ir, 0, 12) == 0xE77) || (getBits(ir, 6, 6) == 0b010011))) ||
	((line == 0) && (getBits(ir, 6, 3) == 0));

    if (line == 4)
    {
	switch (getBits(ir, 5, 2))
	{
	    case 0:
	    case 1: decoded.macro_tvn = 6; break;
	    case 3: decoded.macro_tvn = 7; break;
	    case 2: decoded.macro_tvn = 1; break;
	}
    }
    else
    {
	decoded.macro_tvn = 5;
    }

    // Decode ALU signals (WIP)
    bool ea_r_dir = (getBits(ir, 4, 2) == 0b00);
    bool ea_a_dir = (getBits(ir, 3, 3) == 0b001);
    bool size_11 = (getBits(ir, 6, 2) == 0b11);

    decoded.inhibit_ccr =
	(((line == 0x9) || (line == 0xD)) && size_11) ||
	((line == 0x5) && ea_a_dir) ||
	(((line == 0x2) || (line == 0x3)) && (getBits(ir, 6, 3) == 0b001));

    switch (line)
    {
	case 0x4:
	case 0x9:
	case 0xD:
	{
	    decoded.is_ar_x = true;
	}
	break;
	default:
	{
	    decoded.is_ar_x = false;
	}
	break;
    }

    decoded.is_long = (testbit(ir, 7) && !testbit(ir, 6));

    decoded.is_mul_signed = testbit(ir, 8);

    switch (line)
    {
	case 0x8:
	{
	    if (size_11)
	    {
		decoded.alu_row = 1;
	    }
	    else if (testbit(ir, 8) && ea_r_dir)
	    {
		decoded.alu_row = 9;
	    }
	    else
	    {
		decoded.alu_row = 14;
	    }
	}
	break;
	case 0x9:
	{
	    if (testbit(ir, 8) && !size_11 && ea_r_dir)
	    {
		decoded.alu_row = 10;
	    }
	    else
	    {
		decoded.alu_row = 5;
	    }
	}
	break;
	case 0xB:
	{
	    if (testbit(ir, 8) && !size_11 && !ea_a_dir)
	    {
		decoded.alu_row = 13;
	    }
	    else
	    {
		decoded.alu_row = 6;
	    }
	}
	break;
	case 0xC:
	{
	    if (size_11)
	    {
		decoded.alu_row = 7;
	    }
	    else if (testbit(ir, 8) && ea_r_dir)
	    {
		decoded.alu_row = 3;
	    }
	    else
	    {
		decoded.alu_row = 4;
	    }
	}
	break;
	case 0xE:
	{
	    int stype = 0;

	    if (size_11)
	    {
		stype = getBits(ir, 9, 2);
	    }
	    else
	    {
		stype = getBits(ir, 3, 2);
	    }

	    int alu_val = ((stype << 1) | testbit(ir, 8));

	    switch (alu_val)
	    {
		case 0: decoded.alu_row = 2; break;
		case 1: decoded.alu_row = 3; break;
		case 2: decoded.alu_row = 5; break;
		case 3: decoded.alu_row = 4; break;
		case 4: decoded.alu_row = 8; break;
		case 5: decoded.alu_row = 11; break;
		case 6: decoded.alu_row = 10; break;
		case 7: decoded.alu_row = 9; break;
	    }
	}
	break;
	case 0xD:
	{
	    if (testbit(ir, 8) && !size_11 && ea_r_dir)
	    {
		decoded.alu_row = 12;
	    }
	    else
	    {
		decoded.alu_row = 2;
	    }
	}
	break;
	case 0x0:
	{
	    if (testbit(ir, 8))
	    {
		decoded.alu_row = testbit(ir, 7) ? 14 : 13;
	    }
	    else
	    {
		switch (getBits(ir, 9, 3))
		{
		    case 0b000: decoded.alu_row = 14; break;
		    case 0b001: decoded.alu_row = 4; break;
		    case 0b010: decoded.alu_row = 5; break;
		    case 0b011: decoded.alu_row = 2; break;
		    case 0b100: decoded.alu_row = testbit(ir, 7) ? 14 : 13;
		    case 0b101: decoded.alu_row = 13; break;
		    case 0b110: decoded.alu_row = 6; break;
		    default: decoded.alu_row = 0; break;
		}
	    }
	}
	break;
	case 0x1:
	case 0x2:
	case 0x3:
	{
	    decoded.alu_row = 2;
	}
	break;
	case 0x4:
	{
	    if (testbit(ir, 8))
	    {
		decoded.alu_row = 6;
	    }
	    else
	    {
		switch (getBits(ir, 9, 3))
		{
		    case 0b000: decoded.alu_row = 10; break;
		    case 0b001: decoded.alu_row = 4; break;
		    case 0b010: decoded.alu_row = 5; break;
		    case 0b011: decoded.alu_row = 11; break;
		    case 0b100: decoded.alu_row = testbit(ir, 7) ? 8 : 9; break;
		    case 0b101: decoded.alu_row = 15; break;
		    default: decoded.alu_row = 0; break;
		}
	    }
	}
	break;
	case 0x5:
	{
	    if (size_11)
	    {
		decoded.alu_row = 15;
	    }
	    else
	    {
		decoded.alu_row = testbit(ir, 8) ? 5 : 2;
	    }
	}
	break;
	case 0x6: decoded.alu_row = 0; break;
	case 0x7: decoded.alu_row = 2; break;
	default: decoded.alu_row = 0; break;
    }

    if (testbit(ir, 15) && !testbit(ir, 13) && testbit(ir, 12) && size_11)
    {
	decoded.no_ccr_en = true;
    }
    else if ((line == 0x5) && ea_a_dir)
    {
	decoded.no_ccr_en = true;
    }
    else if (!testbit(ir, 15) && !testbit(ir, 15) && testbit(ir, 13) && (getBits(ir, 6, 3) == 0b001))
    {
	decoded.no_ccr_en = true;
    }
    else
    {
	decoded.no_ccr_en = false;
    }

    return decoded;
}

NanoDecoded decodeNano(array<uint32_t, 3> nano, IrDecoded &ir_decode)
{
    int atl_ctrl = nanox(nano, 36, 3);
    int ath_ctrl = nanox(nano, 56, 3);
    int ftu_ctrl = nanox(nano, 39, 4);
    int dob_ctrl = ((nanox(nano, 14) << 1) | nanox(nano, 11));
    NanoDecoded decoded;

    // T4
    decoded.au_clk_en = !nanox(nano, 48);
    decoded.au_ctrl = nanox(nano, 49, 3);
    decoded.no_sp_align = (nanox(nano, 66, 2) == 3);
    decoded.ext_dbh = nanox(nano, 55);
    decoded.ext_abh = nanox(nano, 54);
    decoded.to_dbin = nanox(nano, 7);
    decoded.to_irc = nanox(nano, 1);
    decoded.abl_abd = nanox(nano, 32);
    decoded.abl_abh = nanox(nano, 53);
    decoded.dbl_dbd = nanox(nano, 33);
    decoded.dbl_dbh = nanox(nano, 52);

    decoded.dbl_2_atl = (atl_ctrl == 2);
    decoded.atl_2_dbl = (atl_ctrl == 6);
    decoded.abl_2_atl = (atl_ctrl == 1);
    decoded.atl_2_abl = (atl_ctrl == 5);

    decoded.aob_2_ab = (ath_ctrl == 5);
    decoded.abh_2_ath = ((ath_ctrl == 4) || (ath_ctrl == 5));
    decoded.dbh_2_ath = (ath_ctrl == 1);
    decoded.ath_2_dbh = (ath_ctrl == 3);
    decoded.ath_2_abh = (ath_ctrl == 6);

    decoded.alu_2_dbd = nanox(nano, 23);
    decoded.alu_2_abd = nanox(nano, 22);

    decoded.abd_2_dcr = (nanox(nano, 9, 2) == 3);
    decoded.dcr_2_dbd = (nanox(nano, 8, 2) == 3);
    decoded.dbd_2_alue = (nanox(nano, 8, 2) == 1);
    decoded.alue_2_dbd = (nanox(nano, 9, 2) == 2);

    decoded.dbd_2_alub = nanox(nano, 18);
    decoded.abd_2_alub = nanox(nano, 19);

    decoded.dob_ctrl = dob_ctrl;

    decoded.is_rmc = (ir_decode.is_tas && nanox(nano, 25));


    // Start of ucode
    decoded.upd_ssw = decoded.aob_2_ab;

    decoded.upd_tp_end = (ftu_ctrl == 1);
    decoded.clr_tp_end = (ftu_ctrl == 14);
    decoded.tvn_2_ftu = (ftu_ctrl == 13);
    decoded.const_2_ftu = (ftu_ctrl == 1);
    decoded.ftu_2_dbl = ((ftu_ctrl == 4) || (ftu_ctrl == 6));
    decoded.ftu_2_abl = (ftu_ctrl == 8);
    decoded.inl_2_psw = (ftu_ctrl == 6);
    decoded.psw_i_2_ftu = (ftu_ctrl == 5);
    decoded.ftu_2_sr = (ftu_ctrl == 2);
    decoded.sr_2_ftu = (ftu_ctrl == 7);
    decoded.ird_2_ftu = (ftu_ctrl == 9);
    decoded.ssw_2_ftu = (ftu_ctrl == 11);
    decoded.init_st = ((ftu_ctrl == 6) || (ftu_ctrl == 14) || (ftu_ctrl == 15));
    decoded.abl_2_pren = (ftu_ctrl == 12);
    decoded.upd_pren = (ftu_ctrl == 10);

    decoded.ir_2_ird = nanox(nano, 0);
    decoded.alu_dctrl = nanox(nano, 15, 2);
    decoded.alu_actrl = nanox(nano, 17);
    decoded.alu_column = ((nanox(nano, 4) << 2) | (nanox(nano, 3) << 1) | nanox(nano, 2));

    int alu_fininit = nanox(nano, 5, 2);

    decoded.alu_finish = (alu_fininit == 1);
    decoded.alu_init = (alu_fininit == 2);

    decoded.ftu_2_ccr = (alu_fininit == 3);

    decoded.adb_is_byte = nanox(nano, 29);

    decoded.au_2_db = (nanox(nano, 46, 2) == 2);
    decoded.au_2_ab = (nanox(nano, 46, 2) == 1);
    decoded.au_2_pc = (nanox(nano, 46, 2) == 3);

    int aob_ctrl = nanox(nano, 63, 2);

    decoded.db_2_aob = (aob_ctrl == 1);
    decoded.ab_2_aob = (aob_ctrl == 2);
    decoded.au_2_aob = (aob_ctrl == 3);

    decoded.dbin_2_abd = nanox(nano, 21);
    decoded.dbin_2_dbd = nanox(nano, 20);

    decoded.perm_start = (aob_ctrl != 0);
    decoded.is_write = (nanox(nano, 11) || nanox(nano, 14));
    decoded.wait_bus_finish = (nanox(nano, 1) || nanox(nano, 7) || decoded.is_write);
    decoded.bus_byte = nanox(nano, 25);

    decoded.no_low_byte = nanox(nano, 12);
    decoded.no_high_byte = nanox(nano, 13);

    decoded.abl_2_reg = nanox(nano, 31);
    decoded.abh_2_reg = nanox(nano, 60);
    decoded.dbl_2_reg = nanox(nano, 34);
    decoded.dbh_2_reg = nanox(nano, 62);
    decoded.reg_2_dbl = nanox(nano, 35);
    decoded.reg_2_dbh = nanox(nano, 61);
    decoded.reg_2_abl = nanox(nano, 30);
    decoded.reg_2_abh = nanox(nano, 59);

    decoded.ssp = nanox(nano, 43);

    decoded.rz = nanox(nano, 24);

    // PC used instead of RY on PC relative instructions
    decoded.rxl_dbl = nanox(nano, 27);

    bool is_pc_rel = (ir_decode.is_pc_rel && !decoded.rz);
    bool pc_rel_dbl = (is_pc_rel && !nanox(nano, 27));
    bool pc_rel_dbh = (is_pc_rel && !nanox(nano, 45));
    bool pc_rel_abl = (is_pc_rel && nanox(nano, 27));
    bool pc_rel_abh = (is_pc_rel && nanox(nano, 45));

    decoded.pcl_dbl = (nanox(nano, 28) || pc_rel_dbl);
    decoded.pch_dbh = ((nanox(nano, 66, 2) == 2) || pc_rel_dbh);
    decoded.pcl_abl = (nanox(nano, 26) || pc_rel_abl);
    decoded.pch_abh = ((nanox(nano, 66, 2) == 1) || pc_rel_abh);

    decoded.rxl_2_db = (decoded.reg_2_dbl && !decoded.pcl_dbl && nanox(nano, 27));
    decoded.rxl_2_ab = (decoded.reg_2_abl && !decoded.pcl_abl && !nanox(nano, 27));
    decoded.dbl_2_rxl = (decoded.dbl_2_reg && !decoded.pcl_dbl && nanox(nano, 27));
    decoded.abl_2_rxl = (decoded.abl_2_reg && !decoded.pcl_abl && !nanox(nano, 27));

    decoded.rxh_2_dbh = (decoded.reg_2_dbh && !decoded.pch_dbh && nanox(nano, 45));
    decoded.rxh_2_abh = (decoded.reg_2_abh && !decoded.pch_abh && !nanox(nano, 45));

    decoded.dbh_2_rxh = (decoded.dbh_2_reg && !decoded.pch_dbh && nanox(nano, 45));
    decoded.abh_2_rxh = (decoded.abh_2_reg && !decoded.pch_abh && !nanox(nano, 45));

    decoded.dbh_2_ryh = (decoded.dbh_2_reg && !decoded.pch_dbh && !nanox(nano, 45));
    decoded.abh_2_ryh = (decoded.abh_2_reg && !decoded.pch_abh && nanox(nano, 45));

    decoded.dbl_2_ryl = (decoded.dbl_2_reg && !decoded.pcl_dbl && !nanox(nano, 27));
    decoded.abl_2_ryl = (decoded.abl_2_reg && !decoded.pcl_abl && nanox(nano, 27));

    decoded.ryl_2_db = (decoded.reg_2_dbl && !decoded.pcl_dbl && !nanox(nano, 27));
    decoded.ryl_2_ab = (decoded.reg_2_abl && !decoded.pcl_abl && nanox(nano, 27));

    decoded.ryh_2_dbh = (decoded.reg_2_dbh && !decoded.pch_dbh && !nanox(nano, 45));
    decoded.ryh_2_abh = (decoded.reg_2_abh && !decoded.pch_abh && nanox(nano, 45));

    return decoded;
}

string getBool(bool val)
{
    return (val) ? "true" : "false";
}

string getInt(int val)
{
    stringstream ss;
    ss << dec << val;
    return ss.str();
}

bool isNone(string val)
{
    return (val == "-1");
}

bool isFalse(string val)
{
    return (isNone(val) || ((val == "0") || (val == "false")));
}

bool isTrue(string val)
{
    return (isFalse(val) == false);
}

int toInt(string val)
{
    stringstream ss;
    ss << val;
    int res = 0;
    ss >> res;
    return res;
}

namespace cbc
{
    enum : int
    {
	i11 = 0x00,
	auz = 0x01,
	c = 0x02,
	z = 0x03,
	nz1 = 0x04,
	n = 0x05,
	nz2 = 0x06,
	ms0 = 0x07,
	m01 = 0x08,
	cc = 0x09,
	ze = 0x0A,
	nv = 0x0B,
	d4 = 0x0C,
	v = 0x0D,
	enl = 0x0E,
	auzi = 0x11,
	ci = 0x12,
	ni = 0x15,
	cci = 0x19,
	d4i = 0x1C,
	enli = 0x1E
    };
};

array<deque<int>, 32> cbc_slots = 
{{
    { 0, 3 }, { 3, 1 }, { 1, 0 }, { 0, 3 }, { 2, 1, 3 }, { 1, 3 }, { 3, 1 }, { 3, 1, 2 },
    { 0, 1, 2, 3 }, { 1, 3 }, { 3, 0 }, { 3, 0 }, { 3, 1 }, { 3, 0 }, { 2, 3, 0}, {},
    {}, { 3, 0 }, { 3, 2 }, {}, {}, { 2, 3 }, {}, {},
    {}, { 2, 3 }, {}, {}, { 3, 2 }, {}, { 2, 3, 1 }, {}
}};

using frametype = deque<optional<uint16_t>>;

vector<frametype> genGraph(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t ir)
{
    list<uint16_t> addrs;
    set<uint16_t> addru;
    addrs.push_back(a1);

    vector<frametype> graph;

    while (!addrs.empty())
    {
	uint16_t maddr = addrs.front();
	addrs.pop_front();

	if (addru.find(maddr) != addru.end())
	{
	    continue;
	}

	addru.insert(maddr);

	frametype frame = {maddr, {}};

	uint16_t micro = microcode_table.at(maddr);

	uint16_t next = (((micro >> 5) & 0x300) | ((micro << 1) & 0xC0) | ((micro >> 5) & 0x3C) | ((micro >> 11) & 0x3));

	if (testbit(micro, 1))
	{
	    int cond_id = ((micro >> 2) & 0x1F);
	    frame.back() = cond_id;
	    uint16_t next_base = (next & 0x33F);

	    if ((cond_id == cbc::enl) || (cond_id == cbc::enli))
	    {
		uint16_t val0 = testbit(ir, 6) ? cbc_slots[cond_id].at(1) : cbc_slots[cond_id].at(0);

		uint16_t frame_val = (next_base | (val0 << 6));
		uint16_t frame_val1 = (next_base | (cbc_slots[cond_id].at(2) << 6));

		frame.push_back(frame_val);
		frame.push_back(frame_val1);
	    }
	    else if (cond_id == cbc::ms0)
	    {
		uint16_t val0 = testbit(ir, 8) ? cbc_slots[cond_id].at(2) : cbc_slots[cond_id].at(1);
		uint16_t frame_val = (next_base | (cbc_slots[cond_id].at(0) << 6));
		uint16_t frame_val1 = (next_base | (val0 << 6));

		frame.push_back(frame_val);
		frame.push_back(frame_val1);
	    }
	    else if ((cond_id == cbc::m01) && !testbit(ir, 8))
	    {
		uint16_t frame_val = (next_base | (cbc_slots[cond_id].at(0) << 6));
		uint16_t frame_val1 = (next_base | (cbc_slots[cond_id].at(1) << 6));
		uint16_t frame_val2 = (next_base | (cbc_slots[cond_id].at(3) << 6));
		frame.push_back(frame_val);
		frame.push_back(frame_val1);
		frame.push_back(frame_val2);
	    }
	    else
	    {
		auto cbc_slot = cbc_slots.at(cond_id);

		for (size_t i = 0; i < cbc_slot.size(); i++)
		{
		    int slot = cbc_slot.at(i);
		    frame.push_back((next_base | (slot << 6)));
		}
	    }
	}
	else if ((micro & 0xC) != 0)
	{
	    int aslot = ((micro >> 2) & 0x3);

	    if (aslot == 1)
	    {
		// cout << "Success" << endl;
	    }

	    if (aslot == 2)
	    {
		frame.push_back(a2);
	    }
	    else if (aslot == 3)
	    {
		frame.push_back(a3);
	    }
	}
	else
	{
	    frame.push_back(next);
	}

	graph.push_back(frame);

	for (int i = 0; i < frame.size(); i++)
	{
	    if (i < 2)
	    {
		continue;
	    }

	    auto val = frame.at(i);
	    if (!val)
	    {
		cout << "Error" << endl;
		throw runtime_error("Codegen error");
	    }
	    else
	    {
		addrs.push_back(val.value());
	    }
	}
    }

    return graph;
}

template<typename T>
T getValue(optional<T> opt)
{
    if (!opt.has_value())
    {
	cout << "Could not fetch optional value" << endl;
	throw runtime_error("Codegen error");
    }

    return opt.value();
}

struct KujoM68KBlock
{
    uint32_t val = 0;
    vector<uint16_t> block_val;
    optional<uint16_t> last;
    vector<optional<uint16_t>> extra;
};

template<class Key, class Value>
vector<Key> getKeys(unordered_map<Key, Value> maps)
{
    vector<Key> keys;
    keys.reserve(maps.size());
    for (auto &kvp : maps)
    {
	keys.push_back(kvp.first);
    }

    return keys;
}

vector<KujoM68KBlock> genBlocks(vector<frametype> graph)
{
    auto findFwd = [&](uint16_t ma, vector<frametype> graph) -> optional<int>
    {
	optional<int> res;
	for (size_t i = 0; i < graph.size(); i++)
	{
	    auto val = graph.at(i);
	    if (val.at(0) == ma)
	    {
		res = i;
		return res;
	    }
	}

	return res;
    };

    unordered_map<uint16_t, bool> edges;
    auto first_edge = graph[0][0];
    edges[getValue(first_edge)] = true;

    for (auto &fwd : graph)
    {
	if (fwd.size() > 3)
	{
	    for (int i = 2; i < fwd.size(); i++)
	    {
		auto ma = fwd.at(i);
		edges[getValue(ma)] = true;
	    }
	}
    }

    unordered_map<int, uint16_t> bcount;

    for (auto &fwd : graph)
    {
	for (int i = 0; i < fwd.size(); i++)
	{
	    if (i < 2)
	    {
		continue;
	    }

	    auto ma = getValue(fwd.at(i));

	    if (bcount.find(ma) == bcount.end())
	    {
		bcount[ma] = 1;
	    }
	    else
	    {
		bcount[ma] = (bcount[ma] + 1);
	    }
	}
    }

    auto edge_keys = getKeys(edges);

    unordered_map<uint16_t, vector<uint16_t>> blocks;

    for (auto &ma : edge_keys)
    {
	blocks[ma] = {ma};
    }

    for (auto &ext : bcount)
    {
	if (ext.second > 1)
	{
	    uint16_t value = ext.first;
	    blocks[ext.first] = {value};
	}
    }

    auto block_keys = getKeys(blocks);

    for (auto &ma : block_keys)
    {
	auto ma1 = ma;

	while (true)
	{
	    auto iter = findFwd(ma1, graph);

	    if (!iter)
	    {
		cout << "Could not find value" << endl;
		throw runtime_error("Codegen error");
	    }

	    auto val = graph.at(getValue(iter));

	    if (val.size() <= 2)
	    {
		break;
	    }
	    else
	    {
		if (blocks.find(getValue(val.at(2))) != blocks.end())
		{
		    break;
		}
	    }
	    
	    ma1 = getValue(val.at(2));
	    blocks[ma].push_back(ma1);
	}
    }

    unordered_map<uint16_t, uint16_t> bids;
    deque<uint16_t> to_add;

    vector<KujoM68KBlock> oblocks;

    to_add.push_back(getValue(graph[0][0]));
    bids[to_add[0]] = 0;
    int cid = 1;

    while (!to_add.empty())
    {
	uint16_t val = to_add.front();
	to_add.pop_front();

	bids[val] = oblocks.size();

	auto block_iter = blocks.find(val);

	if (block_iter != blocks.end())
	{
	    auto iter = findFwd(blocks[val].back(), graph);

	    if (!iter)
	    {
		throw runtime_error("Codegen error");
	    }

	    auto last = graph.at(getValue(iter));
	    for (int i = 0; i < last.size(); i++)
	    {
		if (i < 2)
		{
		    continue;
		}

		uint16_t nx = getValue(last.at(i));

		if (bids.find(nx) == bids.end())
		{
		    to_add.push_back(nx);
		    bids[nx] = cid;
		    cid += 1;
		}
	    }

	    KujoM68KBlock block;
	    block.val = val;
	    block.block_val = blocks[val];
	    block.last = last.at(1);

	    for (size_t i = 0; i < last.size(); i++)
	    {
		if (i < 2)
		{
		    continue;
		}

		auto last_val = getValue(last.at(i));
		block.extra.push_back(bids.at(last_val));
	    }

	    oblocks.push_back(block);
	}
    }

    return oblocks;
}

enum  : int
{
    axl = 1,
    dxl = 2,
    ayl = 3,
    dyl = 4,
    rzl = 5,
    a7l = 6,
    sspl = 7,
    uspl = 8,
    dtl = 9,
    aul = 10,
    atl = 11,
    pcl = 12,
    aobl = 13,
    moveml = 14,
    axh = 15,
    dxh = 16,
    ayh = 17,
    dyh = 18,
    rzh = 19,
    a7h = 20,
    ssph = 21,
    usph = 22,
    dth = 23,
    auh = 24,
    ath = 25,
    pch = 26,
    aobh = 27,
    movemh = 28,
    alue = 29,
    alub = 30,
    dbin = 31,
    dbout = 32,
    aluo = 33,
    dcr = 34,
    dcro = 35,
    dcro8 = 36,
    ftu = 37,
    ir = 38,
    irc = 39,
    ird = 40,
    edb = 41,
    sr = 42,
    movemr = 43
};

namespace dep
{
enum : int
{
    dregl = (1 << 0),
    dregh = (1 << 1),
    aregl = (1 << 2),
    aregh = (1 << 3),
    irc = (1 << 4),
    dt = (1 << 5),
    au = (1 << 6),
    atl = (1 << 7),
    ath = (1 << 8),
    pc = (1 << 9),
    aob = (1 << 10),
    alue = (1 << 11),
    alub = (1 << 12),
    dbin = (1 << 13),
    aluo = (1 << 14),
    dcr = (1 << 15),
    ftu = (1 << 16),
    ir = (1 << 17),
    ird = (1 << 18),
    sr = (1 << 19)
};
};

namespace alu
{
    enum : int
    {
	none = 0,
	and_ = 1,
	sub = 2,
	subx = 3,
	add = 4,
	ext = 5,
	sbcd = 6,
	not_ = 7,
	or_ = 8,
	eor = 9,
	subc = 10,
	addc = 11,
	addx = 12,
	asl = 13,
	asr = 14,
	lsl = 15,
	lsr = 16,
	rol = 17,
	ror = 18,
	roxl = 19,
	roxr = 20,
	sla0 = 21,
	sla1 = 22,
	abcd = 23,
	over = 24
    };
};

namespace aluinfo
{
    enum : int
    {
	is_byte = (1 << 0),
	is_long = (1 << 1),
	is_mul = (1 << 2),
	is_div = (1 << 3),
	is_rox_and = (1 << 4),
	init = (1 << 5),
	finish = (1 << 6),
	mul_signed = (1 << 7),
	arx = (1 << 8)
    };
};

array<int, 128> alu_ops = 
{
    alu::none, alu::and_, alu::none, alu::none, alu::none, alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::sub,  alu::subc, alu::sla0, alu::over, alu::sla1, alu::none,
    alu::none, alu::and_, alu::add,  alu::addc, alu::asr,  alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::abcd, alu::add,  alu::asl,  alu::ext,  alu::none, alu::none,
    alu::and_, alu::and_, alu::and_, alu::and_, alu::lsl,  alu::ext,  alu::and_, alu::and_,
    alu::none, alu::and_, alu::sub,  alu::subc, alu::lsr,  alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::sub,  alu::subc, alu::lsr,  alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::sub,  alu::add,  alu::roxr, alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::ext,  alu::and_, alu::roxr, alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::sbcd, alu::sbcd, alu::rol,  alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::subx, alu::subc, alu::ror,  alu::ext,  alu::none, alu::none,
    alu::none, alu::and_, alu::not_, alu::not_, alu::roxl, alu::ext,  alu::none, alu::none,
    alu::addx, alu::and_, alu::addx, alu::addx, alu::addx, alu::ext,  alu::addx, alu::addx,
    alu::eor,  alu::and_, alu::eor,  alu::eor,  alu::eor,  alu::ext,  alu::eor,  alu::eor,
    alu::or_,  alu::and_, alu::or_,  alu::or_,  alu::eor,  alu::ext,  alu::or_,  alu::or_,
    alu::or_,  alu::and_, alu::or_,  alu::add,  alu::or_,  alu::ext,  alu::or_,  alu::or_
};

array<array<uint8_t, 128>, 2> alu_masks = {
    0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x0f, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x00, 0x0f, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x1f, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

vector<string> regname = 
{
    "-1",
    "reg_da[rx_index]", "reg_da[rx_index]", "reg_da[ry_index]", "reg_da[ry_index]", "reg_da[mapSP(reg_irc >> 12)]", "reg_da[reg_sp]", "reg_da[16]", "reg_da[15]", "reg_dt", "reg_au", "reg_at", "reg_pc", "reg_aob", "reg_da[reg_movems]",
    "reg_da[rx_index]", "reg_da[rx_index]", "reg_da[ry_index]", "reg_da[ry_index]", "reg_da[mapSP(reg_irc >> 12)]", "reg_da[reg_sp]", "reg_da[16]", "reg_da[15]", "reg_dt", "reg_au", "reg_at", "reg_pc", "reg_aob", "reg_da[reg_movems]",
    "reg_alue", "reg_alub", "reg_dbin", "reg_dbout", "reg_aluo", "reg_dcr", "reg_dcro", "reg_dcro8", "reg_ftu", "reg_ir", "reg_irc", "reg_ird", "reg_edb", "reg_sr", "reg_movemr"
};

vector<int> regdep = 
{
    0,
    dep::aregl, dep::dregl, dep::aregl, dep::dregl, dep::aregl|dep::dregl|dep::irc, dep::aregl, dep::aregl, dep::aregl, dep::dt, dep::au, dep::atl, dep::pc, dep::aob, dep::aregl|dep::dregl,
    dep::aregh, dep::dregh, dep::aregh, dep::dregh, dep::aregh|dep::dregh|dep::irc, dep::aregh, dep::aregh, dep::aregh, dep::dt, dep::au, dep::ath, dep::pc, dep::aob, dep::aregh|dep::dregh,
    dep::alue, dep::alub, dep::dbin, 0, dep::aluo, dep::dcr, dep::dcr, dep::dcr, dep::ftu, dep::ir, dep::irc, dep::ird, 0, dep::sr, 0
};

array<string, 25> alu_opnames = {
    "None", "And", "Sub", "Subx", "Add", "Ext", "Sbcd", "Not", "Or", "Xor", "Subc", "Addc", "Addx", "Asl", "Asr", "Lsl", "Lsr", "Rol", "Ror", "Roxl", "Roxr", "Sla0", "Sla1", "Abcd", "Over"
};

array<bool, 25> is_single_param = { 
false, false, false, false, false, true, false, true, false, false, false, false, false, true, true, true, true, true, true, true, true, true, true, false, true
};

struct KujoCodeLine
{
    string tag;
    deque<string> args;
};

bool isRegMergable(int rh, int rl)
{
    return ((rh != -1) && (rl != -1) && (rl <= moveml) && (rh <= movemh) && ((rl + (axh - axl)) == rh));
}

deque<string> maybeMerge(int rh, int rl, bool is_ext)
{
    if (is_ext)
    {
	return {"ext32", getInt(rl)};
    }
    
    if (isRegMergable(rh, rl))
    {
	return {getInt(rl)};
    }
    else
    {
	return {"merge", getInt(rh), getInt(rl)};
    }
}

int exprDeps(string ci)
{
    if ((ci == "-1") || (ci == "ftu-i") || (ci == "trap-tvn") || (ci == "int-tvn"))
    {
	return 0;
    }

    if (ci == "ftu-ssw")
    {
	return dep::ftu;
    }

    return regdep.at(toInt(ci));
}

int exprDeps(deque<string> ci, int &num_args)
{
    int reg_val = toInt(ci.at(0));

    if ((reg_val >= 1) && (reg_val <= 43))
    {
	num_args = 1;
	return exprDeps(ci.at(0));
    }
    else if (ci.size() == 1)
    {
	num_args = 1;
	return exprDeps(ci.at(0));
    }
    else if ((ci.at(0) == "+1/2") || (ci.at(0) == "-1/2"))
    {
	auto args = ci;
	args.pop_front();

	int nargs = 0;
	int deps = exprDeps(args, nargs);

	num_args = nargs;
	return deps;
    }
    else if (ci.at(0) == "+c")
    {
	auto args = ci;
	args.pop_back();

	int nargs = 0;
	int deps = exprDeps(args, nargs);

	num_args = nargs;
	return deps;
    }
    else if ((ci.at(0) == "ext32") || (ci.at(0) == "ext32h"))
    {
	num_args = 2;
	return exprDeps(ci.at(1));
    }
    else if (ci.at(0) == "merge")
    {
	num_args = 3;
	return (exprDeps(ci.at(1)) | exprDeps(ci.at(2)));
    }
    else if (ci.at(0) == "+r")
    {
	auto args = ci;
	args.pop_front();

	int nargs0 = 0;
	int deps0 = exprDeps(args, nargs0);

	for (int i = 0; i < nargs0; i++)
	{
	    args.pop_front();
	}

	int nargs1 = 0;
	int deps1 = exprDeps(args, nargs1);

	num_args = (nargs0 + nargs1);
	return (deps0 | deps1);
    }
    else if (ci.at(0) == "ct")
    {
	num_args = 2;
	return 0;
    }
    else if ((ci.at(0) == "c0") || (ci.at(0) == "c1"))
    {
	num_args = 1;
	return 0;
    }
    else
    {
	cout << "Unimplemented expr deps" << endl;
	for (auto &c : ci)
	{
	    cout << c << endl;
	}

	throw runtime_error("Codegen error");
    }
}

int exprDeps(deque<string> ci)
{
    int num_args = 0;
    return exprDeps(ci, num_args);
}

array<int, 2> findDeps(KujoCodeLine code)
{
    string tag = code.tag;

    if (tag == "state")
    {
	return {0, 0};
    }
    else if (tag == "set")
    {
	int ci1 = toInt(code.args.at(0));
	int t0 = regdep.at(ci1);

	if (t0 & dep::aregl)
	{
	    t0 |= dep::aregh;
	}

	if (t0 & dep::dregl)
	{
	    t0 |= dep::dregh;
	}

	if (t0 & dep::atl)
	{
	    t0 |= dep::ath;
	}

	deque<string> args = code.args;
	args.pop_front();

	int t1 = exprDeps(args);
	return {t0, t1};
    }
    else if ((tag == "setSR") || (tag == "setSRD") || (tag == "setCCR") || (tag == "set8") || (tag == "set8High") || (tag == "set8ExHigh") || (tag == "set8ExLow") || (tag == "set16Low") || (tag == "set16High"))
    {
	int ci1 = toInt(code.args.at(0));
	int t0 = regdep.at(ci1);

	deque<string> args = code.args;
	args.pop_front();

	int t1 = exprDeps(args);
	return {t0, t1};
    }
    else if ((tag == "setSRI") || (tag == "setSRI7"))
    {
	return {int(regdep.at(sr)), 0};
    }
    else if (tag == "alu")
    {
	int t0 = dep::aluo;

	if (code.args.size() == 4)
	{
	    int t1 = exprDeps(code.args.at(3));
	    return {t0, t1};
	}
	else
	{
	    int t1 = (exprDeps(code.args.at(3)) | exprDeps(code.args.at(4)));
	    return {t0, t1};
	}
    }

    cout << "Unimplemented tag of " << tag << endl;
    throw runtime_error("Codegen error");
    return {0, 0};
}

void sortAndAppend(deque<KujoCodeLine> code_to_sort, deque<KujoCodeLine> &code)
{
    deque<KujoCodeLine> cl;

    for (auto &c : code_to_sort)
    {
	KujoCodeLine line;
	line.tag = c.tag;

	auto deps = findDeps(c);

	line.args.push_back(getInt(deps[0]));
	line.args.push_back(getInt(deps[1]));

	for (auto &arg : c.args)
	{
	    line.args.push_back(arg);
	}

	cl.push_back(line);
    }

    while (!cl.empty())
    {
	int slot = -1;

	for (size_t i = 0; i < cl.size(); i++)
	{
	    bool no_dep = true;

	    for (size_t j = 0; j < cl.size(); j++)
	    {
		int c0 = toInt(cl.at(i).args.at(0));
		int c1 = toInt(cl.at(j).args.at(1));

		if ((i != j) && (c0 & c1))
		{
		    no_dep = false;
		    break;
		}
	    }

	    if (no_dep == true)
	    {
		slot = i;
		break;
	    }
	}

	if (slot == -1)
	{
	    code.push_back({"state", {"fail"}});
	    cout << "Cross dependency occured" << endl;
	    throw runtime_error("Codegen error");
	    slot = 0;
	}

	auto cl2 = cl.at(slot);
	deque<string> args = cl2.args;
	args.pop_front();
	args.pop_front();
	code.push_back({cl2.tag, args});

	cl.erase(cl.begin() + slot);
    }
} 

deque<KujoCodeLine> genBaseCode(uint16_t ir_val, uint16_t ir_mask, uint16_t maddr, int tvn, bool group01)
{
    deque<KujoCodeLine> code;

    deque<KujoCodeLine> code_to_sort;

    stringstream comment;
    comment << hex << setw(3) << setfill('0') << int(maddr) << " " << labelName(maddr);

    code.push_back({"comment", {comment.str()}});

    auto micro = microcode_table.at(maddr);
    auto nano = nanocode_table.at(maddr);

    auto ir_dec = decodeIR(ir_val);
    auto nano_dec = decodeNano(nano, ir_dec);

    int alu_info = 0;

    if (ir_dec.is_byte)
    {
	alu_info |= aluinfo::is_byte;
    }

    if (ir_dec.alu_row == 7)
    {
	alu_info |= aluinfo::is_mul;
    }

    if (ir_dec.alu_row == 1)
    {
	alu_info |= aluinfo::is_div;
    }

    if (ir_dec.is_long || (alu_info & (aluinfo::is_div | aluinfo::is_mul)))
    {
	alu_info |= aluinfo::is_long;
    }

    if ((nano_dec.alu_column == 1) && ((ir_dec.alu_row == 8) || (ir_dec.alu_row == 11)))
    {
	alu_info |= aluinfo::is_rox_and;
    }

    if (nano_dec.alu_init)
    {
	alu_info |= aluinfo::init;
    }

    if (nano_dec.alu_finish)
    {
	alu_info |= aluinfo::finish;
    }

    if (ir_dec.is_mul_signed)
    {
	alu_info |= aluinfo::mul_signed;
    }

    if (ir_dec.is_ar_x && ((ir_dec.alu_row == 10) || (ir_dec.alu_row == 12)))
    {
	alu_info |= aluinfo::arx;
    }


    int alu_op_offs = ((ir_dec.alu_row * 8) + nano_dec.alu_column);
    int alu_op = alu_ops.at(alu_op_offs);

    int alu_mask = 0;

    if (alu_info & aluinfo::finish)
    {
	alu_mask = alu_masks[1][alu_op_offs];
    }
    else
    {
	alu_mask = alu_masks[0][alu_op_offs];
    }

    if ((alu_op == alu::abcd) || (alu_op == alu::sbcd))
    {
	alu_info |= aluinfo::arx;
    }

    int cond = -1;

    if (testbit(micro, 1))
    {
	cond = ((micro >> 2) & 0x1F);
    }

    bool drop_critical = (((micro & 0x3) == 0x3) || ((micro & 0x11) == 0x01));

    int rx = -1;
    int ry = -1;

    // Register selection for x and y channel

    if (nano_dec.ssp)
    {
	rx = sspl;
    }
    else if (ir_dec.rx_is_usp)
    {
	rx = uspl;
    }
    else if (ir_dec.implicit_sp)
    {
	rx = a7l;
    }
    else if (ir_dec.rx_is_dt)
    {
	rx = dtl;
    }
    else if (ir_dec.rx_is_movem)
    {
	rx = moveml;
    }
    else if (ir_dec.rx_is_areg)
    {
	rx = axl;
    }
    else
    {
	rx = dxl;
    }

    if (nano_dec.rz)
    {
	ry = rzl;
    }
    else if (ir_dec.ry_is_dt)
    {
	ry = dtl;
    }
    else if (ir_dec.ry_is_areg)
    {
	ry = ayl;
    }
    else
    {
	ry = dyl;
    }

    int dbd_in = -1;
    int dbl_in = -1;
    int dbh_in = -1;

    int abd_in = -1;
    int abl_in = -1;
    int abh_in = -1;

    int dbd = -1;
    int dbl = -1;
    int dbh = -1;

    int abd = -1;
    int abl = -1;
    int abh = -1;

    if (nano_dec.rxl_2_db && !(nano_dec.ssp || ir_dec.rx_is_usp || ir_dec.implicit_sp || ir_dec.rx_is_areg))
    {
	dbd_in = rx;
    }
    else if (nano_dec.ryl_2_db && !ir_dec.ry_is_areg)
    {
	dbd_in = ry;
    }
    else if (nano_dec.alue_2_dbd)
    {
	dbd_in = alue;
    }
    else if (nano_dec.dbin_2_dbd)
    {
	dbd_in = dbin;
    }
    else if (nano_dec.alu_2_dbd)
    {
	dbd_in = aluo;
    }
    else if (nano_dec.dcr_2_dbd)
    {
	dbd_in = ir_dec.is_byte ? dcro8 : dcro;
    }

    if (nano_dec.rxl_2_db && (nano_dec.ssp || ir_dec.rx_is_usp || ir_dec.implicit_sp || ir_dec.rx_is_areg))
    {
	dbl_in = rx;
    }
    else if (nano_dec.ryl_2_db && ir_dec.ry_is_areg)
    {
	dbl_in = ry;
    }
    else if (nano_dec.ftu_2_dbl)
    {
	dbl_in = ftu;
    }
    else if (nano_dec.au_2_db)
    {
	dbl_in = aul;
    }
    else if (nano_dec.atl_2_dbl)
    {
	dbl_in = atl;
    }
    else if (nano_dec.reg_2_dbl && nano_dec.pcl_dbl)
    {
	dbl_in = pcl;
    }

    if (nano_dec.rxh_2_dbh)
    {
	dbh_in = (rx + (axh - axl));
    }
    else if (nano_dec.ryh_2_dbh)
    {
	dbh_in = (ry + (axh - axl));
    }
    else if (nano_dec.au_2_db)
    {
	dbh_in = auh;
    }
    else if (nano_dec.ath_2_dbh)
    {
	dbh_in = ath;
    }
    else if (nano_dec.reg_2_dbh && nano_dec.pch_dbh)
    {
	dbh_in = pch;
    }

    if (nano_dec.rxl_2_ab && !(nano_dec.ssp || ir_dec.rx_is_usp || ir_dec.implicit_sp || ir_dec.rx_is_areg))
    {
	abd_in = rx;
    }
    else if (nano_dec.ryl_2_ab && !ir_dec.ry_is_areg)
    {
	abd_in = ry;
    }
    else if (nano_dec.alu_2_abd)
    {
	abd_in = aluo;
    }
    else if (nano_dec.dbin_2_abd)
    {
	abd_in = dbin;
    }

    if (nano_dec.rxl_2_ab && (nano_dec.ssp || ir_dec.rx_is_usp || ir_dec.implicit_sp || ir_dec.rx_is_areg))
    {
	abl_in = rx;
    }
    else if (nano_dec.ryl_2_ab && ir_dec.ry_is_areg)
    {
	abl_in = ry;
    }
    else if (nano_dec.ftu_2_abl)
    {
	abl_in = ftu;
    }
    else if (nano_dec.au_2_ab)
    {
	abl_in = aul;
    }
    else if (nano_dec.aob_2_ab)
    {
	abl_in = aobl;
    }
    else if (nano_dec.atl_2_abl)
    {
	abl_in = atl;
    }
    else if (nano_dec.reg_2_abl && nano_dec.pcl_abl)
    {
	abl_in = pcl;
    }

    if (nano_dec.rxh_2_abh)
    {
	abh_in = (rx + (axh - axl));
    }
    else if (nano_dec.ryh_2_abh)
    {
	abh_in = (ry + (axh - axl));
    }
    else if (nano_dec.au_2_ab)
    {
	abh_in = auh;
    }
    else if (nano_dec.aob_2_ab)
    {
	abh_in = aobh;
    }
    else if (nano_dec.ath_2_abh)
    {
	abh_in = ath;
    }
    else if (nano_dec.reg_2_abh && nano_dec.pch_abh)
    {
	abh_in = pch;
    }

    if (dbd_in != -1)
    {
	dbd = dbd_in;
    }
    else if ((dbl_in != -1) && nano_dec.dbl_dbd)
    {
	dbd = dbl_in;
    }
    else if ((dbh_in != -1) && nano_dec.dbl_dbd && nano_dec.dbl_dbh)
    {
	dbd = dbh_in;
    }

    if (dbl_in != -1)
    {
	dbl = dbl_in;
    }
    else if ((dbd_in != -1) && nano_dec.dbl_dbd)
    {
	dbl = dbd_in;
    }
    else if ((dbh_in != -1) && nano_dec.dbl_dbh)
    {
	dbl = dbh_in;
    }

    if (dbh_in != -1)
    {
	dbh = dbh_in;
    }
    else if ((dbl_in != -1) && nano_dec.dbl_dbh)
    {
	dbh = dbl_in;
    }
    else if ((dbd_in != -1) && nano_dec.dbl_dbd && nano_dec.dbl_dbh)
    {
	dbh = dbd_in;
    }

    if (abd_in != -1)
    {
	abd = abd_in;
    }
    else if ((abl_in != -1) && nano_dec.abl_abd)
    {
	abd = abl_in;
    }
    else if ((abh_in != -1) && nano_dec.abl_abh)
    {
	abd = abh_in;
    }

    if (abl_in != -1)
    {
	abl = abl_in;
    }
    else if ((abd_in != -1) && nano_dec.abl_abd)
    {
	abl = abd_in;
    }
    else if ((abh_in != -1) && nano_dec.abl_abh)
    {
	abl = abh_in;
    }

    if (abh_in != -1)
    {
	abh = abh_in;
    }
    else if ((abl_in != -1) && nano_dec.abl_abh)
    {
	abh = abl_in;
    }
    else if ((abd_in != -1) && nano_dec.abl_abd && nano_dec.abl_abh)
    {
	abh = abd_in;
    }

    bool is_ext_dbh = false;
    bool is_ext_abh = false;

    if (nano_dec.ext_dbh)
    {
	is_ext_dbh = true;
	dbh = dbl;
    }

    if (nano_dec.ext_abh)
    {
	is_ext_abh = true;
	abh = abl;
    }

    // T1

    bool micro15 = testbit(micro, 15);
    bool micro16 = testbit(micro, 16);

    if (nano_dec.au_2_aob || (nano_dec.au_2_db && nano_dec.db_2_aob))
    {
	code.push_back({"set", {getInt(aobl), getInt(aul)}});
    }
    else if (nano_dec.db_2_aob)
    {
	deque<string> args = {getInt(aobl)};

	for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
	{
	    args.push_back(arg);
	}

	code.push_back({"set", args});
    }
    else if (nano_dec.ab_2_aob)
    {
	deque<string> args = {getInt(aobl)};

	for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
	{
	    args.push_back(arg);
	}

	code.push_back({"set", args});
    }

    if (nano_dec.ir_2_ird)
    {
	code.push_back({"set", {getInt(ird), getInt(ir)}});
	code.push_back({"state", {"setIntState"}});
    }
    else if (testbit(micro, 0))
    {
	code.push_back({"set", {getInt(ir), getInt(irc)}});
	code.push_back({"state", {"updateIPL"}});
    }

    if (nano_dec.abl_2_pren)
    {
	code.push_back({"set", {getInt(movemr), getInt(dbin)}});
    }

    if (nano_dec.perm_start)
    {
	bool fc0 = (((!ir_dec.is_pc_rel) && !micro16) || micro15);
	bool fc1 = ((ir_dec.is_pc_rel && !micro15) || micro16);

	bool bus_byte = (nano_dec.bus_byte && (ir_dec.is_byte || ir_dec.is_movep));

	deque<string> args = {getBool(fc0), getBool(fc1), getBool(bus_byte), getInt(nano_dec.dob_ctrl), getBool(nano_dec.no_high_byte), getBool(nano_dec.no_low_byte), getBool(group01), getBool(nano_dec.is_rmc)};

	code.push_back({"setBus", args});
    }

    code.push_back({"setLines", {getBool(micro15 && !nano_dec.perm_start), getBool(micro16 && !nano_dec.perm_start)}});

    if (nano_dec.init_st)
    {
	code.push_back({"state", {"initST"}});
    }

    if (cond == cbc::i11)
    {
	code.push_back({"setCond", {"testbit(reg_irc, 11)"}});
    }
    else if ((cond == cbc::d4) || (cond == cbc::d4i))
    {
	code.push_back({"setCond", {"testbit(reg_dcr, 4) ? 1 : 0"}});
    }
    else if (cond == cbc::nv)
    {
	code.push_back({"setCond", {"((reg_isr & (SrOverflow | SrSign)) == 0) ? 1 : 0"}});
    }
    else if ((cond == cbc::n) || (cond == cbc::ni))
    {
	code.push_back({"setCond", {"(reg_isr & SrSign) ? 1 : 0"}});
    }
    else if ((cond == cbc::auz) || (cond == cbc::auzi))
    {
	code.push_back({"setCond", {"(((reg_au & 0x3F) == 0) ? 1 : 0)"}});
    }
    else if (cond == cbc::v)
    {
	code.push_back({"setCond", {"(reg_isr & SrOverflow) ? 1 : 0"}});
    }
    else if ((cond == cbc::cc) || (cond == cbc::cci))
    {
	int c = ((ir_val >> 8) & 0xF);

	switch (c)
	{
	    case 0x0:
	    {
		code.push_back({"setCond", {"1"}});
	    }
	    break;
	    case 0x1:
	    {
		code.push_back({"setCond", {"0"}});
	    }
	    break;
	    case 0x2:
	    {
		code.push_back({"setCond", {"((reg_sr & (SrCarry | SrZero)) == 0) ? 1 : 0"}});
	    }
	    break;
	    case 0x3:
	    {
		code.push_back({"setCond", {"((reg_sr & (SrCarry | SrZero)) != 0) ? 1 : 0"}});
	    }
	    break;
	    case 0x4:
	    {
		code.push_back({"setCond", {"(reg_sr & SrCarry) ? 0 : 1"}});
	    }
	    break;
	    case 0x5:
	    {
		code.push_back({"setCond", {"(reg_sr & SrCarry) ? 1 : 0"}});
	    }
	    break;
	    case 0x6:
	    {
		code.push_back({"setCond", {"(reg_sr & SrZero) ? 0 : 1"}});
	    }
	    break;
	    case 0x7:
	    {
		code.push_back({"setCond", {"(reg_sr & SrZero) ? 1 : 0"}});
	    }
	    break;
	    case 0x8:
	    {
		code.push_back({"setCond", {"(reg_sr & SrOverflow) ? 0 : 1"}});
	    }
	    break;
	    case 0x9:
	    {
		code.push_back({"setCond", {"(reg_sr & SrOverflow) ? 1 : 0"}});
	    }
	    break;
	    case 0xA:
	    {
		code.push_back({"setCond", {"(reg_sr & SrSign) ? 0 : 1"}});
	    }
	    break;
	    case 0xB:
	    {
		code.push_back({"setCond", {"(reg_sr & SrSign) ? 1 : 0"}});
	    }
	    break;
	    case 0xC:
	    {
		code.push_back({"setCond", {"(((reg_sr & (SrSign | SrOverflow)) == (SrSign | SrOverflow)) || ((reg_sr & (SrSign | SrOverflow)) == 0)) ? 1 : 0"}});
	    }
	    break;
	    case 0xD:
	    {
		code.push_back({"setCond", {"(((reg_sr & (SrSign | SrOverflow)) == SrSign) || ((reg_sr & SrOverflow) == 0)) ? 1 : 0"}});
	    }
	    break;
	    case 0xE:
	    {
		code.push_back({"setCond", {"(((reg_sr & (SrSign | SrOverflow | SrZero)) == (SrSign | SrOverflow)) || ((reg_sr & (SrSign | SrOverflow | SrZero)) == 0)) ? 1 : 0"}});
	    }
	    break;
	    case 0xF:
	    {
		code.push_back({"setCond", {"(((reg_sr & SrZero) != 0) || ((reg_sr & (SrSign | SrOverflow)) == SrSign) || ((reg_sr & (SrSign | SrOverflow)) == SrOverflow)) ? 1 : 0"}});
	    }
	    break;
	    default:
	    {
		cout << "Unrecognized cc/cci condition value of " << hex << int(c) << endl;
		throw runtime_error("Codegen error");
	    }
	    break;
	}
    }
    else if ((cond == cbc::z) || (cond == cbc::ze))
    {
	code.push_back({"setCond", {"(reg_isr & SrZero) ? 1 : 0"}});
    }
    else if ((cond == cbc::c) || (cond == cbc::ci))
    {
	code.push_back({"setCond", {"(reg_isr & SrCarry) ? 1 : 0"}});
    }
    else if ((cond == cbc::n) || (cond == cbc::ni))
    {
	code.push_back({"setCond", {"(reg_isr & SrSign) ? 1 : 0"}});
    }
    else if (cond == cbc::nz1)
    {
	code.push_back({"setCond", {"(reg_isr & SrZero) ? 2 : (reg_isr & SrSign) ? 1 : 0"}});
    }
    else if (cond == cbc::nz2)
    {
	code.push_back({"setCond", {"(reg_isr & (SrZero | SrSign)) ? 1 : 0"}});
    }
    else if ((cond == cbc::enl) || (cond == cbc::enli))
    {
	code.push_back({"setCond", {"(reg_movemr == 0)"}});
    }
    else if (cond == cbc::ms0)
    {
	code.push_back({"setCond", {"testbit(reg_alue, 0) ? 1 : 0"}});
    }
    else if ((cond == cbc::m01) && !testbit(ir_val, 8))
    {
	code.push_back({"setCond", {"((reg_au & 0x3F) == 0) ? 0 : testbit(reg_alue, 1) ? 1 : 2"}});
    }
    else if ((cond == cbc::m01) && testbit(ir_val, 8))
    {
	code.push_back({"setCond", {"((reg_au & 0x3F) == 0) ? 0 : ((reg_alue & 0x3) == 1) ? 1 : ((reg_alue & 0x3) == 2) ? 2 : 3"}});
    }
    else if (cond != -1)
    {
	cout << "Unknown condition of " << dec << int(cond) << endl;
	throw runtime_error("Codegen error");
    }

    // T3

    if (nano_dec.dob_ctrl != 0)
    {
	string arg = "set";

	if (nano_dec.no_high_byte || ir_dec.is_byte)
	{
	    arg = "set8ExLow";
	}
	else if (nano_dec.no_low_byte)
	{
	    arg = "set8ExHigh";
	}

	switch (nano_dec.dob_ctrl)
	{
	    case 1:
	    {
		code.push_back({arg, {getInt(dbout), getInt(abd)}});
	    }
	    break;
	    case 2:
	    {
		code.push_back({arg, {getInt(dbout), getInt(dbd)}});
	    }
	    break;
	    case 3:
	    {
		code.push_back({arg, {getInt(dbout), getInt(aluo)}});
	    }
	    break;
	    default:
	    {
		cout << "Unrecognized dob control of " << dec << int(nano_dec.dob_ctrl) << endl;
		throw runtime_error("Codegen error");
	    }
	    break;
	}
    }

    if (nano_dec.upd_ssw)
    {
	code.push_back({"updateSSW"});
    }

    if (drop_critical)
    {
	code.push_back({"dropCritical"});
    }

    if (nano_dec.tvn_2_ftu)
    {
	if ((tvn != -1) && (tvn != 1))
	{
	    code.push_back({"trap", {getInt(tvn)}});
	}
	else if (tvn == 1)
	{
	    code.push_back({"trap", {"int-tvn"}});
	}
	else if (ir_dec.macro_tvn == 1)
	{
	    code.push_back({"trap", {"trap-tvn"}});
	}
	else
	{
	    code.push_back({"trap", {getInt(ir_dec.macro_tvn)}});
	}
    }

    bool dbl_2_pcl = (nano_dec.dbl_2_reg && nano_dec.pcl_dbl);
    bool dbh_2_pch = (nano_dec.dbh_2_reg && nano_dec.pch_dbh);
    bool abl_2_pcl = (nano_dec.abl_2_reg && nano_dec.pcl_abl);
    bool abh_2_pch = (nano_dec.abh_2_reg && nano_dec.pch_abh);

    if (nano_dec.dbd_2_alub)
    {
	code_to_sort.push_back({"set", {getInt(alub), getInt(dbd)}});
    }
    else if (nano_dec.abd_2_alub)
    {
	code_to_sort.push_back({"set", {getInt(alub), getInt(abd)}});
    }

    if (nano_dec.dbd_2_alue)
    {
	code_to_sort.push_back({"set", {getInt(alue), getInt(dbd)}});
    }

    if (nano_dec.au_2_pc)
    {
	code_to_sort.push_back({"set", {getInt(pcl), getInt(aul)}});
    }
    else if (dbl_2_pcl && dbh_2_pch)
    {
	deque<string> args = {getInt(pcl)};

	for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
	{
	    args.push_back(arg);
	}

	code_to_sort.push_back({"set", args});
    }
    else if (abl_2_pcl && abh_2_pch)
    {
	deque<string> args = {getInt(pcl)};

	for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
	{
	    args.push_back(arg);
	}

	code_to_sort.push_back({"set", args});
    }
    else
    {
	if (dbl_2_pcl && (dbl != -1))
	{
	    code_to_sort.push_back({"set16Low", {getInt(pcl), getInt(dbl)}});
	}

	if (abl_2_pcl && (abl != -1))
	{
	    code_to_sort.push_back({"set16Low", {getInt(pcl), getInt(abl)}});
	}

	if (dbh_2_pch && (dbl != -1))
	{
	    code_to_sort.push_back({"set16High", {getInt(pch), getInt(dbh)}});
	}

	if (abh_2_pch && (abl != -1))
	{
	    code_to_sort.push_back({"set16High", {getInt(pch), getInt(abh)}});
	}
    }

    if (nano_dec.abd_2_dcr)
    {
	code_to_sort.push_back({"set", {getInt(dcr), getInt(abd)}});
    }

    if (nano_dec.abl_2_atl && nano_dec.abh_2_ath)
    {
	deque<string> args = {getInt(atl)};

	for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
	{
	    args.push_back(arg);
	}

	code_to_sort.push_back({"set", args});
    }
    else if (nano_dec.dbl_2_atl && nano_dec.dbh_2_ath)
    {
	deque<string> args = {getInt(atl)};

	for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
	{
	    args.push_back(arg);
	}

	code_to_sort.push_back({"set", args});
    }
    else
    {
	if (nano_dec.dbl_2_atl && (dbl != -1))
	{
	    code_to_sort.push_back({"set16Low", {getInt(atl), getInt(dbl)}});
	}

	if (nano_dec.abl_2_atl && (abl != -1))
	{
	    code_to_sort.push_back({"set16Low", {getInt(atl), getInt(abl)}});
	}

	if (nano_dec.dbh_2_ath && (dbh != -1))
	{
	    code_to_sort.push_back({"set16High", {getInt(ath), getInt(dbh)}});
	}

	if (nano_dec.abh_2_ath && (abh != -1))
	{
	    code_to_sort.push_back({"set16High", {getInt(ath), getInt(abh)}});
	}
    }

    bool is_byte_access = (nano_dec.adb_is_byte && ir_dec.is_byte);

    if (nano_dec.dbl_2_rxl)
    {
	if (rx == dxl)
	{
	    if (nano_dec.dbh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(dbh, dbd, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.abh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(abh, dbd, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(rx), getInt(dbd)}});
	    }
	}
	else
	{
	    if (nano_dec.dbh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.abh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(abh, dbl, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(rx), getInt(dbl)}});
	    }
	}
    }
    else if (nano_dec.abl_2_rxl)
    {
	if (rx == dxl)
	{
	    if (is_byte_access)
	    {
		code_to_sort.push_back({"set8", {getInt(rx), getInt(abd)}});
	    }
	    else if (nano_dec.abh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(abh, abd, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.dbh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(dbh, abd, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(rx), getInt(abd)}});
	    }
	}
	else
	{
	    if (nano_dec.abh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.dbh_2_rxh)
	    {
		deque<string> args = {getInt(rx)};

		for (auto &arg : maybeMerge(dbh, abl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(rx), getInt(abl)}});
	    }
	}
    }
    else if (nano_dec.dbh_2_rxh)
    {
	code_to_sort.push_back({"set16High", {getInt(rx), getInt(dbh)}});
    }
    else if (nano_dec.abh_2_rxh)
    {
	code_to_sort.push_back({"set16High", {getInt(rx), getInt(abh)}});
    }

    if (nano_dec.dbl_2_ryl)
    {
	if (ry == dyl)
	{
	    if (nano_dec.dbh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(dbh, dbd, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.abh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(abh, dbd, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(ry), getInt(dbd)}});
	    }
	}
	else
	{
	    if (nano_dec.dbh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.abh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(abh, dbl, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(ry), getInt(dbd)}});
	    }
	}
    }
    else if (nano_dec.abl_2_ryl)
    {
	if (ry == dyl)
	{
	    if (is_byte_access)
	    {
		code_to_sort.push_back({"set8", {getInt(ry), getInt(abd)}});
	    }
	    else if (nano_dec.abh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(abh, abd, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.dbh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(dbh, abd, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(ry), getInt(abd)}});
	    }
	}
	else
	{
	    if (nano_dec.abh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else if (nano_dec.dbh_2_ryh)
	    {
		deque<string> args = {getInt(ry)};

		for (auto &arg : maybeMerge(dbh, abl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    else
	    {
		code_to_sort.push_back({"set16Low", {getInt(ry), getInt(abl)}});
	    }
	}
    }
    else if (nano_dec.dbh_2_ryh)
    {
	code_to_sort.push_back({"set16High", {getInt(ry), getInt(dbh)}});
    }
    else if (nano_dec.abh_2_ryh)
    {
	code_to_sort.push_back({"set16High", {getInt(ry), getInt(abh)}});
    }

    if (nano_dec.inl_2_psw)
    {
	if (tvn == 1)
	{
	    code_to_sort.push_back({"setSRI", {}});
	}
	else
	{
	    code_to_sort.push_back({"setSRI7", {}});
	}
    }

    if (nano_dec.tvn_2_ftu)
    {
	if (tvn != -1)
	{
	    if (tvn == 1)
	    {
		code_to_sort.push_back({"set", {getInt(ftu), "int-tvn"}});
	    }
	    else
	    {
		code_to_sort.push_back({"set", {getInt(ftu), "ct", getInt(tvn << 2)}});
	    }
	}
	else
	{
	    if (ir_dec.macro_tvn == 1)
	    {
		code_to_sort.push_back({"set", {getInt(ftu), "trap-tvn"}});
	    }
	    else
	    {
		code_to_sort.push_back({"set", {getInt(ftu), "ct", getInt(ir_dec.macro_tvn << 2)}});
	    }
	}
    }

    if (nano_dec.ird_2_ftu)
    {
	code_to_sort.push_back({"set", {getInt(ftu), getInt(ird)}});
    }

    if (nano_dec.sr_2_ftu)
    {
	code_to_sort.push_back({"set", {getInt(ftu), getInt(sr)}});
    }

    if (nano_dec.abl_2_pren)
    {
	code_to_sort.push_back({"set", {getInt(ftu), getInt(abl)}});
    }

    if (nano_dec.psw_i_2_ftu)
    {
	code_to_sort.push_back({"set", {getInt(ftu), "ftu-i"}});
    }

    if (nano_dec.ssw_2_ftu)
    {
	code_to_sort.push_back({"set", {getInt(ftu), "ftu-ssw"}});
    }

    if (nano_dec.ftu_2_sr && !ir_dec.to_ccr)
    {
	assert(nano_dec.ftu_2_ccr);
	if (nano_dec.wait_bus_finish)
	{
	    code_to_sort.push_back({"setSRD", {getInt(sr), getInt(ftu)}});
	}
	else
	{
	    code_to_sort.push_back({"setSR", {getInt(sr), getInt(ftu)}});
	}
    }
    else if (nano_dec.ftu_2_ccr)
    {
	code_to_sort.push_back({"setCCR", {getInt(sr), getInt(ftu)}});
    }


    // T4

    if (nano_dec.au_clk_en)
    {
	int au_ctrl = nano_dec.au_ctrl;

	switch (au_ctrl)
	{
	    case 0:
	    {
		if (dbh != -1)
		{
		    deque<string> args = {getInt(aul)};

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }

		    code_to_sort.push_back({"set", args});
		}
		else
		{
		    code_to_sort.push_back({"set", {getInt(aul), "ext32", getInt(dbl)}});
		}
	    }
	    break;
	    case 1:
	    {
		deque<string> args = {getInt(aul), "+c"};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		args.push_back(getInt(2));

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 2:
	    {
		deque<string> args = {getInt(aul), "+c"};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		args.push_back(getInt(-4));

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 3:
	    {
		deque<string> args = {getInt(aul), "+c"};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		args.push_back(getInt(-2));

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 4:
	    {
		deque<string> args = {getInt(aul)};
		if (nano_dec.no_sp_align)
		{
		    args.push_back("+c");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }	

		    args.push_back(getInt(1));
		}
		else if (!ir_dec.is_byte)
		{
		    args.push_back("+c");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }	

		    args.push_back(getInt(2));
		}
		else if (nano_dec.rxl_2_db)
		{
		    args.push_back("+1/2");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }

		    args.push_back("rx_index");
		}
		else
		{
		    args.push_back("+1/2");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }

		    args.push_back("ry_index");
		}

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 5:
	    {
		deque<string> args = {getInt(aul), "+c"};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		args.push_back(getInt(4));

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 6:
	    {
		deque<string> args = {getInt(aul), "+r"};

		for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		{
		    args.push_back(arg);
		}

		for (auto &arg : maybeMerge(abh, abl, is_ext_abh))
		{
		    args.push_back(arg);
		}

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    case 7:
	    {
		deque<string> args = {getInt(aul)};
		if (nano_dec.no_sp_align)
		{
		    args.push_back("+c");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }	

		    args.push_back(getInt(-1));
		}
		else if (!ir_dec.is_byte)
		{
		    args.push_back("+c");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }	

		    args.push_back(getInt(-2));
		}
		else if (nano_dec.rxl_2_db)
		{
		    args.push_back("-1/2");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }

		    args.push_back("rx_index");
		}
		else
		{
		    args.push_back("-1/2");

		    for (auto &arg : maybeMerge(dbh, dbl, is_ext_dbh))
		    {
			args.push_back(arg);
		    }

		    args.push_back("ry_index");
		}

		code_to_sort.push_back({"set", args});
	    }
	    break;
	    default:
	    {
		cout << "Unrecognized au_ctrl of " << dec << int(au_ctrl) << endl;
		throw runtime_error("Codegen error");
	    }
	    break;
	}
    }

    if (alu_op != alu::none)
    {
	if (nano_dec.ftu_2_ccr || ir_dec.no_ccr_en || (!(alu_info & (aluinfo::init | aluinfo::finish))))
	{
	    alu_mask = 0;
	}

	if (((nano_dec.alu_actrl != 0) || (abd != -1) || (alu_op == alu::over)) && is_single_param.at(alu_op))
	{
	    deque<string> args = {getInt(alu_op), getInt(alu_mask), getInt(alu_info)};

	    if (alu_op == alu::over)
	    {
		if (abd != -1)
		{
		    args.push_back(getInt(abd));
		}
		else
		{
		    // ["c", 0]
		    args.push_back("c0");
		}
	    }
	    else if (nano_dec.alu_actrl != 0)
	    {
		args.push_back(getInt(alub));
	    }
	    else
	    {
		args.push_back(getInt(abd));
	    }

	    code_to_sort.push_back({"alu", args});
	}
	else if (((nano_dec.alu_actrl != 0) || (abd != -1)) && ((nano_dec.alu_dctrl == 2) || (nano_dec.alu_dctrl == 3) || ((nano_dec.alu_dctrl == 0) && (dbd != -1))))
	{
	    deque<string> args = {getInt(alu_op), getInt(alu_mask), getInt(alu_info)};

	    if (nano_dec.alu_actrl != 0)
	    {
		args.push_back(getInt(alub));
	    }
	    else
	    {
		args.push_back(getInt(abd));
	    }

	    if (nano_dec.alu_dctrl == 0)
	    {
		args.push_back(getInt(dbd));
	    }
	    else if (nano_dec.alu_dctrl == 2)
	    {
		args.push_back("c0");
	    }
	    else
	    {
		args.push_back("c1");
	    }

	    code_to_sort.push_back({"alu", args});
	}
	else if ((alu_op == alu::and_) && (nano_dec.alu_dctrl == 2))
	{
	    deque<string> args = {getInt(alu_op), getInt(alu_mask), getInt(alu_info), "c0", "c0"};
	    code_to_sort.push_back({"alu", args});
	}
    }

    sortAndAppend(code_to_sort, code);

    if (nano_dec.wait_bus_finish)
    {
	code.push_back({"setBusEnd", {getBool(nano_dec.ftu_2_sr && !ir_dec.to_ccr)}});
    }

    if (nano_dec.to_irc)
    {
	code.push_back({"set", {getInt(irc), getInt(edb)}});
    }

    if (nano_dec.to_dbin)
    {
	if (nano_dec.no_high_byte)
	{
	    code.push_back({"set8", {getInt(dbin), getInt(edb)}});
	}
	else if (nano_dec.no_low_byte)
	{
	    code.push_back({"set8High", {getInt(dbin), getInt(edb)}});
	}
	else
	{
	    code.push_back({"set", {getInt(dbin), getInt(edb)}});
	}
    }

    if (nano_dec.const_2_ftu)
    {
	code.push_back({"state", {"setFTUConst"}});
    }

    if (nano_dec.upd_pren)
    {
	if (ir_dec.movem_pre_decr)
	{
	    code.push_back({"state", {"stepMovemPredec"}});
	}
	else
	{
	    code.push_back({"state", {"stepMovem"}});
	}
    }

    if (!(nano_dec.perm_start || nano_dec.wait_bus_finish))
    {
	code.push_back({"step"});
    }

    if (nano_dec.upd_tp_end)
    {
	code.push_back({"setTrace"});
    }
    else if (nano_dec.clr_tp_end)
    {
	code.push_back({"clearTrace"});
    }

    return code;
}

typedef vector<deque<KujoCodeLine>> kujocode;

kujocode genKujocode(vector<KujoM68KBlock> blocks, uint16_t ir, uint16_t ir_mask, int tvn, bool priv, bool group01)
{
    kujocode code;

    for (size_t i = 0; i < blocks.size(); i++)
    {
	KujoM68KBlock block = blocks.at(i);
	deque<KujoCodeLine> cb;

	if (i != 0)
	{
	    cb.push_back({"label", {labelName(block.val)}});
	}
	else if (priv)
	{
	    cb.push_back({"priv"});
	}

	for (auto &addr : block.block_val)
	{
	    auto code = genBaseCode(ir, ir_mask, addr, tvn, group01);

	    for (auto &ci : code)
	    {
		cb.push_back(ci);
	    }
	}

	if (!block.last)
	{
	    if (block.extra.empty())
	    {
		if (cb.back().tag != "setTrace")
		{
		    cb.push_back({"nextInst"});
		}
		else
		{
		    cb.back() = {"nextTrace"};
		}
	    }
	    else if (getValue(block.extra.at(0)) == i)
	    {
		assert(cb.back().tag == "step");
		cb.back() = {"halt"};
	    }
	    else
	    {
		int index = getValue(block.extra.at(0));
		cb.push_back({"goto", {labelName(blocks.at(index).val)}});
	    }
	}
	else
	{
	    deque<string> args;
	    for (auto &ex : block.extra)
	    {
		uint16_t val = getValue(ex);
		args.push_back(labelName(blocks.at(val).val));
	    }

	    cb.push_back({"cgoto", args});
	}

	code.push_back(cb);
    }

    return code;
}

void propagate(vector<KujoM68KBlock> blocks, kujocode &code, map<int, bool> &seen, deque<string> bus_access, int i, int &cycle, bool &critical)
{
    if (seen.find(i) != seen.end())
    {
	return;
    }

    seen[i] = true;
    for (auto &ci : code.at(i))
    {
	if (ci.tag == "step")
	{
	    ci.args.push_back(getInt(cycle));

	    if (cycle == 1)
	    {
		cycle += 1;
	    }
	    else
	    {
		cycle += 2;
	    }
	}
	else if (ci.tag == "setBus")
	{
	    bus_access = ci.args;
	    ci.args.push_back(getBool(critical));
	}
	else if (ci.tag == "setBusEnd")
	{
	    auto sr_update = ci.args.front();
	    ci.args.pop_front();

	    ci.args.push_back(getInt(cycle));

	    for (auto &arg : bus_access)
	    {
		ci.args.push_back(arg);
	    }

	    ci.args.push_back(sr_update);
	    cycle += 1;
	}
	else if (ci.tag == "dropCritical")
	{
	    critical = false;
	}
    }

    for (auto &nc : blocks.at(i).extra)
    {
	propagate(blocks, code, seen, bus_access, getValue(nc), cycle, critical);
    }
}

void propagateBusAccess(vector<KujoM68KBlock> blocks, kujocode &code, bool critical)
{
    map<int, bool> seen = {};
    deque<string> bus_access;
    int cycle = 1;
    propagate(blocks, code, seen, bus_access, 0, cycle, critical);
}

void fromReg(string val, unordered_map<string, string> &usage)
{
    if ((val == getInt(axl)) || (val == getInt(axh)))
    {
	if (usage.at("rx") == "d")
	{
	    cout << "Collision d -> a on rx" << endl;
	    throw runtime_error("Codegen error");
	}

	usage.at("rx") = "a";
    }

    if ((val == getInt(dxl)) || (val == getInt(dxh)))
    {
	if (usage.at("rx") == "a")
	{
	    cout << "Collision a -> d on rx" << endl;
	    throw runtime_error("Codegen error");
	}

	usage.at("rx") = "d";
    }

    if ((val == getInt(ayl)) || (val == getInt(ayh)))
    {
	if (usage.at("ry") == "d")
	{
	    cout << "Collision d -> a on ry" << endl;
	    throw runtime_error("Codegen error");
	}

	usage.at("ry") = "a";
    }

    if ((val == getInt(dyl)) || (val == getInt(dyh)))
    {
	if (usage.at("ry") == "a")
	{
	    cout << "Collision a -> d on ry" << endl;
	    throw runtime_error("Codegen error");
	}

	usage.at("ry") = "d";
    }
}

void inExpression(string arg, unordered_map<string, string> &usage)
{
    fromReg(arg, usage);
}

void inExpression(deque<string> args, unordered_map<string, string> &usage, int &num_args)
{
    if (args.empty())
    {
	return;
    }

    if (args.size() == 1)
    {
	num_args = 1;
	inExpression(args.at(0), usage);
    }
    else if ((args.at(0) == "+c") || (args.at(0) == "+1/2") || (args.at(0) == "-1/2") || (args.at(0) == "ext32") || (args.at(0) == "ext32High"))
    {
	num_args = 2;
	inExpression(args.at(1), usage);
    }
    else if ((args.at(0) == "+r") || (args.at(0) == "merge"))
    {
	int nargs = 0;
	auto args2 = args;
	args2.pop_front();

	inExpression(args2, usage, nargs);

	for (int i = 0; i < nargs; i++)
	{
	    args2.pop_front();
	}

	num_args = nargs;

	inExpression(args2, usage, nargs);

	num_args += nargs;
    }
    else if ((args.at(0) >= getInt(axl)) && (args.at(0) <= getInt(movemr)))
    {
	num_args = 1;
	inExpression(args.at(0), usage);
    }
}

void inExpression(deque<string> args, unordered_map<string, string> &usage)
{
    int num_args = 0;
    inExpression(args, usage, num_args);
}

unordered_map<string, string> analyzeRegisterUsage(kujocode code)
{
    unordered_map<string, string> reg_usage;
    reg_usage["rx"] = "false";
    reg_usage["ry"] = "false";
    reg_usage["t"] = "false";

    for (auto &cib : code)
    {
	for (auto &ci : cib)
	{
	    string tag = ci.tag;

	    if ((tag == "set") || (tag == "setSR") || (tag == "setSRD") || (tag == "setCCR") || (tag == "set8") || (tag == "set16Low") || (tag == "set16High") || (tag == "set8ExLow") || (tag == "set8ExHigh") || (tag == "set8High"))
	    {
		auto args = ci.args;
		args.pop_front();

		fromReg(ci.args.at(0), reg_usage);
		inExpression(args, reg_usage);
	    }

	    if (tag == "setCond")
	    {
		reg_usage["t"] = "true";
	    }
	    if ((tag == "setSRI") || (tag == "setSRI7"))
	    {
		fromReg(getInt(sr), reg_usage);
	    }
	    else if (tag == "alu")
	    {
		inExpression(ci.args.at(3), reg_usage);

		if (ci.args.size() > 4)
		{
		    inExpression(ci.args.at(4), reg_usage);
		}
	    }
	}
    }

    return reg_usage;
}

bool isHigh16(int reg)
{
    return ((reg > moveml) && (reg <= movemh));
}

string makeExpression(string arg)
{
    if ((arg == "") || (arg == "-1"))
    {
	return "0";
    }

    if (arg == "ftu-i")
    {
	return "(0xfff0 | ((next_state >> 23) & 0xE))";
    }
    else if (arg == "ftu-ssw")
    {
	return "((reg_ftu & ~0x1F) | reg_ssw)";
    }
    else if (arg == "trap-tvn")
    {
	return "0x80 | ((reg_ird & 0xF) << 2)";
    }
    else if (arg == "int-tvn")
    {
	return "reg_int_vec";
    }
    else if (arg == "c0")
    {
	return "0x0000";
    }
    else if (arg == "c1")
    {
	return "0xFFFF";
    }
    else
    {
	int reg = toInt(arg);

	if (reg == dcro)
	{
	    return "(1 << (reg_dcr & 0xF))";
	}
	else if (reg == dcro8)
	{
	    return "(1 << (reg_dcr & 0x7))";
	}
	else if (isHigh16(reg))
	{
	    stringstream ss;
	    ss << "high16(" << regname.at(reg) << ")";
	    return ss.str();
	}
	else
	{
	    return regname.at(reg);
	}
    }
}

string makeExpression(deque<string> args, int &num_args)
{
    if (args.at(0) == "ct")
    {
	num_args = 2;
	int val = toInt(args.at(1));
	stringstream ss;
	ss << "0x" << hex << setw(4) << setfill('0') << int(val);
	return ss.str();
    }
    else if (args.at(0) == "c0")
    {
	num_args = 1;
	return "0x0000";
    }
    else if (args.at(0) == "c1")
    {
	num_args = 1;
	return "0xFFFF";
    }
    else if (args.at(0) == "+c")
    {
	int val = toInt(args.back());

	int alu_args = 0;

	auto ci = args;
	ci.pop_front();
	ci.pop_back();

	if (val < 0)
	{
	    stringstream ss;
	    ss << makeExpression(ci, alu_args) << " - " << dec << int(-val);
	    num_args = (2 + alu_args);
	    return ss.str();
	}
	else
	{
	    stringstream ss;
	    ss << makeExpression(ci, alu_args) << " + " << dec << int(val);
	    num_args = (2 + alu_args);
	    return ss.str();
	}
    }
    else if (args.at(0) == "+1/2")
    {
	int args0 = 0;
	auto ci = args;
	ci.pop_front();

	string arg0 = makeExpression(ci, args0);

	stringstream ss;
	ss << arg0 << " - ((" << args.back() << " < 15) ? 1 : 2)";

	num_args = (args0 + 1);
	return ss.str();
    }
    else if (args.at(0) == "-1/2")
    {
	int args0 = 0;
	auto ci = args;
	ci.pop_front();

	string arg0 = makeExpression(ci, args0);

	stringstream ss;
	ss << arg0 << " - ((" << args.back() << " < 15) ? 1 : 2)";

	num_args = (args0 + 1);
	return ss.str();
    }
    else if (args.at(0) == "+r")
    {
	int args0 = 0;
	auto ci = args;
	ci.pop_front();

	string arg0 = makeExpression(ci, args0);

	for (int i = 0; i < args0; i++)
	{
	    ci.pop_front();
	}

	int args1 = 0;

	string arg1 = makeExpression(ci, args1);

	stringstream ss;
	ss << arg0 << " + " << arg1;
	num_args = (1 + args0 + args1);
	return ss.str();
    }
    else if (args.at(0) == "merge")
    {
	num_args = 3;
	stringstream ss;
	ss << "merge32(" << makeExpression(args.at(1)) << ", " << makeExpression(args.at(2)) << ")";
	return ss.str();
    }
    else if (args.at(0) == "ext32")
    {
	num_args = 2;
	stringstream ss;
	ss << "ext32(" << makeExpression(args.at(1)) << ")";
	return ss.str();
    }
    else if (args.size() == 1)
    {
	num_args = 1;
	return makeExpression(args.at(0));
    }
    else if ((toInt(args.at(0)) >= 0) && (toInt(args.at(0)) <= 42))
    {
	num_args = 1;
	return makeExpression(args.at(0));
    }
    else
    {
	cout << "Unknown expression type" << endl;

	for (auto &arg : args)
	{
	    cout << arg << endl;
	}

	throw runtime_error("Codegen error");

	return "";
    }
}

string makeExpression(deque<string> args)
{
    int num_args = 0;
    return makeExpression(args, num_args);
}

array<string, 2> getALUName(string alu_op, string alu_mask, string alu_info)
{
    int op = toInt(alu_op);

    stringstream alu_ss;
    alu_ss << alu_opnames.at(op);

    int info = toInt(alu_info);

    if (((info & aluinfo::is_long) != 0) && ((op == alu::asl) || (op == alu::asr) || (op == alu::lsl) || (op == alu::lsr) || (op == alu::rol) || (op == alu::ror) || (op == alu::roxl) || (op == alu::roxr)))
    {
	alu_ss << "Long";

	if ((info & aluinfo::is_mul) != 0)
	{
	    if ((info & aluinfo::mul_signed) != 0)
	    {
		alu_ss << "Ms";
	    }
	    else
	    {
		alu_ss << "Mu";
	    }
	}
    }
    else if (((info & aluinfo::is_byte) != 0) && (op != alu::ext))
    {
	alu_ss << "Byte";
    }

    if ((op == alu::and_) && ((info & aluinfo::is_rox_and) != 0))
    {
	alu_ss << "x";
    }

    string flags = "";

    int mask = toInt(alu_mask);

    if (mask != 0)
    {
	stringstream flags_ss;

	if (testbit(mask, 4))
	{
	    flags_ss << "X";
	}

	if (testbit(mask, 3))
	{
	    flags_ss << "N";
	}

	if (testbit(mask, 2))
	{
	    flags_ss << "Z";
	}

	if (testbit(mask, 1))
	{
	    flags_ss << "V";
	}

	if (testbit(mask, 0))
	{
	    flags_ss << "C";
	}

	if ((info & (aluinfo::finish | aluinfo::arx)) != 0)
	{
	    flags_ss << "U";
	}

	flags = flags_ss.str();
    }

    return {alu_ss.str(), flags};
}

vector<string> generateCode(kujocode code, bool &is_step)
{
    is_step = false;
    vector<string> source;

    auto usage = analyzeRegisterUsage(code);

    if (usage.at("rx") == "d")
    {
	source.push_back("    rx_index = ((reg_irdi >> 9) & 0x7);");
    }
    else if (usage.at("rx") == "a")
    {
	source.push_back("    rx_index = mapSP(((reg_irdi >> 9) & 0x7) | 8);");
    }

    if (usage.at("ry") == "d")
    {
	source.push_back("    ry_index = (reg_irdi & 0x7);");
    }
    else if (usage.at("ry") == "a")
    {
	source.push_back("    ry_index = mapSP((reg_irdi & 0x7) | 8);");
    }

    source.push_back("    switch (inst_cycle)");
    source.push_back("    {");
    source.push_back("\tcase 0:");
    source.push_back("\t{");

    for (auto &cib : code)
    {
	for (auto &ci : cib)
	{
	    if (ci.tag == "comment")
	    {
		stringstream ss;
		ss << "\t    // " << ci.args.at(0);
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "setLines")
	    {
		continue;
	    }
	    else if (ci.tag == "step")
	    {
		auto cycle = toInt(ci.args.at(0));

		if (cycle == 1)
		{
		    is_step = true;
		}

		stringstream ss0;
		ss0 << "\t    inst_cycle = " << dec << int(cycle) << ";";
		source.push_back(ss0.str());
		source.push_back("\t}");
		source.push_back("\tbreak;");

		stringstream ss1;
		ss1 << "\tcase " << dec << int(cycle) << ":";
		source.push_back(ss1.str());
		source.push_back("\t{");


		if (cycle != 1)
		{

		stringstream ss2;
		ss2 << "\t    inst_cycle = " << dec << int(cycle + 1) << ";";
		source.push_back(ss2.str());
		source.push_back("\t}");
		source.push_back("\tbreak;");

		stringstream ss3;
		ss3 << "\tcase " << dec << int(cycle + 1) << ":";
		source.push_back(ss3.str());
		source.push_back("\t{");

		}
	    }
	    else if (ci.tag == "priv")
	    {
		source.push_back("\t    if (!testbit(reg_sr, 13))");
		source.push_back("\t    {");
		source.push_back("\t\tsetPriv();");
		source.push_back("\t\treturn;");
		source.push_back("\t    }");
		source.push_back("");
	    }
	    else if (ci.tag == "set")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    " << reg << " = " << expr << ";";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set8")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg8(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set8High")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg8High(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set8ExLow")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg8ExLow(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set8ExHigh")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg8ExHigh(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set16High")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg16High(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "set16Low")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    setReg16Low(" << reg << ", " << expr << ");";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "setSR")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    " << reg << " = reg_isr = (" << expr << " & 0xA71F);";
		source.push_back(ss.str());

		source.push_back("\t    updateSupervisor();");
		source.push_back("\t    updateInterrupts();");
	    }
	    else if (ci.tag == "setCCR")
	    {
		string reg = regname.at(toInt(ci.args.at(0)));
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    " << reg << " = reg_isr = ((" << expr << " & 0x1F) | (" << reg << " & 0xA700));";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "setSRD")
	    {
		auto args = ci.args;
		args.pop_front();
		string expr = makeExpression(args);

		stringstream ss;
		ss << "\t    reg_new_sr = reg_isr = (" << expr << " & 0xA71F);";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "setSRI")
	    {
		source.push_back("\t    reg_sr = ((reg_sr & ~0x700) | ((next_state >> 16) & 0x700));");
		source.push_back("\t    updateInterrupts();");
	    }
	    else if (ci.tag == "setSRI7")
	    {
		source.push_back("\t    reg_sr |= 0x700;");
		source.push_back("\t    updateInterrupts();");
	    }
	    else if (ci.tag == "setBus")
	    {
		stringstream ss0;
		ss0 << "\t    setFC(" << ci.args.at(0) << ", " << ci.args.at(1);

		if (toInt(ci.args.at(3)) == 0)
		{
		    ss0 << ", true";
		}
		else
		{
		    ss0 << ", false";
		}

		if (isTrue(ci.args.at(6)))
		{
		    ss0 << ", true";
		}
		else
		{
		    ss0 << ", false";
		}

		if (isTrue(ci.args.at(8)))
		{
		    ss0 << ", true";
		}
		else
		{
		    ss0 << ", false";
		}

		ss0 << ");";
		source.push_back(ss0.str());

		bool is_irq_vector_lookup = (toInt(ci.args.at(3)) == 0) && (isTrue(ci.args.at(0)) && isTrue(ci.args.at(1)));

		if (is_irq_vector_lookup)
		{
		    source.push_back("\t    startIRQVectorLookup();");
		}

		if (toInt(ci.args.at(3)) != 0)
		{
		    if (isTrue(ci.args.at(2)))
		    {
			if (isTrue(ci.args.at(7)))
			{
			    source.push_back("\t    writeRMC();");
			}
			else
			{
			    source.push_back("\t    writeByte();");
			}
		    }
		    else
		    {
			source.push_back("\t    writeWord();");
		    }
		}
		else
		{
		    if (isTrue(ci.args.at(0)) && isTrue(ci.args.at(1)))
		    {
			source.push_back("\t    readWordCPU();");
		    }
		    else if (isTrue(ci.args.at(2)))
		    {
			if (isTrue(ci.args.at(7)))
			{
			    source.push_back("\t    readRMC();");
			}
			else
			{
			    source.push_back("\t    readByte();");
			}
		    }
		    else
		    {
			source.push_back("\t    readWord();");
		    }
		}

		source.push_back("\t    startBus();");
	    }
	    else if (ci.tag == "setBusEnd")
	    {
		auto cycle = toInt(ci.args.at(0));

		stringstream ss1;
		ss1 << "\t    inst_cycle = " << dec << int(cycle) << ";";
		source.push_back(ss1.str());
		source.push_back("\t}");
		source.push_back("\tbreak;");

		stringstream ss2;
		ss2 << "\tcase " << dec << int(cycle) << ":";
		source.push_back(ss2.str());
		source.push_back("\t{");

		source.push_back("\t    if (!isBusEnd())");
		source.push_back("\t    {");
		source.push_back("\t\treturn;");
		source.push_back("\t    }");
		source.push_back("");
		source.push_back("\t    endBus();");

		bool is_irq_vector_lookup = (toInt(ci.args.at(4)) == 0) && (isTrue(ci.args.at(1)) && isTrue(ci.args.at(2)));

		if (is_irq_vector_lookup)
		{
		    source.push_back("\t    endIRQVectorLookup();");
		}

		if (isTrue(ci.args.at(9)))
		{
		    source.push_back("\t    reg_sr = reg_new_sr;");
		    source.push_back("\t    updateSupervisor();");
		    source.push_back("\t    updateInterrupts();");
		}
	    }
	    else if (ci.tag == "dropCritical")
	    {
		continue;
	    }
	    else if (ci.tag == "trap")
	    {
		string arg = ci.args.at(0);

		if ((arg == "trap-tvn") || (arg == "int-tvn"))
		{
		    stringstream ss;
		    ss << "\t    trapExcept(" << makeExpression(ci.args.at(0)) << ");";
		    source.push_back(ss.str());
		}
		else
		{
		    stringstream ss;
		    ss << "\t    trapExcept(0x" << hex << setw(2) << setfill('0') << int(toInt(ci.args.at(0))) << ");";
		    source.push_back(ss.str());
		}
	    }
	    else if (ci.tag == "halt")
	    {
		source.push_back("\t    return;");
	    }
	    else if (ci.tag == "state")
	    {
		stringstream ss;
		ss << "\t    " << ci.args.at(0) << "();";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "alu")
	    {
		auto names = getALUName(ci.args.at(0), ci.args.at(1), ci.args.at(2));

		int info = toInt(ci.args.at(2));
		int op = toInt(ci.args.at(0));

		if (ci.args.size() == 4)
		{
		    stringstream ss;
		    ss << "\t    alu" << names.at(0) << "(" << makeExpression(ci.args.at(3)) << ");";
		    source.push_back(ss.str());
		}
		else
		{
		    string expr = makeExpression(ci.args.at(4));

		    if ((expr == "0xFFFF") && (info & aluinfo::is_byte) && ((op != alu::and_) || (info & aluinfo::is_rox_and)))
		    {
			expr = "0xFF";
		    }

		    stringstream ss;
		    ss << "\t    alu" << names.at(0) << "(" << makeExpression(ci.args.at(3)) << ", " << expr << ");";
		    source.push_back(ss.str());
		}

		if (names.at(1) != "")
		{
		    stringstream ss2;
		    ss2 << "\t    update" << names.at(1) << "();";
		    source.push_back(ss2.str());
		}
	    }
	    else if (ci.tag == "setTrace")
	    {
		source.push_back("\t    setTrace();");
	    }
	    else if (ci.tag == "clearTrace")
	    {
		source.push_back("\t    clearTrace();");
	    }
	    else if (ci.tag == "nextInst")
	    {
		source.push_back("\t    nextInst();");
		source.push_back("\t    return;");
	    }
	    else if (ci.tag == "nextTrace")
	    {
		source.push_back("\t    nextTrace();");
		source.push_back("\t    return;");
	    }
	    else if (ci.tag == "setCond")
	    {
		stringstream ss;
		ss << "\t    reg_t = " << ci.args.at(0) << ";";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "label")
	    {
		stringstream ss;
		ss << "\t" << ci.args.at(0) << ":";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "goto")
	    {
		stringstream ss;
		ss << "\t    goto " << ci.args.at(0) << ";";
		source.push_back(ss.str());
	    }
	    else if (ci.tag == "cgoto")
 	    {
		if (ci.args.size() == 2)
		{
		    source.push_back("\t    if (reg_t)");
		    source.push_back("\t    {");
		    stringstream ss0;
		    ss0 << "\t\tgoto " << ci.args.at(1) << ";";
		    source.push_back(ss0.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else");
		    source.push_back("\t    {");
		    stringstream ss1;
		    ss1 << "\t\tgoto " << ci.args.at(0) << ";";
		    source.push_back(ss1.str());
		    source.push_back("\t    }");
		}
		else if (ci.args.size() == 3)
		{
		    source.push_back("\t    if (reg_t == 0)");
		    source.push_back("\t    {");
		    stringstream ss0;
		    ss0 << "\t\tgoto " << ci.args.at(0) << ";";
		    source.push_back(ss0.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else if (reg_t == 1)");
		    source.push_back("\t    {");
		    stringstream ss1;
		    ss1 << "\t\tgoto " << ci.args.at(1) << ";";
		    source.push_back(ss1.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else");
		    source.push_back("\t    {");
		    stringstream ss2;
		    ss2 << "\t\tgoto " << ci.args.at(2) << ";";
		    source.push_back(ss2.str());
		    source.push_back("\t    }");
		}
		else if (ci.args.size() == 4)
		{
		    source.push_back("\t    if (reg_t == 0)");
		    source.push_back("\t    {");
		    stringstream ss0;
		    ss0 << "\t\tgoto " << ci.args.at(0) << ";";
		    source.push_back(ss0.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else if (reg_t == 1)");
		    source.push_back("\t    {");
		    stringstream ss1;
		    ss1 << "\t\tgoto " << ci.args.at(1) << ";";
		    source.push_back(ss1.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else if (reg_t == 2)");
		    source.push_back("\t    {");
		    stringstream ss2;
		    ss2 << "\t\tgoto " << ci.args.at(2) << ";";
		    source.push_back(ss2.str());
		    source.push_back("\t    }");
		    source.push_back("\t    else");
		    source.push_back("\t    {");
		    stringstream ss3;
		    ss3 << "\t\tgoto " << ci.args.at(3) << ";";
		    source.push_back(ss3.str());
		    source.push_back("\t     }");
		}
	    }
	    else if (ci.tag == "updateSSW")
	    {
		source.push_back("\t    reg_ssw = (base_ssw | (testbit(reg_sr, 13) ? 0x4 : 0));");
	    }
	    else
	    {
		cout << "Unrecognized tag of " << ci.tag << endl;
		throw runtime_error("Codegen error");
	    }
	}
    }

    source.push_back("\t}");
    source.push_back("\tbreak;");
    source.push_back("\tdefault:");
    source.push_back("\t{");
    source.push_back("\t    unrecognizedState();");
    source.push_back("\t}");
    source.push_back("\tbreak;");
    source.push_back("    }");

    return source;
}

void genMicro(ostream &str, uint16_t a1, uint16_t a2, uint16_t a3, uint16_t ir, uint16_t ir_mask, int tvn, bool critical, bool priv, bool group01, bool &is_step)
{
    auto graph = genGraph(a1, a2, a3, ir);
    auto blocks = genBlocks(graph);

    /*
    cout << "Blocks: " << endl;

    cout << "[";

    for (auto biter = blocks.begin(); biter != blocks.end(); biter++)
    {
	if (biter != blocks.begin())
	{
	    cout << ", ";
	}

	auto block = *biter;

	cout << "[";

	cout << dec << int(block.val) << ", ";

	cout << "[";

	for (auto iter = block.block_val.begin(); iter != block.block_val.end(); iter++)
	{
	    if (iter != block.block_val.begin())
	    {
		cout << ", ";
	    }

	    auto val = *iter;
	    cout << dec << int(val);
	}

	cout << "], ";

	if (block.last)
	{
	    cout << dec << int(block.last.value());
	}
	else
	{
	    cout << "None";
	}

	cout << ", ";

	cout << "[";

	for (auto iter = block.extra.begin(); iter != block.extra.end(); iter++)
	{
	    if (iter != block.extra.begin())
	    {
		cout << ", ";
	    }

	    auto val = *iter;

	    if (val)
	    {
		cout << dec << int(val.value());
	    }
	    else
	    {
		cout << "None";
	    }
	}

	cout << "]";

	cout << "]";
    }

    cout << "]" << endl;
    */


    auto code = genKujocode(blocks, ir, ir_mask, tvn, priv, group01);

    propagateBusAccess(blocks, code, critical);
    /*
    cout << "Code: " << endl;

    for (auto &cib : code)
    {
	for (auto &ci : cib)
	{
	    cout << "[" << ci.tag;

	    if (!ci.args.empty())
	    {
		cout << ", ";

		for (auto iter = ci.args.begin(); iter != ci.args.end(); iter++)
		{
		    if (iter != ci.args.begin())
		    {
			cout << ", ";
		    }

		    auto val = *iter;
		    cout << val;
		}
	    }

	    cout << "]" << endl;
	}
    }
    */

    auto final_code = generateCode(code, is_step);

    for (auto &cib : final_code)
    {
	str << cib << endl;
    }
}

void generateMicrocode()
{
    for (int i = 0; i < 0x400; i++)
    {
	uint32_t mc = 0;
	for (int j = 0; j < 34; j++)
	{
	    auto entry = microcode_entry[j];

	    if ((i & entry.mask) == entry.val)
	    {
		mc = entry.code[(i & 0xF)];
		break;
	    }
	}

	microcode_table.push_back(mc);
    }
}

void generateNanocode()
{
    for (int i = 0; i < 0x400; i++)
    {
	array<uint32_t, 3> nc = {0, 0x10000, 0x0};

	for (int j = 0; j < 84; j++)
	{
	    auto entry = nanocode_entry[j];

	    if ((i & entry.mask) == entry.val)
	    {
		auto nanocode_addr = entry.code[(i & 0x3)];
		nc[0] = nanocode_addr[0];
		nc[1] = nanocode_addr[1];
		nc[2] = nanocode_addr[2];
		break;
	    }
	}

	nanocode_table.push_back(nc);
    }
}

struct KujoState
{
    uint16_t micro_addr = 0;
    string state_name;
    int tvn_val = 0;
    bool is_critical = false;
    bool is_implemented = false;
};

vector<KujoState> states = 
{
    {0x002, "reset", 0, true, true},
    {0x003, "busError", 2, true, false},
    {0x003, "addressError", 3, true, false},
    {0x001, "doubleFault", -1, false, true},
    {0x1C4, "interrupt", 1, false, true},
    {0x1C0, "trace", 9, false, false},
    {0x1C0, "illegal", 4, false, false},
    {0x1C0, "privilege", 8, false, false},
    {0x1C0, "lineA", 10, false, false},
    {0x1C0, "lineF", 11, false, false}
};

bool generateCodeForState(ostream &str, string val)
{
    bool is_step = false;
    KujoState select_state;
    for (auto &state : states)
    {
	if (state.state_name == val)
	{
	    select_state = state;
	    break;
	}
    }

    try
    {
	genMicro(str, select_state.micro_addr, 0x3FF, 0x3FF, 0xFFFF, 0, select_state.tvn_val, select_state.is_critical, false, true, is_step);
	return true;
    }
    catch (exception &ex)
    {
	return false;
    }
}

#include "instr_decode.inl"

bool generateCodeFromInstruction(ostream &str, uint16_t ir, uint16_t ir_mask, bool &is_step)
{
    if (((ir & 0xF000) == 0x6000) && (ir_mask == 0xFF00))
    {
	ir |= 0x0002;
    }

    uint16_t a1 = a1PalApply(ir);

    auto a2_a3 = a23PalApply(ir);

    uint16_t a2 = a2_a3[0];
    uint16_t a3 = a2_a3[1];

    try
    {
	genMicro(str, a1, a2, a3, ir, ir_mask, -1, false, privTest(ir), false, is_step);
	return true;
    }
    catch (exception &ex)
    {
	cout << ex.what() << endl;
	return false;
    }
}

void generateFunctionStart(ostream &str, string func_name)
{
    str << "void m68k" << func_name << "Program()" << endl;
    str << "{" << endl;
}

void generateFunctionEnd(ostream &str)
{
    str << "}" << endl;
    str << endl;
}

struct M68KHandler
{
    uint16_t opcode = 0;
    uint16_t opcode_mask = 0;
    uint16_t dec_op = 0;
    string handler_name;
};

string getInstructionName(vector<string> ii)
{
    string name0 = ii.at(0);

    replace(name0, ".b", "Byte");
    replace(name0, ".w", "Word");
    replace(name0, ".l", "Long");

    name0.at(0) = toupper(name0.at(0));

    string name1 = ii.at(1);
    name1.at(0) = toupper(name1.at(0));

    string name2 = ii.at(2);
    name2.at(0) = toupper(name2.at(0));

    stringstream ss;
    ss << name0;

    if (ii.at(1) != "-")
    {
	ss << name1;
    }

    if (ii.at(2) != "-")
    {
	ss << name2;
    }

    return ss.str();
}

string getStateFunctionName(string func_name)
{
    stringstream func_ss;
    func_name.at(0) = toupper(func_name.at(0));
    func_ss << func_name << "Dp";
    return func_ss.str();
}

string getStateFunctionName(M68KHandler handler)
{
    return getStateFunctionName(handler.handler_name);
}

void generateStateFunction(ostream &file, string func_name, string state_name)
{
    stringstream ss;
    generateFunctionStart(ss, getStateFunctionName(func_name));
    if (!generateCodeForState(ss, state_name))
    {
	generateCodeForState(ss, "doubleFault");
    }

    generateFunctionEnd(ss);
    file << ss.str();
}

void generateInstFunction(ofstream &file, M68KHandler handler, bool &is_step)
{
    cout << "Generating instruction of " << hex << int(handler.dec_op) << ", mask of " << hex << int(handler.opcode_mask) << endl;

    stringstream ss;
    ss << "// " << hex << setw(4) << setfill('0') << int(handler.opcode) << " " << hex << setw(4) << setfill('0') << int(handler.opcode_mask) << endl;
    generateFunctionStart(ss, handler.handler_name);

    if (!generateCodeFromInstruction(ss, handler.dec_op, handler.opcode_mask, is_step))
    {
	ss << "    unknownInstr();\n";
    }

    generateFunctionEnd(ss);
    file << ss.str();
}

vector<M68KHandler> handlers;

void generateInstHandlers(ofstream &file)
{
    vector<bool> step_table;
    generateStateFunction(file, "reset", "reset");
    generateStateFunction(file, "busError", "busError");
    generateStateFunction(file, "addressError", "addressError");
    generateStateFunction(file, "doubleFault", "doubleFault");
    generateStateFunction(file, "interrupt", "interrupt");
    generateStateFunction(file, "illegal", "illegal");
    generateStateFunction(file, "trace", "trace");
    generateStateFunction(file, "privilege", "privilege");
    generateStateFunction(file, "lineA", "lineA");
    generateStateFunction(file, "lineF", "lineF");

    for (auto &handler : handlers)
    {
	bool is_step = false;
	generateInstFunction(file, handler, is_step);

	step_table.push_back(is_step);
    }

    file << endl;
    file << "vector<Kujo68KHandler> handlers = {\n";

    for (size_t i = 0; i < states.size(); i++)
    {
	auto &state = states.at(i);
	if (state.is_implemented)
	{
	    file << "    {getFunction(" << getStateFunctionName(state.state_name) << "), false}," << endl;
	}
	else
	{
	    file << "    {getFunction(DoubleFaultDp), false}," << endl;
	}
    }

    for (size_t i = 0; i < handlers.size(); i++)
    {
	auto &handler = handlers.at(i);
	file << "    {getFunction(" << handler.handler_name << "), ";

	bool is_first_step = step_table.at(i);

	if (is_first_step)
	{
	    file << "true}";
	}
	else
	{
	    file << "false}";
	}

	if (i < (handlers.size() - 1))
	{
	    file << "," << endl;
	}
	else
	{
	    file << endl;
	}
    }

    file << "};";
}

bool fetchIRDecode()
{
    ifstream file;

    file.open("m68000.lst", ios::in);

    if (!file.is_open())
    {
	return false;
    }

    string line;
    while (getline(file, line))
    {
	string line_val = line;
	line_val = trim(line_val);

	string opcode_str = line_val.substr(0, 4);

	string opcode_mask_str = line_val.substr(5, 5);

	string opcode_name = line_val.substr(10);

	vector<string> opcode_names = split(opcode_name, ' ');

	string handler_name = getInstructionName(opcode_names);

	uint16_t opcode = toU16(opcode_str);
	uint16_t opcode_mask = toU16(opcode_mask_str);

	if ((opcode == 0xA000) || (opcode == 0xF000) || (opcode == 0x4AFC))
	{
	    continue;
	}
	
	uint16_t dec_op = opcode;

	if (((opcode & 0xF000) == 0x6000) && (opcode_mask == 0xFF00))
	{
	    dec_op |= 0x2;
	}

	handlers.push_back({opcode, opcode_mask, dec_op, handler_name});
    }

    file.close();

    return true;
}

bool runHandlers()
{
    ofstream file("programs.inl", ios::out | ios::trunc);

    generateMicrocode();
    generateNanocode();
    generateInstHandlers(file);

    /*
    auto code = {genBaseCode(0x0030, 0xFFF8, 0x3E2, -1, false)};

    cout << "Code: " << endl;

    for (auto &cib : code)
    {
	for (auto &ci : cib)
	{
	    cout << "[" << ci.tag;

	    if (!ci.args.empty())
	    {
		cout << ", ";

		for (auto iter = ci.args.begin(); iter != ci.args.end(); iter++)
		{
		    if (iter != ci.args.begin())
		    {
			cout << ", ";
		    }

		    auto val = *iter;
		    cout << val;
		}
	    }

	    cout << "]" << endl;
	}
    }
    */

    // stringstream ss;
    // generateCodeForState(ss, "doubleFault");
    // cout << ss.str();
    
    // stringstream ss;
    // generateCodeFromInstruction(ss, 0x0030, 0xFFF8);
    // cout << ss.str();

    // stringstream ss;
    // generateCodeFromInstruction(ss, 0x303C, 0xF1FF);
    // cout << ss.str();

    /*
    cout << "Test 1:" << endl;
    stringstream ss1;
    generateCodeForState(ss1, "reset");
    cout << ss1.str() << endl;

    cout << "Test 2:" << endl;
    stringstream ss2;
    generateCodeFromInstruction(ss2, 0x6000, 0xFF00);
    cout << ss2.str() << endl;

    cout << "Test 3:" << endl;
    stringstream ss3;
    generateCodeFromInstruction(ss3, 0x0000, 0xFFF8);
    cout << ss3.str() << endl;
    */

    file.close();

    return true;
}

int main(int argc, char *argv[])
{
    if (!fetchIRDecode())
    {
	return 1;
    }

    if (!runHandlers())
    {
	return 1;
    }

    return 0;
}