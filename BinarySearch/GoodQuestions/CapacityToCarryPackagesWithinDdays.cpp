#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<int> &weights,int days,int mid){
        int daysTaken=1,temp=0;
        for(int &weight:weights)
        {
            if(temp+weight>mid)
            {
                temp=0;
                daysTaken++;
            }
            temp+=weight;
            if(daysTaken>days) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0;
        for(int &weight:weights)
        {
            low=max(low,weight);
            high+=weight;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            bool response=check(weights,days,mid);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

return 0;
}