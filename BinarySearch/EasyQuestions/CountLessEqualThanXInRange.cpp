#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
class Solution {
    int countInRange(vi &arr,int low, int high,int t){
        if(t<arr[low]) return 0;
        int lb=low;
        int ub=upper_bound(arr.begin()+low,arr.begin()+high+1,t)-arr.begin();
        return ub-lb;
    }
public:
    int countLessEqual(vi &arr, int x) {
        // code here
        int count=0;
        int low=0, high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // left half sorted.
            if(arr[mid]>=arr[low]){
                count+=countInRange(arr,low,mid,x);
                low=mid+1;
            }
            // right half sorted.
            else{
                count+=countInRange(arr,mid,high,x);
                high=mid-1;
            }
        }
        return count;
    }
};

int main(){

return 0;
}