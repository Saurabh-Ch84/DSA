#include<bits/stdc++.h>
using namespace std;

/* 
    You are given an array arr of n elements of positive integers. Your task is to determine the minimum absolute 
    difference between any 2 elements of the array. You can perform the following two types of operations on the array 
    elements any number of times:

    If element e is even, then you can replace it by e / 2
    If element e is odd, then you can replace it by 2 * e
    Determine the minimum absolute difference between any two elements after performing this operation any 
    number of times (possibly zero) on any element of the array.
*/

int findMinDifferenceAfterOperations(vector<int> nums){
    int n=nums.size();
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int num=nums[i];
        if(num%2==1) arr.push_back({2*num,i});
        while(num%2==0){
            arr.push_back({num,i});
            num=num/2;
        }
        arr.push_back({num,i});
    }
    int m=arr.size(), mini=1e9, j=0;
    sort(arr.begin(),arr.end());
    for(int i=1;i<m;i++){
        int valueI=arr[i][0];
        if(arr[j][1]!=arr[i][1]){
            int valueJ=arr[j][0]; 
            mini=min(mini,valueI-valueJ);
        }
        j=i;
    }
    return mini;
}

int main(){

return 0;
}