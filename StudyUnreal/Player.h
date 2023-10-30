#pragma once
#include "Object.h"

class Player : public Object
{
public:
	static Object* bullets[BulletCount] = {};
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

