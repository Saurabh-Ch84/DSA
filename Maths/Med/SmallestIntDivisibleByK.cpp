#include<iostream>
using namespace std;

int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) return -1; // impossible cases
    int rem = 1 % k;
    for (int len = 1; len <= k; len++) {
        if (rem == 0) return len;
        rem = (rem * 10 + 1) % k;
    }
    return -1;
}

int main(){

return 0;
}