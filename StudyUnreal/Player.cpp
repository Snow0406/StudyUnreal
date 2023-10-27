#include "Player.h"
#include "DoubleBuffer.h"

void Player::Initialize()
{
	x = 10;
	y = 10;
	shape = "¿Ê";
}

void Player::Progress()
{
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
}

void Player::Render()
{
	DoubleBuffer::Get()->WriteBuffer(x, y, shape, 14);
}

void Player::Release()
{
}