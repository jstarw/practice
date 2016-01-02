#include "node.h"
#include <iostream>

using namespace std;

/*
   1) Divide the list in two parts - first node and rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
   4) Fix head pointer
*/
void reverseRecursive (Node *& head) {
	if (head == NULL) return;
	Node * first = head;
	Node * rest = head->next;
	if (rest == NULL) return;
	reverseRecursive(rest);
	cout<<first->data<< " "<<rest->data<<endl;
	first->next->next = first;
	first->next = NULL;
	head = rest;
}

void reverseIterative (Node * head) {
	Node * current = head;
	Node * previous = NULL;
	Node * next = head;
	while (next) {
		next = next->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	current = previous;
	current->print();
}

int main(int argc, char const *argv[])
{
    Node * head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	head->print();
    reverseRecursive(head);
    head->print();
    return 0;
}