#include "Queue.h"

void Queue::Clear()
{
    for (int i = 0; i < MAXCOUNT; i++)
    {
        data[i] = -77;
    }
    count = 0;
}

int Queue::Count()
{
    return count;
}

bool Queue::IsEmpty()
{
    if (count == 0) return true;
    else return false;
}

void Queue::Enqueue(int _data)
{
    if (count >= MAXCOUNT) return;
    data[count] = _data;
    count++;
}

int Queue::Dequeue()
{
    if (count == 0) return -1;

    int num = data[0];
    data[0] = -77;
    count--;
    
    for (int i = 0; i < MAXCOUNT; i++)
    {
        if (i + 1 < MAXCOUNT) data[i] = data[i + 1];
        else data[i] = -77;
    }
    return num;
}

Queue::Queue()
{
    data = new int[MAXCOUNT];
    count = 0;

    for (int i = 0; i < MAXCOUNT; i++)
    {
        data[i] = -77;
    }
}
