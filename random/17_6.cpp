#include <iostream>
#include <vector>

using namespace std;

void findIndexes(int arr[], int N) {
	vector<int> front;
	vector<int> middle;
	vector<int> back;

	for (int i=0; i<N-1; i++) {
		if (arr[i] > arr[i+1]) {
			front.push_back(arr[i]);
			break;
		} else {
			front.push_back(arr[i]);
		}
	}
	for (int i=N-2; i>0; i--) {
		if (arr[i] > arr[i-1]) {
			back.push_back(arr[i-1]);
			break;
		} else {
			back.push_back(arr[i-1]);
		}
	}
	for (int i=front.size(); i<N-back.size(); i++) {
		middle.push_back(arr[i]);
	}

	for (int i=0; i<back.size(); i++) {
		cout<<back[i];
	}
}

int main(int argc, char const *argv[])
{
    int arr [] = {1,2,4,6,10,7,3,9,11};
    findIndexes(arr, 9);
}