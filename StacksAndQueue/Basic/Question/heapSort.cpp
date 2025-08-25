#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

void print(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

class Solution {
    void heapify(vector<int> &arr,int idx,int n){
        int largest=idx;
        int left=2*idx+1,right=2*idx+2;
        if(left<n && arr[largest]<arr[left]) largest=left;
        if(right<n && arr[largest]<arr[right]) largest=right;
        if(largest!=idx){
            swap(arr[idx],arr[largest]);
            heapify(arr,largest,n);
        }
    }
    
    void buildHeap(vector<int> &arr,int n){
        for(int i=n/2-1;i>=0;i--)
            heapify(arr,i,n);
    }
    
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,0,i);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums={1,6,-9,23,0,11};
    print(nums);
    s.heapSort(nums);
    print(nums);
return 0;
}