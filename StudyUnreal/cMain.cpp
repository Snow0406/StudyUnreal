#include <iostream>

using namespace std;

class Animal
{
public:
	Animal() { cout << "Animal 持失" << endl; }
	Animal(int& a)
	{
		a = 33;
		cout << "Animal : " << a << endl;
	}
	~Animal() { cout << "Animal 社瑚" << endl; }
};

class Dog : public Animal
{
public:
	Dog() { cout << "Dog 持失" << endl; }
	Dog(int& a)
	{
		//a?
		cout << "Dog : " << a << endl;
	}
	~Dog() { cout << "Dog 社瑚" << endl; }
};

int main()
{
	int a = 12;
	Dog dog(a);

	return 0;
}