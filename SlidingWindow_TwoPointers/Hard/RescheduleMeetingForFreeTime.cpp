#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> arr;
        int lastEndTime=0;
        for(int i=0;i<n;i++){
            int freeTime=startTime[i]-lastEndTime;
            arr.push_back(freeTime);
            lastEndTime=endTime[i];
            if(i==n-1){
                int remTime=eventTime-lastEndTime;
                arr.push_back(remTime);
            }
        }

        int maxTime=0;
        int left=0,right=0,currTime=0;
        while(right<n+1){
            currTime+=arr[right];
            while(right-left > k){
                currTime-=arr[left];
                left++;
            }
            maxTime=max(maxTime,currTime);
            right++;
        }
        return maxTime;
    }
};

int main(){

return 0;
}