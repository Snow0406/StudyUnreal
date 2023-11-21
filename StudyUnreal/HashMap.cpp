#include "HashMap.h"

void HashMap::Add(int key, int value)
{
    int hashKey = key % TABLE_SIZE;
    while (table[hashKey] == NULL)
    {
        if (TABLE_SIZE == hashKey + 1) hashKey = 0;
        else hashKey++;
    }
   
    Node* node = new Node();
    node->key = key;
    node->data = value;
    table[hashKey] = node;
}

int HashMap::GetValue(int key)
{
    int hashKey = key % TABLE_SIZE;
    while (table[hashKey]->key == key)
    {
        if (TABLE_SIZE == hashKey + 1) hashKey = 0;
        else hashKey++;
    }
    return table[hashKey]->data;
}

void HashMap::Remove(int key)
{
    int hashKey = key % TABLE_SIZE;
    delete table[hashKey];
    table[hashKey] = NULL;
}

int HashMap::Count()
{
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i]->data) count++;
    }

    return count;
}

void HashMap::Clear()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL) {
            delete table[i];
            table[i] = NULL;
        }
    }
}

HashMap::HashMap()
{
    table = new Node * [TABLE_SIZE];
}

HashMap::~HashMap()
{
}
