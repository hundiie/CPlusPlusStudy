#pragma once

#include "Common.h"
#include "Framework/Text.h"

typedef struct tagBullet
{
	bool	IsActive;//총알 유무
	COORD	Coord;//총알 위치
	float	ActiveTime;//총알 존재시간
	float	ElapsedTimeForMove;//총알 이동시간
	Text*	Text[5];//총알 문자
	struct tagGun* Gun;//구조체 건
} Bullet;

void Bullet_Init(Bullet* bullet, struct tagGun* gun);
void Bullet_Update(Bullet* bullet);
void Bullet_Render(Bullet* bullet);
void Bullet_Release(Bullet* bullet);
void Bullet_Spawn(Bullet* bullet, int32 x, int32 y);
