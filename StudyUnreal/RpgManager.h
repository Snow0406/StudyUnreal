#pragma once
#include "Player.h"

class RpgManager
{
private:
	Player* player = NULL;
public:
	void Progress();
	void Render();

	RpgManager() {

	}
};

