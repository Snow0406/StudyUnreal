#include "Deque.h"

void Deque::Push_Back(int num)
{
    if (count >= MAXCOUNT) return;
    data[count] = num;
    count++;
}

void Deque::Push_Front(int num)
{
    if (count >= MAXCOUNT) return;

    int lastData[MAXCOUNT] = {};
    for (int i = 0; i < MAXCOUNT; i++) lastData[i] = data[i];

    //[0,1,2,3,4]    //1,2,3,4
    for (int i = 0; i < MAXCOUNT; i++)
    { 
        if (i + 1 < MAXCOUNT) data[i + 1] = lastData[i];
        else break;
    }

    //delete lastData;
    data[0] = num;
    count++;
}

int Deque::Pop_Back()
{
    if (count == 0) return -1;

    int num = data[count - 1];
    data[count - 1] = -77;
    count--;
    return num;
}

int Deque::Pop_Front()
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

bool Deque::isEmpty()
{
    if (count == 0) return true;
    else return false;
}

void Deque::Clear()
{
    for (int i = 0; i < MAXCOUNT; i++)
    {
        data[i] = -77;
    }
    count = 0;
}

int Deque::Count()
{
    return count;
}

void Deque::PrintAll()
{
    for (int i = 0; i < MAXCOUNT; i++)
    {
        cout << data[i] << endl;
    }
}

Deque::Deque()
{
    data = new int[MAXCOUNT];
    count = 0;

    for (int i = 0; i < MAXCOUNT; i++)
    {
        data[i] = -77;
    }
}
