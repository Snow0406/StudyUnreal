#include "Stage.h"
#include "DoubleBuffer.h"
#include "Player.h"
#include "Bullet.h"

void Stage::Initialize()
{
	player = new Player;
	player->Initialize();

	spawnTime = 0;
}

void Stage::Progress()
{
	spawnTime++;
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