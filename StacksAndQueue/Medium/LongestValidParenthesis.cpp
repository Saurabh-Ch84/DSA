#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]==')' && st.size()>1 && s[st.top()]=='(') st.pop();
            else st.push(i);
        }
        st.push(n);
        int maxi=0;
        while(st.size()>1){
            int ub=st.top();st.pop();
            int lb=st.top();
            int len=ub-lb-1;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};

int main(){

return 0;
}