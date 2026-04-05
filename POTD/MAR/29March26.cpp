#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_set<string> hashSet;
        queue<string> q;
        q.push(s1);
        hashSet.insert(s1);

        while(!q.empty()){
            string s=q.front(); q.pop();
            if(s==s2) return true;
            for(int i=0;i<2;i++){
                swap(s[i],s[i+2]);
                if(!hashSet.count(s)){
                    q.push(s);
                    hashSet.insert(s);
                }
                swap(s[i],s[i+2]);
            }
        }
        return false;
    }
};

class Solution {
	bool check(char a,char b,char c,char d){
		if(a==c && b==d) return true;
		if(a==d && b==c) return true;
		return false;
	}
public:
    bool canBeEqual(string s1, string s2) {
        return (check(s1[0],s1[2],s2[0],s2[2]) && check(s1[1],s1[3],s2[1],s2[3]));
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int n,int sum,vint &arr,vvint &dp){
        if(i==n) return (sum==0? 1: 0);
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notTake=recursion(i+1,n,sum,arr,dp), take=0;
        if(sum>=arr[i]) take=recursion(i+1,n,sum-arr[i],arr,dp);
        return dp[i][sum]=take+notTake;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size(), total=0;
        for(int i=0;i<n;i++)
            total+=arr[i];
        int sum=total+diff;
        if(sum%2==1) return 0;
        sum=sum/2;
        vvint dp(n+1,vint(sum+1,-1));
        return recursion(0,n,sum,arr,dp);
    }
};

int main(){

return 0;
}