#include<bits/stdc++.h>
using namespace std;

class Solution{
    using vint=vector<int>;
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vint alphabets(26,0);
        string res(n,'#');
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            alphabets[idx]++;
        }
        
        int left=0, right=n-1;
        while(left<=right){
            bool flag=false;
            for(int i=0;i<26;i++){
                if(!alphabets[i]) continue;
                if(left==right && alphabets[i]==1){
                    alphabets[i]--;
                    res[left]=i+'a';
                    left++;
                    right--;
                    flag=true;
                }
                else if(left!=right && alphabets[i]>1){
                    alphabets[i]-=2;
                    res[left]=i+'a';
                    res[right]=i+'a';
                    left++;
                    right--;
                    flag=true;
                }
                if(flag) break;
            }
            if(!flag) return "Invalid Input";
        }
        return res;
    }
};

int main(){

return 0;
}