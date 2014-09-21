#pragma once
#include "GameDefines.h"

class CSDL_Setup
{
public:
	CSDL_Setup( bool* isQuit, int screenWidth, int screenHight );
	~CSDL_Setup();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetEvent();

	void Begin();
	void End();

private:
	SDL_Event*    mainEvent;
	SDL_Renderer* renderer;
	SDL_Window*   window;
};
