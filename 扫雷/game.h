
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_NUM 10

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

//��ӡ�˵�
void menu();
//��ʾ
void playgame();
//��ʼ������
void initboard(char board[ROWS][COLS], int rows, int cols, char ret);
//��ӡ����
void printboard(char board[ROWS][COLS], int row, int col);
//������
void setmine(char board[ROWS][COLS], int mine_num, int row, int col);
//ɨ��
void play(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col);
