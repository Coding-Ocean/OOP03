#include "Ship.h"
#include "Game.h"
#include "graphic.h"
#include "window.h"
#include "input.h"
#include "InputComponent.h"
#include "AnimSpriteComponent.h"
#include "CircleComponent.h"
#include "ShipLaser.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mTimer(0.0f)
	,mInterval(0.1f)
{
    SetPosition(VECTOR2(width / 4, height / 2));
    SetScale(1.5f);

	auto ic = new InputComponent(this);
	ic->SetForwardVelocity(200);

    mAnimSprite = new AnimSpriteComponent(this);
    mAnimSprite->SetInterval(0.016f * 3);
    mAnimSprite->AddImage(loadImage("Assets\\Ship01.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship02.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship03.png"));
    mAnimSprite->AddImage(loadImage("Assets\\Ship04.png"));

	mCircle = new CircleComponent(this, 150);
	mCircle->SetRadius(20);

	mHP = 50;

	GetGame()->SetShip(this);
}

Ship::~Ship()
{
	GetGame()->SetShip(nullptr);
}

void Ship::ActorInput()
{
	if (isPress(KEY_SPACE))
	{
		mTimer += delta;
		if (mTimer >= mInterval)
		{
			mTimer -= mInterval;
			auto laser = new ShipLaser(GetGame());
			//”­ŽËˆÊ’u‚ð‚¸‚ç‚·
			float angle = GetRotation();
			laser->SetRotation(angle);
			VECTOR2 pos = GetPosition()+VECTOR2(cos(angle),sin(angle))*60;
			laser->SetPosition(pos);
		}
	}
	else
	{
		mTimer = mInterval;
	}
}

void Ship::Damage()
{
	if (--mHP <= 0)
	{
		SetState(EDead);
	}
	mAnimSprite->StartFlash(0.032f, COLOR(255, 0, 255));
}
