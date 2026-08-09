#include<bits/stdc++.h>
using namespace std;

// Definition for an Interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> mp;
        for(auto &s: schedule){
            for(auto &i: s){
                mp[i.start]++;
                mp[i.end]--;
            }
        }
        int sum=0, prev=-1e9;
        vector<Interval> res;
        for(auto &m: mp){
            if(!sum && prev!=-1e9) 
                res.push_back(Interval(prev, m.first));
            prev=m.first;
            sum+=m.second;
        }
        return res;
    }
};

int main(){

return 0;
}