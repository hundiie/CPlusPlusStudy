#pragma once

#include "Common.h"
#include "Framework/Text.h"

typedef struct tagBullet
{
	bool	IsActive;//�Ѿ� ����
	COORD	Coord;//�Ѿ� ��ġ
	float	ActiveTime;//�Ѿ� ����ð�
	float	ElapsedTimeForMove;//�Ѿ� �̵��ð�
	Text*	Text[5];//�Ѿ� ����
	struct tagGun* Gun;//����ü ��
} Bullet;

void Bullet_Init(Bullet* bullet, struct tagGun* gun);
void Bullet_Update(Bullet* bullet);
void Bullet_Render(Bullet* bullet);
void Bullet_Release(Bullet* bullet);
void Bullet_Spawn(Bullet* bullet, int32 x, int32 y);
