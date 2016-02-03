
#include <iostream>
#include <string>

using namespace std;

int ticTacToe(int arr[3][3]) {
	int sum = 0;

	if (arr[0][0]==1 && 
		arr[1][1]==1 &&
		arr[2][2]==1) {
		sum++;
	}

	if (arr[0][2]==1 && 
		arr[1][1]==1 &&
		arr[2][0]==1) {
		sum++;
	}

	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (arr[i][0]==1 && 
				arr[i][1]==1 &&
				arr[i][2]==1) {
				sum++;
			}

			if (arr[0][j]==1 && 
				arr[1][j]==1 &&
				arr[2][j]==1) {
				sum++;
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int arr[3][3] = {{1,0,0},{0,1,1},{0,0,1}};
	cout<<ticTacToe(arr);
	return 0;
}