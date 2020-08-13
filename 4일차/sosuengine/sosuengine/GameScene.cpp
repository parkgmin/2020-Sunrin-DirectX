#include "stdafx.h"
#include "GameScene.h"
GameScene::GameScene():
	isGround(false),
	currentYPower(0),
	jumpCount(0),
	maxJumpCount(2),
	gravity(9.81f)
{
	backgroundList.push_back(new Sprite("Image/Background.png"));
	Sprite* tmpBackground = new Sprite("Image/Background.png");
	tmpBackground->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(tmpBackground);

	tmpBackground = new Sprite("Image/LoopMap.png");
	tmpBackground->setPos(0,500);
	bridgeList.push_back(tmpBackground);

	tmpBackground = new Sprite("Image/LoopMap.png");
	tmpBackground->setPos(SCREEN_WIDTH, 500);
	bridgeList.push_back(tmpBackground);

	player = new Animation(7);
	player->AddFrame("Image/player-run.png");
	player->AddFrame("Image/player-stop.png");
	player->setPos(50, 100);

	


}
GameScene::~GameScene() {

}
void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& background : bridgeList) {
		background->Render();
	}
	player->Render();
}
void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	player->Update(dTime);
	int tmp = 500 * dTime;

	//Player Movement --------------------------
	if (inputManager->GetKeyState(' ') == KEY_DOWN) {
		if (jumpCount > 0) {
			currentYPower -= 500;
			jumpCount--;
			isGround = false;
		}
	}
	else if (isGround) {
		currentYPower = 0;
		jumpCount = maxJumpCount;
	}
	else {
		currentYPower += 100 * gravity * dTime;
	}

	player->setPos(player->getPosX(), player->getPosY() + currentYPower * dTime);

	if (player->getPosY() + player->getRect().bottom > 500) {
		player->setPos(player->getPosX(), 500 - player->getRect().bottom);
		isGround = true;
	}

	//------------------------------------------

	for (auto iter = backgroundList.begin(); 
		iter != backgroundList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - tmp, 
			(*iter)->getPosY());

		if ((*iter)->getPosX() < -(*iter)->getRect().right) {
			(*iter)->setPos((*iter)->getPosX() + (*iter)->getRect().right*2, (*iter)->getPosY());
		}
	}

	for (auto iter = bridgeList.begin();
		iter != bridgeList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - tmp,
			(*iter)->getPosY());

		if ((*iter)->getPosX() < -(*iter)->getRect().right) {
			(*iter)->setPos((*iter)->getPosX() + (*iter)->getRect().right * 2, (*iter)->getPosY());
		}
	}
}