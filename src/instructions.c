#include "cpu.h"
#include "instructions.h"

struct instruction instructions[INSTRUCTION_COUNT] = {
    [0x18] = {clc, OPERAND_IMPLIED},
    [0xD8] = {cld, OPERAND_IMPLIED},
    [0x58] = {cli, OPERAND_IMPLIED},
    [0xB8] = {clv, OPERAND_IMPLIED},
    [0x38] = {sec, OPERAND_IMPLIED},
    [0xF8] = {sed, OPERAND_IMPLIED},
    [0x78] = {sei, OPERAND_IMPLIED},
    [0xA9] = {lda, OPERAND_IMMEDIATE},
    [0xEA] = {nop, OPERAND_IMPLIED},
};

void clc(struct cpu *cpu, uint8_t *) {
    cpu->sr &= ~SR_C;
}

void cld(struct cpu *cpu, uint8_t *) {
    cpu->sr &= ~SR_D;
}

void cli(struct cpu *cpu, uint8_t *) {
    cpu->sr &= ~SR_I;
}

void clv(struct cpu *cpu, uint8_t *) {
    cpu->sr &= ~SR_V;
}

void sec(struct cpu *cpu, uint8_t *) {
    cpu->sr |= SR_C;
}

void sed(struct cpu *cpu, uint8_t *) {
    cpu->sr |= SR_D;
}

void sei(struct cpu *cpu, uint8_t *) {
    cpu->sr |= SR_I;
}

void nop(struct cpu *, uint8_t *) { }

void lda(struct cpu *cpu, uint8_t *operand) {
    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
        
    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    cpu->ac = *operand;
}