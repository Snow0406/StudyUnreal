#pragma once
#include <iostream>

using namespace std;

#define MAXCOUNT 5

template <typename T>
class Stack
{
private:
	T* data; //[-77][-77][-77][-77][-77][-77][-77]
	int count; //[1][2][3][-77][-77][-77] -> 3
public:
	void Clear(); //자료를 지워주는
	int  Count(); //자료가 몇개인지
	bool IsEmpty(); //자료가 비워있는지 확인

	bool Push(T _data); //값 넣어주는(데이터). 들어가면 true
	T  Pop(); //값을 빼주는, 빼주는 값을 반환, 뺄 것이 없으면 -1 반환
public:
	Stack();
};

