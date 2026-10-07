#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance=0, moves=0, n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') balance++;
            else{
                if(!balance) moves++;
                else balance--;
            }
        }
        return moves+abs(balance);
    }
};

int main(){

return 0;
}