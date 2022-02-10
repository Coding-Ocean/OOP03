#include "Rock.h"
#include "rand.h"
#include "graphic.h"
#include "MoveComponent.h"
#include "AnimSpriteComponent.h"
#include "CircleComponent.h"
#include "Game.h"
#include "ExplosionB.h"

Rock::Rock(Game* game)
	:Actor(game)
{
	VECTOR2 pos(random(width), random(height));
	if (random() % 2)
	{
		if (pos.x > width / 2)pos.x += width / 2;
		else pos.x -= width / 2;
	}
	else
	{
		if (pos.y > height / 2)pos.y += height / 2;
		else pos.y -= height / 2;
	}
	SetPosition(pos);
	SetRotation(random(6.28f));
	
	auto mc = new MoveComponent(this);
	mc->SetForwardSpeed(120.0f);

	mAnimSprite = new AnimSpriteComponent(this);
	char filename[128];
	for (int i = 1; i <= 16; i++)
	{
		sprintf_s(filename, "%s%03d%s", "assets\\Rock\\rock_", i, ".png");
		mAnimSprite->SetInterval(random(0.016f,0.016f*3));
		mAnimSprite->AddImage(loadImage(filename));
	}

	mCircle = new CircleComponent(this, 110);
	mCircle->SetRadius(20);

	mHP = 1;

	game->AddRock(this);
}

Rock::~Rock()
{
	GetGame()->RemoveRock(this);
}

void Rock::Damage()
{
	if (--mHP <= 0)
	{
		auto a = new ExplosionB(GetGame());
		a->SetPosition(GetPosition());
		a->SetRotation(GetRotation());

		SetState(EDead);

		new Rock(GetGame());
	}
	mAnimSprite->StartFlash(0.032f, COLOR(255, 0, 0));
}
