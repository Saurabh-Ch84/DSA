#include<iostream>
#include<vector>
using namespace std;
using vb = vector<bool> ;
using vvb = vector<vector<bool>> ;

class Solution {
    bool recursion(int i,int j,int n,int m,string &txt,string &pat){
        if(i>=n){
            for(int k=j;k<m;k++){
                if(pat[k]!='*') 
                    return false;
            }
            return true;
        }
        if(j>=m) return false;
        char t=txt[i],p=pat[j];
        bool ans=false;
        if(t==p || p=='?'){
            ans=recursion(i+1,j+1,n,m,txt,pat);
        }
        else if(p=='*'){
            bool matchZero=recursion(i,j+1,n,m,txt,pat);
            bool matchOneOrMore=recursion(i+1,j,n,m,txt,pat);
            ans=matchZero | matchOneOrMore;
        }
        return ans;
    }
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=txt.length(),m=pat.length();
        // return recursion(0,0,n,m,txt,pat);
        
        vvb dp(n+1,vb(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            char ch=pat[j-1];
            if(ch=='*' && dp[0][j-1]) dp[0][j]=true;
        }
        
        for(int i=1;i<=n;i++){
            char t=txt[i-1];
            for(int j=1;j<=m;j++){
                char p=pat[j-1];
                if(p=='?' || p==t) dp[i][j]=dp[i-1][j-1];
                else if(p=='*'){
                    bool left=dp[i][j-1],top=dp[i-1][j];
                    dp[i][j]=left|top;
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }

    bool wildCardOptimal(string &txt, string &pat) {
        // code here
        int n=txt.length(),m=pat.length();
        vb dp(m+1,false);
        dp[0]=true;
        for(int j=1;j<=m;j++){
            char ch=pat[j-1];
            if(ch=='*' && dp[j-1]) dp[j]=true;
        }
        
        for(int i=1;i<=n;i++){
            char t=txt[i-1];
            vb temp(m+1,false);
            for(int j=1;j<=m;j++){
                char p=pat[j-1];
                if(p=='?' || p==t) temp[j]=dp[j-1];
                else if(p=='*'){
                    bool left=temp[j-1],top=dp[j];
                    temp[j]=left|top;
                }
                else temp[j]=false;
            }
            dp=temp;
        }
        return dp[m];
    }
};

int main(){

return 0;
}