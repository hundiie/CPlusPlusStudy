#pragma once
#include <iostream>
#include <string>

class Scene
{
public:
	virtual void Init() = 0;		// 씬을 초기화 하는 함수
	virtual void Update() = 0;	// 업데이트
	virtual void Render() = 0;	// 렌더
	virtual void Release() = 0;	// 씬에서 사용한 자원을 정리
};

