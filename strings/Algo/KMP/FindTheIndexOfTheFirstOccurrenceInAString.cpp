#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getLPS(string &pattern){
        int n=pattern.size();
        vector<int> LPS(n,0);
        int i=1, len=0;
        while(i<n){
            if(pattern[i]==pattern[len]){
                len++;
                LPS[i]=len;
                i++;
            }
            else{
                if(len) len=LPS[len-1];
                else i++;
            }
        }
        return LPS;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> LPS=getLPS(needle);
        int n=haystack.size(), m=needle.size(), i=0, j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==m) return i-m;
            }
            else{
                if(j) j=LPS[j-1];
                else i++;
            }
        }
        return -1;
    }
};

int main(){

return 0;
}