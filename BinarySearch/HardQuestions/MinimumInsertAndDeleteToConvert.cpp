#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(), m=b.size();
        vvint dp(n,vint(m,-1));
        
        bool flag1=false;
        for(int j=0;j<m;j++){
            if(a[0]==b[j]){
                if(flag1) dp[0][j]=dp[0][j-1]+1;
                else{
                    if(j) dp[0][j]=dp[0][j-1]-1;
                    else dp[0][j]=0;
                    flag1=true;
                }
            }
            else{
                if(j) dp[0][j]=dp[0][j-1]+1;
                else dp[0][j]=2;
            }
        }
        
        bool flag2=false;
        for(int i=0;i<n;i++){
            if(a[i]==b[0]){
                if(flag2) dp[i][0]=dp[i-1][0]+1;
                else{
                    if(i) dp[i][0]=dp[i-1][0]-1;
                    else dp[i][0]=0;
                    flag2=true;
                }
            }
            else{
                if(i) dp[i][0]=dp[i-1][0]+1;
                else dp[i][0]=2;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(a[i]!=b[j]) dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                else dp[i][j]=dp[i-1][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};

// Optimal
class Solution2 {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        unordered_set<int> hashSet;
        for(int &ele: b)
            hashSet.insert(ele);
        vector<int> arr;
        for(int &ele: a){
            if(!hashSet.count(ele)) continue;
            auto itr=lower_bound(arr.begin(),arr.end(),ele);
            if(itr==arr.end()) arr.push_back(ele);
            else *itr=ele;
        }
        int n=a.size(), m=b.size();
        int lengthOfLIS=arr.size();
        int lengthOfLCS=lengthOfLIS;
        return (n-lengthOfLCS)+(m-lengthOfLIS);
    }
};

int main(){

return 0;
}