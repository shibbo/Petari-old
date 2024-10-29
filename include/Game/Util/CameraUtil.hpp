#pragma once

#include <revolution.h>
#include "JSystem/JGeometry.hpp"

class LiveActor;
class ActorCameraInfo;
class CameraTargetArg;
class NameObj;

namespace MR {
    const TVec3f getCamPos();

    f32 calcCameraDistanceZ(const TVec3f &);

    bool isCameraInterpolateNearlyEnd();

    void setShakeOffset(float, float);

    void cleanEventCameraTarget_temporally();

    const MtxPtr getCameraViewMtx();
    TPos3f *getCameraInvViewMtx();

    void loadProjectionMtx();

    void startEventCamera(const ActorCameraInfo *, const char *, const CameraTargetArg &, long);
    void startEventCameraNoTarget(const ActorCameraInfo *, const char *, s32);

    f32 getAspect();
    f32 getNearZ();
    f32 getFarZ();
    f32 getFovy();
    void setCameraViewMtx(const TPos3f &, bool, bool, const TVec3f &);
    void setNearZ(f32);
    void setFovy(f32);
    void setShakeOffset(f32, f32);
    TVec3f getCamXDir();
    TVec3f getCamYDir();
    TVec3f getCamZDir();
    void createMirrorCamera();
    bool isExistMirrorCamera();

    void completeCameraParameters();
    void resetCameraMan();
    void startCameraInterpolation(u32);
    void declareEventCamera(const ActorCameraInfo *, const char *);
    void endEventCamera(const ActorCameraInfo *,const char *, bool, long);
    void declareGlobalEventCameraAbyss(const char *);
    void declareGlobalEventCameraFixedThere(const char *, bool, f32);
    void declareGlobalEventCameraDead(const char *, f32, s32, s32);
    void declareEventCameraAnim(const ActorCameraInfo *, const char *, void *);
    void declareBlackHoleCamera(const char *);
    void declareGlobalEventCamera(const char *);
    void declareEventCameraProgrammable(const char *);
    void setGameCameraTargetToPlayer();

    void setProgrammableCameraParam(const char *, const TVec3f &, const TVec3f &, const TVec3f &, bool);

    bool calcScreenPosition(TVec2f *, const TVec3f &);

    bool calcScreenPosition(TVec3f *, const TVec3f &);

    void declareEventCameraAnim(const ActorCameraInfo *, const char *, void *);

    void pauseOnAnimCamera(const ActorCameraInfo *, const char *);
    void pauseOffAnimCamera(const ActorCameraInfo *, const char *);

    bool createActorCameraInfoIfExist(const JMapInfoIter &, ActorCameraInfo **);
    void endActorCamera(const LiveActor *, const ActorCameraInfo *, bool, s32);

    bool isStartAnimCameraEnd();

    void overlayWithPreviousScreen(u32);

    void resetCamerLocalOffset();

    void drawInitFor2DModel();

    void declareCameraRegisterVec(const NameObj *, u32, TVec3f *);

    bool hasStartAnimCamera();

    void endStartAnimCamera();

    void pauseOffCameraDirector();

    bool isCameraInWater();

    void startGlobalEventCameraTargetPlayer(const char *, s32);

    bool isEventCameraActive();
    bool isEventCameraActive(const ActorCameraInfo *, const char *);

    void endGlobalEventCamera(const char *, s32, bool);
};
