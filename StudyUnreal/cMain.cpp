#include "DoubleBuffer.h"
#include "Stage.h"

int main()
{
	auto doubleBuffer = DoubleBuffer::Get();

	doubleBuffer->InitBuffer();

	Stage stage;
	stage.Initialize();

	while (true)
	{
		doubleBuffer->FlipBuffer();
		doubleBuffer->ClearBuffer();

		//Todo
		stage.Progress();
		stage.Render();

		Sleep(20);
	}

	stage.Release();
	doubleBuffer->ReleaseBuffer();

	return 0;
}