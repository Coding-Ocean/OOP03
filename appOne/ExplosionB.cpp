#include "ExplosionB.h"
#include "Game.h"
#include "graphic.h"
#include "AnimSpriteComponent.h"

ExplosionB::ExplosionB(Game* game)
	:Actor(game)
{
	auto asc = new AnimSpriteComponent(this);
	asc->SetInterval(0.016f);
	asc->NoLoop();
	char filename[128];
	for (int i = 1; i <= 64; i++)
	{
		sprintf_s(filename, "%s%03d%s", "assets\\Explosion\\type_B_", i, ".png");
		asc->AddImage(loadImage(filename));
	}
}
