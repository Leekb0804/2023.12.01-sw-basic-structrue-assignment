#ifndef __TESTMOVING_H__
#define __TESTMOVING_H__

#include <Windows.h>
#include "calculatorDST.h"


void ShowNpcBlock();
void DeleteBlock();
int NPC_moveLeft();
int NPC_moveRight();
int NPC_moveUp();
int NPC_moveDown();
int NpcMoving(int npc_speed_phase);
int CheckNPCState();
int NPC1_die();

#endif