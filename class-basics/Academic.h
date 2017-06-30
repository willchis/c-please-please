#include <iostream>
using namespace std;

class Academic {
	public:
		Academic(string name, string address);
		string getName();
		string getAddress();
	private:
		string name;
		string address;
};