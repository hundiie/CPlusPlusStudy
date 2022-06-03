#pragma once
#include "Scene.h"

class SceneManager
{
public:
	SceneManager() = delete;
	~SceneManager() = delete;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

	static void Init(){ _currentScene->Init(); };
	static void Update() { _currentScene->Update(); };
	static void Render() { _currentScene->Render(); };
	static void Release() { _currentScene->Release(); };

	static bool IsSetNextScene() { return _nextScene != nullptr; };
	static void SetNextScene();
	static void Change()
	{
		if (_nextScene == nullptr)
		{
			return;
		}

		_currentScene->Release();
		_currentScene = _nextScene;
		_currentScene->Init();
		_nextScene == nullptr;

	}
private:
	static Scene* _currentScene;
	static Scene* _nextScene;
};

Scene* SceneManager::_currentScene;
Scene* SceneManager::_nextScene;
