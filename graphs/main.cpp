#include "graph.h"
#include <iostream>
#include <list>

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

void BFS(Graph* graph, int s) {
	list<int> queue;
	bool* visited = new bool[graph->v];

	queue.push_back(s);
	visited[s] = true;
	int i;

	while (!queue.empty()) {
		s = queue.front();
		cout<< s << " ";
		queue.pop_front();
		for (i = graph->array[s].front(); i = graph->array[s].back(); i++) {
			if (!visited[i]) {
				visited[i] = true;
				queue.push_back(i);
			}
		}
	}
	delete [] visited;
}

void DFSRecurse(Graph* graph, bool visited[], int s) {
	visited[s] = true;
	
}

void DFS(Graph*graph, int s) {
	bool* visited = new bool[graph->v];

	for (int i=0; i<graph->v; i++) visited[i] = false;

	DFSRecurse(Graph* graph, visited, s);
}

int main() {
	Graph* graph = createGraph(5);
	graph = addEdge(graph, 4, 1);
	graph = addEdge(graph, 3, 0);
	graph = addEdge(graph, 2, 1);
	graph = addEdge(graph, 2, 4);
	graph = addEdge(graph, 4, 3);
	print(graph);
}