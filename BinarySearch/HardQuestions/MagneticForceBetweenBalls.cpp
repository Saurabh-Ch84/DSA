#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    bool check(vector<int> &position,int m,int mid,int n){
        int ballsPlaced=1,lastBasket=position[0];
        for(int i=1;i<n;i++){
            int distance=position[i]-lastBasket;
            if(distance>=mid){
                ballsPlaced++;
                lastBasket=position[i];
            }
            if(ballsPlaced>=m) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(position,m,mid,n);
            if(response) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};

int main(){

return 0;
}