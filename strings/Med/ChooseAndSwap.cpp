#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    string chooseSwap(string &s) {
        // code hee
        vvint charArr(26);
        int n=s.size();
        for(int i=0;i<n;i++)
            charArr[s[i]-'a'].push_back(i);
            
        string res=s;
        for(int i=0;i<n;i++){
            if(charArr[s[i]-'a'].empty()) continue;
            bool flag=false;
            for(int j=0;j<s[i]-'a';j++){
                if(!charArr[j].empty()){
                    for(int &k: charArr[j])
                        res[k]=s[i];
                    for(int &k: charArr[s[i]-'a'])
                        res[k]='a'+j;
                    flag=true;
                    break;
                }
            }
            if(flag) break;
            charArr[s[i]-'a'].clear();
        }
        return res;
    }
};

int main(){

return 0;
}