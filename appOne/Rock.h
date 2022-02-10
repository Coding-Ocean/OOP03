#pragma once
#include "Actor.h"
class Rock :
    public Actor
{
public:
    Rock(class Game* game);
    ~Rock();
    void Damage();
    class CircleComponent* GetCircle() { return mCircle; }
private:
    class AnimSpriteComponent* mAnimSprite;
    class CircleComponent* mCircle;
    float mHP;
};

