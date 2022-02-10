#include "InputComponent.h"
#include "input.h"

InputComponent::InputComponent(Actor* owner)
	:MoveComponent(owner)
	, mAngularVelocity(0)
	, mForwardVelocity(0)
{
}

void InputComponent::ProcessInput()
{
	//float angularSpeed = 0;
	if (isPress(KEY_D))
	{
		mAngularVelocity = 3;
		//angularSpeed = mAngularVelocity;
	}
	else if (isPress(KEY_A))
	{
		mAngularVelocity = -3;
		//angularSpeed = -mAngularVelocity;
	}
	else if (isPress(KEY_W))
	{
		mAngularVelocity = 0;
	}
	//SetAngularSpeed(angularSpeed);
	SetAngularSpeed(mAngularVelocity);

	SetForwardSpeed(mForwardVelocity);
}
