#include<iostream>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(), maxi=0;
        for(int i=0;i<n;i++){
            unordered_set<int> even, odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(odd.size()==even.size()) 
                    maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};

using vi=vector<int>;
class Solution2 {
    bool check(vi &arr,int mid,int k){
        long long hours=0;
        for(int &pile: arr){
            int hour=(pile+mid-1)/mid;
            hours+=hour;
            if(hours>k) return false;
        }
        return true;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low=1, high=INT_MIN;
        for(int &pile: arr)
            high=max(high,pile);
        
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(arr,mid,k);
            if(response){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return ans;
    }
};

int main(){

return 0;
}