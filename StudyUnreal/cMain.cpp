#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void ShellSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	ShellSort(array, 10);
}

void ShellSort(int* pNum, int num)
{
	Show(pNum, num);

	int gap = (10 / 2);
	for (int i = 0; gap > 2; i++)
	{
		for (int j = 0; j < gap; j++)
		{
				for (int k = 0; j + gap; k++)
				{
					if (pNum[j] > pNum[j + gap]) {
						SWAP(pNum[j + gap], pNum[j]);
					}
				}
		}
		gap = (gap + 1) / 2;
	}
	Show(pNum, num);
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}