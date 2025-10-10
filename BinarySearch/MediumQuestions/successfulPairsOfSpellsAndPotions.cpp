#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int lowerBound(vector<int> &arr,long long target,int n){
        int low=0,high=n-1,idx=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((long long)arr[mid]>=target){
                idx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return idx;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());

        vector<int> result;
        for(int &spell:spells){
            long long target=(success+spell-1)/spell;
            int idx=lowerBound(potions,target,m);
            int count=m-idx;
            result.push_back(count);
        }

        return result;
    }
};

int main(){

return 0;
}