#include "student.h"

void Student::OutputIdentity() {
        cout << "I am a student" << endl;
}

void Student::OutputAge() {
    OutputIdentity();
    Person::OutputAge();
}