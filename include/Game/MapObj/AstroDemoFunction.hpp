#pragma once

#include <revolution.h>
#include "Game/Util.hpp"

class LiveActor;

class AstroDemoFunction {
public:
    static s32 getOpenedAstroDomeNum();
    static const char* getGrandStarReturnDemoName(int);

    static bool tryRegisterDemo(LiveActor *, const char *, const JMapInfoIter &);
    static bool tryRegisterGrandStarReturnWithFunctionAndSimpleCast(LiveActor *, const JMapInfoIter &);
    static bool tryRegisterGrandStarReturnWithFunctionAndSimpleCast(LiveActor *, const JMapInfoIter &, const MR::FunctorBase &);
};