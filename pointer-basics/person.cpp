#include "person.h"

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
