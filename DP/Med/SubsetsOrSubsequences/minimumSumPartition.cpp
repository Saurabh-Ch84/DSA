#include<iostream>
#include<vector>
using namespace std;

class Solution {
    
  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int totalSum=0;
        for(int &v:arr) totalSum+=v;
        int leftSum=0,sum=totalSum/2,n=arr.size();
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            vector<bool> temp(sum+1,false);
            for(int j=0;j<=sum;j++){
                if(!j)
                {
                    temp[j]=true;
                    continue;
                }
                bool notTake=dp[j];
                bool take=false;
                if(j>=arr[i]) take=dp[j-arr[i]];
                temp[j]=take|notTake;
                
                if(temp[j]) leftSum=j;
            }
            dp=temp;
        }
        int rightSum=totalSum-leftSum;
        return abs(leftSum-rightSum);
    }
};


int main(){

return 0;
}