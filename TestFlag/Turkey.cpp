#include "Turkey.h"
#include "Star.h"
#include <glut.h>

void Turkey::drawTurkey() {
	GLdouble radius=0.8;
	glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef((-radius/2)-0.1,0.0,-5.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(radius,500, 500); 
    glFlush();

	glTranslatef(0.0-0.1,0.0,-5.0);
    glColor3f(Star::rgb(223), Star::rgb(13), Star::rgb(14));
    glutSolidSphere(1.3,500, 500); 
    glFlush();
	
	glTranslatef(1.2,0.0,2.8);
	glRotatef(20, 1.2, 0.0, 2.8);
	glColor3f(Star::rgb(255), Star::rgb(255), Star::rgb(255));
	Star::drawStar(0.0, 0.0, 0.5, 0.2);
	glFlush();
    // sawp buffers called because we are using double buffering 
    // glutSwapBuffers();
}
