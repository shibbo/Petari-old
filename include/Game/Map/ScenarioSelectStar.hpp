#pragma once

#include "Game/Scene/MultiSceneActor.hpp"
#include "Game/MapObj/PowerStar.hpp"

class ScenarioSelectStar : public MultiSceneActor {
public:
    ScenarioSelectStar(EffectSystem *);

    virtual ~ScenarioSelectStar();
    virtual void init(const JMapInfoIter &);
    virtual void calcViewAndEntry();
    virtual void appear();
    virtual void kill();
    virtual void control();

    void tryPointing();
    void select();
    void notSelect();
    bool isAppearEnd() const;
    void setup(s32, int, const TVec3f &, s32);
    bool tryEndPointing();
    void updatePos();
    void exeAppear();
    void exeNotPointing();
    void exePointing();
    void exeEndPointing();
    void exeSelected();
    void exeSelectedMove();
    void exeNotSelected();

    int _44;
    s32 mFrame;             // 0x48
    s32 _4C;
    u8 _50;
    f32 _54;
    s32 _58;
    TVec3f _5C;
    TVec3f _68;
    int _74;
    f32 _78;
};

namespace NrvScenarioSelectStar {
    NERVE_DECL(ScenarioSelectStarNrvAppear, ScenarioSelectStar, ScenarioSelectStar::exeAppear);
    NERVE_DECL(ScenarioSelectStarNrvNotPointing, ScenarioSelectStar, ScenarioSelectStar::exeNotPointing);
    NERVE_DECL(ScenarioSelectStarNrvPointing, ScenarioSelectStar, ScenarioSelectStar::exePointing);
    NERVE_DECL(ScenarioSelectStarNrvEndPointing, ScenarioSelectStar, ScenarioSelectStar::exeEndPointing);
    NERVE_DECL(ScenarioSelectStarNrvSelected, ScenarioSelectStar, ScenarioSelectStar::exeSelected);
    NERVE_DECL(ScenarioSelectStarNrvSelectedMove, ScenarioSelectStar, ScenarioSelectStar::exeSelectedMove);
    NERVE_DECL(ScenarioSelectStarNrvNotSelected, ScenarioSelectStar, ScenarioSelectStar::exeNotSelected);
};