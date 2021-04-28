#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("*** 1.play        0.exit ***\n");
	printf("****************************\n");
}

void playgame()
{
	printf("��Ϸ��ʼ");
	Sleep(650);
	system("cls");
}

void initboard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}

void printboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		if (1 == i)
		{
			for (j = 0; j <= col; j++)
			{
				printf(" %d", j);
			}
			printf("\n");
		}
		for (j = 1; j <= col; j++)
		{
			if (1 == j)
			{
				printf(" %d", i);
			}
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int mine_num, int row, int col)
{
	while (mine_num)
	{
		int x = rand() % row + 1;//���������
		int y = rand() % col + 1;//���������
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			mine_num--;
		}
	}
}

int find(char board[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	if (x > 0 && x < ROW && y > 0 && y < COL)
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (board[i][j] == '1')
					count++;
			}
		}
	}
	return count;
}

void spread(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int x, int y)
{
	//if (x > 0 && x <= ROW && y > 0 && y <= COL)
	//{
		showboard[x][y] = ' ';
		//*pn += 1;
		int i = 0;
		int j = 0;
		int ret = 0;

		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (i > 0 && i <= ROW && j > 0 && j <= COL && mineboard[i][j] != '1' && showboard[i][j] == '*')
				{
					ret = find(mineboard, i, j);
					if (!ret)
					{
						spread(showboard, mineboard, i, j);
					}
					if (ret)
					{
						showboard[i][j] = ret + '0';
						//*pn += 1;
					}
					else if (showboard[i][j] == '*')
					{
						showboard[i][j] = ' ';
						//*pn += 1;
					}
				}
				
			}
		}
	//}
}
int Isblank(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] != '*')
			{
				n++;
			}
		}
	}
	return n;
}

void play(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int n = 0;//��¼���ų��ĸ���
	
	while (row * col - MINE_NUM - n)
	{
		printf("���������꣬�Կո��������>:");
		scanf("%d %d", &x, &y);
		if (x > ROW || y > COL || x < 1 || y < 1)
		{
			printf("����Ƿ�������������\n");
			continue;
		}
		if (mineboard[x][y] != '1')
		{
			int ret = find(mineboard, x, y);
			if (ret != 0)
			{
				showboard[x][y] = ret + '0';
				//n++;
			}
			else
			{
				//showboard[x][y] = ' ';
				spread(showboard, mineboard, x, y);
				
			}
			n = Isblank(showboard, row, col);//����Ѿ��ж��ٸ����Ѿ��ų�
			system("cls");
			printboard(showboard, row, col);
		}
		else
		{
			break;
		}
	}
	if (row * col - MINE_NUM - n)
	{
		printf("���ź����㱻ը����\n");	
	}
	else
	{
		printf("��ϲ�㣬ɨ�׳ɹ�\n");
	}
	printboard(mineboard, row, col);
}