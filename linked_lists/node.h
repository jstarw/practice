#include <iostream>

struct Node {
    int data;
    struct Node * next;
    void print();
    Node();
    Node(int, Node * = NULL);
};