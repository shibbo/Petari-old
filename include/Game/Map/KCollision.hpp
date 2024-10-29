#pragma once

#include "Game/Util/JMapInfo.hpp"
#include "JSystem/JGeometry/TVec.hpp"
#include <revolution.h>

class JMapInfo;

struct KC_PrismData {
    f32 mHeight;                // 0x0
    u16 mPositionIndex;         // 0x4
    u16 mNormalIndex;           // 0x6
    u16 mEdgeIndices[3];        // 0x8
    u16 mAttribute;             // 0xE
};

class Fxyz {
public:
    inline Fxyz() {

    }

    Fxyz &operator=(const Fxyz &);

    f32 x, y, z;
};

struct KCLFile {
    union {
        TVec3f *mPos;           // 0x0
        u32 mPosOffset;         // 0x0
    };
    union {
        TVec3f *mNorms;         // 0x4
        u32 mNormOffset;        // 0x4
    };
    union {
        KC_PrismData *mPrisms;  // 0x8
        u32 mPrismOffset;       // 0x8
    };
    union {
        void *mOctree;          // 0xC
        u32 mOctreeOffset;      // 0xC
    };
    f32 mThickness;             // 0x10
    TVec3f mMin;                // 0x14
    s32 mXMask;                 // 0x20
    s32 mYMask;                 // 0x24
    s32 mZMask;                 // 0x28
    s32 mBlockWidthShift;       // 0x2C
    s32 mBlockXShift;           // 0x30
    s32 mBlockXYShift;          // 0x34
};

class KCollisionServer {
public:
    class V3u {
    public:
        inline V3u() {

        }

        void setUsingCast(const TVec3f &);

        s32 x;
        s32 y;
        s32 z;
    };

    KCollisionServer();

    void init(void *, const void *);
    void setData(void *);
    void calcFarthestVertexDistance();
    static bool isBinaryInitialized(const void *);
    void checkPoint(Fxyz *, float, float *);
    void checkArea3D(Fxyz *, Fxyz *, KC_PrismData **, unsigned long);
    void checkSphere(Fxyz *, float, float, unsigned long, KC_PrismData **, float *, unsigned char *);
    void checkSphereWithThickness(Fxyz *, float, float, unsigned long, KC_PrismData **, float *, unsigned char *, float);
    void checkArrow(const TVec3f, const TVec3f, float *, unsigned char *, unsigned long *, KC_PrismData **, unsigned long) const;
    void KCHitSphere(KC_PrismData *, Fxyz *, float, float, float *, unsigned char *);
    void KCHitSphereWithThickness(KC_PrismData *, Fxyz *, float, float, float *, unsigned char *, float);
    bool isNearParallelNormal(const KC_PrismData *) const;
    void KCHitArrow(KC_PrismData *, const TVec3f, const TVec3f, float *, unsigned char *) const;
    s32 toIndex(const KC_PrismData *) const;
    TVec3f *getFaceNormal(const KC_PrismData *) const;
    TVec3f *getEdgeNormal1(const KC_PrismData *) const;
    TVec3f *getEdgeNormal2(const KC_PrismData *) const;
    TVec3f *getEdgeNormal3(const KC_PrismData *) const;
    TVec3f *getNormal(unsigned long) const;
    void calXvec(const Fxyz *, const Fxyz *, Fxyz *) const;
    TVec3f getPos(const KC_PrismData *, int) const;
    KC_PrismData *getPrismData(unsigned long) const;
    s32 getTriangleNum() const;
    JMapInfoIter getAttributes(unsigned long) const;
    s32 *searchBlock(long *, const unsigned long &, const unsigned long &, const unsigned long &) const;
    bool isInsideMinMaxInLocalSpace(const V3u &) const;
    bool outCheck(const TVec3f *, const TVec3f *, V3u *, V3u *) const;
    void objectSpaceToLocalSpace(V3u *, const TVec3f &) const;

    KCLFile* mFile;         // 0x0
    JMapInfo *mapInfo;      // 0x4
    f32 mMaxVertexDistance; // 0x8
};