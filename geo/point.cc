/************************************
 * point.cc					*
 * A mathematical point object	*
 * v1.0 - April 2, 2014			*
 ***********************************/

#include "./point.h"
#include <iostream>

#define PI 3.14159265

point::point(float fXCord, float fYCord, float fZCord)
:px(fXCord), py(fYCord), pz(fZCord)
{
	/*pRho	 = sqrt(fXCord*fXCord+fYCord*fYCord);
	pR	 = sqrt(fXCord*fXCord+fYCord*fYCord+fZCord*fZCord);
	if(pR!=0)
	{
		pTheta = acos(pz/pR);
	} else {
		pTheta = 0;
	}
	
	if(px!=0)
	{
		pPhi	 = atan(py/px);
	} else if(py>=0) {
		pPhi = PI/2.0;
	} else {
		pPhi = 3*PI/2.0;
	}*/
	
	/*cout << "rho: " << pRho << ", phi: " << pPhi << cout;
	cout << "R: " << pR << ", theta: " << pTheta << cout;*/
}

point::~point()
{ }

//point::point( point& other)

//point& point::operator=(const &point other)

//point::cylPoint(float fRCord, float fPhiChord, float fZCord)

//point::sphPoint(float fRCord, float fPhiChord, float fThetaCord)

point::point(float fXCord, float fYCord)
:px(fXCord), py(fYCord), pz(0)
{ }

//point::radPoint(float fRCord, float fPhiChord)

float point::distanceToOrigin()
{
	return sqrt(px*px + py*py + pz*pz);
}

float point::distanceToPoint(const point& other)
{
	float dx = px - other.px;
	float dy = py - other.py;
	float dz = pz - other.pz;
	
	return sqrt(dx*dx + dy*dy + dz*dz);
}