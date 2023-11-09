#pragma once
#include <iostream>

#define MAXCOUNT 5

using namespace std;

class Deque
{
private:
	int* data;
	int count;
public:
	//뒤로 값을 추가
	void Push_Back(int num);
	//앞으로 값을 추가
	void Push_Front(int num);
	//뒤에 있는 데이터 배출
	int Pop_Back();
	//앞에 있는 데이터 배출
	int Pop_Front();
	//값이 있는지 없는지 확인
	bool isEmpty();
	//전체 데이터 삭제
	void Clear();
	//들어가 있는 갯수 반환
	int Count();
public:
	//전체 자료 출력
	void PrintAll();
public:
	Deque();
};


