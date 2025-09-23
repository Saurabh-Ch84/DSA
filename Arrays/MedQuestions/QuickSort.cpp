#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high){
            return ;
        }
        int pIdx=partition(arr,low,high);
        quickSort(arr,low,pIdx-1);
        quickSort(arr,pIdx+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pIdx=low;
        for(int i=low;i<high;i++){
            if(arr[i]<arr[high]){
                swap(arr[i],arr[pIdx]);
                pIdx++;
            }
        }
        swap(arr[high],arr[pIdx]);
        return pIdx;
    }
};

void print(vector<int> arr){
    for(int &num:arr)
        cout<<num<<" ";
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> arr={9,8,3,1,5,3,3,7,3,6};
    print(arr);
    s.quickSort(arr,0,arr.size()-1);
    print(arr);
return 0;
}