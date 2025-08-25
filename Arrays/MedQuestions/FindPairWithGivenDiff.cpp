#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool findPairUsingHashMap(vector<int> &arr,int x,int n){
        unordered_set<int> hashSet;
        for(int i=0;i<n;i++){
            int val=arr[i];
            if(hashSet.count(val+x) || hashSet.count(val-x)) return true;
            hashSet.insert(val);
        }
        return false;
    }
    
    bool findPairUsingTwoPointers(vector<int> &arr,int x,int n){
        sort(arr.begin(),arr.end());
        int left=0,right=1;
        while(right<n){
            int diff=arr[right]-arr[left];
            if(diff==x) return true;
            else if(diff<x) right++;
            else{
                left++;
                if(left==right) right++;
            }
        }
        return false;
    }
    
  public:
    bool findPair(vector<int> &arr, int x,bool useMap=true) {
        // code here
        int n=arr.size();
        return (useMap)?findPairUsingHashMap(arr,x,n):findPairUsingTwoPointers(arr,x,n);
    }
};

int main(){
    Solution s;

    // Test Case 1: Pair exists
    vector<int> arr1 = {1, 8, 30, 40, 100};
    int x1 = 10;
    // Expected: true (30, 40)

    // Test Case 2: No pair exists  
    vector<int> arr2 = {1, 2, 3, 4};
    int x2 = 10;
    // Expected: false

    // Test Case 3: Edge case - same element
    vector<int> arr3 = {5, 5, 5};
    int x3 = 0;
    // Expected: true (5, 5)

    // Test Case 4: Negative numbers
    vector<int> arr4 = {-1, 0, 1, 2};
    int x4 = 3;  
    // Expected: true (-1, 2)

    cout<<s.findPair(arr1,x1,false)<<endl;
    cout<<s.findPair(arr2,x2,false)<<endl;
    cout<<s.findPair(arr3,x3)<<endl;
    cout<<s.findPair(arr4,x4,true)<<endl;
return 0;
}