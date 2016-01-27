#include "node.h"

using namespace std;

void Node::print() {
    cout << data << "->";
    if (!next) {
        cout << "NULL" << endl;
    } else {
        next->print();
    }
}

Node::Node() {
	data = NULL;
	next = NULL;
}

Node::Node(int a, Node *b) {
    data = a;
    next = b;
}