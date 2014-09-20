#include "stdafx.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup( bool* isQuit, int screenWidth, int screenHight ) : mainEvent( NULL ),
																		   renderer( NULL ),
																		   window( NULL )
{
	window = SDL_CreateWindow( "My first RPG", 300, 300, screenWidth, screenHight, SDL_WINDOW_SHOWN );
	if( !window )
	{
		std::cout << "Window couldn't be created" << std::endl;
		*isQuit = true;
	}
	renderer  = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	mainEvent = new SDL_Event();
}

CSDL_Setup::~CSDL_Setup()
{
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );
	delete mainEvent;
}

SDL_Renderer* CSDL_Setup::GetRenderer()
{
	return renderer;
}

SDL_Event* CSDL_Setup::GetEvent()
{
	return mainEvent;
}

void CSDL_Setup::Begin()
{
	SDL_PollEvent( mainEvent );
	SDL_RenderClear( renderer );
}

void CSDL_Setup::End()
{
	SDL_RenderPresent( renderer );
}
