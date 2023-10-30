#pragma once
#include "Object.h"
#include "Player.h"

class Bullet : public Object
{
private:
	Object* bullets[BulletCount] = Object* Player::bullets[BulletCount];
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

