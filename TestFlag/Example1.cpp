#include <iostream>

#include <glut.h>
#include <cmath>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=0.8;


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
void Initialize();
inline double rgb(int old);

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
	if(flag == 1) {
		Initialize();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
	} else if(flag == 2) {

	} else if(flag == 3) {

	}
    glutMainLoop();
    return 0;
}

void Initialize() {
	glClearColor(rgb(255), rgb(0), rgb(0), rgb(0));
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
    glColor3f(rgb(255), rgb(0), rgb(0));
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
} 

//FLAGS: http://www.photius.com/flags/alphabetic_list.html, Panama, Switzerland, Israel, etc