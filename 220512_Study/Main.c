
#include "common.h"

#define GA_N 0x8000 & GetAsyncKeyState
#define CuserMove SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
int main(void)
{
	int x = 1;// �÷��̾� ��ǥ
	int y = 1;
	
	int shot_x=0;//�Ѿ� ���� ��ǥ
	int shot_y=0;

	int Time_Save = 0;
	int page= 0;
	int in = 0;
	clock_t Time1 = clock();
	while (1)
	{
		clock_t Time2 = clock();
		int SecTime = (Time2 - Time1) / CLOCKS_PER_SEC;//�ð� �ʸ� ���Ѵ�.

		printf("%d", SecTime);//�ð��� ǥ���Ѵ�.
	
		COORD coord = { x,y };
		CuserMove;
		printf("P");

		if (SecTime <= Time_Save&& in == 1)//�����̽��� ������ �� �ð�+3�ʸ� INTIME�� �����ؼ� 3�� ���� �Ѿ��� ���ư��� ��
		{
			COORD coord = { shot_x,shot_y };
			CuserMove;
			printf("O");
			shot_x += 2;//�Ѿ� �ӵ�
		}
		if (GA_N(VK_UP))
		{
			y--;
		}
		if (GA_N(VK_DOWN))
		{
			y++;
		}
		if (GA_N(VK_LEFT))
		{
			x--;
		}
		if (GA_N(VK_RIGHT))
		{
			x++;
		}
		if (SecTime >= Time_Save && GA_N(VK_SPACE))
		{
			shot_x = x + 1;//�Ѿ��� �����ϴ� ��ġ�� ����
			shot_y = y;//�Ѿ��� �����ϴ� ��ġ�� ����
			Time_Save = SecTime + 3;//INTIME�� ���� ��+3�ʸ� �����Ѵ�.
			in = 1;//ù �Ѿ��� �߻� �ߴ��� ���θ� üũ�Ѵ�.
		}
		Sleep(10);
		system("cls");
	}
}