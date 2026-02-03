#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int prev=nums[0], n=nums.size(), flag=0;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            if(!flag && prev!=curr){
                if(prev>curr) flag=-1;
                else flag=1;
            }
            else if(flag==1 && prev>curr) return false;
            else if(flag==-1 && prev<curr) return false;
            prev=curr;
        }
        return true;
    }
};

int main(){

return 0;
}