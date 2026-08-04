#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using pii=pair<int,int>;
    using vpii=vector<pii>;
public:
    int minimumPushes(string word) {
        int n=word.size();
        vpii alphabet(26,{0,-1});
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            alphabet[idx].first++;
            alphabet[idx].second=idx;
        }
        sort(alphabet.rbegin(),alphabet.rend());
        
        vint letter(26,0);
        int pushes=0, press=1, count=0;
        for(int i=0;i<26;i++){
            int characterIdx=alphabet[i].second;
            if(characterIdx==-1) break;
            int freq=alphabet[i].first;
            if(!letter[characterIdx]){
                letter[characterIdx]=press;
                count++;
                if(count%8==0) press++;
            }
            pushes+=letter[characterIdx]*freq;
        }
        return pushes;
    }
};

int main(){

return 0;
}