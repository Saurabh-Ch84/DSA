#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void recursion(vector<vector<int>> &ans,vector<int> &temp,int n,int k,int lb){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for(int num=lb;num<=n;num++){
            temp.push_back(num);
            recursion(ans,temp,n,k,num+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        recursion(ans,temp,n,k,1);
        return ans;
    }
};

int main(){
return 0;
}