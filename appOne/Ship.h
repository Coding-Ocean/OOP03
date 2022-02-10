#pragma once
#include "Actor.h"
class Ship :
    public Actor
{
public:
    Ship(class Game* game);
    ~Ship();
    void ActorInput() override;
    void Damage();
    class CircleComponent* GetCircle()const { return mCircle; }
private:
    class AnimSpriteComponent* mAnimSprite;
    //当たり判定
    class CircleComponent* mCircle;
    int mHP;
    //キーが押されている間、一定時間に発射
    float mTimer;
    float mInterval;
};

