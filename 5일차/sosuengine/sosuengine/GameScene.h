#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Number.h"
#include "Background.h"
#include <list>
class GameScene : public Scene
{
private:
	Animation* player;
	std::list<Background*> backgroundList;
	std::list<Sprite*> bridgeList;
	std::list<Sprite*> obstacleList;
	std::list<Sprite*> coinList;

	int score;
	
	bool firstBackground;
	float scrollSpeed;
	float gravity;
	bool doubleJump, isJump;
	Number numArray[4];
public:
	GameScene();
	~GameScene();
	void Render();
	void Update(float dTime);
};