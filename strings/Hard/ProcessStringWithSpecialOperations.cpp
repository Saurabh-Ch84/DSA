#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        long long l=0;
        for(const char &ch: s){
            if(ch=='*'){
                if(l) l--;
            }
            else if(ch=='#') l=l*2;
            else if(ch>='a' && ch<='z') l++;
        }
        if(k>=l) return '.';
        int n=s.size(), i=n-1;
        while(i>=0){
            char ch=s[i];
            if(ch=='*') l++;
            else if(ch=='#'){
                l=l/2;
                if(k>=l) k=k-l;
            }
            else if(ch>='a' && ch<='z') l--;
            else k=l-k-1;
            if(l==k) return s[i];
            i--;
        }
        return '.';
    }
};

int main(){

return 0;
}