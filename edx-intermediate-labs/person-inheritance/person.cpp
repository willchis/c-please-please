#include <iostream>
#include "person.h"
using namespace std;

void Person::OutputAge() {
    cout << "I am " << age << " years old" << endl;
}

void Person::SetAge(int inputAge) {
    age = inputAge;
}