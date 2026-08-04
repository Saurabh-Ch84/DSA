#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=vector<int>;
    using vvint=vector<vint>;
    int inf=1e9;
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vvint dp(n+1,vint(2,0));
        for(int i=n-1;i>=0;i--){
            int take1=-inf, take2=-inf, take3=-inf;
            take1=stoneValue[i]+dp[i+1][0];
            if(i+1<n) take2=stoneValue[i]+stoneValue[i+1]+dp[i+2][0];
            if(i+2<n) take3=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+dp[i+3][0];
            dp[i][1]=max({take1,take2,take3});

            int take1_=inf, take2_=inf, take3_=inf;
            take1_=-stoneValue[i]+dp[i+1][1];
            if(i+1<n) take2_=-stoneValue[i]-stoneValue[i+1]+dp[i+2][1];
            if(i+2<n) take3_=-stoneValue[i]-stoneValue[i+1]-stoneValue[i+2]+dp[i+3][1];
            dp[i][0]=min({take1_,take2_,take3_});
        }
        int scoreOfAlice=dp[0][1];
        if(!scoreOfAlice) return "Tie";
        return (scoreOfAlice>0? "Alice":"Bob");
    }
};

int main(){

return 0;
}