#include <iostream>
#include <cmath>
#include "Point2d.h"
using namespace std;

Point2d::Point2d(double x, double y) {
    m__x = x;
    m__y = y;
}

void Point2d::print() {
    cout << "Point2d(" << m__x << "," << m__y << ");" << endl;
}

double Point2d::getX() {
    return m__x;
}

double Point2d::getY() {
    return m__y;
}

double Point2d::distanceTo(Point2d toPoint) {
    double xTo = toPoint.getX();
    double yTo = toPoint.getY();
    return sqrt(pow((m__x - xTo), 2) + pow((m__y - yTo), 2));
}