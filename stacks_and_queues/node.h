#include <iostream>

struct Node {
    int data;
    struct Node * next;
    void print();
    Node(int, Node * = NULL);
};