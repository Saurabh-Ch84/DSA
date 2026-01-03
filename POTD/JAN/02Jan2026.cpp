#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low=0, mid=0, high=arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        for(int &num: nums){
            if(hashMap[num])
                return num;
            hashMap[num]++;
        }
        return -1;
    }
};

int main(){

return 0;
}