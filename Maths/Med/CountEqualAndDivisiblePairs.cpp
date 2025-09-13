#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a,int b){
        while(b){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

public:
    
    //optimal
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<n;i++)
            hashMap[nums[i]].push_back(i);

        int count=0;
        for(auto &itr:hashMap){
            unordered_map<int,int> gcdCount;
            for(int &i:itr.second){
                int gi=gcd(k,i);
                for(auto &itr_:gcdCount){
                    int freq=itr_.second;
                    int gj=itr_.first;
                    if((gi*gj) % k==0)
                        count+=freq;
                }
                gcdCount[gi]++;
            }
        }
        return count;
    }

    int countPairsBrute(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    if((i*j)%k==0)
                        count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,9,5,3,3,5,3,6};
    cout<<s.countPairs(nums,3);
return 0;
}