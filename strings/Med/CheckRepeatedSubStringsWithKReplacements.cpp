#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n=s.size();
        if(n%k) return false;
        unordered_map<string,int> hashMap;
        int i=0;
        while(i<n){
            hashMap[s.substr(i,k)]++;
            if(hashMap.size()>2) return false;
            i+=k;
        }
        if(hashMap.size()==1) return true;
        for(auto &p: hashMap){
            if(p.second==1) return true;
        }
        return false;
    }
};



int main(){

return 0;
}