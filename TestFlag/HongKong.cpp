#include "HongKong.h"
#include <iostream>
#include "Point2D.h"
#include "Star.h"
#include <glut.h>
#include <vector>
#include <math.h>


void HongKong::drawHongKong() {
	std::vector<Point2D> vec1, vec2;
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (Star::rgb(223), Star::rgb(13), Star::rgb(14));
	glTranslatef(0.0, 0.0 , -6.8);
    glutSolidSphere(0.05,500, 500); 
    glFlush();

	double  PI = 3.141592654;
	glRotatef(100, 0.0, 0.0, -6.8);	
	
    glBegin(GL_LINE_STRIP);
		int count = 0;
		for(double i =-1; i < 1;i+=0.1){
			Point2D temp(i-1.02, 0.65*i*i+0.1*i-0.3-0.45);
			glVertex3f(temp.x, temp.y, 0.0);
			vec1.push_back(temp);
			count++;
		}
    glEnd();

	glRotatef(-4.9, 0.0, 0.0, -6.8);
	glColor3f (1.0, 1.0, 1.0);
	
	glBegin(GL_LINE_STRIP);
		count = 0;
		for(double i = -1; i < 1; i+=0.1){
			Point2D temp(i-0.7, cos(PI*i)/3+0.32);
			glVertex3f(temp.x, temp.y, 0.0);
			count++;
			vec2.push_back(temp);
		}
    glEnd();

	glBegin(GL_QUADS);
		for(int i=0; i < vec1.size()-1; i+=1) {
			glVertex3f(vec1[i].x, vec1[i].y, 0.0);
			glVertex3f(vec1[i+1].x, vec1[i+1].y, 0.0);
			glVertex3f(vec2[i+1].x, vec2[i+1].y, 0.0);
			glVertex3f(vec2[i].x, vec2[i].y, 0.0);
			
		}
	glEnd();
	
	glRotatef(0, 0.0, 0.0, -6.8);
	glColor3f (Star::rgb(223), Star::rgb(13), Star::rgb(14));
    glBegin(GL_LINE_STRIP);
		for(double i =-0.6; i < 0.6;i+=0.1){
			glLineWidth(100.0);
			Point2D temp(i-0.065, 0.45*i*i+0.1*i-0.08);
			glVertex3f(temp.x, temp.y, 0.0);
		}
    glEnd();

	glTranslatef(-0.5,0.05,2.8);
	glColor3f(Star::rgb(223), Star::rgb(13), Star::rgb(14));
	Star::drawStar(0.0, 0.0, 0.1, 0.05);
	glFlush ();
}
