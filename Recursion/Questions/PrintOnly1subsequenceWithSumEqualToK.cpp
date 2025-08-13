#include<iostream>
#include<vector>
using namespace std;

bool recursion(vector<int> &arr,int i,int n,vector<int> &ans,int currSum){
    if(i>=n)
    {
        if(!currSum) return true;
        return false;
    }
    //notTake
    if(recursion(arr,i+1,n,ans,currSum)) return true;
    //take
    if(currSum>=arr[i]){
        ans.push_back(arr[i]);
        if(recursion(arr,i+1,n,ans,currSum-arr[i])) return true;
        ans.pop_back();
    }
    return false;
}

int main(){
    vector<int> arr={5,2,3,4,5,7},answer;
    int sum=10;
    recursion(arr,0,arr.size(),answer,sum);
    for(int &val:answer)
        cout<<val<<" ";
return 0;
}