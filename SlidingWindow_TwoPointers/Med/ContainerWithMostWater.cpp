#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,maxi=0;
        while(left<right){
            int breadth=right-left,length=min(height[left],height[right]);
            int area=length*breadth;
            maxi=max(maxi,area);
            if(height[left]<height[right]) 
                left++;
            else 
                right--;
        }
        return maxi;
    }
};

int main(){

return 0;
}