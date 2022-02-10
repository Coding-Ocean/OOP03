#pragma once
#include "Actor.h"
class ShipLaser :
    public Actor
{
public:
    ShipLaser(class Game*);
    void UpdateActor() override;
private:
    class MoveComponent* mMove;
    class CircleComponent* mCircle;
    float mLifeTime;
};

