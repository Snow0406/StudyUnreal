#pragma once
#include "Scene.h"
#include "Object.h"

class Stage : public Scene
{
public:
	Object* player = NULL;
	Object* bullet = NULL;
public:
	virtual void Initialize() override;
	virtual void Progress() override;
	virtual void Render() override;
	virtual void Release() override;
};

