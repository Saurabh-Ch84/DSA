#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    struct Comp{
        bool operator()(const vint &a,const vint &b){
            if(a[0]<b[0]) return true;
            else if(a[0]==b[0]){
                int A=a[1]-a[0], B=b[1]-b[0];
                return A>B;
            }
            return false;
        }
    };
    bool isCovered(vint &a,vint &b){
        return (a[0]<=b[0] && a[1]>=b[1]);
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count=0, n=intervals.size();
        sort(intervals.begin(),intervals.end(),Comp());
        vint prev={0,0};
        for(vint &interval: intervals){
            if(isCovered(prev,interval)) count++;
            else prev=interval;
        }
        return n-count;
    }
};

int main(){

return 0;
}