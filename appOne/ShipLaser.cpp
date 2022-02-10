#include "ShipLaser.h"
#include "graphic.h"
#include "window.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"
#include "Game.h"
#include "Rock.h"

ShipLaser::ShipLaser(Game* game)
	:Actor(game)
{
	mLifeTime = 1.5f;

	mMove = new MoveComponent(this,50);
	mMove->SetForwardSpeed(600);

	auto sc = new SpriteComponent(this, 50);
	sc->SetImage(loadImage("Assets\\Laser.png"));

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(9);
}

void ShipLaser::UpdateActor()
{
	mLifeTime -= delta;
	if (mLifeTime<=0.0f)
	{
		SetState(EDead);
	}
	else{
		//Õ“Ë”»’è
		for (auto rock : GetGame()->GetRocks()) {
			if (Intersect(mCircle, rock->GetCircle()))
			{
				SetState(EDead);
				rock->Damage();
			}
		}
	}
}
