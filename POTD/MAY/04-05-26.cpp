#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(string &s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
  public:
    int isPallindrome(long long int N) {
        // code here
        string bin;
        while(N){
            if(N&1) bin.push_back('1');
            else bin.push_back('0');
            N=N>>1;
        }
        return check(bin);
    }
};

int main(){

return 0;
}