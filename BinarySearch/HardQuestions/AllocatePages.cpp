#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool check(vector<int> &arr,int k,int mid,int n){
        int students=1,bookSize=mid,temp=0;
        for(int &book:arr){
            if(temp+book>bookSize){
                students++;
                temp=0;
            }
            temp+=book;
            if(students>k) return false;
        }
        return true;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int low=0,high=0;
        for(int &page:arr){
            low=max(low,page);
            high+=page;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            bool response=check(arr,k,mid,n);
            if(response) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

return 0;
}