#pragma once
#include <iostream>

#define MAXCOUNT 5

using namespace std;

class Queue
{
public:
	//Queue를 가르키는 포인터
	int* data;
private:
	//데이터 갯수
	int count;
public:
	//자료를 지워주는 아이
	void Clear();
	//몇개인지 알려주는 아이
	int Count();
	//비어 있는지 알려주는 아이
	bool IsEmpty();
	//값을 넣어주는(int num) 
	void Enqueue(int _data);
	//값을 빼주는 아이
	int Dequeue();
public:
	Queue();
};