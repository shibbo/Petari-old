#pragma once

#include <revolution.h>
#include "JSystem/JKernel/JKRExpHeap.hpp"
#include "JSystem/JKernel/JKRSolidHeap.hpp"
#include "Inline.hpp"

namespace {
    JKRExpHeap* createExpHeap(u32, JKRHeap *, bool) NO_INLINE;
    JKRSolidHeap* createSolidHeap(u32, JKRHeap *) NO_INLINE;
    void destroyHeapAndSetNULL(JKRHeap **) NO_INLINE;
};

class HeapMemoryWatcher {
public:
    HeapMemoryWatcher();

    JKRHeap* getHeapNapa(const JKRHeap *);
    JKRHeap* getHeapGDDR3(const JKRHeap *);
    void createFileCacheHeapOnGameHeap(u32);
    void createSceneHeapOnGameHeap();
    void adjustStationedHeaps();
    void setCurrentHeapToStationedHeap();
    void setCurrentHeapToGameHeap();
    void setCurrentHeapToSceneHeap();
    void destroySceneHeap();
    void destroyGameHeap();
    static void createRootHeap();
    void createHeaps();
    void createGameHeap();
    static void memoryErrorCallback(void *, u32, int);
    void checkRestMemory();

    JKRExpHeap* mStationedHeapNapa;     // 0x0
    JKRExpHeap* mStationedHeapGDDR;     // 0x4
    JKRExpHeap* mGameHeapNapa;          // 0x8
    JKRExpHeap* mGameHeapGDDR;          // 0xC
    JKRHeap* mFileCacheHeap;            // 0x10
    JKRSolidHeap* mSceneHeapNapa;       // 0x14
    JKRSolidHeap* mSceneHeapGDDR;       // 0x18
    JKRExpHeap* mWPadHeap;              // 0x1C
    JKRExpHeap* mHomeButtonLayoutHeap;  // 0x20
    JKRSolidHeap* mAudSystemHeap;       // 0x24

    static JKRExpHeap* sRootHeapGDDR3;
};