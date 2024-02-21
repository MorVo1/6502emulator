#pragma once

#include <stdint.h>

#include "cpu.h"

#define INSTRUCTION_COUNT

enum address_mode {
    OPERAND_ACCUMULATOR,
	OPERAND_ABSOLUTE,
	OPERAND_ABSOLUTE_JMP,
	OPERAND_ABSOLUTE_X,
	OPERAND_ABSOLUTE_Y,
	OPERAND_IMMEDIATE,
	OPERAND_IMPLIED,
	OPERAND_ZEROPAGE,
	OPEARAND_ZEROPAGE_X,
	OPERAND_ZEROPAGE_Y,
	OPERAND_PRE_ZEROPAGE_X,
	OPERAND_POST_ZEROPAGE_Y,
	OPERAND_INDIRECT
};

struct instruction {
    void (*implementation)(struct cpu *, uint8_t *);
    enum address_mode address_mode;
};

extern struct instruction instructions[INSTRUCTION_COUNT];

void clc(struct cpu *, uint8_t *);
void cld(struct cpu *, uint8_t *);
void cli(struct cpu *, uint8_t *);
void clv(struct cpu *, uint8_t *);
void sec(struct cpu *, uint8_t *);
void sed(struct cpu *, uint8_t *);
void sei(struct cpu *, uint8_t *);
void lda(struct cpu *, uint8_t *);
void jmp(struct cpu *, uint8_t *);
void nop(struct cpu *, uint8_t *);
