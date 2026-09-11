#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<vector<int>> &matrix){
    vector<int> dp=matrix[0];
    for(int i=1;i<n;i++){
        vector<int> temp(3,0);
        temp[0]=matrix[i][0]+max(dp[1],dp[2]);
        temp[1]=matrix[i][1]+max(dp[0],dp[2]);
        temp[2]=matrix[i][2]+max(dp[0],dp[1]);
        dp=temp;
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<solve(n,matrix);
return 0;
}