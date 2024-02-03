#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cpu.h"

uint8_t ram[MEM_SIZE];

int main() {
	memset(ram, 0, MEM_SIZE);
	struct cpu cpu = {
		.pc = 0
	};

	FILE* ramfile = fopen("../ram", "r");
	fgets(ram, MEM_SIZE, ramfile);

	run(&cpu, ram);
}