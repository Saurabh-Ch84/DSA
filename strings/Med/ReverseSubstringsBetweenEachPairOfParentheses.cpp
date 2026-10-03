#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n=s.size(), i=0;
        while(i<n){
            // simulate bracket solving.
            if(s[i]=='('){
                st.push("(");
                i++;
            }
            else if(s[i]==')'){
                string token;
                while(st.top()!="("){
                    string temp=st.top(); st.pop();
                    reverse(temp.begin(),temp.end());
                    token+=temp;
                }
                if(st.top()=="(") st.pop();
                st.push(token);
                i++;
            }
            else{
                string token;
                while(i<n && s[i]!='(' && s[i]!=')'){
                    token.push_back(s[i]);
                    i++;
                }
                st.push(token);
            }
        }
        // answer formation
        string res;
        while(!st.empty()){
            string temp=st.top(); st.pop();
            reverse(temp.begin(),temp.end());
            res+=temp;
        }
        // FIFO order.
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

return 0;
}