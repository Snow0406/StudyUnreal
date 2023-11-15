#include <iostream>
using namespace std;

//#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}
#define MAX 10

void BubbleSort(int* pNum, int num);
void Show(int* pArray, int num);

void main()
{
	int array[MAX] = { 3,0,1,8,7,2,5,4,6,9 };
	BubbleSort(array, MAX);
	BubbleSort(array, MAX);
}

void BubbleSort(int* pArray, int num)
{
	Show(pArray, num);

	int isEnd = 0;
	while (true)
	{
		for (int i = 0; i < MAX - 1; i++)
		{
			int num;
			if (pArray[i] < pArray[i + 1]) { //ex: 2 4
				isEnd++;
			}
			else if (pArray[i] > pArray[i + 1]) { //ex: 4 2
				num = pArray[i];
				pArray[i] = pArray[i + 1];
				pArray[i + 1] = num;
			} else { //ex: 2 2
				isEnd++;
			}
		}

		if (isEnd == MAX - 1) {
			Show(pArray, num);
			break;
		} else isEnd = 0;
	}
}

void Show(int* pArray, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << pArray[i] << " ";
	}

	cout << endl;
}