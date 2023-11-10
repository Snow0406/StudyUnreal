#include "ArrayList.h"

int main()
{ 
	ArrayList arrayList;

	arrayList.AddNode(10);
	arrayList.AddNode(20);
	arrayList.AddNode(30);
	arrayList.AddNode(40);
	arrayList.InsertNode(2, 77);
	arrayList.InsertNode(0, 2, 88);

	arrayList.DeleteNodeData(10);
	arrayList.DeleteIndex(0);

	arrayList.UpdateNode(3, 99);

	arrayList.PrintAll();

	return 0;
}