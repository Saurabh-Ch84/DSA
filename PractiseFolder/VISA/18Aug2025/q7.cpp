#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Find the Nth biggest number in an array.
*/

class Solution{
    int partition(vector<int> &nums,int left,int right,int pivot_index){
        int pivotElement=nums[pivot_index];
        swap(nums[pivot_index],nums[right]);
        int storedIndex=left;
        for(int i=left;i<right;i++){
            if(nums[i]<pivotElement){
                swap(nums[i],nums[storedIndex]);
                storedIndex++;
            }
        }
        swap(nums[right],nums[storedIndex]);
        return storedIndex;
    }
        public:
    //Brute Force    
    int findKthLargestElement1(vector<int> nums,int k){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
    //Better
    int findKthLargestElement2(vector<int> nums,int k){
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.begin()+k);
        for(int i=k;i<n;i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    //optimal
    int findKthLargestElement3(vector<int> nums,int k){
        int n=nums.size();
        int left=0,right=n-1;
        while(true){
            int pivot_index=rand()%(right-left+1)+left;
            int new_pivot_index=partition(nums,left,right,pivot_index);
            if(new_pivot_index==n-k){
                return nums[new_pivot_index];
            }
            else if(new_pivot_index > n-k)
                right=new_pivot_index-1;
            else left=new_pivot_index+1;
        }
        return -1; //dummy return 
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,27,0,3,5,11};
    int k1=3;
    cout<<s.findKthLargestElement1(nums1,k1)<<endl;
    cout<<s.findKthLargestElement2(nums1,k1)<<endl;
    cout<<s.findKthLargestElement3(nums1,k1)<<endl;
return 0;
}