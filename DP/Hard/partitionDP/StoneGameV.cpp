#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    // O(n^3) solution, we can optimize it to O(n^2) using binary search, but this is good enough for now.
    int recursion(int low,int high,vint &stoneValue,vint &prefixArr,vvint &dp){
        if(low>=high) return 0; // If there is only one stone left, Alice cannot make any move, so her score is 0
        if(dp[low][high]!=-1) return dp[low][high];
        int ans=0; // Alice's score is initially 0, we will try to maximize it
        for(int i=low;i<high;i++){
            int leftValue=prefixArr[i]-(low? prefixArr[low-1]:0);
            int rightValue=prefixArr[high]-prefixArr[i];
            int nextAns=0;
            if(leftValue>rightValue) // Alice will choose the right part, i+1 cause the right part starts from i+1
                nextAns=rightValue+recursion(i+1,high,stoneValue,prefixArr,dp);
            else if(leftValue<rightValue) // Alice will choose the left part, i cause the left part ends at i
                nextAns=leftValue+recursion(low,i,stoneValue,prefixArr,dp);
            else{
                // Alice can choose either part, so we will take the maximum of both choices
                int choice1=rightValue+recursion(i+1,high,stoneValue,prefixArr,dp);
                int choice2=leftValue+recursion(low,i,stoneValue,prefixArr,dp);
                nextAns=max(choice1,choice2);
            }
            ans=max(ans,nextAns);
        }
        return dp[low][high]=ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vint prefixArr(n,0);
        prefixArr[0]=stoneValue[0];
        for(int i=1;i<n;i++) // prefix sum array to get the sum of any subarray in O(1)
            prefixArr[i]=prefixArr[i-1]+stoneValue[i];
        vvint dp(n+1,vint(n+1,-1));
        return recursion(0,n-1,stoneValue,prefixArr,dp);
    }
};

int main(){

return 0;
}