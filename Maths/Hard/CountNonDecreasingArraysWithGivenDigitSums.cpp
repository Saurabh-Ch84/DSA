#include<iostream>
#include<vector>
using namespace std;

//brute-force
class Solution {
    using vint=vector<int>;
    const int mod=1e9+7;

    void generate(vint &nums,int sum,int lB,int uB,int num){
        if(num>uB) return;
        if(!sum && num>=lB) nums.push_back(num);
        for(int d=(num? 0:1);d<=9;d++){
            if(d>sum) return;
            generate(nums,sum-d,lB,uB,num*10+d);
        }
    }

    int recursion(int i,int n,int p,vint &digitSum){
        if(i==n) return 1;
        vint nums;
        if(!digitSum[i]){
            if(p>0) return 0;
            else nums.push_back(0);
        }
        else generate(nums,digitSum[i],p,5000,0);
        int m=nums.size(), count=0;
        for(int j=0;j<m;j++){
            int next=recursion(i+1,n,nums[j],digitSum);
            count=(count+next)%mod;
        }
        return count%mod;
    }
public:
    int countArrays(vector<int>& digitSum) {
        int n=digitSum.size();
        for(int i=0;i<n;i++)
            if(digitSum[i]>31) return 0;
        return recursion(0,n,-1,digitSum);
    }
};

int main(){

return 0;
}