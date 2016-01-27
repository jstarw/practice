#include "setofstacks.h"

SetOfStacks::SetOfStacks(int t) {
	T = t;
	count = 0;
	index = 0;

	array.push_back(new Stack());
}

void SetOfStacks::pop() {
	if (index==0) throw new std::exception();
	array[index]->pop();
	count--;
	if (count==0) {
		array.pop_back();
		index--;
	}
}

void SetOfStacks::push(int a) {
	// Node* node = new Node(a);
	if (count > T) {
		array.push_back(new Stack(a));
		index++;
		count = 1;
	} else {
		array[index]->push(a);
	}
}