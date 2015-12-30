#include "node.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "hello world"<<endl;
    Node * head = new Node(1, new Node(2, new Node(3)));
    head->print();
    return 0;
}