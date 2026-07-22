#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

using pii = pair<int,int> ;

class Solution {
    struct Comp{
        // freq, val
        bool operator()(const pii &a,const pii &b) const{
            // descending order of freq, if same freq then greater number first.
            if(a.first==b.first)
                return a.second>b.second;
            return a.first>b.first;
        }
    };

    void initHashSet(unordered_map<int,int> &freqMap,set<pii,Comp> &hashSet){
        for(auto &p: freqMap){
            int val=p.first,freq=p.second;
            hashSet.insert({freq,val});
        }
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int m=n-k+1;
        
        // val, freq.
        unordered_map<int,int> freqMap;
        for(int i=0;i<k;i++)
            freqMap[nums[i]]++;
        
        set<pii,Comp> hashSet;
        // intialize the hashSet
        initHashSet(freqMap,hashSet);

        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int h=hashSet.size();
            // if size is less than x then consider the complete subArray
            int sz=min(x,h);
            auto itr=hashSet.begin();
            //compute one element
            for(int j=0;j<sz;j++){
                int freq=itr->first,val=itr->second;
                ans[i]+=val*freq;
                itr++;
            }
            
            //slide window.

            //eject last
            int oldVal=nums[i],oldFreq=freqMap[oldVal]--;
            hashSet.erase({oldFreq,oldVal});
            hashSet.insert({oldFreq-1,oldVal});
            
            if(i+k>=n) break;
            //insert latest
            int newVal=nums[i+k],newFreq=freqMap[newVal]++;
            hashSet.erase({newFreq,newVal});
            hashSet.insert({newFreq+1,newVal});
        }

        return ans;
    }
};

int main(){

return 0;
}