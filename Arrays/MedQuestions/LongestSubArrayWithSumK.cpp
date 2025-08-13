#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//better for positive nums but optimal for zeros and negative case
class Solution1 {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size(),sum=0,maxLen=0;
        unordered_map<int,int> preSumMap;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) maxLen=i+1;
            int remSum=sum-k;
            if(preSumMap.find(remSum)!=preSumMap.end()){
                int len=i-preSumMap[remSum];
                maxLen=max(len,maxLen);
            }
            if(preSumMap.find(sum)==preSumMap.end())
                preSumMap[sum]=i;
        }
        return maxLen;
    }
    
    //better solution
    int longestSubarrayWithSumK(vector<int>& arr, int k) {
        unordered_map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
    
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k) maxLen = i + 1;
            long long rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen=max(maxLen,len);
            }
            if (preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }
        return maxLen;
    }
};

//optimal for non-negative numbers only
class Solution2{
        public:
    int longestSubArrayWithSumK(vector<int> &arr,int k){
        int left=0,right=0,n=arr.size(),maxLen=0,sum=0;
        while(right<n){
            sum+=arr[right];
            while(sum>k)
            {
                sum-=arr[left];
                left++;
            }
            if(sum==k) maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};

int main(){

return 0;
}