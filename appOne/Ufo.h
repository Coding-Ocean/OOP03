#pragma once
#include "Actor.h"
class Ufo :
    public Actor
{
public:
    Ufo(class Game* game);
    ~Ufo();
    void UpdateActor() override;
    void SetTheta(float theta) { mTheta = theta; }
    void Damage();
    class RectComponent* GetRect() { return mRect; }
private:
    //当たり判定
    class RectComponent* mRect;
    int mHP;
    //上下移動用
    class MoveComponent* mMove;
    float mTheta;
    //
    class AnimSpriteComponent* mAnimSprite;
    //一定時間に発射
    float mTimer;
    float mInterval;
};

