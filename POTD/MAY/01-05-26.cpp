#include<bits/stdc++.h>
using namespace std;

class SolutionGFG {
    using vint=vector<int>;
  public:
    vint kthLargest(vint &arr, int k) {
        // code here
        int n=arr.size();
        vint res(n,-1);
        priority_queue<int,vint,greater<int>> pq;
        for(int i=0;i<n;i++){
            int num=arr[i];
            if(pq.size()<k) pq.push(num);
            else if(pq.top()<=num){
                pq.pop();
                pq.push(num);
            }
            if(pq.size()>=k){
                res[i]=pq.top();
            }
        }
        return res;
    }
};

class SolutionLC {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int t=accumulate(nums.begin(),nums.end(),0);
        int a=0, b=0, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(i) b=b-n*a+t;
            else{
                for(int i=0;i<n;i++)
                    b=b+(i*nums[i]);
            }
            maxi=max(maxi,b);
            a=nums[n-1-i];
        }
        return maxi;
    }
};

int main(){

return 0;
}