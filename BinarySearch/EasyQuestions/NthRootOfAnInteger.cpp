#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int cal(int m,int n,int num){
        int temp=num;
        for(int i=0;i<n-1;i++)
        {
            num=num*temp;
            if(num>m) return 1;
        }
        if(num<m) return -1;
        return 0;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int low=1,high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            int response=cal(m,n,mid);
            if(response==0) return mid;
            else if(response==1) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};

int main(){

return 0;
}