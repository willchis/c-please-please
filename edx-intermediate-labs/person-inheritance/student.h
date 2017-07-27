#include "person.h"
using namespace std;

class Student : public Person {
    public:
        virtual void OutputIdentity();
        virtual void OutputAge();
};
