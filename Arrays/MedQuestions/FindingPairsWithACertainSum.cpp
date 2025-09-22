#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
    unordered_map<int,int> hashMap1,hashMap2;
    vector<int> nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2=nums2;
        for(int &num:nums1)
            hashMap1[num]++;
        for(int &num:nums2)
            hashMap2[num]++;
    }
    
    void add(int index, int val) {
        int oldVal=nums2[index];
        hashMap2[oldVal]--;
        if(hashMap2[oldVal]==0)
            hashMap2.erase(oldVal);
        hashMap2[oldVal+val]++;
        nums2[index]+=val;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto &p:hashMap1){
            int x=p.first,xCount=p.second;
            int y=tot-x,yCount=hashMap2[y];
            ans+=xCount*yCount;
        }
        return ans;
    }
};


int main(){

return 0;
}