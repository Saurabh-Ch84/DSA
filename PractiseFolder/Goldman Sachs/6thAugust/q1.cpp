#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    int fun1(vector<int> &arr) {
        // code here
        int n=arr.size(),prefixMax=0,water=0;
        vector<int> suffixMax(n,-1);
        //suffix Max
        suffixMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            suffixMax[i]=max(suffixMax[i+1],arr[i]);
            
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,arr[i]);
            //formula for currWater calculation
            int currWater=min(prefixMax,suffixMax[i])-arr[i];
            //avoid neg values
            water+=max(currWater,0);
        }
        return water;
    }
    
    int fun2(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0,right=n-1,leftMax=arr[0],rightMax=arr[n-1];
        int water=0;
        while(left<right){
            int currWater;
            if(arr[left]>arr[right]){
                right--;
                rightMax=max(rightMax,arr[right]);
                currWater=rightMax-arr[right];    
            }
            else{
                left++;
                leftMax=max(leftMax,arr[left]);
                currWater=leftMax-arr[left];
            }
            water+=max(currWater,0);
        }
        return water;
    }
        public:
    int maxWater(vector<int> &arr){
        return fun2(arr);
    }
};

int main(){
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<"The Max Water Trapped is: "<<s.maxWater(arr);
return 0;
}