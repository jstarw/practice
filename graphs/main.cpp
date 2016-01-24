#include "graph.h"
#include <iostream>

using namespace std;

Node* getNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int v) {
	Graph* graph = new Graph();
	graph->v = v;
	graph->array = new AdjList[v];

	for (int i=0; i<v; i++) {
		graph->array[i].head = NULL;
	}
	return graph;
}

Graph* addEdge(Graph* graph, int src, int dest) {
	if (src<0 || dest<0 || src>graph->v || dest>graph->v) {
		cout<<"Error."<<endl;
		return graph;
	}
	Node* newNode = getNewNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	
	newNode = getNewNode(src);
	graph->array[dest].head = newNode;
	return graph;
}

void print(Graph* graph) {
    for (int v = 0; v < graph->v; ++v)
    {
        Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
	Graph* graph = createGraph(5);
	graph = addEdge(graph, 4, 1);
	print(graph);
}