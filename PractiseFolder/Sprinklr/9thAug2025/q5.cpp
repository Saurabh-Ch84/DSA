#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;
        set<pair<int,int>> hashSet;
        pq.push({a[0]+b[0],{0,0}});
        hashSet.insert({0,0});
        
        vector<int> di={1,0},dj={0,1};
        vector<int> res;
        while(res.size()<k){
            auto item=pq.top();
            pq.pop();
            int sum=item.first;
            int i=item.second.first,j=item.second.second;
            res.push_back(sum);
            
            for(int k=0;k<2;k++){
                int newI=i+di[k],newJ=j+dj[k];
                if(newI<n && newJ<n && hashSet.count({newI,newJ})==false){
                    hashSet.insert({newI,newJ});
                    int newSum=a[newI]+b[newJ];
                    pq.push({newSum,{newI,newJ}});
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}