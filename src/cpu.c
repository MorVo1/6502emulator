#include <stdio.h>
#include <stdbool.h>

#include "cpu.h"
#include "instructions.h"

void run(struct cpu *cpu, uint8_t *ram) {
    while (true) {
        if (cpu->pc > 0x1000)
            cpu->pc = 0;

        printf("PC = %04x\tAC = %02x\tX = %02x\tY = %02x\tSP = %02x\tSR = %08b\n", cpu->pc, cpu->ac, cpu->x, cpu->y, cpu->sp, cpu->sr);

        struct instruction *instruction = &instructions[ram[cpu->pc]];
        if (instruction->implementation == NULL) {
            printf("Unimplemented instruction 0x%02x\n", ram[cpu->pc]);
            break;
        }

        switch (instruction->address_mode) {
            case OPERAND_ACCUMULATOR:
            case OPERAND_ABSOLUTE:
            case OPERAND_ABSOLUTE_X:
            case OPERAND_ABSOLUTE_Y:
                break;
            case OPERAND_IMMEDIATE:
                instruction->implementation(cpu, &ram[++cpu->pc]);
                break;
            case OPERAND_IMPLIED:
                instruction->implementation(cpu, 0);
        }
        cpu->pc++;
    }
}