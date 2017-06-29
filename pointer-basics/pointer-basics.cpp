#include <iostream>
#include "person.cpp"
    
using namespace std;

void incrementByReference(int &);

int main()
{

    int num = 3;
    int *pNum = &num;

    cout << *pNum << endl;
    
    *pNum = 4;
    
    cout << *pNum << endl;
    
    incrementByReference(*pNum);
    
    cout << *pNum << endl;

    Person *person = new Person();
    person->setName("Foo");

    cout << "We have a pointer to a person, with address: " << &person << endl;

    cout << "The name is: " << person->getName() << endl;

    *person = Person(); // reassign a new person to the old value
    cout << "The new name is: " << person->getName() << endl;

    delete person;



    int x = 1, y = 2;

    cout << "y used to be: " << y << endl;

    int *ip; // declares *ip as a pointer to an int type

    ip = &x; // assigns the address of x to ip

    y = *ip; // y is now 1 via dereferencing
    cout << "y is now: " << y << endl;

    return 0;
}

void incrementByReference(int &toBeIncremented) {
    toBeIncremented++;
}
