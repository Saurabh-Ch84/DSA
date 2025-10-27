#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size()<=1) return 0;
        priority_queue<int,vector<int>,greater<int>> pq(arr.begin(),arr.end());
        
        int totalCost=0;
        while(pq.size()>1){
            int topA=pq.top();pq.pop();
            int topB=pq.top();pq.pop();
            int cost=topA+topB;
            totalCost+=cost;
            pq.push(cost);
        }
        return totalCost;
    }
};

int main(){

return 0;
}