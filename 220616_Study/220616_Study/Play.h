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
	cout << "�÷��̾� �̸� �Է� : ";
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
			"��������.",
			"�п��� ���´�.",
			"�ɽ��ϴ�.",
			"�ǰ��ϴ�.",
			"�� ȥ����?"
		};


		choice(A, 5);


	}

}

void Renderer()
{


}