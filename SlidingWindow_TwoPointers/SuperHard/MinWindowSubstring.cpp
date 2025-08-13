#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
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

int main(){

return 0;
}