#include "stdafx.h"
#include "GameScene.h"
GameScene::GameScene() {
	firstBackground = false;
	scrollSpeed = 500;
	gravity = 0;
	isJump = false;
	doubleJump = false;
	score = 0;

	
	Background *background = new Background();
	background->setPos(SCREEN_WIDTH, 0);
	backgroundList.push_back(background);

	Sprite* tmpBridge = new Sprite("Image/LoopMap.png");
	tmpBridge->setPos(0, 560);
	bridgeList.push_back(tmpBridge);

	Sprite* tempBridge = new Sprite("Image/LoopMap.png");
	tempBridge->setPos(SCREEN_WIDTH, 560);
	bridgeList.push_back(tempBridge);

	Sprite* tmpCoin = new Sprite("Image/coin-yellow.png");
	tmpCoin->setPos(SCREEN_WIDTH, 400);
	coinList.push_back(tmpCoin);


	Sprite* tmpObstacle = new Sprite("Image/Drop.png");
	tmpObstacle->setPos(SCREEN_WIDTH, 500);
	obstacleList.push_back(tmpObstacle);

	player = new Animation(50);
	player->AddFrame("Image/player1.png");
	player->AddFrame("Image/player2.png");
	player->setPos(50, 100);
	for (int i = 0; i < 4; i++) {
		numArray[i].setPos(50*i,20);
	}
	
}
GameScene::~GameScene() {

}
void GameScene::Render() {
	for (auto& background : backgroundList) {
		background->Render();
	}
	for (auto& bridge : bridgeList) {
		bridge->Render();
	}
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}
	for (auto& coin : coinList) {
		coin->Render();
	}
	for (int i = 0; i < 4; i++) {
		numArray[i].Render();
	}
	player->Render();
}
void GameScene::Update(float dTime) {
	Scene::Update(dTime);


	numArray[0].setNum(score/1000);
	numArray[1].setNum(score/100 % 10);
	numArray[2].setNum(score/10 % 10);
	numArray[3].setNum(score%10);

	if (rand() % 10 + 1 == (1)) {
		Sprite* tmpCoin = new Sprite("Image/coin-yellow.png");
		tmpCoin->setPos(SCREEN_WIDTH + 70, 400);
		coinList.push_back(tmpCoin);
	}
	gravity += 9.8f;
	player->setPos(player->getPosX(), player->getPosY() + gravity * dTime);
	if (isJump) {
		player->setPos(player->getPosX(), player->getPosY() - 400 * dTime);
		if (doubleJump) {
			player->setPos(player->getPosX(), player->getPosY() - 300 * dTime);
		}
		if (inputManager->GetKeyState(VK_UP) == KEY_DOWN || inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
			doubleJump = true;
		}
	}
	if (player->getPosY() > 370) {
		player->setPos(player->getPosX(), 370);
		doubleJump = false;
		isJump = false;
	}
	if (inputManager->GetKeyState(VK_UP) == KEY_DOWN || inputManager->GetKeyState(VK_SPACE) == KEY_DOWN) {
		if (player->getPosY() == 370) {
			isJump = true;
			gravity = 0;
		}
	}

	player->Update(dTime);
	int backgroundDiff = scrollSpeed * dTime;
	scrollSpeed += 0.1f;
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
	}
	for (auto iter = backgroundList.begin(); iter != backgroundList.end(); iter++) {

		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			float posX = (*iter)->getPosX();
			SAFE_DELETE(*iter);
			iter = backgroundList.erase(iter);

			if (firstBackground) {
				Sprite* tmpBackground = new Sprite("Image/Background.png");
				tmpBackground->setPos(posX + tmpBackground->getRect().right * 2, 0);
				backgroundList.push_back(tmpBackground);
				firstBackground = false;
			}
			else {
				Sprite* tmpBackground = new Sprite("Image/Background.png");
				tmpBackground->setPos(posX + tmpBackground->getRect().right * 2, 0);
				backgroundList.push_back(tmpBackground);
				firstBackground = true;
			}
		}
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
	}
	for (auto iter = bridgeList.begin(); iter != bridgeList.end(); iter++) {
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = bridgeList.erase(iter);

			Sprite* tempBridge = new Sprite("Image/LoopMap.png");
			tempBridge->setPos(SCREEN_WIDTH, 560);
			bridgeList.push_back(tempBridge);

			if (iter == bridgeList.end()) {
				break;
			}
		}
	}

	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
	}
	for (auto iter = coinList.begin(); iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			score++;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
		}
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
			if (iter == coinList.end()) {
				break;
			}
		}
	}

	for (auto iter = obstacleList.begin(); iter != obstacleList.end(); iter++) {
		(*iter)->setPos((*iter)->getPosX() - backgroundDiff, (*iter)->getPosY());
		if (player->IsCollisionRect(*iter)) {
			sceneManager->ChangeScene(new MainScene());
			return;
		}
		if ((*iter)->getPosX() < -SCREEN_WIDTH) { // 여기서 10은 조절해도댐
			SAFE_DELETE(*iter);
			iter = obstacleList.erase(iter);

			Sprite* tmpObstacle = new Sprite("Image/Drop.png");
			tmpObstacle->setPos(SCREEN_WIDTH, 500);
			obstacleList.push_back(tmpObstacle);
			if (iter == obstacleList.end()) {
				break;
			}
		}
	}

	for (auto iter = coinList.begin();  iter != coinList.end(); iter++) {
		if (player->IsCollisionRect((*iter))) {
			score += 1;
			SAFE_DELETE(*iter);
			iter = coinList.erase(iter);
		 }
		if (iter == coinList.end()) {
			break;
		}
	}


}