#pragma once
#include <iostream>

class Player
{
public:
	int level = 1;
	int money = 0;

	Player();
	~Player();

	int GetUserID();

private:
	int userID = 1004;
};

int Player::GetUserID() { return userID; }
Player::Player() { std::cout << "캐릭터 생성" << std::endl; }
Player::~Player() { std::cout << "캐릭터 삭제" << std::endl; }

