#include <iostream>

using namespace std;

class MinHeap {
	int *arr;
	int capacity;
	int heapSize;
public:
	MinHeap(int);
	void minHeapify(int i);
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i+2; }
	int getMin() { return arr[0]; }
	void swap(int* a, int* b);
	void print();

	int deleteMin();
	int deleteKey(int i);
	void insertKey(int k);
};

void MinHeap::swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

MinHeap::MinHeap(int i) {
	arr = new int[i];
	capacity = i;
	heapSize = 0;
}

void MinHeap::minHeapify(int i) {
	int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heapSize && arr[l] < arr[i])
        smallest = l;
    if (r < heapSize && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(smallest);
    }
}

int MinHeap::deleteMin() {
	if (heapSize==0) {
		cout<<"empty array!\n";
		return -1;
	} else if (heapSize==1) {
		heapSize--;
		return arr[0];
	}

	int root = arr[0];
	arr[0] = arr[heapSize-1];
	heapSize--;
	minHeapify(0);
	return root;
}

void MinHeap::insertKey(int k) {
	if (heapSize == capacity) {
		cout<<"Max size hit!\n";
		return;
	}
	heapSize++;
	int i = heapSize-1;
	arr[i] = k;
	while (i!=0 && arr[parent(i)] > arr[i]) {
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

int MinHeap::deleteKey(int i) {
	if (i >= heapSize) {
		cout<<"the heck\n";
		return -1;
	}
	int key = arr[i];
	arr[i] = arr[heapSize-1];
	heapSize--;
	minHeapify(i);
	return key;
}

void MinHeap::print() {
	for (int i=0; i<heapSize; i++) {
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}

class MaxHeap {
	int* arr;
	int heapSize;
	int capacity;
public:
	MaxHeap(int);
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return 2*i+1; }
	int right(int i) { return 2*i+2; }
	int getMax() { return arr[0]; }
	void swap(int* a, int* b);
	void print();

	void heapify(int i);
	void insert(int k);
	int extractMax();

};

MaxHeap::MaxHeap(int cap) {
	arr = new int[cap];
	capacity = cap;
	heapSize = 0;
}

void MaxHeap::swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeap::insert(int k) {
	if (heapSize==capacity) {
		cout<<"Max capacity!!!\n";
		return;
	}

	heapSize++;
	int i = heapSize-1;
	arr[i] = k;
	while(i>0 && arr[parent(i)] < arr[i]) {
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void MaxHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);
	int biggest = i;
	if (l < heapSize && arr[l] > arr[i]) {
		biggest = l;
	} if (r < heapSize && arr[r] > biggest) {
		biggest = r;
	} if (biggest!=i) {
		swap(&arr[biggest], &arr[i]);
		heapify(biggest);
	}
}

int MaxHeap::extractMax() {
	if (heapSize==0) {
		cout<<"heap is empty!\n";
	} else if (heapSize==1){
		heapSize--;
		return arr[0];
	}

	int key = arr[0];
	arr[0] = arr[heapSize-1];
	heapSize--;
	heapify(0);
	return key;
}

void MaxHeap::print() {
	for (int i=0; i<heapSize; i++) {
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}

int main() {
	MaxHeap m(11);
	m.insert(3);
    m.insert(2);
    m.insert(15);
    m.insert(5);
    m.insert(4);
    m.insert(45);
    // m.deleteKey(3);
    m.print();
	return 0;
}