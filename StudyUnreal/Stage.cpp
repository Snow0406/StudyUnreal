#include "Stage.h"

void Stage::Initialize()
{
	player = new Player;
	player->Initialize();
}

void Stage::Progress()
{
	player->Progress();
}

void Stage::Render()
{
	player->Render();
}

void Stage::Release()
{
	if (player != nullptr)
	{
		player->Release();
		delete player;
		player = nullptr;
	}
}