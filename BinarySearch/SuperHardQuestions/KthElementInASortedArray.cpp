#include<iostream>
#include<vector>
#include<climits>
using namespace std;

    class Solution {
      public:
        int kthElement(vector<int>& a, vector<int>& b, int k) {
            // code here
            int n=a.size(),m=b.size();
            if(n>m) return kthElement(b,a,k);
            int partition=k;
            int low=max(0,k-m),high=min(n,k);
            while(low<=high){
                int mid1=low+(high-low)/2;
                int mid2=partition-mid1;
                
                int left1=(mid1>0)? a[mid1-1]:INT_MIN;
                int left2=(mid2>0)? b[mid2-1]:INT_MIN;
    
                int right1=(mid1<n)? a[mid1]:INT_MAX;
                int right2=(mid2<m)? b[mid2]:INT_MAX;
                
                if(left1<=right2 && left2<=right1) return max(left1,left2);
                else if(left1>right2) high=mid1-1;
                else low=mid1+1;
            }
            return 0;
        }
    };

int main(){

return 0;
}