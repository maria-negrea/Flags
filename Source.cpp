#include "vector"
#include "math.h"
#ifdef __unix || __unix__
	#include <GL/glut.h>
#else
	#include <glut.h>
#endif

struct Point2D{
	double x;
	double y;
	Point2D(double x, double y)
	:x(x), y(y)
	{

	}
};

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	const double pi = 3.1415926535897932384626433832795;
	double raport = GLUT_WINDOW_WIDTH / (double)GLUT_WINDOW_HEIGHT;
    glBegin(GL_POLYGON);
	glColor3f(0., 0., 0.);
	float theta = 0;
    for(int ii = 1; ii <= num_segments; ii++)
    {
		theta += 2 * pi / num_segments;
        glVertex2f(r * cos(theta) + cx,raport * r * sin(theta) + cy);//output vertex
		
    }
    glEnd();
}

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


void ComputeBezier(std::vector<Point2D>controlPoints, std::vector<Point2D> &bladePoints)
{
	for (double t = 0; t <= 1; t += 0.01)
	{
		Point2D s = Point2D(0., 0.);
		for(int i = 0; i < controlPoints.size(); i++)
		{
			double coef = Bezier(controlPoints.size() - 1, i, t);
			s.x += controlPoints[i].x * coef;
			s.y += controlPoints[i].y * coef;
		}
		bladePoints.push_back(s);
	}
}
std::vector<Point2D*> DrawArc(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments) 
{ 
	 float theta = arc_angle / float(num_segments - 1);
	 float tangetial_factor = tanf(theta);
	 float radial_factor = cosf(theta);
	 float x = r * cosf(start_angle);
	 float y = r * sinf(start_angle); 

	 std::vector<Point2D*> points;
	 points.push_back(new Point2D(x+cx,y+cy));

	 for(int i = 0; i < num_segments; i++)
	 { 
		  float tx = -y; 
		  float ty = x; 

		  x += tx * tangetial_factor; 
		  y += ty * tangetial_factor; 

		  x *= radial_factor; 
		  y *= radial_factor; 
		  points.push_back(new Point2D(x+cx,y+cy));
	 } 

	 return points;
}


void DrawAngolaFlag()
{
	glClearColor(224.0/255.0, 18.0/255.0, 18.0/255.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0., 0., 0.);
	glVertex2d(0., 0.5);
	glVertex2d(1., 0.5);
	glVertex2d(1., 0.0);
	glVertex2d(0., 0.0);
	glEnd();
	

/// ------------------ \\\

	/* const double pi = 3.1415926535897932384626433832795;
	std::vector<Point2D*> points1=DrawArc(0.45, 0.5, 0.34, -pi/2-0.15, 180*pi/180, 50);
	std::vector<Point2D*> points2=DrawArc(0.45, 0.5, 0.3, -pi/2-0.15, 180*pi/180, 50);
 */
	/*glBegin(GL_QUADS);
	glColor3f(200.0 / 255.0, 200.0 / 255.0, 0.0);
	for(int i=0; i<49; i++){
		glVertex2f(points1[i]->x, points1[i]->y);
		glVertex2f(points1[i+1]->x, points1[i+1]->y);
		glVertex2f(points2[i+1]->x, points2[i+1]->y);
		glVertex2f(points2[i]->x, points2[i]->y);
	}
	glEnd();*/
	//std::vector<Point2D*> points3=DrawArc(0.45, 0.5, 0.38, -pi/2-0.15, 180*pi/180, 50);
 //
	//glBegin(GL_LINES);
	//glColor3f(1., 1., 1.);
	///*for(int i=0; i<45; i+=5){
	//	glVertex2f(points1[i]->x, points1[i]->y);
	//	glVertex2f(points1[i+3]->x, points1[i+3]->y);
	//	glVertex2f(points3[i+3]->x, points3[i+3]->y);
	//	glVertex2f(points3[i]->x, points3[i]->y);
	//}*/
	//for (int i = 1; i < points3.size(); i++)
	//{
	//	glVertex2d(points3[i-1]->x, points3[i-1]->y);
	//	glVertex2d(points3[i]->x, points3[i]->y);
	//	
	//}
	//glEnd();




	std::vector<Point2D> bladeUpPoints;
	std::vector<Point2D> bladeDownPoints;
	std::vector<Point2D> controlPoints;
	
	controlPoints.push_back(Point2D(0.475, 0.57));
	controlPoints.push_back(Point2D(0.465, 0.5));
	controlPoints.push_back(Point2D(0.78, 0.25));
	ComputeBezier(controlPoints, bladeUpPoints);
	
	controlPoints.clear();
	controlPoints.push_back(Point2D(0.475, 0.57));
	controlPoints.push_back(Point2D(0.435, 0.368));
	controlPoints.push_back(Point2D(0.52, 0.38));
	controlPoints.push_back(Point2D(0.6, 0.35));
	controlPoints.push_back(Point2D(0.7552, 0.215));
	ComputeBezier(controlPoints, bladeDownPoints);


	
	for (int i = 1; i < bladeUpPoints.size(); i++)
	{
		glBegin(GL_QUADS);
		glColor3f(200.0 / 255.0, 200.0 / 255.0, 0.0);
		glVertex2d(bladeUpPoints[i-1].x, bladeUpPoints[i-1].y);
		glVertex2d(bladeUpPoints[i].x, bladeUpPoints[i].y);
		glVertex2d(bladeDownPoints[i].x, bladeDownPoints[i].y);
		glVertex2d(bladeDownPoints[i-1].x, bladeDownPoints[i-1].y);
		glEnd();
	}
	
	glBegin(GL_QUADS);
	glColor3f(0., 0., 0.);
	glVertex2f(0.77, 0.24);
	glVertex2f(0.767, 0.235);
	glVertex2f(0.545, 0.43);
	glVertex2f(0.548, 0.435);
	glEnd();
	
	
	
/// -----------------------------   \\\

	std::vector<Point2D> handleUpPoints;
	std::vector<Point2D> handleDownPoints;
	controlPoints.clear();
	
	controlPoints.push_back(Point2D(0.782, 0.255));
	controlPoints.push_back(Point2D(0.82, 0.22));
	controlPoints.push_back(Point2D(0.87, 0.2));
	controlPoints.push_back(Point2D(0.86, 0.15));
	ComputeBezier(controlPoints, handleUpPoints);

	controlPoints.clear();
	controlPoints.push_back(Point2D(0.7526, 0.213));
	controlPoints.push_back(Point2D(0.7535, 0.205));
	controlPoints.push_back(Point2D(0.755, 0.20));
	//aici
	controlPoints.push_back(Point2D(0.82, 0.23));
	controlPoints.push_back(Point2D(0.83, 0.1));
	controlPoints.push_back(Point2D(0.86, 0.15));
	ComputeBezier(controlPoints, handleDownPoints);
	
	for (int i = 1; i < handleUpPoints.size(); i++)
	{
		
		glBegin(GL_QUADS);
		glColor3f(200.0 / 255.0, 200.0 / 255.0, 0.0);
		glVertex2d(handleUpPoints[i-1].x, handleUpPoints[i-1].y);
		glVertex2d(handleUpPoints[i].x, handleUpPoints[i].y);
		glVertex2d(handleDownPoints[i].x, handleDownPoints[i].y);
		glVertex2d(handleDownPoints[i-1].x, handleDownPoints[i-1].y);
		glEnd();	
	}
	
	DrawCircle(0.79, 0.228, 0.005, 180);
	DrawCircle(0.814, 0.21, 0.005, 180);
	DrawCircle(0.835, 0.19, 0.005, 180);

	

	glFlush();
}

void Initialize() {

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv)
{
glutInit(&iArgc, cppArgv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(200, 200);
glutCreateWindow("Angola Flag");
Initialize();
glutDisplayFunc(DrawAngolaFlag);
glutMainLoop();

return 0;
}

