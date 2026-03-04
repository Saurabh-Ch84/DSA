#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution1 {
    class Comp{
        unordered_map<int,int> bitCount;
            public:
        Comp(unordered_map<int,int> &hashMap):bitCount(hashMap){}
        int getBitCount(int num){
            int count=0;
            while(num){
                count++;
                num=num&(num-1);
            }
            return count;
        }

        bool operator()(const int &a,const int &b){
            if(!bitCount.count(a))
                bitCount[a]=getBitCount(a);
            if(!bitCount.count(b))
                bitCount[b]=getBitCount(b);
            if(bitCount[a]==bitCount[b])
                return a<b;
            return bitCount[a]<bitCount[b];
        }
    };
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> hashMap;
        sort(arr.begin(),arr.end(),Comp(hashMap));
        return arr;
    }
};

class Solution2 {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> hashMap;
        int n=arr.size(), sum=0, maxi=0;
        for(int i=0;i<n;i++){
            if(arr[i]>k) sum++;
            else sum--;
            if(sum>0) maxi=i+1;
            else if(hashMap.count(sum-1)){
                int j=hashMap[sum-1];
                maxi=max(maxi,i-j);
            }    
            if(!hashMap.count(sum))
                hashMap[sum]=i;
        }
        return maxi;
    }
};

int main(){

return 0;
}