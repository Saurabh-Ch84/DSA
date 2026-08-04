#include<bits/stdc++.h>
using namespace std;

class Solution {
    using pis=pair<int,string>;
    using vpis=vector<pis>;
    struct Comp{
        // min-heap according to frequency, if frequency is same, then max-heap according to string.
        bool operator()(const pis &a,const pis &b) const{
            int fA=a.first, fB=b.first;
            if(fA!=fB) return fA>fB;
            string sA=a.second, sB=b.second;
            return sA<sB;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hashMap;
        for(string &word: words)
            hashMap[word]++;
        
        int n=words.size();
        // min-heap like
        priority_queue<pis,vpis,Comp> pq;
        for(auto &p: hashMap){
            string str=p.first;
            int freq=p.second;
            if(pq.size()<k)
                pq.push({freq,str});
            else if(freq<pq.top().first || (freq==pq.top().first && str>pq.top().second))
                continue;
            else{
                pq.pop();
                pq.push({freq,str});
            }
        }
        vector<string> res(k);
        int ptr=k-1;
        while(!pq.empty()){
            res[ptr]=pq.top().second;
            pq.pop();
            ptr--;
        }
        return res;
    }
};

int main(){

return 0;
}