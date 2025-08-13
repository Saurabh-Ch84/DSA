#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//most optimal 
class Solution1 {
    int nextGap(int n){
        return (n+1)/2;
    }
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        int len=n+m;
        int gap=len;
        while(gap>1){
            gap=nextGap(gap);
            int left=0;
            int right=gap+left;
            while(right<len){
                if(left<n && right<n && a[left]>a[right])
                    swap(a[left],a[right]);
                else if(left<n && right>=n && a[left]>b[right-n])
                    swap(a[left],b[right-n]);
                else if(left>=n  && b[left-n]>b[right-n])
                    swap(b[left-n],b[right-n]);
                right++;
                left++;
            }
        }
    }
};

//optimal method2
class Solution2 {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size(),m=b.size();
        int left=n-1,right=0;
        while(left>-1 && right<m){
            if(a[left]>b[right]){
                swap(a[left],b[right]);
                left--;
                right++;
            }
            else break;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
};

int main(){

return 0;
}