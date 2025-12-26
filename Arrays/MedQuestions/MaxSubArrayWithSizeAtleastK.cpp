#include<iostream>
#include<vector>
#include<climits>
using namespace std;

using lli = long long int;
class Solution {
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

int main(){

return 0;
}