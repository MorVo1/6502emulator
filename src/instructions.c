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
    [0xA5] = {lda, OPERAND_ZEROPAGE},
    [0xB5] = {lda, OPEARAND_ZEROPAGE_X},
    [0xAD] = {lda, OPERAND_ABSOLUTE},
    [0xBD] = {lda, OPERAND_ABSOLUTE_X},
    [0xB9] = {lda, OPERAND_ABSOLUTE_Y},
    [0xA1] = {lda, OPERAND_PRE_ZEROPAGE_X},
    [0xB1] = {lda, OPERAND_POST_ZEROPAGE_Y},
    [0xA2] = {ldx, OPERAND_IMMEDIATE},
    [0xA6] = {ldx, OPERAND_ZEROPAGE},
    [0xB6] = {ldx, OPERAND_ZEROPAGE_Y},
    [0xAE] = {ldx, OPERAND_ABSOLUTE},
    [0xBE] = {ldx, OPERAND_ABSOLUTE_Y},
    [0x4C] = {jmp, OPERAND_ABSOLUTE_JMP},
    [0x6C] = {jmp, OPERAND_INDIRECT},
    [0xEA] = {nop, OPERAND_IMPLIED}
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

void ldx(struct cpu *cpu, uint8_t *operand) {
    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
        
    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    cpu->x = *operand;
}

void jmp(struct cpu *cpu, uint8_t *operand) {
    uint16_t addr = *operand;
    addr += *(operand + 1) * 0x100;
    cpu->pc = addr;
}

void nop(struct cpu *, uint8_t *) { }
