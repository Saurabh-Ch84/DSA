#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;
using vi = vector<int>;
using pii=pair<int,int>;
using vvi = vector<vi>;

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> hashMap;
        hashMap[0]=1;
        int ptr=0, n=arr.size();
        int count=0, prefixSum=0;
        while(ptr<n){
            int num = arr[ptr++] % 2;
            prefixSum+=num;
            int remSum=prefixSum-k;
            count+=hashMap[remSum];
            hashMap[prefixSum]++;
        }
        return count;
    }
};


class Solution {
	int recursion(int i,int j,int n,int m,vi &nums1,vi &nums2,vvi &dp){
		if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
		int notTake=max(recursion(i+1,j,n,m,nums1,nums2,dp),
                        recursion(i,j+1,n,m,nums1,nums2,dp));
		int take=(nums1[i]*nums2[j])+recursion(i+1,j+1,n,m,nums1,nums2,dp);
		return dp[i][j]=max(take,notTake);
	}
	
	pii getMinAndMax(vi &nums){
		int n=nums.size() ,maxi=INT_MIN, mini=INT_MAX;
        for(int i=0;i<n;i++){
        	maxi=max(maxi,nums[i]);
        	mini=min(mini,nums[i]);
        }
        return {maxi,mini};
	}
	
public:
    int maxDotProduct(vi & nums1, vi & nums2) {
        int n=nums1.size(), m=nums2.size();
        vvi dp(n,vi(m,-1));
        int ans=recursion(0,0,n,m,nums1,nums2,dp);
        if(ans) return ans;
        
        pii num1=getMinAndMax(nums1);
        int maxi1=num1.first, mini1=num1.second;
        pii num2=getMinAndMax(nums2);
        int maxi2=num2.first, mini2=num2.second;
        
        return max(maxi1*mini2, mini1*maxi2);
    }
};

int main(){

return 0;
}