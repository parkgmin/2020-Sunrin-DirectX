#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<double> vec(10);

	cout << "10���� ���ڸ� �Է����ּ��� : ";
	for (double& elem : vec) {
		cin >> elem;
	}

	for (double elem : vec) {
		cout << elem << endl;
	}
}