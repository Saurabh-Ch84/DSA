#include<bits/stdc++.h>
using namespace std;

class Solution {
    int customBinarySearch(vector<int> &arr,int low,int high,int x,int k){
        int idx=low-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]-x<k){
                idx=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return idx;
    }
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size(), count=0;
        for(int i=0;i<n;i++){
            int j=customBinarySearch(arr,i+1,n-1,arr[i],k);
            count+=j-i;
        }
        return count;
    }
};

int main(){

return 0;
}