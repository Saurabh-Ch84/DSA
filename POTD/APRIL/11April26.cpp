#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n=arr.size(), left=0, right=1, count=0;
        while(right<n){
            if(arr[right]>arr[right-1]){
                count+=right-left;
                right++;
            }
            else{
                left=right;
                right++;
            }
        }
        return count;
    }
};

class Solution {
    using vint=vector<int>;
    int cal(int i,int j,int k){
        return abs(i-j)+abs(j-k)+abs(k-i);
    }
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size(), mini=1e9;
        unordered_map<int,vint> hashMap;
        for(int i=0;i<n;i++){
            int sz=hashMap[nums[i]].size();
            if(sz>2){
                vint &indices=hashMap[nums[i]];
                indices[0]=indices[1];
                indices[1]=indices[2];
                indices[2]=i;
                mini=min(mini,cal(indices[0],indices[1],indices[2]));
            }
            else{
                hashMap[nums[i]].push_back(i);
                vint &indices=hashMap[nums[i]];
                if(sz+1>2) mini=min(mini,cal(indices[0],indices[1],indices[2]));
            }
        }    
        return (mini==1e9 ? -1: mini);
    }
};

int main(){

return 0;
}