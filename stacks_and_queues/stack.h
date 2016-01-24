#include "Node.h"
#include <iostream>

struct Stack {
	Node top;
	Node pop();
	Node Push(Node);
};