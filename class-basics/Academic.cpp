#include <iostream>
#include "Academic.h"

Academic::Academic(string nameNew, string addressNew) : name(nameNew), address(addressNew) { }

string Academic::getName() {
	return name;
}

string Academic::getAddress() {
	return address;
}

void Academic::SitInClass() {
	cout << "Sitting SOMEWHERE in class" << endl;
}