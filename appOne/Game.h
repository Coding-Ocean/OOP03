#pragma once
#include <vector>
#include "VECTOR2.h"
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*>mActors;
	std::vector<class SpriteComponent*>mSprites;

	// Update中フラッグ
	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors;

	//このGame固有の記述
public:
	void AddRock(class Rock* rock);
	void RemoveRock(class Rock* rock);
	std::vector<class Rock*>& GetRocks() { return mRocks; }
	void SetShip(class Ship* ship) { mShip = ship; }
	class Ship* GetShip() { return mShip; }
private:
	std::vector<class Rock*> mRocks;
	class Ship* mShip;
};

