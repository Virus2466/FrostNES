#include<cstdio>
#include "CPU6502.h"


// External Memory Declaration
extern uint8_t memory[0x10000];


int main() {
	// testing 
	memory[0xFFFC] = 0x00;
	memory[0xFFFD] = 0x00; // Reset Vector

	memory[0x8000] = 0xA9; // LDA #$42
	memory[0x8001] = 0x42;
	memory[0x8002] = 0xAA; // TAX

	CPU cpu;
	cpu.Reset();

	while (cpu.cycles > 0) cpu.Clock(); // Finish Reset Cycles

	// Step CPU through test instructions .
	while(cpu.PC < 0x8003)
		cpu.Clock();

	/// Print Register Results.
	printf("A : %02X\n", cpu.A); 
	printf("X : %02X\n", cpu.X);
	printf("PC : %02X\n", cpu.PC);
}