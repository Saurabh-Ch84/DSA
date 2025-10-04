#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sz=s.length(),n=words.size(),wordLen=words[0].length();
        int totalLen=n*wordLen;

        unordered_map<string,int> freqMap;
        for(const string &word:words)
            freqMap[word]++;
        
        vector<int> res;
        for(int i=0;i<wordLen;i++)
        {
            int ptr=i;
            while(ptr+totalLen<=sz)
            {
                unordered_map<string,int> currMap=freqMap;
                bool matched=true;
                for(int j=0;j<n;j++)
                {
                    string str=s.substr(ptr+j*wordLen,wordLen);
                    if(currMap.count(str)==0 || currMap[str]==0){
                        matched=false;
                        break;
                    }
                    currMap[str]--;
                }
                if(matched) 
                    res.push_back(ptr);
                ptr+=wordLen;
            }
        }
        return res;
    }
};

int main(){

return 0;
}