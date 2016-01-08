#include "node.h"
#include <iostream>

using namespace std;



bool isCircular (Node * head) {
	Node * turtle = head;
	Node * rabbit = head;
	while (rabbit->next != NULL) {
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit) {
			return true;
			break;
		}
	}
	return false;
}

int circleBegins (Node * head) {
	bool circular = false;
	Node * turtle = head;
	Node * rabbit = head;
	while (rabbit->next != NULL) {
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit) {
			circular = true;
			break;
		}
	}
	if (!circular) return 0;
	turtle = head;
	while (rabbit != turtle) {
		rabbit = rabbit->next;
		turtle = turtle->next;
	}
	return rabbit->data;
}

int main(int argc, char const *argv[])
{
    Node * head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
    head->next->next->next->next->next = head->next->next;
    bool circular = isCircular(head);
    cout << circular << endl;
    cout << circleBegins(head) << endl;
    return 0;
}