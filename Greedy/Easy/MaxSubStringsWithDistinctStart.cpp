#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> alphabets(26,0);
        int n=s.size(), count=0;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(!alphabets[idx]){
                alphabets[idx]=1;
                count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}