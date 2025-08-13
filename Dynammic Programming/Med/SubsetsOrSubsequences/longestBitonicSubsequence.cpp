#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> lis(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && lis[i]<1+lis[prev])
                    lis[i]=1+lis[prev];
            }
        }
        vector<int> lds(n,1);
       for (int i = n - 1; i >= 0; i--) {
            for (int next = n - 1; next > i; next--) {
                if (nums[next] < nums[i] && lds[i] < 1 + lds[next])
                    lds[i] = 1 + lds[next];
            }
        }
        if(lis[n-1] == n || lds[0] == n) return 0;
        int ans=0;
        for(int i=0;i<n;i++)
             if(lis[i] > 1 && lds[i] > 1){
                ans = max(ans, lis[i] + lds[i] - 1);  
            }
        
        return ans;
    }
};


int main(){

return 0;
}