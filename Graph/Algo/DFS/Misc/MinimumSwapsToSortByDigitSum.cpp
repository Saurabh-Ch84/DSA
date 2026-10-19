#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Data{
        int value, sum, index;
        Data(int value=0,int sum=0,int index=0):value(value),sum(sum),index(index){}
    };
    struct Comp{
        bool operator()(const Data &a,const Data &b){
            if(a.sum==b.sum) return a.value<b.value;
            return a.sum<b.sum;
        }
    };
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<Data> arr(n);
        for(int i=0;i<n;i++){
            Data d(nums[i],sumOfDigits(nums[i]),i);
            arr[i]=d;
        }
        sort(arr.begin(),arr.end(),Comp());
        int minSwaps=0;
        for(int i=0;i<n;i++){
            int u=i, cycleLength=0;
            while(arr[u].index!=-1){
                int v=arr[u].index;
                arr[u].index=-1;
                u=v;
                cycleLength++;
            }
            int swaps=max(0,cycleLength-1);
            minSwaps+=swaps;
        }
        return minSwaps;
    }
};

int main(){

return 0;
}