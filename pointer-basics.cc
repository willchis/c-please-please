#include <iostream>
    
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

    return 0;
}

void incrementByReference(int &toBeIncremented) {
    toBeIncremented++;
}
