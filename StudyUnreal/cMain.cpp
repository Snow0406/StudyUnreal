#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {
    
    HashMap hashMap;

    hashMap.Add(10, 11);
    hashMap.Add(20, 22);

    hashMap.Add(99, 9);
    hashMap.Add(89, 99);
    hashMap.Add(79, 999);

    hashMap.PrintALL();
   
    cout << hashMap.Count() << endl;
    cout << hashMap.GetValue(89) << endl;
    hashMap.Remove(89);

    hashMap.PrintALL();

    return 0;
}