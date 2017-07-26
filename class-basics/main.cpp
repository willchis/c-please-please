#include <iostream>
#include "Student.h"
#include "Teacher.h"
 
int main()
{
	Student littleBobby("Robert", "7 Windsor Place.");
	Teacher aLecturer("Niels Bohr", "Cambridge University");

	cout << aLecturer.getName() << endl;
	cout << littleBobby.getName() << endl;

	aLecturer.SitInClass();

    //Point2d first;
    //Point2d second(3.0, 4.0);
    //first.print();
    //second.print();
 
    return 0;
}
