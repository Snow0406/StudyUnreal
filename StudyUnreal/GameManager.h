#pragma once
#include "Player.h"
#include "Screen.h"

class GameManager
{
public:
	Player* player;
	Screen* screen;
public:
	void Progress();
};

