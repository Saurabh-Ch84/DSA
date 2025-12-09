#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int> ;

class Solution {
  public:
    int minCost(vector<vector<int>> &colors) {
        int n=colors.size(),m=colors[0].size();
        vi dp = colors[0];
        for(int i=1; i<n; i++){
            int mini1=INT_MAX,mini2=INT_MAX;
            int minIdx=m;
            for(int j=0;j<m;j++){
                if(dp[j] < mini1){
                    mini2=mini1;
                    mini1=dp[j];
                    minIdx=j;
                }else if(dp[j] < mini2){
                    mini2=dp[j];
                }
            }
            vi temp(m, INT_MAX);
            for(int j=0; j<m; j++){
                int val = colors[i][j];
                if(j!=minIdx && minIdx!=m) temp[j]=val+mini1;
                else if(mini2!=INT_MAX) temp[j]=val+mini2;
            }
            dp=temp;
        }
        int mini= *min_element(dp.begin(),dp.end());
        return mini==INT_MAX ? -1: mini;
    }
};

int main(){

return 0;
}