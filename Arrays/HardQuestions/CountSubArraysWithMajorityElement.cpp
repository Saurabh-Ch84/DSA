#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    long long correctCount(int low,int high,vint &arr){
        if(low>=high) return 0;
        long long count=0;
        int mid=low+(high-low)/2;
        count+=correctCount(low,mid,arr);
        count+=correctCount(mid+1,high,arr);
        return count+mergeCount(low,mid,high,arr);
    }
    long long mergeCount(int low,int mid,int high,vint &arr){
        vint temp;
        int left=low, right=mid+1;
        long long count=0;
        while(left<=mid && right<=high){
            if(arr[left]<arr[right]){
                temp.push_back(arr[left++]);
                count+=high-right+1;
            }
            else temp.push_back(arr[right++]);
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
        while(right<=high)
            temp.push_back(arr[right++]);
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
        return count;
    }
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // arr has size n+1 to include the implicit 0 at the start
        vint arr(n + 1, 0);
        for(int i = 0; i < n; i++){
            arr[i+1] = arr[i] + (nums[i] == target ? 1 : -1);
        }
        return correctCount(0, n, arr);
    }
};

int main(){

return 0;
}