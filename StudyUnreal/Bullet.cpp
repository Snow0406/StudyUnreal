#include "Bullet.h"
#include "DoubleBuffer.h"
#include "Player.h"

void Bullet::Initialize()
{
	for (int i = 0; i < BulletCount; i++)
	{
		bullets[i]->isAct = false;
		bullets[i]->x = i;
		bullets[i]->y = 0;
		bullets[i]->color = LIGHTCYAN;
		bullets[i]->shape = "¡Ü";
	}
}

void Bullet::Progress()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!bullets[i]->isAct)
			{
				bullets[i]->x = 0 + 6;
				bullets[i]->y = 0 + 1;
				bullets[i]->isAct = true;
				break;
			}
		}
	}

	for (int i = 0; i < BulletCount; i++)
	{
		if (bullets[i]->isAct)
		{
			bullets[i]->x++;

			if (bullets[i]->x > 38)
			{
				bullets[i]->isAct = false;
				bullets[i]->x = i;
				bullets[i]->y = 0;
			}
		}
	}

}

void Bullet::Render()
{
	for (int i = 0; i < BulletCount; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(bullets[i]->x, bullets[i]->y, bullets[i]->shape, bullets[i]->color);
	}
}

void Bullet::Release()
{
}
