#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
class Solution1 {
  public:
    lli maxSumWithK(lli a[], lli n, lli k) {
        int left=0, right=0;
        lli currSum=0, maxSum=INT_MIN, lastSum=0;
        while(right<n){
            currSum+=a[right];
            if(right-left+1==k){
                maxSum=max(maxSum, currSum);
            }
            else if(right-left+1>k){
                maxSum=max(maxSum, currSum);
                lastSum+=a[left];
                left++;
                if(lastSum<0){
                    currSum-=lastSum;
                    lastSum=0;
                    maxSum=max(maxSum, currSum);
                }
            }
            right++;
        }
        return maxSum;
    }
};

class Solution2 {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n=arr.size(), left=0, right=0;
        int sum=0, maxi=-1e9, optionalSum=0; // Used to keep track of the sum of elements that are being removed
        while(right<n){
            sum+=arr[right];
            if(right-left+1==k)
                maxi=max(maxi,sum);
            else if(right-left+1>k){
                maxi=max(maxi,sum);
                optionalSum+=arr[left];
                left++;
                if(optionalSum<0){
                    sum-=optionalSum;
                    optionalSum=0;
                    maxi=max(maxi,sum);
                }
            }
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}