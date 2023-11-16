#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void SelectionSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[10] = { 3,0,1,8,7,2,5,4,9,6 };
	SelectionSort(array, 10);
}

void SelectionSort(int* pArray, int num)
{
	Show(pArray, num);
	
	int newArray[10] = {};
	for (int i = 0; i < 10; i++)
	{
			int mainNum = pArray[i]; //3
			for (int j = i + 1; j < 10; j++) //1 //2 //3
			{
				if (mainNum < pArray[j]) { //3 0 //0 1 //
					continue;
				} else if (mainNum > pArray[j]) { //3 0 //0 1
					SWAP(mainNum, pArray[j]); //0 //0
				}
			}
			newArray[i] = mainNum;
	}
	pArray = newArray;
	  Show(pArray, num);
	}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}