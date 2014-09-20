// FirstRPG.cpp : Defines the entry point for the console application.
//

#include "GameDefines.h"
#include "Main.h"


int main( int argc, char* argv[] )
{
	CMain game( WINDOW_WIDTH, WINDOW_HIGHT );

	game.GameLoop();

	return 0;
}
