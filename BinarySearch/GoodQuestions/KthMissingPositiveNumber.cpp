#include<iostream>
#include<vector>
using namespace std;

// Binary Search Approach
class Solution1 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int miss=arr[mid]-(mid+1);
            if(miss<k) low=mid+1;
            else high=mid-1;
        }
        // return k+high+1;
        return low+k;
    }
};

//Linear Search Approach
class Solution2 {
public:
    //My Version
    int findKthPositive1(vector<int>& arr, int k) {
        int lastNum=0,n=arr.size();
        for(int i=0;i<n;i++){
            int miss=arr[i]-(lastNum+1);
            if(miss>=k) return lastNum+k;
            k-=miss;
            lastNum=arr[i];
        }
        return arr.back()+k;
    }
    //Striver's version
    int findKthPositive2(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
    }
};

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n=arr.size(), low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k) low=mid+1;
            else high=mid-1;
        }
        int ans=low+k;                
        return ans;
    }
};

int main(){

return 0;
}