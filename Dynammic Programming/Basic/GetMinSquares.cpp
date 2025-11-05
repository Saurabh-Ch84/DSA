#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++)
                mini=min(mini,dp[i-j*j]);
            dp[i]=1+mini;
        }
        
        return dp[n];
    }
};

class Solution2 {
    int BFS(queue<int> &q,int n){
        unordered_set<int> hashSet;
        int steps=0,lim=sqrt(n);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz){
                int top=q.front();q.pop();
                if(top==n) return steps;
                for(int i=1;i<=lim;i++){
                    int num=top+i*i;
                    if(num>n || hashSet.count(num)) continue;
                    q.push(num);
                    hashSet.insert(num);
                }
                sz--;
            }
            steps++;
        }
        
        return -1;
    }
  public:
    int minSquares(int n) {
        // Code here
        queue<int> q;
        q.push(0);
        return BFS(q,n);
    }
};

int main(){

return 0;
}