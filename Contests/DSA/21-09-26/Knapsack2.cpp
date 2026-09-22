#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(int N, int W, vector<pair<int,int>> &items, int sumOfValues){
        long long inf = 1e15;
        vector<long long> dp(sumOfValues+2,inf);
        dp[0]=0;
        for(int i=0;i<N;i++){
            int weight=items[i].first, value=items[i].second;
            for(int currV=sumOfValues;currV>=value;currV--){
                if(dp[currV-value]!=inf)
                    dp[currV]=min(dp[currV],dp[currV-value]+weight);
            }
        }
        for(int j=sumOfValues;j>=0;j--)
            if(dp[j]<=W) return j;
        return -1;
    }
};

int main(){
    int N,W;
    cin>>N>>W;
    vector<pair<int,int>> items(N);
    int sumOfValues=0;
    for(int i=0;i<N;i++){
        cin>>items[i].first>>items[i].second;
        sumOfValues+=items[i].second;
    }
    Solution s;
    cout<<s.solve(N,W,items,sumOfValues);
return 0;
}