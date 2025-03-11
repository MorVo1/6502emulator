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
    [0xB5] = {lda, OPERAND_ZEROPAGE_X},
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
    [0xA0] = {ldy, OPERAND_IMMEDIATE},
    [0xA4] = {ldy, OPERAND_ZEROPAGE},
    [0xB4] = {ldy, OPERAND_ZEROPAGE_X},
    [0xAC] = {ldy, OPERAND_ABSOLUTE},
    [0xBC] = {ldy, OPERAND_ABSOLUTE_X},
    [0x00] = {brk, OPERAND_IMPLIED},
    [0x4C] = {jmp, OPERAND_ABSOLUTE},
    [0x6C] = {jmp, OPERAND_INDIRECT},
    [0x20] = {jsr, OPERAND_ABSOLUTE},
    [0x40] = {rti, OPERAND_IMPLIED},
    [0x60] = {rts, OPERAND_IMPLIED},
    [0x85] = {sta, OPERAND_ZEROPAGE},
    [0x95] = {sta, OPERAND_ZEROPAGE_X},
    [0x8D] = {sta, OPERAND_ABSOLUTE},
    [0x9D] = {sta, OPERAND_ABSOLUTE_X},
    [0x99] = {sta, OPERAND_ABSOLUTE_Y},
    [0x81] = {sta, OPERAND_PRE_ZEROPAGE_X},
    [0x91] = {sta, OPERAND_POST_ZEROPAGE_Y},
    [0x86] = {stx, OPERAND_ZEROPAGE},
    [0x96] = {stx, OPERAND_ZEROPAGE_Y},
    [0x8E] = {stx, OPERAND_ABSOLUTE},
    [0x84] = {sty, OPERAND_ZEROPAGE},
    [0x94] = {sty, OPERAND_ZEROPAGE},
    [0x8C] = {sty, OPERAND_ZEROPAGE},
    [0xAA] = {tax, OPERAND_IMPLIED},
    [0xA8] = {tay, OPERAND_IMPLIED},
    [0xBA] = {tsx, OPERAND_IMPLIED},
    [0x8A] = {txa, OPERAND_IMPLIED},
    [0x9A] = {txs, OPERAND_IMPLIED},
    [0x98] = {tya, OPERAND_IMPLIED},
    [0x48] = {pha, OPERAND_IMPLIED},
    [0x08] = {php, OPERAND_IMPLIED},
    [0x68] = {pla, OPERAND_IMPLIED},
    [0x28] = {plp, OPERAND_IMPLIED},
    [0x0A] = {asl, OPERAND_ACCUMULATOR},
    [0x06] = {asl, OPERAND_ZEROPAGE},
    [0x16] = {asl, OPERAND_ZEROPAGE_X},
    [0x0E] = {asl, OPERAND_ABSOLUTE},
    [0x1E] = {asl, OPERAND_ABSOLUTE_X},
    [0x2A] = {rol, OPERAND_ACCUMULATOR},
    [0x26] = {rol, OPERAND_ZEROPAGE},
    [0x36] = {rol, OPERAND_ZEROPAGE_X},
    [0x2E] = {rol, OPERAND_ABSOLUTE},
    [0x3E] = {rol, OPERAND_ABSOLUTE_X},
    [0x6A] = {ror, OPERAND_ACCUMULATOR},
    [0x66] = {ror, OPERAND_ZEROPAGE},
    [0x76] = {ror, OPERAND_ZEROPAGE_X},
    [0x6E] = {ror, OPERAND_ABSOLUTE},
    [0x7E] = {ror, OPERAND_ABSOLUTE_X},
    [0x29] = {and, OPERAND_IMMEDIATE},
    [0x25] = {and, OPERAND_ZEROPAGE},
    [0x35] = {and, OPERAND_ZEROPAGE_X},
    [0x2D] = {and, OPERAND_ABSOLUTE},
    [0x3D] = {and, OPERAND_ABSOLUTE_X},
    [0x39] = {and, OPERAND_ABSOLUTE_Y},
    [0x21] = {and, OPERAND_PRE_ZEROPAGE_X},
    [0x31] = {and, OPERAND_POST_ZEROPAGE_Y},
    [0x2C] = {bit, OPERAND_ABSOLUTE},
    [0x24] = {bit, OPERAND_ZEROPAGE},
    [0x49] = {eor, OPERAND_IMMEDIATE},
    [0x45] = {eor, OPERAND_ZEROPAGE},
    [0x55] = {eor, OPERAND_ZEROPAGE_X},
    [0x4D] = {eor, OPERAND_ABSOLUTE},
    [0x5D] = {eor, OPERAND_ABSOLUTE_X},
    [0x59] = {eor, OPERAND_ABSOLUTE_Y},
    [0x41] = {eor, OPERAND_PRE_ZEROPAGE_X},
    [0x51] = {eor, OPERAND_POST_ZEROPAGE_Y},
    [0x09] = {ora, OPERAND_IMMEDIATE},
    [0x05] = {ora, OPERAND_ZEROPAGE},
    [0x15] = {ora, OPERAND_ZEROPAGE_X},
    [0x0D] = {ora, OPERAND_ABSOLUTE},
    [0x1D] = {ora, OPERAND_ABSOLUTE_X},
    [0x19] = {ora, OPERAND_ABSOLUTE_Y},
    [0x01] = {ora, OPERAND_PRE_ZEROPAGE_X},
    [0x11] = {ora, OPERAND_POST_ZEROPAGE_Y},
    [0xC6] = {dec, OPERAND_ZEROPAGE},
    [0xD6] = {dec, OPERAND_ZEROPAGE_X},
    [0xCE] = {dec, OPERAND_ABSOLUTE},
    [0xDE] = {dec, OPERAND_ABSOLUTE_X},
    [0xCA] = {dex, OPERAND_IMPLIED},
    [0x88] = {dey, OPERAND_IMPLIED},
    [0xE6] = {inc, OPERAND_ZEROPAGE},
    [0xF6] = {inc, OPERAND_ZEROPAGE_X},
    [0xEE] = {inc, OPERAND_ABSOLUTE},
    [0xFE] = {inc, OPERAND_ABSOLUTE_X},
    [0xE8] = {inx, OPERAND_IMPLIED},
    [0xC8] = {iny, OPERAND_IMPLIED},
    [0x90] = {bcc, OPERAND_RELATIVE},
    [0xB0] = {bcs, OPERAND_RELATIVE},
    [0xEA] = {nop, OPERAND_IMPLIED}
};

void clc(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr &= ~SR_C;
}

void cld(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr &= ~SR_D;
}

void cli(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr &= ~SR_I;
}

void clv(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr &= ~SR_V;
}

void sec(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr |= SR_C;
}

void sed(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr |= SR_D;
}

void sei(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sr |= SR_I;
}

void lda(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac = *operand;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void ldx(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->x = *operand;
    set_n_if_negative(cpu, cpu->x);
    set_z_if_zero(cpu, cpu->x);
}

void ldy(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->y = *operand;
    set_n_if_negative(cpu, cpu->y);
    set_z_if_zero(cpu, cpu->y);
}

void brk(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    push(cpu, cpu->pc >> 8, ram);
    push(cpu, (cpu->pc & 0xFF) + 1, ram);

    cpu->sr |= SR_B;
    cpu->sr |= SR_I;
    
    push(cpu, cpu->sp, ram);

    // I am subtracting 1 from it because it gets added later on in my main loop.
    cpu->pc = ram[0xFFFE] + ram[0xFFFF] * 0x100 - 1;
}

void jmp(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    // I am subtracting 1 from it because it gets added later on in my main loop.
    cpu->pc = operand - ram - 1;
}

void jsr(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    push(cpu, cpu->pc >> 8, ram);
    push(cpu, cpu->pc & 0xFF, ram);

    // I am subtracting 1 from it because it gets added later on in my main loop.
    cpu->pc = operand - ram - 1;
}

void rti(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    pull(cpu, &cpu->sr, ram);
    
    uint8_t high, low;
    pull(cpu, &low, ram);
    pull(cpu, &high, ram);
    cpu->pc = high * 0x100 + low;
}

void rts(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    uint8_t high, low;
    pull(cpu, &low, ram);
    pull(cpu, &high, ram);
    cpu->pc = high * 0x100 + low;
}

void sta(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    *operand = cpu->ac;
}

void stx(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    *operand = cpu->x;
}

void sty(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    *operand = cpu->y;
}

void tax(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x = cpu->ac;
    set_n_if_negative(cpu, cpu->x);
    set_z_if_zero(cpu, cpu->x);
}

void tay(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->y = cpu->ac;
    set_n_if_negative(cpu, cpu->y);
    set_z_if_zero(cpu, cpu->y);
}

void tsx(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x = cpu->sp;
    set_n_if_negative(cpu, cpu->x);
    set_z_if_zero(cpu, cpu->x);
}

void txa(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->ac = cpu->x;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void txs(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sp = cpu->x;
}

void tya(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->ac = cpu->y;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void pha(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    push(cpu, cpu->ac, ram);
}

void php(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    push(cpu, cpu->sr, ram);
}

void pla(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    pull(cpu, &cpu->ac, ram);
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void plp(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    pull(cpu, &cpu->sr, ram);
}

void asl(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (*operand & 0b1000'0000)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;
    
    *operand = *operand << 1;

    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, *operand);
}

void lsr(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (*operand & 0b000'0001)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;

    cpu->sr &= ~SR_N;
    *operand = *operand >> 1;
    
    set_z_if_zero(cpu, *operand);
}

void rol(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t carryin = cpu->sr & SR_C;
    if (*operand & 0b1000'0000)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;

    *operand = *operand << 1;
    *operand |= carryin;

    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, *operand);
}

void ror(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t carryin = cpu->sr & SR_C;
    if (*operand & 0b0000'0001)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;
    
    *operand = *operand >> 1;
    *operand |= carryin;

    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, *operand);
}

void and(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac &= *operand;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void eor(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac ^= *operand;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void ora(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac |= *operand;
    set_n_if_negative(cpu, cpu->ac);
    set_z_if_zero(cpu, cpu->ac);
}

void bit(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t result = cpu->ac & *operand;
    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, result);

    if (*operand & SR_V)
        cpu->sr |= SR_V;
    else
        cpu->sr &= ~SR_V;

}

void dec(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    (*operand)--;
    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, *operand);
}

void dex(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x--;
    set_n_if_negative(cpu, cpu->x);
    set_z_if_zero(cpu, cpu->x);
}

void dey(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->y--;
    set_n_if_negative(cpu, cpu->y);
}

void inc(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    (*operand)++;
    set_n_if_negative(cpu, *operand);
    set_z_if_zero(cpu, *operand);
}

void inx(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x++;
    set_n_if_negative(cpu, cpu->x);
    set_z_if_zero(cpu, cpu->y);
}

void iny(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->y++;
    set_n_if_negative(cpu, cpu->y);
    set_z_if_zero(cpu, cpu->y);
}

void bcc(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (!(cpu->sr & SR_C))
        cpu->pc += *operand;
}

void bcs(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (cpu->sr & SR_C)
        cpu->pc += *operand;
}

void beq(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (cpu->sr & SR_Z)
        cpu->pc += *operand;
}

void bmi(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (cpu->sr & SR_N)
        cpu->pc += *operand;
}

void bne(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (!(cpu->sr & SR_Z))
        cpu->pc += *operand;
}

void bpl(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (!(cpu->sr & SR_N))
        cpu->pc += *operand;
}

void bvc(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (!(cpu->sr & SR_V))
        cpu->pc += *operand;
}

void bvs(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (cpu->sr & SR_V)
        cpu->pc += *operand;
}

void nop(struct cpu *, uint8_t *, uint8_t *) { }

// The functions below do not represent the 6502's instructions

void set_z_if_zero(struct cpu *cpu, uint8_t value) {
    if (!value)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void set_n_if_negative(struct cpu *cpu, uint8_t value) {
    if (value & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
}

void push(struct cpu *cpu, uint8_t value, uint8_t *ram) {
    ram[0x100 + cpu->sp] = value;
    cpu->sp--;
}

void pull(struct cpu *cpu, uint8_t *dest, uint8_t *ram) {
    cpu->sp++;
    *dest = ram[0x100 + cpu->sp];
}
