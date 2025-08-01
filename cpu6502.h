#pragma once

class Bus;


class cpu6502
{
public:
	cpu6502();
	~cpu6502();


public:
	enum FLAGS6502
	{
		C = (1 << 0), // Carry Bit
		Z = (1 << 1), // Zero
		I = (1 << 2), // Disable Interrupts
		D = (1 << 3), // Decimal mode
		B = (1 << 4), // Break
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7), // Negative
	};



	void ConnectBus(Bus* n) { bus = n; }


private:
	Bus* bus = nullptr;
	uint8_t read(uint16_t a);
	void write(uint16_t a, uint8_t d);
};

