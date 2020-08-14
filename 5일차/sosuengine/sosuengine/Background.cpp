#include "stdafx.h"
#include "Background.h"

Background::Background() {
	background = new Sprite("Image / Background.png");
}

Background::~Background() {

}

void Background::Render() {
	Object::Render();
	background->Render();
}

void Background::Update(float dTime) {
	Object::Update(dTime);

	setPos(getPosX() - 500 * dTime, getPosY());

}