#include <iostream>
#include "Point2D.h"
#include <vector>
#include <glut.h>
#include <cmath>

#include "Turkey.h"
#include "Switzerland.h"
#include "HongKong.h"

// Main class including project-wide methods
class Main {
public:
	static void Initialize()
	{
		glutInitWindowSize(500,300);
		glutCreateWindow("Flags");
		glClearColor(Star::rgb(223), Star::rgb(13), Star::rgb(14), Star::rgb(0));
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	}

	static void reshape(int x, int y)
	{
		if (y == 0 || x == 0) return;   
		glMatrixMode(GL_PROJECTION);  
		glLoadIdentity(); 
		gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
		glMatrixMode(GL_MODELVIEW);
		glViewport(0,0,x,y);
	}
};

// Main function implementing a menu for selecting the desired flag
int main (int argc, char **argv)
{
	int flag = 0;
    glutInit(&argc, argv); 
	Main::Initialize();
				
	std::cout<<"Choose your flag! Turkey / Hong Kong / Switzerland / Exit [1|2|3|-1] ";
	std::cin>>flag;
	switch(flag) 
	{
		case 1: 
			{
				glutDisplayFunc(Turkey::drawTurkey);
				break;
			}
		case 2: 
			{
				glutDisplayFunc(HongKong::drawHongKong);
				break;
			}
		case 3: 
			{
				glutDisplayFunc(Switzerland::drawSwitzerland);
				break;
			}
		default: 
			{
			system("cls");
			return 0;
		}
	}

	glutReshapeFunc(Main::reshape);
	glutMainLoop();
    
    return 0;
}



