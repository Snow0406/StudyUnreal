#include <iostream>

using namespace std;

class Obj
{
public:
	int x;
	int y;
public:
	//반환형 operator연산자(매개변수들)
	//{}
	//void operator+(const Obj& other)
	//{
	//	cout << "In" << endl;
	//}
};

//반환형 operator연산자(매개변수들)
void operator+(const Obj& a, const Obj& b)
{
	cout << "Out" << endl;
}

int main()
{
	Obj a;
	a.x = 1;
	a.y = 1;

	Obj b;
	b.x = 2;
	b.y = 2;

	a + b;
	//a.operator+(b);


	return 0;
}