#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//DNF algorithm (Dutch National Algorithm)
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else mid++;
        }
    }
};

//counting-sort
class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freqArr(3,0);
        int n=nums.size();
        for(int &num:nums)
            freqArr[num]++;
        int left=0,right=0;
        while(left<n){
            while(freqArr[right]){
                nums[left++]=right;
                freqArr[right]--;
            }
            right++;
        }
    }
};

//better 
class Solution2 {
    int customSort(vector<int> &nums,int n,int t,int st=0){
        int idx=n-1;
        for(int i=st;i<n;i++){
            if(nums[i]!=t){
                idx=i;
                break;
            }
        }
        for(int i=idx+1;i<n;i++){
            if(nums[i]==t){
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        return idx;
    }
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=customSort(nums,n,0);
        customSort(nums,n,1,left);
    }
};

int main(){

return 0;
}