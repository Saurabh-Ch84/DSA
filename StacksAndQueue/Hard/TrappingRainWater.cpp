#include<iostream>
#include<vector>
using namespace std;

//optimal solution
class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int waterTrapped = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else waterTrapped += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else waterTrapped += rightMax - height[right];
                right--;
            }
        }

        return waterTrapped;
    }
};

//better solution
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suffixMax(n,-1);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>-1;i--)
            suffixMax[i]=max(height[i],suffixMax[i+1]);

        int prefixMax=-1,totalWater=0;
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,height[i]);
            if(height[i]<prefixMax && height[i]<suffixMax[i])
                totalWater+=max(min(prefixMax,suffixMax[i])-height[i],0);
        }
        return totalWater;
    }
};

int main(){

return 0;
}