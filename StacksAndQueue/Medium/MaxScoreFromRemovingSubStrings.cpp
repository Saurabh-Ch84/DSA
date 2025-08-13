#include<iostream>
#include<stack>
using namespace std;

class Solution {
    bool is_a_or_b(char ch){
        if(ch=='a' || ch=='b') return true;
        return false;
    }
    
    int gainFinder(string &s,stack<char> &st,string str,int n,int points){
        int score=0;
        for(int i=0;i<n;i++){
            char letter=s[i];
            if(!st.empty() && is_a_or_b(letter) && is_a_or_b(st.top())){
                char first=st.top();
                string temp="";
                temp+=first;
                temp+=letter;
                if(temp==str){
                    st.pop();
                    score+=points;
                    continue;
                }
            }
            st.push(letter);
        }
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        stack<char> helperStack;
        int maxScore=0;
        if(x>y) maxScore+=gainFinder(s,helperStack,"ab",s.length(),x);
        else maxScore+=gainFinder(s,helperStack,"ba",s.length(),y);
        
        int n=helperStack.size();
        string s1(n,'$');
        for(int i=0;i<n;i++){
            s1[n-i-1]=helperStack.top();
            helperStack.pop();
        }
        
        if(x>y) maxScore+=gainFinder(s1,helperStack,"ba",s1.length(),y);
        else maxScore+=gainFinder(s1,helperStack,"ab",s1.length(),x);
        
        return maxScore;
    }
};

int main(){

return 0;
}