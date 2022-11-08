#include "person.h"
#include <iostream>
using namespace std;

Person::Person() {};

Person::~Person() {
	cout << "Destructor called." << endl;
};

void Person::setName(string newName) {
	name = newName;
};

string Person::getName() {
	return name;
};
