#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> getLPS(string &pattern){
        int n=pattern.size();
        vector<int> lps(n,0);
        int i=1, len=0;
        while(i<n){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len) len=lps[len-1];
                else i++;
            }
        }
        return lps;
    }
        public:
    int solve(string &text,string &pattern){
        vector<int> lps=getLPS(pattern);
        int i=0, j=0, n=text.size(), m=pattern.size();
        int count=0;
        while(i<n){
            if(text[i]==pattern[j]){
                j++;
                i++;
                if(j==m){
                    count++;
                    j=lps[j-1];
                }
            }
            else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return count;
    }
};


int main(){
    string text, pattern;
    cin>>text;
    cin>>pattern;
    Solution s;
    cout<<s.solve(text,pattern);
return 0;
}