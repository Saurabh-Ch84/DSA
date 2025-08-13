#include<iostream>
#include<vector>
using namespace std;

class BinarySearch{
        public:
    int binarySearchIterative(const vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target) return mid;
            if(arr[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int binarySearchRecursive(vector<int> &arr,int low,int high,int target){
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]>target) return binarySearchRecursive(arr,low,mid-1,target);
        return binarySearchRecursive(arr,mid+1,high,target);
    }

    int lowerBound(const vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int ansIdx=arr.size();
        while (low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                ansIdx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ansIdx;
    }

    int upperBound(const vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int ansIdx=arr.size();
        while (low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>target){
                ansIdx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ansIdx;
    }    

    int floor(const vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while (low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=target){
                ans=arr[mid];
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }    

    int ceil(const vector<int> &arr,int target){
        int low=0,high=arr.size()-1;
        int ans=-1;
        while (low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                ans=arr[mid];
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }    
};

int main() {
    BinarySearch bs;
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    int target = 4;

    cout << "Iterative Binary Search: " << bs.binarySearchIterative(arr, target) << endl;
    cout << "Recursive Binary Search: " << bs.binarySearchRecursive(arr, 0, arr.size()-1, target) << endl;
    cout << "Lower Bound: " << bs.lowerBound(arr, target) << endl;
    cout << "Upper Bound: " << bs.upperBound(arr, target) << endl;

    return 0;
}
