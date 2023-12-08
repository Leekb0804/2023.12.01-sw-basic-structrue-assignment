#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "Test_Moving3.h"
#include "cursor.h"
#include "map.h"
#include "calculatorDST3.h"
#include "player.h"
#include "define_state.h"
#include "bomb.h"

#define flagTime 4000


extern int npc3_state_flag;

extern int npcCurPosX3, npcCurPosY3;
extern unsigned long long NPC_current_Time3;
extern unsigned long long current_game_time;
extern int npc3_bomb_exist_count = 0;
int npc3_bomb_max = 1;


void ShowNpcBlock3()
{
	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // ����

	printf("��");
}

void DeleteBlock3()
{

	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	printf("  ");
}

int NPC_moveLeft3() {

	if (mapModel[cursorY_to_arrY(npcCurPosY3)][cursorX_to_arrX(npcCurPosX3)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock3();
	npcCurPosX3 -= 2;
	set_Empty(cursorX_to_arrX(npcCurPosX3), cursorY_to_arrY(npcCurPosY3));
	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	ShowNpcBlock3();
	return 0;

}

int NPC_moveRight3() {

	if (mapModel[cursorY_to_arrY(npcCurPosY3)][cursorX_to_arrX(npcCurPosX3)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock3();
	npcCurPosX3 += 2;
	set_Empty(cursorX_to_arrX(npcCurPosX3), cursorY_to_arrY(npcCurPosY3));
	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	ShowNpcBlock3();

	return 0;

}

int NPC_moveUp3() {

	if (mapModel[cursorY_to_arrY(npcCurPosY3)][cursorX_to_arrX(npcCurPosX3)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock3();
	npcCurPosY3 -= 1;
	set_Empty(cursorX_to_arrX(npcCurPosX3), cursorY_to_arrY(npcCurPosY3));
	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	ShowNpcBlock3();

	return 0;
}

int NPC_moveDown3() {

	if (mapModel[cursorY_to_arrY(npcCurPosY3)][cursorX_to_arrX(npcCurPosX3)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock3();
	npcCurPosY3 += 1;
	set_Empty(cursorX_to_arrX(npcCurPosX3), cursorY_to_arrY(npcCurPosY3));
	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	ShowNpcBlock3();

	return 0;
}


int NpcMoving3()
{
	int preX = 0, preY = 0;
	int npcX, npcY;

	npcX = npcCurPosX3 / 2;
	npcY = npcCurPosY3;

	npcX = cursorX_to_arrX(npcCurPosX3);
	npcY = cursorY_to_arrY(npcCurPosY3);

	int kill_Mode = ShortestDistance3(npcX, npcY); // ���⼭ one_srt_dist �迭�� ������� (�� �迭�� ���� NPC�� ������)

	int dx = npcX;
	int dy = npcY;

	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);


	while (1) { //�� while�� �ȿ� �ִ� clock�������� �Ű澲�� �ʾƵ� ��, ���� �׽�Ʈ��, �Ƹ� 1ĭ�� �������� �ϴϱ� while ����� ����� ���

		preX = dx;
		preY = dy;

		if (one_srt_dist3[dy][dx + 1] == 1) { // NPC ������ġ ���� one_srt_dist�� �������� 1�̶�� (�����ִ±�)
			one_srt_dist3[dy][dx] = 0; // ���� ��ġ�� one_srt_dist�� 0���� �ʱ�ȭ �ϰ�
			if (current_game_time - NPC_current_Time3 > flagTime) {
				NPC_current_Time3 = clock();
				NPC_moveRight3(); //���������� �̵�
			}
			dx += 1;
		}
		else if (one_srt_dist3[dy][dx - 1] == 1) {
			one_srt_dist3[dy][dx] = 0;

			if (current_game_time - NPC_current_Time3 > flagTime) {
				NPC_current_Time3 = clock();
				NPC_moveLeft3();
			}
			dx -= 1;
		}
		else if (one_srt_dist3[dy + 1][dx] == 1) {
			one_srt_dist3[dy][dx] = 0;

			if (current_game_time - NPC_current_Time3 > flagTime) {
				NPC_current_Time3 = clock();
				NPC_moveDown3();
			}
			dy += 1;
		}
		else if (one_srt_dist3[dy - 1][dx] == 1) {
			one_srt_dist3[dy][dx] = 0;

			if (current_game_time - NPC_current_Time3 > flagTime) {
				NPC_current_Time3 = clock();
				NPC_moveUp3();
			}
			dy -= 1;
		}

		if (dx == dstX3 && dy == dstY3) { // ��ǥ ��ġ�� �����ϸ� mapModel�� �����¿츦 1�� �ʱ�ȭ �ϰ� ���� ������ (�ӽ� ��ǳ��)

			if (current_game_time - NPC_current_Time3 > flagTime) {
				if (npc3_bomb_exist_count < npc3_bomb_max) {
					npc3_set_bomb();
				}
				//NPCmapModel[dstY3][dstX3] = STATE_NPC_WARNING;
				NPC_current_Time3 = clock();
				if (dx < preX) {
					NPC_moveRight3();
				}
				else if (dx > preX) {
					NPC_moveLeft3();
				}
				else if (dy > preY) {
					NPC_moveUp3();
				}
				else if (dy < preY) {
					NPC_moveDown3();
				}
			}
		}
		return 0;
	}
}

int CheckNPCState3()
{
	// ���� �÷��̾� ��ǥ�� �������� ���� PlayerState ������Ʈ
	// ������Ʈ�� PlayerState ���� �°� ó��

	////////////�߰�
	if (checkObject_boom(npcCurPosX3, npcCurPosY3) == 1)
	{
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y + 1);
		printf("NPC3 down!\n");
		npc3_state_flag = 1;
		return (1);
	}
	if (checkPlayer_Killed_NPC(npcCurPosX3, npcCurPosY3, PlayerCurPosX, PlayerCurPosY) == 1) {
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
		Sleep(700);
		GameOver_Mapdrawing();
		return (2);
	}
	return (0);
}

int NPC3_die() {
	if (cursorX_to_arrX(npcCurPosX3) < 0 || WIDTH - 1 < cursorX_to_arrX(npcCurPosX3))
		return (1);
	if (cursorY_to_arrY(npcCurPosY3) < 0 || HEIGHT - 1 < cursorY_to_arrY(npcCurPosY3))
		return (1);

	SetCurrentCursorPos(npcCurPosX3, npcCurPosY3);
	set_Empty(cursorX_to_arrX(npcCurPosX3), cursorY_to_arrY(npcCurPosY3));
	/*npcCurPosX3 = 0;
	npcCurPosY3 = 0;*/
}