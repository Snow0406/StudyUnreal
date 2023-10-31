#pragma once
#include "Header.h"

class Object
{
protected:
	bool isAct;
	int x;
	int y;
	const char* shape;
	Color color;

public:
	bool GetAct() { return isAct;  }
	void SetAct(bool _act) { isAct = _act; }
	void SetPos(int _x, int _y) { x = _x, y = _y; }

public:
	virtual void Initialize() abstract;
	virtual void Progress() abstract;
	virtual void Render() abstract;
	virtual void Release() abstract;
};

