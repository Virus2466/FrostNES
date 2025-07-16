#include "CPU6502.h"

uint8_t memory[0x10000];

// Constructor.
CPU::CPU(){}

//Destructor.
CPU::~CPU(){}

// Get The flag value -- returns 1 or 0
uint8_t CPU::GetFlag(FLAGS flag) {
	return (P & flag) ? 1 : 0;
}

// Set or clear a flag.
void CPU::SetFlag(FLAGS flag, bool value) {
	if (value)
		P |= flag;
	else
		P &= ~flag;
}


uint8_t CPU::Read(uint16_t addr) {
	return memory[addr];
}



void CPU::Reset() {
	A = 0x00;
	X = 0x00;
	Y = 0x00;

	SP = 0xFD;
	P = 0x34; // Official Power Up state
	uint16_t lo = Read(0xFFFC);
	uint16_t hi = Read(0xFFDD);

	PC = (hi << 8) | lo;
	
}

void CPU::Clock(){
	if (cycles == 0) {
		opcode = Read(PC++);
		switch (opcode) 
		{
		case 0xA9: // LDA immediate
		{
			uint8_t value = Read(PC++);
			A = value;
			cycles = 2;
			break;
		
		}
		case 0xAA: // TAX
		{
			X = A;
			cycles = 2;
			break;
		}
		default:
			break;

		}
	}
	cycles--;
}