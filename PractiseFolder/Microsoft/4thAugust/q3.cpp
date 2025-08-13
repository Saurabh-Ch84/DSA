#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int merge(vector<int> &arr,int low,int mid,int high){
        int invCount=0,left=low,right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right++]);
                invCount+=mid-left+1;
            }
            else temp.push_back(arr[left++]);
        }
        while(left<=mid) temp.push_back(arr[left++]);
        while(right<=high) temp.push_back(arr[right++]);
        int size=temp.size();
        for(int i=0;i<size;i++){
            arr[low+i]=temp[i];
        }
        return invCount;
    }

    int mergeSort(vector<int> &arr,int low,int high){
        if(low>=high) return 0;
        int mid=(low+high)/2;
        int invCount=0;
        invCount+=mergeSort(arr,low,mid);
        invCount+=mergeSort(arr,mid+1,high);
        invCount+=merge(arr,low,mid,high);
        return invCount;
    }
    class SegmentTree{
        vector<int> segTree;
            public:
        SegmentTree(int n,vector<int> arr){
            segTree.resize(4*n,0);
        }
        // void build()
    };
        public:
    int numberOfInversions(vector<int> &nums){
        return mergeSort(nums,0,nums.size()-1);
    }
};

int main(){
    vector<int> nums1={1,2,3,6,7,4};
    Solution s;
    cout<<s.numberOfInversions(nums1);
return 0;
}