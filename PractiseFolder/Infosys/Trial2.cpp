#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
	First Problem:
	
			Given an array with a peak (it always exists). Now you have to find the maximum element that 
			exists on both the left and right of the peak.
			
	N <= 1e5
	a[i] <= 1e9
*/

int maxAtBothSidesOfPeak(vector<int> arr){
	int n=arr.size();
	int maxIdx=0;
	for(int i=1;i<n;i++){
		if(arr[maxIdx]<arr[i]){
			maxIdx=i;
		}
	}
	unordered_set<int> hashSet;
	bool flag=false;
	int ans=-1;
	for(int i=0;i<n;i++){
		if(i==maxIdx){
			flag=true;
			continue;
		}
		if(flag && hashSet.count(arr[i])){
			ans=max(ans,arr[i]);
		}
		else if(!flag) hashSet.insert(arr[i]);
	}
	return ans;
}

/*
	Second Problem:
	
		Given an array consisting of positive, negative, and zero values, you can change the sign of at 
		most one element. Find the maximum sum subarray.
	N <= 1e5
	abs(a[i]) <= 1e9
*/

long long maxSumSubarrayAfterOperation(vector<int> arr){
	int n=arr.size();
	long long maxSum=-1e15, sum=0;
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
		if(sum<0) sum=0;
		maxSum=max(maxSum,sum);
	}
	
	vector<long long> maxSubarrayLeft(n,0), maxSubarrayRight(n,0);
	long long prefixKadane=0;
	for(int i=0;i<n;i++){
		if(prefixKadane<0) prefixKadane=0;
		maxSubarrayLeft[i]=prefixKadane;
		prefixKadane=prefixKadane+arr[i];
	}
	long long suffixKadane=0;
	for(int i=n-1;i>=0;i--){
		if(suffixKadane<0) suffixKadane=0;
		maxSubarrayRight[i]=suffixKadane;
		suffixKadane=suffixKadane+arr[i];
	}
	for(int i=0;i<n;i++){
		long long sum=maxSubarrayLeft[i]+maxSubarrayRight[i]+abs(arr[i]);
		maxSum=max(maxSum,sum);
	}
	return maxSum;
}

/*
	Third Problem:
			Given an array and K, divide the array into K contiguous subarrays. The cost of a subarray 
			is maximum - minimum of subarray + abs(left end - right end). Find the minimum cost among 
			all partitions.
	N <= 500
	K <= N

    Input: arr = [1, 3, 5, 2, 4], K = 2
    Expected Output: 4
    Explanation:
        [1] → cost = (1-1) + |1-1| = 0 + 0 = 0
        [3, 5, 2, 4] → cost = (5-2) + |3-4| = 3 + 1 = 4
        Total = 8 (Optimal)
*/

class Solution1{
    // brute force O(n^3) Time and Space
    int costFunction(vector<int> &arr,int left,int right){
        int maxi=arr[left], mini=arr[left];
        for(int i=left;i<=right;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        return maxi-mini+abs(arr[left]-arr[right]);
    }
    int recursion(int p,int i,int n,int k,vector<int> &arr){
        if(i>=n) return 1e7;
        if(k==1) return costFunction(arr,i,n-1);
        int skip=recursion(p,i+1,n,k,arr);
        int take=costFunction(arr,p,i)+recursion(i+1,i+1,n,k-1,arr);
        return min(take,skip);
    };
        public:
    int findMinCostAfterDividingArray(vector<int> arr,int k){
        int n=arr.size();
        return recursion(0,0,n,k,arr);
    }
};

class Solution2{
    int costFunction(vector<int> &arr,int left,int right){
        int maxi=arr[left], mini=arr[left];
        for(int i=left;i<=right;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        return maxi-mini+abs(arr[left]-arr[right]);
    }
    int recursion(int i,int n,int k,vector<int> &arr,vector<vector<int>> &dp){ 
        if(i>=n) return 1e7;
        if(k==1) return costFunction(arr,i,n-1);
        if(dp[i][k]!=-1) return dp[i][k];
        int miniCost=1e7, mini=1e9, maxi=-1e9;
        for(int j=i;j<n;j++){
            maxi=max(maxi,arr[j]);
            mini=min(mini,arr[j]);
            int cost=maxi-mini+abs(arr[i]-arr[j])+recursion(j+1,n,k-1,arr,dp);
            miniCost=min(miniCost,cost);
        }
        return dp[i][k]=miniCost;
    }
        public:
    int findMinCostAfterDividingArray(vector<int> arr,int k){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return recursion(0,n,k,arr,dp);
    }
};  

int main(){
	// cout<<maxAtBothSidesOfPeak({8,2,7,6,0,6,2,0,9,7,8})<<endl;
	// cout<<maxSumSubarrayAfterOperation({3,-1,2,0,-5})<<endl;

    Solution2 s;
    cout<<s.findMinCostAfterDividingArray({1,3,5,2,4},2)<<endl;
    return 0;
}