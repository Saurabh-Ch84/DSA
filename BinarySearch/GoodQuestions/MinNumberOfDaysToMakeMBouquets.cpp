#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution2 {
    bool check(vector<int> &bloomDay,int m,int k,int mid){
        int bouquets=0,flower=0;
        for(int &day:bloomDay)
        {
            if(mid>=day)
            {
                flower++;
                if(flower==k)
                {
                    bouquets++;
                    flower=0;
                    if(bouquets>=m) return true;
                }
            }
            else flower=0;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded=1LL*m*k;
        int totalAvailableFlowers=bloomDay.size();
        if(totalFlowersNeeded>totalAvailableFlowers) return -1;
        
        int high=INT_MIN,low=INT_MAX;
        for(int &day:bloomDay){
            high=max(high,day);
            low=min(low,day);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(bloomDay,m,k,mid);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

class Solution1 {
    bool check(vector<int> &bloomDay,int m,int k,int mid){
        int bouquets=0,flower=0;
        for(int &day:bloomDay){
            if(mid>=day){
                flower++;
                if(flower==k){
                    bouquets++;
                    flower=0;
                }
            }
            else flower=0;
        }
        return bouquets>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded=1LL*m*k;
        int totalAvailableFlowers=bloomDay.size();
        if(totalFlowersNeeded>totalAvailableFlowers) return -1;
        int high=INT_MIN,low=INT_MAX;
        for(int &day:bloomDay){
            high=max(high,day);
            low=min(low,day);
        }
        int minDays=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(bloomDay,m,k,mid);
            if(response){
                minDays=min(mid,minDays);
                high=mid-1;
            }
            else low=mid+1;
        }
        return minDays;
    }
};

int main(){

return 0;
}