#include<bits/stdc++.h>
using namespace std;

class Solution2 {
    int countTripletsWithSumLessThanEqualToS(vector<int> &arr,int s){
        int n=arr.size(), count=0;
        for(int i=0;i<n-2;i++){
            int j=i+1, k=n-1;
            if(arr[i]+arr[j]>s) break;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>s) k--;
                else{
                    count+=k-j;
                    j++;
                }
            }
        }
        return count;
    }
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        // optimal
        sort(arr.begin(),arr.end());
        return countTripletsWithSumLessThanEqualToS(arr,r)-countTripletsWithSumLessThanEqualToS(arr,l-1);
    }
};

class Solution1 {
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        // brute force.
        sort(arr.begin(),arr.end());
        int n=arr.size(), count=0;
        for(int i=0;i<n-2;i++){
            if(arr[i]>r) break;
            for(int j=i+1;j<n-1;j++){
                int sum=arr[i]+arr[j];
                if(sum>r) break;
                int maxi, mini;
                if(sum>=l){
                    maxi=r-sum;
                    mini=0;
                }
                else{
                    maxi=r-sum;
                    mini=l-sum;
                }
                // find the number of elements in arr[j+1...n-1] which are in the range [mini, maxi]
                int validk=upper_bound(arr.begin()+j+1,arr.end(),maxi)-
                           lower_bound(arr.begin()+j+1,arr.end(),mini);
                count=count+validk;
            }
        }
        return count;
    }
};

int main(){

return 0;
}