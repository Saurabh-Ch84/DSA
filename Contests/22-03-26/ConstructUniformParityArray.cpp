#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

class Solution2 {
    bool check(vector<int> &nums1, int n,int minOdd, bool isOdd){
        for(int i=0; i<n; i++){
            if(isOdd && nums1[i]%2==0 && minOdd>=nums1[i]) return false;
            else if(!isOdd && nums1[i]%2==1 && minOdd>=nums1[i]) return false;
        }
        return true;
    }
public:
    bool uniformArray(vector<int>& nums1) {
        const int inf=1e9+7;
        int n=nums1.size(), minEven=inf, minOdd=inf;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0) minEven=min(minEven, nums1[i]);
            else minOdd=min(minOdd, nums1[i]);
        }
        if(minEven==inf || minOdd==inf || check(nums1,n,minOdd,0) || check(nums1,n,minOdd,1))
            return true;
        return false;
    }
};

int main(){

return 0;
}