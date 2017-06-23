#include <iostream>
#include <cmath>
 using namespace std;
 
class Point2d
{
	public:
        Point2d();
        Point2d(double m_x,double m_y);
        ~Point2d(); // destructor
        friend double distanceFrom(Point2d& pointStart, Point2d& pointEnd);
        void print();
		
	private:
        double m_x,  m_y; 

};

double distanceFrom(Point2d& pointStart, Point2d& pointEnd) {
    return sqrt(pow((pointStart.m_x - pointEnd.m_x), 2) + pow((pointStart.m_y - pointEnd.m_y), 2));
}

Point2d::~Point2d()
{
    
}

Point2d::Point2d()
{
    m_x = 0.0;
    m_y = 0.0;
}

Point2d::Point2d(double x, double y)
{

    m_x = x;
    m_y = y;

}

void Point2d::print()
{
	  std::cout << "Point2d(" << m_x << "," << m_y << ");" << std::endl;
}

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    double foo = distanceFrom(first, second);
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
 
    return 0;
}
