#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isPalindrome(const string& str,int st,int end,vector<vector<int>> &dp){
        if(dp[st][end]!=-1) return dp[st][end];
        int l=st,r=end;
        while(l<r){
            if(str[l]!=str[r]) return dp[st][end]=false;
            l++;
            r--;
        }
        return dp[st][end]=true;
    }

    void recursion(string &s,vector<vector<string>> &res,vector<string> &path,int indx,vector<vector<int>> &dp){
        if(indx==s.length()){
            res.push_back(path);
            return ;
        }
        for(int i=indx;i<s.size();i++){
            if(isPalindrome(s,indx,i,dp)){
                path.push_back(s.substr(indx,i-indx+1));
                recursion(s,res,path,i+1,dp);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        recursion(s,res,path,0,dp);
        return res;
    }
};

int main(){

return 0;
}