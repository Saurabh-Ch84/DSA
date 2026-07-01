#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getLPS(string &pattern){
        int n=pattern.size(), len=0, i=1;
        vector<int> lps(n,0);
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
    bool KMPcheck(string &word,string &pattern){
        vector<int> lps=getLPS(pattern);
        int i=0, j=0, n=word.length(), m=pattern.length();
        while(i<n){
            if(word[i]==pattern[j]){
                i++;
                j++;
                if(j==m) return true;
            }
            else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string &pattern: patterns){
            if(KMPcheck(word,pattern)) count++;
        }
        return count;
    }
};

int main(){

return 0;
}