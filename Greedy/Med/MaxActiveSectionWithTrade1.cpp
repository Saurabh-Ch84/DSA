#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    int maxActiveSectionsAfterTrade(string s) {
        vint zero;
        int i=0, n=s.size(), count=0, activeSession=0;
        while(i<n){
            if(s[i]=='0') count++;
            else{
                activeSession++;
                if(count){
                    zero.push_back(count);
                    count=0;
                }
            }
            i++;
        }
        if(count) zero.push_back(count);
        int m=zero.size(), maxPairSum=0;
        for(int i=0;i<m-1;i++)
            maxPairSum=max(maxPairSum,zero[i]+zero[i+1]);
        return activeSession+maxPairSum;
    }
};

int main(){

return 0;
}