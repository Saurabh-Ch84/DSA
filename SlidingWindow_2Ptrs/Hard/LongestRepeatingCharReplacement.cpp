#include<iostream>
#include<vector>
#include<unordered_map>
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

class Solution2 {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(),maxf=0,maxlen=0;
        int left=0,right=0;
        unordered_map<char,int> freqMap;

        while(right<n){ 
            freqMap[s[right]]++;
            maxf=max(maxf,freqMap[s[right]]);
            int ops=(right-left+1)-maxf;
            if(ops>k){
                freqMap[s[left]]--;
                left++;
            }
            else maxlen=max(maxlen,right-left+1);
            right++;
        }

        return maxlen;
    }
};

int main(){

return 0;
}