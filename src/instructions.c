#include "cpu.h"
#include "instructions.h"

struct instruction instructions[INSTRUCTION_COUNT] = {
    [0x18] = {clc, OPERAND_IMPLIED},
    [0xEA] = {nop, OPERAND_IMPLIED},
    [0xA9] = {lda, OPERAND_IMMEDIATE}
};

void clc(struct cpu* cpu, uint16_t) {
    cpu->sr &= ~SR_C;
}

void nop(struct cpu*, uint16_t) { }

void lda(struct cpu* cpu, uint16_t operand) {
    if (!operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
        
    if (operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_Z;

    cpu->ac = operand;
}