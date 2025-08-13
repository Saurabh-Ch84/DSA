#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    bool check(vector<int> &piles,int k,int h){
        long long total_time=0;
        for(int &pileSize:piles)
        {
            long time=1LL * (pileSize+k-1)/k;
            total_time+=time;
        }
        if(total_time>h) return false;
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(int &pileSize:piles)
            high=max(high,pileSize);
        
        int k=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            bool response=check(piles,mid,h);
            if(response)
            {
                k=min(mid,k);
                high=mid-1;
            }
            else low=mid+1;
        }
        return k;
    }
};

int main(){
    
return 0;
}