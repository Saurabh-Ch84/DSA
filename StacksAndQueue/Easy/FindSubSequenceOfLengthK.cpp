#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});

        while(k){
            int idx=pq.top().second;
            pq.pop();
            visited[idx]=true;
            k--;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(visited[i])
                res.push_back(nums[i]);
        }

        return res;
    }
};

int main(){

return 0;
}