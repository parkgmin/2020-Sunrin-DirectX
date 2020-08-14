#include "stdafx.h"
#include "MainScene.h"
MainScene::MainScene() {
	background = new Sprite("Image/Background.png");
	AddObject(background);
	background->setPos(0, 0);

	title = new Sprite("Image/mainname.png");
	AddObject(title);
	title->setPos(275,0);

	startButton = new Sprite("Image/in.png");
	AddObject(startButton);
	startButton->setCenter(300, 120, startButton);
	startButton->setPos(SCREEN_WIDTH / 2, 350);

	exitButton = new Sprite("Image/out.png");
	AddObject(exitButton);
	exitButton->setPos(SCREEN_WIDTH / 2, 500);

}
MainScene::~MainScene() {
	// AddObject로 추가한 오브젝트들은 자동으로 사라짐
	// 만약 AddObject 안쓰면 SAFE_DELETE(background)
}
void MainScene::Render(){
	Scene::Render();
}
void MainScene::Update(float dTime) {
	Scene::Update(dTime);
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (startButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}
		if (exitButton->IsPointInRect(inputManager->GetMousePos())) {
			PostQuitMessage(0);
			return;
		}
	}
}