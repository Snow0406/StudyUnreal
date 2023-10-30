#include "SceneManager.h"
#include "DoubleBuffer.h"

int main()
{
	auto sceneManager = SceneManager::Get();
	auto bufferManager = DoubleBuffer::Get();

	bufferManager->InitBuffer();
	sceneManager->Initialize(LOGO);

	while (true)
	{
		bufferManager->FlipBuffer();
		bufferManager->ClearBuffer();

		sceneManager->Progress();
		sceneManager->Render();
		Sleep(50);
	}

	sceneManager->Release();
	bufferManager->ReleaseBuffer();

	return 0;
}