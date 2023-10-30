#include "Player.h"
#include "DoubleBuffer.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	isAct = true;
	shape = "¿Ê";
	color = YELLOW;
}

void Player::Progress()
{
#pragma region WASD
	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		x++;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
	}
#pragma endregion
#pragma region Act
	if (GetAsyncKeyState(VK_SPACE))
	{
		for (int i = 0; i < BulletCount; i++)
		{
			if (!bullets[i]->isAct)
			{
				bullets[i]->x = x + 6;
				bullets[i]->y = y + 1;
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
#pragma endregion

}

void Player::Render()
{
	DoubleBuffer::Get()->WriteBuffer(x, y, shape, color);
}

void Player::Release()
{
}