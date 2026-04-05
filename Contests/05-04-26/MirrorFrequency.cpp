#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    char getMirrorChar(char c){
        if(c>='0' && c<='9'){
            int d=c-'0';
            return '9'-d;
        }
        int d=c-'a';
        return 'z'-d;
    }
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> freqMap;
        for(const char &ch: s)
            freqMap[ch]++;
        int sum=0;
        for(auto &p: freqMap){
            char c=p.first;
            char m=getMirrorChar(c);
            sum+=abs(p.second-freqMap[m]);
            freqMap.erase(m);
        }
        return sum;
    }
};

int main(){

return 0;
}