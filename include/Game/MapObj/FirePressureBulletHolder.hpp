#pragma once

#include "Game/NameObj/NameObj.hpp"
#include "Game/MapObj/FirePressureBullet.hpp"

class FirePressureBulletHolder : public NameObj {
public:
    FirePressureBulletHolder(const char *);

    virtual ~FirePressureBulletHolder();
    virtual void init(const JMapInfoIter &);

    FirePressureBullet* callEmptyBullet();

    FirePressureBullet* mBullets[0x8];  // 0xC
};