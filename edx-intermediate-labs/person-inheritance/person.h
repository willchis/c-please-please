#include <iostream>
using namespace std;

class Person {
	private:
		int age;
	public:
		string first_name;
		string last_name;
		void SetAge(int inputAge);
		virtual void OutputIdentity() {};
		virtual void OutputAge();
	protected:
		string phone;
};