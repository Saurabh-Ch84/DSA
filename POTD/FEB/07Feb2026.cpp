#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// simpler version-Gemini
class Solution0{
public:
    int maxSum(vector<int> &arr) {
        // code her
        int n = arr.size();
        long long sum = 0, currS = 0;

        // 1. Calculate Total Sum and Initial Rotation Sum
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            currS += i * arr[i];
        }

        long long maxi = currS;
        for (int i = 1; i < n; i++) {
            // Formula: Previous Val - Total Sum + (n * Element that just shifted to end)
            currS = currS - sum + (n * arr[i-1]);
            maxi = max(maxi, currS);
        }
        return (int)maxi;
    }
}; 

class Solution1{
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxi=0,currS=-1,leftS=0,rightS=0,prev=0;
        for(int &num: arr) 
            rightS+=num;
        for(int i=0;i<n;i++){
            if(!i){
                currS=0;
                for(int j=0;j<n;j++)
                    currS+=j*arr[j];
            }
            else currS=currS-(rightS-leftS-prev)-leftS+arr[i-1]*(n-1);
            maxi=max(maxi,currS);
            leftS+=prev;
            prev=arr[i];
        }
        return maxi;
    }
};


// brute-force
using memo_t1= unordered_map<int,unordered_map<int,int>> ;
using memo_t2= vector<unordered_map<int,int>> ;
class Solution {
    const int inf=1e7;
    int recursion(int i,int n,string &s,int b,memo_t2 &memo){
        if(i>=n) return 0;
        if(memo[i].count(b)) return memo[i][b];
        if(s[i]=='b' || (s[i]=='a' && !b)){
            if(s[i]=='b') b++;
            int delNot=recursion(i+1,n,s,b,memo);
            return memo[i][b]=delNot;
        }
        else{
            int delPrevB=inf, delCurrA=inf;
            delPrevB=b+recursion(i+1,n,s,0,memo);
            delCurrA=1+recursion(i+1,n,s,b,memo);
            return  memo[i][b]=min(delPrevB,delCurrA);
        }
        return -1; //dummy-return
    }
public:
    int minimumDeletions(string s){
        int n=s.size();
        // memo_t1 memo;
        memo_t2 memo(n);
        return recursion(0,n,s,0,memo);
    }
};

//optimal greedy
class Solution {
public:
    int minimumDeletions(string s) {
        int dp=0, b=0;
        for(char ch: s){
            if(ch=='b') b++;
            else dp=min(dp+1,b);
        }
        return dp;
    }
};

int main(){

return 0;
}