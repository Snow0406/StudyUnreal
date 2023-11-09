#include "Queue.h"
#include "Deque.h"
//#include <string>

int main()
{ 
	Queue queue;
	Deque deque;

	//queue.Enqueue(10);
	//queue.Enqueue(20);
	//queue.Enqueue(30);
	//
	//cout << queue.Count() << endl;
	//
	//cout << queue.Dequeue() << endl;
	//
	//cout << queue.Count() << endl;

	deque.Push_Back(10);
	deque.Push_Back(20);
	deque.Push_Front(30);
	
	deque.PrintAll();

	cout << "====================" << endl;
	
	cout << deque.Pop_Front() << endl;

	cout << "====================" << endl;
	
	deque.PrintAll();

	return 0;
}