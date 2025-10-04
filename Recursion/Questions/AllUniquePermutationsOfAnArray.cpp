#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    void recursion(vector<int> &arr,set<vector<int>> &hashSet,int n,int i){
        if(i==n){
            hashSet.insert(arr);
            return ;
        }
        for(int j=i;j<n;j++){
            swap(arr[i],arr[j]);
            recursion(arr,hashSet,n,i+1);
            swap(arr[i],arr[j]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> result;
        set<vector<int>> hashSet;
        recursion(arr,hashSet,n,0);
        for(vector<int> v:hashSet)
            result.push_back(v);
        return result;
    }
};

int main(){

return 0;
}