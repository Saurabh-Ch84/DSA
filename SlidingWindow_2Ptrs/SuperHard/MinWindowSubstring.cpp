#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(m>n) return "";
        unordered_map<int,int> hashMap;
        int countRequired=m;
        for(char letter: t)
            hashMap[letter]++;
        
        int left=0, right=0;
        int start=-1, minLen=n+1;
        while(right<n){
            char curr=s[right];
            if(hashMap[curr]>0)
                countRequired--;
            hashMap[curr]--;
            while(countRequired==0){
                int len=right-left+1;
                if(len<minLen){
                    start=left;
                    minLen=len;
                }
                char last=s[left++];
                hashMap[last]++;
                if(hashMap[last]>0) 
                    countRequired++;
            }
            right++;
        }
        return (start==-1? "" : s.substr(start,minLen));
    }
};

class Solution1 {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        if(m>n) return "";
        int left=0,right=0,idx=-1,minLen=1e9;
        unordered_map<char,int> customMap;
        for(char &letter:t)
            customMap[letter]++;
        int count=0;
        while(right<n){
            if(customMap[s[right]]>0) count++;
            customMap[s[right]]--;
            while(count==m){
                int windowLength=right-left+1;
                if(minLen>windowLength){
                    minLen=windowLength;
                    idx=left;
                }
                customMap[s[left]]++;
                if(customMap[s[left]]>0) count--;
                left++;
            }
            right++;
        }
        return minLen == 1e9 ? "" : s.substr(idx, minLen);
    }
};

class Solution2 {
public:
    string minWindow(string s, string t) {
        int minLen=INT_MAX,st=-1;
        unordered_map<char,int> hashMapT;
        for(char ch: t) hashMapT[ch]++;

        int n=s.length(),left=0,right=0,count=0,m=hashMapT.size();
        unordered_map<char,int> hashMapS;
        while(right<n){
            hashMapS[s[right]]++;
            if(hashMapS[s[right]]==hashMapT[s[right]])
                count++;
            while(count>=m && left<=right){
                int windLen=right-left+1;
                if(minLen>windLen){
                    st=left;
                    minLen=windLen;
                }
                if(hashMapS[s[left]]==hashMapT[s[left]]) 
                    count--;
                hashMapS[s[left]]--;
                left++;
            }
            right++;
        }
        return (st==-1) ? "": s.substr(st,minLen);
    }
};

int main(){

return 0;
}