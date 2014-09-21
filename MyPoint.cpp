#include "stdafx.h"
#include "MyPoint.h"

CMyPoint::CMyPoint()
{
	m_x = 0;
	m_y = 0;
}

CMyPoint::CMyPoint( double x, double y )
{
	m_x = x;
	m_y = y;
}

CMyPoint::~CMyPoint()
{}

void CMyPoint::SetX( double x )
{
	m_x = x;
}

double CMyPoint::GetX()
{
	return m_x;
}

void CMyPoint::SetY( double y )
{
	m_y = y;
}

double CMyPoint::GetY()
{
	return m_y;
}

bool CMyPoint::operator==( CMyPoint point )
{
	return ( ( this->m_x == point.GetX() ) && ( this->m_y == point.GetY() ) ) ? true : false;
}

CMyPoint CMyPoint::operator+( CMyPoint point )
{
	return CMyPoint( this->m_x += point.GetX(), this->m_y += point.GetY() );
}

CMyPoint CMyPoint::operator=( CMyPoint point )
{
	return CMyPoint( this->m_x = point.GetX(), this->m_y = point.GetY() );
}

CMyPoint CMyPoint::operator*( CMyPoint point )
{
	return CMyPoint( this->m_x * point.GetX(), this->m_y * point.GetY() );
}

CMyPoint CMyPoint::operator*( int iMultipler )
{
	return CMyPoint( this->m_x * iMultipler, this->m_y * iMultipler );
}

CMyPoint CMyPoint::operator/( int iMultipler )
{
	return CMyPoint( this->m_x / iMultipler, this->m_y / iMultipler );
}

CMyPoint CMyPoint::operator-( CMyPoint point )
{
	return CMyPoint( this->m_x -= point.GetX(), this->m_y -= point.GetY() );
}

CMyPoint CMyPoint::MyPointSQRT( CMyPoint point )
{
	if( point == CMyPoint( 0, 0 ) )
	{
		return CMyPoint( -1, -1 );
	}
	return CMyPoint( sqrt( point.GetX() ), sqrt( point.GetY() ) );
}

CMyPoint CMyPoint::MyPointPOW( CMyPoint point )
{
	if( point == CMyPoint( 0, 0 ) )
	{
		return CMyPoint( 0, 0 );
	}
	return CMyPoint( pow( ( double )point.GetX(), 2 ), pow( ( double )point.GetY(), 2 ) );
}

void CMyPoint::Set( double x, double y )
{
	this->m_x = x;
	this->m_y = y;
}

void CMyPoint::Set(CMyPoint point)
{
	this->m_x = point.GetX();
	this->m_y = point.GetY();
}
