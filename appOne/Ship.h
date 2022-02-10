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
    //“–‚½‚è”»’è
    class CircleComponent* mCircle;
    int mHP;
    //ƒL[‚ª‰Ÿ‚³‚ê‚Ä‚¢‚éŠÔAˆê’èŠÔ‚É”­Ë
    float mTimer;
    float mInterval;
};

