#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Solution {
    bool check(vector<int> &stalls,int k,int mid){
        int minDistance=mid;
        int cowsPlaced=1,lastStall=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            int distance=stalls[i]-lastStall;
            if(distance>=minDistance){
                cowsPlaced++;
                lastStall=stalls[i];
            }
            if(cowsPlaced>=k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(stalls,k,mid);
            if(response) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};

int main(){

return 0;
}