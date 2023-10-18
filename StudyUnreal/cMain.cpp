#include <iostream>

using namespace std;

class Cat
{
public:
	static int age;
};

int Cat::age = 0;

int main()
{
	Cat a;
	a.age = 2;

	cout << a.age << endl;

	return 0;
}