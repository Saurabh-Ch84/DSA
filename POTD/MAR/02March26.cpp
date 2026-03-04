#include<iostream>
#include<vector>
using namespace std;

class Solution1{
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suffixMax(n,-1);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>-1;i--)
            suffixMax[i]=max(height[i],suffixMax[i+1]);

        int prefixMax=-1,totalWater=0;
        for(int i=0;i<n;i++){
            prefixMax=max(prefixMax,height[i]);
            if(height[i]<prefixMax && height[i]<suffixMax[i])
                totalWater+=max(min(prefixMax,suffixMax[i])-height[i],0);
        }
        return totalWater;
    }
};

using vi=vector<int>;
using vvi=vector<vi>;

class Solution2 {
    void precompute(vi &trailingZeros,vvi &grid,int n){
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]) break;
                count++;
            }
            trailingZeros[i]=count;
        }
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(), count=0;
        vi trailingZeros(n,0);
        precompute(trailingZeros,grid,n);

        for(int r=0;r<n;r++){
            int need=n-r-1;
            bool flag=false;
            for(int i=r;i<n;i++){
                if(trailingZeros[i]>=need){
                    while(i!=r){
                        count++;
                        swap(grid[i],grid[i-1]);
                        swap(trailingZeros[i],trailingZeros[i-1]);
                        i--;
                    }
                    flag=true;
                    break;
                }
            }
            if(!flag) return -1;
        }

        return count;
    }
};

int main(){

return 0;
}