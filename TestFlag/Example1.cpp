#include <iostream>
#include "Point2D.h"
#include <vector>
#include <glut.h>
#include <cmath>

using namespace std;

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=0.8;

vector<Point2D> vec1, vec2;


void DrawStar(float fX, float fY) {
	const float kfPi = 3.1415926535897932384626433832795;
	// Draw ten triangles
	//set the radius and the inner radius
	const float kfRadius = 0.5;//0.0616/2.0;
	const float kfInnerRadius = 0.2;//kfRadius*(1.0/(sin((2.0*kfPi)/5.0)*2.0*cos(kfPi/10.0) + sin((3.0*kfPi)/10.0)));
	const float stpConst = 1.0;
	//set the color
	//glColor3f(1.0, 1.0, 0.0);
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

void display(void);
void reshape(int x, int y);
void Initialize(int width, int height);
inline double rgb(int old);


void display2()                    
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0 , -6.8);
    glutSolidSphere(0.05,500, 500); 
    glFlush();

	double  PI = 3.141592654;
	glRotatef(100, 0.0, 0.0, -6.8);	
	//glTranslatef(-1.02, -0.45, 0.0);
	
    glBegin(GL_LINE_STRIP);
		int count = 0;
		for(double i =-1; i < 1;i+=0.1){
			Point2D temp(i-1.02, 0.65*i*i+0.1*i-0.3-0.45);
			glVertex3f(temp.x, temp.y, 0.0);
			vec1.push_back(temp);
			count++;
		}
	std::cout<<"Count1: "<<count<<std::endl;
    glEnd();

	glRotatef(-4.9, 0.0, 0.0, -6.8);
	//glTranslatef(0.01, 0.68, 0.0);
	glColor3f (1.0, 1.0, 1.0);
	
	glBegin(GL_LINE_STRIP);
		count = 0;
		for(double i = -1; i < 1; i+=0.1){
			Point2D temp(i-1.0, cos(PI*i)/3+0.32);
			glVertex3f(temp.x, temp.y, 0.0);
			count++;
			vec2.push_back(temp);
		}
		std::cout<<"Count2: "<<count<<std::endl;
    glEnd();

	glBegin(GL_QUADS);
		for(int i=0; i < vec1.size()-1; i+=1) {
			glVertex3f(vec1[i].x, vec1[i].y, 0.0);
			glVertex3f(vec1[i+1].x, vec1[i+1].y, 0.0);
			glVertex3f(vec2[i+1].x, vec2[i+1].y, 0.0);
			glVertex3f(vec2[i].x, vec2[i].y, 0.0);
			
		}
	glEnd();

    glFlush ();      //forces previously issued commands to execute
}

void display3()
{
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0 , -6.8);
	
	glBegin(GL_QUADS);
		glVertex3f(-0.565, 1.7, 0.0);
		glVertex3f(0.565, 1.7, 0.0);
		glVertex3f(0.565, -1.7, 0.0);
		glVertex3f(-0.565, -1.7, 0.0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(-1.7, 0.565, 0.0);
		glVertex3f(1.7, 0.565, 0.0);
		glVertex3f(1.7, -0.565, 0.0);
		glVertex3f(-1.7, -0.565, 0.0);
	glEnd();
	glPopMatrix();
	glFlush (); 
}

int main (int argc, char **argv)
{
	int flag = 0;
    glutInit(&argc, argv); 
    glutInitWindowSize(500,300);
    glutCreateWindow("Flags");
    /*xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;*/
	std::cout<<"Choose your flag! [1 | 2 | 3] ";
	std::cin>>flag;
	switch(flag)
	{
	case 1:
		{
			Initialize(500, 300);
			glutDisplayFunc(display);
			glutReshapeFunc(reshape);
			break;
		}
	case 2:
		{
			Initialize(500, 300);
			glutDisplayFunc(display2);
			glutReshapeFunc(reshape);
			break;
		}
	case 3:
		{
			Initialize(500, 300);
			glutDisplayFunc(display3);
			glutReshapeFunc(reshape);
			break;
		}
	}

    glutMainLoop();
    return 0;
}

void Initialize(int width, int height) {
	glutInitWindowSize(width, height);
	glClearColor(rgb(223), rgb(13), rgb(14), rgb(0));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

inline double rgb(int old) {
	return ( (double)old ) / 255.0;
}

void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef((-radius/2)-0.1,0.0,-5.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(radius,500, 500); 
    glFlush();

	glTranslatef(0.0-0.1,0.0,-5.0);
    glColor3f(rgb(223), rgb(13), rgb(14));
    glutSolidSphere(1.3,500, 500); 
    glFlush();
	
	glTranslatef(1.2,0.0,2.8);
	glRotatef(20, 1.2, 0.0, 2.8);
	glColor3f(rgb(255), rgb(255), rgb(255));
	DrawStar(0.0, 0.0);
	glFlush();
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
	//glTranslatef(0.0, 0.0 , 6.8);
} 

