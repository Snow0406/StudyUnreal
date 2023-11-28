#pragma once
#include <iostream>

using namespace std;

#define MaxCount 100

struct Node
{
	int priority;
	int data;
};

class PriorityQueue
{
private:
	Node heap[MaxCount];
	int count;
public:
	//비어있는지 알려주는 아이
	bool IsEmpty();
	//값을 추가(우선순위, 값)
	void Push(int _priority, int _data);
	//우선순위가 높은 Node 반환
	Node Pop();
	int Count();
private:
	//우선수위 높은 자식의 index를 반환
	int GetChildIndex(int selfIndex);
	//부모의 index
	int GetParentIndex(int selfIndex);
	//왼쪽 자식의 index
	int GetLeftChildIndex(int selfIndex);
	//오른쪽 자식의 index
	int GetRightChildIndex(int selfIndex);
	//값 서로 바꿈
	void Swap(int firstIndex, int secondIndex);
public:
	PriorityQueue();
	~PriorityQueue() {}
};


