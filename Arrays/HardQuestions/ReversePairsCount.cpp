#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int mergeSort(vector<int> &arr,int low,int high){
        if(low>=high) return 0;

        int mid=(low+high)/2;
        int revPairsCount=0;
        revPairsCount+=mergeSort(arr,low,mid);
        revPairsCount+=mergeSort(arr,mid+1,high);

        int left=low,right=mid+1;
        while(left<=mid){
            while(right<=high && arr[left]>2*arr[right]) right++;
            revPairsCount+=right-(mid+1);
            left++;
        }
        merge(arr,low,mid,high);

        return revPairsCount;  
    }
    
    void merge(vector<int> &arr,int low,int mid,int high){
        vector<int> temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high)
        {
            if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
            
        while(right<=high)
            temp.push_back(arr[right++]);
            
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
    }
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        return mergeSort(arr,0,arr.size()-1);
    }
};

int main(){

return 0;
}