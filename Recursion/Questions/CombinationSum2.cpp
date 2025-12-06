#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

using vi = vector<int> ;

class Solution {
    void recursion(int i,int n,int target,vi &candidates,vi &temp,set<vi> &hashSet){
        if(i>=n){
            if(target) return;
            vector<int> temp_=temp;
            sort(temp_.begin(),temp_.end());
            hashSet.insert(temp_);
            return ;
        }
        recursion(i+1,n,target,candidates,temp,hashSet);
        if(target>=candidates[i]){
            temp.push_back(candidates[i]);
            recursion(i+1,n,target-candidates[i],candidates,temp,hashSet);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vi> hashSet;
        vi temp;
        int n=candidates.size();
        recursion(0,n,target,candidates,temp,hashSet);
        vector<vi> answer(hashSet.begin(),hashSet.end());
        return answer;
    }
};

class Solution {
    void recursion(int i,int n,int target,vi &candidates,vi &temp,vector<vi> &ans){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<n;j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[j]);
            recursion(j+1,n,target-candidates[j],candidates,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vi> ans;
        vi temp;
        recursion(0,n,target,candidates,temp,ans);
        return ans;
    }
};


int main(){

return 0;
}