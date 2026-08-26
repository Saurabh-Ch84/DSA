#include<bits/stdc++.h>
using namespace std;

class Solution1{
    // brute force.
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        set<pair<int,int>> hashSet;
        vector<int> res(n-k+1,0);
        for(int i=0;i<n;i++){
            if(i>=k) hashSet.erase({nums[i-k],i-k});
            if(nums[i]<0) hashSet.insert({nums[i],i});
            if(i+1>=k && hashSet.size()>=x){
                int smallest=1;
                auto itr=hashSet.begin();
                while(smallest<x){
                    smallest++;
                    itr++;
                }
                res[i+1-k]=itr->first;
            }
        }
        return res;
    }
};

class Solution2 {
    // better.
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size(), negs=0, sz=maxi-mini+1;
        vector<int> res(n-k+1,0), arr(sz,0);

        for(int i=0;i<n;i++){
            int normalisedNum=nums[i]-mini;
            if(i>=k && nums[i-k]<0){
                int oldNormalisedNum=nums[i-k]-mini;
                if(arr[oldNormalisedNum]){
                    arr[oldNormalisedNum]--;
                    negs--;
                }
            }
            if(nums[i]<0){
                arr[normalisedNum]++;
                negs++;
            }
            if(i+1>=k && negs>=x){
                int xthSmallest=0, count=0;
                for(int j=0;j<sz;j++){
                    if(arr[j]){
                        xthSmallest=mini+j; 
                        count+=min(x-count,arr[j]);
                        if(count==x){
                            res[i+1-k]=xthSmallest;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution3 {
    // optimal
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> res(n-k+1,0);
        int mini=*min_element(nums.begin(),nums.end());
        if(mini>=0) return res;
        int sz=-mini+1, negs=0;
        vector<int> arr(sz,0); // normalised range.

        for(int i=0;i<n;i++){
            // shrink
            if(i>=k && nums[i-k]<0){
                int oldNormalisedNum=nums[i-k]-mini;
                if(arr[oldNormalisedNum]){
                    arr[oldNormalisedNum]--;
                    negs--;
                }
            }
            // expand
            if(nums[i]<0){
                int currNormalisedNum=nums[i]-mini;
                arr[currNormalisedNum]++;
                negs++;
            }
            if(i+1>=k && negs>=x){
                int xthSmallest=0, count=0;
                for(int j=0;j<sz;j++){
                    if(arr[j]){
                        xthSmallest=mini+j; // denormalize
                        count+=min(x-count,arr[j]);
                        if(count==x){
                            res[i+1-k]=xthSmallest;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}