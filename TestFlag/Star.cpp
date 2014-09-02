#include "Star.h"
#ifdef __unix || __unix__
	#include <GL/glut.h>
#else
	#include <glut.h>
#endif
#include <math.h>

/*
* This method draws a star determined by triangles
* The parameters fX and fY represent the coordinates of the vertex
* on the top of the star
*/

void Star::drawStar(float fX, float fY, float kfRadius, float kfInnerRadius)
{
	const float kfPi = 3.1415926535897932384626433832795;
	const float stpConst = 1.0;
	
	glBegin(GL_TRIANGLE_FAN);
		
		glVertex3f(fX, fY, 0.0);
		
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) 
		{
			float fAngleStart	= kfPi/2.0 + (iVertIndex*2.0*kfPi)/10.0;
			float fAngleEnd		= fAngleStart + kfPi/5.0;
			if (iVertIndex % 2 == 0) 
			{
				glVertex3f(fX + kfRadius*cos(fAngleStart)/stpConst, fY + kfRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfInnerRadius*cos(fAngleEnd)/stpConst, fY + kfInnerRadius*sin(fAngleEnd), 0.0);
			} 
			else 
			{
				glVertex3f(fX + kfInnerRadius*cos(fAngleStart)/stpConst, fY + kfInnerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfRadius*cos(fAngleEnd)/stpConst, fY + kfRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

/*
* This method converts a value in [0, 255] to [0, 1]
*/

double Star::rgb(int old) 
{
	return ( (double)old ) / 255.0;
}