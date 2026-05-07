#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), q=queries.size(), mod=1e9+7;
        for(int i=0;i<q;i++){
            int l=queries[i][0], r=queries[i][1];
            int k=queries[i][2], v=queries[i][3];
            for(int idx=l;idx<=r;){
                nums[idx]=(1LL*nums[idx]*v)%mod;
                idx+=k;
            }
        }
        int totalXOR=0;
        for(int i=0;i<n;i++)
            totalXOR=totalXOR^nums[i];
        return totalXOR;
    }
};

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<n && !arr[i]) i++;
            while(j>0 && arr[j])  j--;
            if(i<j) swap(arr[i],arr[j]);
        }
    }
};

int main(){

return 0;
}