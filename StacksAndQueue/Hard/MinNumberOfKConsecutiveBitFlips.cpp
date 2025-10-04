#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kBitFlips1(vector<int>& arr, int k) {
        // code here
        unordered_set<int> hashSet;
        int n=arr.size(),totalCount=0,count=0;
        
        for(int i=0;i<n;i++){
            if(i>=k && hashSet.count(i-k))
                count--;
            if(count%2==arr[i]){
                if(i+k>n) return -1;
                count++;
                hashSet.insert(i);
                totalCount++;
            }
        }
        return totalCount;
    }
    int kBitFlips2(vector<int>& arr, int k) {
        // code here
        deque<bool> dq;
        int n=arr.size(),totalCount=0,count=0;
        
        for(int i=0;i<n;i++){
            if(i>=k){
                if(dq.front()==true) count--;
                dq.pop_front();
            }
            if(count%2==arr[i]){
                if(i+k>n) return -1;
                count++;
                dq.push_back(true);
                totalCount++;
            }
            else dq.push_back(false);
        }
        return totalCount;
    }
};

int main(){

return 0;
}