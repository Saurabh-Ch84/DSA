#include<iostream>
using namespace std;

/*
    Given two integer arrays of the same length, arr[] and index[], 
    the task is to reorder the elements in arr[] such that after reordering, 
    each element from arr[i] moves to the position index[i]. 
    The new arrangement reflects the values being placed at their target 
    indices, as described by index[] array.

    Example: 

    Input: arr[] = [10, 11, 12], index[] = [1, 0, 2]
    Output: 11 10 12
    Explanation: 10 moves to position 1, 11 to 0, and 12 stays at 2.

    Input: arr[] = [1, 2, 3, 4], index[] = [3, 2, 0, 1]
    Output: 3 4 2 1
    Explanation: 1 moves to 3, 2 to 2, 3 to 0, 4 to 1.

    Input: arr[] = [50, 40, 70, 60, 90], index[] = [3,  0,  4,  1,  2]
    Output: 40 60 90 50 70
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

class Solution{
        public:
    void qBrute(int arr[],int index[],int n){
        print(arr,n);
        int arr_[n]={0};
        for(int i=0;i<n;i++) 
            arr_[i]=arr[i];

        for(int i=0;i<n;i++){
            int i_=index[i];
            arr[i_]=arr_[i];
        }
        print(arr,n);
    }
};


int main(){
    Solution s;
    int arr[]={50, 40, 70, 60, 90};
    int index[]={3,  0,  4,  1,  2};
    int n=sizeof(arr)/sizeof(arr[0]);
    s.qBrute(arr,index,n);
return 0;
}