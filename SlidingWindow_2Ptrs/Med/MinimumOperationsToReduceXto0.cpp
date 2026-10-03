#include<bits/stdc++.h>
using namespace std;

class Solution {
    int customBinarySearch(vector<int>& suffix,int target,int n){
        int high=n,low=0,ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(suffix[mid]==target){
                ans=mid;
                break;
            }
            else if(suffix[mid]>target)
                low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--)
            suffix[i]=suffix[i+1]+nums[i];
        int i=0, prefix=0, mini=n+1;
        while(i<=n && prefix<=x){
            int j=customBinarySearch(suffix,x-prefix,n);
            if(j!=-1 && i<=j){
                int ans=i+(n-j);
                mini=min(mini,ans);
            }
            if(i<n) prefix+=nums[i];
            i++;
        }
        return (mini>n? -1:mini);
    }
};

int main(){

return 0;
}