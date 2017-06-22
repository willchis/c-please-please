#include <iostream>
#include "Point2d.h"
using namespace std;

Point2d::Point2d(double x, double y) {
    m__x = x;
    m__y = y;
}

void Point2d::print() {
    cout << "Point2d(" << m__x << "," << m__y << ");" << endl;
}