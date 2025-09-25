#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int> arr;
        int last=0;
        for(int i=0;i<n;i++){
            int free=startTime[i]-last;
            arr.push_back(free);
            last=endTime[i];
            if(i==n-1){
                int remTime=eventTime-last;
                arr.push_back(remTime);
            }
        }
        vector<int> maxLeft(n+1,0),maxRight(n+1,0);
        for(int i=1;i<=n;i++){
            maxLeft[i]=max(maxLeft[i-1],arr[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],arr[i+1]);
        }

        int result=0;
        for(int i=1;i<=n;i++){
            int currEventTime=endTime[i-1]-startTime[i-1],temp=0;
            if(currEventTime <= max(maxLeft[i-1],maxRight[i]))
                temp=arr[i-1]+currEventTime+arr[i];
            else 
                temp=arr[i-1]+arr[i];
            result=max(result,temp);
        }
        return result;
    }
};

int main(){

return 0;
}