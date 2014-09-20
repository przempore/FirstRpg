#include "stdafx.h"
#include "Sprite.h"
#include "GameDefines.h"

CSprite::CSprite( SDL_Renderer* renderer, char* url, int x, int y, int w, int h ) : m_image( NULL ),
																					m_mouseX( 0 ),
																					m_mouseY( 0 ),
																					m_imgWidth( 0 ),
																					m_imgHeight( 0 ),
																					m_nextPoint( 0., 0. ),
																					m_mousePos( 0., 0. ),
																					m_bobPos( 0., 0. ),
																					m_iDistance( 0 )
{
	this->m_renderer = renderer;

	m_image = IMG_LoadTexture( renderer, url );

	if( !m_image )
	{
		std::cout << "Couldn't load " << url << "!!!" << std::endl;
	}

	m_rect.x = x;
	m_rect.y = y;
	m_rect.w = w;
	m_rect.h = h;

	SDL_QueryTexture( m_image, NULL, NULL, &m_imgWidth, &m_imgHeight );
	m_crop.x = 0;
	m_crop.y = 0;
	m_crop.w = m_imgWidth;
	m_crop.h = m_imgHeight;
}

CSprite::~CSprite()
{
	SDL_DestroyTexture( m_image );
}

void CSprite::Draw()
{
	SDL_RenderCopy( m_renderer, m_image, &m_crop, &m_rect );
}

void CSprite::Move( SDL_Event* moveEvent )
{
	SDL_GetMouseState( &m_mouseX, &m_mouseY );

	m_mousePos.Set( m_mouseX, m_mouseY );


	/*bool isMoveDown = false;
	   bool isMoveUp = false;
	   bool isMoveLeft  = false;
	   bool isMoveRight = false;

	   int iDistance = sqrt( ( m_mousePos.GetX() - rect.x ) * ( m_mousePos.GetX() - rect.x ) + ( m_mousePos.GetY() - rect.y ) * ( m_mousePos.GetY() - rect.y ) );

	   if( moveEvent->type == SDL_MOUSEBUTTONDOWN )
	   {
	    SDL_GetMouseState( &mouseX, &mouseY );
	    m_mousePos.Set( mouseX, mouseY );
	    m_bobPos.Set( rect.x, rect.y );
	   }


	   if( m_iDistance > iDistance )
	   {
	    m_iDistance = iDistance;
	   }
	   if( iDistance <= m_iDistance )
	   {
	    rect.x += m_nextPoint.GetX();
	    rect.y += m_nextPoint.GetY();
	   }
	   else if( iDistance == m_iDistance )
	   {
	    rect.x += m_nextPoint.GetX();
	    rect.y += m_nextPoint.GetY();
	   }
	   else
	   {
	    return;
	   }
	 */
}

void CSprite::PlayAnimation( int beginFrame, int endFrame, int row, float speed )
{
	m_crop.x = m_imgWidth / 4;
	m_crop.w = m_imgWidth / 4;
	m_crop.h = m_imgHeight / 4;
}

CMyPoint CSprite::NextStep( CMyPoint first, CMyPoint second, double speed )
{
	double wholeDistance = 0.0;

	wholeDistance = sqrt( ( first.GetX() - second.GetX() ) * ( first.GetX() - second.GetX() ) + ( first.GetY() - second.GetY() ) * ( first.GetY() - second.GetY() ) );

	CMyPoint nextPoint( 0., 0. );

	//nextPoint = ( ( CMyPoint::MyPointPOW( second - first ) ) / wholeDistance ) * speed;
	int i = first.GetX() * ( 1 - speed ) + speed * second.GetX();
	nextPoint.SetX( first.GetX() * ( 1 - speed ) + speed * second.GetX() );
	nextPoint.SetY( first.GetY() * ( 1 - speed ) + speed * second.GetY() );

	CMyPoint retPoint = nextPoint - first;

	return nextPoint;
}
