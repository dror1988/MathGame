#ifndef __POINT_H
#define __POINT_H

#include <iostream>
using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int x=0, int y=0):x(x),y(y){
	}
};

#endif