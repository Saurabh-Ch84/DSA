#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vvvint dp(m,vvint(n,vint(1024,0)));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i && !j){
                    dp[i][j][grid[i][j]]=1;
                    continue;
                }
                int val=grid[i][j];
                if(i>0){
                    vint &topXORs=dp[i-1][j];
                    for(int oldXOR=0;oldXOR<1024;oldXOR++){
                        if(!topXORs[oldXOR]) continue;
                        int currXOR=oldXOR^val;
                        dp[i][j][currXOR]=1;
                    }
                }
                if(j>0){
                    vint &leftXORs=dp[i][j-1];
                    for(int oldXOR=0;oldXOR<1024;oldXOR++){
                        if(!leftXORs[oldXOR]) continue;
                        int currXOR=oldXOR^val;
                        dp[i][j][currXOR]=1;
                    }
                }
            }
        }
        
        for(int i=0;i<1024;i++){
            if(dp[m-1][n-1][i])
                return i;
        }
        return -1;
    }
};

int main(){

return 0;
}