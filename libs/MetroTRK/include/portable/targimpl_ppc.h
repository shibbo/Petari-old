#ifndef TARGIMPL_PPC_H
#define TARGIMPL_PPC_H

#include "TRK_Types.h"

typedef struct ProcessorRestoreFlags_PPC
{
    u8 TBR;
    u8 DEC;
    u8 linker_padding[7];

} ProcessorRestoreFlags_PPC;

extern ProcessorRestoreFlags_PPC gTRKRestoreFlags;

typedef enum MemoryAccessOptions
{
    kUserMemory,
    kDebuggerMemory
} MemoryAccessOptions;

typedef enum ValidMemoryOptions
{
    kValidMemoryReadable,
    kValidMemoryWriteable
} ValidMemoryOptions;

void SetUseSerialIO(u8);

#endif // TARGIMPL_PPC_H