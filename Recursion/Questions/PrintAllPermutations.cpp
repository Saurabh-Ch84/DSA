#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    void recursion1(vector<int>& n,vector<int> &ds,vector<bool>& v,vector<vector<int>>& a)
    {
        if(ds.size()==n.size()){
            a.push_back(ds);
            return ;
        }
        for(int i=0;i<v.size();i++)
        {
            if(!v[i])
            {
                v[i]=true;
                ds.push_back(n[i]);
                recursion1(n,ds,v,a);
                v[i]=false;
                ds.pop_back();
            }
        }
    }
    void recursion2(vector<int> &ds,vector<vector<int>>& a,int idx,int n)
    {
        if(idx>=n){
            a.push_back(ds);
            return ;
        }
        for(int i=idx;i<n;i++)
        {
            swap(ds[i],ds[idx]);
            recursion2(ds,a,idx+1,n);
            swap(ds[i],ds[idx]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<bool> visited(nums.size(),false);
        vector<int> ds1;
        vector<vector<int>> ans;
        recursion1(nums,ds1,visited,ans);
        // vector<int> ds2=nums;
        // recursion2(ds2,ans,0,ds2.size());
        return ans;
    }
};

int main(){

return 0;
}