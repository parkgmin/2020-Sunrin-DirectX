#include "stdafx.h"
#include "Number.h"

Number::Number() {
	currentNum = 0;

	num[0] = new Sprite("Image/number-0.png");
	num[1] = new Sprite("Image/number-1.png");
	num[2] = new Sprite("Image/number-2.png");
	num[3] = new Sprite("Image/number-3.png");
	num[4] = new Sprite("Image/number-4.png");
	num[5] = new Sprite("Image/number-5.png");
	num[6] = new Sprite("Image/number-6.png");
	num[7] = new Sprite("Image/number-7.png");
	num[8] = new Sprite("Image/number-8.png");
	num[9] = new Sprite("Image/number-9.png");

	for (int i = 0; i < 10; i++) {
		AddChild(num[i]);
	}
}

Number::~Number() {
	for (int i = 0; i < 10; i++) {
		SAFE_DELETE(num[i]);
	 }
}

void Number::Update(float dTime) {
	Object::Update(dTime);
}

void Number::Render() {
	Object::Render();
	num[currentNum]->Render();
}

void Number::setNum(int num) {
	currentNum = num;
}

int Number::getNum() {
	return currentNum;
}


