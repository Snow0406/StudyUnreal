#include "Stage.h"
#include "DoubleBuffer.h"
#include "Player.h"
#include "Bullet.h"

void Stage::Initialize()
{
	player = new Player;
	bullet = new Bullet;
	player->Initialize();
	bullet->Initialize();
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
	if (bullet != nullptr)
	{
		bullet->Release();
		delete bullet;
		bullet = nullptr;
	}
}