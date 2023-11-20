#pragma once
#include <iostream>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

class BinaryTree
{
public:
	Node* rootNode;
public: // 외부에서 호출 용도
	//노드 추가
	void AddNode(int data);
	//노드 삭제
	void RemoveNode(int data);
	//모든 노드 출력
	void PrintAll();
private: // 내부 구현 용도 (재귀)
	//노드 생산
	Node* CreateNode(int data);
	//노드 삽입
	void InsertNode(Node* tree, Node* newNode);
	//노드 삭제
	//Node* DeleteNode(Node* tree, int data);
	//최저값 찾기
	Node* FindMin(Node* root);
	//최대값 찾기
	Node* FindMax(Node* root);
	//적은값 부터 호출
	void InOrder(Node* root);
public:
	BinaryTree();
	~BinaryTree();
};