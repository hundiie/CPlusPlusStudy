#pragma once
#include "common.h"



using namespace std;
class Scene
{
public:
	Scene() = delete;
	~Scene() = delete;
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;


	static int SCENE;
	
	static void Change(int a)
	{
		SCENE = a;
	}


private:

};

int Scene::SCENE = {};
	Player MY;

void Init()
{


	/*MY.Init();
	
	string NAME;
	cout << "플레이어 이름 입력 : ";
	cin >> NAME;
	MY.name(NAME);
	MY.status_Seting();

	cls;
	MY.Print_stat();*/


}

void Play()
{
	scene_Number(0)//Title
	{
		string A[5] = {
			"집에간다.",
			"학원에 남는다.",
			"심심하다.",
			"피곤하다.",
			"왜 혼자지?"
		};


		choice(A, 5);


	}

}

void Renderer()
{


}