#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;

/*
    You are given an array A consisting of N integers and an integer K.
    Your task is to divide the array into exactly K non-empty contiguous subarrays.
    The dominance score of a subarray is defined as the maximum frequency of any element in that subarray.
    The score of a partition is the sum of the dominant scores of all K subarrays.
    Find the max possible score.
    Eg [1,2,2,1,2] k=2
        Output=1+3=4
    Eg [2,3,2,4,2], k=1
        Output=3
    Eg [1,1,2,2,3,3], k=3
        Output=2+2+2=6
*/

/*
    You are given a binary string S consisting only of '0' and '1'.
    Your task is to find the minimum number of adjacent swaps required to make all identical characters appear 
    together in one contiguous block. Adjacent swap means swapping two neighboring characters.

    You have two choices:
    1. Group all '1' characters together.
    2. Group all '0' characters together.

    Return the minimum swaps required among the two options.
*/

/*
    There are N houses arranged in a straight line. Each house must be painted using one of C available colors.
    The cost of painting the i-th house with the j-th color is given by cost[i][j].

    The following conditions must be satisfied:
        Every house must be painted exactly one color.
        No two adjacent houses can have the same color.
        The total painting cost must not exceed the given budget B.

    Your task is to determine the minimum total painting cost.
    If it is impossible to paint all the houses within the given budget, print -1.
*/

/*
    Andy wants to go on a vacation to de-stress himself. He can take only one continuous vacation 
    during the next N days, where the days are numbered from 1 to N.

    Andy already has M obligations scheduled on specific days. The i-th obligation is on day D[i]. 
    To extend his vacation, Andy is allowed to cancel at most K obligations.

    Your task is to determine the maximum number of consecutive vacation days Andy can take after canceling 
    at most K obligations.
*/

class Solution{
    int negInf=-1e7, inf=1e7;
    int recursion(int i,int n,int k,vint &arr,vvint &modMatrix,vvint &dp){
        if(i>=n) return (k? negInf: 0);
        if(dp[i][k]!=negInf) return dp[i][k];
        if(k==1) return dp[i][k]=modMatrix[i][n-1];
        int ans=-1e7;
        for(int j=i;j<n;j++){
            int nextAns=modMatrix[i][j]+recursion(j+1,n,k-1,arr,modMatrix,dp);
            ans=max(ans,nextAns);
        }
        return dp[i][k]=ans;
    }
    int helper(string &str,char digit){
        int n=str.size();
        vint digitIndices;
        for(int i=0;i<n;i++){
            if(str[i]==digit)
                digitIndices.push_back(i);
        }
        int m=digitIndices.size();
        if(m==0 || m==n) return 0;
        vint adjusted(m,-1);
        for(int i=0;i<m;i++) // normalization
            adjusted[i]=digitIndices[i]-i;
        int median=adjusted[m/2], count=0;
        for(int i=0;i<m;i++)
            count=count+abs(adjusted[i]-median);
        return count;
    }
    vint get1MinAnd2Min(vector<int> &arr,int n){
        int min1Idx=-1, min2Idx=-1;
        for(int i=0;i<n;i++){
            if(min1Idx==-1 || arr[i]<arr[min1Idx]){
                min2Idx=min1Idx;
                min1Idx=i;
            }
            else if(min2Idx==-1 || (arr[i]>=arr[min1Idx] && arr[i]<arr[min2Idx]))
                min2Idx=i;
        }
        return {min1Idx,min2Idx};
    }
        public:
    int divideArray(vint arr,int k){
        int n=arr.size();
        // preprocess.
        vvint modMatrix(n,vint(n,0));
        for(int i=0;i<n;i++){
            unordered_map<int,int> freqMap;
            int maxi=0;
            for(int j=i;j<n;j++){
                maxi=max(maxi,++freqMap[arr[j]]);
                modMatrix[i][j]=maxi;
            }
        }
        vvint dp(n+1,vint(k+1,negInf));
        return recursion(0,n,k,arr,modMatrix,dp);
    }
    int minSwapsToMakeContiguous(string s){
        return min(helper(s,'0'),helper(s,'1'));
    }
    int minCostToPaintHouses(int H,int C,int B,vvint cost){
        vint dp(C,inf);
        for(int i=0;i<C;i++)
            dp[i]=cost[0][i];
        for(int i=1;i<H;i++){
            vint minIndices=get1MinAnd2Min(dp,C);
            int firstMin=minIndices[0], secondMin=minIndices[1];
            if(firstMin==-1 || secondMin==-1 || dp[firstMin]>B) return -1;
            vint temp(C,inf);
            for(int j=0;j<C;j++)
                temp[j]=cost[i][j]+(j==firstMin? dp[secondMin]: dp[firstMin]);
            dp=temp;
        }
        int minCost=*min_element(dp.begin(),dp.end());
        return (minCost<=B? minCost: -1);
    }
    int maxNumberOfConsecutiveVacationDays(int n,int m,int k,vint obligations){
        sort(obligations.begin(),obligations.end());
        int maxi=max(obligations[0]-1,n-obligations[m-1]), left=0, right=0;
        while(right<m){
            if(right-left+1>k)
                left++;
            if(right-left+1<=k){
                int leftLimit=(left>0? obligations[left-1]:0);
                int rightLimit=(right<m-1? obligations[right+1]:n+1);
                maxi=max(maxi,rightLimit-leftLimit-1);
            }
            right++;
        }
        return maxi;
    }
};

int main(){
    Solution s;
    cout<<s.divideArray({2,3,2,4,2},1)<<endl;
    cout<<s.divideArray({1,2,2,1,2},2)<<endl;
    cout<<s.divideArray({1,1,2,2,3,3},3)<<endl;

    cout<<s.minSwapsToMakeContiguous("1001111")<<endl;
    cout<<s.minSwapsToMakeContiguous("10101")<<endl;

    cout<<s.minCostToPaintHouses(3,3,20,{{1,5,3},{2,9,4},{3,1,7}})<<endl;
    cout<<s.maxNumberOfConsecutiveVacationDays(20,5,2,{3,8,18,15,12})<<endl;
return 0;
}