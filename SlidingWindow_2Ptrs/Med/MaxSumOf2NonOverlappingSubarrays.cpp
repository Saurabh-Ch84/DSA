#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;

    using pii=pair<int,int>;
    using pipii=pair<int,pii>;
    using vpipii=vector<pipii>;
    
    void preprocess(int n,int k,vpipii &arr,vint &nums){
        int winSum=0;
        for(int i=0;i<k;i++) winSum+=nums[i];
        for(int i=0;i<n-k+1;i++){
            arr.push_back({winSum,{i,i+k-1}});
            winSum-=nums[i];
            winSum+=(i+k<n? nums[i+k]:0);
        }
        sort(arr.rbegin(),arr.rend());
    }
    bool isOverlapping(pii &a,pii &b){
        bool condition1=(a.first>=b.first && a.first<=b.second);
        bool condition2=(b.first>=a.first && b.first<=a.second);
        return (condition1 || condition2);
    }
    int recursion(int i,int j,int n1,int n2,vpipii &arr1,vpipii &arr2,vvint &dp){
        if(i==n1 || j==n2) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(!isOverlapping(arr1[i].second,arr2[j].second)) 
            return dp[i][j]=arr1[i].first+arr2[j].first;
        int left=recursion(i+1,j,n1,n2,arr1,arr2,dp);
        int right=recursion(i,j+1,n1,n2,arr1,arr2,dp);
        return dp[i][j]=max(left,right);
    }
public:
    int maxSumTwoNoOverlap(vint &nums,int firstLen,int secondLen) {
        int n=nums.size(), maxi=0;
        vpipii arr1, arr2;
        preprocess(n,firstLen,arr1,nums);
        preprocess(n,secondLen,arr2,nums);
        int n1=n-firstLen+1, n2=n-secondLen+1;
        vvint dp(n1,vint(n2,-1));
        return recursion(0,0,n1,n2,arr1,arr2,dp);
    }
};

class Solution2 {
    using vint=vector<int>;
    int helper(vint &nums,vint &prefix,int l,int m,int n){
        int maxi=0, k=l+m, maxLeftBlockSum=0;
        for(int mEnd=k-1;mEnd<n;mEnd++){
            int lEnd=mEnd-m, lStartPrev=lEnd-l;
            int rightBlockSum=prefix[mEnd]-prefix[lEnd];
            int leftBlockSum=prefix[lEnd]-(lStartPrev<0? 0:prefix[lStartPrev]);
            maxLeftBlockSum=max(maxLeftBlockSum,leftBlockSum);
            maxi=max(maxi,maxLeftBlockSum+rightBlockSum);
        }
        return maxi;
    }
public:
    int maxSumTwoNoOverlap(vint &nums, int firstLen, int secondLen) {
        int n=nums.size();

        vint prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];

        int case1=helper(nums,prefix,firstLen,secondLen,n);
        int case2=helper(nums,prefix,secondLen,firstLen,n);
        return max(case1,case2);
    }
};

int main(){

return 0;
}