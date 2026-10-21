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
    void solve(string &pattern){
        vector<int> lps=getLPS(pattern);
        int m=pattern.size(), j=lps[m-1];
        vector<int> prefixSuffixLengths;
        while(j){
            prefixSuffixLengths.push_back(j);
            j=lps[j-1];
        }
        sort(prefixSuffixLengths.begin(),prefixSuffixLengths.end());
        for(auto &prefixSuffixLength: prefixSuffixLengths){
            cout<<prefixSuffixLength<<" ";
        }
    }
};


int main(){
    string pattern;
    cin>>pattern;
    Solution s;
    s.solve(pattern);
return 0;
}