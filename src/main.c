#include <stdio.h>
#include <stdint.h>

#include "cpu.h"

uint8_t ram[MEM_SIZE];

int main() {
	struct cpu cpu;

	FILE *ramfile = fopen("../ram", "rb");
	fread(ram, 1, MEM_SIZE, ramfile);

	reset(&cpu, ram);
	run(&cpu, ram);
}
