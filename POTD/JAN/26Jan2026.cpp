#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;

class Solution {
    void recursion(int i,int m,vvi &result,vi &arr){
        if(i>=m){
            result.push_back(arr);
            return ;
        }
        for(int j=i;j<m;j++){
            swap(arr[j],arr[i]);
            recursion(i+1,m,result,arr);
            swap(arr[j],arr[i]);
        }
    }
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int m=arr.size();
        vvi result;
        recursion(0,m,result,arr);
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minDiff=INT_MAX, n=arr.size();
        for(int i=0;i<n-1;i++){
            int diff=arr[i+1]-arr[i];
            minDiff=min(minDiff, diff);
        }
        vector<vector<int>> result;
        for(int i=0;i<n-1;i++){
            int diff=arr[i+1]-arr[i];
            if(diff == minDiff)
                result.push_back({arr[i],arr[i+1]});
        }
        return result;
    }
};

int main(){

return 0;
}