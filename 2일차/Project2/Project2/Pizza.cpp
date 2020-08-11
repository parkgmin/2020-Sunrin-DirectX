#include <iostream>
using namespace std;

int DividePizza(int pizzaSlice, int person);

int main() {
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;

	try {
		cout << "���� �������� �Է��ϼ��� : ";
		cin >> pizza_slices;
		cout << "��� ���� �Է��ϼ��� : ";
		cin >> persons;
		
		slices_per_person = DividePizza(pizza_slices, persons);
		cout << "�� ����� ���ڴ� " << slices_per_person << "�Դϴ�" << endl;

	}
	catch (int e) {
		cout << "����� " << e << "���Դϴ�.";
	}

	return 0;
}

int DividePizza(int pizzaSlice, int person) {
	if (person == 0) {
		throw person;
	}
	return pizzaSlice / person;
}