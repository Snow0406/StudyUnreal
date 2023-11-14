#include "ArrayList.h"

int main()
{ 
	SingleList singleList;

	singleList.AddNode(10);
	singleList.AddNode(20);
	singleList.AddNode(30);

	cout << singleList.head->data << endl;
	//cout << singleList.head->next->data << endl;

	return 0;
}