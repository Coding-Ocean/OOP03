#include "AnimSpriteComponent.h"
#include "window.h"
#include "Actor.h"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, mCurIdx(0)
	, mTimer(0.0f)
	, mInterval(0.0f)
	, mLoop(true)
{
}

void AnimSpriteComponent::AddImage(int img)
{
	mImgs.emplace_back(img);
}

void AnimSpriteComponent::Update()
{
	SpriteComponent::Update();

	mTimer += delta;
	if (mTimer > mInterval)
	{
		mTimer -= mInterval;
		mCurIdx++;
		if (mCurIdx >= mImgs.size())
		{
			if (mLoop)
			{
				mCurIdx %= mImgs.size();
			}
			else
			{
				mOwner->SetState(Actor::EDead);
			}
		}
	}
}

void AnimSpriteComponent::Draw()
{
	SetImage(mImgs[mCurIdx]);
	SpriteComponent::Draw();
}

