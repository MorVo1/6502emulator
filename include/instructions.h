#pragma once

#include <stdint.h>

#include "cpu.h"

#define INSTRUCTION_COUNT

enum address_mode {
    OPERAND_ACCUMULATOR,
	OPERAND_ABSOLUTE,
	OPERAND_ABSOLUTE_X,
	OPERAND_ABSOLUTE_Y,
	OPERAND_IMMEDIATE,
	OPERAND_IMPLIED,
	OPERAND_ZEROPAGE,
	OPERAND_ZEROPAGE_X,
	OPERAND_ZEROPAGE_Y,
	OPERAND_PRE_ZEROPAGE_X,
	OPERAND_POST_ZEROPAGE_Y,
	OPERAND_INDIRECT
};

struct instruction {
    void (*implementation)(struct cpu *, uint8_t *, uint8_t *);
    enum address_mode address_mode;
};

extern struct instruction instructions[INSTRUCTION_COUNT];

void clc(struct cpu *, uint8_t *, uint8_t *);
void cld(struct cpu *, uint8_t *, uint8_t *);
void cli(struct cpu *, uint8_t *, uint8_t *);
void clv(struct cpu *, uint8_t *, uint8_t *);
void sec(struct cpu *, uint8_t *, uint8_t *);
void sed(struct cpu *, uint8_t *, uint8_t *);
void sei(struct cpu *, uint8_t *, uint8_t *);
void lda(struct cpu *, uint8_t *, uint8_t *);
void ldx(struct cpu *, uint8_t *, uint8_t *);
void ldy(struct cpu *, uint8_t *, uint8_t *);
void jmp(struct cpu *, uint8_t *, uint8_t *);
void sta(struct cpu *, uint8_t *, uint8_t *);
void stx(struct cpu *, uint8_t *, uint8_t *);
void sty(struct cpu *, uint8_t *, uint8_t *);
void tax(struct cpu *, uint8_t *, uint8_t *);
void tay(struct cpu *, uint8_t *, uint8_t *);
void tsx(struct cpu *, uint8_t *, uint8_t *);
void txa(struct cpu *, uint8_t *, uint8_t *);
void txs(struct cpu *, uint8_t *, uint8_t *);
void tya(struct cpu *, uint8_t *, uint8_t *);
void pha(struct cpu *, uint8_t *, uint8_t *);
void php(struct cpu *, uint8_t *, uint8_t *);
void pla(struct cpu *, uint8_t *, uint8_t *);
void plp(struct cpu *, uint8_t *, uint8_t *);
void asl(struct cpu *, uint8_t *, uint8_t *);
void lsr(struct cpu *, uint8_t *, uint8_t *);
void rol(struct cpu *, uint8_t *, uint8_t *);
void ror(struct cpu *, uint8_t *, uint8_t *);
void and(struct cpu *, uint8_t *, uint8_t *);
void nop(struct cpu *, uint8_t *, uint8_t *);
