#pragma once
#include "Player.h"
class Stage
{
private:
	Player* player = nullptr;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};