#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void SaveFile() {
	string s;
	ofstream o("abc.txt");
	cout << "파일에 입력할 문장을 넣어주세요 : ";
	cin >> s;
	for (int i = 0; i < 3; i++) {
		o << s << endl;
	}
	o.close();
}

void ReadFile() {
	string s;
	ifstream i("README.txt");
	if (i.is_open()) {
		while (getline(i, s)) {
			cout << s << endl;
		}
	}
}

int main() {
	/*SaveFile();*/
	ReadFile();
	return 0;
}