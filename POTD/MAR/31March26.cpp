#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int n,int k,vint &arr,bool canBuy,vvint &dp){
        if(i==n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int buy=-1e8, sell=-1e8;
        if(canBuy){
            int notBuyNow=recursion(i+1,n,k,arr,canBuy,dp);
            int buyNow=recursion(i+1,n,k,arr,!canBuy,dp)-arr[i];
            buy=max(notBuyNow,buyNow);
        }
        else{
            int notSellNow=recursion(i+1,n,k,arr,canBuy,dp);
            int sellNow=recursion(i+1,n,k,arr,!canBuy,dp)+arr[i]-k;
            sell=max(notSellNow,sellNow);
        }
        return dp[i][canBuy]=max(buy,sell);
    }
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        vvint dp(n,vint(2,-1));
        return recursion(0,n,k,arr,1,dp);
    }
};

class Solution2 {
    using vbool=vector<bool>;
public:
    string generateString(string str1, string str2) {
        int n=str1.size(), m=str2.size();
        string word(n+m-1,'#');
        vbool empty(n+m-1,0);

        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=0;j<m;j++){
                    if(word[i+j]!='#' && word[i+j]!=str2[j]) 
                        return "";
                    word[i+j]=str2[j];
                }
            }
        }

        for(int i=0;i<n+m-1;i++){
            if(word[i]=='#'){
                empty[i]=1;
                word[i]='a';
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F' && word.substr(i,m)==str2){
                bool flag=false;
                for(int j=i+m-1;j>=i;j--){
                    if(empty[j]){
                        empty[j]=0;
                        for(char ch='a';ch<='z';ch++){
                            word[j]=ch;
                            if(word.substr(i,m)!=str2) {
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(flag) break;
                }
                if(!flag) return "";
            }
        }
        return word;
    }
};

class Solution {
public:
    bool isSame(string &word, string & str2, int i, int m) {
        for(int j = 0; j < m; j++) {
            if(word[i] != str2[j]) 
                return false;
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N, '$');

        vector<bool> canChange(N, false);

        //Process the 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                   if(word[i+j] != '$' && word[i+j] != str2[j])
                        return "";
                   word[i+j] = str2[j];
                }
            }
        }

        //FIll the remaining spaces with 'a'
        for(int i = 0; i < N; i++) {
            if(word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        //Process the 'F'
        //T.C : O(n * m)
        //S,C : O(N)
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F' && isSame(word, str2, i, m)) {
                bool changed = false;
                for(int k = i + m - 1; k >= i; k--) {
                    if(canChange[k]) {
                        word[k] = 'b';
                        canChange[k]=false;
                        changed = true;
                        break;
                    }
                }
                if(!changed) return "";
            }
        }
        return word;
    }
};

int main(){

return 0;
}