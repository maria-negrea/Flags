#include "Switzerland.h"
#ifdef __unix || __unix__
	#include <GL/glut.h>
#else
	#include <glut.h>
#endif

/*
* Draws Switzerland flag
* First block initialises the color of the rectangles
* Second block draws the vertical rectangle, while the 
* third one draws the horizontal one
*/
void Switzerland::drawSwitzerland() 
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
