#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution1 {
    int getFlips(string s,string r){
        int flips=0, n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=r[i]) flips++;
        }
        return flips;
    }
public:
    int minFlips(string s) {
        int k=s.length();
        s+=s;
        int n=s.length();
        string t1, t2;
        for(int i=0;i<n;i++){
            t1.push_back(i%2==0? '1':'0');
            t2.push_back(i%2==0? '0':'1');
        }

        int mini=INT_MAX;
        int flip1=-1, flip2=-1;
        for(int i=0;i<n-k+1;i++){
            if(i){
                flip1=flip1-(s[i-1]==t1[i-1]? 0:1)+(s[i+k-1]==t1[i+k-1]? 0:1);
                flip2=flip2-(s[i-1]==t2[i-1]? 0:1)+(s[i+k-1]==t2[i+k-1]? 0:1);
            }
            else{
                flip1=getFlips(s.substr(i,k),t1.substr(i,k));
                flip2=getFlips(s.substr(i,k),t2.substr(i,k));
            }
            mini=min({mini,flip1,flip2});
        }   

        return mini;
    }
};

using vvi=vector<vector<int>>;
class Solution2 {
    int recursion(int i,int n,int m,int x,vvi &dp){
        if(i==n) return x==0;
        if(dp[i][x]!=-1) return dp[i][x];
        int ans=0;
        for(int j=1;j<=m;j++){
            if(x>=j) ans+=recursion(i+1,n,m,x-j,dp);
            else break;
        }
        return dp[i][x]=ans;
    }
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        return recursion(0,n,m,x,dp);
    }
};

int main(){

return 0;
}