#include "Teacher.h"

Teacher::Teacher(string name, string address): Academic(name, address) {	
}

void Teacher::GradeStudent() {
	cout << "Grading student now..." << endl;
}

void Teacher::SitInClass() {
	cout << "Sitting at front of class" << endl;
}