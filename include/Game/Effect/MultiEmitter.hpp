#pragma once

class EffectSystem;

class MultiEmitter {
public:
    void forceDelete(EffectSystem *);
    void create(EffectSystem *);
};