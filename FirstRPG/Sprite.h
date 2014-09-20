#pragma once

#include "MyPoint.h"

class CSprite
{
public:
	CSprite( SDL_Renderer* renderer, char* url, int x, int y, int w, int h );
	virtual ~CSprite();

	void Draw();
	void Move( SDL_Event* moveEvent );

	void PlayAnimation( int beginFrame, int endFrame, int row, float speed );

private:
	CMyPoint NextStep( CMyPoint first, CMyPoint second, double speed );

	SDL_Texture*  m_image; ///< sdf
	SDL_Rect      m_rect;  ///< sdkjhfsd
	SDL_Rect      m_crop;
	SDL_Renderer* m_renderer;
	CMyPoint      m_nextPoint;
	CMyPoint      m_mousePos;
	CMyPoint      m_bobPos;

	int m_mouseX;
	int m_mouseY;
	int m_iDistance;

	int m_imgWidth;
	int m_imgHeight;
};
