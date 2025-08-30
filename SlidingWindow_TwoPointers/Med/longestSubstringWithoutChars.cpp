#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n<2) return n;
        unordered_map<char,int> hashMap;
        int left=0,right=0,ans=0;
        while(right<n)
        {
            if(hashMap.find(s[right])!=hashMap.end() && left<=hashMap[s[right]]) 
                left=hashMap[s[right]]+1;
            hashMap[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};

int main(){

return 0;
}