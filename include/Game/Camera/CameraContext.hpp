#pragma once

#include "Game/NameObj/NameObj.hpp"
#include "JSystem/JGeometry.hpp"

class CameraContext : public NameObj {
public:
    CameraContext();
    virtual ~CameraContext();

    void initParams();
    const TPos3f *getViewMtx() const;
    const TPos3f *getInvViewMtx() const;
    f32 getAspect() const;
    //setViewMtx(const TPos3f &, bool, bool, const TVec3f &);
    void setNearZ(float);
    void setFovy(float);
    void setShakeOffset(float, float);
    void updateProjectionMtx();

    TPos3f mView;          // 0xC
    TPos3f mViewInv;       // 0x3C
    TPos3f mProjection;    // 0x6C
    f32 _9C;
    f32 _A0;
    f32 _A4;
    f32 _A8;
    f32 _AC;
    f32 mNearZ;             // 0xB0
    f32 mFarZ;              // 0xB4
    f32 mFovy;              // 0xB8
    f32 mShakeOffsetX;      // 0xBC
    f32 mShakeOffsetY;      // 0xC0
};