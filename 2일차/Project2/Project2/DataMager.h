#pragma once
#include<fstream>
#include<string>

#define DataMgr DataMager::instance()
using namespace std;

class DataMager
{
private:
	string name = "플레이어";
	int level = 37;
	int exp = 1000000;
public:
	DataMager() {

	}
	static DataMager* instance() {
		static DataMager inst;
		return &inst;
	}
	int getLevel() {
		return level;
	}
};

