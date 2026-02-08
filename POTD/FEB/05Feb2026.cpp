#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int i_=((i+num)%n+n)%n;
            result[i]=nums[i_];
        }
        return result;
    }
};

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int zero=0, n=arr.size();
        int left=0, right=0, maxi=0;
        while(right<n){
            int num=arr[right];
            if(!num) zero++;
            while(zero>k && left<=right){
                if(!arr[left]) zero--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}