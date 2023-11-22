#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree tree;

    tree.AddNode(30);
    tree.AddNode(20);
    tree.AddNode(10);
    tree.AddNode(15);

    tree.PrintAll();
    tree.RemoveNode(20);
    cout << "====================" << endl;

    tree.PrintAll();
    
    return 0;
}