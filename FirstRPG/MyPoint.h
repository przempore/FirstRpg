#pragma once
class CMyPoint
{
public:
	CMyPoint( double x, double y );
	CMyPoint();
	virtual ~CMyPoint();

	void SetX( double x );
	double GetX();

	void SetY( double y );
	double GetY();

	void Set( double x, double y );

	bool operator==( CMyPoint point );
	CMyPoint operator+( CMyPoint point );
	CMyPoint operator=( CMyPoint point );
	CMyPoint operator*( CMyPoint point );
	CMyPoint operator*( int iMultipler );
	CMyPoint operator/( int iMultipler );
	CMyPoint operator-( CMyPoint point );

	static CMyPoint MyPointSQRT( CMyPoint point );
	static CMyPoint MyPointPOW( CMyPoint point );

private:
	double m_x;
	double m_y;
};
