#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.size(), m=roll.size();
        vector<int> diffArr(n+1,0);
        for(int i=0;i<m;i++){
            int idx=roll[i];
            diffArr[0]+=1;
            diffArr[idx]-=1;
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum=currSum+diffArr[i];
            s[i]='a'+(s[i]-'a'+currSum)%26;
        }
        return s;
    }
};


int main(){

return 0;
}