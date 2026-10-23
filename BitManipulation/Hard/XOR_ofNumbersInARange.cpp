#include<iostream>
using namespace std;

int xorFrom0ToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int xorRange(int L, int R) {
    return xorFrom0ToN(R) ^ xorFrom0ToN(L - 1);
}

int main(){

return 0;
}