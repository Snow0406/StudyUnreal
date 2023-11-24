#pragma once
#include "Node.h"

class Queue
{
public:
	Node* head;
	Node* tail;
	int count;
public:
	//자료 입력
	void Push(int _data);
	//자료 출력
	int Pop();
	//첫번째 자료값 확인
	int Front();
	//마지막 자료값 환인
	int Back();
	//크기 확인
	int Count();
	//모든 데이터 지우기
	void Clear();
	//자료가 비었는지 확인
	bool IsEmpty();
	//모든 자료 출력
	void PrintAll();

public:
	Queue();
	~Queue();
};