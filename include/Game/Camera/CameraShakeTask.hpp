#pragma once

class CameraShakePattern;

class CameraShakeTask {
public:
    CameraShakeTask(CameraShakePattern *);

    void start(unsigned long, unsigned long);
    void startInfinity(unsigned long);
    void endForce();
    void movement();
    void getOffset(TVec2f *) const;
    bool isEnd() const;
    void startCommon(unsigned long);
    void updatePattern();
    void updateInterval();

    CameraShakePattern *mPattern;   // 0x0
    bool mHasEnded;                 // 0x4
    bool mIsInfinite;               // 0x5
    u8 _6[2];
    u32 _8;
    u32 _C;
    u32 _10;
};