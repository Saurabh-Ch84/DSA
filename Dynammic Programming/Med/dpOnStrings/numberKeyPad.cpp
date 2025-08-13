#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getCount(int n) {
        // code here
        if(n<=0) return 0;
        vector<vector<int>> adjList={
            {0,8},{1,2,4},{1,2,3,5},{2,3,6},{1,4,5,7},{2,4,5,6,8},
            {3,5,6,9},{4,7,8},{0,5,7,8,9},{6,8,9}
        };
        vector<int> dp(10,1);
        for(int i=1;i<n;i++){
            vector<int> temp(10,0);
            for(int j=0;j<10;j++){
                for(int &num:adjList[j]) 
                    temp[j]+=dp[num];
            }
            dp=temp;
        }
        int comb=0;
        for(int i=0;i<10;i++) comb+=dp[i];
        return comb;
    }
};

int main(){

return 0;
}