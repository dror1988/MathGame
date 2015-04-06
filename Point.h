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
	Point(int x=0, int y=0):x(x),y(y){
	}
};

#endif