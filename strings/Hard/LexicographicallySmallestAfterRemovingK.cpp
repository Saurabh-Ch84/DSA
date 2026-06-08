#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.length();
        if(n&(n-1)) k=k*2;
        else k=k/2;
        
        if(k>=n) return "-1";
        if(!k) return s;
        string str;
        for(int i=0;i<n;i++){
            while(!str.empty() && str.back()>s[i] && k){
                str.pop_back();
                k--;
            }
            str.push_back(s[i]);
        }
        while(k){
            str.pop_back();
            k--;
        }
        return str;
    }
};

int main(){

return 0;
}