#include <iostream>
using namespace std;

void PassByValue(int theInteger) {
		cout << "PassByValue" << endl;
		theInteger = 999;
	}

void PassByRef(int &theInteger) {
	theInteger = 50;
	cout << "PassByRef: " << theInteger << endl;
}

int main() {
	int num1,
		num2;
	int* pNum = &num2;

	*pNum = 5;

	num1 = 3;

	PassByValue(num1);
	cout << "After PassByValue" << endl;

	cout << "Before PassByRef: " << *pNum << endl;	
	PassByRef(*pNum);
	cout << "After PassByRef: " << *pNum << endl;

	double* pDub = new double();

	*pDub = 666.9;

	cout << *pDub << endl;

	delete pDub;

	cout << *pDub << endl;	

	return 0;
}