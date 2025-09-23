#include<iostream>
#include<vector>
using namespace std;

class Solution {

    void mergeSort(int arr[],int left,int right){
        if(left>=right){
            return ;
        }
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    
    void merge(int arr[],int left,int mid,int right){
        int i=left;
        while(i<=mid && arr[i]<0) i++;
        int j=mid+1;
        while(j<=right && arr[j]<0) j++;
        reverse(arr,i,mid);
        reverse(arr,mid+1,j-1);
        reverse(arr,i,j-1);
    }
    
    void reverse(int arr[],int low,int high){
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
  public:
    void Rearrange1(int arr[], int n) {
        // Your code goes here
        mergeSort(arr,0,n-1);
    }

    void Rearrange2(int arr[], int n) {
        // Your code goes here
        vector<int> neg,pos;
        for(int i=0;i<n;i++){
            if(arr[i]<0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }
        
        int left=0,right=0,i=0,m=neg.size();
        
        while(left<m && i<n)
            arr[i++]=neg[left++];
            
        while(right<n-m && i<n)
            arr[i++]=pos[right++];
    }
};

int main(){

return 0;
}