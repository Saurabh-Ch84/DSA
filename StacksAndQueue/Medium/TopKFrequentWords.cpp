#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Comp{
        unordered_map<string,int> hashMap;
        Comp(unordered_map<string,int> &m):hashMap(m){}
        bool operator()(const string &a,const string &b){
            int freqA=hashMap[a], freqB=hashMap[b];
            if(freqA!=freqB) return freqA>freqB;
            return a<b;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hashMap;
        for(string &word: words)
            hashMap[word]++;
        sort(words.begin(),words.end(),Comp(hashMap));
        vector<string> res;
        for(string &word: words){
            if(res.size()==k) break;
            if(!res.empty() && word==res.back()) 
                continue;
            res.push_back(word);
        }
        return res;
    }
};

int main(){

return 0;
}