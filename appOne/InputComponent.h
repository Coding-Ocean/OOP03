#pragma once
#include "MoveComponent.h"
class InputComponent :
    public MoveComponent
{
public:
	// Lower update order to update first
	InputComponent(class Actor* owner);
	void ProcessInput() override;
	void SetAngularVelocity(float vel) { mAngularVelocity = vel; }
	void SetForwardVelocity(float vel) { mForwardVelocity = vel; }
private:
	float mAngularVelocity;
	float mForwardVelocity;
};
