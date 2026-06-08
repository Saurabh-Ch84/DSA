#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    int numberOfSpecialChars(string word){
        int n=word.size();
        vint small(26,-1), capital(26,-1);
        for(int i=0;i<n;i++){
            char letter=word[i];
            if(letter>='a' && letter<='z')
                small[letter-'a']=i;
            else if(capital[letter-'A']==-1) 
                capital[letter-'A']=i;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(small[i]!=-1 && capital[i]!=-1 && small[i]<capital[i]){
                count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}