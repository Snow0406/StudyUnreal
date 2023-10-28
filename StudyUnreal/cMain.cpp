#include <iostream>

using namespace std;

template <typename T>
void ClearData(T a)
{
	cout << sizeof(T) << endl;
	if (a != nullptr)
	{
		delete a;
		a = nullptr;
	}
}

int main()
{
	int* ip = new int;
	float* fp = new float;

	ClearData(ip);
	ClearData(fp);

	cout << "ip : " << ip << endl;
	cout << "fp : " << fp << endl;



	return 0;
}