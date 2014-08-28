#include <iostream>
#include "Point2D.h"
#include <vector>
#include <glut.h>
#include <cmath>

#include "Turkey.h"
#include "Switzerland.h"
#include "HongKong.h"

class Main {
public:
	static void Initialize(int width, int height) {
		glutInitWindowSize(width, height);
		glClearColor(Star::rgb(223), Star::rgb(13), Star::rgb(14), Star::rgb(0));
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	}

	static void reshape(int x, int y) {
		if (y == 0 || x == 0) return;   
		glMatrixMode(GL_PROJECTION);  
		glLoadIdentity(); 
		gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
		glMatrixMode(GL_MODELVIEW);
		glViewport(0,0,x,y);
	}
};

int main (int argc, char **argv)
{
	int flag = 0;
    glutInit(&argc, argv); 
    glutInitWindowSize(500,300);
    glutCreateWindow("Flags");
	
	std::cout<<"Choose your flag! Turkey / Hong Kong / Switzerland / Exit [1|2|3|-1] ";
	std::cin>>flag;
	switch(flag) {
		case 1: {
				Main::Initialize(500, 300);
				glutDisplayFunc(Turkey::drawTurkey);
				glutReshapeFunc(Main::reshape);
				break;
			}
		case 2: {
				Main::Initialize(500, 300);
				glutDisplayFunc(HongKong::drawHongKong);
				glutReshapeFunc(Main::reshape);
				break;
			}
		case 3: {
				Main::Initialize(500, 300);
				glutDisplayFunc(Switzerland::drawSwitzerland);
				glutReshapeFunc(Main::reshape);
				break;
			}
		default: {
			system("cls");
			return 0;
		}
	}
	glutMainLoop();
    
    return 0;
}



