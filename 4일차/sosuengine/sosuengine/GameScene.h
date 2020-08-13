#pragma once
#include "Scene.h"
#include "Sprite.h"
#include <list>
#include "Animation.h"

class GameScene :
	public Scene
{
private:
	std::list<Sprite*>backgroundList;
	std::list<Sprite*>bridgeList;
	Animation* player;
	bool isGround;
	float currentYPower;
	float gravity;
	int jumpCount;
	int maxJumpCount;

public:
	GameScene();
	~GameScene();

	void Render();
	void Update(float dTime);
};

