#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
    bool isOpenBracket(char bracket){
        return (bracket=='{' || bracket=='(' || bracket=='[');
    }
public:
    bool isValid(string s) {
        int n=s.length();
        if(n&1) return false;
        unordered_map<char,char> hashMap;
        hashMap['}']='{';
        hashMap[']']='[';
        hashMap[')']='(';

        stack<char> st;
        for(char bracket: s){
            if(isOpenBracket(bracket)) 
                st.push(bracket);
            else{
                if(st.empty() || hashMap[bracket]!=st.top())
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){

return 0;
}