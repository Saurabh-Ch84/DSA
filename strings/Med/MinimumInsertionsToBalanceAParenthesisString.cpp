#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int operations=0, balance=0, n=s.size(), i=0;
        while(i<n){
            if(s[i]==')'){
                if(balance) balance--;
                else operations++;
                if(i==n-1 || s[i+1]!=')'){
                    operations++;
                    i+=1;
                }
                else i+=2;
            }
            else{
                balance++;
                i+=1;
            }
        }
        return operations+balance*2;
    }
};

int main(){

return 0;
}