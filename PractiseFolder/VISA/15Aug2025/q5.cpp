#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isCorrect(int y, int n) {
        double x = ((2.0 * n) / y - y + 1) / 2.0;
        if (x < 1.0) return false;       // Ensure starting number >= 1
        int numX = static_cast<int>(x);
        double fp = x - numX;
        return fabs(fp) < 1e-9;
    }
  public:
    int getCount(int N) {
        int count = 0;
        int bound = sqrt(2 * N);
        for (int y = 2; y <= bound; y++)
            if (isCorrect(y, N)) count++;
        return count;
    }
};

int main(){

return 0;
}