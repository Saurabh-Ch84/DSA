#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0,high=arr.size()-1;
        int minIndx=0,minNum=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[high]){
                if(minNum>arr[low]){
                    minIndx=low;
                    minNum=arr[low];
                }
                break;
            }
            else if(arr[low]<=arr[mid]){
                if(minNum>arr[low]){
                    minNum=arr[low];
                    minIndx=low;
                }
                low=mid+1;
            }
            else{
                if(minNum>arr[mid]){
                    minNum=arr[mid];
                    minIndx=mid;
                }
                high=mid-1;
            }
        }
        return minIndx;
    }
};


int main(){

return 0;
}