#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSorted(string &s,int n){
        int i=1;
        while(i<n){
            if(s[i]<s[i-1]) return 0;
            i++;
        }
        return 1;
    }
public:
    int minOperations(string s) {
        int n=s.size(); 
        if(isSorted(s,n)) return 0;
        if(n==2) return -1;

        char miniChar=*min_element(s.begin(),s.end());
        char maxiChar=*max_element(s.begin(),s.end());
        if(s[0]==miniChar || s[n-1]==maxiChar) return 1;

        char maxMid=*max_element(s.begin()+1,s.end()-1);
        char minMid=*min_element(s.begin()+1,s.end()-1);
        if(s[0]>maxMid && s[n-1]<minMid) return 3;
        return 2;
    }
};

int main(){

return 0;
}