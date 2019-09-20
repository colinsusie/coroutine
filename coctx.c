#include <string.h>
#include "coctx.h"

int comakectx(coctx_t *ctx, cofun fn, uint32_t p1, uint32_t p2) {
#if defined(__x86_64__)
    char *sp = ctx->ss_sp + ctx->ss_size;
	sp = (char*) ((uintptr_t)sp & -16LL);
	memset(ctx->regs, 0, sizeof(ctx->regs));
	ctx->regs[6] = (void*)(intptr_t)p1;       // p1
	ctx->regs[7] = (void*)(intptr_t)p2;       // p2
    ctx->regs[12] = fn;             // rip
    ctx->regs[13] = sp - 8;         // rsp
	return 0;
#else
    #error "platform not support"
#endif
    return 0;
}