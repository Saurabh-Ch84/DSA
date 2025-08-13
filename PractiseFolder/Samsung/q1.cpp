#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int computeLPS(string &s){
        int n=s.length();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len) len=lps[len-1];
                else i++;
            }
        }
        return lps.back();
    }
  public:
    int minChar(string &s) {
        // code here
        string r=s;
        reverse(r.begin(),r.end());
        string temp=s+'#'+r;
        int palinLen=computeLPS(temp),n=s.length();
        return n-palinLen;
    }
};


int main(){

return 0;
}