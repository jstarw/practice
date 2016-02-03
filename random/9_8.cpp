#include <iostream>

using namespace std;

int money(int n, int denom) {
    int next_denom = 0;
    switch(denom) {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            return 1;
    }
    int ways = 0;
    for (int i=0; i*denom <=n ; i++) {
        ways += money(n-i*denom, next_denom);
    }
    return ways;
}

// int moneyRecursive(int n) {
//     if (n<0) return 0;
//     else if (n==0) return 1;
//     else return money(n-25) + money(n-10) + money(n-5) + money(n-1);
// }

int main(int argc, char const *argv[])
{
    cout<<money(100, 25);
    return 0;
}