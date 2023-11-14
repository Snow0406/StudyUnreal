#include "ArrayList.h"

int main()
{
	SingleList singleList;

	singleList.AddNode(10);
	singleList.AddNode(20);
	singleList.AddNode(30);
	singleList.AddNode(40);
	singleList.AddNode(50);

	singleList.InsertNode(2, 77);

	singleList.UpdateNode(3, 33);
	singleList.UpdateNode(4, 44);

	singleList.DeleteNodeData(77);
	singleList.DeleteIndex(2);

	singleList.PrintAll();

	cout << "================" << endl;

	cout << singleList.GetNodeData(1) << endl;
	singleList.ClearAllNode();

	cout << "================" << endl;

	cout << singleList.GetListSize() << endl;

	return 0;
}