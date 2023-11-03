#include <iostream>

using namespace std;

typedef int(*A)(int, int);
using B = int(*)(int, int);

int Add(int a, int b) { return a + b; }

int main()
{
	A p = Add;
	B pp = Add;

	cout << p(1, 2) << endl;
	cout << p(2, 4) << endl;


	return 0;
}