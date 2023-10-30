#pragma once
#include "Object.h"
#include "Player.h"

class Bullet : public Object
{
public:
	Bullet* bullets[BulletCount] = {};
public:
	bool isAct;
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

