#include<iostream>
#include<vector>
using namespace std;

//Striver's version
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,n=s.length(),maxLen=0,maxFreq=0;
        vector<int> hashArr(26,0);
        while(right<n){
            hashArr[s[right]-'A']++;
            maxFreq=max(maxFreq,hashArr[s[right]-'A']);
            int operations=(right-left+1)-maxFreq;
            if(operations>k)
            {
                hashArr[s[left]-'A']--;
                left++;
            }
            else maxLen=max(maxLen,operations+maxFreq);
            right++;
        }
        return maxLen;
    }
};

int main(){

return 0;
}