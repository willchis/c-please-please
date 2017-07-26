#include <iostream>
using namespace std;

class Person {
	private:
		int age;
	public:
		string first_name;
		string last_name;
		virtual void OutputIdentity() {}
		void OutputAge();
	protected:
		string phone;
};