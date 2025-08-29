#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isCorrect(int y, int n) {
        double x = (((2.0 * n)/y) - y + 1) / 2.0;
        if (x < 1.0) return false;
        int x_ = (int)x;
        return abs(x - x_) < 1e-7;
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
    Solution s;
    cout<<s.getCount(15);
return 0;
}