#include "MoveComponent.h"
#include "Actor.h"
#include "window.h"
#include "graphic.h"

MoveComponent::MoveComponent(Actor* owner, int order)
	:Component(owner, order)
	, mForwardSpeed(0)
	, mAngularSpeed(0)
{
}

void MoveComponent::Update()
{
	if (mAngularSpeed != 0.0f)
	{
		float angle = mOwner->GetRotation() + mAngularSpeed*delta;
		mOwner->SetRotation(angle);
	}
	if (mForwardSpeed != 0.0f)
	{
		VECTOR2 pos = mOwner->GetPosition();
		float angle = mOwner->GetRotation();
		pos.x += cos(angle) * mForwardSpeed*delta;
		pos.y += sin(angle) * mForwardSpeed*delta;
		if (pos.x < -50)pos.x = width + 50;
		if (pos.x > width + 50)pos.x = -50;
		if (pos.y < -50)pos.y = height + 50;
		if (pos.y > height + 50)pos.y = -50;
		mOwner->SetPosition(pos);
	}
}
