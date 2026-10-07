#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int totalScore=0, n=s.size(), depth=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                depth--;
                if(s[i-1] == '(')
                    totalScore+=(1<<depth);
            }
            else depth++;
        }
        return totalScore;
    }
};

int main(){

return 0;
}