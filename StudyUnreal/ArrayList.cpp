#include "ArrayList.h"

void SingleList::AddNode(int _data)
{
	Node* node = new Node();
	count++;

	node->data = _data;
	node->next = NULL;

	if (head == NULL) {
		head = node;
	}
	else {
		Node* temp = head;
		while (true)
		{
			if (temp->next != NULL) temp = temp->next;
			else {
				temp->next = node;
				//delete temp;
				break;
			}
		}
	}
}
void SingleList::InsertNode(int _index, int _data)
{
	if (IsEmpty() || count+1 < _index) {
		AddNode(_data);
		return;
	}

	Node* node = new Node();
	node->data = _data;
	node->next = NULL;

	if (_index == 0) { //0번째일때
		node->next = head;
		head = node;
	}

	Node* tempNode = head;
	int index = 0;

	while (true)
	{
		if (index == _index - 1) { //frontNode
			node->next = tempNode->next;
			tempNode->next = node;
			break;
		}
		index++;
		tempNode = tempNode->next;
	}

	count++;
}

void SingleList::UpdateNode(int _index, int _data)
{
	if (IsEmpty() || count < _index) return;

	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		if (i == _index) {
			temp->data = _data;
			break;
		}
		temp = temp->next;
	}
}

void SingleList::DeleteNodeData(int _data)
{
	if (IsEmpty()) return;

	Node* temp = head;
	Node* past = head;
	while (past != NULL)
	{
		if (temp->data == _data) {
			past->next = temp->next;
			break;
		}
		else {
			past = temp;
			temp = temp->next;
		}
	}

	if (past == NULL) return
	delete temp;
	count--;
}

void SingleList::DeleteIndex(int _index)
{
	if (IsEmpty() || count < _index) return;

	Node* temp = head;
	Node* past = head;
	int index = 0;

	while (past != NULL)
	{
		if (index == _index) {
			past->next = temp->next;
			break;
		}
		else {
			past = temp;
			temp = temp->next;
			index++;
		}
	}
	delete temp;
	count--;
}

void SingleList::ClearAllNode()
{
	Node* temp = head;
	Node* past = head;

	while (true)
	{
		if (temp->next != NULL) {
			past = temp;
			temp = temp->next;
			delete past;
		}
		else {
			break;
		}
	}

	head = NULL;
	count = 0;
}

int SingleList::GetNodeData(int _index)
{
	if (IsEmpty() || count < _index) return -1;

	Node* temp = head;
	int index = 0;
	int res = 0;

	while (true)
	{
		if (index == _index) {
			res = temp->data;
			break;
		}
		else {
			temp = temp->next;
			index++;
		}
	}
	return res;
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
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

SingleList::SingleList()
{
	count = 0;
	head = NULL;
}

SingleList::~SingleList()
{
}
