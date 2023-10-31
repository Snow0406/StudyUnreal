#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	Object* bullets[BulletCount] = {};
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void _Initialize();
	void _Progress();
	void _Shoot(int _x, int _y);
	void _Render();
	void _Release();
};

