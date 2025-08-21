#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool response(vector<int>& time,long long mid, int totalTrips){
        long long ans=0;
        for(int &t:time){
            ans+=1LL*mid/t;
            if(ans>=totalTrips) return true;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int maxi=INT_MIN;
        for(int &t:time)
            maxi=max(maxi,t);
        long long low=1,high=1LL*maxi*totalTrips;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(response(time,mid,totalTrips)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

return 0;
}