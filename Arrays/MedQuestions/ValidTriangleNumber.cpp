#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0) continue;
            int a=nums[i];
            for(int j=i+1;j<n-1;j++){
                int b=nums[j];
                int idx=lower_bound(nums.begin()+j+1,nums.end(),a+b)-nums.begin();
                count+=max(idx-(j+1),0);
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,n=nums.size();
        for(int i=n-1;i>=0;i--){
            int j=i-1;
            int k=0;
            while(k<j){
                if(nums[k]+nums[j] > nums[i]){
                    count+=j-k;
                    j--;
                }
                else k++;
            }
        }
        return count;
    }
};

int main(){
    Solution2 s;
    vector<int> nums={9,8,3,1,5,3,3,7,3,6};
    cout<<s.triangleNumber(nums);
return 0;
}