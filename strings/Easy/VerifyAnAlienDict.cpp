#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(const string &wordA,const string &wordB,unordered_map<char,int>& hashMap){
        int n=wordA.length(),m=wordB.length();
        int left=0,right=0;
        while(left<n || right<m){
            char a=(left<n) ? wordA[left++]:'#';
            char b=(right<m) ? wordB[right++]:'#';
            if(hashMap[a]<hashMap[b]) return true;
            if(hashMap[a]>hashMap[b]) return false;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        unordered_map<char,int> hashMap;
        hashMap['#']=0;
        for(int i=0;i<26;i++){
            char letter=order[i];
            hashMap[letter]=i+1;
        }
        for(int i=0;i<n-1;i++){
            if(!isValid(words[i],words[i+1],hashMap))
                return false;
        }
        return true;
    }
};

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