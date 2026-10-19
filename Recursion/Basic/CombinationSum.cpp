#include<bits/stdc++.h>
using namespace std;

using vi = vector<int> ;
class Solution {
    void recursion(int i,int n,int target,vi &candidates,vi &temp,vector<vi> &ans){
        if(i>=n){
            if(target==0) ans.push_back(temp);
            return ;
        }
        //take
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            recursion(i,n,target-candidates[i],candidates,temp,ans);
            temp.pop_back();
        }
        //skip
        recursion(i+1,n,target,candidates,temp,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        recursion(0,n,target,candidates,temp,ans);
        return ans; 
    }
};


int main(){

return 0;
}