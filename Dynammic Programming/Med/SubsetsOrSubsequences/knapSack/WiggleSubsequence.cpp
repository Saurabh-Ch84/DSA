#include<iostream>
#include<vector>

using namespace std;
using vi=vector<int> ;
using vvi=vector<vi>;
using vvvi=vector<vvi>;

class Solution {
    int recursion(int p,int i,int n,vi &nums,vvvi &dp,bool sign){
        if(i>=n) return 0;
        if(dp[p+1][i][sign]!=-1) return dp[p+1][i][sign];
        int take=0, notTake=0;
        notTake=0+recursion(p,i+1,n,nums,dp,sign);
        if(p==-1 || (sign && nums[i]>nums[p]) || (!sign && nums[i]<nums[p]))
            take=1+recursion(i,i+1,n,nums,dp,!sign);
        return dp[p+1][i][sign]=max(take,notTake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vvvi dp1(n+1,vvi(n+1,vi(2,-1)));
        int pos=recursion(-1,0,n,nums,dp1,true);
        vvvi dp2(n+1,vvi(n+1,vi(2,-1)));
        int neg=recursion(-1,0,n,nums,dp2,false);
        return max(pos,neg);
    }
};

int main(){

return 0;
}