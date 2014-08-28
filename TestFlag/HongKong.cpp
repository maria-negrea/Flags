#include "HongKong.h"
#include <iostream>
#include "Point2D.h"
#include "Star.h"
#include <glut.h>
#include <vector>
#include <math.h>


/*
* Drawing one leaf from the Hong Kong flag

* Has 2 curves determined by 2 equations
*	    x in [-1;1]
*		y = 0.65 * x ^ 2 + 0.1 * x - 0.75
*	and 
*		x in [-1;1]
*		y = cos( PI * x )/ 3 + 0.32

* The leaf also has a line inside, given by 
* the same equation as the first curve

* On the top of this line there is a star, 
* rotated clockwise by 4.9 degrees

* In order to fill the leaf, we selected points 
* having the same OY coordinate and joined them
* in a Quad

*/
void HongKong::drawHongKong() 
{
	std::vector<Point2D> vec1, vec2;
	double PI = 3.141592654;
	int count = 0;
	
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (Star::rgb(223), Star::rgb(13), Star::rgb(14));
	glTranslatef( 0.0, 0.0 , -6.8);
    glutSolidSphere( 0.05, 500, 500); 
    glFlush();

	glRotatef( 100, 0.0, 0.0, -6.8);
    glBegin(GL_LINE_STRIP);
		for(double i =-1; i < 1;i+=0.1)
		{
			Point2D temp(i-1.02, 0.65*i*i+0.1*i-0.75);
			glVertex3f(temp.x, temp.y, 0.0);
			vec1.push_back(temp);
			count++;
		}
    glEnd();

	glRotatef( -4.9, 0.0, 0.0, -6.8);
	glColor3f ( Star::rgb(255), Star::rgb(255), Star::rgb(255));
	glBegin(GL_LINE_STRIP);
		count = 0;
		for(double i = -1; i < 1; i+=0.1)
		{
			Point2D temp(i-0.7, cos(PI*i)/3+0.32);
			glVertex3f(temp.x, temp.y, 0.0);
			count++;
			vec2.push_back(temp);
		}
    glEnd();

	glBegin(GL_QUADS);
		for(int i=0; i < vec1.size()-1; i+=1) 
		{
			glVertex3f(vec1[i].x, vec1[i].y, 0.0);
			glVertex3f(vec1[i+1].x, vec1[i+1].y, 0.0);
			glVertex3f(vec2[i+1].x, vec2[i+1].y, 0.0);
			glVertex3f(vec2[i].x, vec2[i].y, 0.0);
			
		}
	glEnd();
	
	glRotatef(0, 0.0, 0.0, -6.8);
	glColor3f (Star::rgb(223), Star::rgb(13), Star::rgb(14));
    glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
		for(double i =-0.6; i < 0.6;i+=0.1)
		{
			Point2D temp(i-0.06, 0.45*i*i+0.1*i-0.08);
			glVertex3f(temp.x, temp.y, 0.0);
		}
    glEnd();

	glTranslatef(-0.5,0.05,2.8);
	glColor3f(Star::rgb(223), Star::rgb(13), Star::rgb(14));
	Star::drawStar(0.0, 0.0, 0.1, 0.05);
	glFlush ();
}
