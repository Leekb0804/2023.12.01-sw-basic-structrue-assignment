#ifndef __TESTMOVING2_H__
#define __TESTMOVING2_H__

#include <Windows.h>
#include "calculatorDST2.h"

void ShowNpcBlock2();
void DeleteBlock2();
int NPC_moveLeft2();
int NPC_moveRight2();
int NPC_moveUp2();
int NPC_moveDown2();
int NpcMoving2(int npc_speed_phase);
int CheckNPCState2();
int NPC2_die();


#endif