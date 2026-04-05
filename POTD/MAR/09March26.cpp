#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
  public:
    string largestSwap(string &s) {
        // code here
        
        int n=s.size();
        vector<int> lastSeen(10,-1);
        //number-> last-index        
        for(int i=0;i<n;i++)
            lastSeen[s[i]-'0']=i;
        for(int i=0;i<n;i++){
            int curr=s[i]-'0';
            for(int digit=9;digit>curr;digit--){
                // if found at a right index.
                if(lastSeen[digit]>i){
                    swap(s[lastSeen[digit]],s[i]);
                    return s;
                }
            }
        }
        return s;
    }
};


using vll=vector<long long>;
using vvll=vector<vll>;
using vvvll=vector<vvll>;

class Solution2 {
    const int MOD=1e9+7;
    long long recursion(int num,int zero,int one,int limit,vvvll &dp){
        if(!zero && !one) return 1;
        if(dp[zero][one][num]!=-1) return dp[zero][one][num];
        long long ans=0;
        for(int i=1;i<=min(limit,(num? one:zero));i++){
            if(num) ans=(ans+recursion(1-num,zero,one-i,limit,dp))%MOD;
            else ans=(ans+recursion(1-num,zero-i,one,limit,dp))%MOD;
        }
        return dp[zero][one][num]=ans;
    }
    
public:
    int numberOfStableArrays(int zero, int one, int limit){
        vvvll dp(zero+1,vvll(one+1,vll(2,-1)));
        long long startingFromOne=recursion(0,zero,one,limit,dp);
        long long startingFromZero=recursion(1,zero,one,limit,dp);
        return (startingFromOne + startingFromZero)%MOD;
    }
};



int main(){

return 0;
}