#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int mergeSort(vector<int> &v, int low, int high){
        if (low >= high) return 0;
        int invCount=0;
        int mid = (high + low) / 2;
        invCount+=mergeSort(v, low, mid);
        invCount+=mergeSort(v, mid + 1, high);
        invCount+=merge(v, low, mid, high);
        return invCount;
    }

    int merge(vector<int> &v,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        int invCount=0;
        while(left<=mid && right<=high){
            if(v[left]<=v[right])
                temp.push_back(v[left++]);
            else{
                temp.push_back(v[right++]);
                invCount+=mid-left+1;
            }
        }
        while(left<=mid)
            temp.push_back(v[left++]);
        while(right<=high)
            temp.push_back(v[right++]);
        for(int i=low;i<=high;i++)
            v[i]=temp[i-low];
        return invCount;
    }   
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        return mergeSort(arr,0,n-1);
    }
};

int main(){

return 0;
}