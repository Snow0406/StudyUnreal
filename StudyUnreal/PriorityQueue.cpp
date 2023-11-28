#include "PriorityQueue.h"

bool PriorityQueue::IsEmpty()
{
    return (count == 0 ? true : false);
}

void PriorityQueue::Push(int _priority, int _data)
{

}

Node PriorityQueue::Pop()
{
    return Node();
}

int PriorityQueue::Count()
{
    return count;
}

int PriorityQueue::GetChildIndex(int selfIndex)
{
    return 0;
}

int PriorityQueue::GetParentIndex(int selfIndex)
{
    return 0;
}

int PriorityQueue::GetLeftChildIndex(int selfIndex)
{
    return 0;
}

int PriorityQueue::GetRightChildIndex(int selfIndex)
{
    return 0;
}

void PriorityQueue::Swap(int firstIndex, int secondIndex)
{
    Node temp = heap[firstIndex];
    temp = heap[firstIndex];
    heap[firstIndex] = heap[secondIndex];
    heap[secondIndex] = temp;
}

PriorityQueue::PriorityQueue()
{
    count = 0;
}
