#pragma once
class Player
{
private:
	int x;
	int y;
	const char* shape;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
};