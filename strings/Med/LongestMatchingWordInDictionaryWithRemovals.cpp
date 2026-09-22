#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n=s.size(), m=d.size();
        vector<vector<int>> nextIdx(n,vector<int>(26,-1));
        nextIdx[n-1][s[n-1]-'a']=n-1;
        
        for(int i=n-2;i>=0;i--){
            nextIdx[i]=nextIdx[i+1];
            nextIdx[i][s[i]-'a']=i;
        }
        
        int ansIdx=-1;
        for(int i=0;i<m;i++){
            string &word=d[i];
            int j=0, k=0, sz=word.size();
            while(k<sz && j<n && nextIdx[j][word[k]-'a']!=-1){
                j=nextIdx[j][word[k]-'a']+1;
                k++;
            }
            if(k==sz && (ansIdx==-1 || sz>d[ansIdx].size() || (sz==d[ansIdx].size() && word<d[ansIdx])))
                ansIdx=i;
        }
        return (ansIdx==-1? "":d[ansIdx]);
    }
};

int main(){

return 0;
}