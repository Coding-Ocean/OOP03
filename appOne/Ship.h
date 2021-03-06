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
    class RectComponent* GetRect()const { return mRect; }
private:
    class AnimSpriteComponent* mAnimSprite;
    //当たり判定
    class RectComponent* mRect;
    int mHP;
    //キーが押されている間、一定時間に発射
    float mTimer;
    float mInterval;
};

