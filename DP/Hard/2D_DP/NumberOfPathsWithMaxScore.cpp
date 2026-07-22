#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using pill=pair<int,long long>; 
    using vpill=vector<pill>;
    using vvpill=vector<vpill>;
public:
    vint pathsWithMaxScore(vector<string>& board) {
        int n=board.size(), mod=1e9+7;
        vpill dp(n+1,{-1,0});
        dp[n-1].first=0, dp[n-1].second=1;

        for(int j=n-2;j>=0;j--){
            if(board[n-1][j]=='X' || dp[j+1].first==-1){
                dp[j].first=-1;
                continue;
            }
            dp[j].first=dp[j+1].first+(board[n-1][j]-'0');
            dp[j].second=1;
        }
        for(int i=n-2;i>=0;i--){
            vpill temp(n+1,{-1,0});
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X'){
                    temp[j].first=-1;
                    continue;
                }
                pill downN=dp[j];
                pill rightN=temp[j+1];
                pill downRightN=dp[j+1];
                temp[j].first=max({downN.first,rightN.first,downRightN.first});
                if(temp[j].first==-1) continue;
                if(downN.first==temp[j].first) temp[j].second=(temp[j].second+downN.second)%mod;
                if(rightN.first==temp[j].first) temp[j].second=(temp[j].second+rightN.second)%mod;
                if(downRightN.first==temp[j].first) temp[j].second=(temp[j].second+downRightN.second)%mod;
                if(board[i][j]!='E')
                    temp[j].first+=(board[i][j]-'0');
            }
            dp=temp;
        }
        return {max(dp[0].first,0),(int)(dp[0].second)};
    }
};

class Solution2 {
    using vint=vector<int>;
    using pill=pair<int,long long>; 
    using vpill=vector<pill>;
    using vvpill=vector<vpill>;
public:
    vint pathsWithMaxScore(vector<string>& board) {
        int n=board.size(), mod=1e9+7;
        vvpill dp(n,vpill(n,{-1,0}));
        dp[n-1][n-1].first=0, dp[n-1][n-1].second=1;
        for(int i=n-2;i>=0;i--){
            if(board[i][n-1]=='X' || dp[i+1][n-1].first==-1){
                dp[i][n-1].first=-1;
                continue;
            }
            dp[i][n-1].first=dp[i+1][n-1].first+(board[i][n-1]-'0');
            dp[i][n-1].second=1;
        }
        for(int j=n-2;j>=0;j--){
            if(board[n-1][j]=='X' || dp[n-1][j+1].first==-1){
                dp[n-1][j].first=-1;
                continue;
            }
            dp[n-1][j].first=dp[n-1][j+1].first+(board[n-1][j]-'0');
            dp[n-1][j].second=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(board[i][j]=='X'){
                    dp[i][j].first=-1;
                    continue;
                }
                pill &r=dp[i][j+1], &d=dp[i+1][j], &dR=dp[i+1][j+1];
                dp[i][j].first=max({r.first,d.first,dR.first});
                if(dp[i][j].first==-1) continue;
                if(r.first==dp[i][j].first) dp[i][j].second=(dp[i][j].second+r.second)%mod;
                if(d.first==dp[i][j].first) dp[i][j].second=(dp[i][j].second+d.second)%mod;
                if(dR.first==dp[i][j].first) dp[i][j].second=(dp[i][j].second+dR.second)%mod;
                if(board[i][j]=='E') continue;
                dp[i][j].first+=(board[i][j]-'0');
            }
        }
        return {max(dp[0][0].first,0),(int)(dp[0][0].second)};
    }
};

int main(){

return 0;
}