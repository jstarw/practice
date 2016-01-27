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
	next = NULL;
}

Node::Node(int a, Node *b) {
    data = a;
    next = b;
}

void Node::insert(Node* a) {
	
}

void Node::remove(Node* a) {

}