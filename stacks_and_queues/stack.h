#include "Node.h"
#include <iostream>

struct Stack {
	Node* top;
	void pop();
	void push(int a);
	int peek();
	void print();
	Stack(int);
	Stack();
};