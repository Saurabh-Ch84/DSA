#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vint letters(26,0);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            letters[idx]++;
        }
        int i=0, matched=0;
        string res(n,' ');
        while(i<n){
            int idx=target[i]-'a';
            if(letters[idx]>0){
                letters[idx]--;
                res[i]=target[i];
                matched++;
            }
            else break;
            i++;
        }
        
        i=min(matched,n-1);
        while(i>=0){
            int idx=target[i]-'a';
            if(i<matched) letters[idx]++;
            int nIdx=-1;
            for(int j=idx+1;j<26;j++){
                if(letters[j]>0){
                    nIdx=j;
                    break;
                }
            }
            if(nIdx!=-1){
                res[i]='a'+nIdx;
                letters[nIdx]--;
                int k=i+1;
                for(int j=0;j<26;j++){
                    while(letters[j]>0){
                        res[k]='a'+j;
                        letters[j]--;
                        k++;
                    }
                }
                return res;
            }
            i--;
        }
        return "";
    }
};

int main(){

return 0;
}