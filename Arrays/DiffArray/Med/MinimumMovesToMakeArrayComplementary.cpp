#include<bits/stdc++.h>
using namespace std;

class Solution1{
    // Brute-Force.
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size(), mini=2*n;
        for(int sum=2;sum<=2*limit;sum++){
            int moves=0;
            for(int i=0;i<n/2;i++){
                int a=nums[i], b=nums[n-i-1], currSum=a+b;
                if(currSum==sum) continue;
                int minVal=1+min(a,b), maxVal=limit+max(a,b);
                if(minVal<=sum && maxVal>=sum) moves+=1;
                else moves+=2;
            }
            mini=min(mini,moves);
        }
        return mini;
    }
};

class Solution2{
    // optimal
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size(), mini=2*n;
        vector<int> diffArray(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int a=nums[i], b=nums[n-i-1];
            int sum=a+b, minVal=min(a,b)+1, maxVal=limit+max(a,b);
            diffArray[2]+=2, diffArray[2*limit+1]-=2;
            diffArray[minVal]+=-1, diffArray[maxVal+1]-=-1;
            diffArray[sum]+=-1, diffArray[sum+1]-=-1;
        }
        int m=diffArray.size();
        for(int sum=2;sum<=2*limit;sum++){
            diffArray[sum]+=diffArray[sum-1];
            mini=min(mini,diffArray[sum]);
        }
        return mini;
    }
};

int main(){

return 0;
}