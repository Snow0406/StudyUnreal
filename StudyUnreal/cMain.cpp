#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {
    
    HashMap hashMap;

    hashMap.Add(10, 11);
    hashMap.Add(20, 111);
    hashMap.Add(30, 1111);
    hashMap.Add(21, 22);

    cout << hashMap.Count() << endl;

    cout << hashMap.GetValue(40) << endl;

    return 0;
}