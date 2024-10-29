#pragma once

#include <revolution.h>
#include "JSystem/JKernel/JKRHeap.hpp"

class SpkMixingBuffer {
public:
    SpkMixingBuffer(JKRHeap *);

    void mix(s32, s16 *, s32, f32, s32);
    const s16* getSamples(s32) const;
    bool update(s32);

    const s16* mSamples[4];
};