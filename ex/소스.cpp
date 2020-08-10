#include<iostream>
#include<string>
#include<Windows.h>
#include<time.h>
using namespace std;

class  Car {
private:
	int speed;
	int gear;
	string color;
	int* p;
	const int MAX_SPEED;

public:
	Car() : MAX_SPEED(200) {
		cout << "������ ȣ��" << endl;
		speed = 0;
		gear = 1;
		color = "white";
	}
	Car(int s, int g, string c);
	~Car() {
		cout << "�Ҹ��� ȣ��" << endl;
	}
	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	void setColor(string c);
	string getColor();
	void SpeedUp();
	void SpeedDown();
	void init(int s, int g, string c);
	void show();
};

int Car::getSpeed() {
	return speed;
}
void  Car::setSpeed(int s) {
	speed = s;
}
int  Car::getGear() {
	return gear;
}
void  Car::setGear(int g) {
	gear = g;
}
string  Car::getColor() {
	return color;
}
void  Car::setColor(string c) {
	color = c;
}
void  Car::SpeedUp() {
	speed += 10;
}
void  Car::SpeedDown() {
	speed -= 10;
}
void  Car::show() {
	cout << "==========" << endl;
	cout << "�ӵ� :" << speed << endl;
	cout << "��� :" << gear << endl;
	cout << "���� :" << color << endl;
	cout << "==========" << endl;
}
Car::Car(int s, int g, string c): speed(s), gear(g), color(c) {
}



int main() {
	srand(time(NULL));
	srand(GetTickCount());
	Car car1(rand() % 200, 1, "red"), car2(rand() % 200, 1, "red");
	Car* a = new Car();
	car1.show();
	car2.show();

	if (car1.getSpeed() > car2.getSpeed()) {
		cout << "������ �¸���" << endl;
	}
	else {
		cout << "���ؼ��� �¸���" << endl;
	}
	delete(a);
}
