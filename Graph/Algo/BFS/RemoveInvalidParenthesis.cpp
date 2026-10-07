#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValidParenthesis(string &s){
        int balance=0;
        for(const char &parenthesis: s){
            if(parenthesis=='(') balance++;
            else if(parenthesis==')'){
                balance--;
                if(balance<0) return 0;
            }
        }
        return (balance==0);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if(isValidParenthesis(s)){
            // level:0
            res.push_back(s);
            return res;
        }

        queue<string> q;
        q.push(s);
        unordered_set<string> hashSet;
        hashSet.insert(s);
        
        while(!s.empty()){
            // level:1
            int sz=q.size();
            while(sz--){
                string strU=q.front(); q.pop();
                int n=strU.size();
                for(int i=0;i<n;i++){
                    if(strU[i]!='(' && strU[i]!=')') continue;
                    if(i>0 && strU[i]==strU[i-1]) continue;  // optimization.
                    string strV=strU.substr(0,i)+strU.substr(i+1,n-i-1);
                    if(isValidParenthesis(strV) && !hashSet.count(strV)){
                        hashSet.insert(strV);
                        res.push_back(strV);
                        continue;
                    }
                    if(!hashSet.count(strV)){
                        q.push(strV);
                        hashSet.insert(strV);
                    }
                }
            }
            if(!res.empty()) break;
        }
        return res;
    }
};

int main(){

return 0;
}