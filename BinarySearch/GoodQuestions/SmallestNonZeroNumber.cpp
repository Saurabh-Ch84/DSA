#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    bool check(int mid,int maxi,vector<int> &arr){
        long long st=mid;
        for(int &e: arr){
            st=2*st-e;
            if(st<0) return false;
            if(st>=maxi) return true;
        }
        return true;
    }
  public:
    int find(vector<int>& arr) {
        // code here
        int maxi=*max_element(arr.begin(),arr.end());
        int low=1, high=maxi, x=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,maxi,arr)){
                x=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return x;
    }
};

class Solution2 {
  public:
    int find(vector<int>& arr) {
        // code here
        int need = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            need = (need + arr[i] + 1)/ 2;
        }
    
        return need;
    }
};

int main(){

return 0;
}