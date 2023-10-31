#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

