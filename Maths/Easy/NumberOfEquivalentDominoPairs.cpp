#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int hash(vector<int>& domino){
        return domino[0]*10+domino[1];
    }

    int findLastIndexOf(vector<int>& arr,int low,int high,int target){
        int lastIdx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                lastIdx=mid;
                low=mid+1;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else high=mid-1;
        }
        return lastIdx;
    }
public:
    int numEquivDominoPairs1(vector<vector<int>>& dominoes) {
        vector<int> arr;
        for(vector<int>& domino:dominoes){
            sort(domino.begin(),domino.end());
            int key=hash(domino);
            arr.push_back(key);
        }
        sort(begin(arr),end(arr));
        int n=arr.size(),count=0;
        for(int i=0;i<n;i++){
            int target=arr[i];
            int j=findLastIndexOf(arr,i+1,n-1,target);
            if(j==-1) continue;
            count+=j-i;
        }
        return count;
    }

    int numEquivDominoPairs2(vector<vector<int>>& dominoes) {
        unordered_map<int,int> hashMap;
        for(vector<int> &domino:dominoes){
            sort(begin(domino),end(domino));
            int key=hash(domino);
            hashMap[key]++;
        }
        int count=0;
        for(auto &p:hashMap){
            int temp=((p.second)*(p.second-1))/2;
            count+=temp;
        }
        return count;
    }
};

int main(){

return 0;
}