#ifndef ACADEMIC_H
#define ACADEMIC_H

#include <iostream>
using namespace std;

class Academic {
	public:
		Academic(string name, string address);
		string getName();
		string getAddress();
		virtual void SitInClass();
	private:
		string name;
		string address;
};
#endif