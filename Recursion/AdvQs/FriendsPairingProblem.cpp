#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // brute-force
    using vint=vector<int>;
    int recursion(int i,int n,vint &isSingle){
        if(i==n) return 1;
        if(!isSingle[i]) return recursion(i+1,n,isSingle);
        int single=0, paired=0;
        single=recursion(i+1,n,isSingle);
        for(int j=i-1;j>=0;j--){
            if(isSingle[j]){
                isSingle[i]=0;
                isSingle[j]=0;
                paired=paired+recursion(i+1,n,isSingle);
                isSingle[j]=1;
                isSingle[i]=1;
            }
        }
        return single+paired;
    }
  public:
    int countFriendsPairings(int n) {
        // code here
        vint isSingle(n,1);
        return recursion(0,n,isSingle);
    }
};

class Solution2 {
    // better solution using bitmasking and memoization
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isIthBitSet(int mask,int i){
        return (mask & (1<<i));
    }
    void toggleIthBit(int &mask,int i){
        // pass by reference to modify the original mask
        mask=mask^(1<<i);
    }
    int recursion(int i,int n,int mask,vvint &dp){
        if(i==n) return 1;
        if(dp[i][mask]!=-1) return dp[i][mask];
        if(!isIthBitSet(mask,i)) return recursion(i+1,n,mask,dp);
        int single=0, paired=0;
        single=recursion(i+1,n,mask,dp);
        for(int j=i-1;j>=0;j--){
            if(isIthBitSet(mask,j)){
                toggleIthBit(mask,i);
                toggleIthBit(mask,j);
                paired=paired+recursion(i+1,n,mask,dp);
                toggleIthBit(mask,j);
                toggleIthBit(mask,i);
            }
        }
        return dp[i][mask]=single+paired;
    }
  public:
    int countFriendsPairings(int n) {
        // code here
        int mask=0;
        for(int i=0;i<n;i++)
            mask=mask|(1<<i);
        vvint dp(n+1,vint(1<<n,-1));
        return recursion(0,n,mask,dp);
    }
};

class Solution3 {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    int countFriendsPairings(int n) {
        // code here
        vint dp(n+1,0);
        dp[0]=1, dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
        }
        return dp[n];
    }
};

class Solution4 {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    int countFriendsPairings(int n) {
        // code here
        int a=1, b=1;
        for(int i=2;i<=n;i++){
            int c=b+(i-1)*a;
            a=b, b=c;
        }
        return b;
    }
};



int main(){

return 0;
}