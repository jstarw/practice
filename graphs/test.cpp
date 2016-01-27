#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,8,2,7,6,5,4,3,2,100};

	int b[] = {};
	b=a;
	for (int i=1; i<13; i++) {
		if (a[i]<a[i-1]) {
			b[i] = b[i-1]++;
		}
	}

	for (int j=0; j<13; j++) {
		cout<< b[j]<<" ";
	}
	return 0;
}