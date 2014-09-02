#include <iostream>
#include <vector>
#include <math.h>
#include "Point2D.h"
#include "Star.h"
#include "HongKong.h"
#ifdef __unix || __unix__
	#include <GL/glut.h>
#else
	#include <glut.h>
#endif

int getComb(int n, int i)
{
	if (n == i || i == 0)
		return 1;
	return (n * getComb(n - 1, i - 1)) / i;

}

double Bezier(int n, int i, double t)
{
	 return (double)getComb(n, i) * pow(t, i) * pow((1 - t), (n - i));
}


void ComputeBezier(std::vector<Point2D>controlPoints, std::vector<Point2D> &curvePoints)
{
	curvePoints.clear();
	for (double t = 0; t <= 1; t += 0.01)
	{
		Point2D s = Point2D(0., 0.);
		for(int i = 0; i < controlPoints.size(); i++)
		{
			double coef = Bezier(controlPoints.size() - 1, i, t);
			s.x += controlPoints[i].x * coef;
			s.y += controlPoints[i].y * coef;
		}
		curvePoints.push_back(s);
	}
}

void drawQuads(std::vector<Point2D> curve1, std::vector<Point2D> curve2) {
	for(int i=0; i < curve1.size() - 1; i++) {
		glBegin(GL_QUADS);
			glColor3f(255.0 / 255.0, 255.0 / 255.0, 255.0);
			glVertex2f(curve1[i].x, curve1[i].y);
			glVertex2f(curve1[i+1].x, curve1[i+1].y);
			glVertex2f(curve2[i+1].x, curve2[i+1].y);
			glVertex2f(curve2[i].x, curve2[i].y);
		glEnd();
	}
}

void drawCurve(std::vector<Point2D> curve) {
	for(int i=0; i < curve.size() - 1; i++) {
		glBegin(GL_LINES);
			glColor3f(255.0 / 255.0, 0.0 / 255.0, 0.0);
			glVertex2f(curve[i].x, curve[i].y);
			glVertex2f(curve[i+1].x, curve[i+1].y);
		glEnd();
	}
}

void drawControlPoints(std::vector<Point2D> controlPoints) {
	for(int i=0; i < controlPoints.size(); i++) {
		glPointSize(4.0);
		glBegin(GL_POINTS);
			glColor3f(0.0 / 255.0, 255.0 / 255.0, 255.0);
			glVertex2f(controlPoints[i].x, controlPoints[i].y);
		glEnd();
	}
}

double dist(Point2D x, Point2D y) {
	return sqrt( (x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y) );
}

double original(Point2D c) {
	double radius = dist(c, Point2D(0.0, 0.0));
	Point2D temp(radius, 0.0);
	double x = dist(temp, c);
	double pi = 3.1415;

	return 2.0*(asin(x/(2.0*radius)));
}

void rotate(std::vector<Point2D> &controlPoints, int angle) {
	double pi = 3.1415;
	for(int i=1; i < controlPoints.size(); i++) {
		double radius = dist(controlPoints[i], Point2D(0.0, 0.0));
		double origAngle = original(controlPoints[i]);
		std::cout<<radius<<std::endl;
		double up = 0;
		if(controlPoints[i].y < 0)
			origAngle = 2*pi-origAngle;
		controlPoints[i].x = 0.0 + radius*cos(angle*pi/180 + origAngle);
		controlPoints[i].y = 0.0 + radius*sin(angle*pi/180 + origAngle);
	}
}



/*!
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
	std::vector<Point2D> cp1, curve1;
	std::vector<Point2D> cp2, curve2;
	std::vector<Point2D> cp3, curve3;
	glClear (GL_COLOR_BUFFER_BIT);

	cp1.push_back(Point2D(0.0, 0.0));
	cp1.push_back(Point2D(-0.2, 0.45));
	cp1.push_back(Point2D(0.2, 0.6));

	ComputeBezier(cp1, curve1);

	cp2.push_back(Point2D(0.0, 0.0));
	cp2.push_back(Point2D(-0.08, 0.15));
	cp2.push_back(Point2D(0.6, 0.25));
	cp2.push_back(Point2D(0.06, 0.4));
	cp2.push_back(Point2D(0.2, 0.6));

	ComputeBezier(cp2, curve2);

	cp3.push_back(Point2D(0.0, 0.0));
	cp3.push_back(Point2D(-0.01, 0.2));
	cp3.push_back(Point2D(0.1, 0.3));

	ComputeBezier(cp3, curve3);
	drawQuads(curve1, curve2);
	drawCurve(curve3);

	for(int i=0; i < 4; i++) {
		rotate(cp1, 72);
		rotate(cp2, 72);
		ComputeBezier(cp1, curve1);
		ComputeBezier(cp2, curve2);
		drawQuads(curve1, curve2);
	}

	glFlush ();
}
