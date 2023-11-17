#include <iostream>
using namespace std;

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}
#define MAX 10

void QuickSort(int* pNum, int left, int right);
void Show(int* pArray, int num, int type);

void main()
{
	int array[MAX] = { 3,0,1,8,7,2,5,4,9,6 };
	QuickSort(array, 0, 9);
}

void QuickSort(int* pNum, int left, int right)
{
	Show(pNum, MAX, 0);

	int newArray[10] = {};
	int i = 0;
		//int mainNum = pNum[i];
		for (int j = 1; j < MAX; j++) //1
		{
			if (pNum[i] > pNum[MAX - j]) {
				SWAP(pNum[i], pNum[MAX - j]);
				Show(pNum, MAX, 1);

				for (int k = 0; k < MAX - j; k++) //2
				{
					if (pNum[MAX - j] < pNum[k]) {
						int mainIndex = 0;
						SWAP(pNum[MAX - j], pNum[k]);
						mainIndex = k;
						Show(pNum, MAX, 2);
						if (pNum[k] > pNum[k + 1])
						{
							SWAP(pNum[k], pNum[k + 1]);
							Show(pNum, MAX, 2.5);
							mainIndex = k + 1;
						}
						for (int n = 0; n < mainIndex; n++) //3
						{
							if (pNum[n] > pNum[mainIndex-1])
							{
								SWAP(pNum[n], pNum[mainIndex - 1]);
								for (int m = n+1; m < mainIndex - 1; m++)
								{
									if (pNum[m] > pNum[mainIndex - 1])
									{
										SWAP(pNum[m], pNum[mainIndex - 1]);
									}
								}
							}
						}
						for (int l = 0; l < MAX; l++) //4
						{
							if (pNum[mainIndex + 1] > pNum[MAX - l])
							{
								SWAP(pNum[mainIndex + 1], pNum[MAX - l]);
								for (int m = l + 1; m < mainIndex - 1; m++)
								{
									if (pNum[m] > pNum[mainIndex - 1])
									{
										SWAP(pNum[m], pNum[mainIndex - 1]);
									}
								}
							}
						}
					}
				}
			}
		}
		//Show(newArray, MAX);
}

void Show(int* pArray, int num, int type)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << " [" << type << "]" << endl;
}