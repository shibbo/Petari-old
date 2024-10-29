#pragma once

#include "Game/Util.hpp"
#include <revolution.h>

class AlreadyDoneInfo {
public:
    AlreadyDoneInfo();

    void clear();
    void init(const char *, s32, s32);
    bool isEqual(const AlreadyDoneInfo &) const;
    void set(bool);

    u16 _0;
    u16 _2;
    u16 _4;
};

class AlreadyDoneFlagInGalaxy {
public:
    AlreadyDoneFlagInGalaxy(int);

    void clear();
    u32 setupFlag(const char *, const JMapInfoIter &, u32 *);

    AlreadyDoneInfo* mDoneInfos;    // 0x0
    int mNumInfos;                  // 0x4
    u32 _8;                         // 0x8
};