#pragma once
#include <iostream>

using namespace std;

class ArrayList
{
public:
	int* data;
	int count;
public:
	//추가
	void AddNode(int _data);
	//값 삽입(순서 == _index)
	void InsertNode(int _index, int _data);
	//값 삽입(순서 == _index, 갯수 == _count)
	void InsertNode(int _index, int _count, int _data);
	//데이터 변경(순서 == _index)
	void UpdateNode(int _index, int _data);
	//값 제거(값 == _data)
	void DeleteNodeData(int _data);
	//값 제거(순서 == _index)
	void DeleteIndex(int _index);
	//모든 값 삭제
	void ClearAllNode();
	//원하는 값의 정보 불러오기(순서 == _index)
	int GetNodeData(int _index);
	//현재 List크기
	int GetListSize();
	//현재 데이터가 비어 있는지 아닌지
	bool IsEmpty();
	//모든 node 출력
	void PrintAll();
public:
	ArrayList();
	~ArrayList();
};

