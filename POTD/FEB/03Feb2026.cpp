#include<iostream>
#include<vector>
#include<stack>
using namespace std;

using vi = vector<int> ;
class Solution {
    int helper(vi &nums,int idx,int n,bool flag){
        int i=idx;
        while(i<n-1){
            if(flag && nums[i]>=nums[i+1]) return i;
            if(!flag && nums[i]<=nums[i+1]) return i;
            i++;
        }
        return i;
    }
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=helper(nums,0,n,true);
        if(p==0 || p==n-1) return false;
        int q=helper(nums,p,n,false);
        if(q==p || q==n-1) return false;
        int r=helper(nums,q,n,true);
        if(r==q || r!=n-1) return false;
        return true;
    }
};

// Better soln
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size(), maxi=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && prices[i]<=prices[st.top()]) st.pop();
            if(!st.empty()){
                int cost=prices[i]-prices[st.top()];
                maxi=max(maxi,cost);
            }
            else st.push(i);
        }
        return maxi;
    }
};

// Optimal
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size(), maxi=0;
        int ptr=0, buy=prices[0];
        while(ptr<n){
            int price=prices[ptr];
            if(price>buy){
                int profit=price-buy;
                maxi=max(maxi,profit);
            }
            else buy=price;
            ptr++;
        }
        return maxi;
    }
};

int main(){

return 0;
}