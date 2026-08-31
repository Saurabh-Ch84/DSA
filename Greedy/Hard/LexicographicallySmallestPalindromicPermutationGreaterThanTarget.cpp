#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    string lexPalindromicPermutation(string s, string target) {
        vint letters(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            letters[idx]++;
        }
        char middleChar='#';
        for(int i=0;i<26;i++){
            if(letters[i]%2==1){
                if(middleChar=='#') middleChar='a'+i;
                else return "";
            }
        }
        for(int i=0;i<26;i++)
            letters[i]=letters[i]/2;
        
        int halfLen=n/2;
        bool canFormL=1;
        vint temp=letters;
        for(int i=0;i<halfLen;i++){
            int idx=target[i]-'a';
            if(temp[idx])
                temp[idx]--;
            else{
                canFormL=0;
                break;
            }
        }
        if(canFormL){
            string leftHalf=target.substr(0,halfLen);
            string rightHalf=leftHalf;
            if(middleChar!='#') rightHalf.push_back(middleChar);
            reverse(rightHalf.begin(),rightHalf.end());
            string res=leftHalf+rightHalf;
            if(res>target) return res;           
        }
        
        int i=0, matched=0;
        string leftHalf(halfLen,'#');
        while(i<halfLen){
            int idx=target[i]-'a';
            if(letters[idx]){
                leftHalf[i]=target[i];
                matched++;
                letters[idx]--;
            }
            else break;
            i++;
        }

        i=min(halfLen-1,matched);
        while(i>=0){
            int idx=target[i]-'a';
            if(i<matched) letters[idx]++;
            int nIdx=-1;
            for(int j=idx+1;j<26;j++){
                if(letters[j]){
                    nIdx=j;
                    break;
                }
            }
            if(nIdx!=-1){
                leftHalf[i]='a'+nIdx;
                letters[nIdx]--;
                int k=i+1;
                for(int j=0;j<26;j++){
                    while(letters[j]){
                        leftHalf[k]='a'+j;
                        letters[j]--;
                        k++;
                    }
                }
                string rightHalf=leftHalf;
                if(middleChar!='#') rightHalf.push_back(middleChar);
                reverse(rightHalf.begin(),rightHalf.end());
                string res=leftHalf+rightHalf;
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