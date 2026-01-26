#include<iostream>
#include<vector>

using namespace std;
using vi=vector<int> ;
using vvi=vector<vi> ;

class Solution {
    int countAtmostK(string& s, int k){
        int left=0, right=0, n=s.size(), count=0, distinct=0;
        vi freqArr(26,0);
        
        while(right<n){
            char curr=s[right];
            if(freqArr[curr-'a']==0) distinct++;
            freqArr[curr-'a']++;
            
            while(distinct>k){
                char prev=s[left++];
                freqArr[prev-'a']--;
                if(!freqArr[prev-'a'])
                    distinct--;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
  public:
    int countSubstr(string& s, int k) {
        // code here
        return countAtmostK(s,k)-countAtmostK(s,k-1);
    }
};


class Solution {
    int asciiSum(string &s){
        int sum=0;
        for(char ch: s) 
            sum+=(int)ch;
        return sum;
    }
    int asciiSumLCS(int i,int n,int j,int m,string &s1,string &s2,vvi &dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0, notTake=0;
        if(s1[i]==s2[j]) take=(int)s1[i]+asciiSumLCS(i+1,n,j+1,m,s1,s2,dp);
        notTake=max(asciiSumLCS(i+1,n,j,m,s1,s2,dp),
                    asciiSumLCS(i,n,j+1,m,s1,s2,dp));
        return dp[i][j]=max(take,notTake);
    }
public:
    int minimumDeleteSum(string s1, string s2){
        int n=s1.size(), m=s2.size();
        vvi dp(n,vi(m,-1));
        return asciiSum(s1)+asciiSum(s2)-2*asciiSumLCS(0,n,0,m,s1,s2,dp);
    }
};

int main(){

return 0;
}