#ifndef __STAGE_IMAGE_H__
#define __STAGE_IMAGE_H__

#define letter_WIDTH 32 //�� ���� ����
#define letter_HEIGHT 20 //�� ���� ����
#define letter 1 //�� ���� ����
#define Empty 0 //�� ���� ����
#define total_Maps 6 //�� ���� ����



/*���� ����, �Լ�, ���� (�߰��� �ʿ�X)*/
#include "define_state.h"
// #define GBOARD_ORIGIN_X 0
// #define GBOARD_ORIGIN_Y 0

#include <stdio.h>
#include <Windows.h>
#include <time.h>

//int game_round = 0; //������ �ִ� ���� ���� ����

#include "cursor.h"
// void SetCurrentCursorPos(int x, int y)
// {
// 	COORD pos = { x, y };

// 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
// }



/*map.h*/
/*���ο� �Լ���
��Ȳ�� ���� ȣ�⸸ �ϸ� ��.

1. printf("Game Over")��� GameOver_Mapdrawing();ȣ���ϱ�
2. ���� �������� �Ѿ�°� �ϼ��ϸ� NextStage_Mapdrawing();ȣ���ϰ� �� �ȿ� �Ѿ�� �Լ� ȣ���ϱ�
3. ���� Ŭ����� Clear_Letterdrawing(); ȣ��
*/
void draw_GameOver_letterMaps();
void draw_NextStage_letterMaps();
void draw_AllClear(int i);
void GameOver_Mapdrawing(); //���� ������ �� ȣ��
void NextStage_Mapdrawing(); //���� ���������� �Ѿ�� ȣ��
void Clear_Letterdrawing(); //Ŭ������ �� ȣ��

// 12�� 04�� �̰���� �߰� �������� ����ϴ� ȭ�� �������� �ʱ�ȭ�ϴ� �Լ� �߰�
void draw_Stagemap_reset();		//������������ߴ� ȭ�� �������� �ʱ�ȭ

/*map.c*/
//���ο� �ʵ�


/*����� (�߰�X)*/
// int main() {
// 	//GameOver_Mapdrawing(); //���ӿ����Ҷ� ���� ȣ��.
// 	//NextStage_Mapdrawing(); //�������� ǥ�� ��
// 	Clear_Letterdrawing(); //���� �������Ҷ� ALL Clear ǥ��
// }

#endif