#pragma once
#include "Header.h"
class DoubleBuffer
{
private:
	static DoubleBuffer* instance;
public:
	static DoubleBuffer* Get()
	{
		if (instance == nullptr)
		{
			instance = new DoubleBuffer;
		}

		return instance;
	}
private:
	HANDLE hBuffer[2]; // 창 두개를 제어하는 핸들
	int screenIndex;   // hBuffer[screenIndex], screenIndex == 0 or 1
public:
	//버퍼 초기화
	void InitBuffer();
	//버퍼 활성화 [0]->[1] / [1]->[0]
	void FlipBuffer();
	//화면 지우는거
	void ClearBuffer();
	//화면 그려주기(x좌표, y좌표, 모양, 색깔)
	void WriteBuffer(int x, int y, const char* shape, int color);
	//버퍼 해제
	void ReleaseBuffer();
};