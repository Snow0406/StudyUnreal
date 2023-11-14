#include "ArrayList.h"

void SingleList::AddNode(int _data)
{
	if (IsEmpty()) { //count 0
		Node node;
		node.data = _data; //10
		node.next = NULL;
		head = &node;
	}
	else {
		Node* temp = head;
		//if (temp->next != NULL) { //count 2 ÀÌ»ף
		//	Node* node = new Node();
		//
		//	node->data = _data;
		//	node->next = NULL;
		//	temp = temp->next;
		//}
		else { //count 1
			Node node1;
			node1.data = _data; //2
			node1.next = NULL;
			temp->next = &node1;
		}
	}
}
void SingleList::InsertNode(int _index, int _data)
{
}

void SingleList::UpdateNode(int _index, int _data)
{
}

void SingleList::DeleteNodeData(int _data)
{
}

void SingleList::DeleteIndex(int _index)
{
}

void SingleList::ClearAllNode()
{
}

int SingleList::GetNodeData(int _index)
{
	return 0;
}

int SingleList::GetListSize()
{
	return count;
}

bool SingleList::IsEmpty()
{
	if (count == 0) return true;
	else return false;
}

void SingleList::PrintAll()
{
}

SingleList::SingleList()
{
	count = 0;
	head = NULL;
}

SingleList::~SingleList()
{
}
