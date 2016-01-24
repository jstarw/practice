#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 4, b = 2;
    int * ptr2 = &a;
    int ** ptr = &ptr2;
    *ptr = &b;
    cout << **ptr;
}