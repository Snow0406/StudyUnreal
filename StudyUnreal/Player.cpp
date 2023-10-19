#include "Player.h"

using namespace std;

#define SKILL_MAX_NUM 1

enum Skill
{
	Heal = 1
};

void Player::LvUp() {
	if (this->lv * 100 > this->exp) return;
	this->lv++;
	this->exp = 0;
}

void Player::Attack() {
}

void Player::UseSkill(int num) {
	if (1 > num || SKILL_MAX_NUM < num)
	{
		cout << "[ " << name << "´Ô ×´Â ½ºÅ³ÀÌ¾ß ! ]" << endl;
		return;
	}
}

void Player::GetMyInfo() {
	cout << "[ " << this->name << "´ÔÀÇ Á¤º¸ ]" << endl << endl
		<< "Level : " << this->lv << endl
		<< "Exp : " << this->exp << "/" << (this->lv * this->exp) << endl << endl
		<< "Hp : " << this->hp << "/100" << endl
		<< "Atk : " << this->atk << endl
		<< "Gold : " << this->gold << endl;
}
