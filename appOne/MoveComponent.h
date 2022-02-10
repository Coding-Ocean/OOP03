#pragma once
#include "Component.h"
#include "VECTOR2.h"

class MoveComponent :
    public Component
{
public:
    MoveComponent(class Actor* owner, int order=100);
    void Update() override;
    void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
    void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
    float GetSpeed() { return mForwardSpeed; }
private:
    float mForwardSpeed;
    float mAngularSpeed;
};

