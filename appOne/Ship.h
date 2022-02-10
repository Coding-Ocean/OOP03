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
    //�����蔻��
    class CircleComponent* mCircle;
    int mHP;
    //�L�[��������Ă���ԁA��莞�Ԃɔ���
    float mTimer;
    float mInterval;
};

