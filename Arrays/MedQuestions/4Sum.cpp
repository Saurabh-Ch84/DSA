#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// User function template for C++

class Solution {
  public:
    // target : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int n=arr.size();
        if(n<4) return {};
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        int left=0;
        while(left<n)
        {
            if(left>0 && arr[left]==arr[left-1]){
                left++;
                continue;
            }
            int mid1=left+1;
            while(mid1<n){
                if(mid1>left+1 && arr[mid1]==arr[mid1-1]){
                    mid1++;
                    continue;
                }
                int mid2=mid1+1,right=n-1;
                int sum=arr[left]+arr[mid1];
                while(mid2<right)
                {
                    int currSum=sum+arr[mid2]+arr[right];
                    if(currSum>target) right--;
                    else if(currSum<target) mid2++;
                    else
                    {
                        res.push_back({arr[left],arr[mid1],arr[mid2],arr[right]});
                        mid2++;
                        right--;
                        while(mid2<right && arr[mid2]==arr[mid2-1]) mid2++;
                        while(right>mid2 && arr[right]==arr[right+1]) right--;
                    }
                }
                mid1++;
            }
            left++;    
        }
        return res;
    }
};

int main(){

return 0;
}