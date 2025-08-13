#include<iostream>
#include<vector>
using namespace std;

void recursion(vector<int> &arr,int i,int n,vector<int> &temp,vector<vector<int>> &ans,int currSum){
    if(i>=n)
    {
        if(!currSum) ans.push_back(temp);
        return; 
    }
    //notTake
    recursion(arr,i+1,n,temp,ans,currSum);
    //take
    if(currSum>=arr[i]){
        temp.push_back(arr[i]);
        recursion(arr,i+1,n,temp,ans,currSum-arr[i]);
        temp.pop_back();
    }
}

int main(){
    vector<int> arr={5,2,3,4,6,7,9},temp;
    int sum=9;
    vector<vector<int>> ans;
    recursion(arr,0,arr.size(),temp,ans,sum);
    for(vector<int> &v:ans){
        for(int &val:v){
            cout<<val<<" ";
        }
        cout<<"  ";
    }
return 0;
}