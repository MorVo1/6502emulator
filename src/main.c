#include <stdio.h>
#include <stdint.h>

#include "cpu.h"

uint8_t ram[MEM_SIZE];

int main() {
	struct cpu cpu = {
		.pc = 0
	};

	FILE *ramfile = fopen("../ram", "r");
	fgets(ram, MEM_SIZE, ramfile);

	run(&cpu, ram);
}