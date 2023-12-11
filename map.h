#ifndef __MAP_H__
#define __MAP_H__

#include "bomb.h"
#include <Windows.h>

#include "define_state.h"

extern int mapModel[HEIGHT][WIDTH];
extern int NPCmapModel[HEIGHT][WIDTH];

typedef struct map {
	int state;
	Bomb* bomb;
} Map;

typedef struct map_box {
	int x;
	int y;
	struct map_box* next;
} Map_box;

typedef struct map_box_head {
	struct map_box* next;
} Map_box_head;


Map_box_head* map_box_head;
extern unsigned long long current_game_time;
extern unsigned long long recent_sky_bomb_drop_time;//warning�� ���� �ð�
extern unsigned long long stage_start_time;
int check_sky_bomb_set;

COORD sky_bomb_drop_coordinate;

int* output_random_5_num_arr();		//�� ���� ��ġ�� ���� ���� ���� 5�� ���� �Լ�
void resetMap();		//�� �ʱ� �� ����
void generateMap();		//�� ����
void drawMaps();		//�� ���
//void draw_3_3maps(int x, int y, int cursX, int cursY);		//3*3 ���� Ȯ��

int checkObject_can_go(int cursorX, int cursorY);		//���ڷ� �־��� ��ǥ�� �̵��� �� �ִ���
int checkObject_Item(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� �������� �ִ���

int checkObject_bomb_max_Item(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� ��ź ���� ���� �������� �ִ���
int checkObject_bomb_range_Item(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� ��ź ���� ���� �������� �ִ���
int checkObject_character_Move_Item(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� �̵��ӵ� ���� �������� �ִ���

int checkObject_boom(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� ���߹�������
int checkObject_box(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� �ν� �� �ִ� ��ֹ��� �ִ���
int checkObject_wall(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� �ν� �� ���� ��ֹ��� �ִ���
int checkObject_exist_bomb(int cursorX, int cursorY);	//���ڶ� �־��� ��ǥ�� ������ ���� ��ź�� �����ϴ���

void gernerate_Item(int cursorX, int cursorY);          // �ش� ��ǥ�� ������ ����
void draw_Item_bomb_max(int x, int y);       // �ش� ��ǥ�� bomb max ���� ������ ���
void draw_Item_bomb_range(int x, int y);     // �ش� ��ǥ�� bomb max ���� ������ ���
void draw_Item_chracter_move(int x, int y); // �ش� ��ǥ�� bomb max ���� ������ ���

int get_Player_starting_point_x();			//�÷��̾� �ʱ� x ��ġ ����
int get_Player_starting_point_y();			//�÷��̾� �ʱ� y ��ġ ����

void set_Bomb(int arrX, int arrY);				//�ش���ǥ�� ��ź����		
void set_Empty(int arrX, int arrY);				//�ش� ��ǥ �������� �����
void set_Bomb_Boom(int arrX, int arrY);			//�ش� ��ǥ�� ��ź �����ϰ� �����
void set_NPC_Warning(int arrX, int arrY);		//�ش� ��ǥ�� NPC Warning update�ϱ�

// 11�� 18�� �߰�
int cursorX_to_arrX(int cursorX);			//Ŀ����ǥ�� �迭�� ��ǥ�� ��ȯ
int cursorY_to_arrY(int cursorY);			//Ŀ����ǥ�� �迭�� ��ǥ�� ��ȯ

int arrX_to_cursorX(int arrX);				//�迭 ��ǥ�� Ŀ�� ��ǥ�� ��ȯ
int arrY_to_cursorY(int arrY);				//�迭 ��ǥ�� Ŀ�� ��ǥ�� ��ȯ

int check_over_GameBoard_Width(int arrX);		//���� �������
int check_over_GameBoard_HEIGHT(int arrY);		//���� �������

//void npc_Warning_update(int arrX, int arrY, Bomb* newbomb);
int checkPlayer_Killed_NPC(int npcCurPosX, int npcCurPosY, int PlayerCurPosX, int PlayerCurPosY);

// 11�� 20�� map_box_head

Map_box_head* generate_map_box_head();
void insert_map_box_struct(Map_box_head* head, int x, int y);
void remove_generate_item_all_map_box_struct(Map_box_head* head);


void set_mapModel2();
void set_mapModel3();




void reset_npcMapModel();


// 11�� 30��
void draw_Item_chracter_move_reverse(int cursorX, int cursorY); // ĳ���� �̵� �ݴ�� ������ ���

int checkObject_character_Move_reverse_Item(int cursorX, int cursorY);			//���ڷ� �־��� ��ǥ�� �̵��ӵ� ���� �������� �ִ���

// 12�� 02��
int checkObject_Empty(int cursorX, int cursorY);		//���ڷ� �־��� ��ǥ�� ����ִ���
void sky_bomb_drop();
void bomb_dropping();
int check_can_sky_bomb_drop(int arrX, int arrY);
void set_sky_bomb_warning(int arrX, int arrY);

//12�� 04�� �����̰� ���� �� �߰�

void set_mapModel_spiral();
void set_mapModel_eye();
void set_mapModel_snail();
void set_mapModel_symmetry();
void set_mapModel_popopoktan();
void set_mapModel_firework();


#endif