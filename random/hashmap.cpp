#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	map<char, int> hashmap;
	map<char, int>::iterator i;
	hashmap['a'] = 3;
	hashmap['t'] = 4;
	for (i = hashmap.begin(); i != hashmap.end(); i++) {
		cout<< i->second;
	}
	
	return 0;
}