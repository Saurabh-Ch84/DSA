#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getBeauty(vector<int> &alphabets){
        int mini=1e9, maxi=-1e9;
        for(int i=0;i<26;i++){
            if(!alphabets[i]) continue;
            mini=min(mini,alphabets[i]);
            maxi=max(maxi,alphabets[i]); 
        }
        return (maxi-mini);
    }
  public:
    int beautySum(string &s) {
        // code here
        int n=s.size(), sum=0;
        for(int i=0;i<n-1;i++){
            vector<int> alphabets(26,0);
            alphabets[s[i]-'a']++;
            for(int j=i+1;j<n;j++){
                int letter=s[j]-'a';
                alphabets[letter]++;
                sum=sum+getBeauty(alphabets);
            }
        }
        return sum;
    }
};

int main(){

return 0;
}