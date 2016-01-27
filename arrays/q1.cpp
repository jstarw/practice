#include <iostream>
#include <string>
#include <vector>

using namespace std;

void isUnique(string str) {
	for (int i=0; i<str.length()-1; i++) {
		for (int j=i+1; j<str.length(); j++) {
			if (str[i]==str[j]) {
				cout<<"not unique\n";
			}
		}
	}
}

bool isUnique2(string str) {
	if (str.length()>256) return false;
	bool charSet[256] = {};
	for (int i=0; i<str.length(); i++) {
		if (charSet[str[i]]) return false;
		charSet[str[i]]=true;
	}
	return true;
}

//q2
string reverse(string str) {
	int j = str.length()-1;
	for (int i=0; i<str.length()/2; i++ ) {
		char tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j--;
	}
	return str;
}

//q3
bool isPermute(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	int arr[256] = {};
	for (int i=0; i<str1.length(); i++) {
		arr[str1[i]]++;
	}
	for (int i=0; i<str2.length(); i++) {
		arr[str2[i]]--;
		if (arr[str2[i]]<0) return false;
	}
	return true;
}

string compress(string str) {
	char c=str[0];
	int count = 1;
	string s;
	s+=c;
	for (int i=1; i<str.length(); i++) {
		if(c == str[i]) {
			count++;

		} else {
			c = str[i];
			s=s+to_string(count)+c;
			count = 1;
		}
	}
	s=s+to_string(count);
	if (s.length()>str.length()) return str;
	else return s;
}

void rotateImg(int img[3][3]) {

	int temp;
	for (int i=0; i<3; i++) {
		for (int j=0; j<i; j++) {
			temp = img[i][j];
			img[i][j] = img[j][i];
			img[j][i] = temp;
		}
	}
	//print
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout<<img[i][j]<<" ";
		}
		cout<<endl;
	}
}

void setZero (int matrix[3][3]) {
	bool row [3] = {};
	bool column [3] = {};
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (matrix[i][j]==0) {
				row[i] = true;
				column[j] = true;
			}
		}
	}
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (row[i] || column[j]) {
				matrix[i][j] = 0;
			}
		}
	}
	//print
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	char word[] = {'a', 'b', 'c', 'd', '\0'};
	string str1 = "aaaabssssssssddhh";
	string str2 = "afghjrtd";
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,0,9}};

	// isUnique(str);
	// bool unique = isUnique2(str);
	// cout<<unique;
	// str = reverse(str);
	// bool a = isPermute(str1, str2);
	// str1 = compress(str1);
	// rotateImg(image);
	setZero(matrix);
	return 0;
}