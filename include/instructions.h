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
	OPERAND_IMPLIED
};

struct instruction {
    void (*implementation)(struct cpu *, uint16_t);
    enum address_mode address_mode;
};

extern struct instruction instructions[INSTRUCTION_COUNT];

void clc(struct cpu *, uint16_t);
void nop(struct cpu *, uint16_t);
void lda(struct cpu *, uint16_t);