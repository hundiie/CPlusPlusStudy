#include <stdio.h>
#include <stdarg.h>

//enum Meta
//{
//	META_A,
//	META_B,
//};
//구조체 는 변수에 각가 다른 선언을 할때 용도
//그만큼 바이트 = 용량이 각기 다르며 1씩 올려야 하는게 아니다.
//패딩 바이트를 줄이기 위해 작은것에서 큰순 혹은 큰것에서 작은순으로 한다.
//패딩의 목적은 메모리 주소를 한번에 접근하기 위해
//void my(int count, ...)
//{
//	va_list args;
//	va_start(args, count);
//	for (int i = 0; i < count; i++)
//	{
//		int num = va_arg(args, int);
//		printf("%d", num);
//	}
//	__crt_va_end(args);
//}
void myprintf(char* format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		printf("%c", *format);

		if (*format == '%')
		{
			
			++format;
			if (*format == 'd')
			{
				format -= 2;
				int result = va_arg(args, int);
				printf("%d", result);
				format += 1;
			}
			else if (*format == 'c')
			{
				format -= 2;
				int result = va_arg(args, int);
				printf("%c", result);
				format += 2;
			}
			else if (*format == 's')
			{
				format -= 2;
				double result = va_arg(args, double);
				printf("%s", result);

				//for (char result = va_arg(args, char*); *word; word++);
				format += 2;
			}
		}
		++format;
	}
	va_end(args);
}

int main()
{
	myprintf(": %d, %c, %s \n", 10, 'A', "Hello");
	return 0;
}