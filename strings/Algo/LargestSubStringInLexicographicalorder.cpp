#include<bits/stdc++.h>
using namespace std;

class Solution {
    // brute-force.
    class SuffixArray{
        vector<int> suffixIdxArr;
        const string &s;
        struct SuffixComp{
            const string &s;
            SuffixComp(const string &s):s(s){}
            bool operator()(const int aIdx,const int bIdx) const{
                return string_view(s).substr(aIdx)<string_view(s).substr(bIdx);
            }
        };
            public:
        SuffixArray(const string &s):s(s){
            int n=s.size();
            suffixIdxArr.resize(n);
            for(int i=0;i<n;i++)
                suffixIdxArr[i]=i;
            sort(suffixIdxArr.begin(),suffixIdxArr.end(),SuffixComp(s));    
        }
        string lastSubString(){
            int idx=suffixIdxArr.back();
            return (string)string_view(s).substr(idx);
        }
    };
public:
    string lastSubstring(string s) {
        SuffixArray sa(s);
        return sa.lastSubString();
    }
};

int main(){

return 0;
}