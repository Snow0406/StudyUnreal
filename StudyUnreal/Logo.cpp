#include "Logo.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

void Logo::Initialize()
{
}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN)) SceneManager::Get()->Initialize(MENU);
}

void Logo::Render()
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "LOGO", BLUE);
}

void Logo::Release()
{
}
