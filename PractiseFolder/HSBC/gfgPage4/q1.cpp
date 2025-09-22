#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Find a triplet in a given array such that product is a given number X 
    (all numbers were present only once, i.e. non repetitive).
*/

class Solution{
    // Brute
    int binarySearch(int target,int low,int high,vector<int> &arr){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
        public:
    vector<int> q1Brute(vector<int> &arr,int X){
        sort(arr.begin(),arr.end());
        int left=0,n=arr.size();
        while(left<n){
            if(arr[left]==0 || X%arr[left]!=0){
                left++;
                continue;
            }
            int right=n-1;
            while(right!=left){
                if(X % arr[right]==0 && X % (arr[right]*arr[left])==0){
                    int target=X/(arr[left]*arr[right]);
                    int mid=(arr[left] && arr[right]) ? binarySearch(target,left+1,right-1,arr) : -1;
                    if(mid!=-1)
                        return {arr[left],arr[mid],arr[right]};
                }
                right--;
            }
            left++;
        }
        return {};
    }

    vector<int> q1Optimal(vector<int> &arr,int X){
        unordered_set<int> hashSet(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n;i++){
            int a=arr[i];
            for(int j=i+1;j<n;j++){
                int b=arr[j];
                long long prod=1LL*a*b;
                if(prod==0 || X%prod!=0) continue;
                int c=X/prod;
                if(c!=a && c!=b && hashSet.count(c))
                    return {a,b,c};
            }
        }
        return {};
    }
};

void print(vector<int> nums){
    for(int &num:nums)
        cout<<num<<' ';
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> arr={9,8,3,1,5,3,3,7,3,6};
    print(s.q1Optimal(arr,30));
return 0;
}