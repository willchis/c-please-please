using namespace std;

class Person {
	public:
		Person();
		~Person();
		string getName();
		void setName(string name);
	private:
		string name;
};