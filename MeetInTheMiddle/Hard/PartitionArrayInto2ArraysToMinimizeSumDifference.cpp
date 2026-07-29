#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int inf=1e6;
    int recursion(int i,int S1,int n,int S,vint &nums,int k=0){
        if(i==n) return ((k==n/2)? abs(2*S1-S): inf);
        int notTake=recursion(i+1,S1,n,S,nums,k);
        int take=recursion(i+1,S1+nums[i],n,S,nums,k+1);
        return min(notTake,take);
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(), S=accumulate(nums.begin(),nums.end(),0);
        return recursion(0,0,n,S,nums);
    }
};

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    vvint getSubSetSum(vint &arr,int l,int n){
        vvint subSetSum(n+1);
        for(int i=0;i<(1<<n);i++){
            int k=0, sum=0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    sum+=arr[l+j];
                    k++;
                }
            }
            subSetSum[k].push_back(sum);
        }
        return subSetSum;
    }
    int binarySearch(vint &arr,int x,int S){
        int mini=1e9, low=0, high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int S1=x+arr[mid];
            int D=2*S1-S;
            if(D==0) return 0;
            if(D>0){
                mini=min(mini,D);
                high=mid-1;
            }
            else{
                mini=min(mini,-D);
                low=mid+1;
            }
        }
        return mini;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(), S=accumulate(nums.begin(),nums.end(),0);
        vvint subSetSum1=getSubSetSum(nums,0,n/2);
        vvint subSetSum2=getSubSetSum(nums,n/2,n/2);
        int n1=subSetSum1.size(), n2=subSetSum2.size();
        for(int i=0;i<n2;i++){
            sort(subSetSum2[i].begin(),subSetSum2[i].end());
        }
        int mini=1e9;
        for(int i=0;i<n1;i++){
            int count=i, m=subSetSum1[i].size();
            int remCount=n/2-count;
            for(int j=0;j<m;j++){
                int sumLeft=subSetSum1[i][j];
                mini=min(mini,binarySearch(subSetSum2[remCount],sumLeft,S));
                if(!mini) break;
            }
            if(!mini) break;
        }
        return mini;
    }
};

int main(){

return 0;
}