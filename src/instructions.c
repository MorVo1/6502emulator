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
    [0x4C] = {jmp, OPERAND_ABSOLUTE},
    [0x6C] = {jmp, OPERAND_INDIRECT},
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

void ldx(struct cpu *cpu, uint8_t *operand, uint8_t *) {
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

void ldy(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
        
    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    cpu->y = *operand;
}

void jmp(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    // I am subtracting 1 from it because it gets added later on in my main loop.
    cpu->pc = operand - ram - 1;
}

void sta(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    ram[operand - ram] = cpu->ac;
}

void stx(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    ram[operand - ram] = cpu->x;
}

void sty(struct cpu *cpu, uint8_t *operand, uint8_t *ram) {
    ram[operand - ram] = cpu->y;
}

void tax(struct cpu *cpu, uint8_t *, uint8_t *) {
    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
    
    cpu->x = cpu->ac;
}

void tay(struct cpu *cpu, uint8_t *, uint8_t *) {
    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
    
    cpu->y = cpu->ac;
}

void tsx(struct cpu *cpu, uint8_t *, uint8_t *) {
    if (!cpu->sp)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->sp & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
    
    cpu->x = cpu->sp;
}

void txa(struct cpu *cpu, uint8_t *, uint8_t *) {
    if (!cpu->x)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->x & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
    
    cpu->ac = cpu->x;
}

void txs(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->sp = cpu->x;
}

void tya(struct cpu *cpu, uint8_t *, uint8_t *) {
    if (!cpu->y)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->y & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
    
    cpu->ac = cpu->y;
}

void pha(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    ram[0x100 + cpu->sp] = cpu->ac;
    cpu->sp--;
}

void php(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    ram[0x100 + cpu->sp] = cpu->sr;
    cpu->sp--;
}

void pla(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    cpu->sp++;
    cpu->ac = ram[0x100 + cpu->sp];
    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
    
    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
}

void plp(struct cpu *cpu, uint8_t *, uint8_t *ram) {
    cpu->sp++;
    cpu->sr = ram[0x100 + cpu->sp];
}

void asl(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (*operand & 0b1000'0000)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;
    
    *operand = *operand << 1;

    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void lsr(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    if (*operand & 0b000'0001)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;

    cpu->sr &= ~SR_N;
    *operand = *operand >> 1;
    
    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void rol(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t carryin = cpu->sr & SR_C;
    if (*operand & 0b1000'0000)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;

    *operand = *operand << 1;
    *operand += carryin;

    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void ror(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t carryin = cpu->sr & SR_C;
    if (carryin)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;
        
    if (*operand & 0b0000'0001)
        cpu->sr |= SR_C;
    else
        cpu->sr &= ~SR_C;

    *operand = *operand >> 1;

    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void and(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac &= *operand;

    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void eor(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac ^= *operand;

    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void ora(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    cpu->ac |= *operand;

    if (cpu->ac & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->ac)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void bit(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    uint8_t result = cpu->ac & *operand;

    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (*operand & SR_V)
        cpu->sr |= SR_V;
    else
        cpu->sr &= ~SR_V;

    if (!result)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void dec(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    *operand -= 1;

    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void dex(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x -= 1;

    if (cpu->x & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->x)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void dey(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->y -= 1;

    if (cpu->y & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->y)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void inc(struct cpu *cpu, uint8_t *operand, uint8_t *) {
    *operand += 1;

    if (*operand & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!*operand)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void inx(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->x += 1;

    if (cpu->x & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->x)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void iny(struct cpu *cpu, uint8_t *, uint8_t *) {
    cpu->y += 1;

    if (cpu->y & SIGN_BIT)
        cpu->sr |= SR_N;
    else
        cpu->sr &= ~SR_N;

    if (!cpu->y)
        cpu->sr |= SR_Z;
    else
        cpu->sr &= ~SR_Z;
}

void nop(struct cpu *, uint8_t *, uint8_t *) { }
