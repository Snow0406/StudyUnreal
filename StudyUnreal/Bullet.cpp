#include "Bullet.h"
#include "DoubleBuffer.h"
#include "Player.h"

#pragma region First
void Bullet::Initialize()
{
	isAct = false;
	x = 0;
	y = 0;
	shape = "¤·";
	color = RED;
}

void Bullet::Progress()
{
	if (isAct)
	{
		x++;
		if (x > BufferWidth / 2 - 2) isAct = false;
	}
}

void Bullet::Render()
{
	if (isAct) DoubleBuffer::Get()->WriteBuffer(x, y, shape, color);
}

void Bullet::Release() {}
#pragma endregion
#pragma region Second
void Bullet::_Initialize()
{
	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i] = new Bullet;
		bullets[i]->Initialize();
	}
}

void Bullet::_Progress()
{
	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i]->Progress();
	}
}

void Bullet::_Shoot(int _x, int _y)
{
	for (int i = 0; i < BulletCount; i++)
	{
		if (!bullets[i]->GetAct())
		{
			bullets[i]->SetAct(true);
			bullets[i]->SetPos(_x, _y);
			break;
		}
	}
}

void Bullet::_Render()
{
	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i]->Render();
	}
}

void Bullet::_Release()
{
	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i]->Release();
		delete bullets[i];
		bullets[i] = nullptr;
	}
}
#pragma endregion
