#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

INT WINAPI WinMain(HINSTANCE hInstance
	, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {
	srand(GetTickCount()); 

	Console console;
	Application app;

	if (CONSOLE_ON) {
		console.OpenConsole();
	}

	std::cout << "아령하세여~~~잇!" << std::endl;

	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));


	app.InitDeltaTime();
	app.InitManager();

	return app.DoMainLoop(new MainScene());

}