#include "CircleComponent.h"
#include "Actor.h"

CircleComponent::CircleComponent(Actor* owner, int order)
	:Component(owner, order)
	, mRadius(0.0f)
{
}

const VECTOR2& CircleComponent::GetCenter()const
{
	return mOwner->GetPosition();
}

bool Intersect(const CircleComponent* a, const CircleComponent* b)
{
	VECTOR2 vec = a->GetCenter() - b->GetCenter();
	float  nearest = a->GetRadius() + b->GetRadius();
	if (vec.magSq() < nearest * nearest)
	{
		return true;
	}
	return false;
}
