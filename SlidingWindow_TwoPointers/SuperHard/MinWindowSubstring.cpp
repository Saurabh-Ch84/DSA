#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

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