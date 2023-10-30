#pragma once
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* instanse;
public:
	static SceneManager* Get()
	{
		if (instanse == NULL) instanse = new SceneManager;
		return instanse;
	}
private:
	Scene* currentScene = NULL;
public:
	void Initialize(SCENE_ID id);
	void Progress();
	void Render();
	void Release();
};

