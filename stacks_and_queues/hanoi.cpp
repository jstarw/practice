#include <iostream>
#include "stack.h"

using namespace std;

void moveTopTo(Stack*& origin, Stack*& dest) {
	dest->push(origin->peek());
	origin->pop();
	// origin->print();
	// dest->print();
}

void moveDisks(int n, Stack*& origin, Stack*& dest, Stack*& buffer) {
	//move n-1 disks using s3 as buffer to s2
	//move n disk (bottom) to s3
	//move n-1 disks using s1 as buffer to s3
	if (n>0) {
		moveDisks(n-1, origin, buffer, dest);
		moveTopTo(origin, dest);
		moveDisks(n-1, buffer, dest, origin);
	}
}

int main(int argc, char const *argv[])
{
	Stack* s1 = new Stack(4);
	Stack* s2 = new Stack();
	Stack* s3 = new Stack();
	// s1->print();
	s1->push(3);
	s1->push(2);
	s1->push(1);
	// s1->print();
	moveDisks(4, s1, s3, s2);
	s1->print();
	s2->print();
	s3->print();
}