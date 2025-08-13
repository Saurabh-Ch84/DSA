#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int left=0,right=n1;
        int bar=(n1+n2+1)/2;
        int n=n1+n2;
        while(left<=right){
            int mid1=(left+right)/2;
            int mid2=bar-mid1;
            int left1=INT_MIN,left2=INT_MIN;
            int right1=INT_MAX,right2=INT_MAX;
            if(mid1<n1) right1=nums1[mid1];
            if(mid2<n2) right2=nums2[mid2];
            if(mid1-1>=0) left1=nums1[mid1-1];
            if(mid2-1>=0) left2=nums2[mid2-1];

            if(left1<=right2 && left2<=right1){
                if(n%2) return (double)max(left1,left2);
                return (double)(max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1>right2)
                right=mid1-1;
            else
                left=mid1+1;
        }
        return 0.0;
    }
};

class Solution2 {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n=a.size(),m=b.size();
        if(n>m) return medianOf2(b,a);
        int low=0,high=n,totalElements=n+m;
        int partition=(totalElements+1)/2;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=partition-mid1;
            
            int left1=INT_MIN,left2=INT_MIN;
            if(mid1-1>=0) left1=a[mid1-1];
            if(mid2-1>=0) left2=b[mid2-1];
            int right1=INT_MAX,right2=INT_MAX;
            if(mid1<=n-1) right1=a[mid1];
            if(mid2<=m-1) right2=b[mid2];
            
            if(left1<=right2 && left2<=right1){
                if(totalElements%2==1) return (double)max(left1,left2);
                return (double)(max(left1,left2)+min(right1,right2))/2.0;
            }
            else if(left1>right2) high=mid1-1;
            else low=mid1+1;
        }
        return 0.0;
    }
};

class Solution3 {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n > m) return medianOf2(b, a);
        int low = 0, high = n, total = n + m;
        int halfLen = (total + 1) / 2;
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = halfLen - mid1;
            int left1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int left2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int right1 = (mid1 < n) ? a[mid1] : INT_MAX;
            int right2 = (mid2 < m) ? b[mid2] : INT_MAX;
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 1) return max(left1, left2);
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 > right2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0.0; // should never reach here
    }
};


int main(){

return 0;
}