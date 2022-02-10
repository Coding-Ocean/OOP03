#pragma once
#include "Component.h"
#include "VECTOR2.h"
class CircleComponent :
    public Component
{
public:
    CircleComponent(class Actor* owner, int order=100);
    const VECTOR2& GetCenter()const;
    float GetRadius() const{ return mRadius; }
    void SetRadius(float r) { mRadius = r; }
private:
    float mRadius;
};

bool Intersect(const CircleComponent* a, const CircleComponent* b);
