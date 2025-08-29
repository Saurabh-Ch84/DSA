#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int idx=i-j;
                hashMap[idx].push_back(grid[i][j]);
            }
        }
        vector<vector<int>> ans=grid;
        unordered_set<int> hashSet;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int idx=i-j;
                if(hashSet.count(idx)==0){
                    if(idx<0) sort(hashMap[idx].begin(),hashMap[idx].end());
                    else sort(hashMap[idx].rbegin(),hashMap[idx].rend());
                    hashSet.insert(idx);
                }
                ans[i][j]=hashMap[idx].back();
                hashMap[idx].pop_back();
            }
        }
        return ans;
    }
};

int main(){

return 0;
}