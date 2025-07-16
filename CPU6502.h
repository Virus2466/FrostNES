#pragma once
#include<cstdint>


// Main CPU class
class CPU {
public:
	// Registers.
	uint8_t A = 0x00; // Accumulator
	uint8_t X = 0x00; // Index X
	uint8_t Y = 0x00; // Index Y

	uint16_t PC = 0x0000; // Program Counter
	uint8_t SP = 0xFD; // Stack Pointer
	uint8_t P = 0x24; // Status Register (flags)




	// Internals
	uint8_t opcode = 0x00;
	uint8_t cycles = 0;

	// Status Flags Bits Position
	enum FLAGS {
		C = (1 << 0),
		Z = (1 << 1),
		I = (1 << 2),
		D = (1 << 3),
		B = (1 << 4),
		U = (1 << 5),
		V = (1 << 6),
		N = (1 << 7),
	};

	CPU();
	~CPU();

	// Flag Helpers..
	uint8_t GetFlag(FLAGS flag);
	void SetFlag(FLAGS flag, bool value);

	// CPU Functionality.
	void Reset();
	uint8_t Read(uint16_t addr);
	void Clock();
};