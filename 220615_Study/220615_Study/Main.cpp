#include <iostream>

using namespace std;

#define 정수 int
#define 실수 float
#define 문자 char
#define 진실 true
#define 거짓 false

#define 메인 main

#define 만약 if
#define 아니면 else

#define 혹은 ||
#define 그리고 &&

#define 증가 ++
#define 감소 --

#define 돌려준다 return

#define 출력 cout
#define 입력 cin
#define 줄바꿈 endl

#define 나누기 /
#define 더하기 +
#define 빼기 -
#define 곱하기 *

#define 더해서대입 +=
#define 빼서대입 -=
#define 곱해서대입 *=
#define 나눠서대입 /=

#define 반복 for
#define 반복문 while

#define 화면초기화 system("cls")

#define 스위치 switch
#define 기본 default
#define 멈추기 break
#define 스위치값 case

#define 는 ==
#define 은 =

#define 사이즈표시(a) sizeof(a)
#define 구조체 struct

구조체 ㄲ
{
	문자 ㄱ[128];
};

//void a(ㄲ ㄷ)
//{
//}
//
//정수 메인()
//{
//	ㄲ* ㄱ;
//	ㄲ ㄴ;
//	
//	출력 << 사이즈표시(ㄱ)		<< 줄바꿈;	//8
//	출력 << 사이즈표시(ㄱ->ㄱ)	<< 줄바꿈;	//128
//	출력 << 사이즈표시(ㄴ)		<< 줄바꿈;	//128
//	출력 << 사이즈표시(&ㄴ)		<< 줄바꿈;	//8
#include <stdio.h>

	int main(void)
	{
		int a;
		int b;
		scanf_s("%d %d", &a, &b);
		for (int i = 0; i < b; i++)
		{
			for (int i = 0; i < a; i++)
			{
				printf("*");
			}
			printf("\n");
		}
		return 0;
	}
	//템플릿 : 타입을 인자로 전달한다.

	//입출력 라이브러리
	//파일 입출력 : 파일을 만들거나 삭제하거나 조작할 수 있음
	// -표준 파일 입출력 : 콘솔 입출력
	//문자 입출력
	
	//문자열 라이브러리
	// -



	/*
	반복 (정수 수 = 일; 수 <= 백; 수 증가)
	{
		만약 (수 % 삼 == 영 혹은 수 % 오 == 영)
		{
			만약 (수 % 삼 == 0)
			{
				출력 << "Fizz";
			}
			만약 (수 % 오 == 0)
			{
				출력 << "Buzz";
			}
		}
		아니면
		{
			출력 << 수;
		}
		출력 << 줄바꿈;
	}
	돌려준다 영;
	*/
	/*
	정수 키;
	출력 << "키 입력 : ";
	입력 >> 키;

	만약(키 >= 165)
	{
		출력 << "탑승 가능";
	}
	아니면
	{
		출력 << "탑승 불가";
	}
	*/
	/*
	정수 점수[십];
	실수 평균 = 영;

	반복 (정수 수 = 영; 수 < 십; 수 증가)
	{
		입력 >> 점수[수];
		평균 더해서대입 점수[수];
	}
	출력 << 평균 나누기 십;
	*/
	/*
	//탈출게임
	//플레이어 P
	//맵 크기 10x10
	//플레이어 초기위치는 0,0
	//탈출지점 E
	//탈출 위치는 8,8
	//키 입력 ASDW

	문자 맵[10][10];
	정수 플레이어_ㄱ 은 0,플레이어_ㄴ 은 0;
	정수 나가기_ㄱ 은 8, 나가기_ㄴ 은 8;

	반복문(진실)
	{
		반복(정수 ㄱ 은 0; ㄱ < 10; ㄱ 증가)
		{
			반복(정수 ㄴ 은 0; ㄴ < 10; ㄴ 증가)
			{
				맵[ㄱ][ㄴ] 은 '#';
			}
		}

		맵[플레이어_ㄱ][플레이어_ㄴ] 은 'P';
		맵[나가기_ㄱ][나가기_ㄴ] 은 'E';

		화면초기화;

		반복(정수 ㄱ 은 0; ㄱ < 10; ㄱ 증가)
		{
			반복(정수 ㄴ 은 0; ㄴ < 10; ㄴ 증가)
			{
				출력 << 맵[ㄱ][ㄴ];
			}
			출력 << 줄바꿈;
		}
		출력 << "이동키 입력 : ";
		문자 입력키;
		입력 >> 입력키;

		스위치(입력키)
		{
			스위치값'A':
			만약(플레이어_ㄴ > 0)
			{
				플레이어_ㄴ 감소;
			}
			멈추기;
			스위치값'S':
			만약(플레이어_ㄱ < 9)
			{
				플레이어_ㄱ 증가;
			}
			멈추기;
			스위치값'D':
			만약(플레이어_ㄴ < 9)
			{
				플레이어_ㄴ 증가;
			}
			멈추기;
			스위치값'W':
			만약(플레이어_ㄱ > 0)
			{
				플레이어_ㄱ 감소;
			}
			멈추기;
		기본:
			멈추기;
		}

		만약(플레이어_ㄱ 는 나가기_ㄱ 그리고 플레이어_ㄴ 는 나가기_ㄴ)
		{
			출력 << "탈출";
			돌려준다 0;
		}
	}
	*/

