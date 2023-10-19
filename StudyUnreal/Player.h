#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	const char* name;

	int lv;
	int exp;
	int gold;
	
	float hp;
	float atk;

	int dieCount;
public:
	void LvUp();
	void Attack();
	void UseSkill(int num);
	void GetMyInfo();

	Player(const char* _name) {
		this->name = _name;

		this->lv = 1;
		this->exp = 0;

		this->hp = 100;
		this->atk = 1;
		this->gold = 0;

		this->dieCount = 0;

		cout << "[ " << name << "´Ô °èÁ¤ »ý¼º ¿Ï·á ! ]" << endl;
	}

	~Player() {
		this->dieCount++;
		cout << "[ " << name << "´Ô Á×Àº È½¼ö +1 ]" << endl;
	}
};


