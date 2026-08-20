#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) swap(cost1, cost2);
        long long ways = 0;
        int maxCount1 = total / cost1;
        for (int i = 0; i <= maxCount1; i++) {
            int remaining = total - i * cost1;
            ways += remaining / cost2 + 1;
        }
        return ways;
    }
};

int main(){

return 0;
}