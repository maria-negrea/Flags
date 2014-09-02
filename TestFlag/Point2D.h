#pragma once

class Point2D
{
public:
	double x, y;
	Point2D(double cx, double cy) : x(cx), y(cy) {}

    Point2D& operator= (Point2D temp) {
        this->x = temp.x;
        this->y = temp.y;
    }
	~Point2D(){}
};
