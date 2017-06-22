#include <iostream>
using namespace std;
 
class Point2d {
    public:
        Point2d(double x = 0.0, double y = 0.0);
        void print();
    private:
        double m__x;
        double m__y;
};

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
 
    return 0;
}

Point2d::Point2d(double x, double y) {
    m__x = x;
    m__y = y;
}

void Point2d::print() {
    cout << "Point2d(" << m__x << "," << m__y << ");" << endl;
}
