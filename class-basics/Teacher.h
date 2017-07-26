#include "Academic.h"

class Teacher: public Academic {
	public:
		Teacher(string name, string address);
		void GradeStudent();
		void SitInClass();
};
