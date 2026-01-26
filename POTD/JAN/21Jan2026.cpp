#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,1);
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            int price=arr[i];
            int count=1;
            while(!st.empty() && st.top().first<=price){
                count+=st.top().second;
                st.pop();
            }
            st.push({price,count});
            ans[i]=count;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        
        for(int i=0;i<n;i++){
        	int num=nums[i];
        	for(int j=0;j<32;j++){
        		if(num & (1<<j)) continue;
        		else{
        			int k=j-1;
        			if(k<0) break;
        			int mask=(1<<k);
        			int x=num^mask;
        			ans[i]=x;
        			break; 
        		}
        	}
        }
        return ans;
    }
};

int main(){

return 0;
}