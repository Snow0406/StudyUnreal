#include "Stack.h"

template <typename T>
void Stack<T>::Clear()
{
    for (int i = 0; i < MAXCOUNT; i++)
    {
        this->data[i] = -77;
    }
    this->count = 0;
}

template <typename T>
int Stack<T>::Count()
{
    return this->count;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    if (this->count == 0) return true;
    else return false;
}

template <typename T>
bool Stack<T>::Push(T _data)
{
    if (this->count == MAXCOUNT) return false;

    for (int i = 0; i < MAXCOUNT; i++)
    {
        if (this->data[i] == -77) {
            this->count++;
            this->data[i] = _data;
            break;
        }
    }
    return true;
}

template <typename T>
T Stack<T>::Pop()
{
    if (this->IsEmpty()) return -1;

    int index = 0;
    T lastData;  //5
    for (int i = 0; i < MAXCOUNT; i++)
    {
        if (this->data[MAXCOUNT-1-i] != -77) {
            index = MAXCOUNT - 1 - i;
            this->count--;
            break;
        }
    }

    lastData = this->data[index];
    this->data[index] = -77;
    return lastData;
}

template <typename T>
Stack<T>::Stack()
{
    this->data = new T[MAXCOUNT];
    this->count = 0;
    for (int i = 0; i < MAXCOUNT; i++)
    {
        this->data[i] = -77;
    }
}
