#include <stdio.h>

//strcpy : 문자열 복사
//strcat : 문자열 합치기
//strlen : 글자 길이 알아내기
//strcmp : 문자열 비교
//strchr : 문자여레엇 특정 문자 찾기
//strrchr : 문자열에서 문자를  찾는데 가장 마지막으로 나타나는 위치를 찾기
//strstr : 문자열속에서 문자열찾기

char strcpy(char* str, const char* cpy)
{
	for (int i = 0; cpy[i] != '\0'; i++)
	{
		str[i] = cpy[i];
		str[i + 1] = '\0';
	}
	return str;
}
char strcat(char* str1, const char* str2)
{
	int n = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		n= i;
	}
	for (int j = 0; j < str2[j]; j++)
	{
		str1[n + 1] = str2[j];
		n++;
	}
	return str1;
}
int strlen(char* str)
{
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
char strcmp(const char* str1,const char* str2)
{
	for (int i = 0; str1[i] != '\0'; i++)
	{
		for (int j = 0; str2[j] != '\0'; j++)
		{
			if (str1[i] != str2[i])
			{
				int n1 = str1[i];
				int n2 = str2[i];
				if (n2 > n1)
				{
					return -1;
				}
				else
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
char strchr(const char* str1, const char str2)
{
	char* n;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == str2)
		{
			str1[i]
		}
	}
}
int main()
{

	char a[100] = "asdfghxz";
	char b[100] = "asdfgaxz";
	
	//글자 복사 strcpy
	//strcpy(b, a);
	//printf("%s\n", b);
	//printf("%s\n", a);
	
	//글자 합치기 strcat
	//strcat(a, b);
	//printf("%s\n", a);

	//글자 수 세기 strlen
	//int c = strlen(a);
	//printf("%d\n", c);

	//글자 비교 strcmp 
	//같으면 0 앞이 크면 1 뒤가 크면 -1
	//int d = strcmp(a, b);
	//printf("%d\n", d);

}

