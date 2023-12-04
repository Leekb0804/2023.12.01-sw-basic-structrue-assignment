#include "stage_image.h"

extern int game_round;

int GameOver_letter_map[letter_HEIGHT][letter_WIDTH] =
{
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,Empty,letter,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
};

int Clear_letter_map[total_Maps][letter_HEIGHT][letter_WIDTH] =
{
	//1
	{ {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty }},


	//2
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },

//3
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,Empty},
{Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


//4
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,Empty,letter,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter},
{letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


//5
{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,letter,letter,letter,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty},
{letter,letter,letter,letter,Empty,letter,letter,letter,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter},
{letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,Empty,letter,letter},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} },


{ {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,letter,letter,letter,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty} }
};

int NextStage_letter_map[total_Maps][letter_HEIGHT][letter_WIDTH] =
{
	//stage 1
	{
	{Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty},
	{ Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty },
	{ Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty }
	},


	//stage2
	{
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
	{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
	},


	//stage3
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},


//stage4
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},


//stage 5
{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty},
{Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,letter,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,letter,Empty,letter,Empty,Empty},
{Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty},
{Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
},

{
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,letter,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,letter,letter,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,Empty,Empty,letter,letter,letter,letter,letter,letter,letter,letter,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty},
{Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty}
}
};


void draw_GameOver_letterMaps()		//���� ���� ȭ�� ���
{
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (GameOver_letter_map[y][x] == letter)
			{
				printf("��");
			}
			else { printf("  "); }
		}
	}
	SetCurrentCursorPos((GBOARD_ORIGIN_X/*BOARD_ORIGIN_X*/ + letter_WIDTH * 2 + 1), letter_HEIGHT + 1);
}

void draw_NextStage_letterMaps()		//���� �������� ȭ�� ���
{
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		if (y >= 8)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (NextStage_letter_map[game_round][y][x] == letter)
			{
				printf("��");
			}
			else { printf("  "); }
		}
	}
	Sleep(3000);
	//���⿡ ���� ���������� �Ѿ�� �Լ� ȣ��
}

void draw_AllClear(int i) { //Ŭ���� ȭ�� ���
	int x, y;
	int cursX, cursY;

	for (y = 0; y < letter_HEIGHT; y++) {
		for (x = 0; x < letter_WIDTH; x++)
		{
			cursX = x * 2 + GBOARD_ORIGIN_X; /*GBOARD_ORIGIN_X*/;
			cursY = y + GBOARD_ORIGIN_Y; /*GBOARD_ORIGIN_Y*/;

			SetCurrentCursorPos(cursX, cursY);

			if (Clear_letter_map[i][y][x] == letter)
			{
				printf("��");
			}
			else { printf("  "); }
		}
	}
	SetCurrentCursorPos((GBOARD_ORIGIN_X/*BOARD_ORIGIN_X*/ + letter_WIDTH * 2 + 1), letter_HEIGHT + 1);
}

void GameOver_Mapdrawing() {
	int a = 12;
	int b = 15;
	SetCurrentCursorPos(0, letter_HEIGHT + 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b);
	printf("Player Score = %d"); //���� �÷��̾� ���� �ֱ�
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		draw_GameOver_letterMaps();
		Sleep(1000); //1�ʸ��� ���� �ٲٱ�
		if (a == 12) a = 15;
		else a = 12;
	}
}

void NextStage_Mapdrawing() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	draw_NextStage_letterMaps();
}

void Clear_Letterdrawing() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for (int i = 0; i < 5; i++) { //���� ������ �ִϸ��̼�
		draw_AllClear(i);
		Sleep(800); //0.8���� ������
	}
	int a = 10;
	int b = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), b);
	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		draw_AllClear(5);
		Sleep(1000); //Ŭ���� �޼��� ���� 1�ʸ��� �ٲٱ�
		if (a == 10) a = 15;
		else a = 10;
	}
}
