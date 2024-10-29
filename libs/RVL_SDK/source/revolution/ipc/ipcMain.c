#include "revolution/ipc.h"
#include "revolution/os/OSIpc.h"
#include "private/flipper.h"

static void* IPCBufferHi;
static void* IPCBufferLo;

static void* IPCCurrentBufferHi;
static void* IPCCurrentBufferLo;

static u8 Initialized;

void IPCInit(void) {
    if (Initialized) {
        return;
    }

    IPCBufferHi = __OSGetIPCBufferHi();
    IPCBufferLo = __OSGetIPCBufferLo();
    IPCCurrentBufferHi = IPCBufferHi;
    IPCCurrentBufferLo = IPCBufferLo;

    Initialized = TRUE;
}

void IPCReInit(void) {
    Initialized = FALSE;
    IPCInit();
}

u32 IPCReadReg(u32 regIdx) {
    u32 reg = __IPCRegs[regIdx];
    return reg;
}

void IPCWriteReg(u32 regIdx, u32 data) {
    __IPCRegs[regIdx] = data;
}

void* IPCGetBufferHi(void) {
    return IPCCurrentBufferHi;
}

void* IPCGetBufferLo(void) {
    return IPCCurrentBufferLo;
}

void IPCSetBufferLo(void* lo) {
    IPCCurrentBufferLo = lo;
}