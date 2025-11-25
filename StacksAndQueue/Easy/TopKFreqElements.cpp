#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using pii = pair<int,int> ;

class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        set<pair<int,int>> set_;
        for(int &num: nums)
        {
            int oldFreq=hashMap[num]++;
            set_.erase({oldFreq,num});
            set_.insert({hashMap[num],num});
        }
        vector<int> res;
        set<pair<int,int>>::reverse_iterator itr=set_.rbegin();
        while(k)
        {
            int val=itr->second;
            res.push_back(val);
            itr++;
            k--;
        }   
        return res;
    }
};

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int &num: nums)
            hashMap[num]++;
        
        priority_queue<pii,vector<pii>> pq;
        for(auto &p: hashMap)
            pq.push({p.second,p.first});

        vector<int> res;
        while(k){
            auto p=pq.top();pq.pop();
            res.push_back(p.second);
            k--;
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int &num: nums)
            hashMap[num]++;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto &p: hashMap){
            int val=p.first,freq=p.second;
            if(pq.size()<k)
                pq.push({freq,val});
            else
            {
                auto q=pq.top();
                int val_=q.second,freq_=q.first;
                if(freq_<freq)
                {
                    pq.pop();
                    pq.push({freq,val});
                }
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            int val=pq.top().second;pq.pop();
            res.push_back(val);
        }

        return res;
    }
};

int main(){

return 0;
}