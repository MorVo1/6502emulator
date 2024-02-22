#include <stdio.h>
#include <stdbool.h>

#include "cpu.h"
#include "instructions.h"

void run(struct cpu *cpu, uint8_t *ram) {
    uint16_t operand;
    uint16_t lookup;

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
                break;
            case OPERAND_ABSOLUTE:
                operand = ram[++cpu->pc];
                operand += ram[++cpu->pc] * 0x100;
                instruction->implementation(cpu, &ram[operand]);
                break;
            case OPERAND_ABSOLUTE_X:
                operand = ram[++cpu->pc];
                operand += ram[++cpu->pc] * 0x100;
                instruction->implementation(cpu, &ram[operand + cpu->x]);
                break;
            case OPERAND_ABSOLUTE_Y:
                operand = ram[++cpu->pc];
                operand += ram[++cpu->pc] * 0x100;
                instruction->implementation(cpu, &ram[operand + cpu->y]);
                break;
            case OPERAND_ABSOLUTE_JMP:
                instruction->implementation(cpu, &ram[++cpu->pc]);
                continue;
                break;
            case OPERAND_INDIRECT:
                operand = ram[++cpu->pc];
                operand += ram[++cpu->pc] * 0x100;
                instruction->implementation(cpu, &ram[operand]);
                continue;
                break;
            case OPERAND_IMMEDIATE:
                instruction->implementation(cpu, &ram[++cpu->pc]);
                break;
            case OPERAND_IMPLIED:
                instruction->implementation(cpu, 0);
                break;
            case OPERAND_ZEROPAGE:
                instruction->implementation(cpu, &ram[ram[++cpu->pc]]);
                break;
            case OPERAND_ZEROPAGE_X:
                instruction->implementation(cpu, &ram[ram[++cpu->pc] + cpu->x]);
                break;
            case OPERAND_ZEROPAGE_Y:
                instruction->implementation(cpu, &ram[ram[++cpu->pc] + cpu->y]);
                break;
            case OPERAND_PRE_ZEROPAGE_X:
                lookup = ram[++cpu->pc] + cpu->x;
                instruction->implementation(cpu, &ram[ram[lookup] + ram[lookup + 1] * 0x100]);
                break;
            case OPERAND_POST_ZEROPAGE_Y:
                lookup = ram[++cpu->pc];
                instruction->implementation(cpu, &ram[ram[lookup] + ram[lookup + 1] * 0x100 + cpu->y]);
        }
        cpu->pc++;
    }
}
