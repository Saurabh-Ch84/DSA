#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(const string &a,const string &b,unordered_map<char,int>& hashMap){
        int left=0,right=0,n=a.length(),m=b.length();
        while(left<n || right<m){
            char a_=(left<n) ? a[left]:'#', b_=(right<m) ? b[right]:'#';
            if(hashMap[a_]<hashMap[b_]) return true;
            if(hashMap[a_]>hashMap[b_]) return false;
            left++,right++;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> hashMap;
        hashMap['#']=0;
        for(int i=0;i<=25;i++)
            hashMap[order[i]]=i+1;
        int n=words.size();
        for(int i=0;i<n-1;i++){
            if(!isValid(words[i],words[i+1],hashMap))
                return false;
        }
        return true;
    }
};

int main(){

return 0;
}