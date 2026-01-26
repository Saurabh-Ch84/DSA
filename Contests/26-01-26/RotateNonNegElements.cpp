#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void rotate(vector<int> &nonNeg,int k,int m){
        vector<int> temp=nonNeg;
        for(int i=0;i<m;i++){
            int j=(i-k+m)%m;
            nonNeg[j]=temp[i];
        }
    }
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
        for(int &num: nums){
            if(num>=0) nonNeg.push_back(num);
        }
        int n=nums.size(), m=nonNeg.size(), ptr=0;
        if(!m) return nums;
        rotate(nonNeg,k%m,m);
        for(int i=0;i<n;i++){
            if(nums[i]>=0 && ptr<m){
                nums[i]=nonNeg[ptr];
                ptr++;
            }
        }
        return nums;
    }
};

int main(){

return 0;
}