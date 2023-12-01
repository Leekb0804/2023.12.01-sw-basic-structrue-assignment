#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "player.h"
#include "map.h"
#include "cursor.h"

#include "bomb.h"

#include "define_state.h"
#include "calculatorDST.h"

#include <time.h>

extern int bomb_max = 1;
extern int player_bomb_len = 1;
extern int bomb_exist_count = 0;

extern unsigned long long current_game_time;
unsigned long long recent_player_move_time = 0;
unsigned long long player_move_span = 300;

extern int check_player_move_reverse = 0;

void ShowPlayerBlock()
{

	COORD curPos = GetCurrentCursorPos();

	SetCurrentCursorPos(curPos.X, curPos.Y);
	printf("  ");
	SetCurrentCursorPos(curPos.X, curPos.Y);
	printf("��");
	SetCurrentCursorPos(curPos.X, curPos.Y);
}

void DeletePlayerBlock()
{
	int x, y;

	COORD curPos = GetCurrentCursorPos();

	if (checkObject_exist_bomb(curPos.X, curPos.Y) == 1)
	{
		SetCurrentCursorPos(curPos.X, curPos.Y);
		printf("��");
		SetCurrentCursorPos(curPos.X, curPos.Y);
	}
	else
	{
		SetCurrentCursorPos(curPos.X, curPos.Y);
		printf("  ");
		SetCurrentCursorPos(curPos.X, curPos.Y);
	}
}

void PlayerMoveLeft()
{
	if (!DetectCollision(PlayerCurPosX - 2, PlayerCurPosY))
	{
		return;
	}

	DeletePlayerBlock();

	PlayerCurPosX -= 2;

	if (checkObject_Item(PlayerCurPosX, PlayerCurPosY))
	{
		apply_Item(PlayerCurPosX, PlayerCurPosY);
		set_Empty(cursorX_to_arrX(PlayerCurPosX), cursorY_to_arrY(PlayerCurPosY));
	}

	SetCurrentCursorPos(PlayerCurPosX, PlayerCurPosY);
	ShowPlayerBlock();
}

void PlayerMoveRight()
{
	if (!DetectCollision(PlayerCurPosX + 2, PlayerCurPosY))
	{
		return;
	}

	DeletePlayerBlock();

	PlayerCurPosX += 2;

	if (checkObject_Item(PlayerCurPosX, PlayerCurPosY))
	{
		apply_Item(PlayerCurPosX, PlayerCurPosY);
		set_Empty(cursorX_to_arrX(PlayerCurPosX), cursorY_to_arrY(PlayerCurPosY));
	}

	SetCurrentCursorPos(PlayerCurPosX, PlayerCurPosY);
	ShowPlayerBlock();
}

void PlayerMoveDown() // ?�레?�어 ?�동 (??
{
	if (!DetectCollision(PlayerCurPosX, PlayerCurPosY + 1))
	{
		return;
	}

	DeletePlayerBlock();

	PlayerCurPosY += 1;

	if (checkObject_Item(PlayerCurPosX, PlayerCurPosY))
	{
		apply_Item(PlayerCurPosX, PlayerCurPosY);
		set_Empty(cursorX_to_arrX(PlayerCurPosX), cursorY_to_arrY(PlayerCurPosY));
	}

	SetCurrentCursorPos(PlayerCurPosX, PlayerCurPosY);
	ShowPlayerBlock();
}

void PlayerMoveUp() // ?�레?�어 ?�동 (??
{
	if (!DetectCollision(PlayerCurPosX, PlayerCurPosY - 1))
	{
		return;
	}

	DeletePlayerBlock();

	PlayerCurPosY -= 1;

	if (checkObject_Item(PlayerCurPosX, PlayerCurPosY))
	{
		apply_Item(PlayerCurPosX, PlayerCurPosY);
		set_Empty(cursorX_to_arrX(PlayerCurPosX), cursorY_to_arrY(PlayerCurPosY));
	}

	SetCurrentCursorPos(PlayerCurPosX, PlayerCurPosY);
	ShowPlayerBlock();
}

int DetectCollision(int posX, int posY) // �ӽ÷� ��ֹ� GameBoardInfo�� �����Ͽ� ����
{										// ���� ��ֹ��� ���� �����ϵ��� �ٲ� ����
	int x, y;

	return checkObject_can_go(posX, posY);
}

void SetPlayerBomb() // ??��?�는 ?�수
{
	// 좌표 (PlayerCurPosX, PlayerCurPosY)????�� ?�는 ?�수
	player_set_bomb();
}

int CheckPlayerState()
{
	// ���� �÷��̾� ��ǥ�� �������� ���� PlayerState ������Ʈ
	// ������Ʈ�� PlayerState ���� �°� ó��

		////////////�߰�
	if (checkObject_boom(PlayerCurPosX, PlayerCurPosY) == 1)
	{
		SetCurrentCursorPos(3, HEIGHT + GBOARD_ORIGIN_Y);
		printf("Player down    Game Over!\n");
		return (1);
	}
	return (0);
}

void ProcessKeyInput()
{
	int key;

	key = 0;
	if (_kbhit() != 0)
	{
		key = _getch();
		switch (key)
		{
		case LEFT:
			if (check_player_move_span())
			{
				if (check_player_move_reverse == 0)
					PlayerMoveLeft();
				else
					PlayerMoveRight();
				recent_player_move_time = clock();
			}
			break;
		case RIGHT:
			if (check_player_move_span())
			{
				if (check_player_move_reverse == 0)
					PlayerMoveRight();
				else
					PlayerMoveLeft();
				recent_player_move_time = clock();
			}
			break;
		case UP:
			if (check_player_move_span())
			{
				if (check_player_move_reverse == 0)
					PlayerMoveUp();
				else
					PlayerMoveDown();
				recent_player_move_time = clock();
			}
			break;
		case DOWN:
			if (check_player_move_span())
			{
				if (check_player_move_reverse == 0)
					PlayerMoveDown();
				else
					PlayerMoveUp();
				recent_player_move_time = clock();
			}
			break;
		case SPACE_BAR:
			if (bomb_exist_count < bomb_max && checkObject_exist_bomb(PlayerCurPosX, PlayerCurPosY) == 0)
				SetPlayerBomb();
			break;
		default:
			break;
		}
	}
}

void PlayerControl()
{
	SetCurrentCursorPos(PlayerCurPosX, PlayerCurPosY);
	ShowPlayerBlock();

	ProcessKeyInput();
}

int check_player_move_span()
{
	current_game_time = clock();
	if (current_game_time - recent_player_move_time > player_move_span)
		return (1);
	return (0);
}

void apply_Item(int cursorX, int cursorY)
{
	if (checkObject_bomb_max_Item(cursorX, cursorY))
		bomb_max++;
	if (checkObject_bomb_range_Item(cursorX, cursorY))
		player_bomb_len++;
	if (checkObject_character_Move_Item(cursorX, cursorY))
	{
		if (player_move_span > 50)
			player_move_span -= 40;
	}
	if (checkObject_character_Move_reverse_Item(cursorX, cursorY))
	{
		check_player_move_reverse += 1;
		check_player_move_reverse %= 2;
	}
}
