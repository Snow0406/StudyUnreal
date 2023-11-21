#pragma once
#include <iostream>

using namespace std;

#define TABLE_SIZE 10

struct  Node
{
	int key;
	int data;
};

class HashMap
{
private:
	Node** table;
public:
	void Add(int key, int value);
	int GetValue(int key);
	void Remove(int key);
	int Count();
	void Clear();
public:
	HashMap();
	~HashMap();
};	