#pragma once
#include "GameDefines.h"
#include "SDL_Setup.h"
#include "Sprite.h"
class CMain
{
public:
	CMain( int screenWidth, int screenHigh );
	virtual ~CMain();

	void GameLoop();

private:
	bool     m_isQuit;
	CSprite* grass;
	CSprite* bob;

	CSDL_Setup* csdl_setup;

	int timeCheck;
};
