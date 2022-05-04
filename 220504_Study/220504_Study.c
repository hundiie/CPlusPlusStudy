#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>
#include <errno.h>

void myprintf(char* format, ...)
{
	va_list wo;
	va_start(wo, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
			{
				int d = va_arg(wo, int);
				int k = d;
				
				printf("%d",d); // putchar로 숫자 출력 짜증남
				format++; 
			}
				break;
			case 'c':
			{
				int c = va_arg(wo, int);
				putchar(c);
				format++;
			}
				break;
			case 's':
			{
				char* s = va_arg(wo, char*);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
				}
				format++;
			}
				break;
			default:
				break;
			}
		}
		putchar(*format);
		format++;
	}

}//myprintf("hello : %d %c %s ", 112345 , 'A', "string");
//math 는 계산지원
//exp 제곱 구하기 <- 유용함

void show_errno(void)
{
	const char* err_info = "unknown error";
	switch (errno) {
	case EDOM:
		err_info = "domain error";
		break;
	case EILSEQ:
		err_info = "illegal sequence";
		break;
	case ERANGE:
		err_info = "pole or range error";
		break;
	case 0:
		err_info = "no error";
	}
	fputs(err_info, stdout);
	puts(" occurred");
}

int main()
{
	// 메모리는 자원이다.
	// 자원은 시스템으로부터 빌려와서 돌려줘야한다.
	// 돌려주지 않으면 메모리 누수가 발생한다.
	// free(p) 메모리 반환
	
	//int n = 1;// 메모리 무한으로 늘리기
	//while (1)
	//{
	//	int* p = malloc(sizeof(int) * n);
	//}

	//메모리를 관리 할 때 문제
	// 1. 언제 사용이 끝나는지 불명확 >반환안됨 > 누수
	// 2. 반환이 됐는데 접근하는 경우 > 유효하지 않은 메모리 접근(댕글리 포인터)> 메모리 접근 위반
	// 3. 반환하고 또 반환하는 경우 > 이중 해제 > 메모리 접근 위반
	//free(p);
	// p = NULL;
	// p를 반환 후 널값으로 만들면 2, 3 은 방지가능

	//1. 파일을 다루는 객체 생성
	FILE* fp = NULL;

	//2. 파일을 연다.
	//텍스트 파일 : 텍스트 에디터로 볼 수 있는 읽을 수 있는 파일
	//바이너리 파일 : 그 이외 모든 파일

	if (0 != fopen_s(&fp, "Meta", "w"))
	{
		printf("오류 발생");//성공하면 0 반환함
		return 1;
	}
	//3.컨텐츠 작성
	//텍스트 파일에 쓰는 함수 : fputs() / fputc() / fprintf()
	//바이너리 파일에 쓰는 함수 : fwrite()
	fputs("Hello File!", fp);// string 문자열 추가
	fputc('Z', fp);//char 문자 하나 추가 
	fprintf(fp, "\n여왕 : %s\n", "김균지");//printf 처럼 사용 가능

	fclose(fp);

	
	
	if (0 != fopen_s(&fp, "Meta", "r"))
	{
		printf("오류 발생");//성공하면 0 반환함
		return 1;
	}
	
	//텍스트 파일에서 읽어 들일 수 있는 함수 : fgets() / fgetc() / fscanf()
	//바이너리 : fread()
	
	char ch = fgetc(fp);
	char str1[128] = "";
	fgets(str1, sizeof(str1), fp);
	char str2[128] = "";
	fscanf(fp, "여왕 : %s", str2, sizeof(str2));

	printf("읽은 문자 : %c\n", ch);
	printf("읽은 문자열 : %s\n", str1);
	printf("읽은 문자 : %s\n", str2);

	fclose(fp);


	//바이너리 파일

	if (0 != fopen_s(&fp, "Meta1", "wb"))// b를 붙이면 바이너리로 인식함
	{
		printf("오류 발생");//성공하면 0 반환함
		return 1;
	}

	struct Student
	{
		int Age;
		enum
		{
			A, B, O, AB
		} Blood;
		char name[24];
	};

	struct Student s = { 20, A, "최선문" };

	if (1 != fwrite(&s, sizeof(s), 1, fp))
	{
		printf("오류 발생");//성공하면 0 반환함
		fclose(fp);
		return 1;
	}


	fclose(fp);

	if (0 != fopen_s(&fp, "Meta1", "rb"))// b를 붙이면 바이너리로 인식함
	{
		printf("오류 발생");//성공하면 0 반환함
		fclose(fp);
		return 1;
	}

	struct Student s2 = { 0 };
	
	if (1 != fread(&s2, sizeof(s2), 1,fp))
	{
		printf("오류 발생");//성공하면 0 반환함
		fclose(fp);
		return 1;
	}

	printf("나이 :%d 피 :%d 이름 :%s\n",s2.Age, s2.Blood, s2.name);

	fclose(fp);
	
	return 0;

}

	//.txt와 같은 확장자 없어도 됨 // mata라는 텍스트 파일을 연다.
	//r read		읽을 못적		파일 없으면 에러
	//w write		수정 할 목적		파일 없으면 만듬
	// a apppend	추가할 목적		파일 없으면 만듬



	//time_t result = time(NULL);// 시간 보기.
	//if (result != (time_t)(-1))
	//	printf("현재 시간 %s",asctime(gmtime(&result)));


//	int min;
//	int max;
//	scanf("%d %d", &min, &max);
//
//	int count = 0;
//	for (int i = 0; i < max - min; i++)
//	{/*
//		if (max == 1)
//		{
//			count++;
//		}*/
//		for (int j = min + 1; j < max; j++)
//		{
//			if (max % j == 0)
//			{
//				count++;
//				break;
//			}
//		}
//	}
//	printf("%d", max - min - count);

	/*// 소수
	int T;

	scanf("%d", &T);

	int count = 0;
	for (int i = 0; i < T; i++)
	{
		int num;
		
		scanf("%d,", &num);
		if (num == 1)
		{
			count++;
		}
		for (int j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				count++;
				break;
			}
		}
	}
	printf("%d",T -count);
}*/