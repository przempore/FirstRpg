#pragma once

#include "MyPoint.h"

class CSprite
{
public:
	CSprite( SDL_Renderer* renderer, char* url, int x, int y, int w, int h );
	virtual ~CSprite();

	void Draw();
	void Move( SDL_Event* moveEvent );

	void PlayAnimation(int beginFrame, int endFrame, int row, float speed);
	void SetUpAnimation(int passedAmointX, int passedAmmountY);

private:
	void PrepereToMove();
	SDL_Texture*  m_image; ///< sdf
	SDL_Rect      m_rect;  ///< sdkjhfsd
	SDL_Rect      m_crop;
	SDL_Renderer* m_renderer;
	CMyPoint      sspTemp;
	CMyPoint      m_mousePos;
	CMyPoint      m_bobPos;

	CMyPoint m_oldPos;
	CMyPoint m_newPos;

	int m_mouseX;
	int m_mouseY;
	int m_iDistance;

	bool m_bIsMoving;

	int m_imgWidth;
	int m_imgHeight;
	int m_currentFrame;
	int m_animDelay;
	int m_amountFrameX;
	int m_amountFrameY;

	unsigned long m_ulStartMove;
	unsigned long m_ulStopMove;
};
inline bool Compare(float val1, float val2);
CMyPoint CalculatePoint(CMyPoint& spStartPos, CMyPoint& spStopPos, float fProgress);
float EasingQuadInv(float fTime);
float EasingQuad(float fTime);
//float EasingQuadAndInv(float fTime);
float CalculateProgress(unsigned int uiStartTime, unsigned int uiEndTime, unsigned int uiTimeToken);