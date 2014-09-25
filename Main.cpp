#include "stdafx.h"
#include "Main.h"


CMain::CMain( int screenWidth, int screenHigh ) : m_isQuit( false ),
												  csdl_setup( NULL ),
												  grass( NULL ),
												  bob( NULL )
{
	csdl_setup = new CSDL_Setup( &m_isQuit, screenWidth, screenHigh );
	grass = new CSprite( csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, WINDOW_WIDTH, WINDOW_HIGHT );
	bob = new CSprite( csdl_setup->GetRenderer(), "data/tom.png", 250, 100, 50, 80 );
	bob->SetUpAnimation( 4, 4 );

	timeCheck = SDL_GetTicks();
}

CMain::~CMain()
{
	delete csdl_setup;
	delete grass;
	delete bob;
}

void CMain::GameLoop()
{
	while( !m_isQuit && csdl_setup->GetEvent()->type != SDL_QUIT )
	{
		csdl_setup->Begin();

		grass->Draw();
		bob->Draw();

		int angle 

		bob->PlayAnimation( 0, 3, 1, 150 );

		if( timeCheck + 50 < SDL_GetTicks() )
		{
			bob->Move( csdl_setup->GetEvent() );

			timeCheck = SDL_GetTicks();
		}

		csdl_setup->End();
	}
}
