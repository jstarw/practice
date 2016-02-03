#include <iostream>

using namespace std;

void _parentheses(int pos, int n, int open, int close) {
    static char str[100];
    if (close == n) {
        printf("%s \n", str);
        return;
    } else {
        if (open < n) {
            str[pos] = '(';
            _parentheses(pos+1, n, open+1, close);
        } 
        if (close < open) {
            str[pos] = ')';
            _parentheses(pos+1, n, open, close+1);
        }
    }
}

void parentheses(int n) { //wrapper
    _parentheses(0, n, 0, 0);
}

int main(int argc, char const *argv[])
{
    parentheses(3);
    return 0;
}