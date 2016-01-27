#include "stack.h"

using namespace std;

Stack::Stack() {
	top = NULL;
}

Stack::Stack(int a) {
	top = new Node(a);
}

void Stack::pop() {
	if (top == NULL) {
		throw new exception();
	}
	top->remove(top);
}

void Stack::push(int a) {
	Node* node = new Node(a);
	node->next = top;
	top = node;
}

int Stack::peek() {
	return top->data;
}

void Stack::print() {
	top->print();
}