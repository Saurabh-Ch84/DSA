#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int> ;
class Solution {
    struct Comp{
          bool operator()(const pii &a,const pii &b) const{
              if(a.second==b.second) return a.first > b.first;
              return a.second > b.second;
          }
    };
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> freqMap;
        set<pii,Comp> hashSet;
        
        for(int &ele: arr){
            if(hashSet.count({ele,freqMap[ele]}))
                hashSet.erase({ele,freqMap[ele]});  
            hashSet.insert({ele,++freqMap[ele]});
        }
        
        vector<int> res;
        for(auto &p: hashSet){
            int ele=p.first;
            res.push_back(ele);
            if(res.size()==k) break;
        }
        
        return res;
    }
};


int main(){

return 0;
}