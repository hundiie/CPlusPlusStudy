#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>

#include "Input.h"
#include "Play.h"
#include "Player.h"
#include "Interface.h"
#include "Scene.h"

#define cls system("cls")
#define NomalColer SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define scene_Number(a)  if (Scene::SCENE == a)


using namespace std;