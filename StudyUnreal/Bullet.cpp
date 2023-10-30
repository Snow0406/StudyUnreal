#include "Bullet.h"
#include "DoubleBuffer.h"

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

}

void Bullet::Render()
{
	DoubleBuffer::Get()->WriteBuffer(x, y, shape, color);
}

void Bullet::Release()
{
}
