#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ele1=INT_MIN,ele2=INT_MIN;
        int count1=0,count2=0,ptr=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=ele2){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        int majority=(n/3)+1;
        count1=0,count2=0;
        for(int &num:nums)
        {
            if(num==ele1) count1++;
            if(num==ele2) count2++;
        }

        vector<int> res;
        if(count1>=majority) res.push_back(ele1);
        if(count2>=majority) res.push_back(ele2);
        return res;
    }
};

int main(){

return 0;
}