#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    int lowerBound(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ansIdx = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ansIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ansIdx;
    }

    int upperBound(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ansIdx = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                ansIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ansIdx;
    }

public:
    vector<int> find(vector<int>& arr, int x) {
        int first = lowerBound(arr, x);
        int last = upperBound(arr, x) - 1;

        // Check if x is present in the array
        if (first == arr.size() || arr[first] != x)
            return {-1, -1};
        else
            return {first, last};
    }
};


class Solution2 {
    int BS_first(vector<int>& arr, int x){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                if(arr[mid]==x) ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    
    int BS_last(vector<int>& arr, int x){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=x){
                if(arr[mid]==x) ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        
        return ans;
    }
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int firstOccurence=BS_first(arr,x);
        int lastOccurence=BS_last(arr,x);
        return {firstOccurence,lastOccurence};
    }
};

int main(){

return 0;
}