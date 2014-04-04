// object to describe a mathematical point

#ifndef POINT_H
#define POINT_H
#include <math.h>

using namespace std;

class point
{
public:
	// constructors for 3d points
	// point is cartesian by default
	// angles are defined in radians
	point(float fXCord, float fYCord, float fZCord);
	~point();
	//point( point& other);
	//point& operator=(const &point other);
	//cylPoint(float fRhoCord, float fPhiChord, float fZCord);
	//sphPoint(float fRCord, float fPhiChord, float fThetaCord);

	//constructors for 2dpoints
	point(float fXCord, float fYCord);
	//radPoint(float fRCord, float fPhiChord);
	
	float distanceToOrigin();
	float distanceToPoint(const point& other);
	
private:
	float px;
	float py;
	float pz;
	//float pRho;
	//float pPhi;
	//float pR;
	//float pTheta;
};
#endif