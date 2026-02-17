#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    bool check(vector<int> &arr,int n,int k,int mid){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                k--;
                if(k<=0) return false;
            }
        }
        return true;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int low=0, high=0, n=arr.size();
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool resp=check(arr,n,k,mid);
            if(resp){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

using vd=vector<double>;
using vvd=vector<vd>;
class Solution {
    void fillGlass(vvd &pyramid,int poured,int n){
        pyramid[0][0]=poured;
        for(int i=0;i<n-1;i++){
            bool canEarlyReturn=true;
            for(int j=0;j<=i;j++){
                if(pyramid[i][j]>1.0){
                    double overflow=(pyramid[i][j]-1.0)/2.0;
                    pyramid[i+1][j]+=overflow;
                    pyramid[i+1][j+1]+=overflow;
                    pyramid[i][j]=1.0;
                    canEarlyReturn=false;
                }
            }
            if(canEarlyReturn) return ;
        }
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n=100;
        //Build-the champagne pyramid.
        vvd pyramid(n);
        for(int i=0;i<n;i++)
            pyramid[i]=vd(i+1,0.0);
        //simulate
        fillGlass(pyramid,poured,n);
        //query
        return pyramid[query_row][query_glass];
    }
};

int main(){

return 0;
}