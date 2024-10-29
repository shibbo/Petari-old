#pragma once

#include "revolution.h"

#include "Game/AreaObj/AreaForm.hpp"
#include "Game/NameObj/NameObj.hpp"
#include "Game/Map/StageSwitch.hpp"
#include "Game/Util/Array.hpp"

class AreaObj : public NameObj {
public:
    AreaObj(int, const char *);
    virtual ~AreaObj() {

    }

    virtual void init(const JMapInfoIter &);

    virtual bool isInVolume(const TVec3f &) const;
    virtual const char* getManagerName() const;

    void onSwitchA();
    void offSwitchA();
    bool isOnSwitchA() const;
    bool isOnSwitchB() const;
    bool isValidSwitchA() const;
    bool isValidSwitchB() const;
    void setFollowMtx(const TPos3f *);
    TPos3f* getFollowMtx() const;

    void validate();
    void invalidate();

    bool isValid() const;

    void awake();
    void sleep();

    AreaForm* mForm;              // 0xC
    int mType;                    // 0x10
    bool mValid;                  // 0x14
    bool _15;
    bool mAwake;                  // 0x16
    s32 mObjArg0;                 // 0x18
    s32 mObjArg1;                 // 0x1C
    s32 mObjArg2;                 // 0x20
    s32 mObjArg3;                 // 0x24
    s32 mObjArg4;                 // 0x28
    s32 mObjArg5;                 // 0x2C
    s32 mObjArg6;                 // 0x30
    s32 mObjArg7;                 // 0x34
    StageSwitchCtrl* mSwitchCtrl; // 0x38
};

class AreaObjMgr : public NameObj {
public:
    AreaObjMgr(s32, const char *);

    virtual ~AreaObjMgr();

    void entry(AreaObj *);
    AreaObj* find_in(const TVec3f &) const;

    MR::Vector<MR::AssignableArray<AreaObj*> > mArray; // 0xC
    s32 _18;
};
