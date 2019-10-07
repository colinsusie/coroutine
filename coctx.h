#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    void *regs[16];
    size_t ss_size;
    char *ss_sp;
} coctx_t;

typedef void (*cofun)(uint32_t p1, uint32_t p2);

extern int comakectx(coctx_t *ctx, cofun fn, uint32_t p1, uint32_t p2);
extern int coswapctx(coctx_t *octx, coctx_t *ctx) asm("coswapctx");