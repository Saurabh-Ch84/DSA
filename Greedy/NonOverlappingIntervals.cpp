#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int overlappingIntervals=0,freeTime=INT_MIN;
        for(vector<int> &v:intervals)
        {
            if(v[0]>=freeTime) freeTime=v[1];
            else overlappingIntervals++;
        }
        return overlappingIntervals;
    }
};

int main(){

return 0;
}