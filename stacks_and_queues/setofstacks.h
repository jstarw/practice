#include "stack.h"
#include <vector>

struct SetOfStacks {
	int count;
	int index;
	int T;
	std::vector<Stack*> array;
	void pop();
	void push(int);
	SetOfStacks(int);
};