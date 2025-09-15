#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath1(string path) {
        stringstream ss(path);
        string token;
        stack<string> s;
        while(getline(ss,token,'/')){
            if(token=="." || token.empty()) continue;
            else if(token==".." ){
                if(s.empty()) continue;
                s.pop();
            }
            else s.push(token);
        }

        if(s.empty()) return "/";
        string res;
        while(!s.empty()){
            res='/'+s.top()+res;
            s.pop();
        }
        return res;
    }

    string simplifyPath2(string path) {
        stringstream ss(path);
        string token;
        vector<string> temp;
        while(getline(ss,token,'/')){
            if(token=="." || token.empty()) continue;
            else if(token==".." ){
                if(temp.empty()) continue;
                temp.pop_back();
            }
            else temp.push_back(token);
        }

        if(temp.empty()) return "/";
        string res;
        for(string &str:temp)
            res+='/'+str;
        
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.simplifyPath1("/C//OneDrive/Desktop//./Coding/../DSA//.../");
return 0;
}