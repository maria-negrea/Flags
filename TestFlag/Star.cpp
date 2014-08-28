#include "Star.h"
#include <glut.h>
#include <math.h>

void Star::drawStar(float fX, float fY, float bigRadius, float smallRadius){
	const float kfPi = 3.1415926535897932384626433832795;

	const float kfRadius = bigRadius; 
	const float kfInnerRadius = smallRadius;
	const float stpConst = 1.0;
	
	glBegin(GL_TRIANGLE_FAN);
		
		glVertex3f(fX, fY, 0.0);
		
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) {
			float fAngleStart	= kfPi/2.0 + (iVertIndex*2.0*kfPi)/10.0;
			float fAngleEnd		= fAngleStart + kfPi/5.0;
			if (iVertIndex % 2 == 0) {
				glVertex3f(fX + kfRadius*cos(fAngleStart)/stpConst, fY + kfRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfInnerRadius*cos(fAngleEnd)/stpConst, fY + kfInnerRadius*sin(fAngleEnd), 0.0);
			} else {
				glVertex3f(fX + kfInnerRadius*cos(fAngleStart)/stpConst, fY + kfInnerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfRadius*cos(fAngleEnd)/stpConst, fY + kfRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

double Star::rgb(int old) {
	return ( (double)old ) / 255.0;
}