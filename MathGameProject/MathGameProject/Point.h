#ifndef __POINT_H
#define __POINT_H

#include <iostream>

using namespace std;

class Point{
public:
	enum {
		minX = 0,
		maxX = 79,
		minY = 3,
		maxY = 23
	};

	int x;
	int y;
	Point(int x, int y) :x(x), y(y){
	}
	Point(){
		x = (rand() % 80);
		y = (rand() % 21 + 3);
	}
	bool comparePoints(Point const &otherPoint){
		return (x == otherPoint.x && y == otherPoint.y);
	}
};

#endif
