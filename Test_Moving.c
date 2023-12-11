#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "Test_Moving.h"
#include "cursor.h"
#include "map.h"
#include "calculatorDST.h"
#include "player.h"
#include "define_state.h"
#include "bomb.h"

#define flagTime1 1000
#define flagTime2 700
int time_limit;

extern int npcCurPosX, npcCurPosY;
extern unsigned long long NPC_current_Time;
extern unsigned long long current_game_time;
extern int npc1_bomb_exist_count = 0;
extern int npc1_state_flag;

int npc1_bomb_max = 1;

void ShowNpcBlock()
{
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // ����

	printf("��");
}

void DeleteBlock()
{

	SetCurrentCursorPos(npcCurPosX, npcCurPosY);
	printf("  ");
}

int NPC_moveLeft() {


	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock();
	npcCurPosX -= 2;

	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();
	return 0;

}

int NPC_moveRight() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock();
	npcCurPosX += 2;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;

}

int NPC_moveUp() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock();
	npcCurPosY -= 1;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;
}

int NPC_moveDown() {

	if (mapModel[cursorY_to_arrY(npcCurPosY)][cursorX_to_arrX(npcCurPosX)] == STATE_BOMB_SETTING)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // ��ο� ����
		printf("��");
	}
	else
		DeleteBlock();
	npcCurPosY += 1;
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));
	SetCurrentCursorPos(npcCurPosX, npcCurPosY);

	ShowNpcBlock();

	return 0;
}


int NpcMoving(int npc_speed_phase)
{
	int preX = 0, preY = 0;
	int npcX, npcY;

	if (npc_speed_phase == 0) {
		time_limit = flagTime1;
	}
	else if(npc_speed_phase == 1) {
		time_limit = flagTime2;
	}

	//npcX = npcCurPosX / 2;
	npcX = cursorX_to_arrX(npcCurPosX);
	//npcY = npcCurPosY;
	npcY = cursorY_to_arrY(npcCurPosY);

	int kill_Mode = ShortestDistance(npcX, npcY); // ���⼭ one_srt_dist �迭�� ������� (�� �迭�� ���� NPC�� ������)

	int dx = npcX;
	int dy = npcY;

	SetCurrentCursorPos(npcCurPosX, npcCurPosY);


	while (1) { //�� while�� �ȿ� �ִ� clock�������� �Ű澲�� �ʾƵ� ��, ���� �׽�Ʈ��, �Ƹ� 1ĭ�� �������� �ϴϱ� while ����� ����� ���

		preX = dx;
		preY = dy;

		if (one_srt_dist[dy][dx + 1] == 1) { // NPC ������ġ ���� one_srt_dist�� �������� 1�̶�� (�����ִ±�)
			one_srt_dist[dy][dx] = 0; // ���� ��ġ�� one_srt_dist�� 0���� �ʱ�ȭ �ϰ�

			if (current_game_time - NPC_current_Time > time_limit) {
				NPC_current_Time = clock();
				NPC_moveRight(); //���������� �̵�
			}
			dx += 1;
		}
		else if (one_srt_dist[dy][dx - 1] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > time_limit) {
				NPC_current_Time = clock();
				NPC_moveLeft();
			}
			dx -= 1;
		}
		else if (one_srt_dist[dy + 1][dx] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > time_limit) {
				NPC_current_Time = clock();
				NPC_moveDown();
			}
			dy += 1;
		}
		else if (one_srt_dist[dy - 1][dx] == 1) {
			one_srt_dist[dy][dx] = 0;

			if (current_game_time - NPC_current_Time > time_limit) {
				NPC_current_Time = clock();
				NPC_moveUp();
			}
			dy -= 1;
		}

		if (dx == dstX && dy == dstY) {

			if (current_game_time - NPC_current_Time > time_limit) {
				if (npc1_bomb_exist_count < npc1_bomb_max) {
					//(523.2511, 250); // ��ź��ġ ȿ����
					npc1_set_bomb();
				}
				//NPCmapModel[dstY][dstX] = STATE_NPC_WARNING;
				NPC_current_Time = clock();
				if (dx < preX) {
					NPC_moveRight();
				}
				else if (dx > preX) {
					NPC_moveLeft();
				}
				else if (dy > preY) {
					NPC_moveUp();
				}
				else if (dy < preY) {
					NPC_moveDown();
				}
			}
		}
		return 0;
	}
}

int CheckNPCState()
{
	// ���� �÷��̾� ��ǥ�� �������� ���� PlayerState ������Ʈ
	// ������Ʈ�� PlayerState ���� �°� ó��

	////////////�߰�
	if (checkObject_boom(npcCurPosX, npcCurPosY) == 1)
	{
		//SetCurrentCursorPos(GBOARD_ORIGIN_X, HEIGHT + GBOARD_ORIGIN_Y);
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // ���
		//printf("NPC1 down!\n");
		npc1_state_flag = 1;

		return (1);
	}
	if (checkPlayer_Killed_NPC(npcCurPosX, npcCurPosY, PlayerCurPosX, PlayerCurPosY) == 1) {
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);

		Sleep(700);
		GameOver_Mapdrawing();
		return (2);
	}
	return (0);
}

int NPC1_die() {

	if (cursorX_to_arrX(npcCurPosX) < 0 || WIDTH - 1 < cursorX_to_arrX(npcCurPosX))
		return (1);
	if (cursorY_to_arrY(npcCurPosY) < 0 || HEIGHT - 1 < cursorY_to_arrY(npcCurPosY))
		return (1);

	SetCurrentCursorPos(npcCurPosX, npcCurPosY);
	set_Empty(cursorX_to_arrX(npcCurPosX), cursorY_to_arrY(npcCurPosY));


	npcCurPosX = 0;
	npcCurPosY = 0;
}