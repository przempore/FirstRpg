#include <algorithm> // std::max
#include "stdafx.h"
#include "Sprite.h"
#include "GameDefines.h"

CSprite::CSprite( SDL_Renderer* renderer, char* url, int x, int y, int w, int h ) : m_image( NULL ),
																					m_mouseX( 0 ),
																					m_mouseY( 0 ),
																					m_imgWidth( 0 ),
																					m_imgHeight( 0 ),
																					m_mousePos( 0., 0. ),
																					m_bobPos( 0., 0. ),
																					m_iDistance( 0 ),
																					m_bIsMoving( false )
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


	if( moveEvent->type == SDL_MOUSEBUTTONDOWN )
	{
		SDL_GetMouseState( &m_mouseX, &m_mouseY );
		m_mousePos.Set( m_mouseX, m_mouseY );
		m_oldPos.Set( m_rect.x, m_rect.y );
		m_newPos.Set( m_mousePos );
		m_bIsMoving = true;
	}

	if( m_bIsMoving )
	{
		if( ( m_rect.x == m_newPos.GetX() )
			&& ( m_rect.y == m_newPos.GetY() ) )
		{
			return;
		}

		Uint32 czas = SDL_GetTicks();
		czas = czas;
		CMyPoint sspTemp;
		float    fFraction = /*EasingQuadAndInv( */ CalculateProgress( m_ulStartMove, m_ulStopMove, SDL_GetTicks() ) /*)*/;

		CMyPoint fSection;

		fSection.SetX( m_oldPos.GetX() - m_newPos.GetX() );
		fSection.SetY( m_oldPos.GetY() - m_newPos.GetY() );

		sspTemp.SetX( m_oldPos.GetX() - fSection.GetX() * fFraction );
		sspTemp.SetY( m_oldPos.GetY() - fSection.GetY() * fFraction );

		if( Compare( m_oldPos.GetX(), m_newPos.GetX() ) )
		{
			sspTemp = CalculatePoint( m_oldPos, m_newPos, fFraction );
		}

		m_rect.x += sspTemp.GetX();
		m_rect.y += sspTemp.GetY();
	}

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
	//int i = first.GetX() * ( 1 - speed ) + speed * second.GetX();
	nextPoint.SetX( first.GetX() * ( 1 - speed ) + speed * second.GetX() );
	nextPoint.SetY( first.GetY() * ( 1 - speed ) + speed * second.GetY() );

	CMyPoint retPoint = nextPoint - first;

	return nextPoint;
}

float CalculateProgress( unsigned int uiStartTime, unsigned int uiEndTime, unsigned int uiTimeToken )
{
	if( uiStartTime > uiTimeToken )
	{
		return 0.0f;
	}
	if( ( uiEndTime <= uiTimeToken ) || ( uiStartTime > uiEndTime ) )
	{
		return 1.0f;
	}
	float fStart = ( float )uiTimeToken - ( float )uiStartTime;
	float fEnd = ( float )uiEndTime - ( float )uiStartTime;

	return( fStart / fEnd );
}

/*
   float EasingQuadAndInv( float fTime )
   {
    return CalcFun( EasingQuad, EasingQuadInv, fTime );
   }*/
float EasingQuad( float fTime )
{
	if( fTime < 0.0f )
	{
		return 0.0f;
	}
	if( fTime > 1.0f )
	{
		return 1.0f;
	}
	return fTime * fTime;
}

float EasingQuadInv( float fTime )
{
	return 1.0f - EasingQuad( 1.0f - fTime );
}

CMyPoint CalculatePoint( CMyPoint& spStartPos, CMyPoint& spStopPos, float fProgress )
{
	return CMyPoint( spStartPos + ( ( spStopPos - spStartPos ) * fProgress ) );
}

inline bool Compare( float val1, float val2 )
{
	return std::fabs( val1 - val2 ) <= ( std::numeric_limits< float >::epsilon() * std::max( std::fabs( val1 ), std::fabs( val2 ) ) );
}
