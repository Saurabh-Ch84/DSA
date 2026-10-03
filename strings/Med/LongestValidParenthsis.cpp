#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getMaxGap(vector<int> &st){
        int maxi=0, n=st.size();
        for(int i=0;i<n-1;i++){
            int l=st[i], r=st[i+1];
            maxi=max(maxi,r-l-1);
        }
        return maxi;
    }
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int> st;
        st.push_back(-1);
        for(int i=0;i<n;i++){
            if(s[i]==')' && st.back()!=-1 && s[st.back()]=='(')
                st.pop_back();
            else st.push_back(i);
        }
        st.push_back(n);
        return getMaxGap(st);
    }
};

int main(){

return 0;
}