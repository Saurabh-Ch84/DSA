#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
//Pair with one element from each of the 2 arrays forming a sum closest to a given sum

pair<int,int> fun(vector<int> &arr1,vector<int> &arr2,int sum){
    if(arr1.empty() || arr2.empty()) return {-1,-1};
    int n=arr1.size(),m=arr2.size();
    int left=0,right=m-1,oldVar=INT32_MAX;
    pair<int,int> ans={-1,-1};
    while(left<n && right>-1){
        int l=arr1[left],r=arr2[right];
        int currSum=l+r;
        int newVar=abs(sum-currSum);
        if(newVar<oldVar){
            oldVar=newVar;
            ans={l,r};
            if(!oldVar) return ans;
        }
        if(currSum<sum) left++;
        else right--;
    }
    return ans;
}

int main(){
    vector<int> nums1={1,4,5,7};
    vector<int> nums2={10,20,30,40};
    int sum1=32;
    int sum2=50;
    pair<int,int> p=fun(nums2,nums1,sum1);
    cout<<p.first<<","<<p.second<<endl;
return 0;
}

