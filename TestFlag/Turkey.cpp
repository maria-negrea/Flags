#include "Turkey.h"
#include "Star.h"
#ifdef __unix || __unix__
    #include <GL/glut.h>
#else
    #include <glut.h>
#endif


/*
* Draws Turkey flag
* Has 2 partially overlapping circles and a star
* The star is rotated by 20 degrees (counter clockwise)
*/
void Turkey::drawTurkey() 
{
	GLdouble radius=0.8;
	glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
	glTranslatef( (-radius/2), 0.0, -5.0);
	glColor3f( Star::rgb(255), Star::rgb(255), Star::rgb(255));
    glutSolidSphere( radius, 500, 500); 
    glFlush();

	glTranslatef(0.0,0.0,-5.0);
    glColor3f( Star::rgb(223), Star::rgb(13), Star::rgb(14));
    glutSolidSphere( 1.3, 500, 500); 
    glFlush();
	
	glTranslatef( 1.2, 0.0, 2.8);
	glRotatef( 20, 1.2, 0.0, 2.8);
	glColor3f( Star::rgb(255), Star::rgb(255), Star::rgb(255));
	Star::drawStar( 0.0, 0.0, 0.5, 0.2);
	glFlush();
}
