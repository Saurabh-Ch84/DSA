#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int n=s.size(), balance=0, start=-1;
        for(int i=0;i<n;i++){
            if(start==-1) start=i;
            if(s[i]=='(') balance++;
            else balance--;
            if(!balance){
                int end=i, len=(end-1)-(start+1)+1;
                res=res+s.substr(start+1,len);
                start=-1;
            }
        }
        return res;
    }
};

int main(){

return 0;
}