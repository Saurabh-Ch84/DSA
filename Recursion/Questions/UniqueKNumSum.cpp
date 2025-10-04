#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<vector<int>> &result,vector<int> &temp,int n,int k,int i){
        if(n==0 && k==0){
            result.push_back(temp);
            return ;
        }
        if(k<=0 || i>9 || i>n){
            return ;
        }
        //take
        if(i<=n){
            temp.push_back(i);
            recursion(result,temp,n-i,k-1,i+1);
            temp.pop_back();
        }
        //notTake
        recursion(result,temp,n,k,i+1);
    }
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> result;
        vector<int> temp;
        recursion(result,temp,n,k,1);
        return result;
    }
};

void print(vector<vector<int>> nums){
    for(vector<int> &arr:nums){
        for(int &ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Solution s;
    print(s.combinationSum(13,3));
return 0;
}