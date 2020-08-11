#include "NoPersonException.h"
#include <iostream>
using namespace std;

int main() {
	int pizzaSlices = 12;
	int persons = 0;
	int slicesPerPerson = 0;

	try {
		cout << "��� ���� �Է��ϼ��� : ";
		cin >> persons;
		if (persons <= 0) {
			throw NoPersonException(persons);
		}

		slicesPerPerson = pizzaSlices / persons;
		cout << "�� ����� ���ڴ� " << slicesPerPerson << "�Դϴ�." << endl;

	}
	catch (NoPersonException e) {
		cout << "���� : ����� " << e.getPersons() << "�� �Դϴ�." << endl;
	}
}
