#include "Player.h"
#include "DoubleBuffer.h"
#include "Bullet.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	shape = "¿Ê";
	color = YELLOW;

	Bullet::_Initialize();
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
		Bullet::_Shoot(x, y);
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
