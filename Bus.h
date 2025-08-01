#pragma once
#include<cstdint>
#include "cpu6502.h"
#include<array>


class Bus
{
public:
	Bus();
	~Bus();

public: // Devices on bus
	cpu6502 cpu;

	// Fake RAM
	std::array<uint8_t, 64 * 1024>ram;

public:
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);



};

