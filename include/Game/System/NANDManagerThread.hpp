#pragma once

#include "Game/System/OSThreadWrapper.hpp"

class NANDRequestInfo;

class NANDManagerThread : public OSThreadWrapper {
public:
    NANDManagerThread(int, int, JKRHeap *);

    virtual ~NANDManagerThread();
    virtual s32 run();

    void executeWriteSequence(NANDRequestInfo *);
    void executeReadSequence(NANDRequestInfo *);
};