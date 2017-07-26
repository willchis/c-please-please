#include "Student.h"

Student::Student(string nameNew, string addressNew): Academic(nameNew, addressNew) { 
}

void Student::SitInClass() {
	cout << "Sitting in main theatre" << endl;
}

