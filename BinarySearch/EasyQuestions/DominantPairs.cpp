#include<bits/stdc++.h>
using namespace std;

class Solution {
    int customBinarySearch(vector<int> &arr,int low,int high,int x){
        int ans=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size(), total=0;
        sort(arr.begin(),arr.begin()+n/2);
        for(int j=n/2;j<n;j++){
            int idx=customBinarySearch(arr,0,n/2,arr[j]*5);
            int count=max(0,(n/2-idx));
            total+=count;
        }
        return total;
    }
};

int main(){

return 0;
}