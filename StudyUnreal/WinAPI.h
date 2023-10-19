#pragma once
#include <Windows.h>

class WinAPI
{
protected:
	//깜박깜박 거리는 커서 없애주는 함수
	void HideCursor()
	{
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 1;
		info.bVisible = false;

		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

	//X,Y값 받아서 커서의 좌표를 이동시켜주는 함수
	void SetPosition(int x, int y)
	{
		COORD pos;
		pos.X = x * 2;
		pos.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	//color값 받아서 색깔 바꿔주는 아이
	void SetColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
};

