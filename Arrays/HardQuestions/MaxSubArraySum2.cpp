#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrSumBrute(vector<int>& arr, int a, int b) {
        // code here
        int left=0,right=0,n=arr.size();
        int maxSum=INT_MIN,currSum=0;
        while(right<n){
            currSum+=arr[right];
            while(right-left+1>b)
                currSum-=arr[left++];
            int tempSum=currSum,left_=left;
            while(right-left_+1>=a && right-left_+1<=b){
                maxSum=max(maxSum,tempSum);
                tempSum-=arr[left_++];
            }
            right++;
        }
        return maxSum;
    }

    int maxSubarrSumOptimal(vector<int>& arr, int a, int b) {
        // code here
        int n=arr.size();
        
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+arr[i];
        }
        
        multiset<int> window;
        int maxSum=INT_MIN;
        for(int i=1;i<=n;i++){
            if(i>=a)
                window.insert(prefix[i-a]);
            if(i>b)
                window.erase(window.find(prefix[i-b-1]));
            if(!window.empty())
                maxSum=max(maxSum,prefix[i]-*window.begin());
        }
        return maxSum;
    }
};
int main(){

return 0;
}