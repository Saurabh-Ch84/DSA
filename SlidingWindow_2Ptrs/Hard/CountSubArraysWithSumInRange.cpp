#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    int countSubarrayWithSumLessthanK(vint &arr,int k,int n){
        int count=0, left=0, right=0, sum=0;
        while(right<n){
            sum+=arr[right];
            while(sum>=k && left<=right){
                sum-=arr[left];
                left++;
            }
            count+=(right-left+1); // all subarrays ending at 'right' and starting from 'left' to 'right' are valid subarrays.
            right++;
        }
        return count;
    }
    int countSubarrayWithSumMorethanK(vint &arr,int k,int n){
        int count=0, left=0, right=0, sum=0;
        while(right<n){
            sum+=arr[right];
            while(sum>k && left<=right){
                count+=(n-right); // all subarrays starting from 'left' and ending from 'right' to 'n-1' are valid subarrays.
                sum-=arr[left];
                left++;
            }
            right++;
        }
        return count;
    }
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int n=arr.size(); 
        // array has only positive integers, we can use sliding window technique to find the count of subarrays.
        int subarraySumLessThanK=countSubarrayWithSumLessthanK(arr,l,n);
        int subarraySumMoreThanK=countSubarrayWithSumMorethanK(arr,r,n);
        long long ans=(1LL*n*(n+1)/2-(subarraySumLessThanK+subarraySumMoreThanK));
        return (int)ans;
    }
};

int main(){

return 0;
}