#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=std::vector<int>;
  public:
    int maxIndexDifference(string &s) {
        // code here
        int n=s.size(), endIdx=-1, startIdx=-1;
        vint dp(26,0);
        for(int i=0;i<n;i++){
            char letter=s[i];
            int idx=letter-'a';
            if(letter=='a' && startIdx!=-1) continue;
            if(letter=='a' || dp[idx-1]){
                if(startIdx==-1) startIdx=i;
                dp[idx]=1;
                endIdx=max(endIdx,i);
            }
        }
        return (startIdx==-1? -1: endIdx-startIdx);
    }
};


int main(){

return 0;
}