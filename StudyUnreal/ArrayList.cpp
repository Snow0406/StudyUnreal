#include "ArrayList.h"

void ArrayList::AddNode(int _data)
{
	count++; //3
	int* temp = new int[count];

	if (!IsEmpty()) {
		//0, 1
		for (int i = 0; i < count - 1; i++)
		{
			temp[i] = data[i];
		}

		delete data;
	}

	temp[count - 1] = _data;
	data = temp;
}

void ArrayList::InsertNode(int _index, int _data)
{
	count++; //5
	int* temp = new int[count];

	if (!IsEmpty()) {
		//0, 1, 2(Push), 3, 4
		bool isPush = false;
		for (int i = 0; i < count; i++)
		{
			if (i != _index && !isPush) temp[i] = data[i];
			else if (i == _index) {
				temp[i] = _data;
				isPush = true;
			}
			else temp[i] = data[i - 1];
		}

		delete data;
	}
	else temp[count - 1] = _data;

	data = temp;
}

void ArrayList::InsertNode(int _index, int _count, int _data)
{
	if (_count == 0) _count = 1;
	count += _count;
	int* temp = new int[count];

	if (!IsEmpty()) {
		//0, 1, 2(index & Push), 3(Push), 4, 5
		bool isPush = false;
		for (int i = 0; i < count; i++)
		{
			if (i != _index && !isPush) temp[i] = data[i]; //0, 1
			else if (i >= _index && i < _index + _count) {
				temp[i] = _data; 
				isPush = true;
			}
			else temp[i] = data[i - _count];
		}

		delete data;
	}
	else {
		for (int i = 0; i < count; i++)
		{
			temp[i] = _data;
		}
	}

	data = temp;
}

void ArrayList::UpdateNode(int _index, int _data)
{
	data[_index] = _data;
}

void ArrayList::DeleteNodeData(int _data)
{
	if (IsEmpty()) return;

	count--;
	int* temp = new int[count];

	bool isPush = false;
	for (int i = 0; i < count+1; i++)
	{
		if (data[i] != _data && !isPush) temp[i] = data[i];
		else if (data[i] == _data) {
			isPush = true;
			continue;
		} else temp[i-1] = data[i];
	}

	delete data;
	data = temp;
}

void ArrayList::DeleteIndex(int _index)
{
	if (IsEmpty()) return;

	count--;
	int* temp = new int[count];

	bool isPush = false;
	for (int i = 0; i < count + 1; i++)
	{
		if (i != _index && !isPush) temp[i] = data[i];
		else if (i == _index) {
			isPush = true;
			continue;
		}
		else temp[i - 1] = data[i];
	}

	delete data;
	data = temp;
}

void ArrayList::ClearAllNode()
{
	if (!IsEmpty()) {
		delete data;
		data = NULL;
		count = 0;
	}
}

int ArrayList::GetNodeData(int _index)
{
	return data[_index];
}

int ArrayList::GetListSize()
{
	return count;
}

bool ArrayList::IsEmpty()
{
	if (data == NULL) return true;
	else return false;
}

void ArrayList::PrintAll()
{
	for (int i = 0; i < count; i++)
	{
		cout << data[i] << endl;
	}
}

ArrayList::ArrayList()
{
	data = NULL;
	count = 0;
}

ArrayList::~ArrayList()
{
	ClearAllNode();
}
