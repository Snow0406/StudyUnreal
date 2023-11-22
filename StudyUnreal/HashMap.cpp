#include "HashMap.h"

void HashMap::Add(int key, int value)
{
    int hashKey = key % TABLE_SIZE;
    while(true)
    {
        if (table[hashKey] == NULL) break;

        if (hashKey == TABLE_SIZE - 1) hashKey = 0;
        hashKey++;
    }
   
    Node* newNode = new Node{key, value};
    table[hashKey] = newNode;
}

int HashMap::GetValue(int key)
{
    int hashKey = key % TABLE_SIZE;
    while (true)
    {
        if (table[hashKey]->key == key) break;
        if (hashKey == TABLE_SIZE - 1) hashKey = 0;
        hashKey++;
    }
    return table[hashKey]->data;
}

void HashMap::Remove(int key)
{
    int hashKey = key % TABLE_SIZE;
    while (true)
    {
        if (table[hashKey]->key == key) break;
        if (hashKey == TABLE_SIZE - 1) hashKey = 0;
        hashKey++;
    }
    delete table[hashKey];
    table[hashKey] = NULL;
}

int HashMap::Count()
{
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL) count++;
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

void HashMap::PrintALL()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL) {
            cout << "[" << i << "] " << "[key:" << table[i]->key << ", data:" << table[i]->data << "]" << endl;
        } else cout << "[" << i << "] " << "[NULL]" << endl;
    }
}

HashMap::HashMap()
{
    table = new Node * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}

HashMap::~HashMap()
{
}
