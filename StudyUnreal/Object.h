#pragma once
#include "Header.h"

class Object
{
public:
	int x;
	int y;
	const char* shape;
	bool isAct;
	Color color;
public:
	virtual void Initialize() abstract;
	virtual void Progress() abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;
};

