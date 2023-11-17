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

	int gap = (num / 2);
	int count = 0;
	
	while (count != 2)
	{
		for (int i = 0; gap + i < num; i++)
		{
			if (pNum[i] > pNum[gap + i]) {
				SWAP(pNum[i], pNum[gap + i]);
				Show(pNum, num);
				for (int j = 1; !pNum[i - (gap * j)]; j++)
				{
					if (pNum[i - (gap * j)] > pNum[i - (gap * (j - 1))]) {
						SWAP(pNum[i - (gap * j)], pNum[i - (gap * (j - 1))]);
						Show(pNum, num);
					}
				}
			}
		}
		gap = (gap + 1) / 2 | 0;

		if (gap == 1) count++;
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