#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void game()
{
	playgame();
	char mineboard[ROWS][COLS] = { 0 };//����׵�����
	char showboard[ROWS][COLS] = { 0 };//չʾ��Ϣ������
	initboard(mineboard, ROWS, COLS, '0');
	//printboard(mineboard, ROW, COL);
	initboard(showboard, ROWS, COLS, '*');
	printboard(showboard, ROW, COL);
	setmine(mineboard, MINE_NUM, ROW, COL);
	//printboard(mineboard, ROW, COL);
	play(mineboard, showboard, ROW, COL);

}

int main()
{
	int Input = 0;
	do 
	{
		srand((unsigned int)time(NULL));//�����������
		menu();
		printf("��ѡ��>:");
		scanf("%d", &Input);
		switch (Input)
		{
		case 1:game(); 
			break;
		case 0:printf("�˳���Ϸ\n");
			break;
		default:printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (Input);
	return 0;
}