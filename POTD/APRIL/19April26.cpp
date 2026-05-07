#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int i=n-1, j=m-1, maxi=0;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) j--;
            else{
                maxi=max(maxi,j-i);
                i--;
            }
        }
        return maxi;
    }
};

class Solution {
  public:
    bool isPower(int x, int y) {
        if (x == 1) return y == 1;
        while (y % x == 0) y /= x;
        return y == 1;
    }
};

int main(){

return 0;
}