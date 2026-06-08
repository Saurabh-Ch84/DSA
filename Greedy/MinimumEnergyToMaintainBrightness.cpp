#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    long long minEnergy(int n,int brightness,vvint &intervals) {
        sort(intervals.begin(),intervals.end());
        vvint newInterval;
        for(vint &interval: intervals){
            if(newInterval.empty() || newInterval.back()[1]<interval[0])
                newInterval.push_back(interval);
            else newInterval.back()[1]=max(newInterval.back()[1],interval[1]);
        }
        long long range=0;
        for(vint &interval: newInterval)
            range+=interval[1]-interval[0]+1;
        int bulbs=(brightness+2)/3;
        return range*bulbs;
    }
};

int main(){

return 0;
}